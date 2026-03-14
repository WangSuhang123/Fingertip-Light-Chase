#ifndef ARTICLESERVICE_H
#define ARTICLESERVICE_H

#include "articledao.h"
//解耦作用，以后如果你想给文章列表加缓存、或者加过滤条件，改这里就行，不用改 UI。
class ArticleService
{
public:
    ArticleService();
    // 供 UI 调用的接口
    QList<Article> getArticleListForDropdown();

    QString getArticleById(int articleID);

    QString getArticleTitleById(int articleID);

    //判断是否插入成功
    bool isInsertNewArticleInfo(const QString& title, const QString& author, const QString& content, const QString& date);

private:
    ArticleDao articleDao;

};

#endif // ARTICLESERVICE_H
