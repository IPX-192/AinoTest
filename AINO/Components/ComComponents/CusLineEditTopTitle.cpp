#include "CusLineEditTopTitle.h"
#include "ui_CusLineEditTopTitle.h"

CusLineEditTopTitle::CusLineEditTopTitle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CusLineEditTopTitle)
{
    ui->setupUi(this);
}

CusLineEditTopTitle::~CusLineEditTopTitle()
{
    delete ui;
}

void CusLineEditTopTitle::setTitle(const QString &title)
{
    ui->label->setText( title + ":" );
}

QString CusLineEditTopTitle::getText()
{
    return ui->label->text();
}
