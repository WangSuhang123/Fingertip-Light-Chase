#include "CompetitionRecordsDao.h"
#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QPointF>

CompetitionRecordsDao::CompetitionRecordsDao(QObject *parent)
	: QObject(parent)
{}

CompetitionRecordsDao::~CompetitionRecordsDao()
{}

bool CompetitionRecordsDao::insertCompetitionRecords(int comID, int userID, int WPM, double accuracy, int UsedTime, int CorrectCount, int ErrorCount, double finalScore)
{
    //获取DatabaseManager的单例连接（引用）
    QSqlDatabase& db = DatabaseManager::instance().getDatabase();
    //显式指定连接创建QSqlQuery，不再默认的空参构造
    QSqlQuery query(db);    //QSqlQuery 自动使用「默认连接」
    query.prepare(R"(INSERT INTO competition_records(CompID, UserID, WPM, Accuracy, TimeUsed, CorrectCount, ErrorCount, FinalScore)
    VALUES(:comid, :userid, :wpm, :accuracy, :usedtime, :correctcount, :errorcount, :finalscore)
)");

    //逐个绑定参数
    query.bindValue(":comid", comID);
    query.bindValue(":userid", userID);
    query.bindValue(":wpm", WPM);
    query.bindValue(":accuracy", accuracy);
    query.bindValue(":usedtime", UsedTime);
    query.bindValue(":correctcount", CorrectCount);
    query.bindValue(":errorcount", ErrorCount);
    query.bindValue(":finalscore", finalScore);


    bool execOk = query.exec();
    qDebug() << "===========================================";
    qDebug() << execOk;

    if (!execOk) {
        // 打印执行失败的详细错误信息（核心新增）
        qDebug() << "[注册失败] SQL语句执行失败：" << query.lastError().text();
        qDebug() << "[错误详情] 错误类型：" << query.lastError().type();
        qDebug() << "[错误详情] 数据库驱动错误：" << query.lastError().driverText();
        qDebug() << "[错误详情] 数据库原生错误：" << query.lastError().databaseText();
        return false;
    }
    else {
        return true;
    }
}

bool CompetitionRecordsDao::existsRecord(int compId, int userId)
{
    QSqlQuery query;

    query.prepare(R"(
        SELECT 1 FROM competition_records
        WHERE CompID = :compId AND UserID = :userId
        LIMIT 1
    )");

    query.bindValue(":compId", compId);
    query.bindValue(":userId", userId);

    if (!query.exec()) {
        qDebug() << "查询失败:" << query.lastError();
        return false;
    }

    return query.next(); // 有数据 = 已参加
}

QVector<QPointF> CompetitionRecordsDao::getWPMData(int userId)
{
    QVector<QPointF> data;

    QSqlQuery query;

    // 1. 准备 SQL 语句
    // 注意：确保表名 competitions_wpm 和字段名 CompID, WPM, UserID 与数据库完全一致
    QString sql = R"(SELECT CompID, WPM FROM competition_records WHERE UserID = :userId ORDER BY CompID ASC)";

    query.prepare(sql);
    query.bindValue(":userId", userId);

    // 2. 执行查询
    if (!query.exec()) {
        // 【重要】如果执行失败，输出错误信息到调试控制台
        qDebug() << "SQL Error in getWPMData:" << query.lastError().text();
        qDebug() << "Failed SQL:" << query.lastQuery();
        return data; // 返回空向量
    }

    // 3. 遍历结果集
    int index = 0; // 用于生成连续的 X 轴坐标 (0, 1, 2...)

    while (query.next()) {

        // 使用自增索引作为 X 轴，避免 CompID 不连续导致图表留白
        double wpm = query.value("WPM").toDouble();

        // 这里 X 轴使用 index (0, 1, 2...)，如果你需要在图表上显示具体的 CompID，
        // 可以在 ChartService 中使用 QBarCategoryAxis 或者自定义 X 轴标签
        data.append(QPointF(index, wpm));

        index++;
    }

    // 可选：如果没有数据，打印提示
    if (data.isEmpty()) {
        qDebug() << "No WPM data found for userId:" << userId;
    }

    return data;
}

