#ifndef TURNPAGEGRIDVIEW_H
#define TURNPAGEGRIDVIEW_H

#include <QWidget>
#include "Components_global.h"
#include "CusGridView.h"

namespace Ui {
class TurnPageGridView;
}

using ItemInfosGroup = QVector<std::pair<QString, int> >;

class COMPONENTS_EXPORT TurnPageGridView : public QWidget
{
    Q_OBJECT

public:
    explicit TurnPageGridView(QWidget *parent = nullptr);
    ~TurnPageGridView();

    QStringList getCheckedNamesList() const;
    QVector<std::pair<QString, int >> getCheckedProjectsInfo();

    void resetNameList( QStringList names );
    void resetItemList( const ItemInfosGroup &items );


public slots:
    void onTurnNextPage();
    void onTurnLastPage();


protected:
    void removeAllTabs();
    QVector< QStringList >  getGroupNameList(QStringList &names );
    QVector< ItemInfosGroup > getGroupItemList( ItemInfosGroup items );


private:
    Ui::TurnPageGridView *ui;
    const int m_perPageItemCnt = 16;
    int       m_curTabIndex = 0;
};

#endif // TURNPAGEGRIDVIEW_H
