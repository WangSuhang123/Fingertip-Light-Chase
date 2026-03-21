/********************************************************************************
** Form generated from reading UI file 'CompetitionLobbyWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPETITIONLOBBYWIDGET_H
#define UI_COMPETITIONLOBBYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CompetitionLobbyWidgetClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *CompetitionLobbyWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *titleWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *CompetitionSchool;
    QSpacerItem *horizontalSpacer;
    QWidget *CompetitionTableWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *CompetitionTable;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *refreshBtn;
    QPushButton *BackBtn;

    void setupUi(QMainWindow *CompetitionLobbyWidgetClass)
    {
        if (CompetitionLobbyWidgetClass->objectName().isEmpty())
            CompetitionLobbyWidgetClass->setObjectName("CompetitionLobbyWidgetClass");
        CompetitionLobbyWidgetClass->resize(802, 477);
        centralWidget = new QWidget(CompetitionLobbyWidgetClass);
        centralWidget->setObjectName("centralWidget");
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        CompetitionLobbyWidget = new QWidget(centralWidget);
        CompetitionLobbyWidget->setObjectName("CompetitionLobbyWidget");
        verticalLayout_2 = new QVBoxLayout(CompetitionLobbyWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        titleWidget = new QWidget(CompetitionLobbyWidget);
        titleWidget->setObjectName("titleWidget");
        horizontalLayout_2 = new QHBoxLayout(titleWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(titleWidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 16pt \"Microsoft YaHei UI\";"));

        horizontalLayout_2->addWidget(label_2);

        CompetitionSchool = new QLabel(titleWidget);
        CompetitionSchool->setObjectName("CompetitionSchool");
        CompetitionSchool->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 16pt \"Microsoft YaHei UI\";"));

        horizontalLayout_2->addWidget(CompetitionSchool);

        horizontalSpacer = new QSpacerItem(307, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(titleWidget);

        CompetitionTableWidget = new QWidget(CompetitionLobbyWidget);
        CompetitionTableWidget->setObjectName("CompetitionTableWidget");
        verticalLayout = new QVBoxLayout(CompetitionTableWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(CompetitionTableWidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Microsoft YaHei UI\";"));

        verticalLayout->addWidget(label);

        CompetitionTable = new QTableWidget(CompetitionTableWidget);
        CompetitionTable->setObjectName("CompetitionTable");

        verticalLayout->addWidget(CompetitionTable);

        widget = new QWidget(CompetitionTableWidget);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        refreshBtn = new QPushButton(widget);
        refreshBtn->setObjectName("refreshBtn");

        horizontalLayout->addWidget(refreshBtn);

        BackBtn = new QPushButton(widget);
        BackBtn->setObjectName("BackBtn");

        horizontalLayout->addWidget(BackBtn);


        verticalLayout->addWidget(widget);


        verticalLayout_2->addWidget(CompetitionTableWidget);


        verticalLayout_3->addWidget(CompetitionLobbyWidget);

        CompetitionLobbyWidgetClass->setCentralWidget(centralWidget);

        retranslateUi(CompetitionLobbyWidgetClass);

        QMetaObject::connectSlotsByName(CompetitionLobbyWidgetClass);
    } // setupUi

    void retranslateUi(QMainWindow *CompetitionLobbyWidgetClass)
    {
        CompetitionLobbyWidgetClass->setWindowTitle(QCoreApplication::translate("CompetitionLobbyWidgetClass", "CompetitionLobbyWidget", nullptr));
        label_2->setText(QCoreApplication::translate("CompetitionLobbyWidgetClass", "\345\255\246\346\240\241\357\274\232", nullptr));
        CompetitionSchool->setText(QCoreApplication::translate("CompetitionLobbyWidgetClass", "XXX\345\255\246\346\240\241", nullptr));
        label->setText(QCoreApplication::translate("CompetitionLobbyWidgetClass", "\346\257\224\350\265\233\345\210\227\350\241\250", nullptr));
        refreshBtn->setText(QCoreApplication::translate("CompetitionLobbyWidgetClass", "\345\210\267\346\226\260\346\257\224\350\265\233", nullptr));
        BackBtn->setText(QCoreApplication::translate("CompetitionLobbyWidgetClass", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CompetitionLobbyWidgetClass: public Ui_CompetitionLobbyWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPETITIONLOBBYWIDGET_H
