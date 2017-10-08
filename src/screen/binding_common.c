#ifndef MTR_SCREEN_BINDING_COMMON_C
#define MTR_SCREEN_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(mtrSF_ScreenFunctionSupported, mtrScreenFunctionSupported)
MTR_SCRIPT_FUNC_B_I2B1S1(mtrSF_ScreenInit, mtrScreenInit)
MTR_SCRIPT_FUNC_V_V(mtrSF_ScreenQuit, mtrScreenQuit)
MTR_SCRIPT_FUNC_V_V(mtrSF_ScreenFlip, mtrScreenFlip)

#ifdef lua_h
MTR_SCRIPT_FUNC(mtrSF_ScreenGetSizes)
{
    int width;
    int height;
    mtrScreenGetSizes(&width, &height);
    MTR_SF_PUSH_INT(width);
    MTR_SF_PUSH_INT(height);
    return 2;
}
#endif

MTR_SCRIPT_FUNC_I_V(mtrSF_ScreenGetWidth, mtrScreenGetWidth)
MTR_SCRIPT_FUNC_I_V(mtrSF_ScreenGetHeight, mtrScreenGetHeight)
MTR_SCRIPT_FUNC_B_V(mtrSF_ScreenXed, mtrScreenXed)

void mtrScriptsRegisterAll(void)
{
    mtrVm = mtrScriptsGetVm();

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
