#include "FlowItemWidget.h"
#include "ui_FlowItemWidget.h"
#include "../CommonStyleSheets.h"

FlowItemWidget::FlowItemWidget(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FlowItemWidget)
{
    ui->setupUi(this);
    ui->label->setText( "--" );
    ui->frame->setStyleSheet( StyleSheets::FlowItemWaringQC_UnChecked );

}

FlowItemWidget::~FlowItemWidget()
{
    delete ui;
}

void FlowItemWidget::setCheckState(const bool newCheckState)
{
    /*
    质控失控：背景标记红色
    质控警告：背景标记橙色
    质控在控：背景标记白色；
    未做质控：当天未开展质控测试，背景标记灰色。
*/
    using namespace StyleSheets;
    m_checkState = newCheckState;

    auto handleCheckedState = [ this ](){

        //红色  失控 选中状态
        if( ItemColor::Red == m_color ){
            ui->frame->setStyleSheet( StyleSheets::FlowItemLoseQC_Checked );
        }

        //橙色  警告 选中状态
        if( ItemColor::Orange == m_color ){
            ui->frame->setStyleSheet( StyleSheets::FlowItemWaringQC_Checked );
        }

        //白色； 在控 选中状态
        if( ItemColor::White == m_color ){
            ui->frame->setStyleSheet( StyleSheets::FlowItemInQC_Checked );
        }

        //灰色  未质控 选中状态
        if( ItemColor::Gray == m_color ){
            ui->frame->setStyleSheet( StyleSheets::FlowItemUnQC_Checked );
        }

    };

    auto handleUnCheckedState = [ this ](){
        //红色 失控 未选中状态
        if( ItemColor::Red == m_color ){
            ui->frame->setStyleSheet( StyleSheets::FlowItemLoseQC_UnChecked );
        }

        //橙色 警告 未选中状态
        if( ItemColor::Orange == m_color ){
            ui->frame->setStyleSheet( StyleSheets::FlowItemWaringQC_UnChecked );
        }

        //白色 在控  未选中状态
        if( ItemColor::White == m_color ){
            ui->frame->setStyleSheet( StyleSheets::FlowItemInQC_UnChecked );
        }

        //灰色 未质控  未选中状态
        if( ItemColor::Gray == m_color ){
            ui->frame->setStyleSheet( StyleSheets::FlowItemUnQC_UnChecked );
        }
    };

    if( newCheckState ){
        handleCheckedState();
    }else{
        handleUnCheckedState();
    }
}

void FlowItemWidget::setItemName(const QString &name)
{
    ui->label->setText( name );

    if( name == "--" ){
        m_checkAble = false;
    }else{
        m_checkAble = true;
    }
}

QString FlowItemWidget::getItemName() const
{
    return ui->label->text();
}

void FlowItemWidget::mousePressEvent(QMouseEvent *event)
{
    if( !m_checkAble ){
        return;
    }

    m_checkState = !m_checkState;
    setCheckState( m_checkState );
}

FlowItemWidget::ItemColor FlowItemWidget::color() const
{
    return m_color;
}

void FlowItemWidget::setColor(const ItemColor newColor)
{
    m_color = newColor;
    setCheckState( m_checkState );
}

bool FlowItemWidget::checkState() const
{
    return m_checkState;
}
