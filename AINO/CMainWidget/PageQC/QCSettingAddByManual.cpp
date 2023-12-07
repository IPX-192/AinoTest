#include "QCSettingAddByManual.h"
#include "ui_QCSettingAddByManual.h"

#include <../ComComponents/CusCalendarBox.h>

QCSettingAddByManual::QCSettingAddByManual(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QCSettingAddByManual)
{
    ui->setupUi(this);
    ui->QCName->setTitle( QStringLiteral( "质控名称" ) );
    ui->GroupNumber->setTitle( QStringLiteral( "批号" ) );
    ui->TrackIndexNumber->setTitle( QStringLiteral( "试管架架号" ) );
    ui->IndexNUmber->setTitle( QStringLiteral( "位置" ) );
    ui->targetInput->setTitle( QStringLiteral( "目标值" ) );
    ui->SDInput->setTitle( QStringLiteral( "SD值" ) );

    QStringList comboxItems = { QStringLiteral( "试管架位置模式" ) };
    ui->QCModelCombox->addItems( comboxItems );


    connect( ui->ValuedDateBtn, &QPushButton::clicked, [ this ](){
        CusCalendarBox dateSelect;
        dateSelect.exec();
        ui->ValuedDateBtn->setText( dateSelect.getSelectDateString() );
    } );

    connect( ui->SaveBtn,   &QPushButton::clicked, this, &QCSettingAddByManual::sigSaveBtnClicked );
    connect( ui->ReturnBtn, &QPushButton::clicked, this, &QCSettingAddByManual::sigReturnBtnClicked );
}

QCSettingAddByManual::~QCSettingAddByManual()
{
    delete ui;
}

