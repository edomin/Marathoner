#ifndef MTR_TIMER_BINDING_COMMON_C
#define MTR_TIMER_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(mtrSF_TimerFunctionSupported, mtrTimerFunctionSupported)
MTR_SCRIPT_FUNC_B_V(mtrSF_TimerInit, mtrTimerInit)
MTR_SCRIPT_FUNC_V_V(mtrSF_TimerStart, mtrTimerStart)
MTR_SCRIPT_FUNC_I_I1(mtrSF_TimerDelay, mtrTimerDelay)
MTR_SCRIPT_FUNC_I_I1(mtrSF_TimerDelayForFPS, mtrTimerDelayForFPS)
MTR_SCRIPT_FUNC_F_F1(mtrSF_TimerDelayForFPS_f, mtrTimerDelayForFPS_f)

void mtrScriptsRegisterAll(void)
{
    bool ok;
    ok = true;

    mtrVm = mtrScriptsGetVm();

    MTR_FIND_FUNCTION(mtrTimerFunctionSupported, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTimerInit, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTimerStart, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTimerDelay, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTimerDelayForFPS, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTimerDelayForFPS_f, MTR_SOURCE_MODULE);

    if (ok)
    {
        mtrScriptsRegisterFunction(mtrSF_TimerFunctionSupported,
         "TimerFunctionSupported");
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
