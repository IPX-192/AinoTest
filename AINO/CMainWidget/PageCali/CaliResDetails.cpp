#include "CaliResDetails.h"
#include "ui_CaliResDetails.h"

CaliResDetails::CaliResDetails(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaliResDetails)
{
    ui->setupUi(this);
    initialize();
}

CaliResDetails::~CaliResDetails()
{
    delete ui;
}

void CaliResDetails::initialize()
{
    //初始化表格
    QStringList list = { QString::fromLocal8Bit( "水平" ), QString::fromLocal8Bit( "浓度" ),  QString::fromLocal8Bit( "发光值" ), QString::fromLocal8Bit( "试剂批号" ), QString::fromLocal8Bit( "试剂瓶号" ),
                         QString::fromLocal8Bit( "底物批号" ), QString::fromLocal8Bit( "底物瓶号" ),QString::fromLocal8Bit( "结束时间" )};
    ui->tabView_ResDetails->init( list );
}
