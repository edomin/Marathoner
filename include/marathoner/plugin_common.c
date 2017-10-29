#ifndef MTR_PLUGIN_COMMON_C
#define MTR_PLUGIN_COMMON_C

#include <string.h>

MTR_DCLSPC void MTR_CALL MTR_RequireMarathonerGetVersion(
 MTR_MarathonerGetVersionFunc_t MarathonerGetVersionFunc)
{
    MTR_MarathonerGetVersion = MarathonerGetVersionFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireMarathonerGetModuleVersion(
 MTR_MarathonerGetModuleVersionFunc_t MarathonerGetModuleVersionFunc)
{
    MTR_MarathonerGetModuleVersion = MarathonerGetModuleVersionFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireConfigfileGetKeyName(
 MTR_ConfigfileGetKeyNameFunc_t ConfigfileGetKeyNameFunc)
{
    MTR_ConfigfileGetKeyName = ConfigfileGetKeyNameFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireConfigfileGetSectionName(
 MTR_ConfigfileGetSectionNameFunc_t ConfigfileGetSectionNameFunc)
{
    MTR_ConfigfileGetSectionName = ConfigfileGetSectionNameFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireConfigfileKeyExists(
 MTR_ConfigfileKeyExistsFunc_t ConfigfileKeyExistsFunc)
{
    MTR_ConfigfileKeyExists = ConfigfileKeyExistsFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireConfigfileSectionExists(
 MTR_ConfigfileSectionExistsFunc_t ConfigfileSectionExistsFunc)
{
    MTR_ConfigfileSectionExists = ConfigfileSectionExistsFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireConfigfileDeleteKey(
 MTR_ConfigfileDeleteKeyFunc_t ConfigfileDeleteKeyFunc)
{
    MTR_ConfigfileDeleteKey = ConfigfileDeleteKeyFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireConfigfileDeleteSection(
 MTR_ConfigfileDeleteSectionFunc_t ConfigfileDeleteSectionFunc)
{
    MTR_ConfigfileDeleteSection = ConfigfileDeleteSectionFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireConfigfileReadBool(
 MTR_ConfigfileReadBoolFunc_t ConfigfileReadBoolFunc)
{
    MTR_ConfigfileReadBool = ConfigfileReadBoolFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireConfigfileReadInt(
 MTR_ConfigfileReadIntFunc_t ConfigfileReadIntFunc)
{
    MTR_ConfigfileReadInt = ConfigfileReadIntFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireConfigfileReadSingle(
 MTR_ConfigfileReadSingleFunc_t ConfigfileReadSingleFunc)
{
    MTR_ConfigfileReadSingle = ConfigfileReadSingleFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireConfigfileReadString(
 MTR_ConfigfileReadStringFunc_t ConfigfileReadStringFunc)
{
    MTR_ConfigfileReadString = ConfigfileReadStringFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireConfigfileWriteBool(
 MTR_ConfigfileWriteBoolFunc_t ConfigfileWriteBoolFunc)
{
    MTR_ConfigfileWriteBool = ConfigfileWriteBoolFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireConfigfileWriteInt(
 MTR_ConfigfileWriteIntFunc_t ConfigfileWriteIntFunc)
{
    MTR_ConfigfileWriteInt = ConfigfileWriteIntFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireConfigfileWriteSingle(
 MTR_ConfigfileWriteSingleFunc_t ConfigfileWriteSingleFunc)
{
    MTR_ConfigfileWriteSingle = ConfigfileWriteSingleFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireConfigfileWriteString(
 MTR_ConfigfileWriteStringFunc_t ConfigfileWriteStringFunc)
{
    MTR_ConfigfileWriteString = ConfigfileWriteStringFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireConfigfileCreateSection(
 MTR_ConfigfileCreateSectionFunc_t ConfigfileCreateSectionFunc)
{
    MTR_ConfigfileCreateSection = ConfigfileCreateSectionFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireLogWrite(MTR_LogWriteFunc_t LogWriteFunc)
{
    MTR_LogWrite = LogWriteFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireLogWrite_s(
 MTR_LogWrite_sFunc_t LogWrite_sFunc)
{
    MTR_LogWrite_s = LogWrite_sFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireLogWrite_i(
 MTR_LogWrite_iFunc_t LogWrite_iFunc)
{
    MTR_LogWrite_i = LogWrite_iFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireLogWrite_d(
 MTR_LogWrite_dFunc_t LogWrite_dFunc)
{
    MTR_LogWrite_d = LogWrite_dFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireShowSimpleMessageBox(
 MTR_ShowSimpleMessageBoxFunc_t ShowSimpleMessageBoxFunc)
{
    MTR_ShowSimpleMessageBox = ShowSimpleMessageBoxFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireShowYesNoMessageBox(
 MTR_ShowYesNoMessageBoxFunc_t ShowYesNoMessageBoxFunc)
{
    MTR_ShowYesNoMessageBox = ShowYesNoMessageBoxFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireShowOkCancelMessageBox(
 MTR_ShowOkCancelMessageBoxFunc_t ShowOkCancelMessageBoxFunc)
{
    MTR_ShowOkCancelMessageBox = ShowOkCancelMessageBoxFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireShowInputDialog(
 MTR_ShowInputDialogFunc_t ShowInputDialogFunc)
{
    MTR_ShowInputDialog = ShowInputDialogFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireShowPasswordDialog(
 MTR_ShowPasswordDialogFunc_t ShowPasswordDialogFunc)
{
    MTR_ShowPasswordDialog = ShowPasswordDialogFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireAddFileFilter(
 MTR_AddFileFilterFunc_t AddFileFilterFunc)
{
    MTR_AddFileFilter = AddFileFilterFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireClearFileFilters(
 MTR_ClearFileFiltersFunc_t ClearFileFiltersFunc)
{
    MTR_ClearFileFilters = ClearFileFiltersFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireShowSaveFileDialog(
 MTR_ShowSaveFileDialogFunc_t ShowSaveFileDialogFunc)
{
    MTR_ShowSaveFileDialog = ShowSaveFileDialogFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireShowOpenFileDialog(
 MTR_ShowOpenFileDialogFunc_t ShowOpenFileDialogFunc)
{
    MTR_ShowOpenFileDialog = ShowOpenFileDialogFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireShowSelectFolderDialog(
 MTR_ShowSelectFolderDialogFunc_t ShowSelectFolderDialogFunc)
{
    MTR_ShowSelectFolderDialog = ShowSelectFolderDialogFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireNotify(MTR_NotifyFunc_t NotifyFunc)
{
    MTR_Notify = NotifyFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireIndexkeeperCreate(
 MTR_IndexkeeperCreateFunc_t IndexkeeperCreateFunc)
{
    MTR_IndexkeeperCreate = IndexkeeperCreateFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireIndexkeeperGetFreeIndex(
 MTR_IndexkeeperGetFreeIndexFunc_t IndexkeeperGetFreeIndexFunc)
{
    MTR_IndexkeeperGetFreeIndex = IndexkeeperGetFreeIndexFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireIndexkeeperFreeIndex(
 MTR_IndexkeeperFreeIndexFunc_t IndexkeeperFreeIndexFunc)
{
    MTR_IndexkeeperFreeIndex = IndexkeeperFreeIndexFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireIndexkeeperIndexIsEmpty(
 MTR_IndexkeeperIndexIsEmptyFunc_t IndexkeeperIndexIsEmptyFunc)
{
    MTR_IndexkeeperIndexIsEmpty = IndexkeeperIndexIsEmptyFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireIndexkeeperGetReservedDataCount(
 MTR_IndexkeeperGetReservedDataCountFunc_t IndexkeeperGetReservedDataCountFunc)
{
    MTR_IndexkeeperGetReservedDataCount = IndexkeeperGetReservedDataCountFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireIndexkeeperDestroy(
 MTR_IndexkeeperDestroyFunc_t IndexkeeperDestroyFunc)
{
    MTR_IndexkeeperDestroy = IndexkeeperDestroyFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireEncodingUtf8ToUcs4(
 MTR_EncodingUtf8ToUcs4Func_t EncodingUtf8ToUcs4Func)
{
    MTR_EncodingUtf8ToUcs4 = EncodingUtf8ToUcs4Func;
}

MTR_DCLSPC void MTR_CALL MTR_RequireEncodingUtf8Codepoints(
 MTR_EncodingUtf8CodepointsFunc_t EncodingUtf8CodepointsFunc)
{
    MTR_EncodingUtf8Codepoints = EncodingUtf8CodepointsFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireFileOpen(MTR_FileOpenFunc_t FileOpenFunc)
{
    MTR_FileOpen = FileOpenFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireFileClose(MTR_FileCloseFunc_t FileCloseFunc)
{
    MTR_FileClose = FileCloseFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireFileRead(MTR_FileReadFunc_t FileReadFunc)
{
    MTR_FileRead = FileReadFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireFileWrite(MTR_FileWriteFunc_t FileWriteFunc)
{
    MTR_FileWrite = FileWriteFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireFileWriteLine(
 MTR_FileWriteLineFunc_t FileWriteLineFunc)
{
    MTR_FileWriteLine = FileWriteLineFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireFileWriteFast(
 MTR_FileWriteFastFunc_t FileWriteFastFunc)
{
    MTR_FileWriteFast = FileWriteFastFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireFileWriteLineFast(
 MTR_FileWriteLineFastFunc_t FileWriteLineFastFunc)
{
    MTR_FileWriteLineFast = FileWriteLineFastFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireClipboardPutText(
 MTR_ClipboardPutTextFunc_t ClipboardPutTextFunc)
{
    MTR_ClipboardPutText = ClipboardPutTextFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireClipboardGetText(
 MTR_ClipboardGetTextFunc_t ClipboardGetTextFunc)
{
    MTR_ClipboardGetText = ClipboardGetTextFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireStringBufferAdd(
 MTR_StringBufferAddFunc_t StringBufferAddFunc)
{
    MTR_StringBufferAdd = StringBufferAddFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireStringBufferDelete(
 MTR_StringBufferDeleteFunc_t StringBufferDeleteFunc)
{
    MTR_StringBufferDelete = StringBufferDeleteFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireStringBufferSetString(
 MTR_StringBufferSetStringFunc_t StringBufferSetStringFunc)
{
    MTR_StringBufferSetString = StringBufferSetStringFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireStringBufferGetString(
 MTR_StringBufferGetStringFunc_t StringBufferGetStringFunc)
{
    MTR_StringBufferGetString = StringBufferGetStringFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireStringBufferGetMaxLen(
 MTR_StringBufferGetMaxLenFunc_t StringBufferGetMaxLenFunc)
{
    MTR_StringBufferGetMaxLen = StringBufferGetMaxLenFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireOptionsAlias(
 MTR_OptionsAliasFunc_t OptionsAliasFunc)
{
    MTR_OptionsAlias = OptionsAliasFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireOptionsGet(
 MTR_OptionsGetFunc_t OptionsGetFunc)
{
    MTR_OptionsGet = OptionsGetFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireOptionsGet_b(
 MTR_OptionsGet_bFunc_t OptionsGet_bFunc)
{
    MTR_OptionsGet_b = OptionsGet_bFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireOptionsGet_i(
 MTR_OptionsGet_iFunc_t OptionsGet_iFunc)
{
    MTR_OptionsGet_i = OptionsGet_iFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireOptionsGet_l(
 MTR_OptionsGet_lFunc_t OptionsGet_lFunc)
{
    MTR_OptionsGet_l = OptionsGet_lFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireOptionsGet_f(
 MTR_OptionsGet_fFunc_t OptionsGet_fFunc)
{
    MTR_OptionsGet_f = OptionsGet_fFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireOptionsGet_d(
 MTR_OptionsGet_dFunc_t OptionsGet_dFunc)
{
    MTR_OptionsGet_d = OptionsGet_dFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireConsoleShow(
 MTR_ConsoleShowFunc_t ConsoleShowFunc)
{
    MTR_ConsoleShow = ConsoleShowFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireConsoleHide(
 MTR_ConsoleHideFunc_t ConsoleHideFunc)
{
    MTR_ConsoleHide = ConsoleHideFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequireSoLoadSymbol(
 MTR_SoLoadSymbolFunc_t SoLoadSymbolFunc)
{
    MTR_SoLoadSymbol = SoLoadSymbolFunc;
}

MTR_DCLSPC void MTR_CALL MTR_RequirePluginData(mtrPlugin* pluginData,
 uint8_t pluginsCount)
{
    mtrPluginData = pluginData;
    mtrPluginsCount = pluginsCount;
}

void *MTR_FindFunction(char *moduleID, char *functionName)
{
    uint8_t i;
    for (i = 0; i < mtrPluginsCount; i++)
    {
        if (strcmp(mtrPluginData[i].report->moduleID, moduleID) == 0)
        {
            return (void *)MTR_SoLoadSymbol(mtrPluginData[i].so,
             functionName);
        }
    }
    return NULL;
}

void *MTR_FindFunctionInSubsystem(char *subsystem, char *functionName)
{
    uint8_t i;
    if ((strcmp(subsystem, "binding") == 0) ||
     (strcmp(subsystem, "abstraction") == 0) ||
     (strcmp(subsystem, "utils") == 0))
        return NULL;
    else
        for (i = 0; i < mtrPluginsCount; i++)
        {
            if (strcmp(mtrPluginData[i].report->subsystem, subsystem) == 0)
            {
                return (void *)MTR_SoLoadSymbol(mtrPluginData[i].so,
                 functionName);
            }
        }
    return NULL;
}

#endif
