#include "CusClockTimeAdjust.h"
#include "ui_CusClockTimeAdjust.h"

#include <QRegExpValidator>

CusClockTimeAdjust::CusClockTimeAdjust(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CusClockTimeAdjust)
{
    ui->setupUi(this);

    QRegExp reg1( "/0?|1?\\d|2[0-3]/" );
    auto exp1 = new QRegExpValidator( reg1, this );

    QRegExp reg2( "[0-4][0-9]|5[0-9]" );
    auto exp2 = new QRegExpValidator( reg2, this );

    ui->lineEdit->setValidator( exp1 );
    ui->lineEdit_2->setValidator( exp2 );

    //设置默认时间
    ui->lineEdit->setText( "8" );
    ui->lineEdit_2->setText( "0" );
}

CusClockTimeAdjust::~CusClockTimeAdjust()
{
    delete ui;
}

QString CusClockTimeAdjust::getClockTime() const
{
    auto time = ui->lineEdit->text() + ":" + ui->lineEdit_2->text() + ":00";
    return time;
}
