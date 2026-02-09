#ifndef ARTICLE_H
#define ARTICLE_H

#include <QString>

struct Article
{
    int id;     // 数据库中的 ArticleID
    QString title;  // 数据库中的 ArticleName
    QString content;    // 文章内容 (列表查询时可选，看需求)
    QString author;     // 文章作者 (列表查询时可选，看需求)

    Article(int _id = 0, QString _title = "") : id(_id), title(_title){}
};

#endif // ARTICLE_H
