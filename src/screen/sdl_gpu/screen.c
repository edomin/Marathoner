#include "screen.h"

mtrReport* __stdcall mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Screen_sdl_gpu";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    return report;
}

void mtrRequireEngineFuncs(mtrLogWriteFunc_t LogWriteFunc,
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

//void __stdcall mtrScreenInit(uint16_t width, uint16_t height)
//{
//    mtrScreen->screen = GPU_Init(width, height, GPU_DEFAULT_INIT_FLAGS);
//}
//
//void __stdcall mtrScreenInit(void)
//{
//    GPU_Quit();
//}
