#ifndef MTR_PLUGIN
#define MTR_PLUGIN

#include "marathoner/marathoner.h"

typedef struct mtrIndexkeeper_t {
    void *data;
    size_t dataSize;
    uint32_t reservedData;
    uint32_t dataCount;
    uint32_t dmSize;
    uint32_t *dataMap;
} mtrIndexkeeper_t;

mtrConfigfileGetKeyNameFunc_t       mtrConfigfileGetKeyName;
mtrConfigfileGetSectionNameFunc_t   mtrConfigfileGetSectionName;
mtrConfigfileDeleteKeyFunc_t        mtrConfigfileDeleteKey;
mtrConfigfileDeleteSectionFunc_t    mtrConfigfileDeleteSection;
mtrConfigfileReadBoolFunc_t         mtrConfigfileReadBool;
mtrConfigfileReadIntFunc_t          mtrConfigfileReadInt;
mtrConfigfileReadSingleFunc_t       mtrConfigfileReadSingle;
mtrConfigfileReadStringFunc_t       mtrConfigfileReadString;
mtrConfigfileWriteIntFunc_t         mtrConfigfileWriteInt;
mtrConfigfileWriteSingleFunc_t      mtrConfigfileWriteSingle;
mtrConfigfileWriteStringFunc_t      mtrConfigfileWriteString;

mtrLogWriteFunc_t                   mtrLogWrite;
mtrLogWrite_sFunc_t                 mtrLogWrite_s;
mtrLogWrite_iFunc_t                 mtrLogWrite_i;
mtrLogWrite_dFunc_t                 mtrLogWrite_d;

mtrNotifyFunc_t                     mtrNotify;

mtrIndexkeeperCreateFunc_t          mtrIndexkeeperCreate;
mtrIndexkeeperGetFreeIndexFunc_t    mtrIndexkeeperGetFreeIndex;
mtrIndexkeeperFreeIndexFunc_t       mtrIndexkeeperFreeIndex;
mtrIndexkeeperIndexIsEmptyFunc_t    mtrIndexkeeperIndexIsEmpty;
mtrIndexkeeperDestroyFunc_t         mtrIndexkeeperDestroy;

mtrFileWriteLineFunc_t              mtrFileWriteLine;

uint8_t mtrPluginsCount;

#endif
