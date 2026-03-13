#include "settlementdialog.h"
#include "ui_settlementdialog.h"
#include "mainwidget.h"

settlementDialog::settlementDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::settlementDialog)
{
    ui->setupUi(this);

    //ant风格ui
    antStyle();

}

settlementDialog::~settlementDialog()
{
    delete ui;
}

void settlementDialog::showData(int totalChars, int typedChars, int correctChars, int errorChars, double accuracy, double wpm, int usedSeconds)
{
    ui->settleTime->setText(QString::number(usedSeconds) + "秒");
    ui->settleSpeed->setText(QString::number(wpm) + "字/min");
    ui->settleAccuracy->setText(QString::number(accuracy) + "%");
    ui->settleAllchar->setText(QString::number(totalChars) + "字");
    ui->settleInputchar->setText(QString::number(typedChars) + "字");
    ui->settleErrChar->setText(QString::number(errorChars) + "字");
}

void settlementDialog::antStyle()
{
    ui->ConfirmBtn->setProperty("type","primary");
    ui->settleWidget->setProperty("type","PerformanceWidget");
    //刷新样式

}

void settlementDialog::on_ConfirmBtn_clicked()
{
    //点击确认后，返回到主页面mainwidget,
    //关闭当前窗口
    emit requestClosePractice();    //发送信号，通知practicewidget关闭当前窗口
    //this->close();  //关闭弹窗
    accept();
}
