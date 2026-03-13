#ifndef SETTLEMENTDIALOG_H
#define SETTLEMENTDIALOG_H

#include <QDialog>

namespace Ui {
class settlementDialog;
}

class settlementDialog : public QDialog
{
    Q_OBJECT

public:
    explicit settlementDialog(QWidget *parent = nullptr);
    ~settlementDialog();
    //结算数据展示
    void showData(int totalChars, int typedChars, int correctChars, int errorChars, double accuracy, double wpm, int usedSeconds);


private:
    Ui::settlementDialog *ui;

    void antStyle();

private slots:
    void on_ConfirmBtn_clicked();
signals:
    void requestClosePractice();
};

#endif // SETTLEMENTDIALOG_H
