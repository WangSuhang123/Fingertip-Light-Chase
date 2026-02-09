#include "practicewidget.h"
#include "ui_practicewidget.h"

#include "clockservice.h"
#include "timeservice.h"
#include "fontservice.h"

//文本分行函数
QStringList splitTextByWidth(
    const QString &text,
    int maxWidth,
    const QFont &font
    ) {
    QFontMetrics fm(font);
    QStringList lines;

    QString currentLine;

    for (QChar ch : text) {
        QString tryLine = currentLine + ch;

        if (fm.horizontalAdvance(tryLine) <= maxWidth) {
            currentLine = tryLine;
        } else {
            lines << currentLine;
            currentLine = ch;
        }
    }

    if (!currentLine.isEmpty()) {
        lines << currentLine;
    }

    return lines;
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
        isInitialized = true;
    }
}

void PracticeWidget::loadArticleAndGenerateWidgets()
{
    // 1. 获取文章 (此处暂时写死，后续替换为数据库调用)
    originalTargetText = "语言优美：所谓优美，就是指散文的语言清新明丽（也美丽），生动活泼，富于音乐感，行文如涓涓流水，叮咚有声，如娓娓而谈，情真意切。所谓凝练，是说散文的语言简洁质朴，自然流畅，寥寥数语就可以描绘出生动的形象，勾勒出动人的场景，显示出深远的意境。散文力求写景如在眼前，写情沁人心脾。语言优美：所谓优美，就是指散文的语言清新明丽（也美丽），生动活泼，富于音乐感，行文如涓涓流水，叮咚有声，如娓娓而谈，情真意切。所谓凝练，是说散文的语言简洁质朴，自然流畅，寥寥数语就可以描绘出生动的形象，"; // 你的长文本

    // 2. 【关键修正】获取 ScrollArea 的 viewport 宽度
    // viewport() 是实际显示内容的区域，比 width() 更准确（去掉了滚动条宽度）
    // 减去 30 是为了留出滚动条和边距的余量，防止出现水平滚动条
    int labelWidth = ui->scrollArea->viewport()->width() - 30;

    // 如果宽度异常小（比如窗口还没展开），给一个保底值
    if (labelWidth < 200) labelWidth = 800;

    // 3. 设置字体 (建议明确指定字体和大小，避免不同系统差异)
    QFont font = this->font();
    font.setPointSize(12);
    // font.setFamily("Consolas"); // 打字练习建议用等宽字体

    // 4. 分行
    QStringList lines = splitTextByWidth(
        originalTargetText,
        labelWidth,
        font
        );

    // 5. 清理旧控件 (为了以后重开一局做准备)
    // 这里的 contentLayout_3 需要是你 ScrollArea 内部的那个 Layout
    QLayoutItem *child;
    while ((child = ui->contentLayout_3->takeAt(0)) != 0) {
        if(child->widget()) delete child->widget();
        delete child;
    }
    labelList.clear();
    editList.clear();

    // 6. 循环生成 Label 和 LineEdit
    for (int i = 0; i < lines.size(); ++i) {
        QString lineText = lines[i];

        // Label 设置
        QLabel *label = new QLabel(lineText);
        label->setFont(font); // 必须设置字体，否则计算的宽度和显示的不一致
        label->setTextFormat(Qt::RichText);
        label->setWordWrap(false); // 禁止 Label 自己换行，我们已经手动分好了

        // Edit 设置
        QLineEdit *edit = new QLineEdit;
        edit->setFont(font);
        edit->setMaxLength(lineText.length());

        // 添加到布局
        ui->contentLayout_3->addWidget(label);
        ui->contentLayout_3->addWidget(edit);

        // 保存指针
        labelList << label;
        editList << edit;

        // 7. 绑定业务逻辑 (FontService)
        auto fontService = new FontService(this);
        fontService->setTargetText(lineText);

        // 输入联动
        connect(edit, &QLineEdit::textChanged, this, [=](const QString &input){
            fontService->processInput(input);
            // 自动跳行
            if(input.length() == lineText.length() && i+1 < editList.size()){
                editList[i+1]->setFocus();
            }
        });

        // 结果回显
        connect(fontService, &FontService::matchResultReady, this, [=](const QVector<bool> &results){
            QString richText;
            // ... 你的富文本生成逻辑 (保持不变) ...
            // 注意：这里生成 richText 时，mid(j,1) 取出的字符要和 color 拼装
            // 建议把这里的逻辑封装成函数，代码太长了
            for(int j=0; j<lineText.length(); ++j){
                bool match = (j < results.size()) ? results[j] : false;
                QString color = match ? "#4CAF50" : "#F44336"; // 推荐使用 hex 颜色更柔和
                richText += QString("<span style='color:%1;'>%2</span>")
                                .arg(color, lineText.mid(j,1).toHtmlEscaped());
            }
            label->setText(richText);
        });
    }

    // 8. 【重要】在底部添加一个弹簧，把内容顶上去
    ui->contentLayout_3->addStretch();
}
