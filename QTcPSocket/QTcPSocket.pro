QT += core
QT += network
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

TEMPLATE = app

SOURCES += main.cpp \
    tcptest.cpp

HEADERS += \
    tcptest.h
