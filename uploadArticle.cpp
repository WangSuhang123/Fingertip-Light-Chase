#include "uploadArticle.h"

#include <QMessageBox>
#include <QDateTime>

uploadArticle::uploadArticle(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::uploadArticleClass)
{
	ui->setupUi(this);
	//ant风格
	antStyle();

	// 实时统计字数
	connect(ui->ArticleTextEdit, &QTextEdit::textChanged, this, &uploadArticle::updateCharCount);
	updateCharCount(); // 初始化显示
}

uploadArticle::~uploadArticle()
{
	delete ui;
}

void uploadArticle::antStyle()
{
	ui->SubmitBtn->setProperty("type", "primary");
	ui->uploadArticleWidget->setProperty("type", "frontPage");
}

void uploadArticle::uploadArticleData()
{
	//获取页面输入数据
	QString title = ui->titleLineEdit->text().trimmed();
	QString author = ui->authorLineEdit->text().trimmed();
	
	//获取文章内容的时候，清空所有的格式
	QString article = ui->ArticleTextEdit->toPlainText().trimmed();
	article.replace("\n", "");
	//获取当前时间
	QDateTime currentDateTime = QDateTime::currentDateTime();
	QString currentTime = currentDateTime.toString("yyyy-MM-dd HH:mm:ss");
	
	//把新文章插入数据库
	bool isInsertSuccess = m_articleservice.isInsertNewArticleInfo(title, author, article, currentTime);
	//判断是否成功
	if (isInsertSuccess)
	{
		QMessageBox::information(this, "提示", "文章上传成功！");
	}
	else
	{
		QMessageBox::information(this, "提示", "文章上传失败!");
	}

}

void uploadArticle::on_SubmitBtn_clicked()
{
	uploadArticleData();

}

void uploadArticle::on_CancelBtn_clicked()
{
	this->close();

}

void uploadArticle::updateCharCount()
{
	int count = ui->ArticleTextEdit->toPlainText().length();
	//ui->ALLChar->setText(QString("字数：%1").arg(count));
	ui->ALLChar->setText(QString("%1 字").arg(count));
}

