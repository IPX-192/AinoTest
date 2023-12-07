#ifndef CALIAPPLYLIST_H
#define CALIAPPLYLIST_H

#include <QWidget>

namespace Ui {
class CaliApplyList;
}

class CaliApplyList : public QWidget
{
    Q_OBJECT

public:
    explicit CaliApplyList(QWidget *parent = nullptr);
    ~CaliApplyList();

    void init();

private:
    Ui::CaliApplyList *ui;
};

#endif // CALIAPPLYLIST_H
