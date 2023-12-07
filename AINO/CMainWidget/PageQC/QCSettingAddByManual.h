#ifndef QCSETTINGADDBYMANUAL_H
#define QCSETTINGADDBYMANUAL_H

#include <QWidget>

namespace Ui {
class QCSettingAddByManual;
}

class QCSettingAddByManual : public QWidget
{
    Q_OBJECT

public:
    explicit QCSettingAddByManual(QWidget *parent = nullptr);
    ~QCSettingAddByManual();

signals:
    void sigSaveBtnClicked();
    void sigReturnBtnClicked();

private:
    Ui::QCSettingAddByManual *ui;
};

#endif // QCSETTINGADDBYMANUAL_H
