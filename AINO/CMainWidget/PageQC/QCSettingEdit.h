#ifndef QCSETTINGEDIT_H
#define QCSETTINGEDIT_H

#include <QWidget>
#include "QCSettingAddByManual.h"

namespace Ui {
class QCSettingEdit;
}

class QCSettingEdit : public QWidget
{
    Q_OBJECT

public:
    explicit QCSettingEdit(QWidget *parent = nullptr);
    ~QCSettingEdit();


signals:
    void sigSaveBtnClicked();
    void sigReturnBtnClicked();

private:
    Ui::QCSettingEdit *ui;
};

#endif // QCSETTINGEDIT_H
