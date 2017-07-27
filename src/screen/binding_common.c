#ifndef MTR_SCREEN_BINDING_COMMON_C
#define MTR_SCREEN_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_B_I2B1S1(mtrSF_ScreenInit, mtrScreenInit)
MTR_SCRIPT_FUNC_V_V(mtrSF_ScreenQuit, mtrScreenQuit)
MTR_SCRIPT_FUNC_V_V(mtrSF_ScreenFlip, mtrScreenFlip)

void mtrScriptsRegisterAll(void)
{
    bool ok;
    ok = true;

    mtrVm = mtrScriptsGetVm();

    MTR_FIND_FUNCTION(mtrScreenInit, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrScreenQuit, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrScreenFlip, MTR_SOURCE_MODULE);

    if (ok)
    {
        mtrScriptsRegisterFunction(mtrSF_ScreenInit, "ScreenInit");
        mtrScriptsRegisterFunction(mtrSF_ScreenQuit, "ScreenQuit");
        mtrScriptsRegisterFunction(mtrSF_ScreenFlip, "ScreenFlip");
    }
    else
    {
        mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
    }
}

#endif
