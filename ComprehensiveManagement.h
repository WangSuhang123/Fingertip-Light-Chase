#pragma once

#include <QMainWindow>
#include "ui_ComprehensiveManagement.h"
#include "userservice.h"
#include "CompetitionService.h"
#include "articleservice.h"
#include "CompetitionRecordsService.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ComprehensiveManagementClass; };
QT_END_NAMESPACE

class ComprehensiveManagement : public QMainWindow
{
	Q_OBJECT

public:
	ComprehensiveManagement(QWidget *parent = nullptr);
	~ComprehensiveManagement();

	//加载默认数据
	void loadDefaultData();
	//用户表管理
	//绘制用户管理表
	void drawUserTable(QSqlQueryModel* model);
	//用户表条件查询
	void selectUserInfoByChoose();

	//比赛表管理
	//绘制比赛管理表
	void drawCompTable(QSqlQueryModel* model);

	//文章表管理
	//绘制文章管理表
	void drawArticleTable(QSqlQueryModel* model);
	//条件查询
	void selectArticleInfoByChoose();

	//比赛成绩表绘制
	void drawCompScoreTable(QSqlQueryModel* model);

private:
	Ui::ComprehensiveManagementClass *ui;
	//初始化指针
	UserService* m_userservice;
	CompetitionService* m_competitionservice;
	ArticleService* m_articleservice;
	CompetitionRecordsService* m_competitionrecordsservice;
	//ui更新
	void updateUIShow();


private slots:
	//用户表管理
	//修改
	void on_UserUpdateBtn_clicked();
	//删除
	void on_UserDeleteBtn_clicked();
	//导出
	void on_UserLeadingoutBtn_clicked();
	//赛事表
	//查询
	void on_CompSelectBtn_clicked();
	//添加
	void on_CompInsertBtn_clicked();
	//删除
	void on_CompDeleteBtn_clicked();
	//导出
	void on_CompLeadingoutBtn_clicked();

	//文章表管理
	//删除文章
	void on_ArticleDeleteBtn_clicked();
	//新增文章
	void on_ArticleInsertBtn_clicked();
	//修改信息
	void on_ArticleUpdateBtn_clicked();

	//比赛信息表
	//条件查询
	void on_compScoreSelectBtn_clicked();
	//导出
	void on_compScoreLeadingOutBtn_clicked();


};

