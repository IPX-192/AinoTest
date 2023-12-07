#ifndef POPNEWCALIPRODUCT_H
#define POPNEWCALIPRODUCT_H

#include <QDialog>

namespace Ui {
class PopNewCaliProduct;
}

class PopNewCaliProduct : public QDialog
{
    Q_OBJECT

public:
    explicit PopNewCaliProduct(QWidget *parent = nullptr);
    ~PopNewCaliProduct();


signals:
    void sigNewCaliProductReset();
    void sigNewCaliProductOk();
    void sigNewCaliProductCancle();

private:
    Ui::PopNewCaliProduct *ui;
};

#endif // POPNEWCALIPRODUCT_H
