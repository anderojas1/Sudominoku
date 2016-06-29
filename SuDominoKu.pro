#-------------------------------------------------
#
# Project created by QtCreator 2016-06-27T17:27:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SuDominoKu
TEMPLATE = app


SOURCES += main.cpp\
        sudominoku.cpp \
    coordenada.cpp

HEADERS  += sudominoku.hpp \
    coordenada.hpp

FORMS    += sudominoku.ui
