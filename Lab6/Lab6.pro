QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    logic/cardsdeck.cpp \
    logic/cardshands.cpp \
    logic/enemycomputer.cpp \
    logic/fileworker.cpp \
    logic/gameboard.cpp \
    main.cpp \
    logic/printercards.cpp \
    windows/gamewindow.cpp \
    windows/mainwindow.cpp \
    windows/presettingwindow.cpp \
    windows/savewindow.cpp \
    windows/windowrank.cpp \
    windows/windowrules.cpp \
    windows/windowsuit.cpp \
    windows/windowsworker.cpp

HEADERS += \
    logic/cardsdeck.h \
    logic/cardshands.h \
    logic/enemycomputer.h \
    logic/fileworker.h \
    logic/gameboard.h \
    logic/printercards.h \
    windows/gamewindow.h \
    windows/mainwindow.h \
    windows/presettingwindow.h \
    windows/savewindow.h \
    windows/windowrank.h \
    windows/windowrules.h \
    windows/windowsuit.h \
    windows/windowsworker.h

FORMS += \
    windows/gamewindow.ui \
    windows/mainwindow.ui \
    windows/presettingwindow.ui \
    windows/savewindow.ui \
    windows/windowrank.ui \
    windows/windowrules.ui \
    windows/windowsuit.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
