#include "timer.h"

#include "marathoner/plugin_common.c"

__declspec(dllexport) mtrReport* __stdcall mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Timer_SDL2";
    report->version = 0x000000;
    report->prereqsCount = 0;
    report->prereqs = NULL;
    return report;
}

__declspec(dllexport) bool __stdcall mtrTimerInit(void)
{
    SDL_version compiled;
    SDL_version linked;

    mtrLogWrite("Initializing timer subsystem", 0, MTR_LMT_INFO);

    mtrLogWrite("Reporting SDL compile-time version:", 1, MTR_LMT_INFO);
    SDL_VERSION(&compiled);
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, compiled.major);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, compiled.minor);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, compiled.patch);
    mtrLogWrite("Reporting SDL linked version:", 1, MTR_LMT_INFO);
    SDL_GetVersion(&linked);
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, linked.major);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, linked.minor);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, linked.patch);

    if(SDL_WasInit(SDL_INIT_TIMER) != 0)
        if (SDL_InitSubSystem(SDL_INIT_TIMER) == 0)
            mtrLogWrite("SDL timer subsystem initialized", 1, MTR_LMT_INFO);
        else
        {
             mtrNotify("Unable to initialize SDL timer subsystem", 1,
              MTR_LMT_ERROR);
              return false;
        }
    else
        mtrLogWrite("SDL timer subsystem already initialized", 1, MTR_LMT_INFO);
    mtrLogWrite("Timer subsystem initialized", 0, MTR_LMT_INFO);
    return true;
}

__declspec(dllexport) void __stdcall mtrTimerStart(void)
{
    mtrTimer.startTime = SDL_GetTicks();
}

__declspec(dllexport) uint32_t __stdcall mtrTimerGetTicks(void)
{
    return SDL_GetTicks() - mtrTimer.startTime;
}

__declspec(dllexport) uint32_t __stdcall mtrTimerDelay(uint32_t ms)
{
    if (ms > 0);
        SDL_Delay(ms);
    return 1000 / mtrTimerGetTicks();
}

__declspec(dllexport) uint32_t __stdcall mtrTimerDelayForFPS(uint32_t fps)
{
    if (fps > 0)
        if(mtrTimerGetTicks() < 1000 / fps)
        {
            /* Sleep the remaining frame time */
            SDL_Delay((1000 / fps) - mtrTimerGetTicks());
            return fps;
        }
        else
        {
            return 1000 / mtrTimerGetTicks();
        }
    else
        return 1000 / mtrTimerGetTicks();
}

__declspec(dllexport) float __stdcall mtrTimerDelayForFPS_f(float fps)
{
    if (fps > 0.0f)
        if(mtrTimerGetTicks() < 1000.0f / fps)
        {
            /* Sleep the remaining frame time */
            SDL_Delay((1000.0f / fps) - mtrTimerGetTicks());
            return fps;
        }
        else
        {
            return 1000.0f / mtrTimerGetTicks();
        }
    else
        return 1000.0f / mtrTimerGetTicks();
}
