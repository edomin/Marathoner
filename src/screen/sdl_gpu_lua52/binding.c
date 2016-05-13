#include "binding.h"

#include "plugin_common.c"

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
