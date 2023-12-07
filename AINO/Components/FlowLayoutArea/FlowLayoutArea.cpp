#include "FlowLayoutArea.h"
#include "ui_FlowLayoutArea.h"

#include <QPushButton>


FlowLayoutArea::FlowLayoutArea(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FlowLayoutArea)
{
    ui->setupUi(this);

    m_pFlowLayout = new FlowLayout( ui->scrollAreaWidgetContents );
    m_pFlowLayout->setMargin( 10 );

    for( int i = 0; i < 200; i++ ){
        QString tmpName = QString( "Index: %1" ).arg( i );
        auto tmpItem = new FlowItemWidget();
        tmpItem->setItemName( tmpName );
        m_pFlowLayout->addWidget( tmpItem );
    }
}

FlowLayoutArea::~FlowLayoutArea()
{
    delete ui;
}

void FlowLayoutArea::appendWidget( FlowItemWidget *widget )
{
    m_pFlowLayout->addWidget( widget );
}

QStringList FlowLayoutArea::getCheckedItemNames()
{
    int cnt = m_pFlowLayout->count();

    QStringList nameList;
    for( int i = 0; i < cnt; i++ ){
        auto tmpItem = static_cast<FlowItemWidget*>( m_pFlowLayout->itemAt( i )->widget() );

        if( tmpItem->checkState() ){
            nameList << tmpItem->getItemName();
        }

    }

    return nameList;
}

void FlowLayoutArea::setPostion()
{
}
