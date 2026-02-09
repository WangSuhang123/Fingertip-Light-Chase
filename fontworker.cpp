#include "fontworker.h"

#include <QVector>

FontWorker::FontWorker(QObject *parent)
    : QObject{parent}
{}

void FontWorker::setTargetText(const QString &text)
{
    //保存目标文本，不做比较
    targetText = text;

}

void FontWorker::processInput(const QString &input)
{
    QVector<bool> results;

    //比较长度：取较大值，保证一一对应
    int maxLen = qMax(input.length(),targetText.length());

    results.resize(maxLen);

    for (int i = 0; i < maxLen; ++i) {
        //情况1 输入字符串越界
        if(i >= input.length()){
            results[i] = false;
            continue;
        }

        //情况2，目标字符串越界
        if(i>=targetText.length()){
            results[i] = false;
            continue;
        }

        //情况3：双方都有字符
        QChar inputChar = input.at(i);
        QChar targetChar = targetText.at(i);

        if(ignoreCase){
            inputChar = inputChar.toLower();
            targetChar = targetChar.toLower();
        }

        results[i] = (inputChar == targetChar);

    }
    //一次性发出结果
    emit matchResultReady(results);


}

