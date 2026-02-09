#ifndef TIMESERVICE_H
#define TIMESERVICE_H

#include "timeworker.h"
#include <QObject>
#include <QThread>

class TimeService : public QObject
{
    Q_OBJECT
public:
    explicit TimeService(QObject *parent = nullptr);
    ~TimeService();

    void start();
    void stop();

signals:
    void timeUpdated(const QString &timeStr);

private:
    QThread    *thread;
    timeworker *worker;
};

#endif // TIMESERVICE_H
