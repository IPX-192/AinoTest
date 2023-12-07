#ifndef CALIPRODUCTMANAGER_H
#define CALIPRODUCTMANAGER_H

#include <QWidget>

namespace Ui {
class CaliProductManager;
}

class CaliProductManager : public QWidget
{
    Q_OBJECT

public:
    explicit CaliProductManager(QWidget *parent = nullptr);
    ~CaliProductManager();

private:
    Ui::CaliProductManager *ui;
};

#endif // CALIPRODUCTMANAGER_H
