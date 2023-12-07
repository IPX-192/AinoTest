#ifndef CUSADJUSTBOX_H
#define CUSADJUSTBOX_H

#include <QWidget>
#include "Components_global.h"
#include <QFrame>

namespace Ui {
class CusAdjustBox;
}

class COMPONENTS_EXPORT CusAdjustBox : public QFrame
{
    Q_OBJECT

public:
    explicit CusAdjustBox(QWidget *parent = nullptr);
    ~CusAdjustBox();

    void setDisplayList(const QStringList &newDisplayList);

private:
    void init();

private:
    Ui::CusAdjustBox *ui;

    QStringList m_displayList;
    int         m_curIndex = 0;
};

#endif // CUSADJUSTBOX_H
