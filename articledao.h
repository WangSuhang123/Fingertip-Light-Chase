#ifndef ARTICLEDAO_H
#define ARTICLEDAO_H

#include <QList>
#include "article.h"
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

private:

};

#endif // ARTICLEDAO_H
