#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QSqlDatabase>

class DatabaseManager
{
public:
    static DatabaseManager& instance();

    bool openDatabase();

    //返回QSqlDatabase&(引用) ,而非QSqlDatabase(值引用
    QSqlDatabase& getDatabase();


private:
    DatabaseManager();

    //创建QSqlDatabase对象
    QSqlDatabase db;

    //禁止拷贝和赋值（单例模式标准写法，避免意外拷贝
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;
};

#endif // DATABASEMANAGER_H
