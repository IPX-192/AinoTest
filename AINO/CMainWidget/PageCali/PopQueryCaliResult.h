#ifndef POPQUERYCALIRESULT_H
#define POPQUERYCALIRESULT_H

#include <QDialog>

namespace Ui {
class PopQueryCaliResult;
}

class PopQueryCaliResult : public QDialog
{
    Q_OBJECT

public:
    explicit PopQueryCaliResult(QWidget *parent = nullptr);
    ~PopQueryCaliResult();

signals:
    void sigCaliResQueryOk();
    void sigCaliResQueryCancle();

private:
    Ui::PopQueryCaliResult *ui;
};

#endif // POPQUERYCALIRESULT_H
