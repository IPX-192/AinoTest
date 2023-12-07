#include "TurnPageGridView.h"
#include "ui_TurnPageGridView.h"

TurnPageGridView::TurnPageGridView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TurnPageGridView)
{
    ui->setupUi(this);
    connect( ui->lastPageBtn, &QPushButton::clicked, this, &TurnPageGridView::onTurnLastPage );
    connect( ui->nextPageBtn, &QPushButton::clicked, this, &TurnPageGridView::onTurnNextPage );
}

TurnPageGridView::~TurnPageGridView()
{
    delete ui;
}

QStringList TurnPageGridView::getCheckedNamesList() const
{
    QStringList checkedNames;
    int tabCnt = ui->tabWidget->count();

    for( int i = 0; i < tabCnt; i++ ){
        auto tmpTabWidget = static_cast< CusGridView* >( ui->tabWidget->widget( i ) );
        checkedNames += tmpTabWidget->getCheckedNames();
    }

    return checkedNames;
}

QVector<std::pair<QString, int> > TurnPageGridView::getCheckedProjectsInfo()
{
    std::pair<QString, int> tmpCheckedPair;
    QVector<std::pair<QString, int> > vecCheckedInfos;
    QStringList checkedNames;
    int tabCnt = ui->tabWidget->count();

    for( int i = 0; i < tabCnt; i++ ){
        auto tmpTabWidget = static_cast< CusGridView* >( ui->tabWidget->widget( i ) );
        vecCheckedInfos += tmpTabWidget->getCheckedItemInfo();
    }

    return vecCheckedInfos;
}

void TurnPageGridView::resetNameList( QStringList names )
{
    removeAllTabs();

    int pageCnt = names.size() / m_perPageItemCnt;
    int restItemCnt = names.size() % m_perPageItemCnt;

    if( restItemCnt > 0 ){
        pageCnt += 1;
    }

    auto vecPageNames = getGroupNameList( names );

    for( int i = 0; i < pageCnt; i++ ){
        auto perPageTotalNames = names.mid( 0, 16 );
        auto tmpGridView = new CusGridView( this );
        tmpGridView->setItemNames( vecPageNames[ i ] );
        ui->tabWidget->addTab( tmpGridView, QString::number( i ) );
    }

}

void TurnPageGridView::resetItemList(const ItemInfosGroup &items)
{
    removeAllTabs();

    int pageCnt     = items.size() / m_perPageItemCnt;
    int restItemCnt = items.size() % m_perPageItemCnt;

    if( restItemCnt > 0 ){
        pageCnt += 1;
    }

    auto vecPageItems = getGroupItemList( items );

    for( int i = 0; i < pageCnt; i++ ){
        auto perPageTotalNames = items.mid( 0, 16 );
        auto tmpGridView = new CusGridView( this );
        tmpGridView->setItems( vecPageItems[ i ] );
        ui->tabWidget->addTab( tmpGridView, QString::number( i ) );
    }
}

void TurnPageGridView::onTurnNextPage()
{
    m_curTabIndex += 1;
    int tabCnt = ui->tabWidget->count();

    m_curTabIndex = m_curTabIndex >= tabCnt ? m_curTabIndex - 1 : m_curTabIndex;

    ui->tabWidget->setCurrentIndex( m_curTabIndex );
}

void TurnPageGridView::onTurnLastPage()
{
    m_curTabIndex -= 1;
    m_curTabIndex = m_curTabIndex <= 0 ? m_curTabIndex : m_curTabIndex - 1;

    ui->tabWidget->setCurrentIndex( m_curTabIndex );
}

void TurnPageGridView::removeAllTabs()
{
    int tabCnt = ui->tabWidget->count();
    for( int i = tabCnt; i >= 0; i-- ){
        auto tmpTabWidget = static_cast< CusGridView* >( ui->tabWidget->widget( i ) );
        ui->tabWidget->removeTab( i );
        delete tmpTabWidget;
        tmpTabWidget = nullptr;
    }
}

QVector<QStringList> TurnPageGridView::getGroupNameList(QStringList &names)
{
    int pageCnt = names.size() / m_perPageItemCnt;

    QVector<QStringList> vecRet;
    for( int i = 0; i < pageCnt; i++ ){
        QStringList retList;

        for( int i = 0; i < m_perPageItemCnt; i++ ){
            retList << names.takeFirst();
        }

        vecRet << retList;

    }

    // 取出前面 m_perPageItemCnt 整数倍的个数， 剩下的数量肯定小于 m_perPageItemCnt， 直接全部存入
    vecRet << names;

    return vecRet;



}

QVector<ItemInfosGroup> TurnPageGridView::getGroupItemList(ItemInfosGroup items)
{
    int pageCnt = items.size() / m_perPageItemCnt;

    QVector<ItemInfosGroup> vecRet;
    for( int i = 0; i < pageCnt; i++ ){
        ItemInfosGroup retList;

        for( int i = 0; i < m_perPageItemCnt; i++ ){
            retList << items.takeFirst();
        }

        vecRet << retList;

    }

    vecRet << items;

    return vecRet;
}
