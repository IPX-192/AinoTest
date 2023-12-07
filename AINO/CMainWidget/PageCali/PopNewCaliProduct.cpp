#include "PopNewCaliProduct.h"
#include "ui_PopNewCaliProduct.h"

PopNewCaliProduct::PopNewCaliProduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PopNewCaliProduct)
{
    ui->setupUi(this);

    connect( ui->btn_NewCaliReset,&QPushButton::clicked, this, &PopNewCaliProduct::sigNewCaliProductReset );
    connect( ui->btn_NewCaliOK,&QPushButton::clicked, this, &PopNewCaliProduct::sigNewCaliProductOk );
    connect( ui->btn_NewCaliCancle,&QPushButton::clicked, this, &PopNewCaliProduct::sigNewCaliProductCancle );
}

PopNewCaliProduct::~PopNewCaliProduct()
{
    delete ui;
}
