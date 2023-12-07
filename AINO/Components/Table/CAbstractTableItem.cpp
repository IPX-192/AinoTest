#include "CAbstractTableItem.h"

TableRowItem::TableRowItem(size_t colCnt)
{
    while( colCnt-- ){
        m_dataMap.insert( colCnt, QVariant() );
    }
}

TableRowItem::TableRowItem(const QStringList &valList, const int size)
{
    for( int i = 0; i < size; i++ ){
        m_dataMap.insert( i, valList.at( i ) );
    }
}

TableRowItem TableRowItem::createTableRowFromVariantList(const QVariantList &varList)
{
    TableRowItem tmpRowItem( varList.size() );

    for( int colIndex = 0; colIndex < varList.size(); colIndex++ ){
        auto tmpData = varList.at( colIndex );
        tmpRowItem.setData( tmpData, colIndex );
    }

    return tmpRowItem;
}

QVariant TableRowItem::getData(const int role)
{
    auto ret = m_dataMap.value( role, "Error" );
    return ret;
}

void TableRowItem::setData(const QVariant &val, const int role)
{
    m_dataMap[ role ] = val;
}

int TableRowItem::colCnt() const
{
    return m_roleList.size();
}

TableDataStore::TableDataStore(const size_t colCnt) : m_colCnt( colCnt )
{

}

TableRowItem TableDataStore::getRowData(const size_t row)
{
    auto ret = m_vecDatas.at( row );

    return ret;
}

QVariant TableDataStore::getElementData(const size_t row, const size_t col)
{
    auto ret = m_vecDatas[ row ].getData( col );
    return ret;
}

void TableDataStore::setElementData(const size_t row, const size_t col, const QVariant &val)
{
    m_vecDatas[ row ].setData( val, col );
}

void TableDataStore::appendRowData(const TableRowItem &newRow)
{
    m_vecDatas.append( newRow );
}

int TableDataStore::rowCnt()
{
    int rowCnt = m_vecDatas.size();
    return rowCnt;
}

int TableDataStore::colCnt()
{
    if( m_vecDatas.isEmpty() ){
        return 0;
    }

    int colCnt = m_vecDatas.at( 0 ).colCnt();
    return colCnt;
}

void TableDataStore::resetModelData(const QVector<TableRowItem> &modelData)
{
    m_vecDatas = modelData;
}
