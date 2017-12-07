#-------------------------------------------------
#
# Project created by QtCreator 2017-12-04T15:23:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = i18n_ex
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        src/main.cpp \
        src/widget.cpp

HEADERS += \
        src/widget.h

FORMS += \
    form.ui

TRANSLATIONS += i18n.pt_BR.ts
