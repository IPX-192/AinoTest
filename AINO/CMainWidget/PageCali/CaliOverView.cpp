#include "CaliOverView.h"
#include "ui_CaliOverView.h"

CaliOverView::CaliOverView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaliOverView)
{
    ui->setupUi(this);

    init();
}

CaliOverView::~CaliOverView()
{
    delete ui;
}

void CaliOverView::init()
{


    //ui->frame->setStyleSheet("border: 1px solid black;"); // 设置边框为红色

    //初始化表格
    QStringList list = { QString::fromLocal8Bit( "机器" ), QString::fromLocal8Bit( "试剂项目" ),  QString::fromLocal8Bit( "试剂批号" ), QString::fromLocal8Bit( "项目可测数" ), QString::fromLocal8Bit( "校准状态" ),
                         QString::fromLocal8Bit( "校准有效期" ), QString::fromLocal8Bit( "操作" )};
    ui->tabView_CaliOverlist->init( list );




}

