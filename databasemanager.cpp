//#include "databasemanager.h"
//#include <QSqlDatabase>
//#include <QSqlError>
//
//DatabaseManager::DatabaseManager() {
//    //构造方法
//    //建立mysql连接，db是QSqlDatabase创建的对象
//    //db = QSqlDatabase::addDatabase("QMYSQL");
//    //创建连接，设置信息
//    //db.setHostName("localhost");
//    //db.setPort(3306);
//    //db.setUserName("root");
//    //db.setPassword("123456");        // 你的密码
//    //db.setDatabaseName("Fingertip-Light-Chase");   // 数据库名
//    // qDebug() << "Available drivers:" << QSqlDatabase::drivers();
//    // qDebug() << "Database Error:" << db.lastError().text();
//    // 使用 ODBC 驱动
//    db = QSqlDatabase::addDatabase("QODBC");
//
//    QString connStr =
//        "Driver={MySQL ODBC 9.6 Unicode Driver};"
//        "Server=127.0.0.1;"
//        "Database=Fingertip_Light_Chase;"
//        "User=root;"
//        "Password=123456;"
//        "Port=3306;"
//        "OPTION=3;"
//        "CHARSET=utf8mb4;";
//
//    db.setDatabaseName(connStr);
//
//
//    // 调试：打印Qt支持的数据库驱动
//    qDebug() << "Available drivers:" << QSqlDatabase::drivers();
//    
//
//}
//
//DatabaseManager& DatabaseManager::instance(){
//    static DatabaseManager instance;
//    return instance;
//
//}
//
//bool DatabaseManager::openDatabase(){
//    if(!db.open()){
//        qDebug() << "Database Error:" << db.lastError().text();
//        return false;
//    }
//    qDebug() << "Database connected!";
//    return true;
//}
//
//QSqlDatabase& DatabaseManager::getDatabase(){
//    return db;
//}
//
//

#include "databasemanager.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

DatabaseManager::DatabaseManager() {
    // 使用 ODBC 连接 MySQL
    db = QSqlDatabase::addDatabase("QODBC");

    // ====================== 【必须改成你自己的腾讯云信息】 ======================
    QString serverIP = "gz-cdb-drnp86qz.sql.tencentcdb.com";    // 你的腾讯云公网IP
    QString dbName = "fingertip_light_chase";
    QString user = "root";
    QString password = "wsh5211314";        // 你的云服务器MySQL密码
    int port = 24205;

    QString connStr =
        QString("Driver={MySQL ODBC 9.6 Unicode Driver};")
        + "Server=" + serverIP + ";"
        + "Database=" + dbName + ";"
        + "User=" + user + ";"
        + "Password=" + password + ";"
        + "Port=" + QString::number(port) + ";"
        + "OPTION=3;"
        + "CHARSET=utf8mb4;";

    db.setDatabaseName(connStr);

    qDebug() << "已连接到腾讯云数据库";
}

DatabaseManager& DatabaseManager::instance() {
    static DatabaseManager instance;
    return instance;
}

bool DatabaseManager::openDatabase() {
    if (!db.open()) {
        qDebug() << "数据库连接失败：" << db.lastError().text();
        //弹窗输出错误原因
        QString errorMsg = "数据库连接失败：" + db.lastError().text();
        QMessageBox::warning(nullptr, "错误", errorMsg);
        return false;
    }
    qDebug() << "✅ 腾讯云数据库连接成功！";
    return true;
}

QSqlDatabase& DatabaseManager::getDatabase() {
    return db;
}

