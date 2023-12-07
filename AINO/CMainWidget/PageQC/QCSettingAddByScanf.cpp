#include "QCSettingAddByScanf.h"
#include "ui_QCSettingAddByScanf.h"

#include <../ComComponents/CusCalendarBox.h>

QCSettingAddByScanf::QCSettingAddByScanf(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QCSettingAddByScanf)
{
    ui->setupUi(this);
    ui->BarCodeArea->setTitle( QStringLiteral( "条码信息" ) );
    ui->RackIndex->setTitle( QStringLiteral( "试管架架号设置" ) );
    ui->ElementIndex->setTitle( QStringLiteral( "位置" ) );

    QStringList comboxItems = { QStringLiteral( "试管架位置模式" ) };
    ui->QCModelCombox->addItems( comboxItems );

    connect( ui->SaveBtn,   &QPushButton::clicked, this, &QCSettingAddByScanf::sigSaveBtnClicked );
    connect( ui->ReturnBtn, &QPushButton::clicked, this, &QCSettingAddByScanf::sigReturnBtnClicked );


}

QCSettingAddByScanf::~QCSettingAddByScanf()
{
    delete ui;
}
