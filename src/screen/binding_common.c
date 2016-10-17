#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC(mtrSF_ScreenInit)
{
    int w;
    int h;

    MTR_SF_GET_INT(w, 1);
    MTR_SF_GET_INT(h, 2);
    mtrScreenInit(w, h);

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
