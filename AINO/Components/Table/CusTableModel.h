#pragma once

#include <QAbstractTableModel>
#include "CAbstractTableItem.h"
#include "Components_global.h"
#include <QAbstractItemModel>

class COMPONENTS_EXPORT CusTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit CusTableModel( const QStringList &roleList, QObject *parent = nullptr );

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;


    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void appendRow( const TableRowItem &newRow );

    void setHeaderList(const QStringList &newHeaderList);

    void resetModelData(const QVector<TableRowItem> &modelData);

    TableRowItem getTargetRow( const int rowIndex ) const;


private:
    TableDataStore  *m_pDataStore = nullptr;
    QStringList      m_headerList;
};

