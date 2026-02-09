#include "timeservice.h"

TimeService::TimeService(QObject *parent)
    : QObject{parent}
{
    //创建线程和时间管理类的对象
    thread = new QThread(this);
    worker = new timeworker();

    //将时间放入子线程中
    worker->moveToThread(thread);

    //线程开始的时候调用时间工作类的开始方法
    connect(thread, &QThread::started,
            worker, &timeworker::start);

    //当时间工作类的时间更新方法启动的时候，调用服务类的更新方法
    connect(worker, &timeworker::timeUpdated,
            this, &TimeService::timeUpdated);

    //当线程结束的时候，释放work内存
    connect(thread, &QThread::finished,
            worker, &QObject::deleteLater);
}

void TimeService::start()
{
    if(!thread->isRunning()){
        thread->start();
    }
}

void TimeService::stop()
{
    if (thread->isRunning())
    {
        thread->quit();
        thread->wait();
    }
}

TimeService::~TimeService()
{
    stop();
}
