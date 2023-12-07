#include "CaliApplyList.h"
#include "ui_CaliApplyList.h"

CaliApplyList::CaliApplyList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaliApplyList)
{
    ui->setupUi(this);
    init();
}

CaliApplyList::~CaliApplyList()
{
    delete ui;
}

void CaliApplyList::init()
{
    //初始化表格
    QStringList list = { QString::fromLocal8Bit( "机器" ), QString::fromLocal8Bit( "项目" ),  QString::fromLocal8Bit( "试剂批号" ), QString::fromLocal8Bit( "试管架架号" ), QString::fromLocal8Bit( "C0" ),
                         QString::fromLocal8Bit( "C1" ), QString::fromLocal8Bit( "C2" ), QString::fromLocal8Bit( "C3" ), QString::fromLocal8Bit( "C4" ),QString::fromLocal8Bit( "C5" )};
    ui->tabView_CaliApplist->init( list );
}
