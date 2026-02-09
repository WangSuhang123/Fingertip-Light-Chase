#include "timeworker.h"
#include <QDebug>
#include <QThread>
#include <QDateTime>

timeworker::timeworker(QObject *parent)
    : QObject{parent}
{}

void timeworker::start()
{
    //打印线程地址
    qDebug() << "TimeWorker thread:" << QThread::currentThread();
    //创建timer对象
    timer = new QTimer(this);
    //连接，当timer发出timeout信号时获取当前时间，并设置QDateTime的格式
    connect(timer, &QTimer::timeout, this, [=]() {
        QString timeStr =
            QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
        //发射时间更新的信号，并传入当前的时间
        emit timeUpdated(timeStr);
    });
    //
    timer->start(1000);


}

void timeworker::stop()
{
    if (timer)
        timer->stop();
}
