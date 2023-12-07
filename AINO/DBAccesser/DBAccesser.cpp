#include "DBAccesser.h"

DBAccesser::DBAccesser()
{

}

DBAccesser *DBAccesser::getInstance()
{
    static DBAccesser *instance = new DBAccesser();
    return instance;
}

bool DBAccesser::isDataBaseAvailable()
{
    return false;
}


/*
 *@brief:
 *
 *查询所有的质控品
 *
 *@param:
 *
 *
 *@return:
 *
 *查询结果: 只需要三列, 按 质控品，批号，有效期 排列
*/
TableRowRecords DBAccesser::queryQCOverviewProducts() const
{
    return TableRowRecords();
}

/*
 *@brief:
 *
 *1.键值对key定义在 IQCDbAccesser.h 中
 *
 *2.先判断是根据质控品查询还是根据质控项目查询:  key -> QueryType,   value->  ( 0 -> 质控项目；  1 -> 质控品 )
 *
 *3.1如果是根据  质控品  查询, 查询条件如下:
 *                              a.StartDateTime          开始时间
 *                              b.EndDateTime            结束时间
 *                              c.QCProductNames         质控品名称
 *                              d.QCProductGroupNumber   质控品批号
 *
 *3.2如果是根据  质控项目  查询, 查询条件如下:
 *                              a.StartDateTime
 *                              b.EndDateTime
 *                              c.QCProjectNames         质控项目名称
 *
 *@param:
 *condition
 *存储所有键值对的QMap
 *
 *@return:
 *
 *查询结果: 8列， 按 质控品，批号，试管架架号，试管位置，申请状态，申请时间，结束时间，LIS 排列
 *
*/
TableRowRecords DBAccesser::queryQCResultByCondition(const QVariantMap &condition) const
{
    return TableRowRecords();
}


/*
 *@brief:
 *
 *1.查询质控品和机器号对应的所有质控项目
 *2.键值对key定义在 IQCDbAccesser.h 中
 *
 *@param:
 *
 *1.机器号  key -> MachineID( 传入 -1时，代表忽略机器号的限制，查询所有机器号的结果 )
 *
 *2.质控品名称   key -> QCProductNames
 *
 *@return:
 *
 *查询结果: 目前来看，至少两列。后面可能会新增  按  质控项目名称，质控项目状态 排列
*/
TableRowRecords DBAccesser::queryQCOverviewProjects(const QVariantMap &condition) const
{
    return TableRowRecords();
}


/*
 *@brief:
 *
 *查询所有的质控结果
 *
 *@param:
 *
 *
 *@return:
 *
 *查询结果: 8列， 按 质控品，批号，试管架架号，试管位置，申请状态，申请时间，结束时间，LIS 排列
*/
TableRowRecords DBAccesser::queryQCResultAll() const
{
    return TableRowRecords();
}
