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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
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

        horizontalLayout->addWidget(UserInfoLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        ClockLabel = new QLabel(TitleWidget);
        ClockLabel->setObjectName("ClockLabel");
        ClockLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(ClockLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(TitleWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        ArticleLabel = new QLabel(TitleWidget);
        ArticleLabel->setObjectName("ArticleLabel");

        horizontalLayout->addWidget(ArticleLabel);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(TitleWidget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        SetTime = new QLabel(TitleWidget);
        SetTime->setObjectName("SetTime");

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
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 717, 576));
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
    } // retranslateUi

};

namespace Ui {
    class PracticeWidget: public Ui_PracticeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRACTICEWIDGET_H
