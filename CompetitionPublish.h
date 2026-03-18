#pragma once

#include <QMainWindow>
#include "ui_CompetitionPublish.h"
#include "articleservice.h"
#include "CompetitionService.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CompetitionPublishClass; };
QT_END_NAMESPACE

class CompetitionPublish : public QMainWindow
{
	Q_OBJECT

public:
	CompetitionPublish(QWidget *parent = nullptr);
	~CompetitionPublish();

private:
	Ui::CompetitionPublishClass *ui;
	ArticleService articleService; // 声明 Service 对象
	CompetitionService competitionService; // 声明 Service 对象

	//更新ui样式
	void updateUiShow();

private slots:

	void initComboBox(); // 初始化下拉框的函数

	void on_publishBtn_clicked(); // 发布按钮的槽函数


};

