#include "userdao.h"
#include "databasemanager.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlTableModel>

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

//返回除密码列的所有信息
//查询登录管理员学校内的所有成员
QSqlQueryModel* UserDao::selectAllInfoFromUserInfo(const QString& SchoolName)
{
    QSqlDatabase& db = DatabaseManager::instance().getDatabase();

    // 1. 创建并绑定参数
    QSqlQuery query(db);
    query.prepare("SELECT UserID, UserName, StudentID, SchoolName, EMail, UserStatus FROM userinfo WHERE SchoolName = ?");
    query.addBindValue(SchoolName);  // 绑定学校名称

    // 执行查询
    if (!query.exec()) {
        qCritical() << "查询userinfo失败：" << query.lastError().text();
        return nullptr;
    }

    // 将结果交给 model
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(std::move(query));  // Qt5.14+ 支持移动语义，效率更高

    // 4. 错误检查
    if (model->lastError().isValid()) {
        qCritical() << "Model设置查询失败：" << model->lastError().text();
    }

    return model;

}

QSqlQueryModel* UserDao::queryUserByDynamicField(const QString& schoolName, const QString& fieldName, const QString& keyword)
{
    QSqlDatabase db = DatabaseManager::instance().getDatabase();

    QSqlQueryModel* model = new QSqlQueryModel;

    // 一条 SQL 动态适配 3 个字段
    QString sql = R"(SELECT UserID, UserName, StudentID, SchoolName, EMail, UserStatus FROM userinfo WHERE SchoolName = ? AND )" + fieldName + R"( LIKE ?)";

    QSqlQuery query(db);
    query.prepare(sql);
    query.addBindValue(schoolName);
    query.addBindValue("%" + keyword + "%");
    if (!query.exec()) {
        qDebug() << "SQL 执行失败：" << query.lastError().text();
        qDebug() << "SQL 语句：" << query.executedQuery();
    }

    model->setQuery(query);
    return model;
}


bool UserDao::updateUserField(int userId, const QString& fieldName, const QString& newValue)
{
    QString realField;

    // 只允许修改这 3 个！
    if (fieldName == "用户名")       realField = "UserName";
    else if (fieldName == "学号")    realField = "StudentID";
    else if (fieldName == "EMail")   realField = "EMail";

    // 学校、权限 直接 return false，不处理
    else return false;

    QSqlDatabase db = DatabaseManager::instance().getDatabase();
    QSqlQuery query(db);

    QString sql = QString("UPDATE userinfo SET %1 = ? WHERE UserID = ?").arg(realField);
    query.prepare(sql);
    query.addBindValue(newValue);
    query.addBindValue(userId);

    if (!query.exec()) {
        qDebug() << "用户修改失败：" << query.lastError().text();
        return false;
    }

    return true;
}

bool UserDao::deleteUser(int userId)
{
    QSqlDatabase db = DatabaseManager::instance().getDatabase();

    QSqlQuery query(db);

    query.prepare("DELETE FROM userinfo WHERE UserID = ?");

    query.addBindValue(userId);

    if (!query.exec()) {
        qDebug() << "用户删除失败：" << query.lastError().text();
        return false;
    }
    return true;
}
