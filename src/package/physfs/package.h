#ifndef MTR_PACKAGE_PHYSFS_H
#define MTR_PACKAGE_PHYSFS_H

#include <stdarg.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wundef"
#include "physfs.h"
#pragma GCC diagnostic pop

#include "marathoner/plugin.h"
#ifdef MTR_MOD_STATIC
    #define fa faPackage
#endif
#include "fa/Package_PhysFS.h"

typedef struct mtrPackage_t {
    int   currentFile;
    char *currentFilename;
} mtrPackage_t;

mtrPackage_t mtrPackage;
static bool  mtrPackageInited = false;
char         mtrPackageBuffer[1048576];

#define MTR_PACKAGE_CHECK_IF_NOT_INITED(returnValue) \
    if (!mtrPackageInited)                           \
        return returnValue;
#define MTR_PACKAGE_CHECK_IF_NOT_INITED_WITH_LOG(message, returnValue) \
    if (!mtrPackageInited)                                             \
    {                                                                  \
        MTR_LogWrite(                                                  \
         message ". Package i/o are not initialized", 1,               \
         MTR_LMT_ERROR);                                               \
        return returnValue;                                            \
    }

#endif
