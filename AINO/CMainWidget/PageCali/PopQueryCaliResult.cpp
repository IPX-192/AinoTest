#include "PopQueryCaliResult.h"
#include "ui_PopQueryCaliResult.h"

PopQueryCaliResult::PopQueryCaliResult(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PopQueryCaliResult)
{
    ui->setupUi(this);

    connect( ui->btn_QueryCaliOK,&QPushButton::clicked, this, &PopQueryCaliResult::sigCaliResQueryOk );
    connect( ui->btn_QueryCaliCancle,&QPushButton::clicked, this, &PopQueryCaliResult::sigCaliResQueryCancle );
}

PopQueryCaliResult::~PopQueryCaliResult()
{
    delete ui;
}
