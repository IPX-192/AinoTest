#ifndef CALIRESDETAILS_H
#define CALIRESDETAILS_H

#include <QWidget>

namespace Ui {
class CaliResDetails;
}

class CaliResDetails : public QWidget
{
    Q_OBJECT

public:
    explicit CaliResDetails(QWidget *parent = nullptr);
    ~CaliResDetails();

    void initialize();


private:
    Ui::CaliResDetails *ui;
};

#endif // CALIRESDETAILS_H
