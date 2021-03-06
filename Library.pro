#-------------------------------------------------
#
# Project created by QtCreator 2018-10-22T19:15:36
#
#-------------------------------------------------

QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Library
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
    addbookwindow.cpp \
    book.cpp \
    findbookwindow.cpp \
    bookwindow.cpp \
    librarydb.cpp \
    addinstanceswindow.cpp \
    reader.cpp \
    addreaderwindow.cpp \
    findreaderwindow.cpp \
    readerwindow.cpp \
    givebookwindow.cpp \
    returnbookwindow.cpp \
    deleteinstanceswindow.cpp

HEADERS += \
        mainwindow.h \
    addbookwindow.h \
    book.h \
    findbookwindow.h \
    bookwindow.h \
    librarydb.h \
    addinstanceswindow.h \
    reader.h \
    addreaderwindow.h \
    findreaderwindow.h \
    readerwindow.h \
    givebookwindow.h \
    returnbookwindow.h \
    deleteinstanceswindow.h

FORMS += \
        mainwindow.ui \
    addbookwindow.ui \
    findbookwindow.ui \
    bookwindow.ui \
    addinstanceswindow.ui \
    addreaderwindow.ui \
    findreaderwindow.ui \
    readerwindow.ui \
    givebookwindow.ui \
    returnbookwindow.ui \
    deleteinstanceswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
