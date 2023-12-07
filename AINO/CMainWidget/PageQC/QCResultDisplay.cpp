#include "QCResultDisplay.h"
#include "ui_QCResultDisplay.h"

QCResultDisplay::QCResultDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QCResultDisplay)
{
    ui->setupUi(this);

    QStringList headerList = { QString::fromLocal8Bit( "机器号"),
                              QString::fromLocal8Bit( "项目" ),
                              QString::fromLocal8Bit( "浓度" ),
                              QString::fromLocal8Bit( "发光值" ),
                              QString::fromLocal8Bit( "结束时间" ),
                              QString::fromLocal8Bit( "试剂批号" ),
                              QString::fromLocal8Bit( "试剂瓶号" ),
                              QString::fromLocal8Bit( "底物瓶号" ),
                              QString::fromLocal8Bit( "校准品批号" ),
                              QString::fromLocal8Bit( "校准时间" ),
                              };

    ui->QCProductsDisplayWidget->init( headerList );

    connect( ui->ExportBtn, &QPushButton::clicked, this, &QCResultDisplay::sigExportBtnClicked );
    connect( ui->ReturnBtn, &QPushButton::clicked, this, &QCResultDisplay::sigReturnBtnClicked );
}

QCResultDisplay::~QCResultDisplay()
{
    delete ui;
}
