#include "CaliProductManager.h"
#include "ui_CaliProductManager.h"

CaliProductManager::CaliProductManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaliProductManager)
{
    ui->setupUi(this);
    //初始化表格
    //初始化表格
    QStringList list1 = { QString::fromLocal8Bit( "序号" ), QString::fromLocal8Bit( "项目" ),  QString::fromLocal8Bit( "校准品批号" ), QString::fromLocal8Bit( "有效期" ), QString::fromLocal8Bit( "试管架架号" ),
                          QString::fromLocal8Bit( "C0" ), QString::fromLocal8Bit( "C1" ), QString::fromLocal8Bit( "C2" ), QString::fromLocal8Bit( "C3" ), QString::fromLocal8Bit( "C4" ), QString::fromLocal8Bit( "C5" )};

    QStringList list2 = { QString::fromLocal8Bit( "试剂批号" ), QString::fromLocal8Bit( "主曲线" )};
    ui->tabView_caliSetLeft->init( list1 );
    ui->tabView_caliSetRight->init(list2);
}

CaliProductManager::~CaliProductManager()
{
    delete ui;
}
