#include "practicewidget.h"
#include "ui_practicewidget.h"

#include "clockservice.h"
#include "timeservice.h"
#include "fontservice.h"
#include "NoCopyPasteLineEdit.h"
#include "usermanager.h"
#include "articleservice.h"
#include "settlementdialog.h"
#include "mainwidget.h"
#include <QMessageBox>


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


PracticeWidget::PracticeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PracticeWidget)
    , m_currentArticleId(-1)
    , m_practiceDuration(0)
    , m_clockService(nullptr) // 【关键】初始化指针为空
    , m_isTimeUp(false) // 初始化标记为 false
    , m_totalSeconds(0)
    , m_remainingSeconds(0)
    , m_totalChars(0)
    , m_typedChars(0)
    , m_errorChars(0)
    , m_hasSubmitted(false)
    , m_isPaused(false)
{
    ui->setupUi(this);

    //连接，当时间管理类的时间更新启动的时候更新ui上的数据
    //显示当前的时间 系统北京时间
    auto timeService = new TimeService(this);

    m_competitionRecordsService = new CompetitionRecordsService(this);
    m_practiceRecordsService = new practiceRecordsService(this);

    connect(timeService,&TimeService::timeUpdated,this,[=](const QString &timeStr){
        ui->ClockLabel->setText(timeStr);
    });

    timeService->start();

    //初始化 ClockService (倒计时)
    m_clockService = new ClockService(this);

    //连接倒计时的显示信号 (负责格式化为 MM:SS)
    // 注意：这里只负责“显示”，不负责“启动”或“设置时间”
    connect(m_clockService, &ClockService::timeUpdated, this, [=](int totalSeconds){
        // 记录当前剩余时间，供统计使用
        m_remainingSeconds = totalSeconds;

        int minutes = totalSeconds / 60;
        int seconds = totalSeconds % 60;

        // 格式化为两位数
        QString timeString = QString("%1:%2")
                                 .arg(minutes, 2, 10, QChar('0'))
                                 .arg(seconds, 2, 10, QChar('0'));

        ui->CountdownTimer->setText(timeString);

        if (totalSeconds == 0) {
            // 确保只触发一次超时逻辑
            if (!m_isTimeUp) {
                m_isTimeUp = true;

                //自动暂停,防止变成负数
                if (m_clockService) {
                    m_clockService->pause();
                }

                // 倒计时结束，统一走练习结束逻辑（供后续数据库写入）
                handlePracticeFinished(true);
            }
        } else {
            m_isTimeUp = false;
        }

    });

    // 4. 连接暂停按钮
    //connect(ui->StopBtn, &QPushButton::clicked,this, &PracticeWidget::togglePause);
    connect(ui->StopBtn, &QPushButton::clicked, this, [=]() {

        if (m_mode == CompetitionMode)
        {
            QMessageBox::warning(this, "提示", "比赛模式禁止暂停！");
            return;
        }

        togglePause();
        });

    

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

bool PracticeWidget::isTimeUp() const
{
    return m_isTimeUp;
}

void PracticeWidget::onSetupReceived(int articleId, int practiceTime, Mode mode, int compId)
{

    m_mode = mode;
    m_competitionId = compId;

    qDebug() << "模式:" << (m_mode == PracticeMode ? "练习" : "比赛")
        << "compId:" << m_competitionId;

    m_currentArticleId = articleId;
    m_practiceDuration = practiceTime;

    // ⭐ UI差异（比赛模式）
    if (m_mode == CompetitionMode)
    {
        ui->mode->setText("比赛模式");
        ui->ExitBtn->hide();     // 禁止退出（可选）
        ui->StopBtn->hide();     // 禁止暂停（强烈建议）
    }

    qDebug() << "收到设置数据！ID:" << articleId << "时间:" << practiceTime;

    m_currentArticleId = articleId;
    m_practiceDuration = practiceTime;  // 这里存的是分钟

    //更改页面信息,显示的是文章名
    //通过Service获取数据
    ArticleService service;
    QString articleTitle = service.getArticleTitleById(m_currentArticleId);

    ui->ArticleLabel->setText(articleTitle);
    //填充时间信息
    ui->SetTime->setText(QString("%1 分钟").arg(m_practiceDuration));

    emit GetChooseDataSignals();

    // 3. 【核心修改】配置并启动倒计时
    if (m_clockService) {
        // A. 单位换算：分钟 -> 秒
        int totalSeconds = m_practiceDuration * 60;
        m_totalSeconds = totalSeconds;
        m_remainingSeconds = totalSeconds;

        // B. 设置初始时间
        m_clockService->setInitialSeconds(totalSeconds);

        // C. 重置样式 (防止上次结束时是红色的)
        //ui->CountdownTimer->setStyleSheet("");
        ui->CountdownTimer->setText(QString("%1:%2")
                                        .arg(m_practiceDuration, 2, 10, QChar('0'))
                                        .arg(0, 2, 10, QChar('0')));

        // D. 启动倒计时
        m_clockService->start();

        qDebug() << "倒计时已启动，总秒数:" << totalSeconds;
    }

    // 发射信号通知其他组件（如果需要）
    emit GetChooseDataSignals();

    // 如果界面还没初始化，强制刷新一次以加载文章
    if (!isInitialized && isVisible()) {
        loadArticleAndGenerateWidgets();
        UpdateUIShow();
        isInitialized = true;
    }


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

        QStringList oldInputs = collectUserInputs();

        loadArticleAndGenerateWidgets(oldInputs);
    }
}


