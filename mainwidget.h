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

};

#endif // MAINWIDGET_H
