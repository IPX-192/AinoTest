QT       += core gui widgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH += $$PWD/../../Components/
INCLUDEPATH += $$PWD/../../Components/Table
INCLUDEPATH += $$PWD/../../Components/FlowLayoutArea
INCLUDEPATH += $$PWD/../../Components/ComComponents
INCLUDEPATH += $$PWD/../../Components/Plot

CONFIG( debug, debug | release ){
    DESTDIR = $$PWD/bin/Debug
    LIBS += -L$$PWD/../../bin/debug -lComponents

}

CONFIG( release, debug | release ){
    DESTDIR = $$PWD/bin/Release
}

SOURCES += \
    main.cpp \
    UnitComponentTest.cpp

HEADERS += \
    UnitComponentTest.h

FORMS += \
    UnitComponentTest.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
