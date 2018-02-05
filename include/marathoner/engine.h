#ifndef MTR_ENGINE_H
#define MTR_ENGINE_H

#include <unistd.h>
#include <string.h>

#include "marathoner/marathoner.h"

#ifdef MTR_MOD_PLUGIN
typedef mtrReport* (MTR_CALL * MTR_ReportFunc)(void);
MTR_ReportFunc MTR_CreateReport;

/* Engine funcs exported to every plugin */
typedef void (MTR_CALL * MTR_RequireMarathonerFunctionSupportedFunc)(
 MTR_MarathonerFunctionSupportedFunc_t);
MTR_RequireMarathonerFunctionSupportedFunc MTR_RequireMarathonerFunctionSupported;
typedef void (MTR_CALL * MTR_RequireMarathonerGetVersionFunc)(
 MTR_MarathonerGetVersionFunc_t);
MTR_RequireMarathonerGetVersionFunc MTR_RequireMarathonerGetVersion;
typedef void (MTR_CALL * MTR_RequireMarathonerGetModuleVersionFunc)(
 MTR_MarathonerGetModuleVersionFunc_t);
MTR_RequireMarathonerGetModuleVersionFunc MTR_RequireMarathonerGetModuleVersion;
typedef void (MTR_CALL * MTR_RequireMarathonerGetSubsystemModuleIdFunc)(
 MTR_MarathonerGetSubsystemModuleIdFunc_t);
MTR_RequireMarathonerGetSubsystemModuleIdFunc MTR_RequireMarathonerGetSubsystemModuleId;
typedef void (MTR_CALL * MTR_RequireConfigfileGetKeyNameFunc)(
 MTR_ConfigfileGetKeyNameFunc_t);
MTR_RequireConfigfileGetKeyNameFunc MTR_RequireConfigfileGetKeyName;

typedef void (MTR_CALL * MTR_RequireGetCurrentDirectoryFunc)(
 MTR_GetCurrentDirectoryFunc_t);
MTR_RequireGetCurrentDirectoryFunc MTR_RequireGetCurrentDirectory;

typedef void (MTR_CALL * MTR_RequireConfigfileGetSectionNameFunc)(
 MTR_ConfigfileGetSectionNameFunc_t);
MTR_RequireConfigfileGetSectionNameFunc MTR_RequireConfigfileGetSectionName;
typedef void (MTR_CALL * MTR_RequireConfigfileKeyExistsFunc)(
 MTR_ConfigfileKeyExistsFunc_t);
MTR_RequireConfigfileKeyExistsFunc MTR_RequireConfigfileKeyExists;
typedef void (MTR_CALL * MTR_RequireConfigfileSectionExistsFunc)(
 MTR_ConfigfileSectionExistsFunc_t);
MTR_RequireConfigfileSectionExistsFunc MTR_RequireConfigfileSectionExists;
typedef void (MTR_CALL * MTR_RequireConfigfileDeleteKeyFunc)(
 MTR_ConfigfileDeleteKeyFunc_t);
MTR_RequireConfigfileDeleteKeyFunc MTR_RequireConfigfileDeleteKey;
typedef void (MTR_CALL * MTR_RequireConfigfileDeleteSectionFunc)(
 MTR_ConfigfileDeleteSectionFunc_t);
MTR_RequireConfigfileDeleteSectionFunc MTR_RequireConfigfileDeleteSection;
typedef void (MTR_CALL * MTR_RequireConfigfileReadBoolFunc)(
 MTR_ConfigfileReadBoolFunc_t);
MTR_RequireConfigfileReadBoolFunc MTR_RequireConfigfileReadBool;
typedef void (MTR_CALL * MTR_RequireConfigfileReadIntFunc)(
 MTR_ConfigfileReadIntFunc_t);
MTR_RequireConfigfileReadIntFunc MTR_RequireConfigfileReadInt;
typedef void (MTR_CALL * MTR_RequireConfigfileReadSingleFunc)(
 MTR_ConfigfileReadSingleFunc_t);
