#include "DataVisualization.h"
#include "ChartService.h"
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include "usermanager.h"
#include <QPointF>
#include <QStandardItem>

DataVisualization::DataVisualization(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::DataVisualizationClass())
{
	ui->setupUi(this);
    //初始化指针
    m_competitionRecordsService = new CompetitionRecordsService(this);
    m_practiceRecordsService = new practiceRecordsService(this);

    updateUIShowStyle();
    //更新图标数据-比赛
    updatelineChartsData();
    updatesplineChartsData();
    updatebarChartsData();
    updatepieChartsData();
    updateTableView();
    //更新图标数据-练习
    updatelineChartsDataPractice();
    updatesplineChartsDataPractice();
    updatebarChartsDataPractice();
    updatepieChartsDataPractice();
    updateTableViewPractice();
    
}

DataVisualization::~DataVisualization()
{
	delete ui;
}

void DataVisualization::updateUIShowStyle()
{
    ui->centralWidget->setProperty("type", "StatusWidget");
}

QChart* DataVisualization::emptyChartsShow(const QString& message)
{
    QChart* emptyChart = new QChart();
    emptyChart->setTitle(message);
    emptyChart->legend()->hide();

    // 重要：创建默认坐标轴，否则图表可能显示为空白或报错
    emptyChart->createDefaultAxes();

    // 可选：美化一下，让文字居中或更大
    // emptyChart->animationOptions() = QChart::NoAnimation; 

    return emptyChart; // 返回指针
}

void DataVisualization::setChartSafe(QChartView* view, QChart* chart)
{
    if (!view) return;

    QChart* oldChart = view->chart();
    view->setChart(chart);

    delete oldChart;
}


//折线图
void DataVisualization::updatelineChartsData()
{
    
    //获取当前用户id
    /*UserManager& userMgr = UserManager::instance();
    int userID = userMgr.getCurrentUserID();*/

    //临时测试
    int userID = 1;

    QVector<QPointF> data = m_competitionRecordsService->getWPMData(userID);

    //处理空数据
    if (data.isEmpty()) {
        qDebug() << "Info: No competition records found for userId:" << userID;

        //读取emptyChartsShow();创建的图表
        QChart* emptyChart = emptyChartsShow("暂无比赛数据，快去参加一场吧！");
        
        ui->WPMChartView->setChart(emptyChart);
        return;
    }

    //ui->WPMChartView->setChart(ChartService::createLineChart(data, "WPM趋势"));
    setChartSafe(ui->WPMChartView,ChartService::createSplineChart(data, "WPM"));
}

void DataVisualization::updatesplineChartsData()
{
    //获取当前用户id
    /*UserManager& userMgr = UserManager::instance();
    int userID = userMgr.getCurrentUserID();*/

    //临时测试
    int userID = 1;

    QVector<QPointF> data = m_competitionRecordsService->getAccuracyData(userID);

    //处理空数据
    if (data.isEmpty()) {
        qDebug() << "Info: No competition records found for userId:" << userID;

        //读取emptyChartsShow();创建的图表
        QChart* emptyChart = emptyChartsShow("暂无比赛数据，快去参加一场吧！");

        ui->accuracyChartView->setChart(emptyChart);
        return;
    }
    
    setChartSafe(ui->accuracyChartView,ChartService::createSplineChart(data, "正确率"));
}

void DataVisualization::updatebarChartsData()
{
    QStringList categories;
    QVector<double> values;

    //获取当前用户id
    /*UserManager& userMgr = UserManager::instance();
    int userID = userMgr.getCurrentUserID();*/

    //临时测试
    int userID = 1;

    if (!m_competitionRecordsService->getFinalScoreBarData(userID, categories, values)) {
        
        //读取emptyChartsShow();创建的图表
        QChart* emptyChart = emptyChartsShow("暂无比赛数据，快去参加一场吧！");

        ui->finalScorehartView->setChart(emptyChart);
        return;
    }
        
    setChartSafe(ui->finalScorehartView, ChartService::createBarChart(categories, values, "历史成绩"));
}

void DataVisualization::updatepieChartsData()
{
    int correct = 0;
    int error = 0;

    //获取当前用户id
    /*UserManager& userMgr = UserManager::instance();
    int userID = userMgr.getCurrentUserID();*/

    int userID = 1;

    if (!m_competitionRecordsService->getCharCountData(userID, correct, error)) {
        
        //读取emptyChartsShow();创建的图表
        QChart* emptyChart = emptyChartsShow("暂无比赛数据，快去参加一场吧！");

        ui->fontChartView->setChart(emptyChart);
        return;
    }
       

    // 防止全为0导致饼图崩
    if (correct == 0 && error == 0)
    {
        correct = 1;
        error = 0;
    }

    setChartSafe(ui->fontChartView, ChartService::createPieChart(correct, error, "正确率"));

}

void DataVisualization::updateTableView()
{

    /*UserManager& userMgr = UserManager::instance();
    int userID = userMgr.getCurrentUserID();*/

    int userID = 1; // 改成当前用户

    auto records = m_competitionRecordsService->getFullRecords(userID);

    QStandardItemModel* model = new QStandardItemModel(this);

    // 表头
    model->setHorizontalHeaderLabels({
        "比赛名称", "文章名称", "WPM", "正确率",
        "正确字数", "错误字数", "最终得分", "耗时(s)"
        });

    // 填充数据
    for (int row = 0; row < records.size(); ++row)
    {
        const auto& r = records[row];

        model->setItem(row, 0, new QStandardItem(r.compName));
        model->setItem(row, 1, new QStandardItem(r.articleName));
        model->setItem(row, 2, new QStandardItem(QString::number(r.wpm)));

        // 正确率格式化
        model->setItem(row, 3, new QStandardItem(
            QString("%1%").arg(r.accuracy, 0, 'f', 1)
        ));

        model->setItem(row, 4, new QStandardItem(QString::number(r.correctCount)));
        model->setItem(row, 5, new QStandardItem(QString::number(r.errorCount)));
        model->setItem(row, 6, new QStandardItem(QString::number(r.finalScore)));

        // 时间（秒）
        model->setItem(row, 7, new QStandardItem(QString::number(r.timeUsed)));
    }

    ui->recentComtableView->setModel(model);

    // UI优化（很重要）
    ui->recentComtableView->horizontalHeader()->setStretchLastSection(true);
    ui->recentComtableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->recentComtableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->recentComtableView->setAlternatingRowColors(true);
}

