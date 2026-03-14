#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QMainWindow>

namespace Ui {
class MainWidget;
}

class MainWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    Ui::MainWidget *ui;
    void widgetStyle();
    void CardPerformanceStyle();
    void FunturesCardStyle();
    //退出当前登录的账号,并回到登录页面
    void Logout();

    //修改主页面上的欢迎标题头，改成登录者的姓名+学校
    void UpdateWidgetTitle();
    //打开登录页面
    void OpenLoginWidget();
    //打开练习功能
    void OpenPracticeFeature();

private slots:
    //打开新增文章功能
    void on_InsertArticleFeature_clicked();


};

#endif // MAINWIDGET_H
