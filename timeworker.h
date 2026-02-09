#ifndef TIMEWORKER_H
#define TIMEWORKER_H

#include <QObject>
#include <QTimer>

class timeworker : public QObject
{
    Q_OBJECT
public:
    explicit timeworker(QObject *parent = nullptr);

public slots:
    void start();   // 开始获取时间
    void stop();    // 停止


signals:
    void timeUpdated(const QString &timeStr);
private:
    QTimer *timer;
};

#endif // TIMEWORKER_H
