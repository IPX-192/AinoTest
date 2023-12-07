#ifndef CUSCLOCKTIMEADJUST_H
#define CUSCLOCKTIMEADJUST_H

#include <QWidget>
#include "Components_global.h"

namespace Ui {
class CusClockTimeAdjust;
}

class COMPONENTS_EXPORT CusClockTimeAdjust : public QWidget
{
    Q_OBJECT

public:
    explicit CusClockTimeAdjust(QWidget *parent = nullptr);
    ~CusClockTimeAdjust();

    QString getClockTime() const;

private:
    Ui::CusClockTimeAdjust *ui;
};

#endif // CUSCLOCKTIMEADJUST_H
