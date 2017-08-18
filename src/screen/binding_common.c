#ifndef MTR_SCREEN_BINDING_COMMON_C
#define MTR_SCREEN_BINDING_COMMON_C

#include "marathoner/script_func.h"

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

void mtrScriptsRegisterAll(void)
{
    bool ok;
    ok = true;

    mtrVm = mtrScriptsGetVm();

    MTR_FIND_FUNCTION(mtrScreenInit, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrScreenQuit, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrScreenFlip, MTR_SOURCE_MODULE);
    #ifdef lua_h
    MTR_FIND_FUNCTION(mtrScreenGetSizes, MTR_SOURCE_MODULE);
    #endif
    MTR_FIND_FUNCTION(mtrScreenGetWidth, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrScreenGetHeight, MTR_SOURCE_MODULE);

    if (ok)
    {
        mtrScriptsRegisterFunction(mtrSF_ScreenInit, "ScreenInit");
        mtrScriptsRegisterFunction(mtrSF_ScreenQuit, "ScreenQuit");
        mtrScriptsRegisterFunction(mtrSF_ScreenFlip, "ScreenFlip");
        #ifdef lua_h
        mtrScriptsRegisterFunction(mtrSF_ScreenGetSizes, "ScreenGetSizes");
        #endif
        mtrScriptsRegisterFunction(mtrSF_ScreenGetWidth, "ScreenGetWidth");
        mtrScriptsRegisterFunction(mtrSF_ScreenGetHeight, "ScreenGetHeight");
    }
    else
    {
        mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
    }
}

#endif
