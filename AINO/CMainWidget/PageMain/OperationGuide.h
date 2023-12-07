#ifndef OPERATIONGUIDE_H
#define OPERATIONGUIDE_H

#include <QWidget>

namespace Ui {
class OperationGuide;
}

class OperationGuide : public QWidget
{
    Q_OBJECT

public:
    explicit OperationGuide(QWidget *parent = 0);
    ~OperationGuide();

private:
    Ui::OperationGuide *ui;
};

#endif // OPERATIONGUIDE_H
