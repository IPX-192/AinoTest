#include "TablePageButton.h"
#include "ui_TablePageButton.h"

TablePageButton::TablePageButton(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TablePageButton)
{
    ui->setupUi(this);
    updatePageDisplay();
    connect( ui->pushButton, &QPushButton::clicked, [ this ](){
        emit sigTurnLastPage();
    } );

    connect( ui->pushButton_2, &QPushButton::clicked, [ this ](){
        emit sigTurnNextPage();
    } );
}

TablePageButton::~TablePageButton()
{
    delete ui;
}

void TablePageButton::setTotalPage(const size_t totalPage)
{
    m_totalPage = totalPage;
    updatePageDisplay();
}

void TablePageButton::setCurPage(const size_t curPageIndex)
{
    m_curPageIndex = curPageIndex;
    updatePageDisplay();
}

void TablePageButton::updatePageDisplay()
{
    QString str = QString( "%1 / %2" ).arg( m_curPageIndex ).arg( m_totalPage );
    ui->label->setText( str );
}
