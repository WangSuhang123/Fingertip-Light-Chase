#include "ComprehensiveManagement.h"
#include "usermanager.h"
#include "uploadArticle.h"
#include "CompetitionPublish.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDateTime>


ComprehensiveManagement::ComprehensiveManagement(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::ComprehensiveManagementClass())
{
	ui->setupUi(this);

	//更新ui样式
	updateUIShow();
	//初始化指针
	m_userservice = new UserService(this);
	m_competitionservice = new CompetitionService(this);
	m_articleservice = new ArticleService(this);
	m_competitionrecordsservice = new CompetitionRecordsService(this);
	//实现初始数据
	loadDefaultData();

	//信号槽
	connect(ui->UserSelectBtn, &QPushButton::clicked, this, &ComprehensiveManagement::selectUserInfoByChoose);

	connect(ui->ArticleSelectBtn, &QPushButton::clicked, this, &ComprehensiveManagement::selectArticleInfoByChoose);
}

ComprehensiveManagement::~ComprehensiveManagement()
{
	delete ui;
}

void setBtnStyle(QPushButton* btn, const QString& type)
{
	if (!btn) return;
	btn->setProperty("type", type);
	btn->style()->unpolish(btn);
	btn->style()->polish(btn);
	btn->update();
}

void ComprehensiveManagement::updateUIShow()
{
	ui->centralWidget->setProperty("type", "frontPage");
	setBtnStyle(ui->UserSelectBtn, "primary");
	setBtnStyle(ui->UserDeleteBtn, "danger");
	setBtnStyle(ui->UserLeadingoutBtn, "primary");

	setBtnStyle(ui->CompSelectBtn,"primary");
	setBtnStyle(ui->CompDeleteBtn, "danger");
	setBtnStyle(ui->CompLeadingoutBtn, "primary");

	setBtnStyle(ui->ArticleSelectBtn, "primary");
	setBtnStyle(ui->ArticleDeleteBtn, "danger");

	setBtnStyle(ui->compScoreSelectBtn, "primary");
	setBtnStyle(ui->compScoreLeadingOutBtn, "primary");
}



void ComprehensiveManagement::loadDefaultData()
{
	//通过userservice加载用户数据
	//获取当前登录用户的学校
	UserManager& userMgr = UserManager::instance();
	QString SchoolName = userMgr.getSchoolName();

	//测试值
	/*QString SchoolName = "嗡嗡嗡";*/

	//用户表格
	QSqlQueryModel* userModel = m_userservice->selectAllInfoFromUserInfo(SchoolName);
	this->drawUserTable(userModel);
	//比赛表格
	QSqlQueryModel* compModel = m_competitionservice->selectAllCompetitions(SchoolName);
	this->drawCompTable(compModel);
	//文章表格
	QSqlQueryModel* articleModel = m_articleservice->selectAllArticleInfo();
	this->drawArticleTable(articleModel);
	//比赛成绩表
	//查询该学校所有的比赛所有的成绩，也要联表查
	QSqlQueryModel* compScoreModel = m_competitionrecordsservice->queryAllCompScoresBySchool(SchoolName);
	this->drawCompScoreTable(compScoreModel);


	//下拉表默认数据
	//用户表
	ui->userComboBox->clear();
	ui->userComboBox->addItems({ "用户名","学号","EMail" });
	ui->userComboBox->setCurrentIndex(0);
	//比赛表
	ui->compComboBox->clear();
	ui->compComboBox->addItems({ "比赛名称","文章","创建者" });
	ui->compComboBox->setCurrentIndex(0);

	//文章表
	//清空下拉框数据
	ui->articleComboBox->clear();
	//添加静态数据
	ui->articleComboBox->addItems({ "文章名称","作者" });
	//设置默认值
	ui->articleComboBox->setCurrentIndex(0);

	//比赛成绩表
	ui->compScoreComboBox->clear();
	ui->compScoreComboBox->addItems({ "比赛名称","文章" ,"学号"});
	ui->compScoreComboBox->setCurrentIndex(0);


}

