#ifndef MTR_PAK_PHYSFS_H
#define MTR_PAK_PHYSFS_H

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wundef"
#include "physfs.h"
#pragma GCC diagnostic pop

#include "marathoner/plugin.h"
#ifdef MTR_MOD_STATIC
    #define fa faPak
#endif
#include "fa/PAK_PhysFS.h"

typedef struct mtrPak_t {
    int   currentFile;
    char *currentFilename;
} mtrPak_t;

mtrPak_t    mtrPak;
static bool mtrPakInited = false;
char        mtrPakBuffer[1048576];

#define MTR_PAK_CHECK_IF_NOT_INITED(returnValue) \
    if (!mtrPakInited)                           \
        return returnValue;
#define MTR_PAK_CHECK_IF_NOT_INITED_WITH_LOG(message, returnValue) \
    if (!mtrPakInited)                                             \
    {                                                              \
        MTR_LogWrite(                                              \
         message ". PAK i/o are not initialized", 1,               \
         MTR_LMT_ERROR);                                           \
        return returnValue;                                        \
    }

#endif
