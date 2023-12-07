#pragma once

#include <QFrame>
#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class FlowItemWidget;
}

class FlowItemWidget : public QFrame
{
    Q_OBJECT

public:
    enum ItemColor{
        Red = 0,
        Orange,
        White,
        Gray,
    };


    explicit FlowItemWidget( QWidget *parent = nullptr);
    ~FlowItemWidget();

    bool checkState() const;
    void setCheckState(const bool newCheckState);

    void setItemName( const QString &name );
    QString getItemName() const;


    FlowItemWidget::ItemColor color() const;
    void setColor(const ItemColor newColor);

protected:
    virtual void mousePressEvent( QMouseEvent *event ) override;


private:
    Ui::FlowItemWidget *ui;
    bool               m_checkState = false;
    bool               m_checkAble  = false;
    ItemColor          m_color      = ItemColor::Orange;
};

