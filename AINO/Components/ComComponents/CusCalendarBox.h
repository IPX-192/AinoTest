#ifndef CUSCALENDARBOX_H
#define CUSCALENDARBOX_H

#include <QDialog>
#include <QWidget>
#include "Components_global.h"
#include <QDateTime>
#include <QCalendarWidget>
#include <QDate>


namespace Ui {
class CusCalendarBox;
}

class COMPONENTS_EXPORT CusCalendarBox : public QDialog
{
    Q_OBJECT

public:
    explicit CusCalendarBox(QWidget *parent = nullptr);
    ~CusCalendarBox();

    QDate selectDate() const;
    QString getSelectDateString();

private:
    Ui::CusCalendarBox *ui;
    QDate               m_date = QDate::currentDate();
};

#endif // CUSCALENDARBOX_H
