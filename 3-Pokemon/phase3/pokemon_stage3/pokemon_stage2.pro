QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Server.cpp \
    battle.cpp \
    changeUi.cpp \
    getnewpokemon.cpp \
    main.cpp \
    client.cpp \
    mainUi.cpp \
    pokemon.cpp \
    pokemonsubtype.cpp \
    rule.cpp \
    signInSignUp.cpp \
    uiDesign.cpp

HEADERS += \
    Server.h \
    client.h \
    getnewpokemon.h \
    pokemon.h \
    pokemonsubtype.h \
    rule.h

FORMS += \
    client.ui \
    getnewpokemon.ui \
    rule.ui \
    tmp.ui \
    ui1.ui \
    ui2.ui \
    ui3.ui \
    ui4.ui \
    ui5.ui \
    ui6.ui \
    ui7.ui \
    ui8.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
