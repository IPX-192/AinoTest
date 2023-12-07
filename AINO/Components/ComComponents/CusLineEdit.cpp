#include "CusLineEdit.h"
#include "ui_CusLineEdit.h"

CusLineEdit::CusLineEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CusLineEdit)
{
    ui->setupUi(this);
}

CusLineEdit::~CusLineEdit()
{
    delete ui;
}

void CusLineEdit::setTitle(const QString &title)
{
    ui->label->setText( title + ":" );
}

QString CusLineEdit::getText()
{
    return ui->lineEdit->text();
}
