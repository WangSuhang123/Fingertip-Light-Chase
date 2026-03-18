#include "CompetitionPublish.h"

#include <QDateTime>
#include <QMessageBox>
#include "usermanager.h"

CompetitionPublish::CompetitionPublish(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::CompetitionPublishClass())
{
	ui->setupUi(this);

	//更新ui样式
	updateUiShow();
	//初始化下拉框
	initComboBox();
}

CompetitionPublish::~CompetitionPublish()
{
	delete ui;
}

void CompetitionPublish::updateUiShow()
{
	ui->publishBtn->setProperty("type", "primary");
	ui->CancelBtn->setProperty("type", "text");
	ui->competitionPubilshWidget->setProperty("type", "DialogPage");
	ui->competitionPubilshTitleWidget->setProperty("type", "StatusWidget");

	//设置默认状态
	//获取当前时间
	QDateTime defaultDateTime = QDateTime::currentDateTime();
	ui->StartTime->setDateTime(defaultDateTime);
	ui->EndTime->setDateTime(defaultDateTime);

}

void CompetitionPublish::initComboBox()
{
	//通过Service获取数据
	QList<Article> articles = articleService.getArticleListForDropdown();
	//清空下拉框（防止重复添加
	ui->ChooseArticleCombo->clear();
	//遍历数据添加到下拉框
	for (const Article& art : articles) {
		// addItem(显示的文字, 隐藏的数据)
		// 这一点非常重要：用户看的是 Title，但程序后台需要 ID
		ui->ChooseArticleCombo->addItem(art.title, art.id);
	}
}
void CompetitionPublish::on_publishBtn_clicked()
{
	//通过 instance() 获取那个唯一的实例
	UserManager& userMgr = UserManager::instance();
	int userID = userMgr.getCurrentUserID();	//用户id
	QString userSchool = userMgr.getSchoolName();	//学校名称

	//获取输入框内容
	QString CompetitionName = ui->CompetitionNameEdit->text();	//比赛名称
	int ChooseArticleID = ui->ChooseArticleCombo->currentData().toInt();	//选择文章的id
	QString LimitTime = ui->LimitTimeEdit->text();	//限制的时间
	QDateTime StartTime = ui->StartTime->dateTime();	//开始时间
	QDateTime EndTime = ui->EndTime->dateTime();	//结束时间

	// 转换限制时间为int（分钟）
	bool ok = false;
	int durationMinutes = LimitTime.toInt(&ok);
	if (!ok || durationMinutes <= 0) {
		QMessageBox::warning(this, "警告", "请输入有效的比赛时长（分钟）！");
		return;
	}
	//打印所有的要输入的内容
	qDebug() << "CompetitionName:" << CompetitionName;
	qDebug() << "ChooseArticleID:" << ChooseArticleID;
	qDebug() << "LimitTime:" << durationMinutes;
	qDebug() << "StartTime:" << StartTime.toString("yyyy-MM-dd HH:mm:ss");
	qDebug() << "EndTime:" << EndTime.toString("yyyy-MM-dd HH:mm:ss");


	// 调用插入方法
	bool success = competitionService.insertCompetition(
		CompetitionName,
		ChooseArticleID,
		userID,
		userSchool,
		StartTime,
		EndTime,
		durationMinutes
	);

	if (success) {
		QMessageBox::information(this, "提示", "比赛发布成功！");
		this->close();
	}
}
