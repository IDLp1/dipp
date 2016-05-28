#-------------------------------------------------
#
# Project created by QtCreator 2016-05-19T13:59:50
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = diplom3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialogsetup.cpp \
    user.cpp \
    dialogsendfile.cpp

HEADERS  += mainwindow.h \
    dialogsetup.h \
    main.h \
    user.h \
    dialogsendfile.h

FORMS    += mainwindow.ui \
    dialogsetup.ui \
    dialogsendfile.ui

RESOURCES += \
    resource.qrc
