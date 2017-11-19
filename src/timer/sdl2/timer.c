#include "timer.h"

#ifdef MTR_MOD_PLUGIN
#include "marathoner/plugin_common.c"

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Timer_SDL2";
    report->version = MTR_VERSION_TIMER_SDL2;
    report->subsystem = "timer";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}
#endif

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Timer, FA_FUNCTIONS_COUNT)

/*fa MTR_TimerInit yes */
MTR_DCLSPC bool MTR_CALL MTR_TimerInit(void)
{
    SDL_version compiled;
    SDL_version linked;

    MTR_LogWrite("Initializing timer subsystem", 0, MTR_LMT_INFO);

    MTR_LogWrite("Reporting SDL compile-time version:", 1, MTR_LMT_INFO);
    SDL_VERSION(&compiled);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, compiled.major);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, compiled.minor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, compiled.patch);
    MTR_LogWrite("Reporting SDL linked version:", 1, MTR_LMT_INFO);
    SDL_GetVersion(&linked);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, linked.major);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, linked.minor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, linked.patch);

    if(SDL_WasInit(SDL_INIT_TIMER) != 0)
        if (SDL_InitSubSystem(SDL_INIT_TIMER) == 0)
            MTR_LogWrite("SDL timer subsystem initialized", 1, MTR_LMT_INFO);
        else
        {
             MTR_Notify("Unable to initialize SDL timer subsystem", 1,
              MTR_LMT_ERROR);
              return false;
        }
    else
        MTR_LogWrite("SDL timer subsystem already initialized", 1, MTR_LMT_INFO);
    MTR_LogWrite("Timer subsystem initialized", 0, MTR_LMT_INFO);

    mtrTimerInited = true;
    return true;
}

/*fa MTR_TimerStart yes */
MTR_DCLSPC void MTR_CALL MTR_TimerStart(void)
{
    MTR_TIMER_CHECK_IF_NOT_INITED();

    mtrTimer.startTime = SDL_GetTicks();
}

MTR_DCLSPC uint32_t MTR_CALL MTR_TimerGetTicks(void)
{
    return SDL_GetTicks() - mtrTimer.startTime;
}

/*fa MTR_TimerDelay yes */
MTR_DCLSPC int MTR_CALL MTR_TimerDelay(int ms)
{
    MTR_TIMER_CHECK_IF_NOT_INITED(0);

    if (ms > 0)
        SDL_Delay(ms);
    return 1000 / MTR_TimerGetTicks();
}

/*fa MTR_TimerDelayForFPS yes */
MTR_DCLSPC int MTR_CALL MTR_TimerDelayForFPS(int fps)
{
    MTR_TIMER_CHECK_IF_NOT_INITED(0);

    if (fps > 0)
        if(MTR_TimerGetTicks() < 1000U / fps)
        {
            /* Sleep the remaining frame time */
            SDL_Delay((1000 / fps) - MTR_TimerGetTicks());
            return fps;
        }
        else
        {
            return 1000 / MTR_TimerGetTicks();
        }
    else
        return 1000 / MTR_TimerGetTicks();
}

/*fa MTR_TimerDelayForFPS_f yes */
MTR_DCLSPC float MTR_CALL MTR_TimerDelayForFPS_f(float fps)
{
    MTR_TIMER_CHECK_IF_NOT_INITED(0.0f);

    if (fps > 0.0f)
        if(MTR_TimerGetTicks() < 1000.0f / fps)
        {
            /* Sleep the remaining frame time */
            SDL_Delay((1000.0f / fps) - MTR_TimerGetTicks());
            return fps;
        }
        else
        {
            return 1000.0f / MTR_TimerGetTicks();
        }
    else
        return 1000.0f / MTR_TimerGetTicks();
}