void ComprehensiveManagement::drawUserTable(QSqlQueryModel* model)
{
	//设置表头
	ui->userTable->setModel(model);
	//优化TableView显示效果（可选）
	//ui->userTable->setSelectionBehavior(QAbstractItemView::SelectRows); // 整行选中
	//ui->userTable->setSelectionMode(QAbstractItemView::SingleSelection); // 单行选择

	ui->userTable->setSelectionMode(QAbstractItemView::ExtendedSelection); // 支持Ctrl/Shift多选
	// 开启表头点击排序（核心代码）
	ui->userTable->setSortingEnabled(true);
	ui->userTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); // 列宽自适应

	model->setHeaderData(0, Qt::Horizontal, "用户ID");
	model->setHeaderData(1, Qt::Horizontal, "用户名");
	model->setHeaderData(2, Qt::Horizontal, "学号");
	model->setHeaderData(3, Qt::Horizontal, "学校");
	model->setHeaderData(4, Qt::Horizontal, "EMail");
	model->setHeaderData(5, Qt::Horizontal, "权限");

	ui->userTable->horizontalHeader()->setStretchLastSection(true);
	ui->userTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

void ComprehensiveManagement::selectUserInfoByChoose()
{
	//获取下拉框的id
	int chooseId = ui->userComboBox->currentIndex();
	//进行判断输入框是不是空，如果是空则刷新表格，如果不是空继续
	QString inputText = ui->userSelectEdit->text();
	// 空值刷新
	if (inputText.isEmpty()) {
		loadDefaultData();
		return;
	}

	// 下拉框对应数据库字段
	QStringList fieldList = { "UserName", "StudentID", "EMail" };

	if (chooseId < 0 || chooseId >= fieldList.size())
		return;

	// 获取学校（你现在用测试值，以后替换成真实用户学校）
	//QString schoolName = "嗡嗡嗡";
	UserManager& userMgr = UserManager::instance();
	QString SchoolName = userMgr.getSchoolName();

	// 调用 service 查询
	QSqlQueryModel* model = m_userservice->queryUserByDynamicField(SchoolName,fieldList[chooseId],inputText);

	// 显示到表格
	this->drawUserTable(model);

}

void ComprehensiveManagement::drawCompTable(QSqlQueryModel* model)
{
	//设置表头
	ui->compTable->setModel(model);
	//优化TableView显示效果（可选）
	//ui->compTable->setSelectionBehavior(QAbstractItemView::SelectRows); // 整行选中
	//ui->compTable->setSelectionMode(QAbstractItemView::SingleSelection); // 单行选择

	ui->compTable->setSelectionMode(QAbstractItemView::ExtendedSelection); // 支持Ctrl/Shift多选
	// 开启表头点击排序（核心代码）
	ui->compTable->setSortingEnabled(true);
	ui->compTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); // 列宽自适应

	model->setHeaderData(0, Qt::Horizontal, "比赛ID");
	model->setHeaderData(1, Qt::Horizontal, "比赛名称");
	model->setHeaderData(2, Qt::Horizontal, "文章");
	model->setHeaderData(3, Qt::Horizontal, "创建者");
	model->setHeaderData(4, Qt::Horizontal, "学校");
	model->setHeaderData(5, Qt::Horizontal, "开始时间");
	model->setHeaderData(6, Qt::Horizontal, "结束时间");
	model->setHeaderData(7, Qt::Horizontal, "创建时间");
	model->setHeaderData(8, Qt::Horizontal, "限时");

	ui->compTable->horizontalHeader()->setStretchLastSection(true);
	ui->compTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void ComprehensiveManagement::drawArticleTable(QSqlQueryModel* model)
{
	//设置表头
	ui->articleTable->setModel(model);
	//优化TableView显示效果（可选）
	//ui->articleTable->setSelectionBehavior(QAbstractItemView::SelectRows); // 整行选中
	//ui->articleTable->setSelectionMode(QAbstractItemView::SingleSelection); // 单行选择

	ui->articleTable->setSelectionMode(QAbstractItemView::ExtendedSelection); // 支持Ctrl/Shift多选
	// 开启表头点击排序（核心代码）
	ui->articleTable->setSortingEnabled(true);
	ui->articleTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); // 列宽自适应
	

	model->setHeaderData(0, Qt::Horizontal, "文章ID");
	model->setHeaderData(1, Qt::Horizontal, "文章名称");
	model->setHeaderData(2, Qt::Horizontal, "作者");
	model->setHeaderData(3, Qt::Horizontal, "内容");
	model->setHeaderData(4, Qt::Horizontal, "创建时间");

	ui->articleTable->horizontalHeader()->setStretchLastSection(true);
	ui->articleTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	
}

