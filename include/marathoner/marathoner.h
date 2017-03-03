#ifndef MTR_MARATHONER_H
#define MTR_MARATHONER_H

#include "marathoner/version.h"
#include "marathoner/types.h"

#ifdef __EMSCRIPTEN__
    #include <dlfcn.h>
    #include <dirent.h>
#endif
#include <stdlib.h> /* for malloc */

#define UNUSED(expr) do { (void)(expr); } while (0)

/* Report of loaded dll-plugin */
typedef struct mtrReport{
    char    *moduleID;
    uint32_t version;
    char    *subsystem;
    uint8_t  prereqsCount;
    char   **prereqs;
    uint8_t  prereqSubsystemsCount;
    char   **prereqSubsystems;
} mtrReport;

/* type of loaded dll-plugin data */
typedef struct mtrPlugin{
    mtrReport   *report;
    char        *filename;
    mtr_lhandler dll;
} mtrPlugin;

/* Pointers to engine functions */

typedef char *      (MTR_CALL * mtrConfigfileGetKeyNameFunc_t)(const char *,
 const char *, int);
typedef char *      (MTR_CALL * mtrConfigfileGetSectionNameFunc_t)(const char*,
 int);
typedef bool        (MTR_CALL * mtrConfigfileDeleteKeyFunc_t)(const char *,
 const char *, const char *);
typedef bool        (MTR_CALL * mtrConfigfileDeleteSectionFunc_t)(const char *,
 const char *);
typedef bool        (MTR_CALL * mtrConfigfileReadBoolFunc_t)(const char *,
 const char *, const char *, bool);
typedef int         (MTR_CALL * mtrConfigfileReadIntFunc_t)(const char *,
 const char *, const char *, int);
typedef float       (MTR_CALL * mtrConfigfileReadSingleFunc_t)(const char *,
 const char *, const char *, float);
typedef char *      (MTR_CALL * mtrConfigfileReadStringFunc_t)(const char *,
 const char *, const char *, const char *);
typedef bool        (MTR_CALL * mtrConfigfileWriteBoolFunc_t)(const char *,
 const char *, const char *, bool);
typedef bool        (MTR_CALL * mtrConfigfileWriteIntFunc_t)(const char *,
 const char *, const char *, int);
typedef bool        (MTR_CALL * mtrConfigfileWriteSingleFunc_t)(const char *,
 const char *, const char *, float);
typedef bool        (MTR_CALL * mtrConfigfileWriteStringFunc_t)(const char *,
 const char *, const char *, const char *);

typedef void        (MTR_CALL * mtrLogWriteFunc_t)(const char *, uint8_t,
 uint8_t);
typedef void        (MTR_CALL * mtrLogWrite_sFunc_t)(const char *, uint8_t,
 uint8_t, const char *);
typedef void        (MTR_CALL * mtrLogWrite_iFunc_t)(const char *, uint8_t,
 uint8_t, int32_t);
typedef void        (MTR_CALL * mtrLogWrite_dFunc_t)(const char *, uint8_t,
 uint8_t, double);

typedef void        (MTR_CALL * mtrShowSimpleMessageBoxFunc_t)(uint8_t,
 const char *, const char *);
typedef bool        (MTR_CALL * mtrShowYesNoMessageBoxFunc_t)(const char *,
 const char *);
typedef bool        (MTR_CALL * mtrShowOkCancelMessageBoxFunc_t)(const char *,
 const char *);
typedef const char *(MTR_CALL * mtrShowInputDialogFunc_t)(const char *,
 const char *, const char *);
typedef const char *(MTR_CALL * mtrShowPasswordDialogFunc_t)(const char *,
 const char *);
typedef const char *(MTR_CALL * mtrShowSaveFileDialogFunc_t)(const char *,
 const char *, int, const char **, const char *);
typedef const char *(MTR_CALL * mtrShowOpenFileDialogFunc_t)(const char *,
 const char *, int, const char **, const char *);
typedef const char *(MTR_CALL * mtrShowSelectFolderDialogFunc_t)(const char *,
 const char *);

typedef void        (MTR_CALL * mtrNotifyFunc_t)(const char *, uint8_t,
 uint8_t);

typedef void *      (MTR_CALL * mtrIndexkeeperCreateFunc_t)(uint32_t, uint32_t,
 size_t);
typedef uint32_t    (MTR_CALL * mtrIndexkeeperGetFreeIndexFunc_t)(void *);
typedef void        (MTR_CALL * mtrIndexkeeperFreeIndexFunc_t)(void *,
 uint32_t);
typedef bool        (MTR_CALL * mtrIndexkeeperIndexIsEmptyFunc_t)(void *,
 uint32_t);
typedef void        (MTR_CALL * mtrIndexkeeperDestroyFunc_t)(void *);

typedef size_t      (MTR_CALL * mtrEncodingUtf8ToUcs4Func_t)(const char *,
 uint32_t **);
typedef size_t      (MTR_CALL * mtrEncodingUtf8CodepointsFunc_t)(const char *);

typedef void        (MTR_CALL * mtrFileWriteLineFunc_t)(const char *,
 const char *, int);

typedef bool        (MTR_CALL * mtrClipboardPutTextFunc_t)(const char *);
typedef char *      (MTR_CALL * mtrClipboardGetTextFunc_t)(void);

/* loaded dll-plugin data */
mtrPlugin *mtrPluginData;

/* Log Message Types */
#define MTR_LMT_INFO        0
#define MTR_LMT_NOTE        1
#define MTR_LMT_WARNING     2
#define MTR_LMT_ERROR       3
#define MTR_LMT_FATAL       4
#define MTR_LMT_DEBUG       5

/* Dialog Message Types */
#define MTR_DMT_INFO        0
#define MTR_DMT_NOTE        1
#define MTR_DMT_WARNING     2
#define MTR_DMT_ERROR       3
#define MTR_DMT_FATAL       4
#define MTR_DMT_DEBUG       5

/* Indexkeeper datamap size */
#define MTR_IKDM_SMALL      8
#define MTR_IKDM_MEDIUM     2048
#define MTR_IKDM_LARGE      134217728

/* Indexkeeper datamap size */
#define MTR_FM_WRITE        0
#define MTR_FM_APPEND       1

#endif
