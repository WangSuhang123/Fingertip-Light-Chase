#pragma once

#include <QObject>

class practiceRecordsDao  : public QObject
{
	Q_OBJECT

		//操作练习记录表

public:
	practiceRecordsDao(QObject* parent = nullptr);
	~practiceRecordsDao();

	//插入练习数据，返回bool
	bool insertPracticeRecords(int UserId, int TotalChars, int TypedChars, int CorrectChars, int ErrorChars, int WPM, int UsedTime, double accuracy);




};

