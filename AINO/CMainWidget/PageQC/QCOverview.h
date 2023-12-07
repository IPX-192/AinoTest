#ifndef QCOVERVIEW_H
#define QCOVERVIEW_H

#include <QWidget>
#include "commondefine.h"
#include "QCheaders.h"

namespace Ui {
class QCOverview;
}

using namespace QCModel;

namespace QCProjectsState{
enum CheckedState{
    UnChecked = 0x00000,
    Checked = 0x00001,
};

enum QCState{
    QC_Lose   = 0x00010,
    QC_Waring = 0x00100,
    QC_IN     = 0x01000,
    QC_NO     = 0x10000,
};
}


class QCOverview : public QWidget
{
    Q_OBJECT

public:
    explicit QCOverview(QWidget *parent = nullptr);
    ~QCOverview();

    // 设置质控品表格
    void setQCProjectTableDatas( const OverviewTableRowData &vecDatas );

    //设置项目区域项目名
    void setQCProjectsListDatas( QStringList srcList );

signals:
    void sigOPenQCApplyListBtnClicked();
    void sigSaveQCBtnClicked();
    void sigNewQCApplyAvailable( const QVector<QVariantList> &qcApplyList );

protected slots:
    //选择不同的质控品
    void onTableSelectRowChanged( const int rowIndex );

    // 响应 保存 按钮点击
    void onSaveBtnClicked();

    //
    void onM1BtnClicked();
    void onM2BtnClicked();
    void onM3BtnClicked();
    void onM4BtnClicked();

private:
    void initUI();
    void setMachineBtnStyle( const int btnIndex, const bool checked );

    QString getSelctProjectsNames();

private:
    Ui::QCOverview *ui;
    QString         m_machineID = "M1";
    TableRowItem    m_tarRowProduct;
};

#endif // QCOVERVIEW_H
