#include "userdao.h"
#include "databasemanager.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>

UserDao::UserDao() {}

bool UserDao::verifyUserInfo(const QString& UserName,
    const QString& Password,
    const QString& StudentID,
    const QString& SchoolName,
    int& userId,
    int& userStatus)
{
    QSqlDatabase& db = DatabaseManager::instance().getDatabase();

    if (!db.isOpen()) {
        qCritical() << "数据库未连接";
        return false;
    }

    QSqlQuery query(db);

    query.prepare(
        "SELECT userID, Password, userStatus "
        "FROM userinfo "
        "WHERE UserName = ? AND StudentID = ? AND SchoolName = ?"
    );

    query.addBindValue(UserName);
    query.addBindValue(StudentID);
    query.addBindValue(SchoolName);

    if (!query.exec()) {
        qDebug() << "SQL执行失败:" << query.lastError().text();
        return false;
    }

    if (!query.next()) {
        return false;
    }

    QString dbPassword = query.value("Password").toString();

    // 验证密码
    if (dbPassword != Password) {
        return false;
    }

    // 获取ID和权限
    userId = query.value("userID").toInt();
    userStatus = query.value("userStatus").toInt();

    return true;
}

//判断用户是否存在，通过姓名，学号，学校名称
bool UserDao::existsUserInfo(const QString &UserName, const QString &StudentID, const QString &SchoolName)
{
    //获取DatabaseManager的单例连接（引用）
    QSqlDatabase& db = DatabaseManager::instance().getDatabase();
    //显式指定连接创建QSqlQuery，不再默认的空参构造
    QSqlQuery query(db);    //QSqlQuery 自动使用「默认连接」
    query.prepare("SELECT UserName FROM userinfo where UserName= ? AND StudentID =? AND SchoolName = ? ");
    query.addBindValue(UserName);
    query.addBindValue(StudentID);
    query.addBindValue(SchoolName);
    query.exec();

    if(!query.next()){
        return false;
    }else{
        return true;
    }
}

bool UserDao::registerUserInfo(const QString &UserName, const QString &Password, const QString &StudentID, const QString &SchoolName, const QString EMail)
{
    //获取DatabaseManager的单例连接（引用）
    QSqlDatabase& db = DatabaseManager::instance().getDatabase();
    //显式指定连接创建QSqlQuery，不再默认的空参构造
    QSqlQuery query(db);    //QSqlQuery 自动使用「默认连接」
    query.prepare("INSERT INTO userinfo (UserName, Password, StudentID, SchoolName, EMail) VALUES (?, ?, ?, ?, ?) ");
    //逐个绑定参数
    query.addBindValue(UserName);
    query.addBindValue(Password);
    query.addBindValue(StudentID);
    query.addBindValue(SchoolName);
    query.addBindValue(EMail);

    bool execOk = query.exec();
    qDebug()<<"===========================================";
    qDebug()<<execOk;

    if(!execOk){
        // 打印执行失败的详细错误信息（核心新增）
        qDebug() << "[注册失败] SQL语句执行失败：" << query.lastError().text();
        qDebug() << "[错误详情] 错误类型：" << query.lastError().type();
        qDebug() << "[错误详情] 数据库驱动错误：" << query.lastError().driverText();
        qDebug() << "[错误详情] 数据库原生错误：" << query.lastError().databaseText();
        return false;
    }else{
        return true;
    }


}
//检测邮箱是否是唯一值，是否已经被注册了
bool UserDao::emailIsExist(const QString& EMail)
{
    //获取DatabaseManager的单例连接（引用）
    QSqlDatabase& db = DatabaseManager::instance().getDatabase();
    //显式指定连接创建QSqlQuery，不再默认的空参构造
    QSqlQuery query(db);    //QSqlQuery 自动使用「默认连接」
    query.prepare("SELECT EMail FROM userinfo where EMail= ?");
    query.addBindValue(EMail);
    query.exec();

    if(!query.next()){
        return false;
    }else{
        return true;
    }
}

    //忘记-找回密码逻辑
bool UserDao::retrieveUserPassword(const QString &UserName, const QString &Password, const QString &StudentID, const QString &SchoolName, const QString& EMail)
{
    //获取DatabaseManager的单例连接（引用）
    QSqlDatabase& db = DatabaseManager::instance().getDatabase();
    //显式指定连接创建QSqlQuery，不再默认的空参构造
    QSqlQuery query(db);    //QSqlQuery 自动使用「默认连接」
    query.prepare("UPDATE userinfo SET Password = ? WHERE UserName = ? AND StudentID = ? AND SchoolName = ? AND EMail = ?");
    query.addBindValue(Password);
    query.addBindValue(UserName);
    query.addBindValue(StudentID);
    query.addBindValue(SchoolName);
    query.addBindValue(EMail);

    // 核心修正1：先判断exec()是否执行成功（SQL语法/连接是否正常）
    if (!query.exec()) {
        // 新增：打印错误日志，便于排查问题
        qDebug() << "密码更新SQL执行失败：" << query.lastError().text();
        return false;
    }

    // 核心修正2：判断是否有记录被更新（条件匹配，密码已修改）
    int affectedRows = query.numRowsAffected();
    if (affectedRows > 0) {
        qDebug() << "密码更新成功，受影响行数：" << affectedRows;
        return true;  // 有记录被更新，返回成功
    } else {
        // 无记录被更新
        qDebug() << "密码更新失败";
        return false;
    }
}

int UserDao::getUserStatus(const QString &UserName, const QString &StudentID, const QString &SchoolName)
{
    QSqlDatabase& db = DatabaseManager::instance().getDatabase();
    QSqlQuery query(db);
    // 数据库表 userinfo 中有一个字段叫 userStatus (INT类型)
    query.prepare("SELECT userStatus FROM userinfo WHERE UserName = ? AND StudentID = ? AND SchoolName = ?");
    query.addBindValue(UserName);
    query.addBindValue(StudentID);
    query.addBindValue(SchoolName);

    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return 0; // 默认返回普通用户状态
}

int UserDao::getUserID(const QString& UserName, const QString& StudentID, const QString& SchoolName)
{
    QSqlDatabase& db = DatabaseManager::instance().getDatabase();
    QSqlQuery query(db);
    // 数据库表 userinfo 中有一个字段叫 userStatus (INT类型)
    query.prepare("SELECT userID FROM userinfo WHERE UserName = ? AND StudentID = ? AND SchoolName = ?");
    query.addBindValue(UserName);
    query.addBindValue(StudentID);
    query.addBindValue(SchoolName);

    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return 0; 
}



