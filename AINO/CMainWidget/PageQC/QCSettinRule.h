#ifndef QCSETTINRULE_H
#define QCSETTINRULE_H

#include <QWidget>

namespace Ui {
class QCSettinRule;
}

class QCSettinRule : public QWidget
{
    Q_OBJECT

public:
    explicit QCSettinRule(QWidget *parent = nullptr);
    ~QCSettinRule();

signals:
    void sigSaveBtnClicked();
    void sigReturnBtnClicked();

private:
    Ui::QCSettinRule *ui;
};

#endif // QCSETTINRULE_H
