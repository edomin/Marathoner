__declspec(dllexport) void __stdcall mtrRequireEngineFuncs(mtrLogWriteFunc_t LogWriteFunc,
                           mtrLogWrite_sFunc_t LogWrite_sFunc,
                           mtrLogWrite_iFunc_t LogWrite_iFunc,
                           mtrLogWrite_dFunc_t LogWrite_dFunc,
                           mtrNotifyFunc_t NotifyFunc)
{
    mtrLogWrite = LogWriteFunc;
    mtrLogWrite_s = LogWrite_sFunc;
    mtrLogWrite_i = LogWrite_iFunc;
    mtrLogWrite_d = LogWrite_dFunc;
    mtrNotify = NotifyFunc;
}

__declspec(dllexport) void __stdcall mtrRequirePluginData(mtrPlugin* pluginData, uint8_t pluginsCount)
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
