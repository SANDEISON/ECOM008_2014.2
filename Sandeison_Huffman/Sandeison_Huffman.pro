#-------------------------------------------------
#
# Project created by QtCreator 2014-11-03T23:05:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sandeison_Huffman
TEMPLATE = app


SOURCES += main.cpp\
        view.cpp \
    compress.cpp \
    decompress.cpp

HEADERS  += view.h \
    compress.h \
    decompress.h

FORMS    += view.ui