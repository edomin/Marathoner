#ifndef MTR_ENGINE_H
#define MTR_ENGINE_H

#include "marathoner/marathoner.h"

typedef mtrReport* (MTR_CALL * mtrReportFunc)(void);
mtrReportFunc mtrCreateReport;

/* Engine funcs exported to every plugin */
typedef void (MTR_CALL * mtrRequireConfigfileGetKeyNameFunc)(mtrConfigfileGetKeyNameFunc_t);
mtrRequireConfigfileGetKeyNameFunc mtrRequireConfigfileGetKeyName;
typedef void (MTR_CALL * mtrRequireConfigfileGetSectionNameFunc)(mtrConfigfileGetSectionNameFunc_t);
mtrRequireConfigfileGetSectionNameFunc mtrRequireConfigfileGetSectionName;
typedef void (MTR_CALL * mtrRequireConfigfileDeleteKeyFunc)(mtrConfigfileDeleteKeyFunc_t);
mtrRequireConfigfileDeleteKeyFunc mtrRequireConfigfileDeleteKey;
typedef void (MTR_CALL * mtrRequireConfigfileDeleteSectionFunc)(mtrConfigfileDeleteSectionFunc_t);
mtrRequireConfigfileDeleteSectionFunc mtrRequireConfigfileDeleteSection;
typedef void (MTR_CALL * mtrRequireConfigfileReadBoolFunc)(mtrConfigfileReadBoolFunc_t);
mtrRequireConfigfileReadBoolFunc mtrRequireConfigfileReadBool;
typedef void (MTR_CALL * mtrRequireConfigfileReadIntFunc)(mtrConfigfileReadIntFunc_t);
mtrRequireConfigfileReadIntFunc mtrRequireConfigfileReadInt;
typedef void (MTR_CALL * mtrRequireConfigfileReadSingleFunc)(mtrConfigfileReadSingleFunc_t);
mtrRequireConfigfileReadSingleFunc mtrRequireConfigfileReadSingle;
typedef void (MTR_CALL * mtrRequireConfigfileReadStringFunc)(mtrConfigfileReadStringFunc_t);
mtrRequireConfigfileReadStringFunc mtrRequireConfigfileReadString;
typedef void (MTR_CALL * mtrRequireConfigfileWriteBoolFunc)(mtrConfigfileWriteBoolFunc_t);
mtrRequireConfigfileWriteBoolFunc mtrRequireConfigfileWriteBool;
typedef void (MTR_CALL * mtrRequireConfigfileWriteIntFunc)(mtrConfigfileWriteIntFunc_t);
mtrRequireConfigfileWriteIntFunc mtrRequireConfigfileWriteInt;
typedef void (MTR_CALL * mtrRequireConfigfileWriteSingleFunc)(mtrConfigfileWriteSingleFunc_t);
mtrRequireConfigfileWriteSingleFunc mtrRequireConfigfileWriteSingle;
typedef void (MTR_CALL * mtrRequireConfigfileWriteStringFunc)(mtrConfigfileWriteStringFunc_t);
mtrRequireConfigfileWriteStringFunc mtrRequireConfigfileWriteString;

typedef void (MTR_CALL * mtrRequireLogWriteFunc)(mtrLogWriteFunc_t);
mtrRequireLogWriteFunc mtrRequireLogWrite;
typedef void (MTR_CALL * mtrRequireLogWrite_sFunc)(mtrLogWrite_sFunc_t);
mtrRequireLogWrite_sFunc mtrRequireLogWrite_s;
typedef void (MTR_CALL * mtrRequireLogWrite_iFunc)(mtrLogWrite_iFunc_t);
mtrRequireLogWrite_iFunc mtrRequireLogWrite_i;
typedef void (MTR_CALL * mtrRequireLogWrite_dFunc)(mtrLogWrite_dFunc_t);
mtrRequireLogWrite_dFunc mtrRequireLogWrite_d;

typedef void (MTR_CALL * mtrRequireShowSimpleMessageBoxFunc)(mtrShowSimpleMessageBoxFunc_t);
mtrRequireShowSimpleMessageBoxFunc mtrRequireShowSimpleMessageBox;
typedef void (MTR_CALL * mtrRequireShowYesNoMessageBoxFunc)(mtrShowYesNoMessageBoxFunc_t);
mtrRequireShowYesNoMessageBoxFunc mtrRequireShowYesNoMessageBox;
typedef void (MTR_CALL * mtrRequireShowOkCancelMessageBoxFunc)(mtrShowOkCancelMessageBoxFunc_t);
mtrRequireShowOkCancelMessageBoxFunc mtrRequireShowOkCancelMessageBox;
typedef void (MTR_CALL * mtrRequireShowInputDialogFunc)(mtrShowInputDialogFunc_t);
mtrRequireShowInputDialogFunc mtrRequireShowInputDialog;
typedef void (MTR_CALL * mtrRequireShowPasswordDialogFunc)(mtrShowPasswordDialogFunc_t);
mtrRequireShowPasswordDialogFunc mtrRequireShowPasswordDialog;
typedef void (MTR_CALL * mtrRequireShowSaveFileDialogFunc)(mtrShowSaveFileDialogFunc_t);
mtrRequireShowSaveFileDialogFunc mtrRequireShowSaveFileDialog;
typedef void (MTR_CALL * mtrRequireShowOpenFileDialogFunc)(mtrShowOpenFileDialogFunc_t);
mtrRequireShowOpenFileDialogFunc mtrRequireShowOpenFileDialog;
typedef void (MTR_CALL * mtrRequireShowSelectFolderDialogFunc)(mtrShowSelectFolderDialogFunc_t);
mtrRequireShowSelectFolderDialogFunc mtrRequireShowSelectFolderDialog;

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
