QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cardsdeck.cpp \
    cardshands.cpp \
    gameboard.cpp \
    gamewindow.cpp \
    main.cpp \
    mainwindow.cpp \
    presettingwindow.cpp \
    printercards.cpp \
    windowrank.cpp \
    windowsuit.cpp

HEADERS += \
    cardsdeck.h \
    cardshands.h \
    gameboard.h \
    gamewindow.h \
    mainwindow.h \
    presettingwindow.h \
    printercards.h \
    windowrank.h \
    windowsuit.h

FORMS += \
    gamewindow.ui \
    mainwindow.ui \
    presettingwindow.ui \
    windowrank.ui \
    windowsuit.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
