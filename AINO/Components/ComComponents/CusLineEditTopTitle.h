#ifndef CUSLINEEDITTOPTITLE_H
#define CUSLINEEDITTOPTITLE_H

#include <QWidget>
#include "Components_global.h"

namespace Ui {
class CusLineEditTopTitle;
}

class COMPONENTS_EXPORT CusLineEditTopTitle : public QWidget
{
    Q_OBJECT

public:
    explicit CusLineEditTopTitle(QWidget *parent = nullptr);
    ~CusLineEditTopTitle();

    void setTitle( const QString &title );
    QString getText();

private:
    Ui::CusLineEditTopTitle *ui;
};

#endif // CUSLINEEDITTOPTITLE_H
