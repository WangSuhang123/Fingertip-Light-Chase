#ifndef ARTICLESERVICE_H
#define ARTICLESERVICE_H
#include <QObject>

#include "articledao.h"
//解耦作用，以后如果你想给文章列表加缓存、或者加过滤条件，改这里就行，不用改 UI。
class ArticleService : public QObject
{
public:
    ArticleService(QObject* parent = nullptr);
    ~ArticleService();
    // 供 UI 调用的接口
    QList<Article> getArticleListForDropdown();

    QString getArticleById(int articleID);

    QString getArticleTitleById(int articleID);

    //判断是否插入成功
    bool isInsertNewArticleInfo(const QString& title, const QString& author, const QString& content, const QString& date);

    //综合文章表单查询
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
    ArticleDao articleDao;

};

#endif // ARTICLESERVICE_H
