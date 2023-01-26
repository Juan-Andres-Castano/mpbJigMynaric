QT       += core gui
QT += widgets serialport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    candictionary.cpp \
    comunicationthread.cpp \
    dictionaryutils.cpp \
    lib_crc16.cpp \
    main.cpp \
    mainwindow.cpp \
    mpbpacker.cpp \
    mpbparser.cpp

HEADERS += \
    LaserDiodeBeam.h \
    candictionary.h \
    comunicationthread.h \
    dictionaryutils.h \
    lib_crc16.h \
    mainStateMachine.h \
    mainwindow.h \
    mpbLibs.h \
    mpbLogEvent.h \
    mpbpacker.h \
    mpbparser.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    fta_power.qrc \
    fta_temp_1.qrc
