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
	bool insertPracticeRecordsService(int UserId, int TotalChars, int TypedChars, int CorrectChars, int ErrorChars, int WPM, int UsedTime, double accuracy);

private:
	practiceRecordsDao practicerecordsDao;

};

