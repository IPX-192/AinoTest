#include "QCResultQuery.h"
#include "ui_QCResultQuery.h"
#include "../ComComponents/CusCalendarBox.h"
#include <QRegExp>
#include "DBAccesser.h"


QCResultQuery::QCResultQuery(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QCResultQuery)
{
    ui->setupUi(this);

    connect( ui->SelectAllBtn, &QPushButton::clicked, this, &QCResultQuery::sigSelectAllBtnClicked );
    connect( ui->ConfirmBtn,   &QPushButton::clicked, this, &QCResultQuery::onConfirmBtnClicked );
    connect( ui->returnBtn,    &QPushButton::clicked, this, &QCResultQuery::sigReturnBtnClicked );

    connect( ui->checkBoxQCProduct, &QCheckBox::stateChanged, [ this ]( int state ){
        if( Qt::CheckState::Checked == state ){
            ui->checkBoxQCProjects->setCheckState( Qt::Unchecked );
            m_qeuryType = Query_By_Product;
        }
    } );

    connect( ui->checkBoxQCProjects, &QCheckBox::stateChanged, [ this ]( int state ){
        if( Qt::CheckState::Checked == state ){
            ui->checkBoxQCProduct->setCheckState( Qt::Unchecked);
            m_qeuryType = Query_By_Project;
        }
    } );

    ui->QCProductsNumInput->setTitle( QString::fromLocal8Bit( "质控品批号:" ) );

    connect( ui->startDateBtn, &QPushButton::clicked, [ this ](){
        CusCalendarBox dateSelect;
        dateSelect.exec();
        ui->startDateBtn->setText( dateSelect.getSelectDateString() );
    } );

    connect( ui->endDateBtn, &QPushButton::clicked, [ this ](){
        CusCalendarBox dateSelect;
        dateSelect.exec();
        ui->endDateBtn->setText( dateSelect.getSelectDateString() );
    } );

    auto today = QDate::currentDate();
    ui->startDateBtn->setText( today.toString( "yyyy-MM-dd" ) );
    ui->endDateBtn->setText( today.toString( "yyyy-MM-dd" ) );
}

QCResultQuery::~QCResultQuery()
{
    delete ui;
}

void QCResultQuery::onConfirmBtnClicked()
{
    using namespace QCKeys;
    QVariantMap conditionMap;

    //1.获取开始和结束的日期 - 时间
    auto startDateTime = ui->startDateBtn->text() + " " + ui->StartClockTimeArea->getClockTime();
    auto endDateTime   = ui->endDateBtn->text() + " " + ui->endClockTimeArea->getClockTime();

    conditionMap[ QCKeys::startDateTime ] = startDateTime;
    conditionMap[ QCKeys::endDateTime ]   = endDateTime;


    //2.1 如果是按质控品查询   获取质控品名称  批号
    auto qcProductNames = ui->QCProductsSetArea->getCheckedNamesList();
    auto groupNumuber = ui->QCProductsNumInput->getText();


    //2.2.如果是按质控项目查询  获取项目名称
    auto qcProjectNames = ui->QCProductsSetArea->getCheckedNamesList();


    conditionMap[ QCKeys::queryType ] = m_qeuryType;
    if( Query_By_Project == m_qeuryType ){
        conditionMap[ QCKeys::QCProjectNames ] = qcProjectNames;
    }

    if( Query_By_Product == m_qeuryType ){
        conditionMap[ QCKeys::QCProductNames ]       = qcProductNames;
        conditionMap[ QCKeys::QCProductGroupNumber ] = groupNumuber;
    }


    //3. 按条件从数据库查询
    IQCDbAccesser *pDataBase = DBAccesser::getInstance();
    auto records = pDataBase->queryQCResultByCondition( conditionMap );

    //4.更新表格,, todo

}

void QCResultQuery::init()
{

}
