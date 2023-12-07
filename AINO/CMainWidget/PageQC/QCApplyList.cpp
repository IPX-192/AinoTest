#include "QCApplyList.h"
#include "ui_QCApplyList.h"

QCApplyList::QCApplyList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QCApplyList)
{
    ui->setupUi(this);
    QStringList headerList = { QString::fromLocal8Bit( "模块"),
                              QString::fromLocal8Bit( "质控品" ),
                              QString::fromLocal8Bit( "批号" ),
                              QString::fromLocal8Bit( "试管架号" ),
                              QString::fromLocal8Bit( "试管位置" ),
                              QString::fromLocal8Bit( "状态" ),
                              QString::fromLocal8Bit( "有效期" ),
                              QString::fromLocal8Bit( "项目 " ) };

    ui->QCApplyListTable->init( headerList );

    connect( ui->returnBtn, &QPushButton::clicked, this, &QCApplyList::sigReturnBtnClicked );



    //
//    QVector< TableRowItem > vec;
//    for( int i = 0; i < 79; i++ ){
//        QVariantList tableList;
//        tableList << QString::fromLocal8Bit( "PT%1" ).arg( i );
//        tableList << QString::fromLocal8Bit( "Val%1" ).arg( i );
//        tableList << QString::fromLocal8Bit( "有效期Q%1" ).arg( i );
//        tableList << QString::fromLocal8Bit( "有效期W%1" ).arg( i );
//        tableList << QString::fromLocal8Bit( "有效期E%1" ).arg( i );
//        tableList << QString::fromLocal8Bit( "有效期R%1" ).arg( i );
//        tableList << QString::fromLocal8Bit( "有效期C%1" ).arg( i );
//        tableList << QString::fromLocal8Bit( "有效期N%1" ).arg( i );
//        auto strList = convert2QStringList( tableList );
//        TableRowItem tmpRow( strList, 8 );

//        vec << tmpRow;
//    }

//    ui->QCApplyListTable->resetTableModel( vec );
}

QCApplyList::~QCApplyList()
{
    delete ui;
}

void QCApplyList::resetApplyList(const QVector<QStringList> &rowDatas)
{
    constexpr int rowSize = 8;
    QVector< TableRowItem > vecTmpRowItem;
    for( auto &ele : rowDatas ){
        TableRowItem tmpRow( ele, rowSize );

        vecTmpRowItem << tmpRow;
    }
    ui->QCApplyListTable->resetTableModel( vecTmpRowItem );
}

void QCApplyList::onNewQCApplyAvailable(const QVector<QVariantList> &list)
{
    qDebug() << "QC Apply Page recv new data...";
#if 0
    QVector< TableRowItem > vec;
    for( int i = 0; i < 79; i++ ){
        QVariantList tableList;
        tableList << QString::fromLocal8Bit( "PT%1" ).arg( i );
        tableList << QString::fromLocal8Bit( "Val%1" ).arg( i );
        tableList << QString::fromLocal8Bit( "有效期Q%1" ).arg( i );
        tableList << QString::fromLocal8Bit( "有效期W%1" ).arg( i );
        tableList << QString::fromLocal8Bit( "有效期E%1" ).arg( i );
        tableList << QString::fromLocal8Bit( "有效期R%1" ).arg( i );
        tableList << QString::fromLocal8Bit( "有效期C%1" ).arg( i );
        tableList << QString::fromLocal8Bit( "有效期N%1" ).arg( i );
        auto strList = convert2QStringList( tableList );
        TableRowItem tmpRow( strList, 8 );

        vec << tmpRow;
    }

    ui->QCApplyListTable->resetTableModel( vec );
#else
    QVector<QStringList> vecRowDatas;
    for( auto &ele : list ){
        auto stringList = convert2QStringList( ele );
        vecRowDatas << stringList;
    }

    resetApplyList( vecRowDatas );
#endif
}

QStringList QCApplyList::convert2QStringList(const QVariantList &src)
{
    auto getQCState = [](const int stateCode ) -> QString {
        if( 0 == stateCode ){
            return QString::fromLocal8Bit( "失控" );
        }

        if( 1 == stateCode ){
            return QString::fromLocal8Bit( "警告" );
        }

        if( 2 == stateCode ){
            return QString::fromLocal8Bit( "在控" );
        }

        if( 3 == stateCode ){
            return QString::fromLocal8Bit( "未质控" );
        }

        return QString::fromLocal8Bit( "失控" );
    };

    QStringList retList;
    constexpr int qcStateIndex = 5;

    for( int index = 0; index < 8; index++ ){
        auto itemVal = src.at( index );
        if( qcStateIndex == index ){
            retList << getQCState( itemVal.toInt() );
        }else{
            retList << itemVal.toString();
        }
    }

    return retList;

}
