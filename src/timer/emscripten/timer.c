#include "timer.h"

#ifdef MTR_MOD_PLUGIN
#include "marathoner/plugin_common.c"

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Timer_Emscripten";
    report->version = MTR_VERSION_TIMER_EMSCRIPTEN;
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
    MTR_LogWrite("Initializing timer subsystem (dummy initialization)", 0,
     MTR_LMT_INFO);

    mtrTimerInited = true;
    return true;
}

/*fa MTR_TimerStart yes */
MTR_DCLSPC void MTR_CALL MTR_TimerStart(void)
{
    MTR_TIMER_CHECK_IF_NOT_INITED();

    mtrTimer.startTime = emscripten_get_now();
}

MTR_DCLSPC uint32_t MTR_CALL MTR_TimerGetTicks(void)
{
    return emscripten_get_now() - mtrTimer.startTime;
}

/*fa MTR_TimerDelay yes */
MTR_DCLSPC int MTR_CALL MTR_TimerDelay(int ms)
{
    MTR_TIMER_CHECK_IF_NOT_INITED(0);

    if (ms > 0)
        emscripten_sleep_with_yield(ms);
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
            emscripten_sleep_with_yield((1000 / fps) - MTR_TimerGetTicks());
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
            emscripten_sleep_with_yield((1000.0f / fps) - MTR_TimerGetTicks());
            return fps;
        }
        else
        {
            return 1000.0f / MTR_TimerGetTicks();
        }
    else
        return 1000.0f / MTR_TimerGetTicks();
}

