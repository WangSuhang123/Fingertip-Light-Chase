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

QString ArticleDao::getArticleById(int articleID)
{
    QSqlDatabase& db = DatabaseManager::instance().getDatabase();

    if (!db.isOpen()) {
        qCritical() << "数据库连接未打开！";
        return "";
    }

    QSqlQuery query(db);

    //查询
    QString sql = "SELECT Content FROM articleinfo WHERE ArticleID = ?";

    query.prepare(sql); // 推荐使用 prepare + bindValue 方式，更规范
    query.addBindValue(articleID);

    if (query.exec()) {
        if (query.next()) {
            return query.value("Content").toString();
        } else {
            // 执行成功但没有找到记录
            qDebug() << "未找到 ID 为" << articleID << "的文章";
        }
    } else {
        qDebug() << "ArticleDao Select Error:" << query.lastError().text();
    }

    return "";
}

QString ArticleDao::getArticleTitleById(int articleID)
{
    QSqlDatabase& db = DatabaseManager::instance().getDatabase();

    if (!db.isOpen()) {
        qCritical() << "数据库连接未打开！";
        return "";
    }

    QSqlQuery query(db);

    //查询
    QString sql = "SELECT ArticleName FROM articleinfo WHERE ArticleID = ?";

    query.prepare(sql); // 推荐使用 prepare + bindValue 方式，更规范
    query.addBindValue(articleID);

    if (query.exec()) {
        if (query.next()) {
            return query.value("ArticleName").toString();
        } else {
            // 执行成功但没有找到记录
            qDebug() << "未找到 ID 为" << articleID << "的文章";
        }
    } else {
        qDebug() << "ArticleDao Select Error:" << query.lastError().text();
    }

    return "";
}

bool ArticleDao::insertNewArticleInfo(const QString& title, const QString& author, const QString& content, const QString& date)
{
    //获取DatabaseManager的单例连接（引用）
    QSqlDatabase& db = DatabaseManager::instance().getDatabase();
    //显式指定连接创建QSqlQuery，不再默认的空参构造
    QSqlQuery query(db);    //QSqlQuery 自动使用「默认连接」
    query.prepare("INSERT INTO articleinfo (ArticleName, Author, Content, PublishTime) VALUES (?, ?, ?, ?) ");
    //逐个绑定参数
    query.addBindValue(title);
    query.addBindValue(author);
    query.addBindValue(content);
    query.addBindValue(date);

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
