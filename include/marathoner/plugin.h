#ifndef MTR_PLUGIN_H
#define MTR_PLUGIN_H

#include "marathoner/marathoner.h"

typedef struct mtrIndexkeeper_t {
    void *data;
    size_t dataSize;
    uint32_t reservedData;
    uint32_t dataCount;
    uint32_t dmSize;
    uint32_t *dataMap;
} mtrIndexkeeper_t;

typedef struct mtrPixels_t {
    void *data;
    int   w;
    int   h;
    int   pitch;
    int   pixelformat;
} mtrPixels_t;

/* Texture flipping constants */
#define MTR_FLIP_NONE       0
#define MTR_FLIP_HORIZONTAL 1
#define MTR_FLIP_VERTICAL   2
#define MTR_FLIP_BOTH       (MTR_FLIP_HORIZONTAL | MTR_FLIP_VERTICAL)

/* Pixel format constants */
#define MTR_PF_RGBA         1
#define MTR_PF_ARGB         2

mtrConfigfileGetKeyNameFunc_t               mtrConfigfileGetKeyName;
mtrConfigfileGetSectionNameFunc_t           mtrConfigfileGetSectionName;
mtrConfigfileDeleteKeyFunc_t                mtrConfigfileDeleteKey;
mtrConfigfileDeleteSectionFunc_t            mtrConfigfileDeleteSection;
mtrConfigfileReadBoolFunc_t                 mtrConfigfileReadBool;
mtrConfigfileReadIntFunc_t                  mtrConfigfileReadInt;
mtrConfigfileReadSingleFunc_t               mtrConfigfileReadSingle;
mtrConfigfileReadStringFunc_t               mtrConfigfileReadString;
mtrConfigfileWriteBoolFunc_t                mtrConfigfileWriteBool;
mtrConfigfileWriteIntFunc_t                 mtrConfigfileWriteInt;
mtrConfigfileWriteSingleFunc_t              mtrConfigfileWriteSingle;
mtrConfigfileWriteStringFunc_t              mtrConfigfileWriteString;

mtrLogWriteFunc_t                           mtrLogWrite;
mtrLogWrite_sFunc_t                         mtrLogWrite_s;
mtrLogWrite_iFunc_t                         mtrLogWrite_i;
mtrLogWrite_dFunc_t                         mtrLogWrite_d;

mtrShowSimpleMessageBoxFunc_t               mtrShowSimpleMessageBox;
mtrShowYesNoMessageBoxFunc_t                mtrShowYesNoMessageBox;
mtrShowOkCancelMessageBoxFunc_t             mtrShowOkCancelMessageBox;
mtrShowInputDialogFunc_t                    mtrShowInputDialog;
mtrShowPasswordDialogFunc_t                 mtrShowPasswordDialog;
mtrShowSaveFileDialogFunc_t                 mtrShowSaveFileDialog;
mtrShowOpenFileDialogFunc_t                 mtrShowOpenFileDialog;
mtrShowSelectFolderDialogFunc_t             mtrShowSelectFolderDialog;

mtrNotifyFunc_t                             mtrNotify;

mtrIndexkeeperCreateFunc_t                  mtrIndexkeeperCreate;
mtrIndexkeeperGetFreeIndexFunc_t            mtrIndexkeeperGetFreeIndex;
mtrIndexkeeperFreeIndexFunc_t               mtrIndexkeeperFreeIndex;
mtrIndexkeeperIndexIsEmptyFunc_t            mtrIndexkeeperIndexIsEmpty;
mtrIndexkeeperGetReservedDataCountFunc_t    mtrIndexkeeperGetReservedDataCount;
mtrIndexkeeperDestroyFunc_t                 mtrIndexkeeperDestroy;

mtrEncodingUtf8ToUcs4Func_t                 mtrEncodingUtf8ToUcs4;
mtrEncodingUtf8CodepointsFunc_t             mtrEncodingUtf8Codepoints;

mtrFileOpenFunc_t                           mtrFileOpen;
mtrFileCloseFunc_t                          mtrFileClose;
mtrFileReadFunc_t                           mtrFileRead;
mtrFileWriteFunc_t                          mtrFileWrite;
mtrFileWriteLineFunc_t                      mtrFileWriteLine;
mtrFileWriteFastFunc_t                      mtrFileWriteFast;
mtrFileWriteLineFastFunc_t                  mtrFileWriteLineFast;

mtrClipboardPutTextFunc_t                   mtrClipboardPutText;
mtrClipboardGetTextFunc_t                   mtrClipboardGetText;

mtrStringBufferAddFunc_t                    mtrStringBufferAdd;
mtrStringBufferDeleteFunc_t                 mtrStringBufferDelete;
mtrStringBufferSetStringFunc_t              mtrStringBufferSetString;
mtrStringBufferGetStringFunc_t              mtrStringBufferGetString;
mtrStringBufferGetMaxLenFunc_t              mtrStringBufferGetMaxLen;

uint8_t mtrPluginsCount;

#define MTR_FIND_FUNCTION(function, module)                        \
    function = (function ## Func)mtrFindFunction(module,           \
    #function);                                                    \
    if (function == NULL)                                          \
    {                                                              \
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR, \
         #function);                                               \
        ok = false;                                                \
    }

#define MTR_FIND_FUNCTION_IN_SUBSYSTEM(function, subsystem)             \
    function = (function ## Func)mtrFindFunctionInSubsystem(subsystem,  \
    #function);                                                         \
    if (function == NULL)                                               \
    {                                                                   \
        mtrLogWrite_s("Unable to load function", 1, MTR_LMT_ERROR,      \
         #function);                                                    \
        return false;                                                   \
    }

#endif
