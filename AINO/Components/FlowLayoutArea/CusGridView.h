#ifndef CUSGRIDVIEW_H
#define CUSGRIDVIEW_H

#include <QWidget>
#include "Components_global.h"

namespace Ui {
class CusGridView;
}

class COMPONENTS_EXPORT CusGridView : public QWidget
{
    Q_OBJECT

public:
    explicit CusGridView(QWidget *parent = nullptr);
    ~CusGridView();

    void setItemNames( const QStringList &names );
    QStringList getCheckedNames() const;

    void setItems( const QVector< std::pair< QString, int > > &items );
    QVector< std::pair< QString, int > > getCheckedItemInfo() const;

private:
    Ui::CusGridView *ui;
};

#endif // CUSGRIDVIEW_H
