#-------------------------------------------------
#
# Project created by QtCreator 2016-12-06T19:30:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Intuitive
TEMPLATE = app

RC_FILE = app.rc

SOURCES += main.cpp\
        mwnd.cpp \
    gui/status.cpp \
    3Dmouse/mousedata.cpp \
    3Dmouse/mousehandler.cpp \
    3Dmouse/snapi.cpp \
    vrep/setup.cpp \
    vrep/simdata.cpp \
    vrep/simhandler.cpp \
    vrep/vrapi.cpp \
    vrep/remoteApi/extApi.c \
    vrep/remoteApi/extApiPlatform.c \
    gui/rawdatagroup.cpp \
    gui/hgui.cpp \
    gui/vstream.cpp \
    setwnd.cpp \
    graphwnd.cpp \
    qcustomplot.cpp \
    aboutwnd.cpp

HEADERS  += mwnd.h \
    gui/status.h \
    3Dmouse/mousedata.h \
    3Dmouse/mousehandler.h \
    3Dmouse/snapi.h \
    vrep/setup.h \
    vrep/simdata.h \
    vrep/simhandler.h \
    vrep/vrapi.h \
    vrep/vrepstructs.h \
    vrep/remoteApi/extApi.h \
    vrep/remoteApi/extApiInternal.h \
    vrep/remoteApi/extApiPlatform.h \
    vrep/include/v_repConst.h \
    vrep/include/v_repLib.h \
    vrep/include/v_repTypes.h \
    gui/rawdatagroup.h \
    gui/hgui.h \
    gui/vstream.h \
    setwnd.h \
    graphwnd.h \
    qcustomplot.h \
    aboutwnd.h

FORMS    += mwnd.ui \
    setwnd.ui \
    graphwnd.ui \
    aboutwnd.ui

RESOURCES += \
    resources.qrc
