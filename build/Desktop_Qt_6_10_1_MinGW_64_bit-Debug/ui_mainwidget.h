/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <cardperformance.h>
#include <cardwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_6;
    QWidget *StatusWidget;
    QHBoxLayout *horizontalLayout_6;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *LogOutBtn;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QWidget *PerformanceWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    CardPerformance *typeSpeed;
    CardPerformance *Accuracy;
    CardPerformance *Competitions;
    CardPerformance *Rank;
    QWidget *MainFunturesWidget;
    QVBoxLayout *verticalLayout_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_7;
    QWidget *AllFuntures;
    QVBoxLayout *verticalLayout_4;
    QWidget *FunturesTitle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QWidget *FuntureWidget;
    QGridLayout *gridLayout;
    CardWidget *LeaderboardFeature;
    CardWidget *InfoManagerFeature;
    CardWidget *beiyong2;
    CardWidget *CompetitionFeature;
    CardWidget *PracticeFeature;
    CardWidget *beiyong3;
    CardWidget *beiyong1;
    CardWidget *SettingFeature;
    CardWidget *CompetitionManagementFeature;
    QWidget *TipsWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QLabel *label_3;

    void setupUi(QMainWindow *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName("MainWidget");
        MainWidget->resize(1092, 652);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWidget->sizePolicy().hasHeightForWidth());
        MainWidget->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWidget);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_6 = new QVBoxLayout(centralwidget);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(5, 5, 5, 5);
        StatusWidget = new QWidget(centralwidget);
        StatusWidget->setObjectName("StatusWidget");
        horizontalLayout_6 = new QHBoxLayout(StatusWidget);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        widget_5 = new QWidget(StatusWidget);
        widget_5->setObjectName("widget_5");
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_6 = new QLabel(widget_5);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("font: 900 22pt \"\346\275\256\345\255\227\347\244\276\345\261\240\351\276\231\345\210\200\347\256\200\347\271\201-\351\227\252\";\n"
"color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_5->addWidget(label_6);


        horizontalLayout_6->addWidget(widget_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        widget_4 = new QWidget(StatusWidget);
        widget_4->setObjectName("widget_4");
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_5 = new QLabel(widget_4);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);\n"
"font: 700 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_4->addWidget(label_5);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        LogOutBtn = new QPushButton(widget_4);
        LogOutBtn->setObjectName("LogOutBtn");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LogOutBtn->sizePolicy().hasHeightForWidth());
        LogOutBtn->setSizePolicy(sizePolicy1);
        LogOutBtn->setMinimumSize(QSize(100, 30));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::SystemShutdown));
        LogOutBtn->setIcon(icon);

        horizontalLayout_4->addWidget(LogOutBtn);


        horizontalLayout_6->addWidget(widget_4);


        verticalLayout_6->addWidget(StatusWidget);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName("widget_3");
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(2, 0, 2, 5);
        PerformanceWidget = new QWidget(widget_3);
        PerformanceWidget->setObjectName("PerformanceWidget");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(PerformanceWidget->sizePolicy().hasHeightForWidth());
        PerformanceWidget->setSizePolicy(sizePolicy2);
        PerformanceWidget->setMinimumSize(QSize(160, 527));
        verticalLayout_2 = new QVBoxLayout(PerformanceWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(PerformanceWidget);
        widget_2->setObjectName("widget_2");
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        horizontalLayout->addWidget(label);


        verticalLayout_2->addWidget(widget_2);

        widget = new QWidget(PerformanceWidget);
        widget->setObjectName("widget");
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, 10, -1, 40);
        typeSpeed = new CardPerformance(widget);
        typeSpeed->setObjectName("typeSpeed");

        verticalLayout->addWidget(typeSpeed);

        Accuracy = new CardPerformance(widget);
        Accuracy->setObjectName("Accuracy");

        verticalLayout->addWidget(Accuracy);

        Competitions = new CardPerformance(widget);
        Competitions->setObjectName("Competitions");

        verticalLayout->addWidget(Competitions);

        Rank = new CardPerformance(widget);
        Rank->setObjectName("Rank");

        verticalLayout->addWidget(Rank);


        verticalLayout_2->addWidget(widget);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 9);

        horizontalLayout_3->addWidget(PerformanceWidget);

        MainFunturesWidget = new QWidget(widget_3);
        MainFunturesWidget->setObjectName("MainFunturesWidget");
        verticalLayout_5 = new QVBoxLayout(MainFunturesWidget);
        verticalLayout_5->setSpacing(7);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(MainFunturesWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setMaximumSize(QSize(100000, 100000));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 843, 751));
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy3);
        verticalLayout_7 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_7->setObjectName("verticalLayout_7");
        AllFuntures = new QWidget(scrollAreaWidgetContents);
        AllFuntures->setObjectName("AllFuntures");
        verticalLayout_4 = new QVBoxLayout(AllFuntures);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, -1);
        FunturesTitle = new QWidget(AllFuntures);
        FunturesTitle->setObjectName("FunturesTitle");
        horizontalLayout_2 = new QHBoxLayout(FunturesTitle);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(FunturesTitle);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy4);
        label_2->setMinimumSize(QSize(0, 160));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/res/mainFeatures.jpg")));
        label_2->setScaledContents(true);

        horizontalLayout_2->addWidget(label_2);


        verticalLayout_4->addWidget(FunturesTitle);

        FuntureWidget = new QWidget(AllFuntures);
        FuntureWidget->setObjectName("FuntureWidget");
        FuntureWidget->setMinimumSize(QSize(0, 420));
        gridLayout = new QGridLayout(FuntureWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(30);
        gridLayout->setVerticalSpacing(10);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        LeaderboardFeature = new CardWidget(FuntureWidget);
        LeaderboardFeature->setObjectName("LeaderboardFeature");
        LeaderboardFeature->setFrameShape(QFrame::Shape::StyledPanel);
        LeaderboardFeature->setFrameShadow(QFrame::Shadow::Raised);

        gridLayout->addWidget(LeaderboardFeature, 0, 2, 1, 1);

        InfoManagerFeature = new CardWidget(FuntureWidget);
        InfoManagerFeature->setObjectName("InfoManagerFeature");
        InfoManagerFeature->setFrameShape(QFrame::Shape::StyledPanel);
        InfoManagerFeature->setFrameShadow(QFrame::Shadow::Raised);

        gridLayout->addWidget(InfoManagerFeature, 3, 1, 1, 1);

        beiyong2 = new CardWidget(FuntureWidget);
        beiyong2->setObjectName("beiyong2");
        beiyong2->setFrameShape(QFrame::Shape::StyledPanel);
        beiyong2->setFrameShadow(QFrame::Shadow::Raised);

        gridLayout->addWidget(beiyong2, 4, 1, 1, 1);

        CompetitionFeature = new CardWidget(FuntureWidget);
        CompetitionFeature->setObjectName("CompetitionFeature");
        CompetitionFeature->setFrameShape(QFrame::Shape::StyledPanel);
        CompetitionFeature->setFrameShadow(QFrame::Shadow::Raised);

        gridLayout->addWidget(CompetitionFeature, 0, 1, 1, 1);

        PracticeFeature = new CardWidget(FuntureWidget);
        PracticeFeature->setObjectName("PracticeFeature");
        PracticeFeature->setFrameShape(QFrame::Shape::StyledPanel);
        PracticeFeature->setFrameShadow(QFrame::Shadow::Raised);

        gridLayout->addWidget(PracticeFeature, 0, 0, 1, 1);

        beiyong3 = new CardWidget(FuntureWidget);
        beiyong3->setObjectName("beiyong3");
        beiyong3->setFrameShape(QFrame::Shape::StyledPanel);
        beiyong3->setFrameShadow(QFrame::Shadow::Raised);

        gridLayout->addWidget(beiyong3, 4, 2, 1, 1);

        beiyong1 = new CardWidget(FuntureWidget);
        beiyong1->setObjectName("beiyong1");
        beiyong1->setFrameShape(QFrame::Shape::StyledPanel);
        beiyong1->setFrameShadow(QFrame::Shadow::Raised);

        gridLayout->addWidget(beiyong1, 4, 0, 1, 1);

        SettingFeature = new CardWidget(FuntureWidget);
        SettingFeature->setObjectName("SettingFeature");
        SettingFeature->setFrameShape(QFrame::Shape::StyledPanel);
        SettingFeature->setFrameShadow(QFrame::Shadow::Raised);

        gridLayout->addWidget(SettingFeature, 3, 2, 1, 1);

        CompetitionManagementFeature = new CardWidget(FuntureWidget);
        CompetitionManagementFeature->setObjectName("CompetitionManagementFeature");
        CompetitionManagementFeature->setFrameShape(QFrame::Shape::StyledPanel);
        CompetitionManagementFeature->setFrameShadow(QFrame::Shadow::Raised);

        gridLayout->addWidget(CompetitionManagementFeature, 3, 0, 1, 1);


        verticalLayout_4->addWidget(FuntureWidget);

        TipsWidget = new QWidget(AllFuntures);
        TipsWidget->setObjectName("TipsWidget");
        TipsWidget->setStyleSheet(QString::fromUtf8("border-color: #74b9ea;\n"
"background-color: #c9e4f7;\n"
"border-radius:10px;"));
        verticalLayout_3 = new QVBoxLayout(TipsWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_4 = new QLabel(TipsWidget);
        label_4->setObjectName("label_4");

        verticalLayout_3->addWidget(label_4);

        label_3 = new QLabel(TipsWidget);
        label_3->setObjectName("label_3");

        verticalLayout_3->addWidget(label_3);


        verticalLayout_4->addWidget(TipsWidget);

        verticalLayout_4->setStretch(0, 3);
        verticalLayout_4->setStretch(1, 4);
        verticalLayout_4->setStretch(2, 3);

        verticalLayout_7->addWidget(AllFuntures);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_5->addWidget(scrollArea);


        horizontalLayout_3->addWidget(MainFunturesWidget);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 8);

        verticalLayout_6->addWidget(widget_3);

        verticalLayout_6->setStretch(0, 1);
        verticalLayout_6->setStretch(1, 9);
        MainWidget->setCentralWidget(centralwidget);

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QMainWindow *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "MainWindow", nullptr));
        label_6->setText(QCoreApplication::translate("MainWidget", "Fingertip-Light-Chase", nullptr));
        label_5->setText(QCoreApplication::translate("MainWidget", "Welcome USERNAME!!!", nullptr));
        LogOutBtn->setText(QCoreApplication::translate("MainWidget", "LogOut", nullptr));
        label->setText(QCoreApplication::translate("MainWidget", "Your Performance", nullptr));
        label_2->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWidget", "Tips:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWidget", "Practice daily for 15-20 minutes to improve your speed. \n"
"Focus on accuracy first, speed will follow naturally \n"
"Use proper finger placement on home row keys \n"
"Join competitions to challenge yourself and track progress", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