MTR_RequireConfigfileReadSingleFunc MTR_RequireConfigfileReadSingle;
typedef void (MTR_CALL * MTR_RequireConfigfileReadStringFunc)(
 MTR_ConfigfileReadStringFunc_t);
MTR_RequireConfigfileReadStringFunc MTR_RequireConfigfileReadString;
typedef void (MTR_CALL * MTR_RequireConfigfileWriteBoolFunc)(
 MTR_ConfigfileWriteBoolFunc_t);
MTR_RequireConfigfileWriteBoolFunc MTR_RequireConfigfileWriteBool;
typedef void (MTR_CALL * MTR_RequireConfigfileWriteIntFunc)(
 MTR_ConfigfileWriteIntFunc_t);
MTR_RequireConfigfileWriteIntFunc MTR_RequireConfigfileWriteInt;
typedef void (MTR_CALL * MTR_RequireConfigfileWriteSingleFunc)(
 MTR_ConfigfileWriteSingleFunc_t);
MTR_RequireConfigfileWriteSingleFunc MTR_RequireConfigfileWriteSingle;
typedef void (MTR_CALL * MTR_RequireConfigfileWriteStringFunc)(
 MTR_ConfigfileWriteStringFunc_t);
MTR_RequireConfigfileWriteStringFunc MTR_RequireConfigfileWriteString;
typedef bool (MTR_CALL * MTR_RequireConfigfileCreateSectionFunc)(
 MTR_ConfigfileCreateSectionFunc_t);
MTR_RequireConfigfileCreateSectionFunc MTR_RequireConfigfileCreateSection;

typedef void (MTR_CALL * MTR_RequireLogWriteFunc)(MTR_LogWriteFunc_t);
MTR_RequireLogWriteFunc MTR_RequireLogWrite;
typedef void (MTR_CALL * MTR_RequireLogWrite_sFunc)(MTR_LogWrite_sFunc_t);
MTR_RequireLogWrite_sFunc MTR_RequireLogWrite_s;
typedef void (MTR_CALL * MTR_RequireLogWrite_iFunc)(MTR_LogWrite_iFunc_t);
MTR_RequireLogWrite_iFunc MTR_RequireLogWrite_i;
typedef void (MTR_CALL * MTR_RequireLogWrite_dFunc)(MTR_LogWrite_dFunc_t);
MTR_RequireLogWrite_dFunc MTR_RequireLogWrite_d;

typedef void (MTR_CALL * MTR_RequireShowSimpleMessageBoxFunc)(
 MTR_ShowSimpleMessageBoxFunc_t);
MTR_RequireShowSimpleMessageBoxFunc MTR_RequireShowSimpleMessageBox;
typedef void (MTR_CALL * MTR_RequireShowYesNoMessageBoxFunc)(
 MTR_ShowYesNoMessageBoxFunc_t);
MTR_RequireShowYesNoMessageBoxFunc MTR_RequireShowYesNoMessageBox;
typedef void (MTR_CALL * MTR_RequireShowOkCancelMessageBoxFunc)(
 MTR_ShowOkCancelMessageBoxFunc_t);
MTR_RequireShowOkCancelMessageBoxFunc MTR_RequireShowOkCancelMessageBox;
typedef void (MTR_CALL * MTR_RequireShowInputDialogFunc)(
 MTR_ShowInputDialogFunc_t);
MTR_RequireShowInputDialogFunc MTR_RequireShowInputDialog;
typedef void (MTR_CALL * MTR_RequireShowPasswordDialogFunc)(
 MTR_ShowPasswordDialogFunc_t);
MTR_RequireShowPasswordDialogFunc MTR_RequireShowPasswordDialog;
typedef void (MTR_CALL * MTR_RequireAddFileFilterFunc)(
 MTR_AddFileFilterFunc_t);
MTR_RequireAddFileFilterFunc MTR_RequireAddFileFilter;
typedef void (MTR_CALL * MTR_RequireClearFileFiltersFunc)(
 MTR_ClearFileFiltersFunc_t);
