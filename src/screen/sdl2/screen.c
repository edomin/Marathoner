#include "screen.h"

#include "marathoner/plugin_common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Screen, FA_FUNCTIONS_COUNT)

MTR_EXPORT mtrReport* MTR_CALL MTR_CreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Screen_SDL2";
    report->version = MTR_VERSION_SCREEN_SDL2;
    report->subsystem = "screen";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}

/*fa MTR_ScreenInit yes */
MTR_EXPORT bool MTR_CALL MTR_ScreenInit(int width, int height, bool fullscreen,
 const char *title)
{
    SDL_version         compiled;
    SDL_version         sdlLinked;
    int                 modesNum;
    int                 i;
    SDL_DisplayMode     mode;
    SDL_RendererInfo    rendererInfo;
    const char         *actualTitle;
    const char          defaultTitle[] = "Marathoner";
    int                 fullscreenFlag;

    MTR_LogWrite("Creating Screen", 0, MTR_LMT_INFO);

    MTR_LogWrite("Reporting SDL compile-time version:", 1, MTR_LMT_INFO);
    SDL_VERSION(&compiled);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, compiled.major);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, compiled.minor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, compiled.patch);
    MTR_LogWrite("Reporting SDL linked version:", 1, MTR_LMT_INFO);
    SDL_GetVersion(&sdlLinked);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, sdlLinked.major);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, sdlLinked.minor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, sdlLinked.patch);

    mtrScreen = malloc(sizeof(mtrScreen_t));
    if (mtrScreen == NULL)
    {
        MTR_Notify("Unable to allocate memory for mtrScreen structure", 1,
         MTR_LMT_ERROR);
        return false;
    }

    if(SDL_WasInit(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == 0)
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == 0)
            MTR_LogWrite(
             "SDL library with video and events subsystems initialized", 1,
              MTR_LMT_INFO);
        else
        {
            MTR_Notify(
             "Unable to initialize SDL library with video and events "
             "subsystems", 1, MTR_LMT_ERROR);
            free(mtrScreen);
            MTR_Notify("Screen not initialized", 0, MTR_LMT_ERROR);
            return false;
        }
    else
        MTR_LogWrite(
         "SDL library with video and events subsystems already initialized", 1,
         MTR_LMT_INFO);

    MTR_LogWrite("Reporting available display modes", 1, MTR_LMT_INFO);
    modesNum = SDL_GetNumDisplayModes(0);
    if (modesNum < 0)
    {
        MTR_LogWrite("Unable to check available display modes", 1,
         MTR_LMT_WARNING);
        MTR_LogWrite(SDL_GetError(), 1, MTR_LMT_WARNING);
    }
    else
    {
        MTR_LogWrite_i("Modes found:", 1, MTR_LMT_INFO, modesNum);
        for (i = 0; i < modesNum; i++)
        {
            if (SDL_GetDisplayMode(0, i, &mode) == 0)
            {
                MTR_LogWrite_i("No.", 1, MTR_LMT_INFO, i);
                MTR_LogWrite_i("Width:", 2, MTR_LMT_INFO, mode.w);
                MTR_LogWrite_i("Height:", 2, MTR_LMT_INFO, mode.h);
                MTR_LogWrite_s("Pixel Format:", 2, MTR_LMT_INFO,
                 SDL_GetPixelFormatName(mode.format));
                MTR_LogWrite_i("Refresh Rate (Hz):", 2, MTR_LMT_INFO,
                 mode.refresh_rate);
            }
            else
            {
                MTR_LogWrite_i("Unable to get info of dosplay mode", 1,
                 MTR_LMT_WARNING, i);
                MTR_LogWrite(SDL_GetError(), 1, MTR_LMT_WARNING);
            }
        }
    }

    if (title == NULL)
        actualTitle = defaultTitle;
    else
        actualTitle = title;
    if (fullscreen)
        fullscreenFlag = SDL_WINDOW_FULLSCREEN;
    else
        fullscreenFlag = 0;
    mtrScreen->screen = SDL_CreateWindow(actualTitle, SDL_WINDOWPOS_UNDEFINED,
     SDL_WINDOWPOS_UNDEFINED, width, height,
     SDL_WINDOW_OPENGL | fullscreenFlag);

    if (mtrScreen->screen != NULL)
        MTR_LogWrite("Window created", 1, MTR_LMT_INFO);
    else
    {
        MTR_Notify("Unable to create window", 1, MTR_LMT_ERROR);
        free(mtrScreen);
        MTR_Notify("Screen not initialized", 0, MTR_LMT_ERROR);
        return false;
    }

    MTR_LogWrite("Checking available renderers", 1, MTR_LMT_INFO);
    MTR_LogWrite_i("Drivers found:", 1, MTR_LMT_INFO,
     SDL_GetNumRenderDrivers());
    i = 0;
    while (SDL_GetRenderDriverInfo(i, &rendererInfo) == 0)
    {
        MTR_LogWrite_i("No.", 1, MTR_LMT_INFO, i);
        MTR_LogWrite_s("Renderer name:", 2, MTR_LMT_INFO, rendererInfo.name);
        MTR_LogWrite("Supported renderer flags", 2, MTR_LMT_INFO);
        if ((rendererInfo.flags | SDL_RENDERER_SOFTWARE) == rendererInfo.flags)
            MTR_LogWrite("SDL_RENDERER_SOFTWARE", 3, MTR_LMT_INFO);
        if ((rendererInfo.flags | SDL_RENDERER_ACCELERATED) ==
         rendererInfo.flags)
            MTR_LogWrite("SDL_RENDERER_ACCELERATED", 3, MTR_LMT_INFO);
        if ((rendererInfo.flags | SDL_RENDERER_PRESENTVSYNC) ==
         rendererInfo.flags)
            MTR_LogWrite("SDL_RENDERER_PRESENTVSYNC", 3, MTR_LMT_INFO);
        if ((rendererInfo.flags | SDL_RENDERER_TARGETTEXTURE) ==
         rendererInfo.flags)
            MTR_LogWrite("SDL_RENDERER_TARGETTEXTURE", 3, MTR_LMT_INFO);
        MTR_LogWrite_i("Maximum texture width:", 2, MTR_LMT_INFO,
         rendererInfo.max_texture_width);
        MTR_LogWrite_i("Maximum texture height:", 2, MTR_LMT_INFO,
         rendererInfo.max_texture_height);
        i++;
    }

    #ifdef __MINGW32__
    SDL_GetRenderDriverInfo(0, &rendererInfo);
    if ((rendererInfo.flags | SDL_RENDERER_ACCELERATED) == rendererInfo.flags)
        mtrScreen->renderer = SDL_CreateRenderer(mtrScreen->screen, 0,
         SDL_RENDERER_ACCELERATED);
    else
        mtrScreen->renderer = SDL_CreateRenderer(mtrScreen->screen, 0,
         SDL_RENDERER_SOFTWARE);
    #else
    SDL_GetRenderDriverInfo(1, &rendererInfo);
    mtrScreen->renderer = SDL_CreateRenderer(mtrScreen->screen, 1,
     SDL_RENDERER_SOFTWARE);
    #endif
    if (mtrScreen->renderer != NULL)
    {
        SDL_GetRenderDriverInfo(1, &rendererInfo);
        MTR_LogWrite_s("Renderer initialized:", 1, MTR_LMT_INFO,
         rendererInfo.name);
    }
    else
    {
        MTR_Notify("Unable to initialize renderer", 1, MTR_LMT_ERROR);
        SDL_DestroyWindow(mtrScreen->screen);
        free(mtrScreen);
        MTR_Notify("Screen not initialized", 0, MTR_LMT_ERROR);
        return false;
    }
    MTR_LogWrite("Screen initialized", 0, MTR_LMT_INFO);

    mtrScreenInited = true;
    return true;
}

