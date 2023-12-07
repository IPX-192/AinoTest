#ifndef QCANALYSISQUERY_H
#define QCANALYSISQUERY_H

#include <QWidget>

namespace Ui {
class QCAnalysisQuery;
}

class QCAnalysisQuery : public QWidget
{
    Q_OBJECT

public:
    explicit QCAnalysisQuery(QWidget *parent = nullptr);
    ~QCAnalysisQuery();

signals:
    void sigResetBtnClicked();
    void sigConfirmBtnClicked();
    void sigReturnBtnClicked();

private:
    Ui::QCAnalysisQuery *ui;
};

#endif // QCANALYSISQUERY_H
