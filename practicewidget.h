#ifndef PRACTICEWIDGET_H
#define PRACTICEWIDGET_H

#include <QWidget>
#include <QThread>
#include <QLabel>
#include <QLineEdit>


//前向声明 ClockService，避免包含头文件导致循环依赖或编译变慢
class ClockService;

namespace Ui {
class PracticeWidget;
}

class PracticeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PracticeWidget(QWidget *parent = nullptr);
    ~PracticeWidget();


    //获取用户选择的文章id和时间
    void onSetupReceived(int articleId, int practiceTime);

    // 接口函数：判断时间是否已到
    // 返回 true 表示时间已耗尽 (00:00)，false 表示还有时间
    bool isTimeUp() const;

protected:
    // 【新增】重写显示事件，确保获取真实宽度
    void showEvent(QShowEvent *event) override;
    //支持窗口 resize 自动重建
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::PracticeWidget *ui;

    QString originalTargetText;//初始化目标变量
    QVector<QString> splitLines;          // 分行后的文本
    QVector<QLabel*> labelList;           // 每一行的 label
    QVector<QLineEdit*> editList;         // 每一行的 lineEdit

    bool isInitialized = false; //防止由于窗口切换导致的重复初始化
    //初始化变量
    int m_currentArticleId = -1;
    int m_practiceDuration = 0;

    // 【核心修改】将 ClockService 声明为成员变量
    ClockService *m_clockService;

    // 【新增】标记位，记录时间是否已到
    bool m_isTimeUp;


    // 声明一个根据ID加载文章的私有函数
    void loadArticleContentById(int id);



private slots:

    void loadArticleAndGenerateWidgets(); //将生成逻辑封装成函数

    //更新ui界面
    void UpdateUIShow();

signals:
    //读取到用户选择的信息后
    void GetChooseDataSignals();

};

#endif // PRACTICEWIDGET_H
