#include "articleservice.h"
#include <QDebug>
#include <QMessageBox>

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

//判断是否插入新文章成功
bool ArticleService::isInsertNewArticleInfo(const QString& title, const QString& author, const QString& content, const QString& date)
{
	//把UI层的非空校验移到这里，让UI层更轻
	//判断是否为空
	if (title.isEmpty() || author.isEmpty() || content.isEmpty() || date.isEmpty())
	{
		//提示不能为空
		qWarning() << "提示" << "标题、作者、文章内容不能为空！";
		return false;
	}
	else
	{
		//违禁词检测，后期拓展ai测试是否为违禁词或调用内容安全API
		// 第一步：定义违禁词列表
		QStringList forbiddenWords = { "肏", "sm","约炮", "援交", "外围女", "外围模特", "大保健", "全套", "无套", "口爆", "内射", "颜射", "吞精",
		"多人运动", "3P", "4P", "群P", "换妻", "绿帽", "NTR", "调教", "母狗", "性奴", "性玩具", "情趣内衣","裸聊", "直播漏",
		"福利姬", "福利视频", "丝袜控", "爆乳", "巨乳", "豪乳", "乱伦","人妻出轨", "少妇自慰", "师生恋禁忌", "乱伦小说", "兄妹禁忌", "姐弟恋爱", "SM调教", "绳艺", "滴蜡",
	"足交", "乳交", "后入式", "骑乘位", "性爱姿势", "高潮喷水", "sb","SB","傻逼","淫"};

		// 第二步：拼接所有需要检测的文本（标题+作者+文章内容）
		QString allText = title + author + content;

		// 第三步：遍历检测是否包含违禁词
		bool hasForbiddenWord = false;
		QString foundWord; // 记录找到的第一个违禁词
		foreach(const QString & word, forbiddenWords) {
			// 不区分大小写检测（如需严格区分，去掉.toLower()）
			if (allText.toLower().contains(word.toLower())) {
				hasForbiddenWord = true;
				foundWord = word;
				break; // 找到一个就停止检测，提升效率
			}
		}

		// 第四步：根据检测结果处理
		if (hasForbiddenWord) {
			// 弹窗提示包含违禁词（可选择是否显示具体违禁词）
			QMessageBox::warning(nullptr, "警告", "内容包含违禁词：" + foundWord + "，请修改后重新提交！");
			qWarning() << "错误", "内容包含违禁词：" + foundWord + "，请修改后重新提交！";
			return false;
		}
		else {

			// 这里写你的业务逻辑：比如保存到数据库、文件等
			//测试先打印数据
			qDebug() << "title:" << title;
			qDebug() << "author:" << author;
			qDebug() << "article:" << content;
			qDebug() << "currentTime;" << date;

			// 没有违禁词，执行插入数据库
			bool isSuccess = articleDao.insertNewArticleInfo(title, author, content, date);
			return isSuccess;
		}

	}
}
