#include "practicesetupdialog.h"
#include "ui_practicesetupdialog.h"
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>
#include "practicewidget.h"

PracticeSetupDialog::PracticeSetupDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PracticeSetupDialog)
{
    ui->setupUi(this);


    //设置控件ant风格
    ui->PracticeDialogWidegt->setProperty("type","frontPage");

    ui->PracticeOn->setProperty("type","primary");
    ui->PracticeOff->setProperty("type","text");

    //connect连接
    connect(ui->PracticeOn,&QPushButton::clicked,this,&PracticeSetupDialog::GetDataFromDialog);
    //关闭弹窗
    connect(ui->PracticeOff,&QPushButton::clicked,this,[this](){
        this->close();
    });
    //开始练习
    //connect(ui->PracticeOn,&QPushButton::clicked,this,&PracticeSetupDialog::)

    initComboBox();
}

PracticeSetupDialog::~PracticeSetupDialog()
{
    delete ui;
}

void PracticeSetupDialog::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragPos = event->globalPosition().toPoint() - this->frameGeometry().topLeft();
        event->accept();
    }
}

void PracticeSetupDialog::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPosition().toPoint() - m_dragPos);
        event->accept();
    }
}

void PracticeSetupDialog::initComboBox()
{
    //通过Service获取数据
    QList<Article> articles = articleService.getArticleListForDropdown();
    //清空下拉框（防止重复添加
    ui->comboBoxArticle->clear();
    //遍历数据添加到下拉框
    for(const Article &art : articles){
        // addItem(显示的文字, 隐藏的数据)
        // 这一点非常重要：用户看的是 Title，但程序后台需要 ID
        ui->comboBoxArticle->addItem(art.title, art.id);
    }
}

void PracticeSetupDialog::GetDataFromDialog()
{
    int SelectId = ui->comboBoxArticle->currentData().toInt();
    int PracticeTime = ui->PracticeTimeBox->value();

    qDebug()<<"发射信号mm数据库ID为："<<SelectId<<"选择时间为："<<PracticeTime;

    emit setupConfirmed(SelectId, PracticeTime);

    // 发射完信号后，关闭对话框
    this->accept();

    OpenPracticeWidget(SelectId, PracticeTime);

}

//打开练习页面，如何在页面上选择的参数正确传递则打卡，否则则失败
void PracticeSetupDialog::OpenPracticeWidget(int articleId, int practiceTime)
{
    PracticeWidget *practicewidget = new PracticeWidget();
    // 【关键步骤】在 show() 之前，先把数据传进去
    practicewidget->onSetupReceived(articleId, practiceTime);

    practicewidget->setAttribute(Qt::WA_DeleteOnClose);
    practicewidget->show();
    this->close();
    //this->deleteLater();
}
