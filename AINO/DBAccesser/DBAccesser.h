#ifndef DBACCESSER_H
#define DBACCESSER_H

#include "DBAccesser_global.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <IDBAccesser.h>
#include "IQCDbAccesser.h"

class DBACCESSER_EXPORT DBAccesser : public IQCDbAccesser
{
public:
    static DBAccesser *getInstance();
    bool isDataBaseAvailable();

/***************************** 质控模块的查询 ************************************************************/
    virtual TableRowRecords queryQCOverviewProducts() const override;

    virtual TableRowRecords queryQCOverviewProjects(const QVariantMap &condition) const override;

    virtual TableRowRecords queryQCResultAll() const override;

    virtual TableRowRecords queryQCResultByCondition(const QVariantMap &condition) const override;




/***************************** 校准模块的查询 ************************************************************/








private:
    DBAccesser();
    DBAccesser( const DBAccesser &o ) = delete;
    DBAccesser& operator=( const DBAccesser &o ) = delete;







private:
    QSqlDatabase    m_db;
};

#endif // DBACCESSER_H
