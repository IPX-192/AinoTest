#ifndef COMMONDEFINE_H
#define COMMONDEFINE_H

#include <QString>
#include <tuple>
#include <QDebug>
#include "../../Components/Table/CusTableView.h"


namespace Common {
enum Page{
    Main = 0,
    Apply,
    Reagents,
    Calibration,
    QC,
    Data,
    Use
};

enum Page_CaliApply{
    OverView,
    ApplyList
};

enum Page_CaliRes{
    ResInitPage,
    ResDetails,
    ResTrend
};

// 质控结果模块页面
enum QCResultPageIndex{
    Home = 0,
    Query = 1,
    ResultDetail = 2,

};

//质控分析页面
enum QCAnalysisPageIndex{
    QC_Analysis_Home = 0,
    QC_Analysis_Query = 1,
    QC_Analysis_Trend = 2,
};

//质控图
enum QCChartPageIndex{
    QC_Chart_LJ = 0,
    QC_Chart_TP = 1,
};

//质控设置
enum QCSettingPageIndex{
    QC_Setting_Home   = 0,
    QC_Setting_Scanf  = 1,
    QC_Setting_Manual = 2,
    QC_Setting_Edit   = 3,
    QC_Setting_Rule   = 4,
};
}

namespace QCModel{
//  质控总览页面 最左边表格  质控品 批号  有效期
using OverviewTableRowData = QVector< TableRowItem >;
using QEnumMap = QMap< int, QVariant >;
using QCProjectInfoPair = std::pair< QString, int >;
using QCProjectInfoPairs = QVector< QCProjectInfoPair >;

//质控申请列表表头
enum QCApplyListRoles{
    MachineID = 0,
    QCProductName,
    QCGroupNumber,
    TrackNumber,
    TrackIndex,
    QCState,
    ValuedDate,
    QCProjectName
};
}

#endif // COMMONDEFINE_H

