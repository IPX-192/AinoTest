#include "PopCheckCaliCurve.h"
#include "ui_PopCheckCaliCurve.h"

PopCheckCaliCurve::PopCheckCaliCurve(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PopCheckCaliCurve)
{
    ui->setupUi(this);

    QStringList list = { QString::fromLocal8Bit( "水平" ), QString::fromLocal8Bit( "信号值" ),  QString::fromLocal8Bit( "浓度值" )};
    ui->tableView_CheckCurve->init( list );

    connect( ui->btn_CheckCurveCancle,&QPushButton::clicked, this, &PopCheckCaliCurve::sigCheckCaliCurve );

    createChart();//创建图表
}

PopCheckCaliCurve::~PopCheckCaliCurve()
{
    delete ui;
}

void PopCheckCaliCurve::createChart()
{
    QChart *chart = new QChart();
    chart->setTitle(tr(u8"校准曲线"));

    ui->chart_checkCurve->setChart(chart);
    ui->chart_checkCurve->setRenderHint(QPainter::Antialiasing);


    QLineSeries *series = new QLineSeries();
    series->setName(u8"主曲线");



    QPen    pen;
    pen.setStyle(Qt::DotLine);//Qt::SolidLine, Qt::DashLine, Qt::DotLine, Qt::DashDotLine
    pen.setWidth(3);
    pen.setColor(Qt::red);
    series->setPen(pen); //折线序列的线条设置

    chart->addSeries(series);



    QValueAxis *axisX = new QValueAxis;
    m_CurAxis=axisX; //当前坐标轴
    axisX->setRange(0, 1000); //设置坐标轴范围
    axisX->setLabelFormat("%.1f"); //标签格式
    axisX->setTickCount(5); //主分隔个数
    axisX->setMinorTickCount(4);
    axisX->setTitleText(u8"浓度(g/L)"); //标题


    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0, 1000);
    axisY->setTitleText("RLU");
    axisY->setTickCount(5);
    axisY->setLabelFormat("%.2f"); //标签格式
    axisY->setMinorTickCount(4);

    chart->setAxisX(axisX, series); //添加X坐标轴

    chart->setAxisY(axisY, series); //添加Y坐标轴
}

void PopCheckCaliCurve::prepareData()
{

}

void PopCheckCaliCurve::updateFromChart()
{

}
