#ifndef DBACCESSER_GLOBAL_H
#define DBACCESSER_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QtCore>

using TableRowRecords = QVector< QVariantList >;

#if defined(DBACCESSER_LIBRARY)
#  define DBACCESSER_EXPORT Q_DECL_EXPORT
#else
#  define DBACCESSER_EXPORT Q_DECL_IMPORT
#endif

#endif // DBACCESSER_GLOBAL_H
