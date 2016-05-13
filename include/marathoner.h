#ifndef MTR_MARATHONER
#define MTR_MARATHONER

#include <windows.h> /* for HMODULE */
#include <stdint.h> /* for uintXX_t types */
#include <stdlib.h> /* for malloc */

/* Report of loaded dll-plugin */
typedef struct mtrReport{
    char    *moduleID;
    uint8_t  prereqsCount;
    char   **prereqs;
} mtrReport;

/* type of loaded dll-plugin data */
typedef struct mtrPlugin{
    mtrReport *report;
    char      *filename;
    HMODULE    dll;
} mtrPlugin;

/* Pointers to engine functions */
typedef void (__stdcall * mtrLogWriteFunc_t)(char *, uint8_t, uint8_t);
typedef void (__stdcall * mtrLogWrite_sFunc_t)(char *, uint8_t, uint8_t,
                                               char *);
typedef void (__stdcall * mtrLogWrite_iFunc_t)(char *, uint8_t, uint8_t,
                                               int32_t);
typedef void (__stdcall * mtrLogWrite_dFunc_t)(char *, uint8_t, uint8_t,
                                               double);
typedef void (__stdcall * mtrNotifyFunc_t)(char *, uint8_t, uint8_t);

/* loaded dll-plugin data */
mtrPlugin *mtrPluginData;

#ifdef MTR_PLUGIN
    mtrLogWriteFunc_t mtrLogWrite;
    mtrLogWrite_sFunc_t mtrLogWrite_s;
    mtrLogWrite_iFunc_t mtrLogWrite_i;
    mtrLogWrite_dFunc_t mtrLogWrite_d;
    mtrNotifyFunc_t mtrNotify;

    uint8_t mtrPluginsCount;
#else
    typedef mtrReport* (__stdcall * mtrReportFunc)(void);
    mtrReportFunc mtrCreateReport;

    typedef void (__stdcall * mtrRequireEngineFuncsFunc)(mtrLogWriteFunc_t,
                                                         mtrLogWrite_sFunc_t,
                                                         mtrLogWrite_iFunc_t,
                                                         mtrLogWrite_dFunc_t,
                                                         mtrNotifyFunc_t);
    mtrRequireEngineFuncsFunc mtrRequireEngineFuncs;

    typedef void (__stdcall * mtrRequirePluginDataFunc)(mtrPlugin *, uint8_t);
    mtrRequirePluginDataFunc mtrRequirePluginData;
#endif

/* Log Message Types */
#define MTR_LMT_INFO    0
#define MTR_LMT_NOTE    1
#define MTR_LMT_WARNING 2
#define MTR_LMT_ERROR   3
#define MTR_LMT_FATAL   4
#define MTR_LMT_DEBUG   5

/* Dialog Message Types */
#define MTR_DMT_INFO    0
#define MTR_DMT_NOTE    1
#define MTR_DMT_WARNING 2
#define MTR_DMT_ERROR   3
#define MTR_DMT_FATAL   4
#define MTR_DMT_DEBUG   5

#endif
