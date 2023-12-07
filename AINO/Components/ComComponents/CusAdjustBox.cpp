#include "CusAdjustBox.h"
#include "ui_CusAdjustBox.h"

CusAdjustBox::CusAdjustBox(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CusAdjustBox)
{
    ui->setupUi(this);
    m_displayList =  QStringList{ "1", "2", "3", "4" };

    init();
}

CusAdjustBox::~CusAdjustBox()
{
    delete ui;
}

void CusAdjustBox::init()
{
    connect( ui->leftBtn, &QPushButton::clicked, [ this ](){
        m_curIndex -=1;

        m_curIndex = m_curIndex < 0 ? 0 : m_curIndex;

        ui->label->setText( m_displayList.at( m_curIndex ) );
    } );

    connect( ui->rightBtn, &QPushButton::clicked, [ this ](){
        m_curIndex +=1;

        m_curIndex = m_curIndex >= m_displayList.size() ? m_displayList.size() - 1 : m_curIndex;

        ui->label->setText( m_displayList.at( m_curIndex ) );
    } );
}

void CusAdjustBox::setDisplayList(const QStringList &newDisplayList)
{
    m_displayList = newDisplayList;
}
