#include "CusLineChartWidget.h"
#include "ui_CusLineChartWidget.h"

CusLineChartWidget::CusLineChartWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CusLineChartWidget)
{
    ui->setupUi(this);
    test();

    //    QVector<double> x(101), y(101);
    //    for (int i=0; i<101; ++i)
    //    {
    //        x[i] = i;
    //        y[i] = generateRadomBunber();
    //    }

    //    ui->PlotWidget->addGraph();
    //    ui->PlotWidget->graph( 0 )->setData( x, y );
    //    ui->PlotWidget->xAxis->setLabel("x");
    //    ui->PlotWidget->yAxis->setLabel("y");
    //    ui->PlotWidget->rescaleAxes();
}

CusLineChartWidget::~CusLineChartWidget()
{
    delete ui;
}

void CusLineChartWidget::generateGraph(const CAxisDatasPair &dataPair, const CAxisLabelsPair &labelPair)
{
    auto &&[ x, y ]           = dataPair;
    auto &&[ xLabel, yLabel ] = labelPair;

    QColor color(rand()%128,rand()%256,rand()%256);
    QPen pen( color );

    int index = ui->PlotWidget->graphCount();
    ui->PlotWidget->addGraph();
    QCPGraph *curGraph = ui->PlotWidget->graph( index );
    curGraph->setData( x, y );
    curGraph->setPen( pen );

    if( index <= 2 ){
        curGraph->setVisible( false );
    }


    ui->PlotWidget->xAxis->setLabel( xLabel );
    ui->PlotWidget->yAxis->setLabel( yLabel );
    ui->PlotWidget->rescaleAxes();
    ui->PlotWidget->replot();
}

void CusLineChartWidget::generateTargetColorGraph(const CAxisDatasPair &dataPair, const CAxisLabelsPair &labelPair, const QColor &color)
{
    auto &&[ x, y ]           = dataPair;
    auto &&[ xLabel, yLabel ] = labelPair;

    QPen pen( color );

    int index = ui->PlotWidget->graphCount();
    ui->PlotWidget->addGraph();
    QCPGraph *curGraph = ui->PlotWidget->graph( index );
    curGraph->setData( x, y );
    curGraph->setPen( pen );

    ui->PlotWidget->xAxis->setLabel( xLabel );
    ui->PlotWidget->yAxis->setLabel( yLabel );
    ui->PlotWidget->rescaleAxes();
    ui->PlotWidget->replot();
}

int CusLineChartWidget::generateRadomBunber()
{
    int randomNumber = QRandomGenerator::global()->bounded(100);
    return randomNumber;
}

CAxisDatasPair CusLineChartWidget::generateRandomDataPair()
{
    constexpr int size = 10;
    QVector<double> x(size), y(size);
    for (int i=0; i<size; ++i)
    {
        x[i] = i;
        y[i] = generateRadomBunber();
    }

    return CAxisDatasPair( x, y );
}

void CusLineChartWidget::test()
{
    auto randomDatas1 = generateRandomDataPair();
    generateTargetColorGraph( randomDatas1, { "X", "Y" }, { "red" } );

    auto randomDatas2 = generateRandomDataPair();
    generateTargetColorGraph( randomDatas2, { "X", "Y" }, { "green" } );
}