//用户表
void ComprehensiveManagement::on_UserUpdateBtn_clicked()
{
	QItemSelectionModel* selectionModel = ui->userTable->selectionModel();
	QModelIndexList selectedIndexes = selectionModel->selectedIndexes();

	if (selectedIndexes.isEmpty()) {
		QMessageBox::warning(this, "警告", "请选择要修改的单元格！");
		return;
	}

	QModelIndex index = selectedIndexes.first();
	QAbstractItemModel* model = ui->userTable->model();

	int row = index.row();
	int col = index.column();

	// 获取用户ID（第0列）
	int userId = model->data(model->index(row, 0)).toInt();

	if (userId == 0) {
		QMessageBox::warning(this, "错误", "无法获取用户ID！");
		return;
	}

	// 获取字段名
	QString fieldName = model->headerData(col, Qt::Horizontal).toString();

	//禁止修改：用户ID、学校、权限
	if (fieldName == "用户ID" || fieldName == "学校" || fieldName == "权限") {
		QMessageBox::warning(this, "提示", "该字段不允许修改！");
		return;
	}

	// 当前值
	QString oldValue = model->data(index).toString();

	// 输入弹窗
	bool ok;
	QString newValue = QInputDialog::getText(
		this,
		"修改用户",
		QString("修改【%1】\n当前值：%2").arg(fieldName).arg(oldValue),
		QLineEdit::Normal,
		oldValue,
		&ok
	);

	if (!ok || newValue.isEmpty()) return;
	if (newValue == oldValue) {
		QMessageBox::information(this, "提示", "没有修改内容");
		return;
	}

	// 调用Service
	bool success = m_userservice->updateUserField(userId, fieldName, newValue);

	if (success) {
		QMessageBox::information(this, "成功", "修改成功！");
		loadDefaultData(); // 刷新表格
	}
	else {
		QMessageBox::critical(this, "失败", "修改失败！");
	}
}


