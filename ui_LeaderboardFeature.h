/********************************************************************************
** Form generated from reading UI file 'LeaderboardFeature.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEADERBOARDFEATURE_H
#define UI_LEADERBOARDFEATURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LeaderboardFeatureClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *OperationWidget;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *leaderboardComboBox;
    QLineEdit *leaderboardSelectEdit;
    QPushButton *leaderboardSelectBtn;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTableView *leaderboardTable;

    void setupUi(QMainWindow *LeaderboardFeatureClass)
    {
        if (LeaderboardFeatureClass->objectName().isEmpty())
            LeaderboardFeatureClass->setObjectName("LeaderboardFeatureClass");
        LeaderboardFeatureClass->resize(502, 545);
        centralWidget = new QWidget(LeaderboardFeatureClass);
        centralWidget->setObjectName("centralWidget");
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        OperationWidget = new QWidget(centralWidget);
        OperationWidget->setObjectName("OperationWidget");
        horizontalLayout_3 = new QHBoxLayout(OperationWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        leaderboardComboBox = new QComboBox(OperationWidget);
        leaderboardComboBox->setObjectName("leaderboardComboBox");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leaderboardComboBox->sizePolicy().hasHeightForWidth());
        leaderboardComboBox->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(leaderboardComboBox);

        leaderboardSelectEdit = new QLineEdit(OperationWidget);
        leaderboardSelectEdit->setObjectName("leaderboardSelectEdit");
        sizePolicy.setHeightForWidth(leaderboardSelectEdit->sizePolicy().hasHeightForWidth());
        leaderboardSelectEdit->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(leaderboardSelectEdit);

        leaderboardSelectBtn = new QPushButton(OperationWidget);
        leaderboardSelectBtn->setObjectName("leaderboardSelectBtn");
        sizePolicy.setHeightForWidth(leaderboardSelectBtn->sizePolicy().hasHeightForWidth());
        leaderboardSelectBtn->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(leaderboardSelectBtn);


        verticalLayout_2->addWidget(OperationWidget);

        widget = new QWidget(centralWidget);
        widget->setObjectName("widget");
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        leaderboardTable = new QTableView(widget);
        leaderboardTable->setObjectName("leaderboardTable");

        verticalLayout->addWidget(leaderboardTable);


        verticalLayout_2->addWidget(widget);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 9);
        LeaderboardFeatureClass->setCentralWidget(centralWidget);

        retranslateUi(LeaderboardFeatureClass);

        QMetaObject::connectSlotsByName(LeaderboardFeatureClass);
    } // setupUi

    void retranslateUi(QMainWindow *LeaderboardFeatureClass)
    {
        LeaderboardFeatureClass->setWindowTitle(QCoreApplication::translate("LeaderboardFeatureClass", "LeaderboardFeature", nullptr));
        leaderboardSelectEdit->setPlaceholderText(QCoreApplication::translate("LeaderboardFeatureClass", "\346\237\245\350\257\242/Select", nullptr));
        leaderboardSelectBtn->setText(QCoreApplication::translate("LeaderboardFeatureClass", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LeaderboardFeatureClass: public Ui_LeaderboardFeatureClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEADERBOARDFEATURE_H
