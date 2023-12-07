#pragma once

#include <QWidget>

namespace Ui {
class CusComBox;
}

class CusComBox : public QWidget
{
    Q_OBJECT

public:
    explicit CusComBox(QWidget *parent = nullptr);
    ~CusComBox();

private:
    Ui::CusComBox *ui;
};

