#ifndef PLUGINCORE_GLOBAL_H
#define PLUGINCORE_GLOBAL_H

#include <QtGlobal>

#if defined PLUGINCORE_LIB
    #define PLUGINCORE_LIB_EXPORT Q_DECL_EXPORT
#else
    #define PLUGINCORE_LIB_EXPORT Q_DECL_IMPORT
#endif

#endif // PLUGINCORE_GLOBAL_H
