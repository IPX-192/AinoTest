#ifndef QCSETTING_H
#define QCSETTING_H

#include <QWidget>

namespace Ui {
class QCSetting;
}

class QCSetting : public QWidget
{
    Q_OBJECT

public:
    explicit QCSetting(QWidget *parent = nullptr);
    ~QCSetting();

signals:
    void sigScanfBtnClicked();
    void sigManualBtnClicked();
    void sigEditBtnClicked();
    void sigDeleteBtnClicked();
    void sigRuleBtnClicked();

private:
    Ui::QCSetting *ui;
};

#endif // QCSETTING_H
