#ifndef PRACTICESETUPDIALOG_H
#define PRACTICESETUPDIALOG_H

#include <QDialog>
#include "articleservice.h"

namespace Ui {
class PracticeSetupDialog;
}

class PracticeSetupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PracticeSetupDialog(QWidget *parent = nullptr);
    ~PracticeSetupDialog();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    Ui::PracticeSetupDialog *ui;
    ArticleService articleService; // 声明 Service 对象

    QPoint m_dragPos;

private slots:

    void initComboBox(); // 初始化下拉框的函数

    //获取填入弹窗数据的函数
    void GetDataFromDialog();   // 这个槽函数负责发射信号

    //打开练习页面
    void OpenPracticeWidget(int articleId, int practiceTime);

signals:
    //定义信号：当用户点击确认时发射，携带 ID 和时间
    void setupConfirmed(int articleId, int practiceTime);


};

#endif // PRACTICESETUPDIALOG_H
