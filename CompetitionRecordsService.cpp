#include "CompetitionRecordsService.h"

CompetitionRecordsService::CompetitionRecordsService(QObject *parent)
	: QObject(parent)
{}

CompetitionRecordsService::~CompetitionRecordsService()
{}

bool CompetitionRecordsService::insertCompetitionRecords(int comID, int userID, int WPM, double accuracy, int UsedTime, int CorrectCount, int ErrorCount, double finalScore)
{
	//调用dao层方法，插入数据
	bool isSuccess = competitionrecordsdao.insertCompetitionRecords(comID, userID, WPM, accuracy, UsedTime, CorrectCount, ErrorCount,finalScore);

	return isSuccess;
}

bool CompetitionRecordsService::hasUserJoined(int compId, int userId)
{
	return competitionrecordsdao.existsRecord(compId, userId);
}


