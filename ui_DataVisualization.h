/********************************************************************************
** Form generated from reading UI file 'DataVisualization.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAVISUALIZATION_H
#define UI_DATAVISUALIZATION_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataVisualizationClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *titlewidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_8;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QChartView *WPMChartView;
    QChartView *accuracyChartView;
    QChartView *finalScorehartView;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QTableView *recentComtableView;
    QChartView *fontChartView;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_7;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QChartView *PracticeWPMChartView;
    QChartView *PraceticeaccuracyChartView;
    QChartView *PraceticefinalScorehartView;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_6;
    QTableView *PracticerecentComtableView;
    QChartView *PracticefontChartView;

    void setupUi(QMainWindow *DataVisualizationClass)
    {
        if (DataVisualizationClass->objectName().isEmpty())
            DataVisualizationClass->setObjectName("DataVisualizationClass");
        DataVisualizationClass->setWindowModality(Qt::WindowModality::ApplicationModal);
        DataVisualizationClass->resize(939, 654);
        centralWidget = new QWidget(DataVisualizationClass);
        centralWidget->setObjectName("centralWidget");
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        titlewidget = new QWidget(centralWidget);
        titlewidget->setObjectName("titlewidget");
        horizontalLayout = new QHBoxLayout(titlewidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(titlewidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 700 28pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label);


        verticalLayout_2->addWidget(titlewidget);

        widget_7 = new QWidget(centralWidget);
        widget_7->setObjectName("widget_7");
        horizontalLayout_8 = new QHBoxLayout(widget_7);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(widget_7);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setStyleSheet(QString::fromUtf8("font: 700 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        tabWidget->setTabPosition(QTabWidget::TabPosition::North);
        tabWidget->setTabShape(QTabWidget::TabShape::Rounded);
        tab = new QWidget();
        tab->setObjectName("tab");
        horizontalLayout_4 = new QHBoxLayout(tab);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(tab);
        widget->setObjectName("widget");
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        WPMChartView = new QChartView(widget_2);
        WPMChartView->setObjectName("WPMChartView");
        WPMChartView->setDragMode(QGraphicsView::DragMode::NoDrag);

        horizontalLayout_2->addWidget(WPMChartView);

        accuracyChartView = new QChartView(widget_2);
        accuracyChartView->setObjectName("accuracyChartView");

        horizontalLayout_2->addWidget(accuracyChartView);

        finalScorehartView = new QChartView(widget_2);
        finalScorehartView->setObjectName("finalScorehartView");

        horizontalLayout_2->addWidget(finalScorehartView);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName("widget_3");
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        recentComtableView = new QTableView(widget_3);
        recentComtableView->setObjectName("recentComtableView");

        horizontalLayout_3->addWidget(recentComtableView);

        fontChartView = new QChartView(widget_3);
        fontChartView->setObjectName("fontChartView");

        horizontalLayout_3->addWidget(fontChartView);

        horizontalLayout_3->setStretch(0, 67);
        horizontalLayout_3->setStretch(1, 33);

        verticalLayout->addWidget(widget_3);


        horizontalLayout_4->addWidget(widget);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        horizontalLayout_7 = new QHBoxLayout(tab_2);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        widget_4 = new QWidget(tab_2);
        widget_4->setObjectName("widget_4");
        verticalLayout_3 = new QVBoxLayout(widget_4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName("widget_5");
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        PracticeWPMChartView = new QChartView(widget_5);
        PracticeWPMChartView->setObjectName("PracticeWPMChartView");

        horizontalLayout_5->addWidget(PracticeWPMChartView);

        PraceticeaccuracyChartView = new QChartView(widget_5);
        PraceticeaccuracyChartView->setObjectName("PraceticeaccuracyChartView");

        horizontalLayout_5->addWidget(PraceticeaccuracyChartView);

        PraceticefinalScorehartView = new QChartView(widget_5);
        PraceticefinalScorehartView->setObjectName("PraceticefinalScorehartView");

        horizontalLayout_5->addWidget(PraceticefinalScorehartView);


        verticalLayout_3->addWidget(widget_5);

        widget_6 = new QWidget(widget_4);
        widget_6->setObjectName("widget_6");
        horizontalLayout_6 = new QHBoxLayout(widget_6);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        PracticerecentComtableView = new QTableView(widget_6);
        PracticerecentComtableView->setObjectName("PracticerecentComtableView");

        horizontalLayout_6->addWidget(PracticerecentComtableView);

        PracticefontChartView = new QChartView(widget_6);
        PracticefontChartView->setObjectName("PracticefontChartView");

        horizontalLayout_6->addWidget(PracticefontChartView);

        horizontalLayout_6->setStretch(0, 67);
        horizontalLayout_6->setStretch(1, 33);

        verticalLayout_3->addWidget(widget_6);


        horizontalLayout_7->addWidget(widget_4);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout_8->addWidget(tabWidget);


        verticalLayout_2->addWidget(widget_7);

        DataVisualizationClass->setCentralWidget(centralWidget);

        retranslateUi(DataVisualizationClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DataVisualizationClass);
    } // setupUi

    void retranslateUi(QMainWindow *DataVisualizationClass)
    {
        DataVisualizationClass->setWindowTitle(QCoreApplication::translate("DataVisualizationClass", "DataVisualization", nullptr));
        label->setText(QCoreApplication::translate("DataVisualizationClass", "\346\225\260\346\215\256\345\217\257\350\247\206\345\214\226", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("DataVisualizationClass", "\346\257\224\350\265\233", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("DataVisualizationClass", "\347\273\203\344\271\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataVisualizationClass: public Ui_DataVisualizationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAVISUALIZATION_H
