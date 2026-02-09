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

    void initComboBox(); // 初始化下拉框的函数

    //获取填入弹窗数据的函数
    void GetDataFromDialog();
};

#endif // PRACTICESETUPDIALOG_H
