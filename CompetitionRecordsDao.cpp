#include "CompetitionRecordsDao.h"
#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
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

