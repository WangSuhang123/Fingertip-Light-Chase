#ifndef PRACTICEWIDGET_H
#define PRACTICEWIDGET_H

#include <QWidget>
#include <QThread>
#include <QLabel>
#include <QDialog>
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
    QVector<QString> splitLines;          // 分行后的文本（与 label/edit 一一对应）
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

    // 【新增】练习过程统计相关
    int m_totalSeconds = 0;      // 本次练习总秒数
    int m_remainingSeconds = 0;  // 当前剩余秒数
    int m_totalChars = 0;        // 目标总字数
    int m_typedChars = 0;        // 已输入总字数
    int m_errorChars = 0;        // 错误字数
    bool m_hasSubmitted = false; // 是否已经提交（防止重复写库）
    bool m_isPaused = false;    //是否暂停

    // 私有工具函数
    void loadArticleContentById(int id);
    void loadArticleAndGenerateWidgets(const QStringList &oldInputs = {}); //将生成逻辑封装成函数
    void UpdateUIShow();                  //更新ui界面
    void updateTypingStats();             // 根据当前输入实时计算指标并刷新 UI
    void handlePracticeFinished(bool byTimeout); // 倒计时结束/点击提交时统一收尾

    //收集用户的输入，防止缩放窗口时输入消失
    QStringList collectUserInputs();

    //在暂停的时候调用模态窗口，阻塞主线程的倒计时功能
    void togglePause();

private slots:
    void on_SubmitBtn_clicked(); // 提交按钮槽函数
    void on_ExitBtn_clicked(); // 退出按钮槽函数

signals:
    //读取到用户选择的信息后
    void GetChooseDataSignals();

    // 练习结束时对外暴露的接口，方便外部进行数据库写入
    void PracticeFinished(
        int articleId,
        int usedSeconds,
        int totalChars,
        int typedChars,
        int errorChars,
        double accuracy,
        double wpm,
        bool byTimeout
        );

};

#endif // PRACTICEWIDGET_H
