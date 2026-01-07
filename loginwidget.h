#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QMainWindow>
#include "userservice.h"
#include "registerwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginWidget;
}
QT_END_NAMESPACE

class LoginWidget : public QMainWindow
{
    Q_OBJECT

public:
    LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();


private slots: // 槽函数建议放这里（Qt规范）
    //登录功能实现，调用service层
    void LoginFunction();
    //打开注册功能
    void OpenRegisterWidegt();
    //打开找回密码
    void OpenRetrieveWidget();

private:
    Ui::LoginWidget *ui;
    //保证代码「封装性」，防止外部误操作
    UserService m_userService;
    //RegisterWidget m_registerWidget;


};
#endif // LOGINWIDGET_H
