#include "QCResult.h"
#include "ui_QCResult.h"

QCResult::QCResult(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QCResult)
{
    ui->setupUi(this);

    QStringList headerList = { QString::fromLocal8Bit( "模块"),
                              QString::fromLocal8Bit( "项目" ),
                              QString::fromLocal8Bit( "结果" ),
                              QString::fromLocal8Bit( "单位" ),
                              QString::fromLocal8Bit( "发光值" ),
                              QString::fromLocal8Bit( "标记" ),
                              QString::fromLocal8Bit( "规则" ),
                              };

    ui->QCResultTable->init( headerList );

    initConnection();


    /**********************测试数据************************/
    QVector<QVariantList> vecRets;
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

        vecRets << tableList;
    }

    resetQCResultTable( vecRets );


}

QCResult::~QCResult()
{
    delete ui;
}

void QCResult::resetQCResultTable(const QVector<QVariantList> &rowDatas)
{
    QVector< TableRowItem > vecRows;

    for( auto &ele : rowDatas ){
        auto tmpRow = TableRowItem::createTableRowFromVariantList( ele );
        vecRows << tmpRow;
    }

    ui->QCResultTable->resetTableModel( vecRows );
}

void QCResult::initConnection()
{
    connect( ui->ReJudgeBtn, &QPushButton::clicked, this, &QCResult::sigReJudegeClicked );
    connect( ui->QueryBtn, &QPushButton::clicked, this, &QCResult::sigQueryClicked );
    connect( ui->ExportBtn, &QPushButton::clicked, this, &QCResult::sigExportClicked );
    connect( ui->DetailBtn, &QPushButton::clicked, this, &QCResult::sigDetailClicked );
    connect( ui->LISBtn, &QPushButton::clicked, this, &QCResult::sigLISSendClicked );
    connect( ui->PrintBtn, &QPushButton::clicked, this, &QCResult::sigPrintClicked );
    connect( ui->DeleteBtn, &QPushButton::clicked, this, &QCResult::sigDeleteClicked );
}
