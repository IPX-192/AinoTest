#ifndef QCCHARTLJ_H
#define QCCHARTLJ_H

#include <QWidget>
#include "../../Components/Plot/qcustomplot.h"

namespace Ui {
class QCChartLJ;
}

class QCChartLJ : public QWidget
{
    Q_OBJECT

public:
    explicit QCChartLJ(QWidget *parent = nullptr);
    ~QCChartLJ();

signals:
    void sigRefeshBtnClicked();
    void sigPrintBtnClilcked();
    void sigTPBtnClicked();


private:
    Ui::QCChartLJ *ui;
};

#endif // QCCHARTLJ_H
