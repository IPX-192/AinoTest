QT       += core gui widgets sql charts printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

include( $$PWD/PageLogin/PageLogin.pri )
include( $$PWD/PageScreenProtection/PageScreenProtection.pri )
include( $$PWD/PageMain/PageMain.pri )
include( $$PWD/PageQC/PageQC.pri )
include( $$PWD/PageCali/PageCali.pri )


INCLUDEPATH += $$PWD/../Components/
INCLUDEPATH += $$PWD/../Components/Table
INCLUDEPATH += $$PWD/../Components/FlowLayoutArea
INCLUDEPATH += $$PWD/../Components/ComComponents
INCLUDEPATH += $$PWD/../Components/Plot

INCLUDEPATH += $$PWD/../DBAccesser/
INCLUDEPATH += $$PWD/../Components/
INCLUDEPATH += $$PWD/PageQC/
INCLUDEPATH += $$PWD/PageCali/

CONFIG( debug, debug | release ){
        DESTDIR     = $$PWD/../bin/debug
        LIBS       += -L$$DESTDIR/ -lDBAccesser \
                                   -lComponents


        MOC_DIR     = $$PWD/bin/debug/temp/moc
        RCC_DIR     = $$PWD/bin/debug/temp/rcc
        UI_DIR      = $$PWD/bin/debug/temp/ui
        OBJECTS_DIR = $$PWD/bin/debug/temp/obj
}else
{
        DESTDIR     = $$PWD/../bin/release
        MOC_DIR     = $$PWD/bin/release/temp/moc
        RCC_DIR     = $$PWD/bin/release/temp/rcc
        UI_DIR      = $$PWD/bin/release/temp/ui
        OBJECTS_DIR = $$PWD/bin/release/temp/obj
}

SOURCES += \
    main.cpp \
    MainWindow.cpp \
    CSystemInfoBar.cpp

HEADERS += \
    MainWindow.h \
    CSystemInfoBar.h \
    commondefine.h

FORMS += \
    MainWindow.ui \
    CSystemInfoBar.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
