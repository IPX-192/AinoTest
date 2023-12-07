#include "QCChartTP.h"
#include "ui_QCChartTP.h"

QCChartTP::QCChartTP(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QCChartTP)
{
    ui->setupUi(this);

    ui->QCProjectsTable->init( QStringList() << QStringLiteral( "项目" ) );


    connect( ui->RefreshBtn, &QPushButton::clicked, this, &QCChartTP::sigRefeshBtnClicked );
    connect( ui->PrintBtn,   &QPushButton::clicked, this, &QCChartTP::sigPrintBtnClilcked );
    connect( ui->LJBtn,      &QPushButton::clicked, this, &QCChartTP::sigLJBtnClicked );
}

QCChartTP::~QCChartTP()
{
    delete ui;
}
