#include "CusCalendarBox.h"
#include "ui_CusCalendarBox.h"

CusCalendarBox::CusCalendarBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CusCalendarBox)
{
    ui->setupUi(this);
    connect( ui->calendarWidget, &QCalendarWidget::clicked, [ this ]( const QDate &date ){
        m_date = date;
        this->accept();
    } );
}

CusCalendarBox::~CusCalendarBox()
{
    delete ui;
}

QDate CusCalendarBox::selectDate() const
{
    return m_date;
}

QString CusCalendarBox::getSelectDateString()
{
    return m_date.toString( "yyyy-MM-dd" );
}
