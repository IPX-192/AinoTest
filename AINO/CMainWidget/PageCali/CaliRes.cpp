#include "CaliRes.h"
#include "ui_CaliRes.h"

CaliRes::CaliRes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaliRes)
{
    ui->setupUi(this);
}

CaliRes::~CaliRes()
{
    delete ui;
}
