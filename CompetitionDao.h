#pragma once

#include <QObject>

class CompetitionDao  : public QObject
{
	Q_OBJECT

public:
	CompetitionDao(QObject *parent = nullptr);
	~CompetitionDao();

	//插入新增比赛信息，返回bool
	bool insertCompetition(
        const QString& competitionName,
        int articleId,
        int creatorId,
        const QString& targetSchool,
        const QDateTime& startTime,
        const QDateTime& endTime,
        int DurationMinutes);
    //通过学校来查询比赛信息
    QList<QVariantMap> getCompetitionsBySchool(const QString& school);


private:



};

