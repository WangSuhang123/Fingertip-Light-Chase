#include "clockworker.h"

ClockWorker::ClockWorker(QObject *parent)
    : QObject{parent}
{}

void ClockWorker::start()
{
    if(!timer){
        timer = new QTimer(this);
        connect(timer,&QTimer::timeout,this,[=](){
            elapsedSeconds++;
            emit timeElapsed(elapsedSeconds);
        });
    }
    if(!timer->isActive()){
        timer->start(1000);
    }
}

void ClockWorker::pause()
{
    if(timer && timer->isActive()){
        timer->stop();
    }
}

void ClockWorker::reset()
{
    pause();
    elapsedSeconds = 0;
}
