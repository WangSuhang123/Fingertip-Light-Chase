#include "CompetitionLobbyWidget.h"
#include "ui_CompetitionLobbyWidget.h"

#include <QDateTime>
#include <QStyledItemDelegate>
#include "usermanager.h"

CompetitionLobbyWidget::CompetitionLobbyWidget(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::CompetitionLobbyWidgetClass())
{
    ui->setupUi(this);



    updataUiShow();

    initTable();

    loadCompetitions();

    connect(ui->refreshBtn, &QPushButton::clicked, this, [=]() {
        loadCompetitions();
        });
}

CompetitionLobbyWidget::~CompetitionLobbyWidget()
{
    delete ui;
}

void CompetitionLobbyWidget::updataUiShow()
{
    ui->centralWidget->setProperty("type", "StatusWidget");

    ui->CompetitionTableWidget->setProperty("type", "DialogPage");

    ui->refreshBtn->setProperty("type", "primary");

    ui->BackBtn->setProperty("type", "text");

    //获取当前登录用户的学校
   QString schoolName = UserManager::instance().getSchoolName();
   ui->CompetitionSchool->setText(schoolName);
}

void CompetitionLobbyWidget::initTable()
{
    ui->CompetitionTable->setColumnCount(6);

    QStringList headers;

    headers << "比赛名称" << "开始时间" <<"结束时间" << "限时(分钟)" << "状态" << "操作";

    ui->CompetitionTable->setHorizontalHeaderLabels(headers);

    //不允许编辑
    ui->CompetitionTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //整行选择
    ui->CompetitionTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    //隐藏行号
    ui->CompetitionTable->verticalHeader()->setVisible(false);

    //自动拉伸
    ui->CompetitionTable->horizontalHeader()->setStretchLastSection(true);

    //行高
    ui->CompetitionTable->verticalHeader()->setDefaultSectionSize(50);
    //字符居中
    ui->CompetitionTable->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    // ========== 新增：所有单元格文本居中 ==========
    ui->CompetitionTable->setItemDelegate(new QStyledItemDelegate); // 确保代理生效

}

void CompetitionLobbyWidget::loadCompetitions()
{
    QString school = UserManager::instance().getSchoolName();

    QList<QVariantMap> list = competitionService.getCompetitionList(school);

    ui->CompetitionTable->setRowCount(list.size());

    for (int i = 0; i < list.size(); i++)
    {
        QVariantMap comp = list[i];

        int compId = comp["compId"].toInt();
        QString name = comp["name"].toString();
        QDateTime startTime = comp["startTime"].toDateTime();
        QDateTime endTime = comp["endTime"].toDateTime();
        int durationMin = comp["duration"].toInt();

        // ⭐ 自动计算状态
        QDateTime now = QDateTime::currentDateTime();

        QString status;
        if (now < startTime)
            status = "未开始";
        else if (now >= startTime && now <= endTime)
            status = "进行中";
        else
            status = "已结束";

        // 填充表格
        ui->CompetitionTable->setItem(i, 0, new QTableWidgetItem(name));
        ui->CompetitionTable->setItem(i, 1, new QTableWidgetItem(startTime.toString("yyyy-MM-dd HH:mm")));
        ui->CompetitionTable->setItem(i, 2, new QTableWidgetItem(endTime.toString("yyyy-MM-dd HH:mm")));
        ui->CompetitionTable->setItem(i, 3, new QTableWidgetItem(QString::number(durationMin)));
        ui->CompetitionTable->setItem(i, 4, new QTableWidgetItem(status));

        /*addOperateButton(i, compId, status);*/
        // 判断是否已经参加
        //获取用户id
        int userId = UserManager::instance().getCurrentUserID();
        bool hasJoined = competitionrecordsservice.hasUserJoined(compId, userId);

        addOperateButton(i, compId, status, hasJoined);
    }
}

void CompetitionLobbyWidget::addOperateButton(int row, int compId, QString status, bool hasJoined)
{
    //获取当前时间
    QDateTime now = QDateTime::currentDateTime();
    qDebug("now:%s", now.toString().toUtf8().data());

    QPushButton* btn = new QPushButton();

    if (status == "未开始")
    {
        btn->setText("查看");
    }
    else if (status == "进行中")
    {
        if (hasJoined)
        {
            btn->setText("已完成");
            btn->setEnabled(false); //禁止点击
        }
        else
        {
            btn->setText("进入");
        }
    }
    else
    {
        btn->setText("已结束");
        btn->setEnabled(false);
    }


    btn->setProperty("type", "primary");


    connect(btn, &QPushButton::clicked, this, [=]() {

        onCompetitionClicked(compId, status);

        });


    QWidget* container = new QWidget();

    QHBoxLayout* layout = new QHBoxLayout(container);

    layout->addWidget(btn);

    layout->setAlignment(Qt::AlignCenter);

    layout->setContentsMargins(0, 0, 0, 0);

    ui->CompetitionTable->setCellWidget(row, 5, container);
}

void CompetitionLobbyWidget::onCompetitionClicked(int compId, QString status)
{
    if (status == "未开始")
    {
        QMessageBox::information(this, "提示", "比赛尚未开始");
        return;
    }

    if (status == "已结束")
    {
        QMessageBox::information(this, "提示", "比赛已经结束");
        return;
    }

    // 新增：已参赛判断
    //获取用户id
    int userId = UserManager::instance().getCurrentUserID();
    if (competitionrecordsservice.hasUserJoined(compId, userId)) {
        QMessageBox::information(this, "提示", "你已经完成该比赛，无法再次进入");
        return;
    }

    emit enterCompetition(compId);
}