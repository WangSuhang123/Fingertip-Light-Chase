#pragma once

#include <QObject>
#include "CompetitionDao.h"

class CompetitionService  : public QObject
{
	Q_OBJECT

public:
	CompetitionService(QObject *parent = nullptr);
	~CompetitionService();

	//插入数据库业务逻辑
	bool insertCompetition(const QString& competitionName,
        int articleId,
        int creatorId,
        const QString& targetSchool,
        const QDateTime& startTime,
        const QDateTime& endTime,
        int DurationMinutes);

    QList<QVariantMap> getCompetitionList(const QString& school);
    QVariantMap getCompetitionById(int compId);


    //综合管理比赛表
    QSqlQueryModel* selectAllCompetitions(const QString& schoolName);
    //条件查询
    QSqlQueryModel* queryCompByDynamicField(const QString& schoolName, const QString& fieldName, const QString& keyword);
    //删除
    bool deleteCompetition(int compId);

private:
    CompetitionDao m_competitionDao;
};

