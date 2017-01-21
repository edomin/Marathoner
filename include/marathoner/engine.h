#ifndef MTR_ENGINE_H
#define MTR_ENGINE_H

#include "marathoner/marathoner.h"

typedef mtrReport* (MTR_CALL * mtrReportFunc)(void);
mtrReportFunc mtrCreateReport;

/* Engine funcs exported to every plugin */
typedef void (MTR_CALL * mtrRequireLogWriteFunc)(mtrLogWriteFunc_t);
mtrRequireLogWriteFunc mtrRequireLogWrite;
typedef void (MTR_CALL * mtrRequireLogWrite_sFunc)(mtrLogWrite_sFunc_t);
mtrRequireLogWrite_sFunc mtrRequireLogWrite_s;
typedef void (MTR_CALL * mtrRequireLogWrite_iFunc)(mtrLogWrite_iFunc_t);
mtrRequireLogWrite_iFunc mtrRequireLogWrite_i;
typedef void (MTR_CALL * mtrRequireLogWrite_dFunc)(mtrLogWrite_dFunc_t);
mtrRequireLogWrite_dFunc mtrRequireLogWrite_d;

typedef void (MTR_CALL * mtrRequireNotifyFunc)(mtrNotifyFunc_t);
mtrRequireNotifyFunc mtrRequireNotify;

typedef void (MTR_CALL * mtrRequireIndexkeeperCreateFunc)(mtrIndexkeeperCreateFunc_t);
mtrRequireIndexkeeperCreateFunc mtrRequireIndexkeeperCreate;
typedef void (MTR_CALL * mtrRequireIndexkeeperGetFreeIndexFunc)(mtrIndexkeeperGetFreeIndexFunc_t);
mtrRequireIndexkeeperGetFreeIndexFunc mtrRequireIndexkeeperGetFreeIndex;
typedef void (MTR_CALL * mtrRequireIndexkeeperFreeIndexFunc)(mtrIndexkeeperFreeIndexFunc_t);
mtrRequireIndexkeeperFreeIndexFunc mtrRequireIndexkeeperFreeIndex;
typedef void (MTR_CALL * mtrRequireIndexkeeperIndexIsEmptyFunc)(mtrIndexkeeperIndexIsEmptyFunc_t);
mtrRequireIndexkeeperIndexIsEmptyFunc mtrRequireIndexkeeperIndexIsEmpty;
typedef void (MTR_CALL * mtrRequireIndexkeeperDestroyFunc)(mtrIndexkeeperDestroyFunc_t);
mtrRequireIndexkeeperDestroyFunc mtrRequireIndexkeeperDestroy;

typedef void (MTR_CALL * mtrRequireFileWriteLineFunc)(mtrFileWriteLineFunc_t);
mtrRequireFileWriteLineFunc mtrRequireFileWriteLine;

/*  */
typedef void (MTR_CALL * mtrRequirePluginDataFunc)(mtrPlugin *, uint8_t);
mtrRequirePluginDataFunc mtrRequirePluginData;

typedef void (MTR_CALL * mtrScriptsAutorunFunc)(char *);
mtrScriptsAutorunFunc mtrScriptsAutorun;

#endif
