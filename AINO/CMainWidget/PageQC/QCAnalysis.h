#ifndef QCANALYSIS_H
#define QCANALYSIS_H

#include <QWidget>

namespace Ui {
class QCAnalysis;
}

class QCAnalysis : public QWidget
{
    Q_OBJECT

public:
    explicit QCAnalysis(QWidget *parent = nullptr);
    ~QCAnalysis();

signals:
    void sigQueryBtnClicked();
    void sigTrendBtnClicked();

private:
    Ui::QCAnalysis *ui;
};

#endif // QCANALYSIS_H
