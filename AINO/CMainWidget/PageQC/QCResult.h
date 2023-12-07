#ifndef QCRESULT_H
#define QCRESULT_H

#include <QWidget>

namespace Ui {
class QCResult;
}

class QCResult : public QWidget
{
    Q_OBJECT

public:
    explicit QCResult(QWidget *parent = nullptr);
    ~QCResult();

    void resetQCResultTable( const QVector<QVariantList> &rowDatas );

signals:
    void sigReJudegeClicked();
    void sigQueryClicked();
    void sigExportClicked();
    void sigDetailClicked();
    void sigLISSendClicked();
    void sigPrintClicked();
    void sigDeleteClicked();



private:
    void initConnection();

private:
    Ui::QCResult *ui;
};

#endif // QCRESULT_H
