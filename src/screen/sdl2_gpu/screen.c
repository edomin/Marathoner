#include "screen.h"

#include "marathoner/plugin_common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Screen_SDL2_gpu";
    report->version = MTR_VERSION_SCREEN_SDL2_GPU;
    report->subsystem = "screen";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}

MTR_EXPORT bool MTR_CALL mtrScreenInit(int width, int height)
{
    mtrLogWrite("Creating Window", 0, MTR_LMT_INFO);
    mtrScreen = malloc(sizeof(mtrScreen_t));
    if (mtrScreen == NULL)
    {
        mtrNotify("Unable to allocate memory for mtrScreen structure", 1,
         MTR_LMT_ERROR);
        return false;
    }
    mtrScreen->screen = GPU_Init(width, height, GPU_DEFAULT_INIT_FLAGS);
//    mtrScreen->screen = GPU_Init(width, height, GPU_INIT_ENABLE_VSYNC);
//    GPU_SetFullscreen(true, false);
    if (mtrScreen->screen != NULL)
        mtrLogWrite("Window created", 1, MTR_LMT_INFO);
    else
    {
        mtrNotify("Unable to create window", 1, MTR_LMT_ERROR);
        free(mtrScreen);
        return false;
    }
    mtrScreen->target = mtrScreen->screen;

    return true;
}

MTR_EXPORT void MTR_CALL mtrScreenQuit(void)
{
    GPU_Quit();
    free(mtrScreen);
    mtrLogWrite("Window destroyed", 0, MTR_LMT_INFO);
}

MTR_EXPORT void MTR_CALL mtrScreenFlip(void)
{
    GPU_Flip(mtrScreen->screen);
}

MTR_EXPORT mtrScreen_t *MTR_CALL mtrGetScreen(void)
{
    return mtrScreen;
}
