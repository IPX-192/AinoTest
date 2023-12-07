#ifndef QCCHARTTP_H
#define QCCHARTTP_H

#include <QWidget>
#include "../../Components/Plot/qcustomplot.h"

namespace Ui {
class QCChartTP;
}

class QCChartTP : public QWidget
{
    Q_OBJECT

public:
    explicit QCChartTP(QWidget *parent = nullptr);
    ~QCChartTP();


signals:
    void sigRefeshBtnClicked();
    void sigPrintBtnClilcked();
    void sigLJBtnClicked();

private:
    Ui::QCChartTP *ui;
};

#endif // QCCHARTTP_H
