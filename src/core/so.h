#ifndef MTR_CORE_SO_H
#define MTR_CORE_SO_H

#include "notification.h"
#include "log.h"
#include "indexkeeper.h"
#include "marathoner/engine.h"

#ifdef __MINGW32__
    #include <windows.h>
    typedef HMODULE mtrSoHandle_t;
#else
    #ifdef __EMSCRIPTEN__
        #include <emscripten.h>
    #else
        #include <dlfcn.h>
    #endif
    typedef void *mtrSoHandle_t;
#endif

typedef struct mtrSo_t {
    mtrSoHandle_t handle;
} mtrSo_t;

mtrIndexkeeper_t *mtrSoKeeper;

bool MTR_CALL MTR_SoInit(uint32_t dmSize, uint32_t reservedCount);
uint32_t MTR_CALL MTR_SoOpen(const char *filename);
void *MTR_CALL MTR_SoLoadSymbol(uint32_t soNum, const char *sym);
void MTR_CALL MTR_SoClose(uint32_t soNum);

#endif
