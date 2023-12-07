#include "UnitComponentTest.h"
#include "ui_UnitComponentTest.h"

#include "CusGridView.h"

UnitComponentTest::UnitComponentTest(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UnitComponentTest)
{
    ui->setupUi(this);


    //初始化表格
    QStringList list = { QString::fromLocal8Bit( "质控品" ), QString::fromLocal8Bit( "批号" ) };
    ui->widget->init( list );

    for( int i = 0; i < 5; i++ ){
        QVariantList tableList;
        tableList << QString( "PT%1" ).arg( i );
        tableList << QString( "Val%1" ).arg( i );
        ui->widget->tableAppendRow( tableList );
    }


    connect( ui->pushButton, &QPushButton::clicked, [ this ](){
        ui->widget->nextPage();
    } );

    connect( ui->pushButton_2, &QPushButton::clicked, [ this ](){
        ui->widget->lastPage();
    } );

    connect( ui->pushButton_3, &QPushButton::clicked, [ this ](){
        QVector<TableRowItem> vecRowItems;
        for( int i = 1; i <= 209; i++ ){
            QString W = QString( "WW%1" ).arg( i );
            QString D = QString( "DD%1" ).arg( i );
            QString N = QString( "NN%1" ).arg( i );
            QString M = QString( "MM%1" ).arg( i );
            QString P = QString( "PP%1" ).arg( i );
            QVariantList tmpList = { W, D, N };

            auto tmpRowItem = TableRowItem::createTableRowFromVariantList( tmpList );
            vecRowItems << tmpRowItem;
        }

        ui->widget->resetTableModel( vecRowItems );
    } );

    connect( ui->pushButton_6, &QPushButton::clicked, [ this ](){
        ui->FlowFrame->getCheckedItemNames();
    } );


    testTurnPage();
    testCalendar();

}

UnitComponentTest::~UnitComponentTest()
{
    delete ui;
}

void UnitComponentTest::testTurnPage()
{
    connect( ui->turnPage_btn1, &QPushButton::clicked, [ this ](){
        ui->turnPageViewWidget->getCheckedNamesList();
    } );

    connect( ui->turnPageBtn_2, &QPushButton::clicked, [ this ](){
        QStringList names;

        for( int i = 0; i < 37; i++ ){
            names << QString::number( i );
        }
        
        ui->turnPageViewWidget->resetNameList( names );
    } );


}

void UnitComponentTest::testCalendar()
{
    connect( ui->pushButton_7, &QPushButton::clicked, ui->widget_2, &CusCalendarBox::exec );
    connect( ui->widget_2, &CusCalendarBox::accepted, [ this ](){
        ui->pushButton_7->setText( ui->widget_2->selectDate().toString( "yyyy-MM-dd" )  );
    } );

}

