#ifndef MTR_ENGINE
#define MTR_ENGINE

#include "marathoner/marathoner.h"

typedef mtrReport* (MRT_CALL * mtrReportFunc)(void);
mtrReportFunc mtrCreateReport;

/* Engine funcs exported to every plugin */
typedef void (MRT_CALL * mtrRequireLogWriteFunc)(mtrLogWriteFunc_t);
mtrRequireLogWriteFunc mtrRequireLogWrite;
typedef void (MRT_CALL * mtrRequireLogWrite_sFunc)(mtrLogWrite_sFunc_t);
mtrRequireLogWrite_sFunc mtrRequireLogWrite_s;
typedef void (MRT_CALL * mtrRequireLogWrite_iFunc)(mtrLogWrite_iFunc_t);
mtrRequireLogWrite_iFunc mtrRequireLogWrite_i;
typedef void (MRT_CALL * mtrRequireLogWrite_dFunc)(mtrLogWrite_dFunc_t);
mtrRequireLogWrite_dFunc mtrRequireLogWrite_d;

typedef void (MRT_CALL * mtrRequireNotifyFunc)(mtrNotifyFunc_t);
mtrRequireNotifyFunc mtrRequireNotify;

typedef void (MRT_CALL * mtrRequireIndexkeeperCreateFunc)(mtrIndexkeeperCreateFunc_t);
mtrRequireIndexkeeperCreateFunc mtrRequireIndexkeeperCreate;
typedef void (MRT_CALL * mtrRequireIndexkeeperGetFreeIndexFunc)(mtrIndexkeeperGetFreeIndexFunc_t);
mtrRequireIndexkeeperGetFreeIndexFunc mtrRequireIndexkeeperGetFreeIndex;
typedef void (MRT_CALL * mtrRequireIndexkeeperFreeIndexFunc)(mtrIndexkeeperFreeIndexFunc_t);
mtrRequireIndexkeeperFreeIndexFunc mtrRequireIndexkeeperFreeIndex;
typedef void (MRT_CALL * mtrRequireIndexkeeperDestroyFunc)(mtrIndexkeeperDestroyFunc_t);
mtrRequireIndexkeeperDestroyFunc mtrRequireIndexkeeperDestroy;

typedef void (MRT_CALL * mtrRequireFileWriteLineFunc)(mtrFileWriteLineFunc_t);
mtrRequireFileWriteLineFunc mtrRequireFileWriteLine;

/*  */
typedef void (MRT_CALL * mtrRequirePluginDataFunc)(mtrPlugin *, uint8_t);
mtrRequirePluginDataFunc mtrRequirePluginData;

typedef void (MRT_CALL * mtrScriptsAutorunFunc)(char *);
mtrScriptsAutorunFunc mtrScriptsAutorun;

#endif
