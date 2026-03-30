#pragma once

#include <QObject>
#include <QPointF>
#include <QSqlQueryModel>

struct CompetitionFullRecord
{
	QString compName;
	QString articleName;
	int wpm;
	double accuracy;
	int correctCount;
	int errorCount;
	double finalScore;
	int timeUsed;
};

class CompetitionRecordsDao  : public QObject
{
	Q_OBJECT

public:
	CompetitionRecordsDao(QObject *parent = nullptr);
	~CompetitionRecordsDao();

	//用户通过特定条件完成比赛，比赛成绩插入数据库，返回bool值
	bool insertCompetitionRecords(int comID,int userID, int WPM, double accuracy,int UsedTime, int CorrectCount,int ErrorCount, double finalScore);

	//判断用户是否已经参加过某场比赛，返回bool值
	bool existsRecord(int compId, int userId);


	//数据可视化信息
	// 比赛数据
	//获取用户的wpm信息
	QVector<QPointF> getWPMData(int userId);
	//获取正确率
	QVector<QPointF> getAccuracyData(int userId);
	//获取finalScore，需要返回两个类型的值，使用了“&”，表示引用传递，直接操作外面的变量
	bool getFinalScoreBarData(int userId,QStringList& categories,QVector<double>& values);
	//数据可视化表格
	QVector<CompetitionFullRecord> getFullRecords(int userId);
	//获取字数（正确和错误）
	bool getCharCountData(int userId,int& totalCorrect,int& totalError);

	//查询最近成绩
	QVector<CompetitionFullRecord> getRecentRecords(int userId);
	
	//比赛成绩表-条件查询
	QSqlQueryModel* queryCompScoreByDynamicField(const QString& fieldName, const QString& keyword);

	//比赛成绩查询-全部
	QSqlQueryModel* queryAllCompScoresBySchool(const QString& schoolName);


};

