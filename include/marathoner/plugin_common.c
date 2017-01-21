#include <string.h>

MTR_EXPORT void MTR_CALL mtrRequireConfigfileGetKeyName(mtrConfigfileGetKeyNameFunc_t ConfigfileGetKeyNameFunc)
{
    mtrConfigfileGetKeyName = ConfigfileGetKeyNameFunc;
}

MTR_EXPORT void MTR_CALL mtrRequireConfigfileGetSectionName(mtrConfigfileGetSectionNameFunc_t ConfigfileGetSectionNameFunc)
{
    mtrConfigfileGetSectionName = ConfigfileGetSectionNameFunc;
}

MTR_EXPORT void MTR_CALL mtrRequireConfigfileDeleteKey(mtrConfigfileDeleteKeyFunc_t ConfigfileDeleteKeyFunc)
{
    mtrConfigfileDeleteKey = ConfigfileDeleteKeyFunc;
}

MTR_EXPORT void MTR_CALL mtrRequireConfigfileDeleteSection(mtrConfigfileDeleteSectionFunc_t ConfigfileDeleteSectionFunc)
{
    mtrConfigfileDeleteSection = ConfigfileDeleteSectionFunc;
}

MTR_EXPORT void MTR_CALL mtrRequireConfigfileReadBool(mtrConfigfileReadBoolFunc_t ConfigfileReadBoolFunc)
{
    mtrConfigfileReadBool = ConfigfileReadBoolFunc;
}

MTR_EXPORT void MTR_CALL mtrRequireConfigfileReadInt(mtrConfigfileReadIntFunc_t ConfigfileReadIntFunc)
{
    mtrConfigfileReadInt = ConfigfileReadIntFunc;
}

MTR_EXPORT void MTR_CALL mtrRequireConfigfileReadSingle(mtrConfigfileReadSingleFunc_t ConfigfileReadSingleFunc)
{
    mtrConfigfileReadSingle = ConfigfileReadSingleFunc;
}

MTR_EXPORT void MTR_CALL mtrRequireConfigfileReadString(mtrConfigfileReadStringFunc_t ConfigfileReadStringFunc)
{
    mtrConfigfileReadString = ConfigfileReadStringFunc;
}

MTR_EXPORT void MTR_CALL mtrRequireConfigfileWriteInt(mtrConfigfileWriteIntFunc_t ConfigfileWriteIntFunc)
{
    mtrConfigfileWriteInt = ConfigfileWriteIntFunc;
}

MTR_EXPORT void MTR_CALL mtrRequireConfigfileWriteSingle(mtrConfigfileWriteSingleFunc_t ConfigfileWriteSingleFunc)
{
    mtrConfigfileWriteSingle = ConfigfileWriteSingleFunc;
}

MTR_EXPORT void MTR_CALL mtrRequireConfigfileWriteString(mtrConfigfileWriteStringFunc_t ConfigfileWriteStringFunc)
{
    mtrConfigfileWriteString = ConfigfileWriteStringFunc;
}

MTR_EXPORT void MTR_CALL mtrRequireLogWrite(mtrLogWriteFunc_t LogWriteFunc)
{
    mtrLogWrite = LogWriteFunc;
}

MTR_EXPORT void MTR_CALL mtrRequireLogWrite_s(mtrLogWrite_sFunc_t LogWrite_sFunc)
{
    mtrLogWrite_s = LogWrite_sFunc;
}

MTR_EXPORT void MTR_CALL mtrRequireLogWrite_i(mtrLogWrite_iFunc_t LogWrite_iFunc)
{
    mtrLogWrite_i = LogWrite_iFunc;
}

MTR_EXPORT void MTR_CALL mtrRequireLogWrite_d(mtrLogWrite_dFunc_t LogWrite_dFunc)
{
    mtrLogWrite_d = LogWrite_dFunc;
}

MTR_EXPORT void MTR_CALL mtrRequireNotify(mtrNotifyFunc_t NotifyFunc)
{
    mtrNotify = NotifyFunc;
}

MTR_EXPORT void MTR_CALL mtrRequireIndexkeeperCreate(mtrIndexkeeperCreateFunc_t IndexkeeperCreateFunc)
{
    mtrIndexkeeperCreate = IndexkeeperCreateFunc;
}

MTR_EXPORT void MTR_CALL mtrRequireIndexkeeperGetFreeIndex(mtrIndexkeeperGetFreeIndexFunc_t IndexkeeperGetFreeIndexFunc)
{
    mtrIndexkeeperGetFreeIndex = IndexkeeperGetFreeIndexFunc;
}

MTR_EXPORT void MTR_CALL mtrRequireIndexkeeperFreeIndex(mtrIndexkeeperFreeIndexFunc_t IndexkeeperFreeIndexFunc)
{
    mtrIndexkeeperFreeIndex = IndexkeeperFreeIndexFunc;
}

MTR_EXPORT void MTR_CALL mtrRequireIndexkeeperIndexIsEmpty(mtrIndexkeeperIndexIsEmptyFunc_t IndexkeeperIndexIsEmptyFunc)
{
    mtrIndexkeeperIndexIsEmpty = IndexkeeperIndexIsEmptyFunc;
}

MTR_EXPORT void MTR_CALL mtrRequireIndexkeeperDestroy(mtrIndexkeeperDestroyFunc_t IndexkeeperDestroyFunc)
{
    mtrIndexkeeperDestroy = IndexkeeperDestroyFunc;
}

MTR_EXPORT void MTR_CALL mtrRequireFileWriteLine(mtrFileWriteLineFunc_t FileWriteLineFunc)
{
    mtrFileWriteLine = FileWriteLineFunc;
}

MTR_EXPORT void MTR_CALL mtrRequirePluginData(mtrPlugin* pluginData,
 uint8_t pluginsCount)
{
    mtrPluginData = pluginData;
    mtrPluginsCount = pluginsCount;
}

void *mtrFindFunction(char *moduleID, char *functionName)
{
    uint8_t i;
    for (i = 0; i < mtrPluginsCount; i++)
    {
        if (strcmp(mtrPluginData[i].report->moduleID, moduleID) == 0)
        {
            return (void *)mtrLoadSymbolName(mtrPluginData[i].dll,
             functionName);
        }
    }
    return NULL;
}

void *mtrFindFunctionInSubsystem(char *subsystem, char *functionName)
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
                return (void *)mtrLoadSymbolName(mtrPluginData[i].dll,
                 functionName);
            }
        }
    return NULL;
}
