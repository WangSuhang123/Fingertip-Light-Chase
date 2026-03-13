/********************************************************************************
** Form generated from reading UI file 'PracticeSetupDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRACTICESETUPDIALOG_H
#define UI_PRACTICESETUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PracticeSetupDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *PracticeDialogWidegt;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBoxArticle;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QSpinBox *PracticeTimeBox;
    QLabel *label_2;
    QLabel *labelTip;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *PracticeOn;
    QPushButton *PracticeOff;

    void setupUi(QDialog *PracticeSetupDialog)
    {
        if (PracticeSetupDialog->objectName().isEmpty())
            PracticeSetupDialog->setObjectName("PracticeSetupDialog");
        PracticeSetupDialog->setWindowModality(Qt::WindowModality::ApplicationModal);
        PracticeSetupDialog->resize(280, 331);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PracticeSetupDialog->sizePolicy().hasHeightForWidth());
        PracticeSetupDialog->setSizePolicy(sizePolicy);
        PracticeSetupDialog->setMinimumSize(QSize(280, 300));
        PracticeSetupDialog->setMaximumSize(QSize(318, 331));
        verticalLayout_2 = new QVBoxLayout(PracticeSetupDialog);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        PracticeDialogWidegt = new QWidget(PracticeSetupDialog);
        PracticeDialogWidegt->setObjectName("PracticeDialogWidegt");
        verticalLayout_3 = new QVBoxLayout(PracticeDialogWidegt);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label = new QLabel(PracticeDialogWidegt);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font-family: \"Microsoft YaHei\";\n"
"font-weight: bold;\n"
"font-size: 30px;\n"
"letter-spacing: 10px;"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(label);

        widget_3 = new QWidget(PracticeDialogWidegt);
        widget_3->setObjectName("widget_3");
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(widget_3);
        groupBox->setObjectName("groupBox");
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        comboBoxArticle = new QComboBox(groupBox);
        comboBoxArticle->setObjectName("comboBoxArticle");
        comboBoxArticle->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(comboBoxArticle);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget_3);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        PracticeTimeBox = new QSpinBox(groupBox_2);
        PracticeTimeBox->setObjectName("PracticeTimeBox");
        PracticeTimeBox->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        PracticeTimeBox->setKeyboardTracking(true);
        PracticeTimeBox->setMinimum(1);
        PracticeTimeBox->setMaximum(50);
        PracticeTimeBox->setStepType(QAbstractSpinBox::StepType::AdaptiveDecimalStepType);
        PracticeTimeBox->setValue(1);

        verticalLayout_4->addWidget(PracticeTimeBox);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font-family: \"Microsoft YaHei\";\n"
"font-size: 12px;\n"
"color: rgb(159, 159, 159);\n"
""));
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_4->addWidget(label_2);


        verticalLayout->addWidget(groupBox_2);


        verticalLayout_3->addWidget(widget_3);

        labelTip = new QLabel(PracticeDialogWidegt);
        labelTip->setObjectName("labelTip");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelTip->sizePolicy().hasHeightForWidth());
        labelTip->setSizePolicy(sizePolicy1);
        labelTip->setMaximumSize(QSize(270, 11));
        labelTip->setStyleSheet(QString::fromUtf8("font-family: \"Microsoft YaHei\";\n"
"font-size: 12px;\n"
"color: rgb(159, 159, 159);"));
        labelTip->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_3->addWidget(labelTip);

        widget_2 = new QWidget(PracticeDialogWidegt);
        widget_2->setObjectName("widget_2");
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        PracticeOn = new QPushButton(widget_2);
        PracticeOn->setObjectName("PracticeOn");

        horizontalLayout_4->addWidget(PracticeOn);

        PracticeOff = new QPushButton(widget_2);
        PracticeOff->setObjectName("PracticeOff");

        horizontalLayout_4->addWidget(PracticeOff);


        verticalLayout_3->addWidget(widget_2);


        verticalLayout_2->addWidget(PracticeDialogWidegt);


        retranslateUi(PracticeSetupDialog);

        QMetaObject::connectSlotsByName(PracticeSetupDialog);
    } // setupUi

    void retranslateUi(QDialog *PracticeSetupDialog)
    {
        PracticeSetupDialog->setWindowTitle(QCoreApplication::translate("PracticeSetupDialog", "\346\211\223\345\255\227\347\273\203\344\271\240", nullptr));
        label->setText(QCoreApplication::translate("PracticeSetupDialog", "\345\274\200\345\247\213\350\256\255\347\273\203", nullptr));
        groupBox->setTitle(QCoreApplication::translate("PracticeSetupDialog", "\351\200\211\346\213\251\346\226\207\347\253\240\357\274\232", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("PracticeSetupDialog", "\347\273\203\344\271\240\346\227\266\351\225\277\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("PracticeSetupDialog", "\357\274\2101~50\345\210\206\351\222\237\357\274\211", nullptr));
        labelTip->setText(QCoreApplication::translate("PracticeSetupDialog", "\346\263\250\357\274\232\347\202\271\345\207\273\345\274\200\345\247\213\345\220\216\345\215\263\345\210\273\345\274\200\345\247\213\350\256\241\346\227\266\357\274\201", nullptr));
        PracticeOn->setText(QCoreApplication::translate("PracticeSetupDialog", "\345\274\200\345\247\213", nullptr));
        PracticeOff->setText(QCoreApplication::translate("PracticeSetupDialog", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PracticeSetupDialog: public Ui_PracticeSetupDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRACTICESETUPDIALOG_H
