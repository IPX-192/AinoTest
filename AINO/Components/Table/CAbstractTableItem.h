#pragma once

#include <QDebug>
#include <QVector>
#include <QMap>
#include "Components_global.h"

typedef QMap< int, QVariant >  RowDataMap;


enum class TableRowRole{
    Col_1 = 0,
    Col_2 = 1,
    Col_3 = 2,
    Col_4 = 3,
    Col_5 = 4,
    Col_6 = 5,
    Col_7 = 6,
    Col_8 = 7,
    Col_9 = 8,
    Col_10 = 9,
    Col_11 = 10,
    Col_12 = 11,
    Col_13 = 12,
    Col_14 = 13,
    Col_15 = 14,
    Col_16 = 15,
};

class COMPONENTS_EXPORT TableRowItem{
public:
    //构造一个空的
    TableRowItem( size_t colCnt = 3 );
    //带值构造
    TableRowItem( const QStringList &valList, const int size );

    static TableRowItem createTableRowFromVariantList( const QVariantList &varList );

    virtual QVariant getData( const int role = Qt::DisplayRole );

    // role 看成 列下标
    virtual void setData(const QVariant &val, const int role = Qt::DisplayRole );
    int colCnt() const;

private:
    RowDataMap   m_dataMap;
    QList< int > m_roleList;
};

class COMPONENTS_EXPORT TableDataStore{
public:
    TableDataStore( const size_t colCnt );

    TableRowItem getRowData( const size_t row );
    void appendRowData( const TableRowItem &newRow );

    QVariant getElementData( const size_t row, const size_t col );
    void setElementData( const size_t row, const size_t col, const QVariant &val );


    int rowCnt();
    int colCnt();

    void resetModelData( const QVector< TableRowItem > &modelData );

private:
    QVector< TableRowItem >    m_vecDatas;
    size_t                     m_colCnt = 0;
};
