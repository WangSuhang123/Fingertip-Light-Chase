#pragma once

#include <QObject>
#include "CompetitionRecordsDao.h"

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

private:
	CompetitionRecordsDao competitionrecordsdao;

};

