#include "CaliResTrend.h"
#include "ui_CaliResTrend.h"

CaliResTrend::CaliResTrend(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaliResTrend)
{
    ui->setupUi(this);
    QStringList list1 = { QString::fromLocal8Bit( "项目" )};
    QStringList list2 = { QString::fromLocal8Bit( "试剂批号" )};
    ui->tabView_Project->init( list1 );
    ui->tabView_Reagent->init(list2);
    createChart();
}

CaliResTrend::~CaliResTrend()
{
    delete ui;
}

void CaliResTrend::createChart()
{
    QChart *chart = new QChart();

    ui->chart_CaliTrend->setChart(chart);
    ui->chart_CaliTrend->setRenderHint(QPainter::Antialiasing);

    QLineSeries *series = new QLineSeries();
    //series->setName(u8"主曲线");
    //chart->addSeries(series);


    //    QPen    pen;
    //    pen.setStyle(Qt::DotLine);//Qt::SolidLine, Qt::DashLine, Qt::DotLine, Qt::DashDotLine
    //    pen.setWidth(3);
    //    pen.setColor(Qt::red);
    //    series->setPen(pen); //折线序列的线条设置

    //    chart->addSeries(series);


    QValueAxis *axisX = new QValueAxis;
    m_CurAxis=axisX; //当前坐标轴
    axisX->setRange(0, 30); //设置坐标轴范围
    axisX->setLabelFormat("%.1f"); //标签格式
    axisX->setTickCount(5); //主分隔个数
    axisX->setMinorTickCount(30);



    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0, 1000);

    axisY->setTickCount(5);
    axisY->setLabelFormat("%.2f"); //标签格式
    axisY->setMinorTickCount(8);

    chart->setAxisX(axisX, series); //添加X坐标轴

    chart->setAxisY(axisY, series); //添加Y坐标轴
}

void CaliResTrend::prepareData()
{

}

void CaliResTrend::updateFromChart()
{

}
