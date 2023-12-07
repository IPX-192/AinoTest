#include "MachineInfo.h"
#include "ui_MachineInfo.h"

MachineInfo::MachineInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MachineInfo)
{
    ui->setupUi(this);
}

MachineInfo::~MachineInfo()
{
    delete ui;
}
