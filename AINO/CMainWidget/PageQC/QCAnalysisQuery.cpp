#include "QCAnalysisQuery.h"
#include "ui_QCAnalysisQuery.h"
#include "../ComComponents/CusCalendarBox.h"

QCAnalysisQuery::QCAnalysisQuery(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QCAnalysisQuery)
{
    ui->setupUi(this);
    ui->XCount->setTitle( QStringLiteral( "数据个数" ) );
    ui->YCount->setTitle( QStringLiteral( "数据个数" ) );

    ui->YNumberStart->setTitle( QStringLiteral( "起始值" ) );
    ui->YNumberEnd->setTitle( QStringLiteral( "终止值" ) );

    connect( ui->startDateBtn, &QPushButton::clicked, [ this ](){
        CusCalendarBox dateSelect;
        dateSelect.exec();
        ui->startDateBtn->setText( dateSelect.getSelectDateString() );
    } );

    connect( ui->endDateBtn, &QPushButton::clicked, [ this ](){
        CusCalendarBox dateSelect;
        dateSelect.exec();
        ui->endDateBtn->setText( dateSelect.getSelectDateString() );
    } );

    connect( ui->resetBtn,   &QPushButton::clicked, this, &QCAnalysisQuery::sigResetBtnClicked );
    connect( ui->ConfirmBtn, &QPushButton::clicked, this, &QCAnalysisQuery::sigConfirmBtnClicked );
    connect( ui->returnBtn,  &QPushButton::clicked, this, &QCAnalysisQuery::sigReturnBtnClicked );
}

QCAnalysisQuery::~QCAnalysisQuery()
{
    delete ui;
}
