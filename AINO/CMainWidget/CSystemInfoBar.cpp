#include "CSystemInfoBar.h"
#include "ui_CSystemInfoBar.h"

CSystemInfoBar::CSystemInfoBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CSystemInfoBar)
{
    ui->setupUi(this);

    init();
}

CSystemInfoBar::~CSystemInfoBar()
{
    delete ui;
}

void CSystemInfoBar::onSetUserLoginName(const QString &loginName)
{

}

void CSystemInfoBar::init()
{
    connect( &m_timer, &QTimer::timeout, [ this ](){
        auto curDateTime = QDateTime::currentDateTime().toString( "yyyy/MM/dd hh:mm:ss" );
        ui->timeLabel->setText( curDateTime );
    } );

    m_timer.setInterval( 1000 );
    m_timer.setSingleShot( false );
    m_timer.start();
}
