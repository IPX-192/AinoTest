#ifndef QCSETTINGADDBYSCANF_H
#define QCSETTINGADDBYSCANF_H

#include <QWidget>

namespace Ui {
class QCSettingAddByScanf;
}

class QCSettingAddByScanf : public QWidget
{
    Q_OBJECT

public:
    explicit QCSettingAddByScanf(QWidget *parent = nullptr);
    ~QCSettingAddByScanf();

signals:
    void sigSaveBtnClicked();
    void sigReturnBtnClicked();

private:
    Ui::QCSettingAddByScanf *ui;
};

#endif // QCSETTINGADDBYSCANF_H
