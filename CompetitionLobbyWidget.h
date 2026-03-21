#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QTableWidgetItem>
#include <QHBoxLayout>
#include <QMessageBox>

#include "CompetitionService.h"
#include "CompetitionRecordsService.h"
#include "usermanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CompetitionLobbyWidgetClass; }
QT_END_NAMESPACE


struct Competition
{
    int compId;
    QString name;
    QString startTime;
    QString endTime;
    QString status;
    int limitTime;
};


class CompetitionLobbyWidget : public QMainWindow
{
    Q_OBJECT

public:
    CompetitionLobbyWidget(QWidget* parent = nullptr);
    ~CompetitionLobbyWidget();

private:
    Ui::CompetitionLobbyWidgetClass* ui;

    CompetitionService competitionService;
    CompetitionRecordsService competitionrecordsservice;

    //更新ui样式
    void updataUiShow();

    //初始化表格
    void initTable();

    //加载比赛数据
    void loadCompetitions();

    //添加操作按钮
    void addOperateButton(int row, int compId, QString status, bool hasJoined);

    //按钮点击逻辑
    void onCompetitionClicked(int compId, QString status);

signals:

    //进入比赛
    void enterCompetition(int compId);
};