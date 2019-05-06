#-------------------------------------------------
#
# Project created by QtCreator 2019-04-24T14:14:10
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MediaPlayer_v2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    mediaplayerwidget.cpp \
    controllerwidget.cpp \
    audiocontrollerstrategy.cpp \
    videocontrollerstrategy.cpp \
    mediahandler.cpp \
    audiohandler.cpp \
    videohandler.cpp \
    playlistwidget.cpp

HEADERS += \
        mainwindow.h \
    mediaplayerwidget.h \
    controllerwidget.h \
    controllerstrategy.h \
    audiocontrollerstrategy.h \
    videocontrollerstrategy.h \
    mediahandler.h \
    audiohandler.h \
    videohandler.h \
    playlistwidget.h

FORMS += \
        mainwindow.ui \
    mediaplayerwidget.ui \
    controllerwidget.ui \
    playlistwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
