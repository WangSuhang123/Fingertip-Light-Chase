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
    // 设置倒计时初始值
    void setInitialSeconds(int seconds);

    void start();
    void pause();
    void reset();
signals:
    void timeElapsed(int seconds);

private:
    QTimer *timer = nullptr;    // 初始化timer为nullptr，避免野指针
    int elapsedSeconds = 0; // 倒计时剩余秒数
};

#endif // CLOCKWORKER_H
