/********************************************************************************
** Form generated from reading UI file 'retrievewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RETRIEVEWIDGET_H
#define UI_RETRIEVEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RetrieveWidget
{
public:
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_9;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *RetrUserNameEdit;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *RetrPassWordEdit;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *RetrStudentIDEdit;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *RetrSchoolNameEdit;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_8;
    QLineEdit *RetrEMailEdit;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *RetrVerCodeEdit;
    QPushButton *GetCodeBtn;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_3;
    QPushButton *RetrieveBtn;
    QPushButton *ReturnBtn;

    void setupUi(QWidget *RetrieveWidget)
    {
        if (RetrieveWidget->objectName().isEmpty())
            RetrieveWidget->setObjectName("RetrieveWidget");
        RetrieveWidget->resize(950, 628);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::HelpFaq));
        RetrieveWidget->setWindowIcon(icon);
        horizontalLayout_3 = new QHBoxLayout(RetrieveWidget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(3, 3, 3, 3);
        widget = new QWidget(RetrieveWidget);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(400, 400));
        label->setStyleSheet(QString::fromUtf8(""));
        label->setPixmap(QPixmap(QString::fromUtf8(":/res/RetrievePage.jpg")));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label);


        horizontalLayout->addWidget(widget_2);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName("widget_3");
        widget_3->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_9 = new QVBoxLayout(widget_3);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        widget_7 = new QWidget(widget_3);
        widget_7->setObjectName("widget_7");
        verticalLayout_10 = new QVBoxLayout(widget_7);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_10->setContentsMargins(0, 5, 0, 0);
        label_2 = new QLabel(widget_7);
        label_2->setObjectName("label_2");
        label_2->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_2->setStyleSheet(QString::fromUtf8("font-size:25px;"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_10->addWidget(label_2);

        label_3 = new QLabel(widget_7);
        label_3->setObjectName("label_3");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_10->addWidget(label_3);


        verticalLayout_9->addWidget(widget_7);

        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName("widget_5");
        verticalLayout = new QVBoxLayout(widget_5);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(widget_5);
        groupBox->setObjectName("groupBox");
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName("verticalLayout_4");
        RetrUserNameEdit = new QLineEdit(groupBox);
        RetrUserNameEdit->setObjectName("RetrUserNameEdit");
        RetrUserNameEdit->setInputMethodHints(Qt::InputMethodHint::ImhNone);

        verticalLayout_4->addWidget(RetrUserNameEdit);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget_5);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        RetrPassWordEdit = new QLineEdit(groupBox_2);
        RetrPassWordEdit->setObjectName("RetrPassWordEdit");
        RetrPassWordEdit->setInputMethodHints(Qt::InputMethodHint::ImhNoAutoUppercase|Qt::InputMethodHint::ImhNoPredictiveText|Qt::InputMethodHint::ImhSensitiveData);
        RetrPassWordEdit->setEchoMode(QLineEdit::EchoMode::PasswordEchoOnEdit);
        RetrPassWordEdit->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        RetrPassWordEdit->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);

        verticalLayout_5->addWidget(RetrPassWordEdit);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(widget_5);
        groupBox_3->setObjectName("groupBox_3");
        verticalLayout_6 = new QVBoxLayout(groupBox_3);
        verticalLayout_6->setObjectName("verticalLayout_6");
        RetrStudentIDEdit = new QLineEdit(groupBox_3);
        RetrStudentIDEdit->setObjectName("RetrStudentIDEdit");

        verticalLayout_6->addWidget(RetrStudentIDEdit);


        verticalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(widget_5);
        groupBox_4->setObjectName("groupBox_4");
        verticalLayout_7 = new QVBoxLayout(groupBox_4);
        verticalLayout_7->setObjectName("verticalLayout_7");
        RetrSchoolNameEdit = new QLineEdit(groupBox_4);
        RetrSchoolNameEdit->setObjectName("RetrSchoolNameEdit");

        verticalLayout_7->addWidget(RetrSchoolNameEdit);


        verticalLayout->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(widget_5);
        groupBox_5->setObjectName("groupBox_5");
        verticalLayout_8 = new QVBoxLayout(groupBox_5);
        verticalLayout_8->setObjectName("verticalLayout_8");
        RetrEMailEdit = new QLineEdit(groupBox_5);
        RetrEMailEdit->setObjectName("RetrEMailEdit");

        verticalLayout_8->addWidget(RetrEMailEdit);


        verticalLayout->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(widget_5);
        groupBox_6->setObjectName("groupBox_6");
        horizontalLayout_2 = new QHBoxLayout(groupBox_6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        RetrVerCodeEdit = new QLineEdit(groupBox_6);
        RetrVerCodeEdit->setObjectName("RetrVerCodeEdit");

        horizontalLayout_2->addWidget(RetrVerCodeEdit);

        GetCodeBtn = new QPushButton(groupBox_6);
        GetCodeBtn->setObjectName("GetCodeBtn");

        horizontalLayout_2->addWidget(GetCodeBtn);


        verticalLayout->addWidget(groupBox_6);


        verticalLayout_9->addWidget(widget_5);

        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName("widget_4");
        widget_4->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        verticalLayout_3 = new QVBoxLayout(widget_4);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(18, -1, 18, -1);
        RetrieveBtn = new QPushButton(widget_4);
        RetrieveBtn->setObjectName("RetrieveBtn");

        verticalLayout_3->addWidget(RetrieveBtn);

        ReturnBtn = new QPushButton(widget_4);
        ReturnBtn->setObjectName("ReturnBtn");

        verticalLayout_3->addWidget(ReturnBtn);


        verticalLayout_9->addWidget(widget_4);


        horizontalLayout->addWidget(widget_3);

        horizontalLayout->setStretch(0, 7);
        horizontalLayout->setStretch(1, 3);

        horizontalLayout_3->addWidget(widget);


        retranslateUi(RetrieveWidget);

        QMetaObject::connectSlotsByName(RetrieveWidget);
    } // setupUi

    void retranslateUi(QWidget *RetrieveWidget)
    {
        RetrieveWidget->setWindowTitle(QCoreApplication::translate("RetrieveWidget", "Form", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("RetrieveWidget", "Retrieve Password", nullptr));
        label_3->setText(QCoreApplication::translate("RetrieveWidget", "Retrieve for student portal", nullptr));
        groupBox->setTitle(QCoreApplication::translate("RetrieveWidget", "Username", nullptr));
        RetrUserNameEdit->setPlaceholderText(QCoreApplication::translate("RetrieveWidget", "Enter Username", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("RetrieveWidget", "New Password", nullptr));
        RetrPassWordEdit->setInputMask(QString());
        RetrPassWordEdit->setPlaceholderText(QCoreApplication::translate("RetrieveWidget", "Enter New Password", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("RetrieveWidget", "Student ID", nullptr));
        RetrStudentIDEdit->setPlaceholderText(QCoreApplication::translate("RetrieveWidget", "Enter Student ID", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("RetrieveWidget", "School", nullptr));
        RetrSchoolNameEdit->setPlaceholderText(QCoreApplication::translate("RetrieveWidget", "Enter School Name", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("RetrieveWidget", "E-Mail", nullptr));
        RetrEMailEdit->setPlaceholderText(QCoreApplication::translate("RetrieveWidget", "Enter Your E-Mail", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("RetrieveWidget", "Verification Code", nullptr));
        RetrVerCodeEdit->setPlaceholderText(QCoreApplication::translate("RetrieveWidget", "Enter Code", nullptr));
        GetCodeBtn->setText(QCoreApplication::translate("RetrieveWidget", "Get Code", nullptr));
        RetrieveBtn->setText(QCoreApplication::translate("RetrieveWidget", "Retrieve", nullptr));
        ReturnBtn->setText(QCoreApplication::translate("RetrieveWidget", "Return", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RetrieveWidget: public Ui_RetrieveWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RETRIEVEWIDGET_H
