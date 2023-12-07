#include "CusTableModel.h"
#include <QHeaderView>

CusTableModel::CusTableModel(const QStringList &roleList, QObject *parent)
    : QAbstractTableModel(parent),
    m_headerList( roleList )
{
    m_pDataStore = new TableDataStore( roleList.size() );
}

QVariant CusTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if( orientation != Qt::Horizontal ){
        return QVariant();
    }

    if( role != Qt::DisplayRole ){
        return QVariant();
    }

    return m_headerList.at( section );
}


int CusTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()){
        return 0;
    }

    return m_pDataStore->rowCnt();
}

int CusTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid()){
        return 0;
    }

    return m_headerList.size();
}

QVariant CusTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()){
        return QVariant();
    }

    QVariant ret;

    auto handleDisplayRole = [ &, this ](){
        int row = index.row();
        int col = index.column();

        ret = m_pDataStore->getElementData( row, col );
    };


    switch( role ){
    case Qt::DisplayRole:
        handleDisplayRole();
        break;

    default:
        break;
    }

    return ret;
}

void CusTableModel::appendRow(const TableRowItem &newRow)
{
    beginInsertRows( QModelIndex(), m_pDataStore->rowCnt(), m_pDataStore->rowCnt() );
    m_pDataStore->appendRowData( newRow );
    endInsertRows();

}

void CusTableModel::setHeaderList(const QStringList &newHeaderList)
{
    m_headerList = newHeaderList;
    emit headerDataChanged( Qt::Horizontal, 0, m_headerList.size() - 1 );
}

void CusTableModel::resetModelData(const QVector<TableRowItem> &modelData)
{
    m_pDataStore->resetModelData( modelData );

    auto satrtModelIndex = this->index( 0, 0 );
    auto endModelIndex = this->index( m_pDataStore->rowCnt(), m_pDataStore->colCnt() );

//    emit dataChanged( satrtModelIndex, endModelIndex, QVector<int>() << Qt::DisplayRole );
    emit layoutChanged();
}

TableRowItem CusTableModel::getTargetRow(const int rowIndex) const
{
    auto tarRow = m_pDataStore->getRowData( rowIndex );
    return tarRow;
}
