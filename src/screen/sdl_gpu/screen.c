#include "screen.h"

#include "marathoner/plugin_common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Screen_sdl_gpu";
    report->version = MTR_VERSION_SCREEN_SDL2_GPU;
    report->subsystem = "screen";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}

MTR_EXPORT void MTR_CALL mtrScreenInit(uint16_t width, uint16_t height)
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
