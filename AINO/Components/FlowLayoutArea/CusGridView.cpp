#include "CusGridView.h"
#include "ui_CusGridView.h"

CusGridView::CusGridView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CusGridView)
{
    ui->setupUi(this);
}

CusGridView::~CusGridView()
{
    delete ui;
}

void CusGridView::setItemNames(const QStringList &names)
{
    const int perPageCnt = 16;

    for( int index = 1; index <= perPageCnt; index++ ){

        if( index > names.size() ){
            break;
        }

        QString objName = QString( "item%1" ).arg( index );
        auto tarItem =  this->findChild< FlowItemWidget* >( objName );
        tarItem->setItemName( names.at( index - 1 ) );
    }
}

QStringList CusGridView::getCheckedNames() const
{
    int cnt = ui->gridLayout_15->count();
    QStringList checkedNames;

    for( int i = 0; i < cnt; i++ ){
        auto tmpElement = static_cast< FlowItemWidget* >( ui->gridLayout_15->itemAt( i )->widget() );
        if( tmpElement->checkState() ){
            checkedNames << tmpElement->getItemName();
        }
    }

    return checkedNames;
}

void CusGridView::setItems(const QVector<std::pair<QString, int> > &items)
{
    constexpr int perPageCnt = 16;

    for( int index = 1; index <= perPageCnt; index++ ){
        if( index > items.size() ){
            break;
        }

        auto &[ itemName, itemColor ] = items.at( index - 1 );

        QString objName = QString( "item%1" ).arg( index );
        auto tarItem =  this->findChild< FlowItemWidget* >( objName );
        tarItem->setItemName( itemName );
        tarItem->setColor( static_cast<FlowItemWidget::ItemColor>( itemColor ) );
    }
}

QVector<std::pair<QString, int> > CusGridView::getCheckedItemInfo() const
{
    QVector<std::pair<QString, int> > vecTarItems;
    std::pair<QString, int>  tarPair;
    int cnt = ui->gridLayout_15->count();
    for( int i = 0; i < cnt; i++ ){
        auto tmpElement = static_cast< FlowItemWidget* >( ui->gridLayout_15->itemAt( i )->widget() );
        if( tmpElement->checkState() ){
            auto itemName = tmpElement->getItemName();
            auto itemColor = tmpElement->color();
            tarPair = std::make_pair( itemName, itemColor );
            vecTarItems << tarPair;
        }
    }

    return vecTarItems;
}
