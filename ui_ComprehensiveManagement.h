/********************************************************************************
** Form generated from reading UI file 'ComprehensiveManagement.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPREHENSIVEMANAGEMENT_H
#define UI_COMPREHENSIVEMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ComprehensiveManagementClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *comprehensiveTab;
    QWidget *UserTab;
    QVBoxLayout *verticalLayout;
    QWidget *OperationWidget;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *userComboBox;
    QLineEdit *userSelectEdit;
    QPushButton *UserSelectBtn;
    QPushButton *UserUpdateBtn;
    QPushButton *UserDeleteBtn;
    QPushButton *UserLeadingoutBtn;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QTableView *userTable;
    QWidget *compTab;
    QVBoxLayout *verticalLayout_5;
    QWidget *OperationWidget_3;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *compComboBox;
    QLineEdit *compSelectEdit;
    QPushButton *CompSelectBtn;
    QPushButton *CompInsertBtn;
    QPushButton *CompDeleteBtn;
    QPushButton *CompLeadingoutBtn;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QTableView *compTable;
    QWidget *ArticleTab;
    QVBoxLayout *verticalLayout_4;
    QWidget *OperationWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *articleComboBox;
    QLineEdit *ArticlelSelectEdit;
    QPushButton *ArticleSelectBtn;
    QPushButton *ArticleUpdateBtn;
    QPushButton *ArticleInsertBtn;
    QPushButton *ArticleDeleteBtn;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_6;
    QTableView *articleTable;
    QWidget *compScoreTab;
    QVBoxLayout *verticalLayout_3;
    QWidget *OperationWidget_4;
    QHBoxLayout *horizontalLayout_7;
    QComboBox *compScoreComboBox;
    QLineEdit *compScoreSelectEdit;
    QPushButton *compScoreSelectBtn;
    QPushButton *compScoreLeadingOutBtn;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_8;
    QTableView *compScoreTable;

    void setupUi(QMainWindow *ComprehensiveManagementClass)
    {
        if (ComprehensiveManagementClass->objectName().isEmpty())
            ComprehensiveManagementClass->setObjectName("ComprehensiveManagementClass");
        ComprehensiveManagementClass->setWindowModality(Qt::WindowModality::ApplicationModal);
        ComprehensiveManagementClass->resize(855, 626);
        centralWidget = new QWidget(ComprehensiveManagementClass);
        centralWidget->setObjectName("centralWidget");
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        comprehensiveTab = new QTabWidget(centralWidget);
        comprehensiveTab->setObjectName("comprehensiveTab");
        UserTab = new QWidget();
        UserTab->setObjectName("UserTab");
        verticalLayout = new QVBoxLayout(UserTab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        OperationWidget = new QWidget(UserTab);
        OperationWidget->setObjectName("OperationWidget");
        horizontalLayout_3 = new QHBoxLayout(OperationWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        userComboBox = new QComboBox(OperationWidget);
        userComboBox->setObjectName("userComboBox");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(userComboBox->sizePolicy().hasHeightForWidth());
        userComboBox->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(userComboBox);

        userSelectEdit = new QLineEdit(OperationWidget);
        userSelectEdit->setObjectName("userSelectEdit");
        sizePolicy.setHeightForWidth(userSelectEdit->sizePolicy().hasHeightForWidth());
        userSelectEdit->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(userSelectEdit);

        UserSelectBtn = new QPushButton(OperationWidget);
        UserSelectBtn->setObjectName("UserSelectBtn");
        sizePolicy.setHeightForWidth(UserSelectBtn->sizePolicy().hasHeightForWidth());
        UserSelectBtn->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(UserSelectBtn);

        UserUpdateBtn = new QPushButton(OperationWidget);
        UserUpdateBtn->setObjectName("UserUpdateBtn");
        sizePolicy.setHeightForWidth(UserUpdateBtn->sizePolicy().hasHeightForWidth());
        UserUpdateBtn->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(UserUpdateBtn);

        UserDeleteBtn = new QPushButton(OperationWidget);
        UserDeleteBtn->setObjectName("UserDeleteBtn");
        sizePolicy.setHeightForWidth(UserDeleteBtn->sizePolicy().hasHeightForWidth());
        UserDeleteBtn->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(UserDeleteBtn);

        UserLeadingoutBtn = new QPushButton(OperationWidget);
        UserLeadingoutBtn->setObjectName("UserLeadingoutBtn");
        sizePolicy.setHeightForWidth(UserLeadingoutBtn->sizePolicy().hasHeightForWidth());
        UserLeadingoutBtn->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(UserLeadingoutBtn);


        verticalLayout->addWidget(OperationWidget);

        widget = new QWidget(UserTab);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        userTable = new QTableView(widget);
        userTable->setObjectName("userTable");

        horizontalLayout->addWidget(userTable);


        verticalLayout->addWidget(widget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 9);
        comprehensiveTab->addTab(UserTab, QString());
        compTab = new QWidget();
        compTab->setObjectName("compTab");
        verticalLayout_5 = new QVBoxLayout(compTab);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName("verticalLayout_5");
        OperationWidget_3 = new QWidget(compTab);
        OperationWidget_3->setObjectName("OperationWidget_3");
        horizontalLayout_5 = new QHBoxLayout(OperationWidget_3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        compComboBox = new QComboBox(OperationWidget_3);
        compComboBox->setObjectName("compComboBox");
        sizePolicy.setHeightForWidth(compComboBox->sizePolicy().hasHeightForWidth());
        compComboBox->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(compComboBox);

        compSelectEdit = new QLineEdit(OperationWidget_3);
        compSelectEdit->setObjectName("compSelectEdit");
        sizePolicy.setHeightForWidth(compSelectEdit->sizePolicy().hasHeightForWidth());
        compSelectEdit->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(compSelectEdit);

        CompSelectBtn = new QPushButton(OperationWidget_3);
        CompSelectBtn->setObjectName("CompSelectBtn");
        sizePolicy.setHeightForWidth(CompSelectBtn->sizePolicy().hasHeightForWidth());
        CompSelectBtn->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(CompSelectBtn);

        CompInsertBtn = new QPushButton(OperationWidget_3);
        CompInsertBtn->setObjectName("CompInsertBtn");
        sizePolicy.setHeightForWidth(CompInsertBtn->sizePolicy().hasHeightForWidth());
        CompInsertBtn->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(CompInsertBtn);

        CompDeleteBtn = new QPushButton(OperationWidget_3);
        CompDeleteBtn->setObjectName("CompDeleteBtn");
        sizePolicy.setHeightForWidth(CompDeleteBtn->sizePolicy().hasHeightForWidth());
        CompDeleteBtn->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(CompDeleteBtn);

        CompLeadingoutBtn = new QPushButton(OperationWidget_3);
        CompLeadingoutBtn->setObjectName("CompLeadingoutBtn");
        sizePolicy.setHeightForWidth(CompLeadingoutBtn->sizePolicy().hasHeightForWidth());
        CompLeadingoutBtn->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(CompLeadingoutBtn);


        verticalLayout_5->addWidget(OperationWidget_3);

        widget_3 = new QWidget(compTab);
        widget_3->setObjectName("widget_3");
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        compTable = new QTableView(widget_3);
        compTable->setObjectName("compTable");

        horizontalLayout_2->addWidget(compTable);


        verticalLayout_5->addWidget(widget_3);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 9);
        comprehensiveTab->addTab(compTab, QString());
        ArticleTab = new QWidget();
        ArticleTab->setObjectName("ArticleTab");
        verticalLayout_4 = new QVBoxLayout(ArticleTab);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName("verticalLayout_4");
        OperationWidget_2 = new QWidget(ArticleTab);
        OperationWidget_2->setObjectName("OperationWidget_2");
        horizontalLayout_4 = new QHBoxLayout(OperationWidget_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        articleComboBox = new QComboBox(OperationWidget_2);
        articleComboBox->setObjectName("articleComboBox");
        sizePolicy.setHeightForWidth(articleComboBox->sizePolicy().hasHeightForWidth());
        articleComboBox->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(articleComboBox);

        ArticlelSelectEdit = new QLineEdit(OperationWidget_2);
        ArticlelSelectEdit->setObjectName("ArticlelSelectEdit");
        sizePolicy.setHeightForWidth(ArticlelSelectEdit->sizePolicy().hasHeightForWidth());
        ArticlelSelectEdit->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(ArticlelSelectEdit);

        ArticleSelectBtn = new QPushButton(OperationWidget_2);
        ArticleSelectBtn->setObjectName("ArticleSelectBtn");
        sizePolicy.setHeightForWidth(ArticleSelectBtn->sizePolicy().hasHeightForWidth());
        ArticleSelectBtn->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(ArticleSelectBtn);

        ArticleUpdateBtn = new QPushButton(OperationWidget_2);
        ArticleUpdateBtn->setObjectName("ArticleUpdateBtn");
        sizePolicy.setHeightForWidth(ArticleUpdateBtn->sizePolicy().hasHeightForWidth());
        ArticleUpdateBtn->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(ArticleUpdateBtn);

        ArticleInsertBtn = new QPushButton(OperationWidget_2);
        ArticleInsertBtn->setObjectName("ArticleInsertBtn");
        sizePolicy.setHeightForWidth(ArticleInsertBtn->sizePolicy().hasHeightForWidth());
        ArticleInsertBtn->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(ArticleInsertBtn);

        ArticleDeleteBtn = new QPushButton(OperationWidget_2);
        ArticleDeleteBtn->setObjectName("ArticleDeleteBtn");
        sizePolicy.setHeightForWidth(ArticleDeleteBtn->sizePolicy().hasHeightForWidth());
        ArticleDeleteBtn->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(ArticleDeleteBtn);


        verticalLayout_4->addWidget(OperationWidget_2);

        widget_2 = new QWidget(ArticleTab);
        widget_2->setObjectName("widget_2");
        horizontalLayout_6 = new QHBoxLayout(widget_2);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        articleTable = new QTableView(widget_2);
        articleTable->setObjectName("articleTable");

        horizontalLayout_6->addWidget(articleTable);


        verticalLayout_4->addWidget(widget_2);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 9);
        comprehensiveTab->addTab(ArticleTab, QString());
        compScoreTab = new QWidget();
        compScoreTab->setObjectName("compScoreTab");
        verticalLayout_3 = new QVBoxLayout(compScoreTab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        OperationWidget_4 = new QWidget(compScoreTab);
        OperationWidget_4->setObjectName("OperationWidget_4");
        horizontalLayout_7 = new QHBoxLayout(OperationWidget_4);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        compScoreComboBox = new QComboBox(OperationWidget_4);
        compScoreComboBox->setObjectName("compScoreComboBox");
        sizePolicy.setHeightForWidth(compScoreComboBox->sizePolicy().hasHeightForWidth());
        compScoreComboBox->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(compScoreComboBox);

        compScoreSelectEdit = new QLineEdit(OperationWidget_4);
        compScoreSelectEdit->setObjectName("compScoreSelectEdit");
        sizePolicy.setHeightForWidth(compScoreSelectEdit->sizePolicy().hasHeightForWidth());
        compScoreSelectEdit->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(compScoreSelectEdit);

        compScoreSelectBtn = new QPushButton(OperationWidget_4);
        compScoreSelectBtn->setObjectName("compScoreSelectBtn");
        sizePolicy.setHeightForWidth(compScoreSelectBtn->sizePolicy().hasHeightForWidth());
        compScoreSelectBtn->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(compScoreSelectBtn);

        compScoreLeadingOutBtn = new QPushButton(OperationWidget_4);
        compScoreLeadingOutBtn->setObjectName("compScoreLeadingOutBtn");
        sizePolicy.setHeightForWidth(compScoreLeadingOutBtn->sizePolicy().hasHeightForWidth());
        compScoreLeadingOutBtn->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(compScoreLeadingOutBtn);


        verticalLayout_3->addWidget(OperationWidget_4);

        widget_4 = new QWidget(compScoreTab);
        widget_4->setObjectName("widget_4");
        horizontalLayout_8 = new QHBoxLayout(widget_4);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        compScoreTable = new QTableView(widget_4);
        compScoreTable->setObjectName("compScoreTable");

        horizontalLayout_8->addWidget(compScoreTable);


        verticalLayout_3->addWidget(widget_4);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 9);
        comprehensiveTab->addTab(compScoreTab, QString());

        verticalLayout_2->addWidget(comprehensiveTab);

        ComprehensiveManagementClass->setCentralWidget(centralWidget);

        retranslateUi(ComprehensiveManagementClass);

        comprehensiveTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ComprehensiveManagementClass);
    } // setupUi

    void retranslateUi(QMainWindow *ComprehensiveManagementClass)
    {
        ComprehensiveManagementClass->setWindowTitle(QCoreApplication::translate("ComprehensiveManagementClass", "ComprehensiveManagement", nullptr));
        userSelectEdit->setPlaceholderText(QCoreApplication::translate("ComprehensiveManagementClass", "\346\237\245\350\257\242/Select", nullptr));
        UserSelectBtn->setText(QCoreApplication::translate("ComprehensiveManagementClass", "\346\237\245\350\257\242", nullptr));
        UserUpdateBtn->setText(QCoreApplication::translate("ComprehensiveManagementClass", "\344\277\256\346\224\271", nullptr));
        UserDeleteBtn->setText(QCoreApplication::translate("ComprehensiveManagementClass", "\345\210\240\351\231\244", nullptr));
        UserLeadingoutBtn->setText(QCoreApplication::translate("ComprehensiveManagementClass", "\345\257\274\345\207\272", nullptr));
        comprehensiveTab->setTabText(comprehensiveTab->indexOf(UserTab), QCoreApplication::translate("ComprehensiveManagementClass", "\344\272\272\345\221\230\347\256\241\347\220\206", nullptr));
        compSelectEdit->setPlaceholderText(QCoreApplication::translate("ComprehensiveManagementClass", "\346\237\245\350\257\242/Select", nullptr));
        CompSelectBtn->setText(QCoreApplication::translate("ComprehensiveManagementClass", "\346\237\245\350\257\242", nullptr));
        CompInsertBtn->setText(QCoreApplication::translate("ComprehensiveManagementClass", "\346\267\273\345\212\240", nullptr));
        CompDeleteBtn->setText(QCoreApplication::translate("ComprehensiveManagementClass", "\345\210\240\351\231\244", nullptr));
        CompLeadingoutBtn->setText(QCoreApplication::translate("ComprehensiveManagementClass", "\345\257\274\345\207\272", nullptr));
        comprehensiveTab->setTabText(comprehensiveTab->indexOf(compTab), QCoreApplication::translate("ComprehensiveManagementClass", "\350\265\233\344\272\213\347\256\241\347\220\206", nullptr));
        ArticlelSelectEdit->setPlaceholderText(QCoreApplication::translate("ComprehensiveManagementClass", "\346\237\245\350\257\242/Select", nullptr));
        ArticleSelectBtn->setText(QCoreApplication::translate("ComprehensiveManagementClass", "\346\237\245\350\257\242", nullptr));
        ArticleUpdateBtn->setText(QCoreApplication::translate("ComprehensiveManagementClass", "\344\277\256\346\224\271", nullptr));
        ArticleInsertBtn->setText(QCoreApplication::translate("ComprehensiveManagementClass", "\346\267\273\345\212\240", nullptr));
        ArticleDeleteBtn->setText(QCoreApplication::translate("ComprehensiveManagementClass", "\345\210\240\351\231\244", nullptr));
        comprehensiveTab->setTabText(comprehensiveTab->indexOf(ArticleTab), QCoreApplication::translate("ComprehensiveManagementClass", "\346\226\207\347\253\240\347\256\241\347\220\206", nullptr));
        compScoreSelectEdit->setPlaceholderText(QCoreApplication::translate("ComprehensiveManagementClass", "\346\237\245\350\257\242/Select", nullptr));
        compScoreSelectBtn->setText(QCoreApplication::translate("ComprehensiveManagementClass", "\346\237\245\350\257\242", nullptr));
        compScoreLeadingOutBtn->setText(QCoreApplication::translate("ComprehensiveManagementClass", "\345\257\274\345\207\272", nullptr));
        comprehensiveTab->setTabText(comprehensiveTab->indexOf(compScoreTab), QCoreApplication::translate("ComprehensiveManagementClass", "\346\257\224\350\265\233\346\210\220\347\273\251\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComprehensiveManagementClass: public Ui_ComprehensiveManagementClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPREHENSIVEMANAGEMENT_H
