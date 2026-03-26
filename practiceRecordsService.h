#pragma once

#include <QObject>
#include "practiceRecordsDao.h"

class practiceRecordsService  : public QObject
{
	Q_OBJECT

public:
	practiceRecordsService(QObject *parent);
	~practiceRecordsService();

	//解耦层
	//插入练习记录表
	bool insertPracticeRecordsService(int UserId, int TotalChars, int TypedChars, int CorrectChars, int ErrorChars, int WPM, int UsedTime, double accuracy,int articleID);

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

private:
	practiceRecordsDao practicerecordsDao;

};

