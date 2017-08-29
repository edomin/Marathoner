#ifndef MTR_ENGINE_H
#define MTR_ENGINE_H

#include "marathoner/marathoner.h"

typedef mtrReport* (MTR_CALL * mtrReportFunc)(void);
mtrReportFunc mtrCreateReport;

/* Engine funcs exported to every plugin */
typedef void (MTR_CALL * mtrRequireConfigfileGetKeyNameFunc)(
 mtrConfigfileGetKeyNameFunc_t);
mtrRequireConfigfileGetKeyNameFunc mtrRequireConfigfileGetKeyName;
typedef void (MTR_CALL * mtrRequireConfigfileGetSectionNameFunc)(
 mtrConfigfileGetSectionNameFunc_t);
mtrRequireConfigfileGetSectionNameFunc mtrRequireConfigfileGetSectionName;
typedef void (MTR_CALL * mtrRequireConfigfileDeleteKeyFunc)(
 mtrConfigfileDeleteKeyFunc_t);
mtrRequireConfigfileDeleteKeyFunc mtrRequireConfigfileDeleteKey;
typedef void (MTR_CALL * mtrRequireConfigfileDeleteSectionFunc)(
 mtrConfigfileDeleteSectionFunc_t);
mtrRequireConfigfileDeleteSectionFunc mtrRequireConfigfileDeleteSection;
typedef void (MTR_CALL * mtrRequireConfigfileReadBoolFunc)(
 mtrConfigfileReadBoolFunc_t);
mtrRequireConfigfileReadBoolFunc mtrRequireConfigfileReadBool;
typedef void (MTR_CALL * mtrRequireConfigfileReadIntFunc)(
 mtrConfigfileReadIntFunc_t);
mtrRequireConfigfileReadIntFunc mtrRequireConfigfileReadInt;
typedef void (MTR_CALL * mtrRequireConfigfileReadSingleFunc)(
 mtrConfigfileReadSingleFunc_t);
mtrRequireConfigfileReadSingleFunc mtrRequireConfigfileReadSingle;
typedef void (MTR_CALL * mtrRequireConfigfileReadStringFunc)(
 mtrConfigfileReadStringFunc_t);
mtrRequireConfigfileReadStringFunc mtrRequireConfigfileReadString;
typedef void (MTR_CALL * mtrRequireConfigfileWriteBoolFunc)(
 mtrConfigfileWriteBoolFunc_t);
mtrRequireConfigfileWriteBoolFunc mtrRequireConfigfileWriteBool;
typedef void (MTR_CALL * mtrRequireConfigfileWriteIntFunc)(
 mtrConfigfileWriteIntFunc_t);
mtrRequireConfigfileWriteIntFunc mtrRequireConfigfileWriteInt;
typedef void (MTR_CALL * mtrRequireConfigfileWriteSingleFunc)(
 mtrConfigfileWriteSingleFunc_t);
mtrRequireConfigfileWriteSingleFunc mtrRequireConfigfileWriteSingle;
typedef void (MTR_CALL * mtrRequireConfigfileWriteStringFunc)(
 mtrConfigfileWriteStringFunc_t);
mtrRequireConfigfileWriteStringFunc mtrRequireConfigfileWriteString;
typedef bool (MTR_CALL * mtrRequireConfigfileCreateSectionFunc)(
 mtrConfigfileCreateSectionFunc_t);
mtrRequireConfigfileCreateSectionFunc mtrRequireConfigfileCreateSection;

typedef void (MTR_CALL * mtrRequireLogWriteFunc)(mtrLogWriteFunc_t);
mtrRequireLogWriteFunc mtrRequireLogWrite;
typedef void (MTR_CALL * mtrRequireLogWrite_sFunc)(mtrLogWrite_sFunc_t);
mtrRequireLogWrite_sFunc mtrRequireLogWrite_s;
typedef void (MTR_CALL * mtrRequireLogWrite_iFunc)(mtrLogWrite_iFunc_t);
mtrRequireLogWrite_iFunc mtrRequireLogWrite_i;
typedef void (MTR_CALL * mtrRequireLogWrite_dFunc)(mtrLogWrite_dFunc_t);
mtrRequireLogWrite_dFunc mtrRequireLogWrite_d;

typedef void (MTR_CALL * mtrRequireShowSimpleMessageBoxFunc)(
 mtrShowSimpleMessageBoxFunc_t);
mtrRequireShowSimpleMessageBoxFunc mtrRequireShowSimpleMessageBox;
typedef void (MTR_CALL * mtrRequireShowYesNoMessageBoxFunc)(
 mtrShowYesNoMessageBoxFunc_t);
