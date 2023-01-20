#-------------------------------------------------
#
# Project created by QtCreator 2023-01-11T17:38:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = Service_authentification
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    creer_un_compte.cpp \
    placeholder.cpp

HEADERS  += mainwindow.h \
    creer_un_compte.h \
    placeholder.h

FORMS    += mainwindow.ui \
    creer_un_compte.ui \
    placeholder.ui

RESOURCES += \
    dashboard_icons.qrc \
    resources.qrc
