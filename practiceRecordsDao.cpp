#include "practiceRecordsDao.h"
#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QPointF>

practiceRecordsDao::practiceRecordsDao(QObject *parent)
	: QObject(parent)
{}

practiceRecordsDao::~practiceRecordsDao()
{}

bool practiceRecordsDao::insertPracticeRecords(int UserId, int TotalChars, int TypedChars, int CorrectChars, int ErrorChars, int WPM, int UsedTime, double accuracy, int articleID)
{
    //获取DatabaseManager的单例连接（引用）
    QSqlDatabase& db = DatabaseManager::instance().getDatabase();
    //显式指定连接创建QSqlQuery，不再默认的空参构造
    QSqlQuery query(db);    //QSqlQuery 自动使用「默认连接」
    query.prepare(R"(INSERT INTO typing_practice_records(UserID, TotalChars, TypedChars, CorrectChars, ErrorChars, WPM, Accuracy, UsedSeconds, ArticleID)
    VALUES(:userid, :total, :typed, :correct, :error, :wpm, :accuracy, :seconds,:articleid)
)");

    //逐个绑定参数
    query.bindValue(":userid", UserId);
    query.bindValue(":total", TotalChars);
    query.bindValue(":typed", TypedChars);
    query.bindValue(":correct", CorrectChars);
    query.bindValue(":error", ErrorChars);
    query.bindValue(":wpm", WPM);
    query.bindValue(":accuracy", accuracy);
    query.bindValue(":seconds", UsedTime);
    query.bindValue(":articleid", articleID);


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

QVector<QPointF> practiceRecordsDao::getWPMPracticeData(int userId)
{
    QVector<QPointF> data;

    QSqlQuery query;

    // 1. 准备 SQL 语句
    // 注意：确保表名 competitions_wpm 和字段名 CompID, WPM, UserID 与数据库完全一致
    QString sql = R"(SELECT PracticeID, WPM FROM typing_practice_records WHERE UserID = :userId ORDER BY PracticeID ASC)";

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

QVector<QPointF> practiceRecordsDao::getAccuracyPracticeData(int userId)
{
    QVector<QPointF> data;

    QSqlQuery query;

    // 1. 准备 SQL 语句
    // 注意：确保表名 competitions_wpm 和字段名 CompID, WPM, UserID 与数据库完全一致
    QString sql = R"(SELECT PracticeID, Accuracy FROM typing_practice_records WHERE UserID = :userId ORDER BY PracticeID ASC)";

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

bool practiceRecordsDao::getFinalScoreBarPracticeData(int userId, QStringList& categories, QVector<double>& values)
{
    categories.clear();
    values.clear();

    QSqlQuery query;

    QString sql = R"(
        SELECT PracticeID, TotalChars
        FROM typing_practice_records
        WHERE UserID = :userId
        ORDER BY PracticeID ASC
    )";

    query.prepare(sql);
    query.bindValue(":userId", userId);

    if (!query.exec()) {
        qDebug() << "SQL Error in getFinalScoreBarData:" << query.lastError().text();
        return false;
    }

    int index = 1;  // 用于显示 第1场、第2场...

    while (query.next()) {

        double score = query.value("TotalChars").toDouble();

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

QVector<PracticeFullRecord> practiceRecordsDao::getFullPracticeRecords(int userId)
{
    QVector<PracticeFullRecord> list;

    QSqlQuery query;

    QString sql = R"(
        SELECT 
            a.ArticleName,
            p.WPM,
            p.Accuracy,
            p.CorrectChars,
            p.ErrorChars,
            p.UsedSeconds,
            p.PracticeTime
        FROM typing_practice_records p
        JOIN articleinfo a ON p.ArticleID = a.ArticleID
        WHERE p.UserID = :userId
        ORDER BY p.PracticeTime DESC
    )";

    query.prepare(sql);
    query.bindValue(":userId", userId);

    if (!query.exec()) {
        qDebug() << "SQL Error:" << query.lastError().text();
        return list;
    }

    while (query.next())
    {
        PracticeFullRecord r;

        r.articleName = query.value("ArticleName").toString();
        r.wpm = query.value("WPM").toInt();
        r.accuracy = query.value("Accuracy").toDouble();
        r.correctCount = query.value("CorrectChars").toInt();
        r.errorCount = query.value("ErrorChars").toInt();
        r.timeUsed = query.value("UsedSeconds").toInt();
        r.practiceTime = query.value("PracticeTime").toString();

        list.append(r);
    }

    return list;
}

bool practiceRecordsDao::getCharCountPracticeData(int userId, int& totalCorrect, int& totalError)
{
    totalCorrect = 0;
    totalError = 0;

    QSqlQuery query;

    QString sql = R"(
        SELECT 
            SUM(CorrectChars) AS totalCorrect,
            SUM(ErrorChars) AS totalError
        FROM typing_practice_records
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

