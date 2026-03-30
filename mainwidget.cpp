#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "loginwidget.h"
// 引入UserManager（保存用户信息）
#include "usermanager.h"
#include "practicesetupdialog.h"
#include "uploadArticle.h"
#include "CompetitionLobbyWidget.h"
#include "CompetitionPublish.h"
#include "practicewidget.h"
#include "DataVisualization.h"
#include "ComprehensiveManagement.h"
#include "LeaderboardFeature.h"

#include <QStyle>

MainWidget::MainWidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    competitionService = new CompetitionService(this);
    competitionRecordsService= new CompetitionRecordsService(this);
    
    //Style样式
    widgetStyle();
    CardPerformanceStyle();
    FunturesCardStyle();
    //设置用户登录的欢迎横幅（用户名-学校-权限
    UpdateWidgetTitle();
    //个人最近成绩
    ShowRecentCompetitionResult();
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
    ui->usedTime->setProperty("theme","orange");

    ui->typeSpeed->style()->polish(ui->typeSpeed);
    ui->Accuracy->style()->polish(ui->Accuracy);
    ui->usedTime->style()->polish(ui->usedTime);

    //默认内容显示
    //第一个，value通过别的进行设置，先给一个null值
    ui->typeSpeed->setTitle("WPM");
    ui->typeSpeed->setValue("null");
    ui->typeSpeed->setDescription("words per minute");
    ui->typeSpeed->setIcon(QPixmap(":/res/Blizt.png"));
    //第二个
    ui->Accuracy->setTitle("正确率");
    ui->Accuracy->setValue("null");
    ui->Accuracy->setDescription("accuracy");
    ui->Accuracy->setIcon(QPixmap(":/res/rakete.png"));
    //第三个
    ui->usedTime->setTitle("使用时间");
    ui->usedTime->setValue("null");
    ui->usedTime->setDescription("used time");
    ui->usedTime->setIcon(QPixmap(":/res/Rank.png"));
    //第四个
    ui->finalScore->setTitle("综合评分");
    ui->finalScore->setValue("null");
    ui->finalScore->setDescription("Overall Score");
    ui->finalScore->setIcon(QPixmap(":/res/banner.png"));

}

