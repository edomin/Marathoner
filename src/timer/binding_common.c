#ifndef MTR_TIMER_BINDING_COMMON_C
#define MTR_TIMER_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC(mtrSF_TimerInit)
{
    bool success;

    success = mtrTimerInit();

    MTR_SF_PUSH_BOOL(success);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_TimerStart)
{
    mtrTimerStart();

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_TimerDelay)
{
    int ms;
    int fps;

    MTR_SF_GET_INT(ms, 1);
    fps = mtrTimerDelay(ms);

    MTR_SF_PUSH_INT(fps);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_TimerDelayForFPS)
{
    int fps;
    int resultFps;

    MTR_SF_GET_INT(fps, 1);
    resultFps = mtrTimerDelayForFPS(fps);

    MTR_SF_PUSH_INT(resultFps);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_TimerDelayForFPS_f)
{
    float fps;
    float resultFps;

    MTR_SF_GET_SINGLE(fps, 1);
    resultFps = mtrTimerDelayForFPS_f(fps);

    MTR_SF_PUSH_SINGLE(resultFps);

    return 1;
}

void mtrScriptsRegisterAll(void)
{
    bool ok;
    ok = true;

    mtrVm = mtrScriptsGetVm();

    MTR_FIND_FUNCTION(mtrTimerInit, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTimerStart, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTimerDelay, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTimerDelayForFPS, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTimerDelayForFPS_f, MTR_SOURCE_MODULE);

    if (ok)
    {
        mtrScriptsRegisterFunction(mtrSF_TimerInit, "TimerInit");
        mtrScriptsRegisterFunction(mtrSF_TimerStart, "TimerStart");
        mtrScriptsRegisterFunction(mtrSF_TimerDelay, "TimerDelay");
        mtrScriptsRegisterFunction(mtrSF_TimerDelayForFPS, "TimerDelayForFPS");
        mtrScriptsRegisterFunction(mtrSF_TimerDelayForFPS_f, "TimerDelayForFPS_f");
    }
    else
    {
        mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
    }
}

#endif
