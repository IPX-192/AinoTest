#pragma once

#include <QWidget>
#include "Table/CusTableModel.h"
#include <QTableView>

QT_BEGIN_NAMESPACE
namespace Ui { class UnitComponentTest; }
QT_END_NAMESPACE

class UnitComponentTest : public QWidget
{
    Q_OBJECT

public:
    UnitComponentTest(QWidget *parent = nullptr);
    ~UnitComponentTest();

private:
    void testTurnPage();

    void testCalendar();

private:
    Ui::UnitComponentTest *ui;
};