void PracticeWidget::loadArticleAndGenerateWidgets(const QStringList &oldInputs)
{
    // 【修改点】根据 ID 获取真实文本，而不是写死
    if (m_currentArticleId > 0) {
        ArticleService service;
        QString articleContent = service.getArticleById(m_currentArticleId); // 获取文章内容
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

    // 记录分行文本以及目标总字数
    splitLines.clear();
    m_totalChars = 0;

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

        splitLines.append(lineText);
        m_totalChars += lineText.length();

        // Label 设置
        QLabel *label = new QLabel(lineText);
        label->setFont(practiceFont);
        label->setTextFormat(Qt::RichText);
        label->setWordWrap(false);

        // Edit 设置,不使用原生的lineedit类，使用自创的类来禁用复制粘贴等快捷键，同时取消右键菜单
        NoCopyPasteLineEdit *edit = new NoCopyPasteLineEdit;

        if (idx < oldInputs.size()) {
            edit->setText(oldInputs[idx]);
        }


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

                    // 每次输入变化后实时更新统计指标
                    updateTypingStats();
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

    // 初始化统计相关 UI
    ui->PracticeAllCharacters->setText(QString::number(m_totalChars) + " 字");
    m_typedChars = 0;
    m_errorChars = 0;
    ui->ErrorCharacters->setText(QStringLiteral("0 字"));
    ui->SpeedWPM->setText(QStringLiteral("0 WPM"));
    ui->PracticeAccuracy->setText(QStringLiteral("100%"));
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

void PracticeWidget::updateTypingStats()
{
    int typed = 0;
    int correct = 0;

    const int lineCount = qMin(editList.size(), splitLines.size());

    for (int i = 0; i < lineCount; ++i) {
        const QString input = editList[i]->text();
        const QString target = splitLines[i];

        typed += input.length();

        const int compareLen = qMin(input.length(), target.length());
        for (int j = 0; j < compareLen; ++j) {
            if (input.at(j) == target.at(j)) {
                ++correct;
            }
        }
    }

    int errors = typed - correct;
    if (errors < 0) {
        errors = 0;
    }

    m_typedChars = typed;
    m_errorChars = errors;

    // 目标总字数
    ui->PracticeAllCharacters->setText(QString::number(m_typedChars) + " 字");

    // 错误字数
    ui->ErrorCharacters->setText(QString::number(m_errorChars) + " 字");

    // 准确率：以已输入字数为基准
    double accuracy = 100.0;
    if (m_typedChars > 0) {
        accuracy = static_cast<double>(correct) * 100.0 / static_cast<double>(m_typedChars);
    }
    ui->PracticeAccuracy->setText(QString::number(accuracy, 'f', 1) + "%");

    // 速度：以正确字数为基准计算 WPM
    int usedSeconds = 0;
    if (m_totalSeconds > 0) {
        usedSeconds = m_totalSeconds - m_remainingSeconds;
        if (usedSeconds < 0) {
            usedSeconds = 0;
        }
    }

    double wpm = 0.0;
    if (usedSeconds > 0) {
        wpm = static_cast<double>(correct) * 60.0 / static_cast<double>(usedSeconds);
    }
    ui->SpeedWPM->setText(QString::number(wpm, 'f', 1) + " WPM");
}

void PracticeWidget::handlePracticeFinished(bool byTimeout)
{
    // 防止重复提交（例如先时间到自动提交，再手动点提交）
    if (m_hasSubmitted) {
        return;
    }
    m_hasSubmitted = true;

    // 最终再计算一次统计，确保数据最新
    updateTypingStats();

    // 计算本次实际用时
    int usedSeconds = 0;
    if (m_totalSeconds > 0) {
        usedSeconds = m_totalSeconds - m_remainingSeconds;
        if (usedSeconds < 0) {
            usedSeconds = 0;
        }
    }

    // 利用 m_typedChars 与 m_errorChars 反推正确字数与准确率
    int correctChars = m_typedChars - m_errorChars;
    if (correctChars < 0) {
        correctChars = 0;
    }

    double accuracy = 0.0;
    if (m_typedChars > 0) {
        accuracy = static_cast<double>(correctChars) * 100.0 / static_cast<double>(m_typedChars);
    }

    double wpm = 0.0;
    if (usedSeconds > 0) {
        wpm = static_cast<double>(correctChars) * 60.0 / static_cast<double>(usedSeconds);
    }

    // 新增：比赛模式超时未打完字的提示
    if (byTimeout && m_mode == CompetitionMode && m_typedChars != m_totalChars) {
        QMessageBox::critical(this, "比赛结束", "时间已到！你未完成全部字符输入，本次比赛无效！");
        // 关闭页面或重置
        this->close();
        this->deleteLater();
        return;
    }

    // 对外发出信号，供后续数据库写入使用
    emit PracticeFinished(
        m_currentArticleId,
        usedSeconds,
        m_totalChars,
        m_typedChars,
        m_errorChars,
        accuracy,
        wpm,
        byTimeout
        );
}

QStringList  PracticeWidget::collectUserInputs()
{
    QStringList inputs;

    for (auto edit : editList) {
        inputs << edit->text();
    }

    return inputs;
}

void PracticeWidget::togglePause()
{
    if (!m_clockService) return;

    if (!m_isPaused) {

        // m_clockService->pause();

        // ui->StopBtn->setText("继续");
        //调用模态窗口，阻塞主线程上的操作，包括倒计时吗，实现暂停功能
        // 暂停倒计时
        m_clockService->pause();
        m_isPaused = true;

        ui->StopBtn->setText("继续");

        // 创建模态窗口
        QDialog dialog(this);
        dialog.setWindowTitle("已暂停");

        //设置弹窗的大小
        dialog.setFixedSize(350,170);


        QVBoxLayout *layout = new QVBoxLayout(&dialog);


        QLabel *label = new QLabel("练习已暂停");
        label->setAlignment(Qt::AlignCenter);

        // 天空蓝文字
        label->setStyleSheet("color: skyblue; font-size: 32px;");

        QPushButton *resumeBtn = new QPushButton("继续");
        resumeBtn->setProperty("type","primary");



        layout->addWidget(label);
        layout->addWidget(resumeBtn);

        // 点击继续关闭窗口
        connect(resumeBtn, &QPushButton::clicked, &dialog, &QDialog::accept);

        // 模态显示（阻塞这里）
        dialog.exec();

        // 用户点击继续后执行
        m_clockService->start();
        m_isPaused = false;

        ui->StopBtn->setText("暂停");


        // m_isPaused = true;

    }
}

void PracticeWidget::on_ExitBtn_clicked()
{
    //如果是比赛模式，不让退出
    if (m_mode == CompetitionMode)
    {
        QMessageBox::warning(this, "提示", "比赛中不能退出！");
        return;
    }


    //返回到主界面
    this->close();

    this->deleteLater();

}

void PracticeWidget::on_SubmitBtn_clicked()
{
    // 用户主动点击提交时，优先暂停计时
    if (m_clockService) {
        m_clockService->pause();

        //确保所有数据是新的
        updateTypingStats();

        //获取用户在打字过程中的所有数据，打印出来有速度，错误，输入的字数，和正确率
        //并打印数据
        // 计算实际用时
        int usedSeconds = 0;
        if (m_totalSeconds > 0) {
            usedSeconds = m_totalSeconds - m_remainingSeconds;
            if (usedSeconds < 0) {
                usedSeconds = 0;
            }
        }

        // 计算正确字数
        int correctChars = m_typedChars - m_errorChars;
        if (correctChars < 0) correctChars = 0;

        // 计算准确率
        double accuracy = 0.0;
        if (m_typedChars > 0) {
            accuracy = static_cast<double>(correctChars) * 100.0 / static_cast<double>(m_typedChars);
        }

        // 计算速度（WPM）
        double wpm = 0.0;
        if (usedSeconds > 0) {
            wpm = static_cast<double>(correctChars) * 60.0 / static_cast<double>(usedSeconds);
        }

        //综合评分计算 
        double finalScore = 0.0;

        // 特殊情况处理：如果还没开始打字，得分为 0
        if (m_typedChars > 0) {
            finalScore = wpm * (accuracy / 100.0);
        }

        // 打印数据
        qDebug() << "用户输入的字数：" << m_typedChars;
        qDebug() << "用户错误的字数：" << m_errorChars;
        qDebug() << "用户输入的速度：" << wpm << " WPM";
        qDebug() << "用户输入的准确率：" << accuracy << "%";
        qDebug() << "总字数：" << m_totalChars;
        qDebug() << "正确字数：" << correctChars;
        qDebug() << "用时（秒）：" << usedSeconds;
        qDebug() << "综合评分计算结果:" << finalScore;
        
        //点击提交，中断打字内容，保存数据，结束练习，弹窗出练习信息，并显示正确率，速度，错误率，输入字数，正确字数等
        //将练习数据保存到数据库
        //1获取当前用户登录的id
        //通过 instance() 获取那个唯一的实例
        UserManager& userMgr = UserManager::instance();
        int userID = userMgr.getCurrentUserID();

        if (m_mode == CompetitionMode)
        {
            //只有输入完全部字符才能提交
            if (m_typedChars == m_totalChars) {
                qDebug() << "比赛模式,保存比赛成绩";
                //比赛模式,保存比赛成绩
                bool success = m_competitionRecordsService->insertCompetitionRecords(
                    m_competitionId,
                    userID,
                    wpm,
                    accuracy,
                    usedSeconds,
                    correctChars,
                    m_errorChars,
                    finalScore
                );

                if (success)
                    qDebug() << "比赛成绩提交成功";
                else
                    qDebug() << "比赛成绩提交失败";
            }
            else
            {
                QMessageBox::warning(this, "提示", "比赛中，请确保输入完全部字符！");
                // 重新启动倒计时
                if (m_clockService && !m_isTimeUp) {
                    m_clockService->start(); 
                }
                return;
            }
        }
        else
        {
            //练习逻辑
            bool isSuccess = m_practiceRecordsService->insertPracticeRecordsService(
                userID,
                m_totalChars,
                m_typedChars,
                correctChars,
                m_errorChars,
                wpm,
                usedSeconds,
                accuracy,
                m_currentArticleId
            );

            if (isSuccess)
                qDebug() << "保存练习记录成功";
            else
                qDebug() << "保存练习记录失败";
        }

        //这里要新建ui窗口，后面可用复用
        settlementDialog* settleDialog = new settlementDialog(this);
        //接收结算弹窗发出的信号，关闭此界面
        connect(settleDialog, &settlementDialog::requestClosePractice, this, [this]() {
            this->close();
            });

        settleDialog->showData(m_totalChars, m_typedChars, correctChars, m_errorChars, accuracy, wpm, usedSeconds);
        settleDialog->exec();
        delete settleDialog;

        //更好的写法没有new 没有delete 不会内存泄漏不会野指针
        /*settlementDialog dialog(this);

        connect(&dialog, &settlementDialog::requestClosePractice,
            this, &PracticeWidget::close);

        dialog.showData(m_totalChars, m_typedChars, correctChars,
            m_errorChars, accuracy, wpm, usedSeconds);

        dialog.exec();*/
    }

    handlePracticeFinished(false);
}