MTR_RequireClearFileFiltersFunc MTR_RequireClearFileFilters;
typedef void (MTR_CALL * MTR_RequireShowSaveFileDialogFunc)(
 MTR_ShowSaveFileDialogFunc_t);
MTR_RequireShowSaveFileDialogFunc MTR_RequireShowSaveFileDialog;
typedef void (MTR_CALL * MTR_RequireShowOpenFileDialogFunc)(
 MTR_ShowOpenFileDialogFunc_t);
MTR_RequireShowOpenFileDialogFunc MTR_RequireShowOpenFileDialog;
typedef void (MTR_CALL * MTR_RequireShowSelectFolderDialogFunc)(
 MTR_ShowSelectFolderDialogFunc_t);
MTR_RequireShowSelectFolderDialogFunc MTR_RequireShowSelectFolderDialog;

typedef void (MTR_CALL * MTR_RequireNotifyFunc)(MTR_NotifyFunc_t);
MTR_RequireNotifyFunc MTR_RequireNotify;

typedef void (MTR_CALL * MTR_RequireIndexkeeperCreateFunc)(
 MTR_IndexkeeperCreateFunc_t);
MTR_RequireIndexkeeperCreateFunc MTR_RequireIndexkeeperCreate;
typedef void (MTR_CALL * MTR_RequireIndexkeeperGetFreeIndexFunc)(
 MTR_IndexkeeperGetFreeIndexFunc_t);
MTR_RequireIndexkeeperGetFreeIndexFunc MTR_RequireIndexkeeperGetFreeIndex;
typedef void (MTR_CALL * MTR_RequireIndexkeeperFreeIndexFunc)(
 MTR_IndexkeeperFreeIndexFunc_t);
MTR_RequireIndexkeeperFreeIndexFunc MTR_RequireIndexkeeperFreeIndex;
typedef void (MTR_CALL * MTR_RequireIndexkeeperIndexIsEmptyFunc)(
 MTR_IndexkeeperIndexIsEmptyFunc_t);
MTR_RequireIndexkeeperIndexIsEmptyFunc MTR_RequireIndexkeeperIndexIsEmpty;
typedef void (MTR_CALL * MTR_RequireIndexkeeperGetReservedDataCountFunc)(
 MTR_IndexkeeperGetReservedDataCountFunc_t);
MTR_RequireIndexkeeperGetReservedDataCountFunc MTR_RequireIndexkeeperGetReservedDataCount;
typedef void (MTR_CALL * MTR_RequireIndexkeeperDestroyFunc)(
 MTR_IndexkeeperDestroyFunc_t);
MTR_RequireIndexkeeperDestroyFunc MTR_RequireIndexkeeperDestroy;

typedef void (MTR_CALL * MTR_RequireFileOpenFunc)(MTR_FileOpenFunc_t);
MTR_RequireFileOpenFunc MTR_RequireFileOpen;
typedef void (MTR_CALL * MTR_RequireFileCloseFunc)(MTR_FileCloseFunc_t);
MTR_RequireFileCloseFunc MTR_RequireFileClose;
typedef void (MTR_CALL * MTR_RequireFileReadFunc)(MTR_FileReadFunc_t);
MTR_RequireFileReadFunc MTR_RequireFileRead;
typedef void (MTR_CALL * MTR_RequireFileWriteFunc)(MTR_FileWriteFunc_t);
MTR_RequireFileWriteFunc MTR_RequireFileWrite;
typedef void (MTR_CALL * MTR_RequireFileWriteLineFunc)(MTR_FileWriteLineFunc_t);
MTR_RequireFileWriteLineFunc MTR_RequireFileWriteLine;
typedef void (MTR_CALL * MTR_RequireFileWriteFastFunc)(MTR_FileWriteFastFunc_t);
MTR_RequireFileWriteFastFunc MTR_RequireFileWriteFast;
typedef void (MTR_CALL * MTR_RequireFileWriteLineFastFunc)(
 MTR_FileWriteLineFastFunc_t);
