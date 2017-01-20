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
    mtrScreenInit = (mtrScreenInitFunc)mtrFindFunction("Screen_SDL2_gpu",
     "mtrScreenInit");
    if (mtrScreenInit == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
         "mtrScreenInit");
        ok = false;
    }
    mtrScreenQuit = (mtrScreenQuitFunc)mtrFindFunction("Screen_SDL2_gpu",
     "mtrScreenQuit");
    if (mtrScreenQuit == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
         "mtrScreenQuit");
        ok = false;
    }
    mtrScreenFlip = (mtrScreenFlipFunc)mtrFindFunction("Screen_SDL2_gpu",
     "mtrScreenFlip");
    if (mtrScreenFlip == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
         "mtrScreenFlip");
        ok = false;
    }
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