void MainWidget::FunturesCardStyle()
{
    //设置默认卡片控件显示样式
    ui->PracticeFeature->setProperty("theme","lightblue");
    ui->CompetitionFeature->setProperty("theme","darkblue");
    ui->LeaderboardFeature->setProperty("theme","purple");
    ui->ComprehensiveManagementFeature->setProperty("theme","lightgreen");
    ui->AboutUs->setProperty("theme","pink");
    ui->DataVisualization->setProperty("theme","lightyellow");
    ui->Publishcomp->setProperty("theme","cyan");
    ui->InsertArticleFeature->setProperty("theme","amber");
    //备用三是默认白色
    //刷新样式
    ui->PracticeFeature->style()->polish(ui->PracticeFeature);
    ui->CompetitionFeature->style()->polish(ui->CompetitionFeature);
    ui->LeaderboardFeature->style()->polish(ui->LeaderboardFeature);
    ui->InsertArticleFeature->style()->polish(ui->InsertArticleFeature);
    ui->Feedback->style()->polish(ui->Feedback);
    ui->DataVisualization->style()->polish(ui->DataVisualization);
    ui->Publishcomp->style()->polish(ui->Publishcomp);
    ui->ComprehensiveManagementFeature->style()->polish(ui->ComprehensiveManagementFeature);

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
    ui->ComprehensiveManagementFeature->setTitle("综合管理");
    ui->ComprehensiveManagementFeature->setIcon(QPixmap(":/res/icon/app.png"));
    ui->ComprehensiveManagementFeature->setDescription("综合管理");
    //第五个
    ui->AboutUs->setTitle("关于我们");
    ui->AboutUs->setIcon(QPixmap(":/res/icon/team.png"));
    ui->AboutUs->setDescription("关于我们");
    //第六个
    ui->DataVisualization->setTitle("数据可视化");
    ui->DataVisualization->setIcon(QPixmap(":/res/icon/shiyan.png"));
    ui->DataVisualization->setDescription("数据可视化");
    //第七个
    ui->Publishcomp->setTitle("比赛发布");
    ui->Publishcomp->setIcon(QPixmap(":/res/icon/tongji.png"));
    ui->Publishcomp->setDescription("管理员发布比赛");
    //第八个
    ui->InsertArticleFeature->setTitle("新增文章");
    ui->InsertArticleFeature->setIcon(QPixmap(":/res/icon/kefu.png"));
    ui->InsertArticleFeature->setDescription("新增文章");
    //第九个
    ui->Feedback->setTitle("反馈");
    ui->Feedback->setIcon(QPixmap(":/res/icon/xiaoxi.png"));
    ui->Feedback->setDescription("畅所欲言");
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
//最近比赛成绩展示
void MainWidget::ShowRecentCompetitionResult()
{
    //获取用户id
    UserManager& userMgr = UserManager::instance();
    int userID = userMgr.getCurrentUserID();
    
    // 获取最近的比赛
    QVector<CompetitionFullRecord> records = competitionRecordsService->getRecentRecords(userID);

    if (records.isEmpty()) {
        ui->typeSpeed->setValue("未参加比赛");
        ui->Accuracy->setValue("未参加比赛");
        ui->usedTime->setValue("未参加比赛");
        ui->finalScore->setValue("未参加比赛");
        return;
    }

    // 获取最新的比赛
    CompetitionFullRecord record = records.first();

    // 显示数据
    ui->typeSpeed->setValue(QString::number(record.wpm));
    ui->Accuracy->setValue(QString::number(record.accuracy));
    ui->usedTime->setValue(QString::number(record.timeUsed));
    ui->finalScore->setValue(QString::number(record.finalScore));



}

void MainWidget::on_CompetitionFeature_clicked()
{
    CompetitionLobbyWidget *competitionLobby = new CompetitionLobbyWidget();
    //连接信号，从比赛大厅连接进入比赛
    connect(competitionLobby, &CompetitionLobbyWidget::enterCompetition,
        this, &MainWidget::onEnterCompetition);
    competitionLobby->setAttribute(Qt::WA_DeleteOnClose);
    competitionLobby->show();
}

void MainWidget::on_Publishcomp_clicked()
{
    UserManager& userMgr = UserManager::instance();
    int userStatus = userMgr.getUserStatus();

    if (userStatus == 1)
    {
        CompetitionPublish* competitionPublish = new CompetitionPublish();
        competitionPublish->setAttribute(Qt::WA_DeleteOnClose);
        competitionPublish->show();
    }
    else
    {
        //弹窗警告权限不够
        QMessageBox::warning(this, "警告", "权限不够，请联系管理员");
    }

}
//数据可视化
void MainWidget::on_DataVisualization_clicked()
{
    DataVisualization *dataVisualization = new DataVisualization();
    dataVisualization->setAttribute(Qt::WA_DeleteOnClose);
    dataVisualization->show();
}

// 跳转到管理界面
void MainWidget::on_ComprehensiveManagementFeature_clicked()
{
    UserManager& userMgr = UserManager::instance();
    int userStatus = userMgr.getUserStatus();

    if (userStatus == 1)
    {
        ComprehensiveManagement* comprehensiveManagement = new ComprehensiveManagement();
        comprehensiveManagement->setAttribute(Qt::WA_DeleteOnClose);
        comprehensiveManagement->show();
    }
    else
    {
        //弹窗警告权限不够
        QMessageBox::warning(this, "警告", "权限不够，请联系管理员");
    }
}

//关于我们
void MainWidget::on_AboutUs_clicked()
{
    QMessageBox::about(this, "关于我们 - 指尖逐光",
        "Fingertip-Light-Chase（指尖逐光）\n"
        "一个基于 Qt 开发的跨平台打字测速与比赛系统\n\n"

        "📌 软件介绍\n"
        "本系统集打字练习、赛事发布、在线比赛、成绩统计、数据可视化于一体，\n"
        "致力于为用户提供高效、专业、有趣的打字训练环境。\n\n"

        "🔧 核心功能\n"
        "• 标准打字练习与实时速度检测\n"
        "• 赛事发布、比赛大厅、在线参赛\n"
        "• 个人成绩记录与全局排行榜\n"
        "• 完整后台管理系统（用户/比赛/文章）\n"
        "• 数据可视化统计展示\n\n"

        "👨‍💻 开发者信息\n"
        "GitHub：WangSuhang123\n"
        "邮箱：wangsuhang7984@foxmail.com\n\n"

        "💡 寄语\n"
        "指尖生花，逐光而行；\n"
        "愿每一次敲击，都成为你进步的力量。"
    );
}



void MainWidget::onEnterCompetition(int compId)
{
    // 查比赛详情
    QVariantMap comp = competitionService->getCompetitionById(compId);

    int articleId = comp["articleId"].toInt();
    int duration = comp["duration"].toInt();

    // 创建练习界面
    PracticeWidget* practice = new PracticeWidget;

    //传数据（复用你现有接口）
    /*practice->onSetupReceived(articleId, duration);*/
    practice->onSetupReceived(
        articleId,
        duration,
        PracticeWidget::CompetitionMode,
        compId
    );

    // 显示
    practice->show();
}

void MainWidget::on_InsertArticleFeature_clicked()
{
    UserManager& userMgr = UserManager::instance();
    int userStatus = userMgr.getUserStatus();

    if (userStatus == 1)
    {
        uploadArticle* uploadarticle = new uploadArticle();
        uploadarticle->setAttribute(Qt::WA_DeleteOnClose);
        uploadarticle->show();
    }
    else
    {
        //弹窗警告权限不够
        QMessageBox::warning(this, "警告", "权限不够，请联系管理员");
    }
}

//排行榜
void MainWidget::on_LeaderboardFeature_clicked()
{
    LeaderboardFeature* leaderboard = new LeaderboardFeature();
    leaderboard->setAttribute(Qt::WA_DeleteOnClose);
    leaderboard->show();
}