//练习数据可视化
void DataVisualization::updatelineChartsDataPractice()
{
    //获取当前用户id
    /*UserManager& userMgr = UserManager::instance();
    int userID = userMgr.getCurrentUserID();*/

    //临时测试
    int userID = 1;

    QVector<QPointF> data = m_practiceRecordsService->getWPMPracticeData(userID);

    //处理空数据
    if (data.isEmpty()) {
        qDebug() << "Info: No competition records found for userId:" << userID;

        //读取emptyChartsShow();创建的图表
        QChart* emptyChart = emptyChartsShow("暂无比赛数据，快去参加一场吧！");

        ui->PracticeWPMChartView->setChart(emptyChart);
        return;
    }

    //ui->WPMChartView->setChart(ChartService::createLineChart(data, "WPM趋势"));
    setChartSafe(ui->PracticeWPMChartView, ChartService::createSplineChart(data, "WPM"));

}

void DataVisualization::updatesplineChartsDataPractice()
{
    //获取当前用户id
    /*UserManager& userMgr = UserManager::instance();
    int userID = userMgr.getCurrentUserID();*/

    //临时测试
    int userID = 1;

    QVector<QPointF> data = m_practiceRecordsService->getAccuracyPracticeData(userID);

    //处理空数据
    if (data.isEmpty()) {
        qDebug() << "Info: No competition records found for userId:" << userID;

        //读取emptyChartsShow();创建的图表
        QChart* emptyChart = emptyChartsShow("暂无比赛数据，快去参加一场吧！");

        ui->PraceticeaccuracyChartView->setChart(emptyChart);
        return;
    }

    setChartSafe(ui->PraceticeaccuracyChartView, ChartService::createSplineChart(data, "正确率"));
}

void DataVisualization::updatebarChartsDataPractice()
{
    QStringList categories;
    QVector<double> values;

    //获取当前用户id
    /*UserManager& userMgr = UserManager::instance();
    int userID = userMgr.getCurrentUserID();*/

    //临时测试
    int userID = 1;

    if (!m_practiceRecordsService->getFinalScoreBarPracticeData(userID, categories, values)) {

        //读取emptyChartsShow();创建的图表
        QChart* emptyChart = emptyChartsShow("暂无比赛数据，快去参加一场吧！");

        ui->PraceticefinalScorehartView->setChart(emptyChart);
        return;
    }

    setChartSafe(ui->PraceticefinalScorehartView, ChartService::createBarChart(categories, values, "历史成绩"));
}

void DataVisualization::updatepieChartsDataPractice()
{
    int correct = 0;
    int error = 0;

    //获取当前用户id
    /*UserManager& userMgr = UserManager::instance();
    int userID = userMgr.getCurrentUserID();*/

    int userID = 1;

    if (!m_practiceRecordsService->getCharCountPracticeData(userID, correct, error)) {

        //读取emptyChartsShow();创建的图表
        QChart* emptyChart = emptyChartsShow("暂无比赛数据，快去参加一场吧！");

        ui->PracticefontChartView->setChart(emptyChart);
        return;
    }


    // 防止全为0导致饼图崩
    if (correct == 0 && error == 0)
    {
        correct = 1;
        error = 0;
    }

    setChartSafe(ui->PracticefontChartView, ChartService::createPieChart(correct, error, "正确率"));

}

void DataVisualization::updateTableViewPractice()
{
    /*UserManager& userMgr = UserManager::instance();
    int userID = userMgr.getCurrentUserID();*/

    int userID = 1; // 改成当前用户

    auto records = m_practiceRecordsService->getFullPracticeRecords(userID);

    QStandardItemModel* model = new QStandardItemModel(this);

    // 表头
    model->setHorizontalHeaderLabels({
        "练习题目", "WPM", "正确率",
        "正确字数", "错误字数", "耗时(s)", "练习时间"
        });

    // 填充数据
    for (int row = 0; row < records.size(); ++row)
    {
        const auto& r = records[row];

        model->setItem(row, 0, new QStandardItem(r.articleName));
        model->setItem(row, 1, new QStandardItem(QString::number(r.wpm)));

        // 正确率格式化（和比赛一致）
        model->setItem(row, 2, new QStandardItem(
            QString("%1%").arg(r.accuracy, 0, 'f', 1)
        ));

        model->setItem(row, 3, new QStandardItem(QString::number(r.correctCount)));
        model->setItem(row, 4, new QStandardItem(QString::number(r.errorCount)));

        // 耗时（秒）
        model->setItem(row, 5, new QStandardItem(QString::number(r.timeUsed)));

        // 练习时间（直接显示字符串，保持和你比赛风格一致）
        model->setItem(row, 6, new QStandardItem(r.practiceTime));
    }

    ui->PracticerecentComtableView->setModel(model);

    // UI优化（完全复用你的写法）
    ui->PracticerecentComtableView->horizontalHeader()->setStretchLastSection(true);
    ui->PracticerecentComtableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->PracticerecentComtableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->PracticerecentComtableView->setAlternatingRowColors(true);
}




