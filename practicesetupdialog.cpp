#include "practicesetupdialog.h"
#include "ui_practicesetupdialog.h"
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>

PracticeSetupDialog::PracticeSetupDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PracticeSetupDialog)
{
    ui->setupUi(this);

    // 隐藏标题栏
    // setWindowFlags(Qt::FramelessWindowHint);
    // setAttribute(Qt::WA_TranslucentBackground); // 允许透明，用于圆角

    // ui->PracticeDialogWidegt->setStyleSheet(R"(
    //     QWidget {
    //         border-radius: 12px;
    //     }
    // )");


    // // === 2. 关键：为阴影预留空间（覆盖.ui中的0边距）===
    // if (QLayout *mainLayout = this->layout()) {
    //     mainLayout->setContentsMargins(5, 5, 5, 5); // 阴影需要呼吸空间
    // }

    // QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    // shadow->setBlurRadius(25);          // 模糊程度（越大越柔和）
    // shadow->setColor(QColor(0, 0, 0, 60)); // 半透明深灰（非纯黑更自然）
    // shadow->setOffset(0, 8);            // 垂直偏移8px（模拟顶部光源）
    // ui->PracticeDialogWidegt->setGraphicsEffect(shadow);


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

    qDebug()<<"数据库ID为："<<SelectId<<"选择时间为："<<PracticeTime;
}
