#include "CaliCurve.h"
#include "ui_CaliCurve.h"

CaliCurve::CaliCurve(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaliCurve)
{
    ui->setupUi(this);

    //初始化表格
    QStringList list1 = { QString::fromLocal8Bit( "机器" ), QString::fromLocal8Bit( "校验时间" ),  QString::fromLocal8Bit( "显示" )};
    QStringList list2 = { QString::fromLocal8Bit( "水平" ), QString::fromLocal8Bit( "试管架号" ),  QString::fromLocal8Bit( "试管位置" ), QString::fromLocal8Bit( "目标浓度" ),QString::fromLocal8Bit( "均值" ), QString::fromLocal8Bit( "CV(%)" )};
    QStringList list3 = { QString::fromLocal8Bit( "发光值" ), QString::fromLocal8Bit( "结果" ),  QString::fromLocal8Bit( "试剂批号" ), QString::fromLocal8Bit( "试剂瓶号" ),QString::fromLocal8Bit( "底物批号" ), QString::fromLocal8Bit( "底物瓶号" )};
    ui->tableView_CaliInfo->init( list1 );
    ui->tableView_ConcInfoLeft->init(list2);
    ui->tableView_ConcInfoRight->init(list3);
}

CaliCurve::~CaliCurve()
{
    delete ui;
}
