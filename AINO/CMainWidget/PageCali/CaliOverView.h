#ifndef CALIOVERVIEW_H
#define CALIOVERVIEW_H

#include <QWidget>


namespace Ui {
class CaliOverView;
}

class CaliOverView : public QWidget
{
    Q_OBJECT

public:
    explicit CaliOverView(QWidget *parent = nullptr);
    ~CaliOverView();


    void init();


private:
    Ui::CaliOverView *ui;
};

#endif // CALIOVERVIEW_H
