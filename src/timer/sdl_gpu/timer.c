#include "timer.h"

#include "plugin_common.c"

__declspec(dllexport) mtrReport* __stdcall mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Timer_sdl_gpu";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    return report;
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
