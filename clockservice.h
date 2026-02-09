#ifndef CLOCKSERVICE_H
#define CLOCKSERVICE_H

#include <QObject>
#include <QThread>

#include "clockworker.h"

class ClockService : public QObject
{
    Q_OBJECT
public:
    explicit ClockService(QObject *parent = nullptr);
    ~ClockService();

    void start();
    void pause();
    void reset();


signals:
    void timeUpdated(int seconds);

private:
    QThread *thread;
    ClockWorker *worker;
};

#endif // CLOCKSERVICE_H
