#include "fontservice.h"
#include "fontworker.h"

FontService::FontService(QObject *parent)
    : QObject{parent}
{
    thread = new QThread(this);
    worker = new FontWorker();

    worker->moveToThread(thread);

    connect(thread,&QThread::finished,worker,&QObject::deleteLater);
    connect(worker,&FontWorker::matchResultReady,this,&FontService::matchResultReady);

    thread->start();
}

FontService::~FontService()
{
    if (thread && thread->isRunning()) {
        thread->quit();
        thread->wait();
    }
}


void FontService::setTargetText(const QString &text)
{
    QMetaObject::invokeMethod(
        worker,
        &FontWorker::setTargetText,
        Qt::QueuedConnection,
        text
        );

}

void FontService::processInput(const QString &input)
{
    QMetaObject::invokeMethod(
        worker,
        &FontWorker::processInput,
        Qt::QueuedConnection,
        input
        );

}
