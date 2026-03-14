#include "practiceRecordsService.h"

practiceRecordsService::practiceRecordsService(QObject *parent)
	: QObject(parent),
	practicerecordsDao(this)
{}

practiceRecordsService::~practiceRecordsService()
{}

bool practiceRecordsService::insertPracticeRecordsService(int UserId, int TotalChars, int TypedChars, int CorrectChars, int ErrorChars, int WPM, int UsedTime, double accuracy)
{
	//调用DAO层的insertPracticeRecords方法，将数据插入到数据库中
	bool isSuccess = practicerecordsDao.insertPracticeRecords(UserId, TotalChars, TypedChars, CorrectChars, ErrorChars, WPM, UsedTime, accuracy);
	
	return isSuccess;
}

