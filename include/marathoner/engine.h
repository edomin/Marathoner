#ifndef MTR_ENGINE
#define MTR_ENGINE

#include "marathoner/marathoner.h"

typedef mtrReport* (__stdcall * mtrReportFunc)(void);
mtrReportFunc mtrCreateReport;

/* Engine funcs exported to every plugin */
typedef void (__stdcall * mtrRequireLogWriteFunc)(mtrLogWriteFunc_t);
mtrRequireLogWriteFunc mtrRequireLogWrite;
typedef void (__stdcall * mtrRequireLogWrite_sFunc)(mtrLogWrite_sFunc_t);
mtrRequireLogWrite_sFunc mtrRequireLogWrite_s;
typedef void (__stdcall * mtrRequireLogWrite_iFunc)(mtrLogWrite_iFunc_t);
mtrRequireLogWrite_iFunc mtrRequireLogWrite_i;
typedef void (__stdcall * mtrRequireLogWrite_dFunc)(mtrLogWrite_dFunc_t);
mtrRequireLogWrite_dFunc mtrRequireLogWrite_d;

typedef void (__stdcall * mtrRequireNotifyFunc)(mtrNotifyFunc_t);
mtrRequireNotifyFunc mtrRequireNotify;

typedef void (__stdcall * mtrRequireIndexkeeperCreateFunc)(mtrIndexkeeperCreateFunc_t);
mtrRequireIndexkeeperCreateFunc mtrRequireIndexkeeperCreate;
typedef void (__stdcall * mtrRequireIndexkeeperGetFreeIndexFunc)(mtrIndexkeeperGetFreeIndexFunc_t);
mtrRequireIndexkeeperGetFreeIndexFunc mtrRequireIndexkeeperGetFreeIndex;
typedef void (__stdcall * mtrRequireIndexkeeperFreeIndexFunc)(mtrIndexkeeperFreeIndexFunc_t);
mtrRequireIndexkeeperFreeIndexFunc mtrRequireIndexkeeperFreeIndex;
typedef void (__stdcall * mtrRequireIndexkeeperDestroyFunc)(mtrIndexkeeperDestroyFunc_t);
mtrRequireIndexkeeperDestroyFunc mtrRequireIndexkeeperDestroy;

/*  */
typedef void (__stdcall * mtrRequirePluginDataFunc)(mtrPlugin *, uint8_t);
mtrRequirePluginDataFunc mtrRequirePluginData;

typedef void (__stdcall * mtrScriptsAutorunFunc)(char *);
mtrScriptsAutorunFunc mtrScriptsAutorun;

#endif
