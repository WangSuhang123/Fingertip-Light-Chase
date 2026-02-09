#ifndef PRACTICEWIDGET_H
#define PRACTICEWIDGET_H

#include <QWidget>
#include <QThread>
#include <QLabel>
#include <QLineEdit>

namespace Ui {
class PracticeWidget;
}

class PracticeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PracticeWidget(QWidget *parent = nullptr);
    ~PracticeWidget();

protected:
    // 【新增】重写显示事件，确保获取真实宽度
    void showEvent(QShowEvent *event) override;

private:
    Ui::PracticeWidget *ui;

    QString originalTargetText;//初始化目标变量
    QVector<QString> splitLines;          // 分行后的文本

    QVector<QLabel*> labelList;           // 每一行的 label
    QVector<QLineEdit*> editList;         // 每一行的 lineEdit

    bool isInitialized = false; //防止由于窗口切换导致的重复初始化
    void loadArticleAndGenerateWidgets(); //将生成逻辑封装成函数
};

#endif // PRACTICEWIDGET_H
