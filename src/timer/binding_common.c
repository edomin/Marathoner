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
    mtrVm = mtrScriptsGetVm();

    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TimerFunctionSupported);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TimerInit);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TimerStart);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TimerDelay);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TimerDelayForFPS);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TimerDelayForFPS_f);
}

#endif
