#pragma once

#include <QWidget>
#include "ui_uploadArticle.h"
#include "articleservice.h"

class uploadArticle : public QWidget
{
	Q_OBJECT

public:
	uploadArticle(QWidget *parent = nullptr);
	~uploadArticle();

private:
	Ui::uploadArticleClass *ui;
	ArticleService m_articleservice;

	//ant风格
	void antStyle();

	//获取页面上输入的数据，进行上传文章
	void uploadArticleData();

private slots:
	//数据上传、取消
	void on_SubmitBtn_clicked();
	void on_CancelBtn_clicked();

	//字数统计
	void updateCharCount();


};

