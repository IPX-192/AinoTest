#pragma once

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QFrame>
#include "Components_global.h"

namespace Ui {
class TablePageButton;
}

class COMPONENTS_EXPORT TablePageButton : public QFrame
{
    Q_OBJECT

public:
    explicit TablePageButton(QWidget *parent = nullptr);
    ~TablePageButton();

    void setTotalPage( const size_t totalPage );
    void setCurPage( const size_t curPageIndex );

signals:
    void sigTurnLastPage();
    void sigTurnNextPage();


protected:

    void updatePageDisplay();

private:
    Ui::TablePageButton *ui;

    size_t  m_totalPage = 0;
    size_t m_curPageIndex = 0;
};

