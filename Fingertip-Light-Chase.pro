QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_PROJECT_DEPTH = 0

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    articledao.cpp \
    articleservice.cpp \
    cardperformance.cpp \
    cardwidget.cpp \
    clockservice.cpp \
    clockworker.cpp \
    databasemanager.cpp \
    fontservice.cpp \
    fontworker.cpp \
    main.cpp \
    loginwidget.cpp \
    mainwidget.cpp \
    practicesetupdialog.cpp \
    practicewidget.cpp \
    registerwidget.cpp \
    retrievewidget.cpp \
    smtpclient.cpp \
    timeservice.cpp \
    timeworker.cpp \
    userdao.cpp \
    usermanager.cpp \
    userservice.cpp


HEADERS += \
    Article.h \
    NoCopyPasteLineEdit.h \
    articledao.h \
    articleservice.h \
    cardperformance.h \
    cardwidget.h \
    clockservice.h \
    clockworker.h \
    databasemanager.h \
    fontservice.h \
    fontworker.h \
    loginwidget.h \
    mainwidget.h \
    practicesetupdialog.h \
    practicewidget.h \
    registerwidget.h \
    retrievewidget.h \
    smtpclient.h \
    timeservice.h \
    timeworker.h \
    userdao.h \
    usermanager.h \
    userservice.h


FORMS += \
    PracticeSetupDialog.ui \
    cardperformance.ui \
    loginwidget.ui \
    mainwidget.ui \
    practicewidget.ui \
    registerwidget.ui \
    retrievewidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
