#pragma once

#include <QObject>

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
};

