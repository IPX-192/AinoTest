#ifndef CUSLINEEDIT_H
#define CUSLINEEDIT_H

#include <QWidget>
#include "Components_global.h"

namespace Ui {
class CusLineEdit;
}

class COMPONENTS_EXPORT CusLineEdit : public QWidget
{
    Q_OBJECT

public:
    explicit CusLineEdit(QWidget *parent = nullptr);
    ~CusLineEdit();
    void setTitle( const QString &title );
    QString getText();

private:
    Ui::CusLineEdit *ui;
};

#endif // CUSLINEEDIT_H