void ComprehensiveManagement::on_UserDeleteBtn_clicked()
{
	//获取选中表格中的内容
	//获取选择模型
	QItemSelectionModel* selectionModel = ui->userTable->selectionModel();
	// 获取选中行索引
	QModelIndexList selectedRows = selectionModel->selectedRows();

	if (selectedRows.isEmpty()) {
		QMessageBox::warning(this, "警告", "请先选择要删除的行");
		return;
	}
	//获取选中行的userId
	int userId = ui->userTable->model()->data(selectedRows.at(0)).toInt();
	// 弹出确认删除的弹窗
	QMessageBox::StandardButton result;
	result = QMessageBox::question(this, "确认删除", "确认删除该用户吗？\n删除后数据无法恢复！", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
	if (result == QMessageBox::No) {	// 点击取消
		return;
	}
	//调用eservice的delete方法
	bool deleteSuccess = m_userservice->deleteUser(userId);
	// 5. 根据删除结果给出提示，并刷新表格
	if (deleteSuccess) {
		QMessageBox::information(this, "成功", "删除成功！");
		// 关闭后刷新表格
		loadDefaultData();

	}
	else {
		QMessageBox::critical(this, "失败", "删除失败！");
	}

}

void ComprehensiveManagement::on_UserLeadingoutBtn_clicked()
{
	// 1. 获取表格模型
	QAbstractItemModel* model = ui->userTable->model();
	if (!model || model->rowCount() == 0) {
		QMessageBox::warning(this, "提示", "没有数据可以导出！");
		return;
	}

	// 2. 弹出保存对话框
	QString fileName = QFileDialog::getSaveFileName(
		this,
		"导出用户名单",
		QString("用户名单_%1.csv").arg(QDateTime::currentDateTime().toString("yyyyMMddHHmmss")),
		"CSV 文件 (*.csv)"
	);

	if (fileName.isEmpty()) return;

	// 3. 打开文件
	QFile file(fileName);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
		QMessageBox::critical(this, "错误", "无法创建文件！");
		return;
	}

	QTextStream out(&file);
	out.setEncoding(QStringConverter::Utf8); // 解决中文乱码

	// 4. 写表头（和你表格一致）
	out << "用户ID,用户名,学号,学校,EMail,权限\n";

	// 5. 循环写数据
	for (int row = 0; row < model->rowCount(); ++row) {
		QString userId = model->data(model->index(row, 0)).toString();
		QString userName = model->data(model->index(row, 1)).toString();
		QString studentId = model->data(model->index(row, 2)).toString();
		QString school = model->data(model->index(row, 3)).toString();
		QString email = model->data(model->index(row, 4)).toString();
		QString status = model->data(model->index(row, 5)).toString();

		out << userId << ","
			<< userName << ","
			<< studentId << ","
			<< school << ","
			<< email << ","
			<< status << "\n";
	}

	file.close();

	QMessageBox::information(this, "成功", "用户名单导出完成！");
}
//赛事表
//查询
void ComprehensiveManagement::on_CompSelectBtn_clicked()
{
	// 获取下拉框选择：0=比赛名称 1=文章 2=创建者
	int chooseId = ui->compComboBox->currentIndex();
	QString inputText = ui->compSelectEdit->text().trimmed();

	// 为空则刷新全部数据
	if (inputText.isEmpty()) {
		loadDefaultData();
		return;
	}

	// 下拉框 对应 数据库字段名
	QStringList fieldList = { "CompName", "ArticleName", "Creator" };

	if (chooseId < 0 || chooseId >= fieldList.size())
		return;

	// 当前学校（你现在用的测试值）
	//QString schoolName = "嗡嗡嗡";
	UserManager& userMgr = UserManager::instance();
	QString SchoolName = userMgr.getSchoolName();

	// 调用 service 查询
	QSqlQueryModel* model = m_competitionservice->queryCompByDynamicField(SchoolName,fieldList[chooseId],inputText);

	// 显示到表格
	drawCompTable(model);
}
//添加
void ComprehensiveManagement::on_CompInsertBtn_clicked()
{
	//调用发布比赛
	CompetitionPublish* competitionPublish = new CompetitionPublish();
	competitionPublish->setAttribute(Qt::WA_DeleteOnClose);
	competitionPublish->show();
	// 关闭后刷新表格
	connect(competitionPublish, &CompetitionPublish::destroyed, this, [this]() {
		loadDefaultData();  // 窗口关闭后 → 刷新表格
		});

}
//删除
void ComprehensiveManagement::on_CompDeleteBtn_clicked()
{
	//获取选中表格中的内容
	//获取选择模型
	QItemSelectionModel* selectionModel = ui->compTable->selectionModel();
	// 获取选中行索引
	QModelIndexList selectedRows = selectionModel->selectedRows();

	if (selectedRows.isEmpty()) {
		QMessageBox::warning(this, "警告", "请先选择要删除的行");
		return;
	}
	//获取选中行的compId
	int compId = ui->compTable->model()->data(selectedRows.at(0)).toInt();
	// 弹出确认删除的弹窗
	QMessageBox::StandardButton result;
	result = QMessageBox::question(this, "确认删除", "确认删除该赛事吗？\n删除后无法恢复！", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
	if (result == QMessageBox::No) {	// 点击取消
		return;
	}
	//调用eservice的delete方法
	bool deleteSuccess = m_competitionservice->deleteCompetition(compId);
	// 5. 根据删除结果给出提示，并刷新表格
	if (deleteSuccess) {
		QMessageBox::information(this, "成功", "删除成功！");
		// 关闭后刷新表格
		loadDefaultData();

	}
	else {
		QMessageBox::critical(this, "失败", "删除失败！");
	}

}
//导出
void ComprehensiveManagement::on_CompLeadingoutBtn_clicked()
{
	// 1. 获取表格模型
	QAbstractItemModel* model = ui->compTable->model();
	if (!model || model->rowCount() == 0) {
		QMessageBox::warning(this, "提示", "没有比赛数据可以导出！");
		return;
	}

	// 2. 弹出保存对话框（自动带时间戳，不覆盖）
	QString fileName = QFileDialog::getSaveFileName(
		this,
		"导出比赛名单",
		QString("比赛数据_%1.csv").arg(QDateTime::currentDateTime().toString("yyyyMMddHHmmss")),
		"CSV 文件 (*.csv)"
	);

	if (fileName.isEmpty())
		return;

	// 3. 打开文件
	QFile file(fileName);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
		QMessageBox::critical(this, "错误", "无法创建文件！");
		return;
	}

	QTextStream out(&file);
	out.setEncoding(QStringConverter::Utf8); // 解决 Excel 中文乱码

	// 4. 写入表头（和你 drawCompTable 完全一致）
	out << "比赛ID,比赛名称,文章,创建者,学校,开始时间,结束时间,创建时间,限时\n";

	// 5. 逐行导出数据
	for (int row = 0; row < model->rowCount(); ++row) {
		QString compId = model->data(model->index(row, 0)).toString();
		QString compName = model->data(model->index(row, 1)).toString();
		QString article = model->data(model->index(row, 2)).toString();
		QString creator = model->data(model->index(row, 3)).toString();
		QString school = model->data(model->index(row, 4)).toString();
		QString startTime = model->data(model->index(row, 5)).toString();
		QString endTime = model->data(model->index(row, 6)).toString();
		QString createTime = model->data(model->index(row, 7)).toString();
		QString timeLimit = model->data(model->index(row, 8)).toString();

		out << compId << ","
			<< compName << ","
			<< article << ","
			<< creator << ","
			<< school << ","
			<< startTime << ","
			<< endTime << ","
			<< createTime << ","
			<< timeLimit << "\n";
	}

	file.close();
	QMessageBox::information(this, "成功", "比赛数据导出成功！\n文件名：" + fileName);
}


