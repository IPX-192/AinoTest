#include "QCSettingEdit.h"
#include "ui_QCSettingEdit.h"

#include <../ComComponents/CusCalendarBox.h>

QCSettingEdit::QCSettingEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QCSettingEdit)
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

    connect( ui->SaveBtn,   &QPushButton::clicked, this, &QCSettingEdit::sigSaveBtnClicked );
    connect( ui->ReturnBtn, &QPushButton::clicked, this, &QCSettingEdit::sigReturnBtnClicked );
}

QCSettingEdit::~QCSettingEdit()
{
    delete ui;
}
