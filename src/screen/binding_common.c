#ifndef MTR_SCREEN_BINDING_COMMON_C
#define MTR_SCREEN_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC(mtrSF_ScreenInit)
{
    int w;
    int h;
    bool result;

    MTR_SF_GET_INT(w, 1);
    MTR_SF_GET_INT(h, 2);
    result = mtrScreenInit(w, h);

    MTR_SF_PUSH_BOOL(result);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_ScreenQuit)
{
    mtrScreenQuit();

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_ScreenFlip)
{
    mtrScreenFlip();

    return 0;

}

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
