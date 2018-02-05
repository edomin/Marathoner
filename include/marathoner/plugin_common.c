#ifndef MTR_PLUGIN_COMMON_C
#define MTR_PLUGIN_COMMON_C

#include "plugin_common.h"

MTR_REQUIRE_FUNC(MarathonerFunctionSupported)
MTR_REQUIRE_FUNC(MarathonerGetVersion)
MTR_REQUIRE_FUNC(MarathonerGetModuleVersion)
MTR_REQUIRE_FUNC(MarathonerGetSubsystemModuleId)

MTR_REQUIRE_FUNC(GetCurrentDirectory)

MTR_REQUIRE_FUNC(ConfigfileGetKeyName)
MTR_REQUIRE_FUNC(ConfigfileGetSectionName)
MTR_REQUIRE_FUNC(ConfigfileKeyExists)
MTR_REQUIRE_FUNC(ConfigfileSectionExists)
MTR_REQUIRE_FUNC(ConfigfileDeleteKey)
MTR_REQUIRE_FUNC(ConfigfileDeleteSection)
MTR_REQUIRE_FUNC(ConfigfileReadBool)
MTR_REQUIRE_FUNC(ConfigfileReadInt)
MTR_REQUIRE_FUNC(ConfigfileReadSingle)
MTR_REQUIRE_FUNC(ConfigfileReadString)
MTR_REQUIRE_FUNC(ConfigfileWriteBool)
MTR_REQUIRE_FUNC(ConfigfileWriteInt)
MTR_REQUIRE_FUNC(ConfigfileWriteSingle)
MTR_REQUIRE_FUNC(ConfigfileWriteString)
MTR_REQUIRE_FUNC(ConfigfileCreateSection)

MTR_REQUIRE_FUNC(LogWrite)
MTR_REQUIRE_FUNC(LogWrite_s)
MTR_REQUIRE_FUNC(LogWrite_i)
MTR_REQUIRE_FUNC(LogWrite_d)

MTR_REQUIRE_FUNC(ShowSimpleMessageBox)
MTR_REQUIRE_FUNC(ShowYesNoMessageBox)
MTR_REQUIRE_FUNC(ShowOkCancelMessageBox)
MTR_REQUIRE_FUNC(ShowInputDialog)
MTR_REQUIRE_FUNC(ShowPasswordDialog)
MTR_REQUIRE_FUNC(AddFileFilter)
MTR_REQUIRE_FUNC(ClearFileFilters)
MTR_REQUIRE_FUNC(ShowSaveFileDialog)
MTR_REQUIRE_FUNC(ShowOpenFileDialog)
MTR_REQUIRE_FUNC(ShowSelectFolderDialog)

MTR_REQUIRE_FUNC(Notify)

MTR_REQUIRE_FUNC(IndexkeeperCreate)
MTR_REQUIRE_FUNC(IndexkeeperGetFreeIndex)
MTR_REQUIRE_FUNC(IndexkeeperFreeIndex)
MTR_REQUIRE_FUNC(IndexkeeperIndexIsEmpty)
MTR_REQUIRE_FUNC(IndexkeeperGetReservedDataCount)
MTR_REQUIRE_FUNC(IndexkeeperDestroy)

MTR_REQUIRE_FUNC(EncodingUtf8ToUcs4)
MTR_REQUIRE_FUNC(EncodingUtf8Codepoints)

MTR_REQUIRE_FUNC(FileOpen)
MTR_REQUIRE_FUNC(FileClose)
MTR_REQUIRE_FUNC(FileRead)
MTR_REQUIRE_FUNC(FileWrite)
MTR_REQUIRE_FUNC(FileWriteLine)
MTR_REQUIRE_FUNC(FileWriteFast)
MTR_REQUIRE_FUNC(FileWriteLineFast)
MTR_REQUIRE_FUNC(FileExists)
MTR_REQUIRE_FUNC(FileGetStdFopen)
MTR_REQUIRE_FUNC(FileGetStdFclose)
MTR_REQUIRE_FUNC(FileGetStdFeof)
MTR_REQUIRE_FUNC(FileGetStdFtell)
MTR_REQUIRE_FUNC(FileGetStdFseek)
MTR_REQUIRE_FUNC(FileGetStdRewind)
MTR_REQUIRE_FUNC(FileGetStdFread)
MTR_REQUIRE_FUNC(FileGetStdFwrite)
MTR_REQUIRE_FUNC(FileGetStdFprintf)
MTR_REQUIRE_FUNC(FileGetStdFreadable)
MTR_REQUIRE_FUNC(FileGetStdFwritable)

MTR_REQUIRE_FUNC(ClipboardPutText)
MTR_REQUIRE_FUNC(ClipboardGetText)

MTR_REQUIRE_FUNC(StringBufferAdd)
MTR_REQUIRE_FUNC(StringBufferDelete)
MTR_REQUIRE_FUNC(StringBufferSetString)
MTR_REQUIRE_FUNC(StringBufferGetString)
MTR_REQUIRE_FUNC(StringBufferGetMaxLen)

MTR_REQUIRE_FUNC(OptionsAlias)
MTR_REQUIRE_FUNC(OptionsGet)
MTR_REQUIRE_FUNC(OptionsGet_b)
MTR_REQUIRE_FUNC(OptionsGet_i)
MTR_REQUIRE_FUNC(OptionsGet_l)
MTR_REQUIRE_FUNC(OptionsGet_f)
MTR_REQUIRE_FUNC(OptionsGet_d)

MTR_REQUIRE_FUNC(ConsoleShow)
MTR_REQUIRE_FUNC(ConsoleHide)

MTR_REQUIRE_FUNC(SoLoadSymbol)

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
