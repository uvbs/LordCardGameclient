#-------------------------------------------------
#
# Project created by QtCreator 2015-08-25T15:36:00
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += network
QT       +=phonon
TARGET = Project
TEMPLATE = app


SOURCES += main.cpp\
    entry.cpp \
    login.cpp \
    player.cpp \
    trans.cpp \
    checkguest.cpp \
    roomchoser.cpp \
    game.cpp \
    hand.cpp \
    cards.cpp \
    cardpic.cpp \
    chatroom.cpp \
    mysql.cpp \
    winboard.cpp

HEADERS  += entry.h \
    login.h \
    player.h \
    trans.h \
    checkguest.h \
    roomchoser.h \
    game.h \
    hand.h \
    cards.h \
    cardpic.h \
    chatroom.h \
    mysql.h \
    winboard.h

FORMS    += entry.ui \
    login.ui \
    trans.ui \
    roomchoser.ui \
    game.ui \
    chatroom.ui \
    winboard.ui

RESOURCES += \
    res.qrc

RC_FILE += myico.rc
