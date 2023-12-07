#ifndef MACHINEINFO_H
#define MACHINEINFO_H

#include <QWidget>

namespace Ui {
class MachineInfo;
}

class MachineInfo : public QWidget
{
    Q_OBJECT

public:
    explicit MachineInfo(QWidget *parent = 0);
    ~MachineInfo();

private:
    Ui::MachineInfo *ui;
};

#endif // MACHINEINFO_H
