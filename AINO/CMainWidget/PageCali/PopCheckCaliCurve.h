#ifndef POPCHECKCALICURVE_H
#define POPCHECKCALICURVE_H

#include <QDialog>
#include <QtCharts>

namespace Ui {
class PopCheckCaliCurve;
}

class PopCheckCaliCurve : public QDialog
{
    Q_OBJECT

public:
    explicit PopCheckCaliCurve(QWidget *parent = nullptr);
    ~PopCheckCaliCurve();


    void    createChart(); //创建图表
    void    prepareData(); //更新数据
    void    updateFromChart(); //从图表更新到界面


signals:
    void sigCheckCaliCurve();

private:
    Ui::PopCheckCaliCurve *ui;

    QLineSeries *m_CurSeries; //当前序列
    QValueAxis  *m_CurAxis; //当前坐标轴

};

#endif // POPCHECKCALICURVE_H
