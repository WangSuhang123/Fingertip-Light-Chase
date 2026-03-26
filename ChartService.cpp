#include "ChartService.h"
#include <QtCharts/QChart>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QSplineSeries>
#include <QGraphicsLayout>

ChartService::ChartService(QObject *parent)
	: QObject(parent)
{}

ChartService::~ChartService()
{}

void ChartService::applyChartStyle(QChart * chart)
{
    chart->setBackgroundVisible(false);
    chart->setDropShadowEnabled(false);

    chart->setMargins(QMargins(0, 0, 0, 0));
    chart->layout()->setContentsMargins(0, 0, 0, 0);
    chart->setBackgroundRoundness(0);

    chart->setAnimationOptions(QChart::SeriesAnimations);

    QFont titleFont("Microsoft YaHei", 11, QFont::Bold);
    chart->setTitleFont(titleFont);

    chart->legend()->setFont(QFont("Microsoft YaHei", 9));
}

//折线图
QChart* ChartService::createLineChart(const QVector<QPointF>& data, const QString& title)
{
    auto* series = new QLineSeries();

    for (const auto& p : data)
        series->append(p);

    QPen pen(QColor(0, 170, 255));
    pen.setWidth(3);
    series->setPen(pen);
    series->setPointsVisible(true);

    auto* chart = new QChart();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle(title);

    applyChartStyle(chart);

    return chart;
}

//样条曲线图
QChart* ChartService::createSplineChart(const QVector<QPointF>& data, const QString& title)
{
    auto* series = new QSplineSeries();

    for (const auto& p : data)
        series->append(p);

    QPen pen(QColor(0, 170, 255));
    pen.setWidth(3);
    series->setPen(pen);

    auto* chart = new QChart();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle(title);

    applyChartStyle(chart);

    return chart;
}

QChart* ChartService::createBarChart(const QStringList& categories, const QVector<double>& values, const QString& title)
{
    auto* set = new QBarSet("成绩");

    for (double v : values)
        *set << v;

    set->setColor(QColor(0, 170, 255));

    auto* series = new QBarSeries();
    series->append(set);

    auto* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(title);

    auto* axisX = new QBarCategoryAxis();
    axisX->append(categories);

    chart->createDefaultAxes();
    chart->setAxisX(axisX, series);

    applyChartStyle(chart);

    return chart;
}

QChart* ChartService::createPieChart(double correct, double wrong, const QString& title)
{
    auto* series = new QPieSeries();

    auto* slice1 = series->append("正确", correct);
    auto* slice2 = series->append("错误", wrong);

    slice1->setColor(QColor(0, 170, 255));   // 天蓝
    slice2->setColor(QColor(200, 200, 200)); // 灰色

    slice1->setLabelVisible();
    slice2->setLabelVisible();

    auto* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(title);

    applyChartStyle(chart);

    return chart;
}

