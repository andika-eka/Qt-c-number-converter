#-------------------------------------------------
#
# Project created by QtCreator 2019-12-09T14:11:42
#
#-------------------------------------------------

QT       += core gui

TARGET = NUMBER_CONVERTER
TEMPLATE = app
RC_FILE = myapp.rc

SOURCES += main.cpp\
        number_converter.cpp \
    decimalwindow.cpp \
    binarywindow.cpp \
    hexadecimalwindow.cpp \
    octalwindow.cpp

HEADERS  += number_converter.h \
    decimalwindow.h \
    binarywindow.h \
    hexadecimalwindow.h \
    octalwindow.h \
    used_function.h \
    used_function8.h \
    used_function2.h \
    used_function16.h

FORMS    += number_converter.ui \
    decimalwindow.ui \
    binarywindow.ui \
    hexadecimalwindow.ui \
    octalwindow.ui
