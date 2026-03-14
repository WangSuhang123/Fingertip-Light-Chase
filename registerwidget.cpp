#include "registerwidget.h"
#include "ui_registerwidget.h"
#include "databasemanager.h"
#include "loginwidget.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QRandomGenerator>
#include <QTimer>
RegisterWidget::RegisterWidget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::RegisterWidget)
    , m_countdown(60)
    , m_countdownTimer(new QTimer(this))
    , m_smtpClient(new SmtpClient(this))
{
    ui->setupUi(this);
    //设置控件ant风格
    ui->widget->setProperty("type", "frontPage");
    ui->RegisterBtn->setProperty("type", "primary");
    ui->ReturnBtn->setProperty("type", "text");
    ui->GetCodeBtn->setProperty("type", "primary");

    //程序启动时，显示打开数据库
    DatabaseManager& dbMgr = DatabaseManager::instance();
    if (!dbMgr.openDatabase()) {
        QMessageBox::critical(this, "致命错误", "数据库连接失败！请检查MySQL服务或配置。");
        // 连接失败时禁用注册按钮
        ui->RegisterBtn->setEnabled(false);
    }

    //设置邮箱格式限定
    // 邮箱格式验证（正则表达式）
    QRegularExpression emailRegExp(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b)");
    ui->RegEMailEdit->setValidator(new QRegularExpressionValidator(emailRegExp, this));

    //连接注册槽函数
    //connect(ui->RegisterBtn,&QPushButton::clicked,this,&RegisterWidget::RegisterFunction);
    //返回
    connect(ui->ReturnBtn, &QPushButton::clicked, this, &RegisterWidget::BackToLoginPage);
    connect(ui->GetCodeBtn, &QPushButton::clicked, this, &RegisterWidget::onGetCodeClicked);
    connect(ui->RegisterBtn, &QPushButton::clicked, this, &RegisterWidget::onRegisterClicked);
    connect(m_countdownTimer, &QTimer::timeout, this, &RegisterWidget::updateCountdown);
    connect(m_smtpClient, &SmtpClient::mailSentSuccess, this, &RegisterWidget::onMailSentSuccess);
    connect(m_smtpClient, &SmtpClient::mailSentFailed, this, &RegisterWidget::onMailSentFailed);

    // ========== 配置SMTP（QQ邮箱） ==========
    m_smtpClient->setSmtpServer("smtp.qq.com", 587); // QQ邮箱SMTP服务器：smtp.qq.com，端口：587（STARTTLS）
    // 替换为你的QQ邮箱和SMTP授权码（不是登录密码！需要在QQ邮箱设置中开启POP3/SMTP并获取）
    m_smtpClient->setSender("wangsuhang7984@foxmail.com", "amlcljeptxisgedi");

}

RegisterWidget::~RegisterWidget()
{
    delete ui;
}

void RegisterWidget::RegisterFunction()
{
    QString username = ui->RegUserNameEdit->text().trimmed();
    QString password = ui->RegPassWordEdit->text().trimmed();
    QString StudentID = ui->RegStudentIDEdit->text().trimmed();
    QString SchoolName = ui->RegSchoolNameEdit->text().trimmed();
    QString EMail = ui->RegEMailEdit->text().trimmed();
    QString VerCode = ui->RegVerCodeEdit->text().trimmed();

    //判断输入是否有空
    if (username.isEmpty() || password.isEmpty() || StudentID.isEmpty() || SchoolName.isEmpty() || EMail.isEmpty() || VerCode.isEmpty()) {
        QMessageBox::warning(this, "错误", "输入项不能为空！");
        return;
    }

    //判断用户是否已经存在，避免存在重复数据
    bool isExists = m_userService.isUserExists(username, StudentID, SchoolName);

    if (isExists) { // 用户已存在，直接提示并返回，不执行后续注册
        QMessageBox::warning(this, "注册失败", "用户已存在！");
        return;
    }

    //进行注册操作，返回bool类型
    bool registerSuccess = m_userService.registerUser(username, password, StudentID, SchoolName, EMail, VerCode);

    //注册结果判断
    if (registerSuccess) {
        //做弹窗处理，随后返回到登录页面
        QMessageBox::information(this, "注册成功", "注册成功!");
        //打开登录页面
        LoginWidget* loginWidegt = new LoginWidget();
        loginWidegt->setAttribute(Qt::WA_DeleteOnClose);// 自动释放内存
        loginWidegt->show();
        this->close();
        //emit registerSucceeded();
    }
    else {
        QMessageBox::information(this, "注册失败", "注册失败!");
    }


}

void RegisterWidget::BackToLoginPage()
{
    //打开登录页面
    LoginWidget* loginWidegt = new LoginWidget();
    loginWidegt->setAttribute(Qt::WA_DeleteOnClose);// 自动释放内存
    loginWidegt->show();
    this->close();
}
//邮件验证码验证
// 获取验证码按钮点击事件
void RegisterWidget::onGetCodeClicked()
{
    QString email = ui->RegEMailEdit->text().trimmed();
    // 1. 验证邮箱是否输入合法
    if (email.isEmpty() || !ui->RegEMailEdit->hasAcceptableInput()) {
        QMessageBox::warning(this, "提示", "请输入有效的邮箱地址！");
        return;
    }

    //判断邮箱唯一性
    bool emailExist = m_userService.isEMailExists(email);
    if (emailExist) {
        QMessageBox::warning(this, "提示", "该邮箱已被注册！");
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
// 注册按钮点击事件
void RegisterWidget::onRegisterClicked()
{
    QString inputVerCode = ui->RegVerCodeEdit->text().trimmed();
    if (inputVerCode.isEmpty()) {
        QMessageBox::warning(this, "提示", "请输入验证码！");
        return;
    }
    // 2. 验证验证码是否正确
    if (inputVerCode == m_verificationCode) {

        //执行注册的操作
        RegisterFunction();

        m_verificationCode.clear();
    }
    else {
        QMessageBox::warning(this, "失败", "验证码错误，请重新输入！");
        ui->RegVerCodeEdit->clear();
    }
}
// 倒计时更新
void RegisterWidget::updateCountdown()
{
    m_countdown--;
    ui->GetCodeBtn->setText(QString("重新获取(%1秒)").arg(m_countdown));
    if (m_countdown <= 0) {
        m_countdownTimer->stop();
        ui->GetCodeBtn->setEnabled(true);
        ui->GetCodeBtn->setText("获取验证码");
    }
}
// 邮件发送成功/失败回调
void RegisterWidget::onMailSentSuccess()
{
    QMessageBox::information(this, "提示", "验证码已发送到你的邮箱，请查收！");
}
// 邮件发送失败回调
void RegisterWidget::onMailSentFailed(const QString& errorMsg)
{
    QMessageBox::critical(this, "错误", QString("验证码发送失败：%1").arg(errorMsg));
    // 恢复按钮状态
    m_countdownTimer->stop();
    ui->GetCodeBtn->setEnabled(true);
    ui->GetCodeBtn->setText("获取验证码");
}