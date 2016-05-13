#include "screen.h"

#include "plugin_common.c"

__declspec(dllexport) mtrReport* __stdcall mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Screen_sdl_gpu";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    return report;
}

__declspec(dllexport) void __stdcall mtrScreenInit(uint16_t width, uint16_t height)
{
    mtrScreen->screen = GPU_Init(width, height, GPU_DEFAULT_INIT_FLAGS);
}

__declspec(dllexport) void __stdcall mtrScreenQuit(void)
{
    GPU_Quit();
}
