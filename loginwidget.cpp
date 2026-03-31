#include "loginwidget.h"
#include "ui_loginwidget.h"
#include "mainwidget.h"
// 引入UserManager（保存用户信息）
#include "usermanager.h"

#include "databasemanager.h"
#include "registerwidget.h"
#include "retrievewidget.h"
#include <QMessageBox>
#include <QSqlQuery>

LoginWidget::LoginWidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWidget)
{
    ui->setupUi(this);

    //设置控件ant风格
    ui->centralwidget->setProperty("type","frontPage");
    ui->LoginBtn->setProperty("type","primary");
    ui->registerBtn->setProperty("type","primary");
    ui->forgotBtn->setProperty("type","link");

    //程序启动时，显示打开数据库
    DatabaseManager& dbMgr = DatabaseManager::instance();
    if (!dbMgr.openDatabase()) {
        QMessageBox::critical(this, "致命错误", "数据库连接失败！请检查MySQL服务或配置。");
        // 连接失败时禁用登录/注册按钮
        ui->LoginBtn->setEnabled(false);
        ui->registerBtn->setEnabled(false);
        ui->forgotBtn->setEnabled(false);
    }

    //连接登录槽函数
    connect(ui->LoginBtn,&QPushButton::clicked,this,&LoginWidget::LoginFunction);

    //注册连接
    connect(ui->registerBtn,&QPushButton::clicked,this,&LoginWidget::OpenRegisterWidegt);

    //找回密码
    connect(ui->forgotBtn,&QPushButton::clicked,this,&LoginWidget::OpenRetrieveWidget);
}

LoginWidget::~LoginWidget()
{
    //delete m_userService; // 释放成员变量
    delete ui;
}



//void LoginWidget::LoginFunction()
//{
//    QString username = ui->usernameEdit->text().trimmed();
//    QString password = ui->PasswordEdit->text().trimmed();
//    QString StudentID = ui->StudentIDEdit->text().trimmed();
//    QString SchoolName = ui->SchoolNameEdit->text().trimmed();
//
//    if(username.isEmpty() || password.isEmpty() || StudentID.isEmpty() || SchoolName.isEmpty()){
//        QMessageBox::warning(this,"错误","输入项不能为空！");
//        return;
//    }
//
//
//    //定义一个变量接收状态权限
//    int userStatus = 0;
//
//
//    //操作登录是否成功和whether存在数据
//    bool loginSuccess = m_userService.login(username, password, StudentID, SchoolName,userStatus);
//    bool isExists = m_userService.isUserExists(username,StudentID,SchoolName);
//
//    if(isExists){
//        //如果存在，做登录判断
//        if(loginSuccess){
//            //登录成功后，获取用户的userStatus
//            //查询用户的id号
//            int userId = m_userService.getUserID(username, StudentID, SchoolName);
//
//
//            // 保存当前用户信息到全局单例，包括用户的状态，普通用户或管理员等，
//            UserManager::instance().setCurrentUser(userId,username, StudentID, SchoolName, userStatus);
//            //打开主窗口
//            OpenMainWidget();
//        }else{
//            QMessageBox::warning(this, "失败", "用户名或密码错误！");
//        }
//    }else{
//        QMessageBox::warning(this,"错误","用户不存在！");
//        return;
//    }
//}

void LoginWidget::LoginFunction()
{
    QString username = ui->usernameEdit->text().trimmed();
    QString password = ui->PasswordEdit->text().trimmed();
    QString StudentID = ui->StudentIDEdit->text().trimmed();
    QString SchoolName = ui->SchoolNameEdit->text().trimmed();

    if (username.isEmpty() || password.isEmpty() || StudentID.isEmpty() || SchoolName.isEmpty()) {
        QMessageBox::warning(this, "错误", "输入项不能为空！");
        return;
    }

    int userId = 0;
    int userStatus = 0;

    bool loginSuccess = m_userService.login(
        username,
        password,
        StudentID,
        SchoolName,
        userId,
        userStatus
    );

    if (loginSuccess) {

        UserManager::instance().setCurrentUser(
            userId,
            username,
            StudentID,
            SchoolName,
            userStatus
        );

        //打印当前获取的用户的信息
        qDebug() << "Login success, user id: " << userId << ", username: " << username << ", StudentID: " << StudentID << ", SchoolName: " << SchoolName << ", userStatus: " << userStatus;

        OpenMainWidget();

    }
    else {
        QMessageBox::warning(this, "登录失败", "用户名或密码错误！");
    }
}

void LoginWidget::OpenRegisterWidegt()
{
    RegisterWidget *registerWidget = new RegisterWidget();
    registerWidget->setAttribute(Qt::WA_DeleteOnClose);
    registerWidget->show();
    this->close();
}

void LoginWidget::OpenRetrieveWidget()
{
    RetrieveWidget * retrieveWidget = new RetrieveWidget();
    retrieveWidget->setAttribute(Qt::WA_DeleteOnClose);
    retrieveWidget->show();
    this->close();
}

void LoginWidget::OpenMainWidget()
{
    MainWidget * mainwidget = new MainWidget();
    mainwidget->setAttribute(Qt::WA_DeleteOnClose);
    mainwidget->show();
    this->close();
}

