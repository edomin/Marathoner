#include "screen.h"

#include "marathoner/plugin_common.c"

MRT_EXPORT mtrReport* MRT_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Screen_SDL2";
    report->version = MTR_VERSION_SCREEN_SDL2;
    report->prereqsCount = 0;
    report->prereqs = NULL;
    return report;
}

MRT_EXPORT void MRT_CALL mtrScreenInit(uint16_t width,
 uint16_t height)
{
    SDL_version         compiled;
    SDL_version         sdlLinked;
    int                 modesNum;
    int                 i;
    SDL_DisplayMode     mode;
    SDL_RendererInfo    rendererInfo;

    mtrLogWrite("Creating Screen", 0, MTR_LMT_INFO);

    mtrLogWrite("Reporting SDL compile-time version:", 1, MTR_LMT_INFO);
    SDL_VERSION(&compiled);
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, compiled.major);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, compiled.minor);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, compiled.patch);
    mtrLogWrite("Reporting SDL linked version:", 1, MTR_LMT_INFO);
    SDL_GetVersion(&sdlLinked);
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, sdlLinked.major);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, sdlLinked.minor);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, sdlLinked.patch);

    mtrScreen = malloc(sizeof(mtrScreen_t));
    if (mtrScreen == NULL)
        mtrNotify("Unable to allocate memory for mtrScreen structure", 1,
         MTR_LMT_ERROR);

    if(SDL_WasInit(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == 0)
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == 0)
            mtrLogWrite("SDL library with video and events subsystems initialized",
             1, MTR_LMT_INFO);
        else
        {
            mtrNotify("Unable to initialize SDL library with video and events subsystems",
             1, MTR_LMT_ERROR);
            free(mtrScreen);
            mtrNotify("Screen not initialized", 0, MTR_LMT_ERROR);
            return;
        }
    else
        mtrLogWrite("SDL library with video and events subsystems already initialized",
         1, MTR_LMT_INFO);

    mtrLogWrite("Reporting available display modes", 1, MTR_LMT_INFO);
    modesNum = SDL_GetNumDisplayModes(0);
    if (modesNum < 0)
    {
        mtrLogWrite("Unable to check available display modes", 1,
         MTR_LMT_WARNING);
        mtrLogWrite(SDL_GetError(), 1, MTR_LMT_WARNING);
    }
    else
    {
        mtrLogWrite_i("Modes found:", 1, MTR_LMT_INFO, modesNum);
        for (i = 0; i < modesNum; i++)
        {
            if (SDL_GetDisplayMode(0, i, &mode) == 0)
            {
                mtrLogWrite_i("No.", 1, MTR_LMT_INFO, i);
                mtrLogWrite_i("Width:", 2, MTR_LMT_INFO, mode.w);
                mtrLogWrite_i("Height:", 2, MTR_LMT_INFO, mode.h);
                mtrLogWrite_s("Pixel Format:", 2, MTR_LMT_INFO,
                 SDL_GetPixelFormatName(mode.format));
                mtrLogWrite_i("Refresh Rate (Hz):", 2, MTR_LMT_INFO, mode.refresh_rate);
            }
            else
            {
                mtrLogWrite_i("Unable to get info of dosplay mode", 1,
                 MTR_LMT_WARNING, i);
                mtrLogWrite(SDL_GetError(), 1, MTR_LMT_WARNING);
            }
        }
    }

    /* Copypasted from Run and Jump
    if (!fullscreen)
        Screen.window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
                                         SDL_WINDOWPOS_UNDEFINED, w, h,
                                         SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN);
    */
    mtrScreen->screen = SDL_CreateWindow("Marathoner", SDL_WINDOWPOS_UNDEFINED,
     SDL_WINDOWPOS_UNDEFINED, width, height,
     SDL_WINDOW_OPENGL);

    if (mtrScreen->screen != NULL)
        mtrLogWrite("Window created", 1, MTR_LMT_INFO);
    else
    {
        mtrNotify("Unable to create window", 1, MTR_LMT_ERROR);
        free(mtrScreen);
        mtrNotify("Screen not initialized", 0, MTR_LMT_ERROR);
        return;
    }

    mtrLogWrite("Checking available renderers", 1, MTR_LMT_INFO);
    mtrLogWrite_i("Drivers found:", 1, MTR_LMT_INFO, SDL_GetNumRenderDrivers());
    i = 0;
    while (SDL_GetRenderDriverInfo(i, &rendererInfo) == 0)
    {
        mtrLogWrite_i("No.", 1, MTR_LMT_INFO, i);
        mtrLogWrite_s("Renderer name:", 2, MTR_LMT_INFO, rendererInfo.name);
        mtrLogWrite("Supported renderer flags", 2, MTR_LMT_INFO);
        if ((rendererInfo.flags | SDL_RENDERER_SOFTWARE) == rendererInfo.flags)
            mtrLogWrite("SDL_RENDERER_SOFTWARE", 3, MTR_LMT_INFO);
        if ((rendererInfo.flags | SDL_RENDERER_ACCELERATED) == rendererInfo.flags)
            mtrLogWrite("SDL_RENDERER_ACCELERATED", 3, MTR_LMT_INFO);
        if ((rendererInfo.flags | SDL_RENDERER_PRESENTVSYNC) == rendererInfo.flags)
            mtrLogWrite("SDL_RENDERER_PRESENTVSYNC", 3, MTR_LMT_INFO);
        if ((rendererInfo.flags | SDL_RENDERER_TARGETTEXTURE) == rendererInfo.flags)
            mtrLogWrite("SDL_RENDERER_TARGETTEXTURE", 3, MTR_LMT_INFO);
        mtrLogWrite_i("Maximum texture width:", 2, MTR_LMT_INFO,
         rendererInfo.max_texture_width);
        mtrLogWrite_i("Maximum texture height:", 2, MTR_LMT_INFO,
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
    //mtrScreen->renderer = SDL_CreateRenderer(mtrScreen->screen, -1, 0);
    SDL_GetRenderDriverInfo(1, &rendererInfo);
    mtrScreen->renderer = SDL_CreateRenderer(mtrScreen->screen, 1, SDL_RENDERER_SOFTWARE);
    #endif
    if (mtrScreen->renderer != NULL)
    {
        SDL_GetRenderDriverInfo(1, &rendererInfo);
        mtrLogWrite_s("Renderer initialized:", 1, MTR_LMT_INFO,
         rendererInfo.name);
    }
    else
    {
        mtrNotify("Unable to initialize renderer", 1, MTR_LMT_ERROR);
        SDL_DestroyWindow(mtrScreen->screen);
        free(mtrScreen);
        mtrNotify("Screen not initialized", 0, MTR_LMT_ERROR);
        return;
    }
    mtrLogWrite("Screen initialized", 0, MTR_LMT_INFO);
}

MRT_EXPORT void MRT_CALL mtrScreenQuit(void)
{
    SDL_DestroyRenderer(mtrScreen->renderer);
    SDL_DestroyWindow(mtrScreen->screen);
    free(mtrScreen);
    mtrLogWrite("Screen destroyed", 0, MTR_LMT_INFO);
}

MRT_EXPORT void MRT_CALL mtrScreenFlip(void)
{
    SDL_RenderPresent(mtrScreen->renderer);
}

MRT_EXPORT mtrScreen_t *MRT_CALL mtrGetScreen(void)
{
    return mtrScreen;
}
