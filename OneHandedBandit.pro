TEMPLATE = app
QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11

SOURCES += main.cpp \
    fieldwidget.cpp \
    scorelabel.cpp \
    userinterface.cpp

RESOURCES += \
    images.qrc

HEADERS += \
    fieldwidget.h \
    scorelabel.h \
    userinterface.h
