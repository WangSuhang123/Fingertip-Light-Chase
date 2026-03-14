#ifndef SMTPCLIENT_H
#define SMTPCLIENT_H
#include <QObject>
// 1. 替换 QTcpSocket 为 QSslSocket
#include <QSslSocket>
#include <QString>
#include <QByteArray>

class SmtpClient : public QObject
{
    Q_OBJECT
public:
    explicit SmtpClient(QObject* parent = nullptr);

    // 设置邮件发送参数
    void setSmtpServer(const QString& server, int port);
    void setSender(const QString& senderEmail, const QString& senderPassword);
    void setRecipient(const QString& recipientEmail);
    void setMailContent(const QString& subject, const QString& body);

    // 发送邮件
    void sendMail();

signals:
    // 邮件发送结果（成功/失败）
    void mailSentSuccess();
    void mailSentFailed(const QString& errorMsg);

private slots:
    void socketConnected();
    void socketReadyRead();
    // 2. 添加 TLS 加密握手完成的槽函数
    void sslErrors(const QList<QSslError>& errors);
    void encrypted();
    void socketError(QAbstractSocket::SocketError error);
    void socketDisconnected();

private:
    // 3. 替换 QTcpSocket* 为 QSslSocket*
    QSslSocket* m_socket;
    QString m_smtpServer;
    int m_smtpPort;
    QString m_senderEmail;    // 发送方邮箱（比如你的QQ邮箱）
    QString m_senderPassword; // 发送方邮箱的SMTP授权码（不是登录密码）
    QString m_recipientEmail; // 接收方邮箱（用户输入的邮箱）
    QString m_mailSubject;    // 邮件主题
    QString m_mailBody;       // 邮件内容（验证码）

    QByteArray m_response;    // 存储SMTP服务器的响应
    int m_state;              // SMTP通信状态机
};

#endif // SMTPCLIENT_H