QVector<QPointF> CompetitionRecordsDao::getAccuracyData(int userId)
{
    QVector<QPointF> data;

    QSqlQuery query;

    // 1. 准备 SQL 语句
    // 注意：确保表名 competitions_wpm 和字段名 CompID, WPM, UserID 与数据库完全一致
    QString sql = R"(SELECT CompID, accuracy FROM competition_records WHERE UserID = :userId ORDER BY CompID ASC)";

    query.prepare(sql);
    query.bindValue(":userId", userId);

    // 2. 执行查询
    if (!query.exec()) {
        // 【重要】如果执行失败，输出错误信息到调试控制台
        qDebug() << "SQL Error in getWPMData:" << query.lastError().text();
        qDebug() << "Failed SQL:" << query.lastQuery();
        return data; // 返回空向量
    }

    // 3. 遍历结果集
    int index = 0; // 用于生成连续的 X 轴坐标 (0, 1, 2...)

    while (query.next()) {

        // 使用自增索引作为 X 轴，避免 CompID 不连续导致图表留白
        double wpm = query.value("Accuracy").toDouble();

        data.append(QPointF(index, wpm));

        index++;
    }

    // 可选：如果没有数据，打印提示
    if (data.isEmpty()) {
        qDebug() << "No accuracy data found for userId:" << userId;
    }

    return data;
}


bool CompetitionRecordsDao::getFinalScoreBarData(int userId,QStringList& categories,QVector<double>& values)
{
    categories.clear();
    values.clear();

    QSqlQuery query;

    QString sql = R"(
        SELECT CompID, finalScore
        FROM competition_records
        WHERE UserID = :userId
        ORDER BY CompID ASC
    )";

    query.prepare(sql);
    query.bindValue(":userId", userId);

    if (!query.exec()) {
        qDebug() << "SQL Error in getFinalScoreBarData:" << query.lastError().text();
        return false;
    }

    int index = 1;  // 用于显示 第1场、第2场...

    while (query.next()) {

        double score = query.value("finalScore").toDouble();

        // X轴：第几场比赛（更直观）
        categories.append(QString("第%1场").arg(index));

        // Y轴：分数
        values.append(score);

        index++;
    }
    if (values.isEmpty()) {
        qDebug() << "No finalScore data for userId:" << userId;
        return false;
    }

    return true;
}

bool CompetitionRecordsDao::getCharCountData(int userId, int& totalCorrect, int& totalError)
{
    totalCorrect = 0;
    totalError = 0;

    QSqlQuery query;

    QString sql = R"(
        SELECT 
            SUM(CorrectCount) AS totalCorrect,
            SUM(ErrorCount) AS totalError
        FROM competition_records
        WHERE UserID = :userId
    )";

    query.prepare(sql);
    query.bindValue(":userId", userId);

    if (!query.exec()) {
        qDebug() << "SQL Error in getTypingStats:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        totalCorrect = query.value("totalCorrect").toInt();
        totalError = query.value("totalError").toInt();
        return true;
    }

    return false;
}


QVector<CompetitionFullRecord> CompetitionRecordsDao::getFullRecords(int userId)
{
    QVector<CompetitionFullRecord> list;

    QSqlQuery query;

    QString sql = R"(
        SELECT 
            c.CompName,
            a.ArticleName,
            r.WPM,
            r.Accuracy,
            r.CorrectCount,
            r.ErrorCount,
            r.FinalScore,
            r.TimeUsed
        FROM competition_records r
        JOIN competitions c ON r.CompID = c.CompID
        JOIN articleinfo a ON c.ArticleID = a.ArticleID
        WHERE r.UserID = :userId
        ORDER BY r.SubmitTime DESC
    )";

    query.prepare(sql);
    query.bindValue(":userId", userId);

    if (!query.exec()) {
        qDebug() << "SQL Error:" << query.lastError().text();
        return list;
    }

    while (query.next())
    {
        CompetitionFullRecord r;

        r.compName = query.value("CompName").toString();
        r.articleName = query.value("ArticleName").toString();
        r.wpm = query.value("WPM").toInt();
        r.accuracy = query.value("Accuracy").toDouble();
        r.correctCount = query.value("CorrectCount").toInt();
        r.errorCount = query.value("ErrorCount").toInt();
        r.finalScore = query.value("FinalScore").toDouble();
        r.timeUsed = query.value("TimeUsed").toInt();

        list.append(r);
    }

    return list;
}

