#-------------------------------------------------
#
# Project created by QtCreator 2016-11-21T12:05:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = v-rep_comm
TEMPLATE = app


SOURCES += main.cpp\
        mainwnd.cpp \
    vrapi.cpp \
    simhandler.cpp \
    remoteApi/extApi.c \
    remoteApi/extApiPlatform.c \
    setup.cpp \
    simdata.cpp

HEADERS  += mainwnd.h \
    vrapi.h \
    simhandler.h \
    include/_dirent.h \
    include/luaFunctionData.h \
    include/luaFunctionDataItem.h \
    include/scriptFunctionData.h \
    include/scriptFunctionDataItem.h \
    include/socketInConnection.h \
    include/socketOutConnection.h \
    include/v_repConst.h \
    include/v_repLib.h \
    include/v_repTypes.h \
    remoteApi/extApi.h \
    remoteApi/extApiInternal.h \
    remoteApi/extApiPlatform.h \
    setup.h \
    simdata.h \
    vrepstructs.h

FORMS    += mainwnd.ui
