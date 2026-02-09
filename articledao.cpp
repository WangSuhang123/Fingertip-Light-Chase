#include "articledao.h"
#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

ArticleDao::ArticleDao() {}

QList<Article> ArticleDao::getAllArticles()
{
    QList<Article> list;

    // QSqlQuery query;
    //获取数据库databaseManager的单例连接（引用连接
    QSqlDatabase& db = DatabaseManager::instance().getDatabase();

    //检查数据库连接是否有效
    if (!db.isOpen()) {
        qCritical() << "数据库连接未打开！";

    }

    //显示指定连接创建QSqlQuery,不再默认的空参构造
    QSqlQuery query(db);    //QSqlQuery 自动使用「默认连接」

    // 只查询 ID 和 Name，减少数据传输量，提升下拉框加载速度
    QString sql = "SELECT ArticleID, ArticleName FROM articleinfo";

    if (query.exec(sql)) {
        while (query.next()) {
            int id = query.value("ArticleID").toInt();
            QString title = query.value("ArticleName").toString();

            Article article(id, title);
            list.append(article);

            qDebug() << &list;
        }
    } else {
        qDebug() << "ArticleDao Select Error:" << query.lastError().text();
    }

    return list;
}
