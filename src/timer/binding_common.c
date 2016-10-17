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
