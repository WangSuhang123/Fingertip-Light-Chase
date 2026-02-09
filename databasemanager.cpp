#include "databasemanager.h"
#include <QSqlDatabase>
#include <QSqlError>

DatabaseManager::DatabaseManager() {
    //构造方法
    //建立mysql连接，db是QSqlDatabase创建的对象
    db = QSqlDatabase::addDatabase("QMYSQL");
    //创建连接，设置信息
    db.setHostName("localhost");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("123456");        // 你的密码
    db.setDatabaseName("Fingertip-Light-Chase");   // 数据库名
    // qDebug() << "Available drivers:" << QSqlDatabase::drivers();
    // qDebug() << "Database Error:" << db.lastError().text();

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
