#include "loginwidget.h"
#include "mainwidget.h"
#include "practicesetupdialog.h"
#include "practicewidget.h"
#include "settlementdialog.h"
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

    /*qputenv("QT_DEBUG_PLUGINS", "1");

    qDebug() << QCoreApplication::libraryPaths();*/

    // LoginWidget w;
    // w.show();
    /*PracticeSetupDialog psd;
    psd.show();*/
    // PracticeWidget pw;
    // pw.show();
    /*settlementDialog sd;
    sd.show();*/
     MainWidget mw;
     mw.show();
    return a.exec();
}