mtrRequireShowYesNoMessageBoxFunc mtrRequireShowYesNoMessageBox;
typedef void (MTR_CALL * mtrRequireShowOkCancelMessageBoxFunc)(
 mtrShowOkCancelMessageBoxFunc_t);
mtrRequireShowOkCancelMessageBoxFunc mtrRequireShowOkCancelMessageBox;
typedef void (MTR_CALL * mtrRequireShowInputDialogFunc)(
 mtrShowInputDialogFunc_t);
mtrRequireShowInputDialogFunc mtrRequireShowInputDialog;
typedef void (MTR_CALL * mtrRequireShowPasswordDialogFunc)(
 mtrShowPasswordDialogFunc_t);
mtrRequireShowPasswordDialogFunc mtrRequireShowPasswordDialog;
typedef void (MTR_CALL * mtrRequireAddFileFilterFunc)(
 mtrAddFileFilterFunc_t);
mtrRequireAddFileFilterFunc mtrRequireAddFileFilter;
typedef void (MTR_CALL * mtrRequireClearFileFiltersFunc)(
 mtrClearFileFiltersFunc_t);
mtrRequireClearFileFiltersFunc mtrRequireClearFileFilters;
typedef void (MTR_CALL * mtrRequireShowSaveFileDialogFunc)(
 mtrShowSaveFileDialogFunc_t);
mtrRequireShowSaveFileDialogFunc mtrRequireShowSaveFileDialog;
typedef void (MTR_CALL * mtrRequireShowOpenFileDialogFunc)(
 mtrShowOpenFileDialogFunc_t);
mtrRequireShowOpenFileDialogFunc mtrRequireShowOpenFileDialog;
typedef void (MTR_CALL * mtrRequireShowSelectFolderDialogFunc)(
 mtrShowSelectFolderDialogFunc_t);
mtrRequireShowSelectFolderDialogFunc mtrRequireShowSelectFolderDialog;

typedef void (MTR_CALL * mtrRequireNotifyFunc)(mtrNotifyFunc_t);
mtrRequireNotifyFunc mtrRequireNotify;

typedef void (MTR_CALL * mtrRequireIndexkeeperCreateFunc)(
 mtrIndexkeeperCreateFunc_t);
mtrRequireIndexkeeperCreateFunc mtrRequireIndexkeeperCreate;
typedef void (MTR_CALL * mtrRequireIndexkeeperGetFreeIndexFunc)(
 mtrIndexkeeperGetFreeIndexFunc_t);
mtrRequireIndexkeeperGetFreeIndexFunc mtrRequireIndexkeeperGetFreeIndex;
typedef void (MTR_CALL * mtrRequireIndexkeeperFreeIndexFunc)(
 mtrIndexkeeperFreeIndexFunc_t);
mtrRequireIndexkeeperFreeIndexFunc mtrRequireIndexkeeperFreeIndex;
typedef void (MTR_CALL * mtrRequireIndexkeeperIndexIsEmptyFunc)(
 mtrIndexkeeperIndexIsEmptyFunc_t);
mtrRequireIndexkeeperIndexIsEmptyFunc mtrRequireIndexkeeperIndexIsEmpty;
typedef void (MTR_CALL * mtrRequireIndexkeeperGetReservedDataCountFunc)(
 mtrIndexkeeperGetReservedDataCountFunc_t);
mtrRequireIndexkeeperGetReservedDataCountFunc mtrRequireIndexkeeperGetReservedDataCount;
typedef void (MTR_CALL * mtrRequireIndexkeeperDestroyFunc)(
 mtrIndexkeeperDestroyFunc_t);
mtrRequireIndexkeeperDestroyFunc mtrRequireIndexkeeperDestroy;

typedef void (MTR_CALL * mtrRequireFileOpenFunc)(mtrFileOpenFunc_t);
mtrRequireFileOpenFunc mtrRequireFileOpen;
typedef void (MTR_CALL * mtrRequireFileCloseFunc)(mtrFileCloseFunc_t);
mtrRequireFileCloseFunc mtrRequireFileClose;
typedef void (MTR_CALL * mtrRequireFileReadFunc)(mtrFileReadFunc_t);
mtrRequireFileReadFunc mtrRequireFileRead;
typedef bool (MTR_CALL * mtrRequireFileWriteFunc)(mtrFileWriteFunc_t);
mtrRequireFileWriteFunc mtrRequireFileWrite;
typedef bool (MTR_CALL * mtrRequireFileWriteLineFunc)(mtrFileWriteLineFunc_t);
mtrRequireFileWriteLineFunc mtrRequireFileWriteLine;
typedef void (MTR_CALL * mtrRequireFileWriteFastFunc)(mtrFileWriteFastFunc_t);
mtrRequireFileWriteFastFunc mtrRequireFileWriteFast;
typedef void (MTR_CALL * mtrRequireFileWriteLineFastFunc)(
 mtrFileWriteLineFastFunc_t);
