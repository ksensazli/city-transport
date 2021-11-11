QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    buslines.cpp \
    busnew.cpp \
    busstops.cpp \
    ferrylines.cpp \
    ferrynew.cpp \
    ferrystops.cpp \
    main.cpp \
    mainwindow.cpp \
    metrolines.cpp \
    metronew.cpp \
    metrostops.cpp \
    operations.cpp \
    passenger.cpp

HEADERS += \
    buslines.h \
    busnew.h \
    busstops.h \
    ferrylines.h \
    ferrynew.h \
    ferrystops.h \
    mainwindow.h \
    metrolines.h \
    metronew.h \
    metrostops.h \
    operations.h \
    passenger.h

FORMS += \
    buslines.ui \
    busnew.ui \
    busstops.ui \
    ferrylines.ui \
    ferrynew.ui \
    ferrystops.ui \
    mainwindow.ui \
    metrolines.ui \
    metronew.ui \
    metrostops.ui \
    operations.ui \
    passenger.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
