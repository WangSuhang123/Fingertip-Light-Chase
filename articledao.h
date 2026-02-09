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
};

#endif // ARTICLEDAO_H
