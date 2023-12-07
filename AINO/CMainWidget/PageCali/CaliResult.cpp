#include "CaliResult.h"
#include "ui_CaliResult.h"

CaliResult::CaliResult(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaliResult)
{
    ui->setupUi(this);
    initialize();
}

CaliResult::~CaliResult()
{
    delete ui;
}

void CaliResult::initialize()
{
    //初始化表格
    QStringList list1 = { QString::fromLocal8Bit( "机器" ), QString::fromLocal8Bit( "项目" ),  QString::fromLocal8Bit( "校准品批号" ), QString::fromLocal8Bit( "校准状态" ), QString::fromLocal8Bit( "测试状态" ),
                          QString::fromLocal8Bit( "申请时间" ), QString::fromLocal8Bit( "结束时间" ), QString::fromLocal8Bit( "校准标记" )};

    QStringList list2 = { QString::fromLocal8Bit( "目标浓度" ), QString::fromLocal8Bit( "水平" ),  QString::fromLocal8Bit( "发光值" ), QString::fromLocal8Bit( "标记" )};
    ui->tabView_ResLeft->init( list1 );
    ui->tabView_ResRight->init(list2);
}
