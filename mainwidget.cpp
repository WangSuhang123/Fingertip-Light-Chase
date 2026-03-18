#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "loginwidget.h"
// 引入UserManager（保存用户信息）
#include "usermanager.h"
#include "practicesetupdialog.h"
#include "uploadArticle.h"
#include "CompetitionLobbyWidget.h"
#include "CompetitionPublish.h"

#include <QStyle>

MainWidget::MainWidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    //Style样式
    widgetStyle();
    CardPerformanceStyle();
    FunturesCardStyle();
    //设置用户登录的欢迎横幅（用户名-学校-权限
    UpdateWidgetTitle();
    // 连接点击信号
    connect(ui->typeSpeed, &CardPerformance::clicked, this, []{
        qDebug() << "Type Speed Card Clicked!";

    });
    //连接退出登录按钮
    connect(ui->LogOutBtn,&QPushButton::clicked,this,&MainWidget::Logout);
    //连接练习功能
    connect(ui->PracticeFeature,&CardWidget::clicked,this,&MainWidget::OpenPracticeFeature);

}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::widgetStyle()
{

    ui->PerformanceWidget->setProperty("type","PerformanceWidget");
    ui->StatusWidget->setProperty("type","StatusWidget");

}

void MainWidget::CardPerformanceStyle()
{
    ui->typeSpeed->setProperty("theme","blue");
    ui->Accuracy->setProperty("theme","green");
    ui->Competitions->setProperty("theme","orange");

    ui->typeSpeed->style()->polish(ui->typeSpeed);
    ui->Accuracy->style()->polish(ui->Accuracy);
    ui->Competitions->style()->polish(ui->Competitions);

    //默认内容显示
    //第一个，value通过别的进行设置，先给一个null值
    ui->typeSpeed->setTitle("Typing Speed");
    ui->typeSpeed->setValue("null");
    ui->typeSpeed->setDescription("words per minute");
    ui->typeSpeed->setIcon(QPixmap(":/res/Blizt.png"));
    //第二个
    ui->Accuracy->setTitle("Accuracy");
    ui->Accuracy->setValue("null");
    ui->Accuracy->setDescription("average accuracy");
    ui->Accuracy->setIcon(QPixmap(":/res/rakete.png"));
    //第三个
    ui->Competitions->setTitle("Competitions");
    ui->Competitions->setValue("null");
    ui->Competitions->setDescription("participated");
    ui->Competitions->setIcon(QPixmap(":/res/Rank.png"));
    //第四个
    ui->Rank->setTitle("Your Rank");
    ui->Rank->setValue("null");
    ui->Rank->setDescription("global ranking");
    ui->Rank->setIcon(QPixmap(":/res/banner.png"));

}

void MainWidget::FunturesCardStyle()
{
    //设置默认卡片控件显示样式
    ui->PracticeFeature->setProperty("theme","lightblue");
    ui->CompetitionFeature->setProperty("theme","darkblue");
    ui->LeaderboardFeature->setProperty("theme","purple");
    ui->InsertArticleFeature->setProperty("theme","lightgreen");
    ui->InfoManagerFeature->setProperty("theme","pink");
    ui->SettingFeature->setProperty("theme","lightyellow");
    ui->beiyong1->setProperty("theme","cyan");
    ui->beiyong2->setProperty("theme","amber");
    //备用三是默认白色
    //刷新样式
    ui->PracticeFeature->style()->polish(ui->PracticeFeature);
    ui->CompetitionFeature->style()->polish(ui->CompetitionFeature);
    ui->LeaderboardFeature->style()->polish(ui->LeaderboardFeature);
    ui->InsertArticleFeature->style()->polish(ui->InsertArticleFeature);
    ui->InfoManagerFeature->style()->polish(ui->InfoManagerFeature);
    ui->SettingFeature->style()->polish(ui->SettingFeature);
    ui->beiyong1->style()->polish(ui->beiyong1);
    ui->beiyong2->style()->polish(ui->beiyong2);

    //设置默认卡片控件显示内容
    //第一个
    ui->PracticeFeature->setTitle("练习");
    ui->PracticeFeature->setIcon(QPixmap(":/res/icon/danju.png"));
    ui->PracticeFeature->setDescription("提高你的打字速度和准确性");
    //第二个
    ui->CompetitionFeature->setTitle("比赛大厅");
    ui->CompetitionFeature->setIcon(QPixmap(":/res/icon/report.png"));
    ui->CompetitionFeature->setDescription("参加在线比赛");
    //第三个
    ui->LeaderboardFeature->setTitle("排行榜");
    ui->LeaderboardFeature->setIcon(QPixmap(":/res/icon/data.png"));
    ui->LeaderboardFeature->setDescription("查看在本学校的排行榜");
    //第四个
    ui->InsertArticleFeature->setTitle("新增文章");
    ui->InsertArticleFeature->setIcon(QPixmap(":/res/icon/app.png"));
    ui->InsertArticleFeature->setDescription("管理员新增文章");
    //第五个
    ui->InfoManagerFeature->setTitle("文章管理");
    ui->InfoManagerFeature->setIcon(QPixmap(":/res/icon/team.png"));
    ui->InfoManagerFeature->setDescription("管理员文章管理");
    //第六个
    ui->SettingFeature->setTitle("设置");
    ui->SettingFeature->setIcon(QPixmap(":/res/icon/shiyan.png"));
    ui->SettingFeature->setDescription("系统设置");
    //第七个
    ui->beiyong1->setTitle("比赛发布");
    ui->beiyong1->setIcon(QPixmap(":/res/icon/tongji.png"));
    ui->beiyong1->setDescription("管理员发布比赛");
    //第八个
    ui->beiyong2->setTitle("人员管理");
    ui->beiyong2->setIcon(QPixmap(":/res/icon/kefu.png"));
    ui->beiyong2->setDescription("管理员人员管理");
    //第九个
    ui->beiyong3->setTitle("信息");
    ui->beiyong3->setIcon(QPixmap(":/res/icon/xiaoxi.png"));
    ui->beiyong3->setDescription("消息");
}

