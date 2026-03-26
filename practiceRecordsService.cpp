#include "practiceRecordsService.h"

practiceRecordsService::practiceRecordsService(QObject *parent)
	: QObject(parent),
	practicerecordsDao(this)
{}

practiceRecordsService::~practiceRecordsService()
{}

bool practiceRecordsService::insertPracticeRecordsService(int UserId, int TotalChars, int TypedChars, int CorrectChars, int ErrorChars, int WPM, int UsedTime, double accuracy, int articleID)
{
	//调用DAO层的insertPracticeRecords方法，将数据插入到数据库中
	bool isSuccess = practicerecordsDao.insertPracticeRecords(UserId, TotalChars, TypedChars, CorrectChars, ErrorChars, WPM, UsedTime, accuracy, articleID);
	
	return isSuccess;
}

QVector<QPointF> practiceRecordsService::getWPMPracticeData(int userId)
{
	return practicerecordsDao.getWPMPracticeData(userId);
}

QVector<QPointF> practiceRecordsService::getAccuracyPracticeData(int userId)
{
	return practicerecordsDao.getAccuracyPracticeData(userId);
}

bool practiceRecordsService::getFinalScoreBarPracticeData(int userId, QStringList& categories, QVector<double>& values)
{
	return practicerecordsDao.getFinalScoreBarPracticeData(userId, categories, values);
}

QVector<PracticeFullRecord> practiceRecordsService::getFullPracticeRecords(int userId)
{
	return practicerecordsDao.getFullPracticeRecords(userId);
}

bool practiceRecordsService::getCharCountPracticeData(int userId, int& totalCorrect, int& totalError)
{
	return practicerecordsDao.getCharCountPracticeData(userId, totalCorrect, totalError);
}

