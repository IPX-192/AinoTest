#include "QCOverview.h"
#include "ui_QCOverview.h"

#include "DBAccesser.h"

QCOverview::QCOverview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QCOverview)
{
    ui->setupUi(this);
    initUI();
}

QCOverview::~QCOverview()
{
    delete ui;
}

void QCOverview::setQCProjectTableDatas(const OverviewTableRowData &vecDatas)
{
    ui->QCProducets->resetTableModel( vecDatas );
}

void QCOverview::setQCProjectsListDatas(QStringList srcList)
{
    ui->QCProjects->resetNameList( srcList );
}

void QCOverview::onTableSelectRowChanged(const int rowIndex)
{
    qDebug() << "QC Overview Products select Row change to " << rowIndex;

    //1.获取点击的质控品
    m_tarRowProduct = ui->QCProducets->getTargetRowElement( rowIndex );
    auto qcproductName = m_tarRowProduct.getData( 0 );

    //2.获取目前的机器号
    auto curMachineID = m_machineID;

    //3.查询数据库
    QVariantMap condition = { { QCKeys::QCProductNames, qcproductName },
                             { QCKeys::MachineID, curMachineID }
                             };

    IQCDbAccesser   *pDataBase = DBAccesser::getInstance();
    auto records = pDataBase->queryQCOverviewProjects( condition );

    //4. 刷新中心区域的质控项目

}

void QCOverview::onSaveBtnClicked()
{
    //联合质控品， 咋显示？
    using namespace QCModel;
    //1.获取质控项目  状态
    auto selectQCProjects = ui->QCProjects->getCheckedProjectsInfo();


    //2. 获取质控品名称  批号  有效期
    auto QCProductName        = m_tarRowProduct.getData( 0 ).toString();
    auto QCProductGroupNumber = m_tarRowProduct.getData( 1 ).toString();
    auto QCProductValuedDate  = m_tarRowProduct.getData( 2 ).toString();


    //3.获取机器号
    auto machineID = m_machineID;

    //4.获取样本ID, 样本条码(这两样不用显示到申请列表的表格中), 试管架架号  试管架位置号  样本杯
    auto SampleID = ui->SampleID->getText();
    auto SamplCode = ui->SampleCode->getText();

    auto rackNumber = ui->RackNumberCBX->currentText();
    auto rackIndex  = ui->RackIndexCBX->currentText();
    auto SampleCup  = ui->SampleCupCBX->currentText();


    QVector< QVariantList > vecApplyListDatas;
    for( auto &ele : selectQCProjects ){
        // must ordered like this
        auto &[ qcProjectName, qcState ] = ele;
        QVariantList tmpRowDatas;
        tmpRowDatas << machineID << QCProductName << QCProductGroupNumber << rackNumber << rackIndex << qcState << QCProductValuedDate << qcProjectName;
        vecApplyListDatas << tmpRowDatas;
    }

    emit sigNewQCApplyAvailable( vecApplyListDatas );
}

void QCOverview::onM1BtnClicked()
{
    m_machineID = "M1";

    setMachineBtnStyle( 1, true );
    setMachineBtnStyle( 2, false );
    setMachineBtnStyle( 3, false );
    setMachineBtnStyle( 4, false );
}

void QCOverview::onM2BtnClicked()
{
    m_machineID = "M2";

    setMachineBtnStyle( 1, false );
    setMachineBtnStyle( 2, true );
    setMachineBtnStyle( 3, false );
    setMachineBtnStyle( 4, false );
}

void QCOverview::onM3BtnClicked()
{
    m_machineID = "M3";

    setMachineBtnStyle( 1, false );
    setMachineBtnStyle( 2, false );
    setMachineBtnStyle( 3, true );
    setMachineBtnStyle( 4, false );
}

void QCOverview::onM4BtnClicked()
{
    m_machineID = "M4";

    setMachineBtnStyle( 1, false );
    setMachineBtnStyle( 2, false );
    setMachineBtnStyle( 3, false );
    setMachineBtnStyle( 4, true );
}

void QCOverview::initUI()
{
    ui->SampleID->setTitle( QStringLiteral( "样本ID" ) );
    ui->SampleCode->setTitle( QStringLiteral( "样本条码" ) );
    //初始化表格
    QStringList list = { QString::fromLocal8Bit( "质控品" ), QString::fromLocal8Bit( "批号" ), QString::fromLocal8Bit( "有效期" ) };
    ui->QCProducets->init( list );

    connect( ui->QCApplyListBtn, &QPushButton::clicked,             this, &QCOverview::sigOPenQCApplyListBtnClicked );
    connect( ui->QCSaveBtn,      &QPushButton::clicked,             this, &QCOverview::onSaveBtnClicked );
    connect( ui->QCProducets,    &CusTableView::sigSelctRowChanged, this, &QCOverview::onTableSelectRowChanged );

    connect( ui->MachineM1,       &QPushButton::clicked,            this, &QCOverview::onM1BtnClicked );
    connect( ui->MachineM2,       &QPushButton::clicked,            this, &QCOverview::onM2BtnClicked );
    connect( ui->MachineM3,       &QPushButton::clicked,            this, &QCOverview::onM3BtnClicked );
    connect( ui->MachineM4,       &QPushButton::clicked,            this, &QCOverview::onM4BtnClicked );












    /*********************测试数据***************************/
    for( int i = 0; i < 79; i++ ){
        QVariantList tableList;
        tableList << QString::fromLocal8Bit( "PT%1" ).arg( i );
        tableList << QString::fromLocal8Bit( "Val%1" ).arg( i );
        tableList << QString::fromLocal8Bit( "有效期%1" ).arg( i );
        ui->QCProducets->tableAppendRow( tableList );
    }




    QVector< std::pair< QString, int> > itemList;
    for( int i = 0; i < 25; i++ ){
        QString itemName  = QString( "FT%1" ).arg( i );
        int     itemColor = i % 4;
        auto tmpItem = std::make_pair( itemName, itemColor );
        itemList << tmpItem;
    }
    ui->QCProjects->resetItemList( itemList );
}

void QCOverview::setMachineBtnStyle(const int btnIndex, const bool checked)
{
    QPushButton *tarBtn = nullptr;
    if( 1 == btnIndex ){
        tarBtn = ui->MachineM1;
    }

    if( 2 == btnIndex ){
        tarBtn = ui->MachineM2;
    }

    if( 3 == btnIndex ){
        tarBtn = ui->MachineM3;
    }

    if( 4 == btnIndex ){
        tarBtn = ui->MachineM4;
    }

    if( nullptr == tarBtn ){
        return;
    }

    if( checked ){
        tarBtn->setStyleSheet( QCStyleSheets::MachineChecked );
    }else{
        tarBtn->setStyleSheet( QCStyleSheets::MachineUnChecked );
    }
}

QString QCOverview::getSelctProjectsNames()
{
    //由于一个质控品可以质控多个项目（最多两个？）， 所以如果勾选了多个质控项目，在这里拼接成一个字符串
    QString selectNames;
    auto names = ui->QCProjects->getCheckedNamesList();

    for( auto &ele : names ){
        selectNames += ( ele + "#" );
    }

    return selectNames;
}
