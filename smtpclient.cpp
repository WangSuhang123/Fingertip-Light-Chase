#include "smtpclient.h"
#include <QDebug>
#include <QDateTime>

SmtpClient::SmtpClient(QObject* parent)
    : QObject(parent)
    // 1. 初始化 QSslSocket 而非 QTcpSocket
    , m_socket(new QSslSocket(this))
    , m_smtpPort(587) // QQ邮箱SMTP端口：587（STARTTLS）
    , m_state(0)
{
    // 2. 绑定信号槽（新增 encrypted、sslErrors 信号）
    connect(m_socket, &QSslSocket::connected, this, &SmtpClient::socketConnected);
    connect(m_socket, &QSslSocket::readyRead, this, &SmtpClient::socketReadyRead);
    connect(m_socket, &QSslSocket::encrypted, this, &SmtpClient::encrypted); // TLS加密完成
    connect(m_socket, &QSslSocket::sslErrors, this, &SmtpClient::sslErrors); // SSL错误处理
    connect(m_socket, &QSslSocket::errorOccurred, this, &SmtpClient::socketError);
    connect(m_socket, &QSslSocket::disconnected, this, &SmtpClient::socketDisconnected);
}

void SmtpClient::setSmtpServer(const QString& server, int port)
{
    m_smtpServer = server;
    m_smtpPort = port;
}

void SmtpClient::setSender(const QString& senderEmail, const QString& senderPassword)
{
    m_senderEmail = senderEmail;
    m_senderPassword = senderPassword;
}

void SmtpClient::setRecipient(const QString& recipientEmail)
{
    m_recipientEmail = recipientEmail;
}

void SmtpClient::setMailContent(const QString& subject, const QString& body)
{
    m_mailSubject = subject;
    m_mailBody = body;
}

void SmtpClient::sendMail()
{
    m_socket->connectToHost(m_smtpServer, m_smtpPort);
}

void SmtpClient::socketConnected()
{
    m_state = 0;
    m_response.clear();
    qDebug() << "已连接到SMTP服务器";
}

void SmtpClient::socketReadyRead()
{
    m_response += m_socket->readAll();
    qDebug() << "SMTP Response:" << m_response;

    // SMTP协议交互流程（修复TLS加密逻辑）
    switch (m_state) {
    case 0: // 连接成功，发送EHLO
        if (m_response.contains("220")) {
            m_socket->write("EHLO localhost\r\n");
            m_state = 1;
            m_response.clear();
        }
        break;
    case 1: // 发送STARTTLS（触发TLS加密）
        if (m_response.contains("250")) {
            m_socket->write("STARTTLS\r\n");
            m_state = 2;
            m_response.clear();
        }
        break;
    case 2: // 收到STARTTLS响应后，启动TLS加密（关键修改）
        if (m_response.contains("220 Ready to start TLS")) {
            // 启用客户端TLS加密，这是原代码缺失的核心步骤
            m_socket->startClientEncryption();
            // 此时不会立即发送下一条指令，等待 encrypted() 信号触发后再继续
            m_response.clear();
        }
        break;
    case 3: // TLS加密完成后，重新发送EHLO
        if (m_response.contains("250")) {
            m_socket->write("AUTH LOGIN\r\n");
            m_state = 4;
            m_response.clear();
        }
        break;
    case 4: // 发送用户名（base64编码）
        if (m_response.contains("334")) {
            QByteArray user = m_senderEmail.toUtf8().toBase64();
            m_socket->write(user + "\r\n");
            m_state = 5;
            m_response.clear();
        }
        break;
    case 5: // 发送密码/授权码（base64编码）
        if (m_response.contains("334")) {
            QByteArray pass = m_senderPassword.toUtf8().toBase64();
            m_socket->write(pass + "\r\n");
            m_state = 6;
            m_response.clear();
        }
        break;
    case 6: // 发送发件人
        if (m_response.contains("235")) {
            m_socket->write(QString("MAIL FROM: <%1>\r\n").arg(m_senderEmail).toUtf8());
            m_state = 7;
            m_response.clear();
        }
        else {
            emit mailSentFailed("邮箱授权码错误或SMTP服务未开启");
            m_socket->disconnectFromHost();
        }
        break;
    case 7: // 发送收件人
        if (m_response.contains("250")) {
            m_socket->write(QString("RCPT TO: <%1>\r\n").arg(m_recipientEmail).toUtf8());
            m_state = 8;
            m_response.clear();
        }
        break;
    case 8: // 发送DATA
        if (m_response.contains("250")) {
            m_socket->write("DATA\r\n");
            m_state = 9;
            m_response.clear();
        }
        break;
    case 9: // 发送邮件内容
        if (m_response.contains("354")) {
            QString mailContent = QString("From: %1\r\nTo: %2\r\nSubject: %3\r\n\r\n%4\r\n.\r\n")
                .arg(m_senderEmail)
                .arg(m_recipientEmail)
                .arg(m_mailSubject)
                .arg(m_mailBody);
            m_socket->write(mailContent.toUtf8());
            m_state = 10;
            m_response.clear();
        }
        break;
    case 10: // 发送完成
        if (m_response.contains("250")) {
            emit mailSentSuccess();
            m_socket->write("QUIT\r\n");
        }
        else {
            emit mailSentFailed("邮件发送失败");
        }
        m_socket->disconnectFromHost();
        break;
    default:
        break;
    }
}

// 3. 新增：TLS加密完成后的处理（继续发送EHLO）
void SmtpClient::encrypted()
{
    qDebug() << "TLS加密握手完成";
    // 加密完成后，重新发送EHLO，进入状态3
    m_socket->write("EHLO localhost\r\n");
    m_state = 3;
    m_response.clear();
}

// 4. 新增：SSL错误处理（忽略自签名证书错误，不影响QQ邮箱）
void SmtpClient::sslErrors(const QList<QSslError>& errors)
{
    Q_UNUSED(errors);
    // 忽略SSL错误（生产环境可根据需要处理）
    m_socket->ignoreSslErrors();
}

void SmtpClient::socketError(QAbstractSocket::SocketError error)
{
    Q_UNUSED(error);
    emit mailSentFailed(m_socket->errorString());
}

void SmtpClient::socketDisconnected()
{
    m_socket->close();
}