#ifndef CALIRESULT_H
#define CALIRESULT_H

#include <QWidget>

namespace Ui {
class CaliResult;
}

class CaliResult : public QWidget
{
    Q_OBJECT

public:
    explicit CaliResult(QWidget *parent = nullptr);
    ~CaliResult();


    void initialize();


private:
    Ui::CaliResult *ui;
};

#endif // CALIRESULT_H
