#pragma once

#include <QObject>
#include <QPointF>

struct PracticeFullRecord
{
	QString articleName;   // 练习题目
	int wpm;               // 速度
	double accuracy;       // 正确率
	int correctCount;      // 正确字数
	int errorCount;        // 错误字数
	int timeUsed;          // 耗时（秒）
	QString practiceTime;  // 练习时间
};

class practiceRecordsDao  : public QObject
{
	Q_OBJECT

		//操作练习记录表

public:
	practiceRecordsDao(QObject* parent = nullptr);
	~practiceRecordsDao();

	//插入练习数据，返回bool
	bool insertPracticeRecords(int UserId, int TotalChars, int TypedChars, int CorrectChars, int ErrorChars, int WPM, int UsedTime, double accuracy,int articleID);

	//练习数据可视化查询
	//获取用户的wpm信息
	QVector<QPointF> getWPMPracticeData(int userId);
	//获取正确率
	QVector<QPointF> getAccuracyPracticeData(int userId);
	//获取finalScore，需要返回两个类型的值，使用了“&”，表示引用传递，直接操作外面的变量
	bool getFinalScoreBarPracticeData(int userId, QStringList& categories, QVector<double>& values);
	//数据可视化表格
	QVector<PracticeFullRecord> getFullPracticeRecords(int userId);
	//获取字数（正确和错误）
	bool getCharCountPracticeData(int userId, int& totalCorrect, int& totalError);


};

