#pragma once

#include <QObject>
#include "CompetitionRecordsDao.h"
#include <QVector>
#include <QPointF>
#include <QSqlQueryModel>

class CompetitionRecordsService  : public QObject
{
	Q_OBJECT

public:
	CompetitionRecordsService(QObject *parent = nullptr);
	~CompetitionRecordsService();

	//插入比赛成绩，解耦层
	bool insertCompetitionRecords(int comID, int userID, int WPM, double accuracy, int UsedTime, int CorrectCount, int ErrorCount, double finalScore);

	//判断用户是否已经参加过某场比赛，返回bool值
	bool hasUserJoined(int compId, int userId);

	//数据可视化信息
	//获取用户的wpm信息
	QVector<QPointF> getWPMData(int userId);

	//获取用户的accuracy
	QVector<QPointF> getAccuracyData(int userId);

	//finalScore
	bool getFinalScoreBarData(int userId, QStringList& categories, QVector<double>& values);
	//获取字数（正确和错误）
	bool getCharCountData(int userId, int& totalCorrect, int& totalError);
	//数据表格
	QVector<CompetitionFullRecord> getFullRecords(int userId);


	//查询最近成绩
	QVector<CompetitionFullRecord> getRecentRecords(int userId);

	//比赛成绩表
	QSqlQueryModel* queryCompScoreByDynamicField(const QString& fieldName, const QString& keyword);


	//比赛成绩查询-全部
	QSqlQueryModel* queryAllCompScoresBySchool(const QString& schoolName);

	//排行榜
	QSqlQueryModel* getRankingByCompName(const QString& compName);
	QSqlQueryModel* getGlobalRanking();

private:
	CompetitionRecordsDao competitionrecordsdao;

};

