#include "loginwidget.h"
#include "mainwidget.h"
#include "databasemanager.h"
#include <QApplication>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //打开数据库
    DatabaseManager::instance().openDatabase();

    // 引入 qss 样式表（资源路径）
    QFile qss(":/res/ant.qss");
    if (qss.open(QFile::ReadOnly)) {
        a.setStyleSheet(qss.readAll());
        qss.close();
    }
    // LoginWidget w;
    // w.show();
    // CardPerformance cp;
    // cp.show();
    MainWidget mw;
    mw.show();
    return a.exec();
}
