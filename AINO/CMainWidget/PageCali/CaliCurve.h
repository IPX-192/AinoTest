#ifndef CALICURVE_H
#define CALICURVE_H

#include <QWidget>

namespace Ui {
class CaliCurve;
}

class CaliCurve : public QWidget
{
    Q_OBJECT

public:
    explicit CaliCurve(QWidget *parent = nullptr);
    ~CaliCurve();

private:
    Ui::CaliCurve *ui;
};

#endif // CALICURVE_H
