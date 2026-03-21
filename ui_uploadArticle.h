/********************************************************************************
** Form generated from reading UI file 'uploadArticle.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOADARTICLE_H
#define UI_UPLOADARTICLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_uploadArticleClass
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *uploadArticleWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *titleLineEdit;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *authorLineEdit;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTextEdit *ArticleTextEdit;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLabel *ALLChar;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *SubmitBtn;
    QPushButton *CancelBtn;

    void setupUi(QWidget *uploadArticleClass)
    {
        if (uploadArticleClass->objectName().isEmpty())
            uploadArticleClass->setObjectName("uploadArticleClass");
        uploadArticleClass->setWindowModality(Qt::WindowModality::ApplicationModal);
        uploadArticleClass->resize(448, 494);
        verticalLayout_3 = new QVBoxLayout(uploadArticleClass);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        uploadArticleWidget = new QWidget(uploadArticleClass);
        uploadArticleWidget->setObjectName("uploadArticleWidget");
        verticalLayout_2 = new QVBoxLayout(uploadArticleWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(-1, -1, -1, 5);
        widget_2 = new QWidget(uploadArticleWidget);
        widget_2->setObjectName("widget_2");
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, -1, 0, -1);
        groupBox_2 = new QGroupBox(widget_2);
        groupBox_2->setObjectName("groupBox_2");
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        titleLineEdit = new QLineEdit(groupBox_2);
        titleLineEdit->setObjectName("titleLineEdit");

        horizontalLayout_2->addWidget(titleLineEdit);


        horizontalLayout_4->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(widget_2);
        groupBox_3->setObjectName("groupBox_3");
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        authorLineEdit = new QLineEdit(groupBox_3);
        authorLineEdit->setObjectName("authorLineEdit");

        horizontalLayout_3->addWidget(authorLineEdit);


        horizontalLayout_4->addWidget(groupBox_3);


        verticalLayout_2->addWidget(widget_2);

        groupBox = new QGroupBox(uploadArticleWidget);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        ArticleTextEdit = new QTextEdit(groupBox);
        ArticleTextEdit->setObjectName("ArticleTextEdit");

        verticalLayout->addWidget(ArticleTextEdit);

        widget_3 = new QWidget(groupBox);
        widget_3->setObjectName("widget_3");
        horizontalLayout_5 = new QHBoxLayout(widget_3);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        label = new QLabel(widget_3);
        label->setObjectName("label");

        horizontalLayout_5->addWidget(label);

        ALLChar = new QLabel(widget_3);
        ALLChar->setObjectName("ALLChar");

        horizontalLayout_5->addWidget(ALLChar);


        verticalLayout->addWidget(widget_3);

        verticalLayout->setStretch(0, 9);
        verticalLayout->setStretch(1, 1);

        verticalLayout_2->addWidget(groupBox);

        widget = new QWidget(uploadArticleWidget);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 3, -1, 0);
        SubmitBtn = new QPushButton(widget);
        SubmitBtn->setObjectName("SubmitBtn");

        horizontalLayout->addWidget(SubmitBtn);

        CancelBtn = new QPushButton(widget);
        CancelBtn->setObjectName("CancelBtn");

        horizontalLayout->addWidget(CancelBtn);


        verticalLayout_2->addWidget(widget);


        verticalLayout_3->addWidget(uploadArticleWidget);


        retranslateUi(uploadArticleClass);

        QMetaObject::connectSlotsByName(uploadArticleClass);
    } // setupUi

    void retranslateUi(QWidget *uploadArticleClass)
    {
        uploadArticleClass->setWindowTitle(QCoreApplication::translate("uploadArticleClass", "uploadArticle", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("uploadArticleClass", "\351\242\230\347\233\256", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("uploadArticleClass", "\344\275\234\350\200\205", nullptr));
        groupBox->setTitle(QCoreApplication::translate("uploadArticleClass", "\346\226\207\347\253\240\345\206\205\345\256\271", nullptr));
        label->setText(QCoreApplication::translate("uploadArticleClass", "\346\200\273\345\255\227\346\225\260\357\274\232", nullptr));
        ALLChar->setText(QCoreApplication::translate("uploadArticleClass", "ALLChar", nullptr));
        SubmitBtn->setText(QCoreApplication::translate("uploadArticleClass", "\346\217\220\344\272\244", nullptr));
        CancelBtn->setText(QCoreApplication::translate("uploadArticleClass", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class uploadArticleClass: public Ui_uploadArticleClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADARTICLE_H