void ComprehensiveManagement::selectArticleInfoByChoose()
{
	//获取用户在下拉框的选项
	int chooseId = ui->articleComboBox->currentIndex();
	//对选择进行判断，如果是文章名称，则调用articleservice的selectArticleInfoByArticleName方法，否则调用articleservice的selectArticleByAuthor方法
	QString articleName = ui->ArticlelSelectEdit->text();
	if (articleName.isEmpty())
	{
		loadDefaultData();
	}
	else {
		if (chooseId == 0) {
			QSqlQueryModel* articleModel = m_articleservice->selectArticleInfoByArticleName(articleName);
			//填充数据到表格
			this->drawArticleTable(articleModel);
		}
		else
		{
			//如果为作者，则调用articleservice的selectArticleByAuthor方法
			QSqlQueryModel* articleModel = m_articleservice->selectArticleInfoByAuthor(articleName);
			//填充数据到表格
			this->drawArticleTable(articleModel);
		}
	}
	
}
//比赛成绩表
void ComprehensiveManagement::drawCompScoreTable(QSqlQueryModel* model)
{
	ui->compScoreTable->setModel(model);

	ui->compScoreTable->setSortingEnabled(true);
	ui->compScoreTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

	model->setHeaderData(0, Qt::Horizontal, "记录ID");
	model->setHeaderData(1, Qt::Horizontal, "比赛名称");
	model->setHeaderData(2, Qt::Horizontal, "文章");
	model->setHeaderData(3, Qt::Horizontal, "用户名");
	model->setHeaderData(4, Qt::Horizontal, "学号");
	model->setHeaderData(5, Qt::Horizontal, "速度(WPM)");
	model->setHeaderData(6, Qt::Horizontal, "准确率(%)");
	model->setHeaderData(7, Qt::Horizontal, "用时(秒)");
	model->setHeaderData(8, Qt::Horizontal, "得分");
	model->setHeaderData(9, Qt::Horizontal, "耗时");
	model->setHeaderData(10, Qt::Horizontal, "提交时间");

	ui->compScoreTable->horizontalHeader()->setStretchLastSection(true);
	ui->compScoreTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}



