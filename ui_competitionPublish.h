/********************************************************************************
** Form generated from reading UI file 'CompetitionPublish.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPETITIONPUBLISH_H
#define UI_COMPETITIONPUBLISH_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CompetitionPublishClass
{
public:
    QWidget *competitionPubilshWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *competitionPubilshTitleWidget;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *CompetitionNameEdit;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *ChooseArticleCombo;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *LimitTimeEdit;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDateTimeEdit *StartTime;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDateTimeEdit *EndTime;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *publishBtn;
    QPushButton *CancelBtn;

    void setupUi(QMainWindow *CompetitionPublishClass)
    {
        if (CompetitionPublishClass->objectName().isEmpty())
            CompetitionPublishClass->setObjectName("CompetitionPublishClass");
        CompetitionPublishClass->setWindowModality(Qt::WindowModality::ApplicationModal);
        CompetitionPublishClass->resize(326, 368);
        competitionPubilshWidget = new QWidget(CompetitionPublishClass);
        competitionPubilshWidget->setObjectName("competitionPubilshWidget");
        verticalLayout_2 = new QVBoxLayout(competitionPubilshWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(-1, -1, -1, 0);
        competitionPubilshTitleWidget = new QWidget(competitionPubilshWidget);
        competitionPubilshTitleWidget->setObjectName("competitionPubilshTitleWidget");
        horizontalLayout_7 = new QHBoxLayout(competitionPubilshTitleWidget);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_6 = new QLabel(competitionPubilshTitleWidget);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("font: 700 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_7->addWidget(label_6);

        horizontalSpacer = new QSpacerItem(233, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(competitionPubilshTitleWidget);

        widget_7 = new QWidget(competitionPubilshWidget);
        widget_7->setObjectName("widget_7");
        verticalLayout = new QVBoxLayout(widget_7);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        widget = new QWidget(widget_7);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));

        horizontalLayout->addWidget(label);

        CompetitionNameEdit = new QLineEdit(widget);
        CompetitionNameEdit->setObjectName("CompetitionNameEdit");
        CompetitionNameEdit->setClearButtonEnabled(true);

        horizontalLayout->addWidget(CompetitionNameEdit);


        verticalLayout->addWidget(widget);

        widget_4 = new QWidget(widget_7);
        widget_4->setObjectName("widget_4");
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(widget_4);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));

        horizontalLayout_4->addWidget(label_4);

        ChooseArticleCombo = new QComboBox(widget_4);
        ChooseArticleCombo->setObjectName("ChooseArticleCombo");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChooseArticleCombo->sizePolicy().hasHeightForWidth());
        ChooseArticleCombo->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(ChooseArticleCombo);


        verticalLayout->addWidget(widget_4);

        widget_5 = new QWidget(widget_7);
        widget_5->setObjectName("widget_5");
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_5 = new QLabel(widget_5);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));

        horizontalLayout_5->addWidget(label_5);

        LimitTimeEdit = new QLineEdit(widget_5);
        LimitTimeEdit->setObjectName("LimitTimeEdit");
        LimitTimeEdit->setClearButtonEnabled(true);

        horizontalLayout_5->addWidget(LimitTimeEdit);


        verticalLayout->addWidget(widget_5);

        widget_2 = new QWidget(widget_7);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));

        horizontalLayout_2->addWidget(label_2);

        StartTime = new QDateTimeEdit(widget_2);
        StartTime->setObjectName("StartTime");
        sizePolicy.setHeightForWidth(StartTime->sizePolicy().hasHeightForWidth());
        StartTime->setSizePolicy(sizePolicy);
        StartTime->setWrapping(false);
        StartTime->setDate(QDate(2026, 7, 9));
        StartTime->setCalendarPopup(true);

        horizontalLayout_2->addWidget(StartTime);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(widget_7);
        widget_3->setObjectName("widget_3");
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(widget_3);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));

        horizontalLayout_3->addWidget(label_3);

        EndTime = new QDateTimeEdit(widget_3);
        EndTime->setObjectName("EndTime");
        sizePolicy.setHeightForWidth(EndTime->sizePolicy().hasHeightForWidth());
        EndTime->setSizePolicy(sizePolicy);
        EndTime->setDate(QDate(2026, 12, 9));
        EndTime->setCalendarPopup(true);

        horizontalLayout_3->addWidget(EndTime);


        verticalLayout->addWidget(widget_3);

        widget_6 = new QWidget(widget_7);
        widget_6->setObjectName("widget_6");
        horizontalLayout_6 = new QHBoxLayout(widget_6);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        publishBtn = new QPushButton(widget_6);
        publishBtn->setObjectName("publishBtn");

        horizontalLayout_6->addWidget(publishBtn);

        CancelBtn = new QPushButton(widget_6);
        CancelBtn->setObjectName("CancelBtn");

        horizontalLayout_6->addWidget(CancelBtn);


        verticalLayout->addWidget(widget_6);


        verticalLayout_2->addWidget(widget_7);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 9);
        CompetitionPublishClass->setCentralWidget(competitionPubilshWidget);

        retranslateUi(CompetitionPublishClass);

        QMetaObject::connectSlotsByName(CompetitionPublishClass);
    } // setupUi

    void retranslateUi(QMainWindow *CompetitionPublishClass)
    {
        CompetitionPublishClass->setWindowTitle(QCoreApplication::translate("CompetitionPublishClass", "CompetitionPublish", nullptr));
        label_6->setText(QCoreApplication::translate("CompetitionPublishClass", "\350\265\233\344\272\213\345\217\221\345\270\203", nullptr));
        label->setText(QCoreApplication::translate("CompetitionPublishClass", "\350\265\233\344\272\213\345\220\215\347\247\260\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("CompetitionPublishClass", "\351\200\211\346\213\251\346\226\207\347\253\240\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("CompetitionPublishClass", "\346\257\224\350\265\233\351\231\220\346\227\266\357\274\232", nullptr));
        LimitTimeEdit->setInputMask(QString());
        LimitTimeEdit->setText(QString());
        LimitTimeEdit->setPlaceholderText(QCoreApplication::translate("CompetitionPublishClass", "\345\210\206\351\222\237/min", nullptr));
        label_2->setText(QCoreApplication::translate("CompetitionPublishClass", "\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("CompetitionPublishClass", "\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", nullptr));
        publishBtn->setText(QCoreApplication::translate("CompetitionPublishClass", "\345\217\221\345\270\203", nullptr));
        CancelBtn->setText(QCoreApplication::translate("CompetitionPublishClass", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CompetitionPublishClass: public Ui_CompetitionPublishClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPETITIONPUBLISH_H
