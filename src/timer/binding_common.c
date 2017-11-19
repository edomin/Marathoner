#ifndef MTR_TIMER_BINDING_COMMON_C
#define MTR_TIMER_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(MTR_SF_TimerFunctionSupported, MTR_TimerFunctionSupported)
MTR_SCRIPT_FUNC_B_V(MTR_SF_TimerInit, MTR_TimerInit)
MTR_SCRIPT_FUNC_V_V(MTR_SF_TimerStart, MTR_TimerStart)
MTR_SCRIPT_FUNC_I_I1(MTR_SF_TimerDelay, MTR_TimerDelay)
MTR_SCRIPT_FUNC_I_I1(MTR_SF_TimerDelayForFPS, MTR_TimerDelayForFPS)
MTR_SCRIPT_FUNC_F_F1(MTR_SF_TimerDelayForFPS_f, MTR_TimerDelayForFPS_f)

void MTR_ScriptsRegisterAll(void)
{
    #ifdef MTR_MOD_PLUGIN
    mtrVm = MTR_ScriptsGetVm();
    #endif

    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TimerFunctionSupported);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TimerInit);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TimerStart);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TimerDelay);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TimerDelayForFPS);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TimerDelayForFPS_f);
}

#endif
