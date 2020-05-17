#-------------------------------------------------
#
# Project created by Bogdan Volokhonenko K-28
#
#-------------------------------------------------

QT       += core gui
QT       += core gui multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = CountdownTimer
TEMPLATE = app

SOURCES += main.cpp\
        countdowntimer.cpp \
        othersclock.cpp \
        otherwindows.cpp

HEADERS  += countdowntimer.h \
    othersclock.h \
    otherwindows.h

FORMS    += countdowntimer.ui \
    othersclock.ui \
    otherwindows.ui

RC_ICONS += clock.ico

RESOURCES += \
    audio.qrc