/*fa MTR_ScreenQuit yes */
MTR_EXPORT void MTR_CALL MTR_ScreenQuit(void)
{
    MTR_SCREEN_CHECK_IF_NOT_INITED_WITH_LOG("Unable to destroy Screen",);

    SDL_DestroyRenderer(mtrScreen->renderer);
    SDL_DestroyWindow(mtrScreen->screen);
    free(mtrScreen);
    MTR_LogWrite("Screen destroyed", 0, MTR_LMT_INFO);
}

/*fa MTR_ScreenFlip yes */
MTR_EXPORT void MTR_CALL MTR_ScreenFlip(void)
{
    MTR_SCREEN_CHECK_IF_NOT_INITED();

    SDL_RenderPresent(mtrScreen->renderer);
}

/*fa MTR_ScreenGetSizes yes */
MTR_EXPORT void MTR_CALL MTR_ScreenGetSizes(int *w, int *h)
{
    int width;
    int height;

    if (!mtrScreenInited)
    {
        *w = 0;
        *h = 0;
        return;
    }

    SDL_GetRendererOutputSize(mtrScreen->renderer, &width, &height);
    if (w != NULL)
        *w = width;
    if (h != NULL)
        *h = height;
}

/*fa MTR_ScreenGetWidth yes */
MTR_EXPORT int MTR_CALL MTR_ScreenGetWidth(void)
{
    int width;
    int height;
    MTR_SCREEN_CHECK_IF_NOT_INITED(0);

    SDL_GetRendererOutputSize(mtrScreen->renderer, &width, &height);
    return width;
}

/*fa MTR_ScreenGetHeight yes */
MTR_EXPORT int MTR_CALL MTR_ScreenGetHeight(void)
{
    int width;
    int height;
    MTR_SCREEN_CHECK_IF_NOT_INITED(0);

    SDL_GetRendererOutputSize(mtrScreen->renderer, &width, &height);
    return height;
}

/*fa MTR_ScreenXed yes */
MTR_EXPORT bool MTR_CALL MTR_ScreenXed(void)
{
    SDL_Event events[32];
    int       numEvents;
    MTR_SCREEN_CHECK_IF_NOT_INITED(false);

    numEvents = SDL_PeepEvents(events, 32, SDL_GETEVENT, SDL_QUIT, SDL_QUIT);

    if (numEvents == 0)
        return false;

    return true;
}

MTR_EXPORT mtrScreen_t *MTR_CALL MTR_GetScreen(void)
{
    MTR_SCREEN_CHECK_IF_NOT_INITED(NULL);

    return mtrScreen;
}
