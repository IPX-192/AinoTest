#include "UnitComponentTest.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UnitComponentTest w;
    w.show();
    return a.exec();
}
