#include "loginwidget.h"
#include "mainwidget.h"
#include "practicewidget.h"
#include "settlementdialog.h"
#include "databasemanager.h"
#include "CompetitionLobbyWidget.h"
#include "CompetitionPublish.h"
#include <QApplication>
#include <QFile>
#include "LeaderboardFeature.h"
//#include <QSslSocket>
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

    /*qDebug() << QSslSocket::supportsSsl();
    qDebug() << QSslSocket::supportsSsl();
    qDebug() << QSslSocket::sslLibraryBuildVersionString();
    qDebug() << QSslSocket::sslLibraryVersionString();*/

    /*qputenv("QT_DEBUG_PLUGINS", "1");

    qDebug() << QCoreApplication::libraryPaths();*/

     /*LoginWidget w;
     w.show();*/
     /*MainWidget mw;
     mw.show();*/
    LeaderboardFeature lf;
    lf.show();


    return a.exec();
}
