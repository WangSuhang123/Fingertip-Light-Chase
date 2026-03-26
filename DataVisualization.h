#pragma once

#include <QMainWindow>
#include "ui_DataVisualization.h"
#include "CompetitionRecordsService.h"
#include "practiceRecordsService.h"
#include <QtCharts/QChartView> 
#include <QtCharts/QChart>

QT_BEGIN_NAMESPACE
namespace Ui { class DataVisualizationClass; };
QT_END_NAMESPACE

class DataVisualization : public QMainWindow
{
	Q_OBJECT

public:
	DataVisualization(QWidget *parent = nullptr);
	~DataVisualization();

private:
	Ui::DataVisualizationClass *ui;

	//更新ant风格
	void updateUIShowStyle();

	//更新图标数据
	//比赛数据
	//折线图
	void updatelineChartsData();
	//样条曲线图
	void updatesplineChartsData();
	//柱状图
	void updatebarChartsData();
	//饼状图
	void updatepieChartsData();
	//数据表格
	void updateTableView();

	//练习数据
	//折线图
	void updatelineChartsDataPractice();
	//样条曲线图
	void updatesplineChartsDataPractice();
	//柱状图
	void updatebarChartsDataPractice();
	//饼状图
	void updatepieChartsDataPractice();
	//数据表格
	void updateTableViewPractice();


	//当没有数据的时候，图表位置显示提示
	QChart* emptyChartsShow(const QString& message);
	//内存释放
	void setChartSafe(QChartView* view, QChart* chart);

	// 可选：如果你需要在成员变量中持有 chart 指针
	QChart* m_chart;
	//使用service表解耦比赛
	CompetitionRecordsService* m_competitionRecordsService;
	//练习service
	practiceRecordsService* m_practiceRecordsService;

};

