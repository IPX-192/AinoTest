#include "QCAnalysisTrend.h"
#include "ui_QCAnalysisTrend.h"

QCAnalysisTrend::QCAnalysisTrend(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QCAnalysisTrend)
{
    ui->setupUi(this);
    ui->ProjectsTable->init( QStringList() << QStringLiteral( "项目" ) );

    connect( ui->QueryBtn,  &QPushButton::clicked, this, &QCAnalysisTrend::sigQueryBtnClicked );
    connect( ui->ReturnBtn, &QPushButton::clicked, this, &QCAnalysisTrend::sigReturnBtnClicked );
}

QCAnalysisTrend::~QCAnalysisTrend()
{
    delete ui;
}
