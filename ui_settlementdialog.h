/********************************************************************************
** Form generated from reading UI file 'settlementdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTLEMENTDIALOG_H
#define UI_SETTLEMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settlementDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *settleWidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_10;
    QVBoxLayout *verticalLayout;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QWidget *widget_4;
    QGridLayout *gridLayout;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLabel *settleErrChar;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *settleInputchar;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *settleSpeed;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLabel *settleAllchar;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *settleAccuracy;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *settleTime;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer;
    QPushButton *ConfirmBtn;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *settlementDialog)
    {
        if (settlementDialog->objectName().isEmpty())
            settlementDialog->setObjectName("settlementDialog");
        settlementDialog->resize(399, 297);
        settlementDialog->setMaximumSize(QSize(409, 300));
        verticalLayout_2 = new QVBoxLayout(settlementDialog);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        settleWidget = new QWidget(settlementDialog);
        settleWidget->setObjectName("settleWidget");
        verticalLayout_3 = new QVBoxLayout(settleWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_10 = new QWidget(settleWidget);
        widget_10->setObjectName("widget_10");
        verticalLayout = new QVBoxLayout(widget_10);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        widget_9 = new QWidget(widget_10);
        widget_9->setObjectName("widget_9");
        horizontalLayout_8 = new QHBoxLayout(widget_9);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, 20, 0, 0);
        label_8 = new QLabel(widget_9);
        label_8->setObjectName("label_8");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setStyleSheet(QString::fromUtf8("font: 700 33pt \"Microsoft YaHei UI\";\n"
"color:rgb(49, 138, 255);"));
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_8->addWidget(label_8);


        verticalLayout->addWidget(widget_9);

        widget_4 = new QWidget(widget_10);
        widget_4->setObjectName("widget_4");
        widget_4->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(widget_4);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, -1, 0, -1);
        widget_6 = new QWidget(widget_4);
        widget_6->setObjectName("widget_6");
        horizontalLayout_5 = new QHBoxLayout(widget_6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_5 = new QLabel(widget_6);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_5->addWidget(label_5);

        settleErrChar = new QLabel(widget_6);
        settleErrChar->setObjectName("settleErrChar");

        horizontalLayout_5->addWidget(settleErrChar);


        gridLayout->addWidget(widget_6, 1, 2, 1, 1);

        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName("widget_5");
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(widget_5);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_4->addWidget(label_4);

        settleInputchar = new QLabel(widget_5);
        settleInputchar->setObjectName("settleInputchar");

        horizontalLayout_4->addWidget(settleInputchar);


        gridLayout->addWidget(widget_5, 1, 1, 1, 1);

        widget_2 = new QWidget(widget_4);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_2->addWidget(label_2);

        settleSpeed = new QLabel(widget_2);
        settleSpeed->setObjectName("settleSpeed");
        settleSpeed->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(settleSpeed);


        gridLayout->addWidget(widget_2, 0, 1, 1, 1);

        widget_7 = new QWidget(widget_4);
        widget_7->setObjectName("widget_7");
        horizontalLayout_6 = new QHBoxLayout(widget_7);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_6 = new QLabel(widget_7);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_6->addWidget(label_6);

        settleAllchar = new QLabel(widget_7);
        settleAllchar->setObjectName("settleAllchar");

        horizontalLayout_6->addWidget(settleAllchar);


        gridLayout->addWidget(widget_7, 1, 0, 1, 1);

        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName("widget_3");
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(widget_3);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_3->addWidget(label_3);

        settleAccuracy = new QLabel(widget_3);
        settleAccuracy->setObjectName("settleAccuracy");

        horizontalLayout_3->addWidget(settleAccuracy);


        gridLayout->addWidget(widget_3, 0, 2, 1, 1);

        widget_8 = new QWidget(widget_4);
        widget_8->setObjectName("widget_8");
        horizontalLayout = new QHBoxLayout(widget_8);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget_8);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(label);

        settleTime = new QLabel(widget_8);
        settleTime->setObjectName("settleTime");
        settleTime->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(settleTime);


        gridLayout->addWidget(widget_8, 0, 0, 1, 1);


        verticalLayout->addWidget(widget_4);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 7);

        verticalLayout_3->addWidget(widget_10);

        widget_11 = new QWidget(settleWidget);
        widget_11->setObjectName("widget_11");
        horizontalLayout_9 = new QHBoxLayout(widget_11);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(0, 0, 0, 11);
        horizontalSpacer = new QSpacerItem(130, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        ConfirmBtn = new QPushButton(widget_11);
        ConfirmBtn->setObjectName("ConfirmBtn");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ConfirmBtn->sizePolicy().hasHeightForWidth());
        ConfirmBtn->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(ConfirmBtn);

        horizontalSpacer_2 = new QSpacerItem(130, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);


        verticalLayout_3->addWidget(widget_11);

        verticalLayout_3->setStretch(0, 8);
        verticalLayout_3->setStretch(1, 2);

        verticalLayout_2->addWidget(settleWidget);


        retranslateUi(settlementDialog);

        QMetaObject::connectSlotsByName(settlementDialog);
    } // setupUi

    void retranslateUi(QDialog *settlementDialog)
    {
        settlementDialog->setWindowTitle(QCoreApplication::translate("settlementDialog", "Dialog", nullptr));
        label_8->setText(QCoreApplication::translate("settlementDialog", "\346\265\213\350\257\225\347\273\223\346\236\234", nullptr));
        label_5->setText(QCoreApplication::translate("settlementDialog", "\351\224\231\350\257\257\345\255\227\346\225\260:", nullptr));
        settleErrChar->setText(QCoreApplication::translate("settlementDialog", "XXX\345\255\227", nullptr));
        label_4->setText(QCoreApplication::translate("settlementDialog", "\350\276\223\345\205\245\345\255\227\346\225\260\357\274\232", nullptr));
        settleInputchar->setText(QCoreApplication::translate("settlementDialog", "XXX\345\255\227", nullptr));
        label_2->setText(QCoreApplication::translate("settlementDialog", "\351\200\237\345\272\246\357\274\232", nullptr));
        settleSpeed->setText(QCoreApplication::translate("settlementDialog", "speed", nullptr));
        label_6->setText(QCoreApplication::translate("settlementDialog", "\346\200\273\345\255\227\346\225\260\357\274\232", nullptr));
        settleAllchar->setText(QCoreApplication::translate("settlementDialog", "XXX\345\255\227", nullptr));
        label_3->setText(QCoreApplication::translate("settlementDialog", "\346\255\243\347\241\256\347\216\207\357\274\232", nullptr));
        settleAccuracy->setText(QCoreApplication::translate("settlementDialog", "speed", nullptr));
        label->setText(QCoreApplication::translate("settlementDialog", "\346\227\266\351\227\264\357\274\232", nullptr));
        settleTime->setText(QCoreApplication::translate("settlementDialog", "Time", nullptr));
        ConfirmBtn->setText(QCoreApplication::translate("settlementDialog", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class settlementDialog: public Ui_settlementDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTLEMENTDIALOG_H
