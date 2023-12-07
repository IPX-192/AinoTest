#ifndef PAGEMAIN_H
#define PAGEMAIN_H

#include <QWidget>
#include "OperationGuide.h"

namespace Ui {
class PageMain;
}

class PageMain : public QWidget
{
    Q_OBJECT

public:
    explicit PageMain(QWidget *parent = 0);
    ~PageMain();

private:
    Ui::PageMain *ui;
};

#endif // PAGEMAIN_H
