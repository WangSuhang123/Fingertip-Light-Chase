#ifndef CLOCKWORKER_H
#define CLOCKWORKER_H

#include <QObject>
#include <QTimer>

class ClockWorker : public QObject
{
    Q_OBJECT
public:
    explicit ClockWorker(QObject *parent = nullptr);

public slots:
    void start();
    void pause();
    void reset();
signals:
    void timeElapsed(int seconds);

private:
    QTimer *timer = nullptr;
    int elapsedSeconds = 0;
};

#endif // CLOCKWORKER_H