//查询最近成绩
QVector<CompetitionFullRecord> CompetitionRecordsDao::getRecentRecords(int userId)
{
    QVector<CompetitionFullRecord> list;
    QSqlQuery query;

    // SQL：查当前用户 最新 1 条比赛记录（按提交时间倒序）
    query.prepare(R"(
        SELECT WPM, Accuracy, TimeUsed, FinalScore
        FROM competition_records
        WHERE UserID = ?
        ORDER BY SubmitTime DESC
        LIMIT 1
    )");

    query.addBindValue(userId);

    if (query.exec() && query.next()) {
        CompetitionFullRecord record;

        // 读取字段
        record.wpm = query.value("WPM").toInt();
        record.accuracy = query.value("Accuracy").toDouble();
        record.timeUsed = query.value("TimeUsed").toInt();
        record.finalScore = query.value("FinalScore").toDouble();

        list.append(record);
    }

    return list;
}

QSqlQueryModel* CompetitionRecordsDao::queryCompScoreByDynamicField(const QString& fieldName, const QString& keyword)
{
    QSqlDatabase db = DatabaseManager::instance().getDatabase();
    QSqlQueryModel* model = new QSqlQueryModel;

    // 三表连查：成绩 + 比赛 + 文章
    QString sql = R"(
        SELECT
            cr.RecordID,
            c.CompName,
            a.ArticleName,
            u.UserName,
            u.StudentID,
            cr.WPM,
            cr.Accuracy,
            cr.TimeUsed,
            cr.FinalScore,
            cr.SubmitTime
        FROM competition_records cr
        JOIN competitions c ON cr.CompID = c.CompID
        JOIN articleinfo a ON c.ArticleID = a.ArticleID
        JOIN userinfo u ON cr.UserID = u.UserID
        WHERE )" + fieldName + R"( LIKE ?
        ORDER BY cr.FinalScore DESC
    )";

    QSqlQuery query;
    query.prepare(sql);
    query.addBindValue("%" + keyword + "%");

    if (!query.exec()) {
        qDebug() << "比赛成绩查询失败：" << query.lastError().text();
    }

    model->setQuery(query);
    return model;
}

QSqlQueryModel* CompetitionRecordsDao::queryAllCompScoresBySchool(const QString& schoolName)
{
    QSqlDatabase db = DatabaseManager::instance().getDatabase();
    QSqlQueryModel* model = new QSqlQueryModel;

    // 四表连查 + 按学校筛选
    QString sql = R"(
        SELECT
            cr.RecordID,
            c.CompName,
            a.ArticleName,
            u.UserName,
            u.StudentID,
            u.SchoolName,
            cr.WPM,
            cr.Accuracy,
            cr.TimeUsed,
            cr.FinalScore,
            cr.SubmitTime
        FROM competition_records cr
        JOIN competitions c ON cr.CompID = c.CompID
        JOIN articleinfo a ON c.ArticleID = a.ArticleID
        JOIN userinfo u ON cr.UserID = u.UserID
        WHERE u.SchoolName = ?
        ORDER BY cr.FinalScore DESC
    )";

    QSqlQuery query(db);
    query.prepare(sql);
    query.addBindValue(schoolName);  // 按学校查询
    query.exec();

    model->setQuery(query);
    return model;
}

// 按比赛ID查排行榜
QSqlQueryModel* CompetitionRecordsDao::getRankingByCompName(const QString& compName)
{
    QSqlQueryModel* model = new QSqlQueryModel;

    // 三表联查：成绩表 + 用户表 + 比赛表
    QString sql = R"(
        SELECT
            u.UserName,
            u.StudentID,
            cr.WPM,
            cr.Accuracy,
            cr.FinalScore
        FROM competition_records cr
        JOIN userinfo u ON cr.UserID = u.UserID
        JOIN competitions c ON cr.CompID = c.CompID
        WHERE c.CompName = ?
        ORDER BY cr.FinalScore DESC
    )";

    QSqlQuery query;
    query.prepare(sql);
    query.addBindValue(compName);  // 传入比赛名称
    query.exec();

    model->setQuery(query);
    return model;
}

// 全局总排行榜
QSqlQueryModel* CompetitionRecordsDao::getGlobalRanking()
{
    QSqlQueryModel* model = new QSqlQueryModel;

    QString sql = R"(
        SELECT
            u.UserName,
            u.StudentID,
            MAX(cr.WPM) AS WPM,
            MAX(cr.Accuracy) AS Accuracy,
            MAX(cr.FinalScore) AS FinalScore
        FROM competition_records cr
        JOIN userinfo u ON cr.UserID = u.UserID
        GROUP BY cr.UserID
        ORDER BY FinalScore DESC
    )";

    model->setQuery(sql);
    return model;
}