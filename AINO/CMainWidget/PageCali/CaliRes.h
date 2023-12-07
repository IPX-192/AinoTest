#ifndef CALIRES_H
#define CALIRES_H

#include <QWidget>

namespace Ui {
class CaliRes;
}

class CaliRes : public QWidget
{
    Q_OBJECT

public:
    explicit CaliRes(QWidget *parent = nullptr);
    ~CaliRes();

private:
    Ui::CaliRes *ui;
};

#endif // CALIRES_H
