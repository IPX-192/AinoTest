#include "CusTableView.h"
#include "ui_CusTableView.h"
#include <QScrollBar>
#include <QAbstractItemView>

CusTableView::CusTableView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CusTableView)
{
    ui->setupUi(this);
//    QStringList headers = { "col_1", "col_2", "col_3", "col_4", };
//    m_pModel = new CusTableModel( headers );

//    m_pHeaderView = new QHeaderView( Qt::Horizontal, this );
//    m_pHeaderView->setSectionResizeMode( QHeaderView::Stretch );

//    ui->tableView->setModel( m_pModel );
//    m_pHeaderView->setModel( m_pModel );
//    ui->tableView->setHorizontalHeader( m_pHeaderView );

//    ui->tableView->verticalScrollBar()->setDisabled( true );
//    ui->tableView->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
}

CusTableView::~CusTableView()
{
    delete ui;
}

void CusTableView::init(const QStringList &headerList)
{
    m_pModel = new CusTableModel( headerList );

    m_pHeaderView = new QHeaderView( Qt::Horizontal, this );
    m_pHeaderView->setSectionResizeMode( QHeaderView::Stretch );

    ui->tableView->setModel( m_pModel );
    m_pHeaderView->setModel( m_pModel );
    ui->tableView->setHorizontalHeader( m_pHeaderView );

    ui->tableView->verticalScrollBar()->setDisabled( true );
    ui->tableView->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode( QAbstractItemView::SingleSelection);

    connect( ui->turnPageWidget, &TablePageButton::sigTurnLastPage, this, &CusTableView::lastPage );
    connect( ui->turnPageWidget, &TablePageButton::sigTurnNextPage, this, &CusTableView::nextPage );

    connect( ui->tableView, &QTableView::clicked, [ this ]( const QModelIndex &index ){
        emit sigSelctRowChanged( index.row() );
    } );

}

void CusTableView::setHeaderList(const QStringList &headerList)
{
    m_pModel->setHeaderList( headerList );
    m_pHeaderView->setModel( m_pModel );
}

void CusTableView::tableAppendRow(const TableRowItem &newRow)
{
    m_pModel->appendRow( newRow );
}

void CusTableView::tableAppendRow(const QVariantList &valList)
{
    int colCnt = m_pModel->columnCount();
    if( valList.size() < colCnt ){
        return;
    }

    TableRowItem tmpRow( valList.size() );

    for( int i = 0; i < colCnt; i++ ){
        tmpRow.setData( valList.at( i ), i );
    }

    tableAppendRow( tmpRow );
}

int CusTableView::curIndex() const
{
    int curIndex = ui->tableView->currentIndex().row();
    return curIndex;
}

void CusTableView::nextPage()
{
    int curPos = ui->tableView->verticalScrollBar()->value();
    int step = ui->tableView->verticalScrollBar()->pageStep();
    int tarPos = curPos + step;

    if( tarPos >= m_pModel->rowCount() ){
        int maxIndex = ui->tableView->verticalScrollBar()->maximum();
        ui->tableView->verticalScrollBar()->setSliderPosition( maxIndex );
    }else{
        ui->tableView->verticalScrollBar()->setSliderPosition( tarPos );
        m_curPageIndex++;
    }
    refreshPageInfo();

}

void CusTableView::lastPage()
{
    int curPos = ui->tableView->verticalScrollBar()->value();
    int step = ui->tableView->verticalScrollBar()->pageStep();
    int tarPos = curPos - step;

    if( tarPos > 0 ){
        ui->tableView->verticalScrollBar()->setSliderPosition( tarPos );
    }else{
        int minIndex = ui->tableView->verticalScrollBar()->minimum();
        ui->tableView->verticalScrollBar()->setSliderPosition( minIndex );
    }
    m_curPageIndex--;
    refreshPageInfo();
}

void CusTableView::curPage()
{

    int val = ui->tableView->verticalScrollBar()->value();
    int step = ui->tableView->verticalScrollBar()->pageStep();
    qDebug() << "cur = " << val << "step = " << step;
}

void CusTableView::resetTableModel(const QVector<TableRowItem> &modelData)
{
    m_pModel->resetModelData( modelData );
}

void CusTableView::refreshPageInfo()
{
    int curPos = ui->tableView->verticalScrollBar()->value();
    int step = ui->tableView->verticalScrollBar()->pageStep();
    int itemCnt = m_pModel->rowCount();

    //计算总的页数
    int totalPageCnt = m_pModel->rowCount() / step;
    if( itemCnt % step != 0 ){
        totalPageCnt++;
    }

//    //计算当前页码
//    int curPageIndex = curPos / step;
//    if( curPos %zz step != 0 ){
//        curPageIndex++;
//    }

//    //如果是最后一也页
//    if( itemCnt - curPos < step ){
//        curPageIndex++;
//    }

//    if( curPageIndex == 0 ){
//        curPageIndex = 1;
//    }

    if( m_curPageIndex > totalPageCnt ){
        m_curPageIndex = totalPageCnt;
    }

    if( m_curPageIndex <= 1 ){
        m_curPageIndex = 1;
    }

    ui->turnPageWidget->setTotalPage( totalPageCnt );
    ui->turnPageWidget->setCurPage( m_curPageIndex );
}

TableRowItem CusTableView::getTargetRowElement(const int rowIndex)
{
    auto tarRow = m_pModel->getTargetRow( rowIndex );
    return tarRow;
}

void CusTableView::resizeEvent(QResizeEvent *evt)
{
    refreshPageInfo();
}
