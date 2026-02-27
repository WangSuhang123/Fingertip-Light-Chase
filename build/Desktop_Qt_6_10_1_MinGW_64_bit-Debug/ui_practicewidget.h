/********************************************************************************
** Form generated from reading UI file 'practicewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRACTICEWIDGET_H
#define UI_PRACTICEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PracticeWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *PracticeRealWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *TitleWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *UserInfoLabel;
    QSpacerItem *horizontalSpacer_3;
    QLabel *ClockLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLabel *ArticleLabel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QLabel *SetTime;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QWidget *TypingWidget;
    QVBoxLayout *verticalLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_8;
    QWidget *contentWidget_3;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *contentLayout_3;
    QWidget *StateWidget;
    QVBoxLayout *verticalLayout_6;
    QWidget *TimeWidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLabel *CountdownTimer;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QWidget *SpeedWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *SpeedIcon;
    QLabel *label_5;
    QLabel *SpeedWPM;
    QWidget *ErrorWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *ErrorIcon;
    QLabel *label_8;
    QLabel *ErrorCharacters;
    QWidget *AllCharactersWidget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_11;
    QLabel *label_6;
    QLabel *PracticeAllCharacters;
    QWidget *AccuracyWidget;
    QHBoxLayout *horizontalLayout_6;
    QLabel *AccuracyIcon;
    QLabel *label_7;
    QLabel *PracticeAccuracy;
    QWidget *PracticeBtnWidget;
    QGridLayout *gridLayout;
    QPushButton *StopBtn;
    QPushButton *SubmitBtn;
    QPushButton *FeedbackBtn;
    QPushButton *ExitBtn;

    void setupUi(QWidget *PracticeWidget)
    {
        if (PracticeWidget->objectName().isEmpty())
            PracticeWidget->setObjectName("PracticeWidget");
        PracticeWidget->resize(1080, 700);
        verticalLayout = new QVBoxLayout(PracticeWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, -1);
        PracticeRealWidget = new QWidget(PracticeWidget);
        PracticeRealWidget->setObjectName("PracticeRealWidget");
        verticalLayout_2 = new QVBoxLayout(PracticeRealWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        TitleWidget = new QWidget(PracticeRealWidget);
        TitleWidget->setObjectName("TitleWidget");
        horizontalLayout = new QHBoxLayout(TitleWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        UserInfoLabel = new QLabel(TitleWidget);
        UserInfoLabel->setObjectName("UserInfoLabel");
        UserInfoLabel->setStyleSheet(QString::fromUtf8("font-family: \"Microsoft YaHei\";\n"
"font-weight: bold;\n"
"font-size: 25px;\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(UserInfoLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        ClockLabel = new QLabel(TitleWidget);
        ClockLabel->setObjectName("ClockLabel");
        ClockLabel->setStyleSheet(QString::fromUtf8("font-family: \"Microsoft YaHei\";\n"
"font-weight: bold;\n"
"font-size: 25px;\n"
"color: rgb(255, 255, 255);"));
        ClockLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(ClockLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(TitleWidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font-family: \"Microsoft YaHei\";\n"
"font-weight: bold;\n"
"font-size: 25px;\n"
""));

        horizontalLayout->addWidget(label);

        ArticleLabel = new QLabel(TitleWidget);
        ArticleLabel->setObjectName("ArticleLabel");
        ArticleLabel->setStyleSheet(QString::fromUtf8("font-family: \"Microsoft YaHei\";\n"
"font-weight: bold;\n"
"font-size: 25px;\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(ArticleLabel);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(TitleWidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font-family: \"Microsoft YaHei\";\n"
"font-weight: bold;\n"
"font-size: 25px;\n"
""));

        horizontalLayout->addWidget(label_2);

        SetTime = new QLabel(TitleWidget);
        SetTime->setObjectName("SetTime");
        SetTime->setStyleSheet(QString::fromUtf8("font-family: \"Microsoft YaHei\";\n"
"font-weight: bold;\n"
"font-size: 25px;\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(SetTime);


        verticalLayout_2->addWidget(TitleWidget);

        widget_2 = new QWidget(PracticeRealWidget);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(7, 7, 7, 7);
        TypingWidget = new QWidget(widget_2);
        TypingWidget->setObjectName("TypingWidget");
        verticalLayout_3 = new QVBoxLayout(TypingWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        scrollArea = new QScrollArea(TypingWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 697, 576));
        verticalLayout_8 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_8->setObjectName("verticalLayout_8");
        contentWidget_3 = new QWidget(scrollAreaWidgetContents_3);
        contentWidget_3->setObjectName("contentWidget_3");
        verticalLayout_9 = new QVBoxLayout(contentWidget_3);
        verticalLayout_9->setObjectName("verticalLayout_9");
        contentLayout_3 = new QVBoxLayout();
        contentLayout_3->setObjectName("contentLayout_3");

        verticalLayout_9->addLayout(contentLayout_3);


        verticalLayout_8->addWidget(contentWidget_3);

        scrollArea->setWidget(scrollAreaWidgetContents_3);

        verticalLayout_3->addWidget(scrollArea);


        horizontalLayout_2->addWidget(TypingWidget);

        StateWidget = new QWidget(widget_2);
        StateWidget->setObjectName("StateWidget");
        verticalLayout_6 = new QVBoxLayout(StateWidget);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        TimeWidget = new QWidget(StateWidget);
        TimeWidget->setObjectName("TimeWidget");
        verticalLayout_4 = new QVBoxLayout(TimeWidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_3 = new QLabel(TimeWidget);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("font-family: \"Microsoft YaHei\";\n"
"font-weight: bold;\n"
"font-size: 30px;\n"
"letter-spacing: 10px;"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        verticalLayout_4->addWidget(label_3);

        CountdownTimer = new QLabel(TimeWidget);
        CountdownTimer->setObjectName("CountdownTimer");
        CountdownTimer->setStyleSheet(QString::fromUtf8("font-family: \"Microsoft YaHei\";\n"
"font-weight: bold;\n"
"font-size: 45px;\n"
"color: rgb(255, 0, 0);"));
        CountdownTimer->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(CountdownTimer);


        verticalLayout_6->addWidget(TimeWidget);

        widget = new QWidget(StateWidget);
        widget->setObjectName("widget");
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(25, -1, 50, -1);
        SpeedWidget = new QWidget(widget);
        SpeedWidget->setObjectName("SpeedWidget");
        horizontalLayout_3 = new QHBoxLayout(SpeedWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        SpeedIcon = new QLabel(SpeedWidget);
        SpeedIcon->setObjectName("SpeedIcon");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SpeedIcon->sizePolicy().hasHeightForWidth());
        SpeedIcon->setSizePolicy(sizePolicy);
        SpeedIcon->setMinimumSize(QSize(50, 50));
        SpeedIcon->setMaximumSize(QSize(50, 50));
        SpeedIcon->setPixmap(QPixmap(QString::fromUtf8(":/res/icon/yibiao.png")));
        SpeedIcon->setScaledContents(true);

        horizontalLayout_3->addWidget(SpeedIcon);

        label_5 = new QLabel(SpeedWidget);
        label_5->setObjectName("label_5");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setStyleSheet(QString::fromUtf8("font-family: \"Microsoft YaHei\";\n"
"font-weight: bold;\n"
"font-size: 20px;\n"
""));
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(label_5);

        SpeedWPM = new QLabel(SpeedWidget);
        SpeedWPM->setObjectName("SpeedWPM");
        SpeedWPM->setStyleSheet(QString::fromUtf8("font-family: \"Microsoft YaHei\";\n"
"font-weight: bold;\n"
"font-size: 25px;\n"
""));

        horizontalLayout_3->addWidget(SpeedWPM);


        verticalLayout_5->addWidget(SpeedWidget);

        ErrorWidget = new QWidget(widget);
        ErrorWidget->setObjectName("ErrorWidget");
        horizontalLayout_4 = new QHBoxLayout(ErrorWidget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        ErrorIcon = new QLabel(ErrorWidget);
        ErrorIcon->setObjectName("ErrorIcon");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(50);
        sizePolicy2.setVerticalStretch(50);
        sizePolicy2.setHeightForWidth(ErrorIcon->sizePolicy().hasHeightForWidth());
        ErrorIcon->setSizePolicy(sizePolicy2);
        ErrorIcon->setMinimumSize(QSize(50, 50));
        ErrorIcon->setMaximumSize(QSize(50, 50));
        ErrorIcon->setPixmap(QPixmap(QString::fromUtf8(":/res/icon/tongzhi.png")));
        ErrorIcon->setScaledContents(true);

        horizontalLayout_4->addWidget(ErrorIcon);

        label_8 = new QLabel(ErrorWidget);
        label_8->setObjectName("label_8");
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setStyleSheet(QString::fromUtf8("font-family: \"Microsoft YaHei\";\n"
"font-weight: bold;\n"
"font-size: 20px;\n"
""));
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_4->addWidget(label_8);

        ErrorCharacters = new QLabel(ErrorWidget);
        ErrorCharacters->setObjectName("ErrorCharacters");
        ErrorCharacters->setStyleSheet(QString::fromUtf8("font-family: \"Microsoft YaHei\";\n"
"font-weight: bold;\n"
"font-size: 25px;\n"
""));

        horizontalLayout_4->addWidget(ErrorCharacters);


        verticalLayout_5->addWidget(ErrorWidget);

        AllCharactersWidget = new QWidget(widget);
        AllCharactersWidget->setObjectName("AllCharactersWidget");
        horizontalLayout_5 = new QHBoxLayout(AllCharactersWidget);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_11 = new QLabel(AllCharactersWidget);
        label_11->setObjectName("label_11");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(50);
        sizePolicy3.setVerticalStretch(50);
        sizePolicy3.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy3);
        label_11->setMinimumSize(QSize(50, 50));
        label_11->setMaximumSize(QSize(50, 50));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/res/icon/tongji.png")));
        label_11->setScaledContents(true);

        horizontalLayout_5->addWidget(label_11);

        label_6 = new QLabel(AllCharactersWidget);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("font-family: \"Microsoft YaHei\";\n"
"font-weight: bold;\n"
"font-size: 20px;\n"
""));
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_5->addWidget(label_6);

        PracticeAllCharacters = new QLabel(AllCharactersWidget);
        PracticeAllCharacters->setObjectName("PracticeAllCharacters");
        PracticeAllCharacters->setStyleSheet(QString::fromUtf8("font-family: \"Microsoft YaHei\";\n"
"font-weight: bold;\n"
"font-size: 25px;\n"
""));

        horizontalLayout_5->addWidget(PracticeAllCharacters);


        verticalLayout_5->addWidget(AllCharactersWidget);

        AccuracyWidget = new QWidget(widget);
        AccuracyWidget->setObjectName("AccuracyWidget");
        horizontalLayout_6 = new QHBoxLayout(AccuracyWidget);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        AccuracyIcon = new QLabel(AccuracyWidget);
        AccuracyIcon->setObjectName("AccuracyIcon");
        AccuracyIcon->setMinimumSize(QSize(50, 50));
        AccuracyIcon->setMaximumSize(QSize(50, 50));
        AccuracyIcon->setPixmap(QPixmap(QString::fromUtf8(":/res/icon/app.png")));
        AccuracyIcon->setScaledContents(true);

        horizontalLayout_6->addWidget(AccuracyIcon);

        label_7 = new QLabel(AccuracyWidget);
        label_7->setObjectName("label_7");
        label_7->setStyleSheet(QString::fromUtf8("font-family: \"Microsoft YaHei\";\n"
"font-weight: bold;\n"
"font-size: 20px;\n"
""));
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_6->addWidget(label_7);

        PracticeAccuracy = new QLabel(AccuracyWidget);
        PracticeAccuracy->setObjectName("PracticeAccuracy");
        PracticeAccuracy->setStyleSheet(QString::fromUtf8("font-family: \"Microsoft YaHei\";\n"
"font-weight: bold;\n"
"font-size: 25px;\n"
""));

        horizontalLayout_6->addWidget(PracticeAccuracy);


        verticalLayout_5->addWidget(AccuracyWidget);


        verticalLayout_6->addWidget(widget);

        PracticeBtnWidget = new QWidget(StateWidget);
        PracticeBtnWidget->setObjectName("PracticeBtnWidget");
        gridLayout = new QGridLayout(PracticeBtnWidget);
        gridLayout->setObjectName("gridLayout");
        StopBtn = new QPushButton(PracticeBtnWidget);
        StopBtn->setObjectName("StopBtn");

        gridLayout->addWidget(StopBtn, 0, 0, 1, 1);

        SubmitBtn = new QPushButton(PracticeBtnWidget);
        SubmitBtn->setObjectName("SubmitBtn");

        gridLayout->addWidget(SubmitBtn, 0, 1, 1, 1);

        FeedbackBtn = new QPushButton(PracticeBtnWidget);
        FeedbackBtn->setObjectName("FeedbackBtn");

        gridLayout->addWidget(FeedbackBtn, 1, 0, 1, 1);

        ExitBtn = new QPushButton(PracticeBtnWidget);
        ExitBtn->setObjectName("ExitBtn");

        gridLayout->addWidget(ExitBtn, 1, 1, 1, 1);


        verticalLayout_6->addWidget(PracticeBtnWidget);


        horizontalLayout_2->addWidget(StateWidget);

        horizontalLayout_2->setStretch(0, 7);
        horizontalLayout_2->setStretch(1, 3);

        verticalLayout_2->addWidget(widget_2);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 9);

        verticalLayout->addWidget(PracticeRealWidget);


        retranslateUi(PracticeWidget);

        QMetaObject::connectSlotsByName(PracticeWidget);
    } // setupUi

    void retranslateUi(QWidget *PracticeWidget)
    {
        PracticeWidget->setWindowTitle(QCoreApplication::translate("PracticeWidget", "Form", nullptr));
        UserInfoLabel->setText(QCoreApplication::translate("PracticeWidget", "\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        ClockLabel->setText(QCoreApplication::translate("PracticeWidget", "2025-12-12 12:12:12", nullptr));
        label->setText(QCoreApplication::translate("PracticeWidget", "\346\226\207\347\253\240\345\220\215\347\247\260\357\274\232", nullptr));
        ArticleLabel->setText(QCoreApplication::translate("PracticeWidget", "\346\226\207\347\253\240\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("PracticeWidget", "\350\256\276\345\256\232\346\227\266\351\227\264\357\274\232", nullptr));
        SetTime->setText(QCoreApplication::translate("PracticeWidget", "\346\227\266\351\227\264", nullptr));
        label_3->setText(QCoreApplication::translate("PracticeWidget", "\345\200\222\350\256\241\346\227\266", nullptr));
        CountdownTimer->setText(QCoreApplication::translate("PracticeWidget", "\345\200\222\350\256\241\346\227\266\351\227\264", nullptr));
        SpeedIcon->setText(QString());
        label_5->setText(QCoreApplication::translate("PracticeWidget", "\351\200\237   \345\272\246\357\274\232", nullptr));
        SpeedWPM->setText(QCoreApplication::translate("PracticeWidget", "99WPM", nullptr));
        ErrorIcon->setText(QString());
        label_8->setText(QCoreApplication::translate("PracticeWidget", "\351\224\231   \350\257\257\357\274\232", nullptr));
        ErrorCharacters->setText(QCoreApplication::translate("PracticeWidget", "0  \345\255\227", nullptr));
        label_11->setText(QString());
        label_6->setText(QCoreApplication::translate("PracticeWidget", "\346\200\273\345\255\227\346\225\260\357\274\232", nullptr));
        PracticeAllCharacters->setText(QCoreApplication::translate("PracticeWidget", "66 \345\255\227", nullptr));
        AccuracyIcon->setText(QString());
        label_7->setText(QCoreApplication::translate("PracticeWidget", "\346\255\243\347\241\256\347\216\207\357\274\232", nullptr));
        PracticeAccuracy->setText(QCoreApplication::translate("PracticeWidget", "100%", nullptr));
        StopBtn->setText(QCoreApplication::translate("PracticeWidget", "\346\232\202\345\201\234", nullptr));
        SubmitBtn->setText(QCoreApplication::translate("PracticeWidget", "\346\217\220\344\272\244", nullptr));
        FeedbackBtn->setText(QCoreApplication::translate("PracticeWidget", "\345\217\215\351\246\210", nullptr));
        ExitBtn->setText(QCoreApplication::translate("PracticeWidget", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PracticeWidget: public Ui_PracticeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRACTICEWIDGET_H
