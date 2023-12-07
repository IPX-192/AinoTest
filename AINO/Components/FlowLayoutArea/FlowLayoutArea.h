#pragma once

#include <QWidget>
#include <QDebug>
#include "flowlayout.h"
#include "Components_global.h"
#include "FlowItemWidget.h"
#include <QFrame>
#include <QScrollArea>
#include <QScrollBar>

namespace Ui {
class FlowLayoutArea;
}

class COMPONENTS_EXPORT FlowLayoutArea : public QFrame
{
    Q_OBJECT

public:
    explicit FlowLayoutArea(QWidget *parent = nullptr);
    ~FlowLayoutArea();

    void appendWidget( FlowItemWidget *widget );

    QStringList getCheckedItemNames();

    void setPostion();

private:
    Ui::FlowLayoutArea *ui;
    FlowLayout  *m_pFlowLayout = nullptr;
};

