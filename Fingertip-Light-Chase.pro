QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_PROJECT_DEPTH = 0

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cardperformance.cpp \
    cardwidget.cpp \
    databasemanager.cpp \
    main.cpp \
    loginwidget.cpp \
    mainwidget.cpp \
    registerwidget.cpp \
    retrievewidget.cpp \
    smtpclient.cpp \
    userdao.cpp \
    usermanager.cpp \
    userservice.cpp


HEADERS += \
    cardperformance.h \
    cardwidget.h \
    databasemanager.h \
    loginwidget.h \
    mainwidget.h \
    registerwidget.h \
    retrievewidget.h \
    smtpclient.h \
    userdao.h \
    usermanager.h \
    userservice.h


FORMS += \
    cardperformance.ui \
    loginwidget.ui \
    mainwidget.ui \
    registerwidget.ui \
    retrievewidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
