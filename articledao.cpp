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

QSqlQueryModel* ArticleDao::selectAllArticleInfo()
{
    QSqlDatabase& db = DatabaseManager::instance().getDatabase();

    QSqlQuery query(db);    //QSqlQuery 自动使用「默认连接」
    query.prepare(R"(
        SELECT
            ArticleID,
            ArticleName,
            Author,
            CONCAT(LEFT(Content, 15), '...') AS Content,
            PublishTime
        FROM articleinfo
    )");
    //执行
    if (!query.exec()) {
        qCritical() << "查询文章失败：" << query.lastError().text();
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

QSqlQueryModel* ArticleDao::selectArticleInfoByArticleName(const QString& articleName)
{
    QSqlDatabase& db = DatabaseManager::instance().getDatabase();

    QSqlQuery query(db);    //QSqlQuery 自动使用「默认连接」
    query.prepare(R"(
        SELECT
            ArticleID,
            ArticleName,
            Author,
            CONCAT(LEFT(Content, 15), '...') AS Content,
            PublishTime
        FROM articleinfo WHERE ArticleName LIKE ?
    )");
    //插入数据
    query.addBindValue("%"+articleName+"%" );
    
    //执行
    if (!query.exec()) {
        qCritical() << "查询文章失败：" << query.lastError().text();
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

QSqlQueryModel* ArticleDao::selectArticleInfoByAuthor(const QString& author)
{
    QSqlDatabase& db = DatabaseManager::instance().getDatabase();

    QSqlQuery query(db);    //QSqlQuery 自动使用「默认连接」
    query.prepare(R"(
        SELECT
            ArticleID,
            ArticleName,
            Author,
            CONCAT(LEFT(Content, 15), '...') AS Content,
            PublishTime
        FROM articleinfo WHERE Author LIKE ?
    )");
    //插入数据
    query.addBindValue("%" + author + "%");

    //执行
    if (!query.exec()) {
        qCritical() << "查询文章失败：" << query.lastError().text();
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

bool ArticleDao::deleteArticleInfoByArticleId(int articleID)
{
    QSqlDatabase& db = DatabaseManager::instance().getDatabase();

    QSqlQuery query(db);    //QSqlQuery 自动使用「默认连接」
    query.prepare(R"(
       DELETE FROM articleinfo WHERE ArticleID = ?
    )");

    //执行sql
    query.addBindValue(articleID);
    
    if (!query.exec()) {
        qCritical() << "删除文章失败：" << query.lastError().text();
        return false;
    }
    return true;
    
}

bool ArticleDao::updateArticleField(int articleId, const QString& fieldName, const QString& newValue)
{
    QSqlQuery query;

    // ⚠️ 防止SQL注入（公司级必须做）
    QString dbField;

    if (fieldName == "文章名称") dbField = "title";
    else if (fieldName == "作者") dbField = "author";
    else if (fieldName == "内容") dbField = "content";
    else {
        return false; // 不允许修改的字段
    }

    QString sql = QString("UPDATE articleinfo SET %1 = :value WHERE articleID = :id").arg(dbField);

    query.prepare(sql);
    query.bindValue(":value", newValue);
    query.bindValue(":id", articleId);

    return query.exec();
}