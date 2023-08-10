#-------------------------------------------------
#
# Project created by QtCreator 2015-10-25T09:49:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calculates
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    calc.cpp \
    infixtopostfix.cpp \
    helpdialog.cpp

HEADERS  += mainwindow.h \
    calc.h \
    infixtopostfix.h \
    helpdialog.h

FORMS    += mainwindow.ui \
    helpdialog.ui

RESOURCES += \
    calcres.qrc

ICON = calcicon.icns
