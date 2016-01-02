#-------------------------------------------------
#
# Project created by QtCreator 2015-12-31T00:33:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AddressBook
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    info.cpp \
    form.cpp

HEADERS  += widget.h \
    info.h \
    contacts.h \
    form.h

FORMS    += widget.ui \
    form.ui
