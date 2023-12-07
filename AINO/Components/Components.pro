QT -= gui

QT += core gui widgets printsupport


TEMPLATE = lib
DEFINES += COMPONENTS_LIBRARY

CONFIG += c++17

include( $$PWD/Table/Table.pri )
include( $$PWD/FlowLayoutArea/FlowLayoutArea.pri )
include( $$PWD/ComComponents/ComComponents.pri )
include( $$PWD/Plot/Plot.pri )


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
    Components.cpp

HEADERS += \
    CommonStyleSheets.h \
    Components_global.h \
    Components.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resouces.qrc
