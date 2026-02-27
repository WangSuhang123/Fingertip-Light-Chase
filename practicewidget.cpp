#include "practicewidget.h"
#include "ui_practicewidget.h"

#include "clockservice.h"
#include "timeservice.h"
#include "fontservice.h"
#include "NoCopyPasteLineEdit.h"
#include "usermanager.h"
#include "articleservice.h"

QStringList splitTextByWidth(
    const QString &text,
    int maxWidth,
    const QFont &font
    ) {
    QFontMetrics fm(font);
    QStringList lines;

    QString currentLine;

    for (int i = 0; i < text.length(); ++i) {
        QChar ch = text[i];

        QString tryLine = currentLine + ch;

        if (fm.horizontalAdvance(tryLine) <= maxWidth) {
            currentLine = tryLine;
        } else {
            if (!currentLine.isEmpty())
                lines << currentLine;
            currentLine = ch;
        }
    }

    if (!currentLine.isEmpty())
        lines << currentLine;

    return lines;
}

void PracticeWidget::onSetupReceived(int articleId, int practiceTime)
{
    qDebug() << "收到设置数据！ID:" << articleId << "时间:" << practiceTime;

    m_currentArticleId = articleId;
    m_practiceDuration = practiceTime;

    //更改页面信息,显示的是文章名
    //通过Service获取数据
    ArticleService service;
    QString articleTitle = service.getArticleTitleById(m_currentArticleId);
    qDebug()<<articleTitle<<"11111111111111111111111111";
    ui->ArticleLabel->setText(articleTitle);
    //填充时间信息
    ui->SetTime->setText(QString("%1 分钟").arg(m_practiceDuration));




}

PracticeWidget::PracticeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PracticeWidget)
{
    ui->setupUi(this);
    //连接，当时间管理类的时间更新启动的时候更新ui上的数据
    //显示当前的时间
    auto timeService = new TimeService(this);

    connect(timeService,&TimeService::timeUpdated,this,[=](const QString &timeStr){
        ui->ClockLabel->setText(timeStr);
    });

    timeService->start();

    //ui风格
    ui->PracticeRealWidget->setProperty("type","MainFeatures");
    ui->TitleWidget->setProperty("type","TitleWidget");
    ui->TypingWidget->setProperty("type","typingWidget");
    ui->StateWidget->setProperty("type","typingState");

    ui->ExitBtn->setProperty("type","danger");
    ui->SubmitBtn->setProperty("type","primary");


}

PracticeWidget::~PracticeWidget()
{
    delete ui;
}

void PracticeWidget::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);

    // 只有第一次显示时才加载，避免最小化再打开时重置
    if (!isInitialized) {
        loadArticleAndGenerateWidgets();
        UpdateUIShow();
        isInitialized = true;
    }
}

void PracticeWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    if (isInitialized) {
        loadArticleAndGenerateWidgets();
    }
}


void PracticeWidget::loadArticleAndGenerateWidgets()
{
    // 【修改点】根据 ID 获取真实文本，而不是写死
    if (m_currentArticleId > 0) {
        ArticleService service;
        QString articleContent = service.getArticleById(m_currentArticleId); // 假设你有这个函数
        if (!articleContent.isEmpty()) {
            originalTargetText = articleContent;
        } else {
            originalTargetText = "未找到文章内容，请检查数据库。";
        }
    } else {
        // 如果没有 ID（比如第一次打开还没设置），使用默认文本用于预览
        originalTargetText = "散文是一种以记叙或抒情为主的文学样式...（默认预览文本）";
    }

    //获取 ScrollArea 的 viewport 宽度
    //viewport() 是实际显示内容的区域，比 width() 更准确（去掉了滚动条宽度）
    // 减去5是为了留出滚动条和边距的余量，防止出现水平滚动条
    int labelWidth = ui->scrollArea->viewport()->width() - 5;
    //设置默认的宽度，如果太低就设置成900
    if (labelWidth < 200) labelWidth = 800;




    //设置字体 指定字体和大小
    QFont practiceFont;
    practiceFont.setPointSize(11);
    practiceFont.setFamily("Consolas");

    //分行
    QStringList lines = splitTextByWidth(
        originalTargetText,
        labelWidth,
        practiceFont
        );

    // 清理旧控件
    QLayoutItem *child;
    while ((child = ui->contentLayout_3->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
    labelList.clear();
    editList.clear();
    //循环生成 Label 和 LineEdit
    for (int idx = 0; idx < lines.size(); ++idx) {
        const QString lineText = lines[idx];

        // Label 设置
        QLabel *label = new QLabel(lineText);
        label->setFont(practiceFont);
        label->setTextFormat(Qt::RichText);
        label->setWordWrap(false);

        // Edit 设置,不使用原生的lineedit类，使用自创的类来禁用复制粘贴等快捷键，同时取消右键菜单
        NoCopyPasteLineEdit *edit = new NoCopyPasteLineEdit;
        edit->setFont(practiceFont);
        edit->setMaxLength(lineText.length());


        // 添加到布局
        ui->contentLayout_3->addWidget(label);
        ui->contentLayout_3->addWidget(edit);
        // 保存指针
        labelList << label;
        editList << edit;

        //绑定业务逻辑 (FontService)
        auto fontService = new FontService(this);
        fontService->setTargetText(lineText);

        //不捕获 i，直接用 edit 指针
        // 输入联动
        connect(edit, &QLineEdit::textChanged, this,
                [this, fontService, edit, lineText](const QString &input) {
                    fontService->processInput(input);

                    int index = editList.indexOf(edit);
                    if (input.length() == lineText.length()
                        && index >= 0
                        && index + 1 < editList.size()) {
                        editList[index + 1]->setFocus();
                    }
                });
        // 结果回显
        connect(fontService, &FontService::matchResultReady, this,
                [label, lineText](const QVector<bool> &results) {
                    QString richText;
                    for (int j = 0; j < lineText.length(); ++j) {
                        bool match = (j < results.size()) ? results[j] : false;
                        QString color = match ? "#4CAF50" : "#F44336";
                        richText += QString(
                                        "<span style='color:%1;'>%2</span>")
                                        .arg(color,
                                             lineText.mid(j, 1).toHtmlEscaped());
                    }
                    label->setText(richText);
                });
    }
    //在底部添加一个弹簧，把内容顶上去
    ui->contentLayout_3->addStretch();
}

void PracticeWidget::UpdateUIShow()
{
    //获取登录的用户信息
    //通过 instance() 获取那个唯一的实例
    UserManager& userMgr = UserManager::instance();
    //检查是否登录
    if(userMgr.isLogin()){
        QString LoginUserName = userMgr.getUserName();
        QString LoginUserId = userMgr.getStudentId();
        QString LoginUserSchool = userMgr.getSchoolName();
        int LoginUserStatus = userMgr.getUserStatus();

        QString userStatus = "";

        if(LoginUserStatus==0){
            userStatus = "普通用户";
        }else if(LoginUserStatus==1){
            userStatus = "管理员";
        }else{
            userStatus = "其他";
        }

        // 更新 UI 上的欢迎语
        ui->UserInfoLabel->setText(LoginUserName+"-"+userStatus+"-"+LoginUserSchool);
    }else{
        qDebug() << "暂无用户登录";
    }

}


