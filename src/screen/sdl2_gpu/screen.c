#include "screen.h"

#ifdef MTR_MOD_PLUGIN
#include "marathoner/plugin_common.c"

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
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
#endif

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Screen, FA_FUNCTIONS_COUNT)

/*fa MTR_ScreenInit partially */
MTR_DCLSPC bool MTR_CALL MTR_ScreenInit(int width, int height, bool fullscreen,
 const char *title)
{
//    const char *actualTitle;
//    const char  defaultTitle[] = "Marathoner";

    MTR_LogWrite("Creating Window", 0, MTR_LMT_INFO);
    mtrScreen = malloc(sizeof(mtrScreen_t));
    if (mtrScreen == NULL)
    {
        MTR_Notify("Unable to allocate memory for mtrScreen structure", 1,
         MTR_LMT_ERROR);
        return false;
    }
    mtrScreen->screen = GPU_Init(width, height, GPU_DEFAULT_INIT_FLAGS);
//    mtrScreen->screen = GPU_Init(width, height, GPU_INIT_ENABLE_VSYNC);
    GPU_SetFullscreen(fullscreen, false);
    if (mtrScreen->screen != NULL)
        MTR_LogWrite("Window created", 1, MTR_LMT_INFO);
    else
    {
        MTR_Notify("Unable to create window", 1, MTR_LMT_ERROR);
        free(mtrScreen);
        return false;
    }
    mtrScreen->target = mtrScreen->screen;

    mtrScreenInited = true;
    return true;
}

/*fa MTR_ScreenQuit yes */
MTR_DCLSPC void MTR_CALL MTR_ScreenQuit(void)
{
    MTR_SCREEN_CHECK_IF_NOT_INITED_WITH_LOG("Unable to destroy Screen",);

    GPU_Quit();
    free(mtrScreen);
    MTR_LogWrite("Screen destroyed", 0, MTR_LMT_INFO);
}

/*fa MTR_ScreenFlip yes */
MTR_DCLSPC void MTR_CALL MTR_ScreenFlip(void)
{
    MTR_SCREEN_CHECK_IF_NOT_INITED();

    GPU_Flip(mtrScreen->screen);
}

/*fa MTR_ScreenGetSizes yes */
MTR_DCLSPC void MTR_CALL MTR_ScreenGetSizes(int *w, int *h)
{
    uint16_t width;
    uint16_t height;

    if (!mtrScreenInited)
    {
        *w = 0;
        *h = 0;
        return;
    }

    GPU_GetVirtualResolution(mtrScreen->screen, &width, &height);
    if (w != NULL)
        *w = width;
    if (h != NULL)
        *h = height;
}

/*fa MTR_ScreenGetWidth yes */
MTR_DCLSPC int MTR_CALL MTR_ScreenGetWidth(void)
{
    uint16_t width;
    uint16_t height;
    MTR_SCREEN_CHECK_IF_NOT_INITED(0);

    GPU_GetVirtualResolution(mtrScreen->screen, &width, &height);
    return width;
}

/*fa MTR_ScreenGetHeight yes */
MTR_DCLSPC int MTR_CALL MTR_ScreenGetHeight(void)
{
    uint16_t width;
    uint16_t height;
    MTR_SCREEN_CHECK_IF_NOT_INITED(0);

    GPU_GetVirtualResolution(mtrScreen->screen, &width, &height);
    return height;
}

/*fa MTR_ScreenXed yes */
MTR_DCLSPC bool MTR_CALL MTR_ScreenXed(void)
{
    SDL_Event events[32];
    int       numEvents;
    MTR_SCREEN_CHECK_IF_NOT_INITED(false);

    numEvents = SDL_PeepEvents(events, 32, SDL_GETEVENT, SDL_QUIT, SDL_QUIT);

    if (numEvents == 0)
        return false;

    return true;
}

MTR_DCLSPC mtrScreen_t *MTR_CALL MTR_GetScreen(void)
{
    MTR_SCREEN_CHECK_IF_NOT_INITED(NULL);

    return mtrScreen;
}
