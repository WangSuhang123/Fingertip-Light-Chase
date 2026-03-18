#include "CompetitionService.h"
#include <QDateTime>
#include <QMessageBox>

CompetitionService::CompetitionService(QObject *parent)
	: QObject(parent)
{}

CompetitionService::~CompetitionService()
{}


bool CompetitionService::insertCompetition(const QString& competitionName, int articleId, int creatorId, const QString& targetSchool, const QDateTime& startTime, const QDateTime& endTime, int DurationMinutes)
{
    QDateTime currentDateTime = QDateTime::currentDateTime();

    // 输入校验
    if (competitionName.isEmpty() || startTime.isNull() || endTime.isNull() || DurationMinutes <= 0) {
        QMessageBox::warning(nullptr, "警告", "所有输入项不能为空，且时长需大于0！");
        return false;
    }
    // 时间校验
    if (startTime <= currentDateTime) {
        QMessageBox::warning(nullptr, "警告", "比赛开始时间必须大于当前时间！");
        return false;
    }
    if (endTime <= startTime) {
        QMessageBox::warning(nullptr, "警告", "比赛结束时间必须大于开始时间！");
        return false;
    }

    // 插入数据
    return m_competitionDao->insertCompetition(competitionName, articleId, creatorId, targetSchool, startTime, endTime, DurationMinutes);
}

QList<QVariantMap> CompetitionService::getCompetitionList(const QString& school)
{
    return m_competitionDao->getCompetitionsBySchool(school);
}


