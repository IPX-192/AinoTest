#include "OperationGuide.h"
#include "ui_OperationGuide.h"

OperationGuide::OperationGuide(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OperationGuide)
{
    ui->setupUi(this);
}

OperationGuide::~OperationGuide()
{
    delete ui;
}
