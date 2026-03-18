#include "CompetitionLobbyWidget.h"
#include "ui_CompetitionLobbyWidget.h"

#include <QDateTime>

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

        addOperateButton(i, compId, status);
    }
}

void CompetitionLobbyWidget::addOperateButton(int row, int compId, QString status)
{
    //获取当前时间
    QDateTime now = QDateTime::currentDateTime();
    qDebug("now:%s", now.toString().toUtf8().data());

    QPushButton* btn = new QPushButton();

    if (status == "未开始")
        btn->setText("查看");

    else if (status == "进行中")
        btn->setText("进入");

    else
        btn->setText("已结束");


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

    emit enterCompetition(compId);
}