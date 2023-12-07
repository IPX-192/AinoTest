#include "CaliCurveDraw.h"
#include "ui_CaliCurveDraw.h"


void CaliCurveDraw::createChart()
{
    QChart *chart = new QChart();
    chart->setTitle(tr(u8"校准曲线"));

    ui->chartView->setChart(chart);
    ui->chartView->setRenderHint(QPainter::Antialiasing);


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

void CaliCurveDraw::prepareData()
{

}

void CaliCurveDraw::updateFromChart()
{

}



CaliCurveDraw::CaliCurveDraw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaliCurveDraw)
{
    ui->setupUi(this);
    createChart();//创建图表
    prepareData();//生成数据
    updateFromChart(); //从图表获得属性值，刷新界面显示
}

CaliCurveDraw::~CaliCurveDraw()
{
    delete ui;
}

