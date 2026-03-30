#pragma once

#include <QMainWindow>
#include "ui_LeaderboardFeature.h"
#include <QSqlQueryModel>
#include "CompetitionRecordsService.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LeaderboardFeatureClass; };
QT_END_NAMESPACE

class LeaderboardFeature : public QMainWindow
{
	Q_OBJECT

public:
	LeaderboardFeature(QWidget *parent = nullptr);
	~LeaderboardFeature();

	//ui样式展示
	void showUI();
	//绘画表格
	void paintTable(QSqlQueryModel* model);

	void loadGlobalRanking();

private:
	Ui::LeaderboardFeatureClass *ui;
	CompetitionRecordsService* competitionRecordsService;

private slots:
	void on_leaderboardSelectBtn_clicked();
};

