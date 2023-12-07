#ifndef CALICURVEDRAW_H
#define CALICURVEDRAW_H

#include <QWidget>
#include <QtCharts>

namespace Ui {
class CaliCurveDraw;
}

class CaliCurveDraw : public QWidget
{
    Q_OBJECT

public:
    explicit CaliCurveDraw(QWidget *parent = nullptr);
    ~CaliCurveDraw();


    void    createChart(); //创建图表
    void    prepareData(); //更新数据
    void    updateFromChart(); //从图表更新到界面

private:
    QLineSeries *m_CurSeries; //当前序列
    QValueAxis  *m_CurAxis; //当前坐标轴

private:
    Ui::CaliCurveDraw *ui;
};

#endif // CALICURVEDRAW_H