MTR_RequireFileWriteLineFastFunc MTR_RequireFileWriteLineFast;
typedef void (MTR_CALL * MTR_RequireFileExistsFunc)(MTR_FileExistsFunc_t);
MTR_RequireFileExistsFunc MTR_RequireFileExists;
typedef void (MTR_CALL * MTR_RequireFileGetStdFopenFunc)(
 MTR_FileGetStdFopenFunc_t);
MTR_RequireFileGetStdFopenFunc MTR_RequireFileGetStdFopen;
typedef void (MTR_CALL * MTR_RequireFileGetStdFcloseFunc)(
 MTR_FileGetStdFcloseFunc_t);
MTR_RequireFileGetStdFcloseFunc MTR_RequireFileGetStdFclose;
typedef void (MTR_CALL * MTR_RequireFileGetStdFeofFunc)(
 MTR_FileGetStdFeofFunc_t);
MTR_RequireFileGetStdFeofFunc MTR_RequireFileGetStdFeof;
typedef void (MTR_CALL * MTR_RequireFileGetStdFtellFunc)(
 MTR_FileGetStdFtellFunc_t);
MTR_RequireFileGetStdFtellFunc MTR_RequireFileGetStdFtell;
typedef void (MTR_CALL * MTR_RequireFileGetStdFseekFunc)(
 MTR_FileGetStdFseekFunc_t);
MTR_RequireFileGetStdFseekFunc MTR_RequireFileGetStdFseek;
typedef void (MTR_CALL * MTR_RequireFileGetStdRewindFunc)(
 MTR_FileGetStdRewindFunc_t);
MTR_RequireFileGetStdRewindFunc MTR_RequireFileGetStdRewind;
typedef void (MTR_CALL * MTR_RequireFileGetStdFreadFunc)(
 MTR_FileGetStdFreadFunc_t);
MTR_RequireFileGetStdFreadFunc MTR_RequireFileGetStdFread;
typedef void (MTR_CALL * MTR_RequireFileGetStdFwriteFunc)(
 MTR_FileGetStdFwriteFunc_t);
MTR_RequireFileGetStdFwriteFunc MTR_RequireFileGetStdFwrite;
typedef void (MTR_CALL * MTR_RequireFileGetStdFprintfFunc)(
 MTR_FileGetStdFprintfFunc_t);
MTR_RequireFileGetStdFprintfFunc MTR_RequireFileGetStdFprintf;
typedef void (MTR_CALL * MTR_RequireFileGetStdFreadableFunc)(
 MTR_FileGetStdFreadableFunc_t);
MTR_RequireFileGetStdFreadableFunc MTR_RequireFileGetStdFreadable;
typedef void (MTR_CALL * MTR_RequireFileGetStdFwritableFunc)(
 MTR_FileGetStdFwritableFunc_t);
MTR_RequireFileGetStdFwritableFunc MTR_RequireFileGetStdFwritable;

typedef void (MTR_CALL * MTR_RequireClipboardPutTextFunc)(
 MTR_ClipboardPutTextFunc_t);
MTR_RequireClipboardPutTextFunc MTR_RequireClipboardPutText;
typedef void (MTR_CALL * MTR_RequireClipboardGetTextFunc)(
 MTR_ClipboardGetTextFunc_t);
MTR_RequireClipboardGetTextFunc MTR_RequireClipboardGetText;

typedef void (MTR_CALL * MTR_RequireEncodingUtf8ToUcs4Func)(
 MTR_EncodingUtf8ToUcs4Func_t);
MTR_RequireEncodingUtf8ToUcs4Func MTR_RequireEncodingUtf8ToUcs4;
typedef void (MTR_CALL * MTR_RequireEncodingUtf8CodepointsFunc)(
 MTR_EncodingUtf8CodepointsFunc_t);
MTR_RequireEncodingUtf8CodepointsFunc MTR_RequireEncodingUtf8Codepoints;

typedef void (MTR_CALL * MTR_RequireStringBufferAddFunc)(
 MTR_StringBufferAddFunc_t);
