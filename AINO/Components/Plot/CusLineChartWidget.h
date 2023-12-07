#ifndef CUSLINECHARTWIDGET_H
#define CUSLINECHARTWIDGET_H

#include <QWidget>
#include "Components_global.h"
#include "qcustomplot.h"

namespace Ui {
class CusLineChartWidget;
}

using CAxisDatasPair  = std::pair< QVector<double>, QVector<double> >;
using CAxisLabelsPair = std::pair< QString, QString >;

class COMPONENTS_EXPORT CusLineChartWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CusLineChartWidget(QWidget *parent = nullptr);
    ~CusLineChartWidget();

    void generateGraph( const CAxisDatasPair &dataPair, const CAxisLabelsPair &labelPair );
    void generateTargetColorGraph( const CAxisDatasPair &dataPair, const CAxisLabelsPair &labelPair, const QColor &color );


private:
    int generateRadomBunber();
    CAxisDatasPair generateRandomDataPair();

    void test();

private:
    Ui::CusLineChartWidget *ui;
};

#endif // CUSLINECHARTWIDGET_H