void ComprehensiveManagement::on_ArticleDeleteBtn_clicked()
{
	//获取选中表格中的内容
	//获取选择模型
	QItemSelectionModel* selectionModel = ui->articleTable->selectionModel();
	// 获取选中行索引
	QModelIndexList selectedRows = selectionModel->selectedRows();

	if (selectedRows.isEmpty()) {
		QMessageBox::warning(this, "警告", "请先选择要删除的行");
		return;
	}
	//获取选中行的ArticleID
	int articleId = ui->articleTable->model()->data(selectedRows.at(0)).toInt();
	// 弹出确认删除的弹窗（防止误删，公司开发必做）
	QMessageBox::StandardButton result;
	result = QMessageBox::question(this, "确认删除", "确认删除该文章吗？", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
	if (result == QMessageBox::No) {	// 点击取消
		return;
	}
	//调用articleservice的deleteArticle方法
	bool deleteSuccess = m_articleservice->deleteArticleInfoByArticleId(articleId);
	// 5. 根据删除结果给出提示，并刷新表格
	if (deleteSuccess) {
		QMessageBox::information(this, "成功", "删除成功！");
		// 关闭后刷新表格
		loadDefaultData();

	}
	else {
		QMessageBox::critical(this, "失败","删除失败！" );
	}
}


void ComprehensiveManagement::on_ArticleInsertBtn_clicked()
{
	//直接打开新增文章的界面，在另一个界面上操作
	uploadArticle* uploadarticle = new uploadArticle(); // 不传 this
	uploadarticle->setAttribute(Qt::WA_DeleteOnClose);
	uploadarticle->show();
	// 关闭后刷新表格
	connect(uploadarticle, &uploadArticle::destroyed, this, [this]() {
		loadDefaultData();  // 窗口关闭后 → 刷新表格
		});
	
}

void ComprehensiveManagement::on_ArticleUpdateBtn_clicked()
{
	QItemSelectionModel* selectionModel = ui->articleTable->selectionModel();
	QModelIndexList selectedIndexes = selectionModel->selectedIndexes();

	if (selectedIndexes.isEmpty()) {
		QMessageBox::warning(this, "警告", "请选择要修改的单元格！");
		return;
	}

	QModelIndex index = selectedIndexes.first();
	QAbstractItemModel* model = ui->articleTable->model();

	int row = index.row();
	int col = index.column();

	// ====== 获取文章ID（第0列）======
	int articleId = model->data(model->index(row, 0)).toInt();

	if (articleId == 0) {
		QMessageBox::warning(this, "错误", "无法获取文章ID！");
		return;
	}

	// ====== 获取字段名 ======
	QString fieldName = model->headerData(col, Qt::Horizontal).toString();

	// ❌ 禁止修改ID和时间（公司规范）
	if (fieldName == "文章ID" || fieldName == "创建时间") {
		QMessageBox::warning(this, "提示", "该字段不允许修改！");
		return;
	}

	// ====== 当前值 ======
	QString oldValue = model->data(index).toString();

	// ====== 输入弹窗 ======
	bool ok;
	QString newValue = QInputDialog::getText(
		this,
		"修改文章",
		QString("修改【%1】\n当前值：%2").arg(fieldName).arg(oldValue),
		QLineEdit::Normal,
		oldValue,
		&ok
	);

	if (!ok || newValue.isEmpty()) return;

	if (newValue == oldValue) {
		QMessageBox::information(this, "提示", "没有修改内容");
		return;
	}

	// ====== 调用Service ======
	bool success = m_articleservice->updateArticleField(articleId, fieldName, newValue);

	if (success) {
		QMessageBox::information(this, "成功", "修改成功！");
		loadDefaultData(); // 刷新表格
	}
	else {
		QMessageBox::critical(this, "失败", "修改失败！");
	}
}
//比赛信息表
	//条件查询
void ComprehensiveManagement::on_compScoreSelectBtn_clicked()
{
	//两种条件1、比赛名称 2、文章名称,也需要连表查询
	int chooseId = ui->compScoreComboBox->currentIndex();
	QString inputText = ui->compScoreSelectEdit->text().trimmed();

	if (inputText.isEmpty()) {
		loadDefaultData(); // 刷新全部成绩
		return;
	}

	// 下拉框对应：比赛名称、文章名称
	QStringList fieldList = { "c.CompName", "a.ArticleName","u.StudentID"};

	if (chooseId < 0 || chooseId >= fieldList.size())
		return;

	// 查询
	QSqlQueryModel* model = m_competitionrecordsservice->queryCompScoreByDynamicField(
		fieldList[chooseId],
		inputText
	);

	// 显示到成绩表格
	drawCompScoreTable(model);

}
//导出
void ComprehensiveManagement::on_compScoreLeadingOutBtn_clicked()
{
	// 1. 获取表格模型
	QAbstractItemModel* model = ui->compScoreTable->model();
	if (!model || model->rowCount() == 0) {
		QMessageBox::warning(this, "提示", "没有比赛成绩可以导出！");
		return;
	}

	// 2. 弹出保存对话框（自动带时间戳）
	QString fileName = QFileDialog::getSaveFileName(
		this,
		"导出比赛成绩",
		QString("比赛成绩_%1.csv").arg(QDateTime::currentDateTime().toString("yyyyMMddHHmmss")),
		"CSV 文件 (*.csv)"
	);

	if (fileName.isEmpty())
		return;

	// 3. 打开文件
	QFile file(fileName);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
		QMessageBox::critical(this, "错误", "无法创建文件！");
		return;
	}

	QTextStream out(&file);
	out.setEncoding(QStringConverter::Utf8); // 解决中文乱码

	// 4. 写入表头（和你 drawCompScoreTable 完全一致）
	out << "记录ID,比赛名称,文章,用户名,学号,速度(WPM),准确率(%),用时(秒),得分,耗时,提交时间\n";

	// 5. 逐行导出数据
	for (int row = 0; row < model->rowCount(); ++row) {
		QString recordId = model->data(model->index(row, 0)).toString();
		QString compName = model->data(model->index(row, 1)).toString();
		QString article = model->data(model->index(row, 2)).toString();
		QString userName = model->data(model->index(row, 3)).toString();
		QString studentId = model->data(model->index(row, 4)).toString();
		QString wpm = model->data(model->index(row, 5)).toString();
		QString accuracy = model->data(model->index(row, 6)).toString();
		QString timeUsed = model->data(model->index(row, 7)).toString();
		QString finalScore = model->data(model->index(row, 8)).toString();
		QString costTime = model->data(model->index(row, 9)).toString();
		QString submitTime = model->data(model->index(row, 10)).toString();

		out << recordId << ","
			<< compName << ","
			<< article << ","
			<< userName << ","
			<< studentId << ","
			<< wpm << ","
			<< accuracy << ","
			<< timeUsed << ","
			<< finalScore << ","
			<< costTime << ","
			<< submitTime << "\n";
	}

	file.close();
	QMessageBox::information(this, "成功", "比赛成绩导出成功！");
}
