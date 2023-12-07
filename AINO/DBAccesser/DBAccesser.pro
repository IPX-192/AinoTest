QT -= gui
QT += core sql

TEMPLATE = lib
DEFINES += DBACCESSER_LIBRARY

CONFIG += c++17

CONFIG( debug, debug | release ){
        DESTDIR     = $$PWD/../bin/debug
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
    DBAccesser.cpp \
    IQCDbAccesser.cpp

HEADERS += \
    DBAccesser_global.h \
    DBAccesser.h \
    IDBAccesser.h \
    IQCDbAccesser.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
