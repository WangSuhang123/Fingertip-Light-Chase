#include "retrievewidget.h"
#include "ui_retrievewidget.h"
#include "databasemanager.h"
#include "loginwidget.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QRandomGenerator>
#include <QTimer>

RetrieveWidget::RetrieveWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RetrieveWidget)
    , m_countdown(60)
    , m_countdownTimer(new QTimer(this))
    , m_smtpClient(new SmtpClient(this))
{
    ui->setupUi(this);
    //设置控件ant风格
    ui->widget->setProperty("type","frontPage");
    ui->GetCodeBtn->setProperty("type","primary");
    ui->RetrieveBtn->setProperty("type","primary");
    ui->ReturnBtn->setProperty("type","text");

    //程序启动时，显示打开数据库
    DatabaseManager& dbMgr = DatabaseManager::instance();
    if (!dbMgr.openDatabase()) {
        QMessageBox::critical(this, "致命错误", "数据库连接失败！请检查MySQL服务或配置。");
        // 连接失败时禁用找回按钮
        ui->RetrieveBtn->setEnabled(false);
    }

    //设置邮箱格式限定
    // 邮箱格式验证（正则表达式）
    QRegularExpression emailRegExp(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b)");
    ui->RetrEMailEdit->setValidator(new QRegularExpressionValidator(emailRegExp, this));
    //连接槽函数
    connect(ui->ReturnBtn,&QPushButton::clicked,this,&RetrieveWidget::BackToLoginPage);
    connect(ui->GetCodeBtn, &QPushButton::clicked, this, &RetrieveWidget::onGetCodeClicked);
    connect(ui->RetrieveBtn, &QPushButton::clicked, this, &RetrieveWidget::onRegisterClicked);
    connect(m_countdownTimer, &QTimer::timeout, this, &RetrieveWidget::updateCountdown);
    connect(m_smtpClient, &SmtpClient::mailSentSuccess, this, &RetrieveWidget::onMailSentSuccess);
    connect(m_smtpClient, &SmtpClient::mailSentFailed, this, &RetrieveWidget::onMailSentFailed);


    // ========== 配置SMTP（QQ邮箱） ==========
    m_smtpClient->setSmtpServer("smtp.qq.com", 587); // QQ邮箱SMTP服务器：smtp.qq.com，端口：587（STARTTLS）
    // 替换为你的QQ邮箱和SMTP授权码（不是登录密码！需要在QQ邮箱设置中开启POP3/SMTP并获取）
    m_smtpClient->setSender("wangsuhang7984@foxmail.com", "amlcljeptxisgedi");
}

RetrieveWidget::~RetrieveWidget()
{
    delete ui;
}

void RetrieveWidget::RetrieveFunction()
{
    //获取输入数据
    QString username = ui->RetrUserNameEdit->text().trimmed();
    QString password = ui->RetrPassWordEdit->text().trimmed();
    QString StudentID = ui->RetrStudentIDEdit->text().trimmed();
    QString SchoolName = ui->RetrSchoolNameEdit->text().trimmed();
    QString EMail = ui->RetrEMailEdit->text().trimmed();
    QString VerCode = ui->RetrVerCodeEdit->text().trimmed();

    //判断输入是否有空
    if(username.isEmpty() || password.isEmpty() || StudentID.isEmpty() || SchoolName.isEmpty() || EMail.isEmpty() || VerCode.isEmpty()){
        QMessageBox::warning(this,"错误","输入项不能为空！");
        return;
    }

    //判断用户是否存在
    bool isExists = m_userService.isUserExists(username,StudentID,SchoolName);


    if (!isExists) { // 用户已存在，直接提示并返回，不执行后续注册
        QString Msg = QString("在 %1 中没有找到姓名为 %2 学号为 %3 的用户!").arg(SchoolName).arg(username).arg(StudentID);
        QMessageBox::warning(this,"修改失败",Msg);
        return;
    }
    //修改密码
    bool retrieveSuccess = m_userService.retrievePassword(username,password,StudentID,SchoolName,EMail,VerCode);

    //修改结果判断
    if(retrieveSuccess){
        //做弹窗处理，随后返回到登录页面
        QMessageBox::information(this,"修改成功","修改成功!");
        //打开登录页面
        LoginWidget *loginWidegt = new LoginWidget();
        loginWidegt->setAttribute(Qt::WA_DeleteOnClose);// 自动释放内存
        loginWidegt->show();
        this->close();
    }else{
        QMessageBox::information(this,"修改失败","修改失败!");
    }

}

void RetrieveWidget::BackToLoginPage()
{
    //打开登录页面
    LoginWidget *loginWidegt = new LoginWidget();
    loginWidegt->setAttribute(Qt::WA_DeleteOnClose);// 自动释放内存
    loginWidegt->show();
    this->close();
}

void RetrieveWidget::onGetCodeClicked()
{
    QString email = ui->RetrEMailEdit->text().trimmed();
    // 1. 验证邮箱是否输入合法
    if(email.isEmpty() || !ui->RetrEMailEdit->hasAcceptableInput()){
        QMessageBox::warning(this, "提示", "请输入有效的邮箱地址！");
        return;
    }

    //判断邮箱唯一性
    bool emailExist = m_userService.isEMailExists(email);

    if(!emailExist){
        QMessageBox::warning(this, "提示", "该邮箱未被使用！");
        return;
    }

    // 2. 生成6位随机验证码
    m_verificationCode = QString::number(QRandomGenerator::global()->bounded(100000, 999999));

    // 3. 配置SMTP收件人和邮件内容
    m_smtpClient->setRecipient(email);
    m_smtpClient->setMailContent("【注册验证码】", QString("您的注册验证码是：%1（有效期5分钟）【Fingertip-Light-Chase】").arg(m_verificationCode));

    // 4. 发送邮件
    m_smtpClient->sendMail();

    // 5. 启动倒计时，禁用按钮
    ui->GetCodeBtn->setEnabled(false);
    m_countdown = 60;
    m_countdownTimer->start(1000); // 1秒触发一次
    ui->GetCodeBtn->setText(QString("重新获取(%1秒)").arg(m_countdown));
}

void RetrieveWidget::onRegisterClicked()
{
    QString inputVerCode = ui->RetrVerCodeEdit->text().trimmed();
    if (inputVerCode.isEmpty()) {
        QMessageBox::warning(this, "提示", "请输入验证码！");
        return;
    }
    // 2. 验证验证码是否正确
    if (inputVerCode == m_verificationCode) {

        //执行找回密码的操作
        RetrieveFunction();

        m_verificationCode.clear();
    } else {
        QMessageBox::warning(this, "失败", "验证码错误，请重新输入！");
        ui->RetrVerCodeEdit->clear();
    }
}

void RetrieveWidget::updateCountdown()
{
    m_countdown--;
    ui->GetCodeBtn->setText(QString("重新获取(%1秒)").arg(m_countdown));
    if (m_countdown <= 0) {
        m_countdownTimer->stop();
        ui->GetCodeBtn->setEnabled(true);
        ui->GetCodeBtn->setText("获取验证码");
    }
}

void RetrieveWidget::onMailSentSuccess()
{
    QMessageBox::information(this, "提示", "验证码已发送到你的邮箱，请查收！");
}

void RetrieveWidget::onMailSentFailed(const QString &errorMsg)
{
    QMessageBox::critical(this, "错误", QString("验证码发送失败：%1").arg(errorMsg));
    // 恢复按钮状态
    m_countdownTimer->stop();
    ui->GetCodeBtn->setEnabled(true);
    ui->GetCodeBtn->setText("获取验证码");
}
