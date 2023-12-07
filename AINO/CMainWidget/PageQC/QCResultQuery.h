#ifndef QCRESULTQUERY_H
#define QCRESULTQUERY_H

#include <QWidget>

namespace Ui {
class QCResultQuery;
}

class QCResultQuery : public QWidget
{
    Q_OBJECT

    enum QueryType{
        Query_By_Project = 0,
        Query_By_Product = 1,
    };

public:
    explicit QCResultQuery(QWidget *parent = nullptr);
    ~QCResultQuery();

protected slots:
    void onConfirmBtnClicked();

signals:
    void sigSelectAllBtnClicked();
    void sigConfirmBtnClicked( const QVariantMap &conditions );
    void sigReturnBtnClicked();

private:
    void init();

private:
    Ui::QCResultQuery *ui;
    short     m_qeuryType = Query_By_Product;
};

#endif // QCRESULTQUERY_H
