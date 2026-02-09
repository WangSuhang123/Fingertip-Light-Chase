#include "clockservice.h"

ClockService::ClockService(QObject *parent)
    : QObject{parent}
{
    thread = new QThread(this);
    worker = new ClockWorker();

    worker->moveToThread(thread);

    connect(thread,&QThread::finished,worker,&QObject::deleteLater);

    connect(worker,&ClockWorker::timeElapsed,this,&ClockService::timeUpdated);

    thread->start();

}

ClockService::~ClockService()
{
    thread->quit();
    thread->wait();
}

void ClockService::start()
{
    QMetaObject::invokeMethod(worker, "start", Qt::QueuedConnection);
}

void ClockService::pause()
{
    QMetaObject::invokeMethod(worker, "pause", Qt::QueuedConnection);
}

void ClockService::reset()
{
    QMetaObject::invokeMethod(worker, "reset", Qt::QueuedConnection);
}
