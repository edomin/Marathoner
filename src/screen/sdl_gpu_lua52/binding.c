#include "binding.h"

__declspec(dllexport) mtrReport* __stdcall mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Screen_sdl_gpu_Lua52";
    report->prereqsCount = 2;
    report->prereqs[0] = "Screen_sdl_gpu";
    report->prereqs[1] = "Script_Lua52";
    return report;
}

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

