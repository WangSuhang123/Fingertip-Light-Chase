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

QVector<QPointF> CompetitionRecordsService::getWPMData(int userId)
{
	return competitionrecordsdao.getWPMData(userId);
}

QVector<QPointF> CompetitionRecordsService::getAccuracyData(int userId)
{
	return competitionrecordsdao.getAccuracyData(userId);
}

bool CompetitionRecordsService::getFinalScoreBarData(int userId, QStringList& categories, QVector<double>& values)
{
	return competitionrecordsdao.getFinalScoreBarData(userId, categories, values);
}

bool CompetitionRecordsService::getCharCountData(int userId, int& totalCorrect, int& totalError)
{
	return competitionrecordsdao.getCharCountData(userId, totalCorrect, totalError);
}

QVector<CompetitionFullRecord> CompetitionRecordsService::getFullRecords(int userId)
{
	return competitionrecordsdao.getFullRecords(userId);
}

QVector<CompetitionFullRecord> CompetitionRecordsService::getRecentRecords(int userId)
{
	return competitionrecordsdao.getRecentRecords(userId);
}

QSqlQueryModel* CompetitionRecordsService::queryCompScoreByDynamicField(const QString& fieldName, const QString& keyword)
{
	return competitionrecordsdao.queryCompScoreByDynamicField(fieldName, keyword);
}

QSqlQueryModel* CompetitionRecordsService::queryAllCompScoresBySchool(const QString& schoolName)
{
	return competitionrecordsdao.queryAllCompScoresBySchool(schoolName);
}



QSqlQueryModel* CompetitionRecordsService::getRankingByCompName(const QString& compName)
{
	return competitionrecordsdao.getRankingByCompName(compName);
}

QSqlQueryModel* CompetitionRecordsService::getGlobalRanking()
{
	return competitionrecordsdao.getGlobalRanking();
}


