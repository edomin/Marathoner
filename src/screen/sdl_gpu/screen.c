#include "screen.h"

#include "plugin_common.c"

__declspec(dllexport) mtrReport* __stdcall mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Screen_sdl_gpu";
    report->version = 0x000000;
    report->prereqsCount = 0;
    report->prereqs = NULL;
    return report;
}

__declspec(dllexport) void __stdcall mtrScreenInit(uint16_t width, uint16_t height)
{
    mtrLogWrite("Creating Window", 0, MTR_LMT_INFO);
    mtrScreen = malloc(sizeof(mtrScreen_t));
    if (mtrScreen == NULL)
        mtrNotify("Unable to allocate memory for mtrScreen structure", 1,
         MTR_LMT_ERROR);
    mtrScreen->screen = GPU_Init(width, height, GPU_DEFAULT_INIT_FLAGS);
    if (mtrScreen->screen != NULL)
        mtrLogWrite("Window created", 1, MTR_LMT_INFO);
    else
        mtrNotify("Unable to create window", 1, MTR_LMT_ERROR);
}

__declspec(dllexport) void __stdcall mtrScreenQuit(void)
{
    GPU_Quit();
    free(mtrScreen);
    mtrLogWrite("Window destroyed", 0, MTR_LMT_INFO);
}

__declspec(dllexport) void __stdcall mtrScreenFlip(void)
{
    GPU_Flip(mtrScreen->screen);
}

__declspec(dllexport) mtrScreen_t *__stdcall mtrGetScreen(void)
{
    return mtrScreen;
}
