#include "articleservice.h"

ArticleService::ArticleService() {}

QList<Article> ArticleService::getArticleListForDropdown()
{
    // 这里直接调用 Dao，以后可以在这里加缓存逻辑
    return articleDao.getAllArticles();
}

QString ArticleService::getArticleById(int articleID)
{
    return articleDao.getArticleById(articleID);
}

QString ArticleService::getArticleTitleById(int articleID)
{
    return articleDao.getArticleTitleById(articleID);
}
