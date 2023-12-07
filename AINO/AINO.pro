TEMPLATE = subdirs

SUBDIRS += \
    Components \
    DBAccesser  \
    CMainWidget \
    UnitTest/UnitTest


    CMainWidget.depends = DBAccesser
    CMainWidget.depends = Components
    UnitTest.depends = Components

