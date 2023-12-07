#include "QCSetting.h"
#include "ui_QCSetting.h"

QCSetting::QCSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QCSetting)
{
    ui->setupUi(this);

    QStringList headerList1 = { QString::fromLocal8Bit( "质控品名称"),
                                QString::fromLocal8Bit( "批号" ),
                                QString::fromLocal8Bit( "试管架号" ),
                                QString::fromLocal8Bit( "试管位置" ),
                               QString::fromLocal8Bit( "有效期" ) };

    QStringList headerList2 = { QString::fromLocal8Bit( "项目"),
                               QString::fromLocal8Bit( "目标值" ),
                               QString::fromLocal8Bit( "SD值" ),
                               QString::fromLocal8Bit( "单位" ) };

    ui->QCProductsTable->init( headerList1 );
    ui->QCProjectsTable->init( headerList2 );

    connect( ui->ScanfBtn,  &QPushButton::clicked, this, &QCSetting::sigScanfBtnClicked );
    connect( ui->ManulBtn,  &QPushButton::clicked, this, &QCSetting::sigManualBtnClicked );
    connect( ui->EditBtn,   &QPushButton::clicked, this, &QCSetting::sigEditBtnClicked );
    connect( ui->DeleteBtn, &QPushButton::clicked, this, &QCSetting::sigDeleteBtnClicked );
    connect( ui->RuleBtn,   &QPushButton::clicked, this, &QCSetting::sigRuleBtnClicked );
}

QCSetting::~QCSetting()
{
    delete ui;
}
