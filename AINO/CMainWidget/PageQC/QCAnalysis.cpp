#include "QCAnalysis.h"
#include "ui_QCAnalysis.h"

QCAnalysis::QCAnalysis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QCAnalysis)
{
    ui->setupUi(this);

    connect( ui->QueryBtn, &QPushButton::clicked, this, &QCAnalysis::sigQueryBtnClicked );
    connect( ui->TrendBtn, &QPushButton::clicked, this, &QCAnalysis::sigTrendBtnClicked );

    QStringList headerList = { QString::fromLocal8Bit( "机器号"),
                              QString::fromLocal8Bit( "项目" ),
                              QString::fromLocal8Bit( "质控品" ),
                              QString::fromLocal8Bit( "质控品批号" ),
                              QString::fromLocal8Bit( "试剂批号" ),
                              QString::fromLocal8Bit( "申请时间" ),
                              QString::fromLocal8Bit( "结束时间" ),
                              QString::fromLocal8Bit( "结果" ),
                              QString::fromLocal8Bit( "目标值" ),
                              QString::fromLocal8Bit( "SD值" ),
                              QString::fromLocal8Bit( "单位" ),
                              QString::fromLocal8Bit( "标记" ),
                              QString::fromLocal8Bit( "规则" ),
                              QString::fromLocal8Bit( "状态" )
                              };

    ui->tableArea->init( headerList );

    connect( ui->QueryBtn, &QPushButton::clicked, this, &QCAnalysis::sigQueryBtnClicked );
    connect( ui->TrendBtn, &QPushButton::clicked, this, &QCAnalysis::sigTrendBtnClicked );
}

QCAnalysis::~QCAnalysis()
{
    delete ui;
}