mtrRequireFileWriteLineFastFunc mtrRequireFileWriteLineFast;

typedef void (MTR_CALL * mtrRequireClipboardPutTextFunc)(
 mtrClipboardPutTextFunc_t);
mtrRequireClipboardPutTextFunc mtrRequireClipboardPutText;
typedef void (MTR_CALL * mtrRequireClipboardGetTextFunc)(
 mtrClipboardGetTextFunc_t);
mtrRequireClipboardGetTextFunc mtrRequireClipboardGetText;

typedef void (MTR_CALL * mtrRequireEncodingUtf8ToUcs4Func)(
 mtrEncodingUtf8ToUcs4Func_t);
mtrRequireEncodingUtf8ToUcs4Func mtrRequireEncodingUtf8ToUcs4;
typedef void (MTR_CALL * mtrRequireEncodingUtf8CodepointsFunc)(
 mtrEncodingUtf8CodepointsFunc_t);
mtrRequireEncodingUtf8CodepointsFunc mtrRequireEncodingUtf8Codepoints;

typedef void (MTR_CALL * mtrRequireStringBufferAddFunc)(
 mtrStringBufferAddFunc_t);
mtrRequireStringBufferAddFunc mtrRequireStringBufferAdd;
typedef void (MTR_CALL * mtrRequireStringBufferDeleteFunc)(
 mtrStringBufferDeleteFunc_t);
mtrRequireStringBufferDeleteFunc mtrRequireStringBufferDelete;
typedef void (MTR_CALL * mtrRequireStringBufferSetStringFunc)(
 mtrStringBufferSetStringFunc_t);
mtrRequireStringBufferSetStringFunc mtrRequireStringBufferSetString;
typedef void (MTR_CALL * mtrRequireStringBufferGetStringFunc)(
 mtrStringBufferGetStringFunc_t);
mtrRequireStringBufferGetStringFunc mtrRequireStringBufferGetString;
typedef void (MTR_CALL * mtrRequireStringBufferGetMaxLenFunc)(
 mtrStringBufferGetMaxLenFunc_t);
mtrRequireStringBufferGetMaxLenFunc mtrRequireStringBufferGetMaxLen;

typedef void (MTR_CALL * mtrRequireOptionsAliasFunc)(mtrOptionsAliasFunc_t);
mtrRequireOptionsAliasFunc mtrRequireOptionsAlias;
typedef void (MTR_CALL * mtrRequireOptionsGetFunc)(mtrOptionsGetFunc_t);
mtrRequireOptionsGetFunc mtrRequireOptionsGet;
typedef void (MTR_CALL * mtrRequireOptionsGet_iFunc)(mtrOptionsGet_iFunc_t);
mtrRequireOptionsGet_iFunc mtrRequireOptionsGet_i;
typedef void (MTR_CALL * mtrRequireOptionsGet_lFunc)(mtrOptionsGet_lFunc_t);
mtrRequireOptionsGet_lFunc mtrRequireOptionsGet_l;
typedef void (MTR_CALL * mtrRequireOptionsGet_fFunc)(mtrOptionsGet_fFunc_t);
mtrRequireOptionsGet_fFunc mtrRequireOptionsGet_f;
typedef void (MTR_CALL * mtrRequireOptionsGet_dFunc)(mtrOptionsGet_dFunc_t);
mtrRequireOptionsGet_dFunc mtrRequireOptionsGet_d;

/*  */
typedef void (MTR_CALL * mtrRequirePluginDataFunc)(mtrPlugin *, uint8_t);
mtrRequirePluginDataFunc mtrRequirePluginData;

typedef void (MTR_CALL * mtrScriptsAutorunFunc)(char *);
mtrScriptsAutorunFunc mtrScriptsAutorun;

#define MTR_REQUIRE_ENGINE_FUNC(require_funcname, funcname)                                   \
    require_funcname = (require_funcname ## Func)mtrLoadSymbolName(mtrPluginData[plugin].dll, \
     #require_funcname);                                                                      \
    if (require_funcname != NULL)                                                             \
        require_funcname(funcname);                                                           \
    else                                                                                      \
        mtrLogWrite("Module are not contain declaration for 'funcname' function",             \
         1, MTR_LMT_WARNING);                                                                 \

#endif
