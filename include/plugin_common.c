__declspec(dllexport) void __stdcall mtrRequireLogWrite(mtrLogWriteFunc_t LogWriteFunc)
{
    mtrLogWrite = LogWriteFunc;
}

__declspec(dllexport) void __stdcall mtrRequireLogWrite_s(mtrLogWrite_sFunc_t LogWrite_sFunc)
{
    mtrLogWrite_s = LogWrite_sFunc;
}

__declspec(dllexport) void __stdcall mtrRequireLogWrite_i(mtrLogWrite_iFunc_t LogWrite_iFunc)
{
    mtrLogWrite_i = LogWrite_iFunc;
}

__declspec(dllexport) void __stdcall mtrRequireLogWrite_d(mtrLogWrite_dFunc_t LogWrite_dFunc)
{
    mtrLogWrite_d = LogWrite_dFunc;
}

__declspec(dllexport) void __stdcall mtrRequireNotify(mtrNotifyFunc_t NotifyFunc)
{
    mtrNotify = NotifyFunc;
}

__declspec(dllexport) void __stdcall mtrRequireIndexkeeperCreate(mtrIndexkeeperCreateFunc_t IndexkeeperCreateFunc)
{
    mtrIndexkeeperCreate = IndexkeeperCreateFunc;
}

__declspec(dllexport) void __stdcall mtrRequireIndexkeeperGetFreeIndex(mtrIndexkeeperGetFreeIndexFunc_t IndexkeeperGetFreeIndexFunc)
{
    mtrIndexkeeperGetFreeIndex = IndexkeeperGetFreeIndexFunc;
}

__declspec(dllexport) void __stdcall mtrRequireIndexkeeperFreeIndex(mtrIndexkeeperFreeIndexFunc_t IndexkeeperFreeIndexFunc)
{
    mtrIndexkeeperFreeIndex = IndexkeeperFreeIndexFunc;
}

__declspec(dllexport) void __stdcall mtrRequireIndexkeeperDestroy(mtrIndexkeeperDestroyFunc_t IndexkeeperDestroyFunc)
{
    mtrIndexkeeperDestroy = IndexkeeperDestroyFunc;
}

__declspec(dllexport) void __stdcall mtrRequirePluginData(mtrPlugin* pluginData,
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
