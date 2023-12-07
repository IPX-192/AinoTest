#ifndef QCANALYSISTREND_H
#define QCANALYSISTREND_H

#include <QWidget>
#include "../../Components/Plot/qcustomplot.h"

namespace Ui {
class QCAnalysisTrend;
}

class QCAnalysisTrend : public QWidget
{
    Q_OBJECT

public:
    explicit QCAnalysisTrend(QWidget *parent = nullptr);
    ~QCAnalysisTrend();


signals:
    void sigQueryBtnClicked();
    void sigReturnBtnClicked();

private:
    Ui::QCAnalysisTrend *ui;
};

#endif // QCANALYSISTREND_H