void MainWidget::Logout()
{
    //清空当前登录的账户信息
    UserManager::instance().logout();

    // //测试是否删除成功
    // //通过 instance() 获取那个唯一的实例
    // UserManager& userTest = UserManager::instance();
    // // 检查是否登录
    // QString LoginUserName = userTest.getUserName();
    // QString LoginUserId = userTest.getStudentId();
    // QString LoginUserSchool = userTest.getSchoolName();
    // int LoginUserStatus = userTest.getUserStatus();

    // QString userStatus = "";

    // if(LoginUserStatus==0){
    //     userStatus = "普通用户";
    // }else if(LoginUserStatus==1){
    //     userStatus = "管理员";
    // }else{
    //     userStatus = "其他";
    // }

    // qDebug() << "当前登录用户：" << LoginUserName << " 学号：" << LoginUserId;
    // qDebug() << "当前登录学校：" << LoginUserSchool << " 权限：" << userStatus;

    //跳转到登录页面
    OpenLoginWidget();

}



void MainWidget::UpdateWidgetTitle()
{
    //通过 instance() 获取那个唯一的实例
    UserManager& userMgr = UserManager::instance();
    // 检查是否登录
    if (userMgr.isLogin()) {
        QString LoginUserName = userMgr.getUserName();
        QString LoginUserId = userMgr.getStudentId();
        QString LoginUserSchool = userMgr.getSchoolName();
        int LoginUserStatus = userMgr.getUserStatus();

        QString userStatus = "";

        if(LoginUserStatus==0){
            userStatus = "普通用户";
        }else if(LoginUserStatus==1){
            userStatus = "管理员";
        }else{
            userStatus = "其他";
        }

        //qDebug() << "当前登录用户：" << LoginUserName << " 学号：" << LoginUserId;
        // 更新 UI 上的欢迎语
        ui->label_5->setText(LoginUserName+"-"+userStatus+"-"+LoginUserSchool);
    } else {
        qDebug() << "暂无用户登录";
    }

}

void MainWidget::OpenLoginWidget()
{
    LoginWidget *loginWidget = new LoginWidget();
    loginWidget->setAttribute(Qt::WA_DeleteOnClose);
    loginWidget->show();
    this->close();
}

void MainWidget::OpenPracticeFeature()
{
    PracticeSetupDialog *practiceDialog = new PracticeSetupDialog();
    practiceDialog->setAttribute(Qt::WA_DeleteOnClose);
    practiceDialog->show();
}

void MainWidget::on_CompetitionFeature_clicked()
{
    CompetitionLobbyWidget *competitionLobby = new CompetitionLobbyWidget();
    competitionLobby->setAttribute(Qt::WA_DeleteOnClose);
    competitionLobby->show();
}

void MainWidget::on_beiyong1_clicked()
{
    CompetitionPublish *competitionPublish = new CompetitionPublish();
    competitionPublish->setAttribute(Qt::WA_DeleteOnClose);
    competitionPublish->show();

}

void MainWidget::on_InsertArticleFeature_clicked()
{
    uploadArticle *uploadarticle = new uploadArticle();
    uploadarticle->setAttribute(Qt::WA_DeleteOnClose);
    uploadarticle->show();
}
