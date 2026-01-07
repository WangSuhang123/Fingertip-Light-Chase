#ifndef REGISTERWIDGET_H
#define REGISTERWIDGET_H

#include <QWidget>
#include "userservice.h"
#include "smtpclient.h"

namespace Ui {
class RegisterWidget;
}

class RegisterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterWidget(QWidget *parent = nullptr);
    ~RegisterWidget();

private:
    Ui::RegisterWidget *ui;
    //保证代码「封装性」，防止外部误操作
    UserService m_userService;

    // 邮件验证码业务变量
    QString m_verificationCode;  // 存储生成的验证码
    int m_countdown;             // 倒计时秒数
    QTimer *m_countdownTimer;    // 倒计时定时器
    SmtpClient *m_smtpClient;    // SMTP客户端

private slots: // 槽函数建议放这里（Qt规范）
    void RegisterFunction();
    void BackToLoginPage();

    //邮件验证码验证
    // 获取验证码按钮点击事件
    void onGetCodeClicked();
    // 注册按钮点击事件
    void onRegisterClicked();
    // 倒计时更新
    void updateCountdown();
    // 邮件发送成功/失败回调
    void onMailSentSuccess();
    void onMailSentFailed(const QString &errorMsg);

signals:
    //注册成功的信号
    // void registerSucceeded();


};

#endif // REGISTERWIDGET_H
