#pragma once

#include "../Components_global.h"
#include <QWidget>
#include "CusTableModel.h"
#include <QHeaderView>
#include <QResizeEvent>
#include "../ComComponents/TablePageButton.h"

namespace Ui {
class CusTableView;
}

class COMPONENTS_EXPORT CusTableView : public QWidget
{
    Q_OBJECT

public:
    explicit CusTableView(QWidget *parent = nullptr);
    ~CusTableView();

    void init( const QStringList &headerList );

    void setHeaderList( const QStringList &headerList );

    void tableAppendRow( const TableRowItem &newRow );
    void tableAppendRow( const QVariantList &valList );

    int curIndex() const;

    void curPage();

    void resetTableModel( const QVector< TableRowItem > &modelData );

    void refreshPageInfo();

    TableRowItem getTargetRowElement( const int rowIndex );

signals:
    void sigSelctRowChanged( const int rowIndex );

protected:
    virtual void resizeEvent( QResizeEvent *evt ) override;

public slots:
    void nextPage();
    void lastPage();

private:
    Ui::CusTableView *ui;
    CusTableModel *m_pModel = nullptr;
    QHeaderView   *m_pHeaderView = nullptr;

    int            m_curPageIndex = 1;


//    const int perPageDisplayCnt =


};

