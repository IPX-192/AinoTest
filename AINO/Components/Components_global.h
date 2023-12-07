#pragma once

#include <QtCore/qglobal.h>
#include <QDebug>

#if defined(COMPONENTS_LIBRARY)
#  define COMPONENTS_EXPORT Q_DECL_EXPORT
#else
#  define COMPONENTS_EXPORT Q_DECL_IMPORT
#endif
