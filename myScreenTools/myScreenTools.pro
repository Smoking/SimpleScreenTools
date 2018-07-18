#-------------------------------------------------
#
# Project created by QtCreator 2018/7/18 by shengtu
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = myScreenTools
TEMPLATE = app


SOURCES += main.cpp\
        frmMain.cpp \
    myScreen.cpp \
    myInputDialog.cpp

HEADERS  += frmMain.h \
    myScreen.h \
    myInputDialog.h

FORMS    += frmMain.ui

RESOURCES += \
    myResource.qrc

MOC_DIR=temp/moc
RCC_DIR=temp/rcc
UI_DIR=temp/ui
OBJECTS_DIR=temp/obj

win32:RC_FILE=main.rc
