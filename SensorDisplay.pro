#-------------------------------------------------
#
# Project created by QtCreator 2013-01-06T17:07:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4) {
    QT *= printsupport
}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SensorDisplay
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    fileparser.cpp \
    sensorvalue.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    fileparser.h \
    sensorvalue.h \
    qcustomplot.h

FORMS    += mainwindow.ui
