#include "databasemanager.h"
#include <QSqlDatabase>
#include <QSqlError>

DatabaseManager::DatabaseManager() {
    //构造方法
    //建立mysql连接，db是QSqlDatabase创建的对象
    //db = QSqlDatabase::addDatabase("QMYSQL");
    //创建连接，设置信息
    //db.setHostName("localhost");
    //db.setPort(3306);
    //db.setUserName("root");
    //db.setPassword("123456");        // 你的密码
    //db.setDatabaseName("Fingertip-Light-Chase");   // 数据库名
    // qDebug() << "Available drivers:" << QSqlDatabase::drivers();
    // qDebug() << "Database Error:" << db.lastError().text();
    // 使用 ODBC 驱动
    db = QSqlDatabase::addDatabase("QODBC");

    QString connStr =
        "Driver={MySQL ODBC 9.6 Unicode Driver};"
        "Server=127.0.0.1;"
        "Database=Fingertip_Light_Chase;"
        "User=root;"
        "Password=123456;"
        "Port=3306;"
        "OPTION=3;"
        "CHARSET=utf8mb4;";

    db.setDatabaseName(connStr);


    // 调试：打印Qt支持的数据库驱动
    qDebug() << "Available drivers:" << QSqlDatabase::drivers();
    

}

DatabaseManager& DatabaseManager::instance(){
    static DatabaseManager instance;
    return instance;

}

bool DatabaseManager::openDatabase(){
    if(!db.open()){
        qDebug() << "Database Error:" << db.lastError().text();
        return false;
    }
    qDebug() << "Database connected!";
    return true;
}

QSqlDatabase& DatabaseManager::getDatabase(){
    return db;
}



