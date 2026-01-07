#include "mainwidget.h"
#include "ui_mainwidget.h"
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


    // 连接点击信号
    connect(ui->typeSpeed, &CardPerformance::clicked, this, []{
        qDebug() << "Type Speed Card Clicked!";
    });

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
    ui->CompetitionManagementFeature->setProperty("theme","lightgreen");
    ui->InfoManagerFeature->setProperty("theme","pink");
    ui->SettingFeature->setProperty("theme","lightyellow");
    ui->beiyong1->setProperty("theme","cyan");
    ui->beiyong2->setProperty("theme","amber");
    //备用三是默认白色
    //刷新样式
    ui->PracticeFeature->style()->polish(ui->PracticeFeature);
    ui->CompetitionFeature->style()->polish(ui->CompetitionFeature);
    ui->LeaderboardFeature->style()->polish(ui->LeaderboardFeature);
    ui->CompetitionManagementFeature->style()->polish(ui->CompetitionManagementFeature);
    ui->InfoManagerFeature->style()->polish(ui->InfoManagerFeature);
    ui->SettingFeature->style()->polish(ui->SettingFeature);
    ui->beiyong1->style()->polish(ui->beiyong1);
    ui->beiyong2->style()->polish(ui->beiyong2);

    //设置默认卡片控件显示内容
    //第一个
    ui->PracticeFeature->setTitle("练习");
    ui->PracticeFeature->setIcon(QPixmap(":/res/banner.png"));
    ui->PracticeFeature->setDescription("提高你的打字速度和准确性");
}
