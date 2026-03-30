#include "LeaderboardFeature.h"
#include <QHeaderView>
#include <QTableView>
#include <QStyledItemDelegate>
#include <QBrush>
#include <QColor>
#include <QStandardItem>

LeaderboardFeature::LeaderboardFeature(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::LeaderboardFeatureClass())
{
	ui->setupUi(this);

    competitionRecordsService = new CompetitionRecordsService(this);

	
    //排行榜样式
    ui->leaderboardTable->setStyleSheet(R"(
        QTableView {
            background-color: #fafbfc;
            border:none;
            font-size:10pt;
        }
        QHeaderView::section {
            background-color: #2b5f9e;
            color:white;
            font-weight:bold;
            padding:6px;
            border:none;
        }
        QTableView::item {
            padding:5px;
            border-bottom:1px solid #eaeaea;
        }
        QTableView::item:selected {
            background-color:#d6e4ff;
            color:#000;
        }
    )");
    //加载ui
    showUI();
    // 自动加载排行榜
    loadGlobalRanking();
}

LeaderboardFeature::~LeaderboardFeature()
{
	delete ui;
}

void LeaderboardFeature::showUI()
{
	ui->leaderboardSelectBtn->setProperty("type", "primary");

    ui->leaderboardComboBox->clear();
    ui->leaderboardComboBox->addItem("比赛名称");
    ui->leaderboardComboBox->setCurrentIndex(0);

}

void LeaderboardFeature::loadGlobalRanking()
{
    QSqlQueryModel* model = competitionRecordsService->getGlobalRanking();
    qDebug() << model;
    paintTable(model); // 直接用你美化好的表格
}

void LeaderboardFeature::paintTable(QSqlQueryModel* model)
{
    QStandardItemModel* viewModel = new QStandardItemModel(this);

    // 表头
    viewModel->setHorizontalHeaderLabels({
        "排名", "用户名", "学号", "速度(WPM)", "准确率(%)", "总分"
        });

    for (int row = 0; row < model->rowCount(); ++row)
    {
        // 排名列
        QStandardItem* rankItem = new QStandardItem(QString::number(row + 1));
        rankItem->setTextAlignment(Qt::AlignCenter);
        viewModel->setItem(row, 0, rankItem);

        for (int col = 0; col < model->columnCount(); ++col)
        {
            QString text = model->data(model->index(row, col)).toString();
            QStandardItem* item = new QStandardItem(text);

            item->setTextAlignment(Qt::AlignCenter);

            viewModel->setItem(row, col + 1, item);
        }
    }

    ui->leaderboardTable->setModel(viewModel);

    // UI设置
    ui->leaderboardTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->leaderboardTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->leaderboardTable->setSortingEnabled(false); // ❗必须关掉

    ui->leaderboardTable->horizontalHeader()->setStretchLastSection(true);
    ui->leaderboardTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 前三名高亮
    for (int row = 0; row < viewModel->rowCount() && row < 3; row++) {
        QColor color;
        if (row == 0) color = QColor(255, 215, 0, 60);
        else if (row == 1) color = QColor(192, 192, 192, 60);
        else color = QColor(205, 127, 50, 60);

        for (int col = 0; col < viewModel->columnCount(); col++) {
            viewModel->item(row, col)->setBackground(color);
        }
    }
}

void LeaderboardFeature::on_leaderboardSelectBtn_clicked()
    {
        // 获取下拉框选中的 比赛名称
        QString compName = ui->leaderboardComboBox->currentText();

        CompetitionRecordsService service;
        QSqlQueryModel* model = nullptr;

        if (compName == "全部比赛") {
            // 查全局总榜
            model = service.getGlobalRanking();
        }
        else {
            // 按【比赛名称】查该场比赛排行
            model = service.getRankingByCompName(compName);
        }

        paintTable(model);
    }



