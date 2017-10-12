#include "screen.h"

#include "marathoner/plugin_common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Screen, FA_FUNCTIONS_COUNT)

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

/*fa mtrScreenInit partially */
MTR_EXPORT bool MTR_CALL mtrScreenInit(int width, int height, bool fullscreen,
 const char *title)
{
//    const char *actualTitle;
//    const char  defaultTitle[] = "Marathoner";

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
    GPU_SetFullscreen(fullscreen, false);
    if (mtrScreen->screen != NULL)
        mtrLogWrite("Window created", 1, MTR_LMT_INFO);
    else
    {
        mtrNotify("Unable to create window", 1, MTR_LMT_ERROR);
        free(mtrScreen);
        return false;
    }
    mtrScreen->target = mtrScreen->screen;

    mtrScreenInited = true;
    return true;
}

/*fa mtrScreenQuit yes */
MTR_EXPORT void MTR_CALL mtrScreenQuit(void)
{
    MTR_SCREEN_CHECK_IF_NOT_INITED_WITH_LOG("Unable to destroy Screen",);

    GPU_Quit();
    free(mtrScreen);
    mtrLogWrite("Screen destroyed", 0, MTR_LMT_INFO);
}

/*fa mtrScreenFlip yes */
MTR_EXPORT void MTR_CALL mtrScreenFlip(void)
{
    MTR_SCREEN_CHECK_IF_NOT_INITED();

    GPU_Flip(mtrScreen->screen);
}

/*fa mtrScreenGetSizes yes */
MTR_EXPORT void MTR_CALL mtrScreenGetSizes(int *w, int *h)
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

/*fa mtrScreenGetWidth yes */
MTR_EXPORT int MTR_CALL mtrScreenGetWidth(void)
{
    uint16_t width;
    uint16_t height;
    MTR_SCREEN_CHECK_IF_NOT_INITED(0);

    GPU_GetVirtualResolution(mtrScreen->screen, &width, &height);
    return width;
}

/*fa mtrScreenGetHeight yes */
MTR_EXPORT int MTR_CALL mtrScreenGetHeight(void)
{
    uint16_t width;
    uint16_t height;
    MTR_SCREEN_CHECK_IF_NOT_INITED(0);

    GPU_GetVirtualResolution(mtrScreen->screen, &width, &height);
    return height;
}

/*fa mtrScreenXed yes */
MTR_EXPORT bool MTR_CALL mtrScreenXed(void)
{
    SDL_Event events[32];
    int       numEvents;
    MTR_SCREEN_CHECK_IF_NOT_INITED(false);

    numEvents = SDL_PeepEvents(events, 32, SDL_GETEVENT, SDL_QUIT, SDL_QUIT);

    if (numEvents == 0)
        return false;

    return true;
}

MTR_EXPORT mtrScreen_t *MTR_CALL mtrGetScreen(void)
{
    MTR_SCREEN_CHECK_IF_NOT_INITED(NULL);

    return mtrScreen;
}
