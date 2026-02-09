#ifndef FONTSERVICE_H
#define FONTSERVICE_H
#include "fontworker.h"
#include <QObject>
#include <QThread>

class FontService : public QObject
{
    Q_OBJECT
public:
    explicit FontService(QObject *parent = nullptr);
    ~FontService();

    // UI 调用的接口
    void setTargetText(const QString &text);
    void processInput(const QString &input);

signals:
    // UI 监听的信号
    void matchResultReady(const QVector<bool> &results);
private:
    QThread *thread;
    FontWorker *worker;
};

#endif // FONTSERVICE_H
