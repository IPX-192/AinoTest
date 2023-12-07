#include "QCChartLJ.h"
#include "ui_QCChartLJ.h"
#include "../ComComponents/CusCalendarBox.h"

QCChartLJ::QCChartLJ(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QCChartLJ)
{
    ui->setupUi(this);

    ui->QCProjectsTable->init( QStringList() << QStringLiteral( "项目" ) );

    connect( ui->startDatebtn, &QPushButton::clicked, [ this ](){
        CusCalendarBox dateSelect;
        dateSelect.exec();
        ui->startDatebtn->setText( dateSelect.getSelectDateString() );
    } );

    connect( ui->endDateBtn, &QPushButton::clicked, [ this ](){
        CusCalendarBox dateSelect;
        dateSelect.exec();
        ui->endDateBtn->setText( dateSelect.getSelectDateString() );
    } );

    connect( ui->RefreshBtn, &QPushButton::clicked, this, &QCChartLJ::sigRefeshBtnClicked );
    connect( ui->PrintBtn,   &QPushButton::clicked, this, &QCChartLJ::sigPrintBtnClilcked );
    connect( ui->TPBtn,      &QPushButton::clicked, this, &QCChartLJ::sigTPBtnClicked );
}

QCChartLJ::~QCChartLJ()
{
    delete ui;
}
