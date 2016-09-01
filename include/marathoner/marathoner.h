#ifndef MTR_MARATHONER
#define MTR_MARATHONER

#include <windows.h> /* for HMODULE */
#include <stdint.h> /* for uintXX_t types */
#include <stdlib.h> /* for malloc */
#include <stdbool.h>

#define MTR_MARATHONER_VERSION 0x000000

/* Report of loaded dll-plugin */
typedef struct mtrReport{
    char    *moduleID;
    uint32_t version;
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
typedef void     (__stdcall * mtrLogWriteFunc_t)(char *, uint8_t, uint8_t);
typedef void     (__stdcall * mtrLogWrite_sFunc_t)(char *, uint8_t, uint8_t,
                                                   const char *);
typedef void     (__stdcall * mtrLogWrite_iFunc_t)(char *, uint8_t, uint8_t,
                                                   int32_t);
typedef void     (__stdcall * mtrLogWrite_dFunc_t)(char *, uint8_t, uint8_t,
                                                   double);
typedef void     (__stdcall * mtrNotifyFunc_t)(char *, uint8_t, uint8_t);
typedef void *   (__stdcall * mtrIndexkeeperCreateFunc_t)(uint32_t, uint32_t,
                                                          size_t);
typedef uint32_t (__stdcall * mtrIndexkeeperGetFreeIndexFunc_t)(void *);
typedef void     (__stdcall * mtrIndexkeeperFreeIndexFunc_t)(void *, uint32_t);
typedef void     (__stdcall * mtrIndexkeeperDestroyFunc_t)(void *);
typedef void     (__stdcall * mtrFileWriteLineFunc_t)(const char *, const char *, uint8_t);

/* loaded dll-plugin data */
mtrPlugin *mtrPluginData;

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

/* Indexkeeper datamap size */
#define MTR_IKDM_SMALL  8
#define MTR_IKDM_MEDIUM 2048
#define MTR_IKDM_LARGE  134217728

/* Indexkeeper datamap size */
#define MTR_FM_WRITE    0
#define MTR_FM_APPEND   1

#endif
