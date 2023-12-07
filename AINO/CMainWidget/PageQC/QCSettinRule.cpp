#include "QCSettinRule.h"
#include "ui_QCSettinRule.h"

QCSettinRule::QCSettinRule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QCSettinRule)
{
    ui->setupUi(this);
    ui->QCProjectsTable->init( QStringList() << QStringLiteral( "项目" ) );


    connect( ui->SaveBtn,   &QPushButton::clicked, this, &QCSettinRule::sigSaveBtnClicked );
    connect( ui->returnBtn, &QPushButton::clicked, this, &QCSettinRule::sigReturnBtnClicked );
}

QCSettinRule::~QCSettinRule()
{
    delete ui;
}