MTR_RequireStringBufferAddFunc MTR_RequireStringBufferAdd;
typedef void (MTR_CALL * MTR_RequireStringBufferDeleteFunc)(
 MTR_StringBufferDeleteFunc_t);
MTR_RequireStringBufferDeleteFunc MTR_RequireStringBufferDelete;
typedef void (MTR_CALL * MTR_RequireStringBufferSetStringFunc)(
 MTR_StringBufferSetStringFunc_t);
MTR_RequireStringBufferSetStringFunc MTR_RequireStringBufferSetString;
typedef void (MTR_CALL * MTR_RequireStringBufferGetStringFunc)(
 MTR_StringBufferGetStringFunc_t);
MTR_RequireStringBufferGetStringFunc MTR_RequireStringBufferGetString;
typedef void (MTR_CALL * MTR_RequireStringBufferGetMaxLenFunc)(
 MTR_StringBufferGetMaxLenFunc_t);
MTR_RequireStringBufferGetMaxLenFunc MTR_RequireStringBufferGetMaxLen;

typedef void (MTR_CALL * MTR_RequireOptionsAliasFunc)(MTR_OptionsAliasFunc_t);
MTR_RequireOptionsAliasFunc MTR_RequireOptionsAlias;
typedef void (MTR_CALL * MTR_RequireOptionsGetFunc)(MTR_OptionsGetFunc_t);
MTR_RequireOptionsGetFunc MTR_RequireOptionsGet;
typedef void (MTR_CALL * MTR_RequireOptionsGet_bFunc)(MTR_OptionsGet_bFunc_t);
MTR_RequireOptionsGet_bFunc MTR_RequireOptionsGet_b;
typedef void (MTR_CALL * MTR_RequireOptionsGet_iFunc)(MTR_OptionsGet_iFunc_t);
MTR_RequireOptionsGet_iFunc MTR_RequireOptionsGet_i;
typedef void (MTR_CALL * MTR_RequireOptionsGet_lFunc)(MTR_OptionsGet_lFunc_t);
MTR_RequireOptionsGet_lFunc MTR_RequireOptionsGet_l;
typedef void (MTR_CALL * MTR_RequireOptionsGet_fFunc)(MTR_OptionsGet_fFunc_t);
MTR_RequireOptionsGet_fFunc MTR_RequireOptionsGet_f;
typedef void (MTR_CALL * MTR_RequireOptionsGet_dFunc)(MTR_OptionsGet_dFunc_t);
MTR_RequireOptionsGet_dFunc MTR_RequireOptionsGet_d;

typedef void (MTR_CALL * MTR_RequireConsoleShowFunc)(MTR_ConsoleShowFunc_t);
MTR_RequireConsoleShowFunc MTR_RequireConsoleShow;
typedef void (MTR_CALL * MTR_RequireConsoleHideFunc)(MTR_ConsoleHideFunc_t);
MTR_RequireConsoleHideFunc MTR_RequireConsoleHide;

typedef void (MTR_CALL * MTR_RequireSoLoadSymbolFunc)(MTR_SoLoadSymbolFunc_t);
MTR_RequireSoLoadSymbolFunc MTR_RequireSoLoadSymbol;

typedef void (MTR_CALL * MTR_RequirePluginDataFunc)(mtrPlugin *, uint8_t);
MTR_RequirePluginDataFunc MTR_RequirePluginData;

typedef void (MTR_CALL * MTR_ScriptsAutorunFunc)(char *);
MTR_ScriptsAutorunFunc MTR_ScriptsAutorun;

#define MTR_REQUIRE_ENGINE_FUNC(require_funcname, funcname)                 \
    require_funcname = (require_funcname ## Func)MTR_SoLoadSymbol(          \
     mtrPluginData[plugin].so, #require_funcname);                          \
    if (require_funcname != NULL)                                           \
        require_funcname(funcname);                                         \
    else                                                                    \
        MTR_LogWrite(                                                       \
         "Module are not contain declaration for '" #funcname" ' function", \
         1, MTR_LMT_WARNING);

#endif /* MTR_MOD_PLUGIN */

#endif
