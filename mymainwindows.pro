QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mymainwindows
TEMPLATE = app

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DEFINES += QT_DEPRECATED_WARNINGS
SOURCES += \
    coinbutton.cpp \
    dataconfig.cpp \
    levelselectscene.cpp \
    main.cpp \
    mainwindow.cpp \
    mypushbutton.cpp \
    playscene.cpp \
    startscene.cpp

HEADERS += \
    coinbutton.h \
    dataconfig.h \
    levelselectscene.h \
    mainwindow.h \
    mypushbutton.h \
    playscene.h \
    startscene.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    res.qrc



