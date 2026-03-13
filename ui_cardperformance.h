/********************************************************************************
** Form generated from reading UI file 'cardperformance.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDPERFORMANCE_H
#define UI_CARDPERFORMANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CardPerformance
{
public:
    QHBoxLayout *horizontalLayout_6;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *TitleLabel;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *dataLabel;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *describeLabel;
    QWidget *widget_9;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *iconLabel;
    QWidget *widget_2;

    void setupUi(QWidget *CardPerformance)
    {
        if (CardPerformance->objectName().isEmpty())
            CardPerformance->setObjectName("CardPerformance");
        CardPerformance->resize(311, 144);
        horizontalLayout_6 = new QHBoxLayout(CardPerformance);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        widget_8 = new QWidget(CardPerformance);
        widget_8->setObjectName("widget_8");
        horizontalLayout_5 = new QHBoxLayout(widget_8);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        widget_4 = new QWidget(widget_8);
        widget_4->setObjectName("widget_4");
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName("widget_5");
        horizontalLayout_2 = new QHBoxLayout(widget_5);
        horizontalLayout_2->setSpacing(1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(1, 1, 1, 1);
        TitleLabel = new QLabel(widget_5);
        TitleLabel->setObjectName("TitleLabel");
        TitleLabel->setStyleSheet(QString::fromUtf8("font-size: 15px;\n"
"font-weight: bold;\n"
"color: #000000;\n"
"font-family: \"Microsoft YaHei\";\n"
""));

        horizontalLayout_2->addWidget(TitleLabel);


        verticalLayout_2->addWidget(widget_5);

        widget_6 = new QWidget(widget_4);
        widget_6->setObjectName("widget_6");
        horizontalLayout_3 = new QHBoxLayout(widget_6);
        horizontalLayout_3->setSpacing(1);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(1, 1, 1, 1);
        dataLabel = new QLabel(widget_6);
        dataLabel->setObjectName("dataLabel");
        dataLabel->setStyleSheet(QString::fromUtf8("font-size: 23px;\n"
"font-weight: bold;\n"
"color: #409EFF;\n"
"font-family: \"Microsoft YaHei\";"));

        horizontalLayout_3->addWidget(dataLabel);


        verticalLayout_2->addWidget(widget_6);

        widget_7 = new QWidget(widget_4);
        widget_7->setObjectName("widget_7");
        horizontalLayout_4 = new QHBoxLayout(widget_7);
        horizontalLayout_4->setSpacing(1);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(1, 1, 1, 1);
        describeLabel = new QLabel(widget_7);
        describeLabel->setObjectName("describeLabel");
        describeLabel->setStyleSheet(QString::fromUtf8("color: #312e2eF;\n"
"font-family: \"Microsoft YaHei\";\n"
"font-size: 1px;"));
        describeLabel->setWordWrap(false);

        horizontalLayout_4->addWidget(describeLabel);


        verticalLayout_2->addWidget(widget_7);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(1, 6);
        verticalLayout_2->setStretch(2, 1);

        horizontalLayout_5->addWidget(widget_4);

        widget_9 = new QWidget(widget_8);
        widget_9->setObjectName("widget_9");

        horizontalLayout_5->addWidget(widget_9);

        horizontalLayout_5->setStretch(0, 7);
        horizontalLayout_5->setStretch(1, 3);

        horizontalLayout_6->addWidget(widget_8);

        widget_3 = new QWidget(CardPerformance);
        widget_3->setObjectName("widget_3");
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(widget_3);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        iconLabel = new QLabel(widget);
        iconLabel->setObjectName("iconLabel");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(40);
        sizePolicy.setVerticalStretch(40);
        sizePolicy.setHeightForWidth(iconLabel->sizePolicy().hasHeightForWidth());
        iconLabel->setSizePolicy(sizePolicy);
        iconLabel->setPixmap(QPixmap(QString::fromUtf8(":/res/Blizt.png")));
        iconLabel->setScaledContents(false);

        horizontalLayout->addWidget(iconLabel);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName("widget_2");

        verticalLayout->addWidget(widget_2);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 7);

        horizontalLayout_6->addWidget(widget_3);


        retranslateUi(CardPerformance);

        QMetaObject::connectSlotsByName(CardPerformance);
    } // setupUi

    void retranslateUi(QWidget *CardPerformance)
    {
        CardPerformance->setWindowTitle(QCoreApplication::translate("CardPerformance", "Form", nullptr));
        TitleLabel->setText(QCoreApplication::translate("CardPerformance", "Typing", nullptr));
        dataLabel->setText(QCoreApplication::translate("CardPerformance", "85", nullptr));
        describeLabel->setText(QCoreApplication::translate("CardPerformance", "words per minute", nullptr));
        iconLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CardPerformance: public Ui_CardPerformance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDPERFORMANCE_H
