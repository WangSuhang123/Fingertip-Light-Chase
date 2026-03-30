#ifndef ARTICLEDAO_H
#define ARTICLEDAO_H

#include <QList>
#include "article.h"
#include <QSqlQueryModel>
#include <QSqlTableModel>

class ArticleDao
{
public:
    ArticleDao();

    // 获取所有文章的简介（ID和标题）
    QList<Article> getAllArticles();

    //通过id来查询文章内容
    QString getArticleById(int articleID);

    //通过id来查询文章标题
    QString getArticleTitleById(int articleID);

    //插入articleinfo新文章
    bool insertNewArticleInfo(const QString& title, const QString& author, const QString& content, const QString& date);

    //综合管理
    //文章信息管理
    QSqlQueryModel* selectAllArticleInfo();
    //根据文章名称查询文章信息
    QSqlQueryModel* selectArticleInfoByArticleName(const QString& articleName);
    //根据作者查询文章信息
    QSqlQueryModel* selectArticleInfoByAuthor(const QString& author);
    //根据文章id来删除文章
    bool deleteArticleInfoByArticleId(int articleID);
    //修改内容
    bool updateArticleField(int articleId, const QString& fieldName, const QString& newValue);
    

private:

};

#endif // ARTICLEDAO_H
