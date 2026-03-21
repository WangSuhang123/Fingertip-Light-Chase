#include "CompetitionDao.h"
#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>

CompetitionDao::CompetitionDao(QObject *parent)
	: QObject(parent)
{}

CompetitionDao::~CompetitionDao()
{}

bool CompetitionDao::insertCompetition(const QString& competitionName,
    int articleId,
    int creatorId,
    const QString& targetSchool,
    const QDateTime& startTime,
    const QDateTime& endTime,
    int DurationMinutes)
{
    QSqlQuery query;

    // 预处理SQL（防止SQL注入 + 更安全）
    query.prepare(R"(
        INSERT INTO competitions
        (CompName, ArticleID, CreatorID, TargetSchool,
         StartTime, EndTime, DurationMinutes)
        VALUES
        (:name, :articleId, :creatorId, :school,
         :startTime, :endTime, :duration)
    )");

    // 绑定参数
    query.bindValue(":name", competitionName);
    query.bindValue(":articleId", articleId);
    query.bindValue(":creatorId", creatorId);
    query.bindValue(":school", targetSchool);
    query.bindValue(":startTime", startTime);
    query.bindValue(":endTime", endTime);
    query.bindValue(":duration", DurationMinutes);

    // 执行SQL
    if (!query.exec())
    {
        qDebug() << "插入比赛失败：" << query.lastError().text();
        return false;
    }

    qDebug() << "比赛插入成功！";
    return true;
}
QList<QVariantMap> CompetitionDao::getCompetitionsBySchool(const QString& school)
{
    QList<QVariantMap> list;
    QSqlQuery query;

    query.prepare(R"(
        SELECT CompID, CompName, StartTime, EndTime, DurationMinutes
        FROM competitions
        WHERE TargetSchool = :school
        ORDER BY StartTime DESC
    )");

    query.bindValue(":school", school);

    if (!query.exec())
    {
        qDebug() << "查询比赛失败：" << query.lastError().text();
        return list;
    }

    while (query.next())
    {
        QVariantMap map;

        map["compId"] = query.value("CompID");
        map["name"] = query.value("CompName");
        map["startTime"] = query.value("StartTime");
        map["endTime"] = query.value("EndTime");
        map["duration"] = query.value("DurationMinutes");

        list.append(map);
    }

    return list;
}

QVariantMap CompetitionDao::getCompetitionById(int compId)
{
    QSqlQuery query;

    query.prepare(R"(
        SELECT ArticleID, DurationMinutes
        FROM competitions
        WHERE CompID = :id
    )");

    query.bindValue(":id", compId);

    QVariantMap map;

    if (query.exec() && query.next())
    {
        map["articleId"] = query.value("ArticleID");
        map["duration"] = query.value("DurationMinutes");
    }

    return map;
}