#ifndef MTR_PNG_BINDING_COMMON_C
#define MTR_PNG_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(MTR_SF_PngFunctionSupported, MTR_PngFunctionSupported)
MTR_SCRIPT_FUNC_V_V(MTR_SF_PngInit, MTR_PngInit)
MTR_SCRIPT_FUNC_P_S1(MTR_SF_PngLoadFast, MTR_PngLoadFast)
MTR_SCRIPT_FUNC_B_S1P1(MTR_SF_PngSaveFast, MTR_PngSaveFast)

void MTR_ScriptsRegisterAll(void)
{
    mtrVm = MTR_ScriptsGetVm();

    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PngFunctionSupported);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PngInit);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PngLoadFast);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PngSaveFast);
}

#endif
