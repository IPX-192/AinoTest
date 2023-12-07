#ifndef QCAPPLYLIST_H
#define QCAPPLYLIST_H

#include <QWidget>
#include "../Table/CusTableView.h"

namespace Ui {
class QCApplyList;
}

class QCApplyList : public QWidget
{
    Q_OBJECT

public:
    explicit QCApplyList(QWidget *parent = nullptr);
    ~QCApplyList();

    void resetApplyList(const QVector<QStringList> &rowDatas );

public slots:
    void onNewQCApplyAvailable( const QVector<QVariantList> &list );
signals:
    void sigReturnBtnClicked();

private:
    QStringList convert2QStringList( const QVariantList &src );

private:
    Ui::QCApplyList *ui;
};

#endif // QCAPPLYLIST_H
