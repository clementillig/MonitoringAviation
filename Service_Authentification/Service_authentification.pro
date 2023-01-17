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
    placeholder.cpp \
    creer_un_compte.cpp

HEADERS  += mainwindow.h \
    placeholder.h \
    creer_un_compte.h

FORMS    += mainwindow.ui \
    placeholder.ui \
    creer_un_compte.ui

RESOURCES += \
    resources.qrc \
    dashboard_icons.qrc
