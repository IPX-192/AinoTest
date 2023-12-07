#ifndef CALIRESTREND_H
#define CALIRESTREND_H

#include <QWidget>
#include <QtCharts>

namespace Ui {
class CaliResTrend;
}

class CaliResTrend : public QWidget
{
    Q_OBJECT

public:
    explicit CaliResTrend(QWidget *parent = nullptr);
    ~CaliResTrend();

    void    createChart(); //创建图表
    void    prepareData(); //更新数据
    void    updateFromChart(); //从图表更新到界面

private:
    Ui::CaliResTrend *ui;


private:
    QLineSeries *m_CurSeries; //当前序列
    QValueAxis  *m_CurAxis; //当前坐标轴
};

#endif // CALIRESTREND_H
