#include "articleservice.h"

ArticleService::ArticleService() {}

QList<Article> ArticleService::getArticleListForDropdown()
{
    // 这里直接调用 Dao，以后可以在这里加缓存逻辑
    return articleDao.getAllArticles();
}
