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

QSqlQueryModel* CompetitionDao::selectAllCompetitions(const QString& schoolName)
{
    QSqlDatabase& db = DatabaseManager::instance().getDatabase();

    QSqlQuery query(db);
    query.prepare(R"(
        SELECT
            c.CompID,
            c.CompName,
            a.ArticleName,
            u.UserName,
            c.TargetSchool,
            c.StartTime,
            c.EndTime,
            c.CreatedAt,
            c.DurationMinutes
        FROM competitions c
        JOIN articleinfo a ON c.ArticleID = a.ArticleID
        JOIN userinfo u ON c.CreatorID = u.UserID
        WHERE c.TargetSchool = ?
    )");

    query.addBindValue(schoolName);

    if (!query.exec()) {
        qCritical() << "查询比赛失败：" << query.lastError().text();
        return nullptr;
    }

    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(std::move(query));
    return model;
}

QSqlQueryModel* CompetitionDao::queryCompByDynamicField(const QString& schoolName, const QString& fieldName, const QString& keyword)
{
    QSqlDatabase db = DatabaseManager::instance().getDatabase();
    QSqlQueryModel* model = new QSqlQueryModel;

    // 正确的连表查询 + 动态字段
    QString sql = R"(
        SELECT
            c.CompID,
            c.CompName,
            a.ArticleName,
            u.UserName AS Creator,
            c.TargetSchool,
            c.StartTime,
            c.EndTime,
            c.CreatedAt,
            c.DurationMinutes
        FROM competitions c
        JOIN articleinfo a ON c.ArticleID = a.ArticleID
        JOIN userinfo u ON c.CreatorID = u.UserID
        WHERE c.TargetSchool = ? AND )" + fieldName + R"( LIKE ?
    )";

    QSqlQuery query(db);
    query.prepare(sql);

    query.addBindValue(schoolName);
    query.addBindValue("%" + keyword + "%");

    if (!query.exec()) {
        qDebug() << "比赛查询失败：" << query.lastError().text();
        qDebug() << "SQL：" << query.executedQuery();
    }

    model->setQuery(query);
    return model;
}

bool CompetitionDao::deleteCompetition(int compId)
{
    QSqlDatabase db = DatabaseManager::instance().getDatabase();
    QSqlQuery query(db);
    query.prepare(R"(DELETE FROM competitions WHERE CompID = :id)");

    query.bindValue(":id", compId);

    if (!query.exec()) {
        qDebug() << "删除比赛失败：" << query.lastError().text();
        return false;
    };

    return true;
}

