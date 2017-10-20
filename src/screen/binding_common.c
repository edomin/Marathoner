#ifndef MTR_SCREEN_BINDING_COMMON_C
#define MTR_SCREEN_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(MTR_SF_ScreenFunctionSupported,
 MTR_ScreenFunctionSupported)
MTR_SCRIPT_FUNC_B_I2B1S1(MTR_SF_ScreenInit, MTR_ScreenInit)
MTR_SCRIPT_FUNC_V_V(MTR_SF_ScreenQuit, MTR_ScreenQuit)
MTR_SCRIPT_FUNC_V_V(MTR_SF_ScreenFlip, MTR_ScreenFlip)

#ifdef lua_h
MTR_SCRIPT_FUNC(MTR_SF_ScreenGetSizes)
{
    int width;
    int height;
    MTR_ScreenGetSizes(&width, &height);
    MTR_SF_PUSH_INT(width);
    MTR_SF_PUSH_INT(height);
    return 2;
}
#endif

MTR_SCRIPT_FUNC_I_V(MTR_SF_ScreenGetWidth, MTR_ScreenGetWidth)
MTR_SCRIPT_FUNC_I_V(MTR_SF_ScreenGetHeight, MTR_ScreenGetHeight)
MTR_SCRIPT_FUNC_B_V(MTR_SF_ScreenXed, MTR_ScreenXed)

void MTR_ScriptsRegisterAll(void)
{
    mtrVm = MTR_ScriptsGetVm();

    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, ScreenFunctionSupported);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, ScreenInit);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, ScreenQuit);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, ScreenFlip);
    #ifdef lua_h
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, ScreenGetSizes);
    #endif
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, ScreenGetWidth);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, ScreenGetHeight);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, ScreenXed);
}

#endif
