/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWidget
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
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
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *usernameEdit;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *PasswordEdit;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *StudentIDEdit;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *SchoolNameEdit;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_3;
    QPushButton *LoginBtn;
    QPushButton *registerBtn;
    QSpacerItem *verticalSpacer;
    QPushButton *forgotBtn;

    void setupUi(QMainWindow *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName("LoginWidget");
        LoginWidget->resize(950, 617);
        LoginWidget->setMinimumSize(QSize(950, 617));
        LoginWidget->setMaximumSize(QSize(950, 617));
        LoginWidget->setFocusPolicy(Qt::FocusPolicy::TabFocus);
        LoginWidget->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::GoHome));
        LoginWidget->setWindowIcon(icon);
        LoginWidget->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        LoginWidget->setDocumentMode(false);
        LoginWidget->setTabShape(QTabWidget::TabShape::Rounded);
        centralwidget = new QWidget(LoginWidget);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(3, 3, 3, 3);
        widget = new QWidget(centralwidget);
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
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(400, 400));
        label->setStyleSheet(QString::fromUtf8(""));
        label->setPixmap(QPixmap(QString::fromUtf8(":/res/ZYLoginPage.jpg")));
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
        verticalLayout_8 = new QVBoxLayout(widget_5);
        verticalLayout_8->setObjectName("verticalLayout_8");
        groupBox = new QGroupBox(widget_5);
        groupBox->setObjectName("groupBox");
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName("verticalLayout_4");
        usernameEdit = new QLineEdit(groupBox);
        usernameEdit->setObjectName("usernameEdit");
        usernameEdit->setInputMethodHints(Qt::InputMethodHint::ImhNone);

        verticalLayout_4->addWidget(usernameEdit);


        verticalLayout_8->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget_5);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        PasswordEdit = new QLineEdit(groupBox_2);
        PasswordEdit->setObjectName("PasswordEdit");
        PasswordEdit->setInputMethodHints(Qt::InputMethodHint::ImhNoAutoUppercase|Qt::InputMethodHint::ImhNoPredictiveText|Qt::InputMethodHint::ImhSensitiveData);
        PasswordEdit->setEchoMode(QLineEdit::EchoMode::PasswordEchoOnEdit);
        PasswordEdit->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        PasswordEdit->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);

        verticalLayout_5->addWidget(PasswordEdit);


        verticalLayout_8->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(widget_5);
        groupBox_3->setObjectName("groupBox_3");
        verticalLayout_6 = new QVBoxLayout(groupBox_3);
        verticalLayout_6->setObjectName("verticalLayout_6");
        StudentIDEdit = new QLineEdit(groupBox_3);
        StudentIDEdit->setObjectName("StudentIDEdit");

        verticalLayout_6->addWidget(StudentIDEdit);


        verticalLayout_8->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(widget_5);
        groupBox_4->setObjectName("groupBox_4");
        verticalLayout_7 = new QVBoxLayout(groupBox_4);
        verticalLayout_7->setObjectName("verticalLayout_7");
        SchoolNameEdit = new QLineEdit(groupBox_4);
        SchoolNameEdit->setObjectName("SchoolNameEdit");

        verticalLayout_7->addWidget(SchoolNameEdit);


        verticalLayout_8->addWidget(groupBox_4);


        verticalLayout_9->addWidget(widget_5);

        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName("widget_4");
        widget_4->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        verticalLayout_3 = new QVBoxLayout(widget_4);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(18, -1, 18, -1);
        LoginBtn = new QPushButton(widget_4);
        LoginBtn->setObjectName("LoginBtn");

        verticalLayout_3->addWidget(LoginBtn);

        registerBtn = new QPushButton(widget_4);
        registerBtn->setObjectName("registerBtn");

        verticalLayout_3->addWidget(registerBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_3->addItem(verticalSpacer);

        forgotBtn = new QPushButton(widget_4);
        forgotBtn->setObjectName("forgotBtn");

        verticalLayout_3->addWidget(forgotBtn);


        verticalLayout_9->addWidget(widget_4);


        horizontalLayout->addWidget(widget_3);

        horizontalLayout->setStretch(0, 7);
        horizontalLayout->setStretch(1, 3);

        horizontalLayout_2->addWidget(widget);

        LoginWidget->setCentralWidget(centralwidget);

        retranslateUi(LoginWidget);

        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWidget)
    {
        LoginWidget->setWindowTitle(QCoreApplication::translate("LoginWidget", "\346\214\207\345\260\226\351\200\220\345\205\211-\347\231\273\345\275\225", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("LoginWidget", "Fingertip-Light-Chase", nullptr));
        label_3->setText(QCoreApplication::translate("LoginWidget", "\346\214\207\345\260\226\351\200\220\345\205\211", nullptr));
        groupBox->setTitle(QCoreApplication::translate("LoginWidget", "Username", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("LoginWidget", "Enter Username", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("LoginWidget", "Password", nullptr));
        PasswordEdit->setInputMask(QString());
        PasswordEdit->setPlaceholderText(QCoreApplication::translate("LoginWidget", "Enter Password", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("LoginWidget", "Student ID", nullptr));
        StudentIDEdit->setPlaceholderText(QCoreApplication::translate("LoginWidget", "Enter Student ID", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("LoginWidget", "School", nullptr));
        SchoolNameEdit->setPlaceholderText(QCoreApplication::translate("LoginWidget", "Enter School Name", nullptr));
        LoginBtn->setText(QCoreApplication::translate("LoginWidget", "Login", nullptr));
        registerBtn->setText(QCoreApplication::translate("LoginWidget", "Register", nullptr));
        forgotBtn->setText(QCoreApplication::translate("LoginWidget", "Forgot Password?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
