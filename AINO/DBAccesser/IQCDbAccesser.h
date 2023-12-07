#ifndef IQCDBACCESSER_H
#define IQCDBACCESSER_H

#include "DBAccesser_global.h"

namespace QCKeys{
const QString startDateTime        = "StartDateTime";
const QString endDateTime          = "EndDateTime";
const QString queryType            = "QueryType";
const QString QCProjectNames       = "QCProjectNames";
const QString QCProductNames       = "QCProductNames";
const QString QCProductGroupNumber = "QCProductGroupNumber";
const QString MachineID            = "MachineID";
}

class DBACCESSER_EXPORT IQCDbAccesser
{
public:
    // 质控总览 左边的质控品表格( 3列 )
    virtual TableRowRecords queryQCOverviewProducts() const = 0;

    // 质控总览 中间的质控项目
    //  质控项目是根据质控品名称查询还是啥?
    virtual TableRowRecords queryQCOverviewProjects( const QVariantMap &condition ) const = 0;

    //质控结果 查询 所有
    virtual TableRowRecords queryQCResultAll() const = 0;

    //质控结果查询  条件查询
    virtual TableRowRecords queryQCResultByCondition( const QVariantMap &condition ) const = 0;

};

#endif // IQCDBACCESSER_H
