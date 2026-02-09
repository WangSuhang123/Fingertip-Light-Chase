#ifndef FONTWORKER_H
#define FONTWORKER_H

#include <QObject>

class FontWorker : public QObject
{
    Q_OBJECT
public:
    explicit FontWorker(QObject *parent = nullptr);

public slots:
    // 设置目标字符串（比如 label 上的文本）
    void setTargetText(const QString &text);

    // 当用户输入变化时调用
    void processInput(const QString &input);

signals:
    void matchResultReady(const QVector<bool> &results);
private:
    QString targetText;        // 目标文本（业务记忆）
    bool ignoreCase = false;   // 比较规则（示例）
};

#endif // FONTWORKER_H
