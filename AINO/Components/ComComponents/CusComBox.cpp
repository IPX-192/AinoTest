#include "CusComBox.h"
#include "ui_CusComBox.h"

CusComBox::CusComBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CusComBox)
{
    ui->setupUi(this);
}

CusComBox::~CusComBox()
{
    delete ui;
}
