#include "practiceRecordsDao.h"
#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlerror>

practiceRecordsDao::practiceRecordsDao(QObject *parent)
	: QObject(parent)
{}

practiceRecordsDao::~practiceRecordsDao()
{}

bool practiceRecordsDao::insertPracticeRecords(int UserId, int TotalChars, int TypedChars, int CorrectChars, int ErrorChars, int WPM, int UsedTime, double accuracy)
{
    //获取DatabaseManager的单例连接（引用）
    QSqlDatabase& db = DatabaseManager::instance().getDatabase();
    //显式指定连接创建QSqlQuery，不再默认的空参构造
    QSqlQuery query(db);    //QSqlQuery 自动使用「默认连接」
    query.prepare(R"(INSERT INTO typing_practice_records(UserID, TotalChars, TypedChars, CorrectChars, ErrorChars, WPM, Accuracy, UsedSeconds)
    VALUES(:userid, :total, :typed, :correct, :error, :wpm, :accuracy, :seconds)
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

