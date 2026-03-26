#pragma once

#include <QObject>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QPieSeries>
#include <QVector>
#include <QPointF>

class ChartService  : public QObject
{
	Q_OBJECT

public:
	ChartService(QObject *parent);
	~ChartService();

    //统一图表样式
    static void applyChartStyle(QChart* chart);

    // 折线图（WPM趋势）
    static QChart* createLineChart(const QVector<QPointF>& data, const QString& title);

    //样条曲线图
    static QChart* createSplineChart(const QVector<QPointF>& data, const QString& title);

    // 柱状图（排行榜）
    static QChart* createBarChart(const QStringList& categories, const QVector<double>& values, const QString& title);

    // 饼图（正确率）
    static QChart* createPieChart(double correct, double wrong, const QString& title);

    //数据逻辑

};

