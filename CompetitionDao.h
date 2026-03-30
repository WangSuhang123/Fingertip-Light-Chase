#pragma once

#include <QObject>
#include <QSqlQueryModel>
#include <QSqlTableModel>


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

    //通过比赛id来查询比赛信息
    QVariantMap getCompetitionById(int compId);

    
    //综合管理比赛表
    //全查询
    QSqlQueryModel* selectAllCompetitions(const QString& schoolName);
    //条件查询
    QSqlQueryModel* queryCompByDynamicField(const QString& schoolName, const QString& fieldName, const QString& keyword);

    //删除
    bool deleteCompetition(int compId);




private:



};

