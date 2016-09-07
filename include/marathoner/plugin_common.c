MRT_EXPORT void MRT_CALL mtrRequireLogWrite(mtrLogWriteFunc_t LogWriteFunc)
{
    mtrLogWrite = LogWriteFunc;
}

MRT_EXPORT void MRT_CALL mtrRequireLogWrite_s(mtrLogWrite_sFunc_t LogWrite_sFunc)
{
    mtrLogWrite_s = LogWrite_sFunc;
}

MRT_EXPORT void MRT_CALL mtrRequireLogWrite_i(mtrLogWrite_iFunc_t LogWrite_iFunc)
{
    mtrLogWrite_i = LogWrite_iFunc;
}

MRT_EXPORT void MRT_CALL mtrRequireLogWrite_d(mtrLogWrite_dFunc_t LogWrite_dFunc)
{
    mtrLogWrite_d = LogWrite_dFunc;
}

MRT_EXPORT void MRT_CALL mtrRequireNotify(mtrNotifyFunc_t NotifyFunc)
{
    mtrNotify = NotifyFunc;
}

MRT_EXPORT void MRT_CALL mtrRequireIndexkeeperCreate(mtrIndexkeeperCreateFunc_t IndexkeeperCreateFunc)
{
    mtrIndexkeeperCreate = IndexkeeperCreateFunc;
}

MRT_EXPORT void MRT_CALL mtrRequireIndexkeeperGetFreeIndex(mtrIndexkeeperGetFreeIndexFunc_t IndexkeeperGetFreeIndexFunc)
{
    mtrIndexkeeperGetFreeIndex = IndexkeeperGetFreeIndexFunc;
}

MRT_EXPORT void MRT_CALL mtrRequireIndexkeeperFreeIndex(mtrIndexkeeperFreeIndexFunc_t IndexkeeperFreeIndexFunc)
{
    mtrIndexkeeperFreeIndex = IndexkeeperFreeIndexFunc;
}

MRT_EXPORT void MRT_CALL mtrRequireIndexkeeperDestroy(mtrIndexkeeperDestroyFunc_t IndexkeeperDestroyFunc)
{
    mtrIndexkeeperDestroy = IndexkeeperDestroyFunc;
}

MRT_EXPORT void MRT_CALL mtrRequireFileWriteLine(mtrFileWriteLineFunc_t FileWriteLineFunc)
{
    mtrFileWriteLine = FileWriteLineFunc;
}

MRT_EXPORT void MRT_CALL mtrRequirePluginData(mtrPlugin* pluginData,
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
            return (void *)GetProcAddress(mtrPluginData[i].dll, functionName);
        }
    }
    return NULL;
}
