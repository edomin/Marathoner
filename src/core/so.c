#include "so.h"

bool MTR_CALL MTR_SoInit(uint32_t dmSize, uint32_t reservedCount)
{
    unsigned int i;
    uint64_t     reservedDataCount;
    mtrSo_t     *so;

    MTR_LogWrite("Initializing shared object loading subsystem", 0,
     MTR_LMT_INFO);

    mtrSoKeeper = (mtrIndexkeeper_t *)MTR_IndexkeeperCreate(dmSize,
     reservedCount, sizeof(mtrSo_t));
    if (mtrSoKeeper == NULL)
    {
        MTR_Notify("Unable to initialize shared object loading subsystem", 1,
         MTR_LMT_ERROR);
        return false;
    }
    else
        MTR_LogWrite("Shared object loading subsystem initialized", 0,
         MTR_LMT_INFO);

    reservedDataCount = MTR_IndexkeeperGetReservedDataCount(mtrSoKeeper);
    for (i = 0; i < reservedDataCount; i++)
    {
        so = IK_GET_DATA(mtrSo_t *, mtrSoKeeper, i);
        so->handle = NULL;
    }

    return true;
}

/*fa MTR_SoOpen yes */
uint32_t MTR_CALL MTR_SoOpen(const char *filename)
{
    uint32_t    freeIndex;
    mtrSo_t     *so;

    if (filename == NULL)
    {
        MTR_LogWrite("Unable to open library. Filename is empty", 0,
         MTR_LMT_ERROR);
        return 0;
    }

    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrSoKeeper);
    so = IK_GET_DATA(mtrSo_t *, mtrSoKeeper, freeIndex);
    #ifdef __MINGW32__
    so->handle = LoadLibrary(filename);
    #else
    so->handle = dlopen(filename, RTLD_LAZY);
    #endif
    if (so->handle == NULL)
    {
        MTR_LogWrite("Unable to open library", 0, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrSoKeeper, freeIndex);
        return 0;
    }
    return freeIndex;
}

/*fa MTR_SoLoadSymbol yes */
void *MTR_CALL MTR_SoLoadSymbol(uint32_t soNum, const char *sym)
{
    mtrSo_t *so;

    if (sym == NULL)
    {
        MTR_LogWrite("Unable to load symbol. symbol name is empty", 0,
         MTR_LMT_ERROR);
        return 0;
    }

    so = IK_GET_DATA(mtrSo_t *, mtrSoKeeper, soNum);
    #ifdef __MINGW32__
    return GetProcAddress(so->handle, sym);
    #else
    return dlsym(so->handle, sym);
    #endif
}

/*fa MTR_SoClose yes */
void MTR_CALL MTR_SoClose(uint32_t soNum)
{
    mtrSo_t *so;

    so = IK_GET_DATA(mtrSo_t *, mtrSoKeeper, soNum);
    #ifdef __MINGW32__
    FreeLibrary(so->handle);
    #else
    dlclose(so->handle);
    #endif
}
