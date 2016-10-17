#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC(mtrSF_MouseInit)
{
    bool success;

    success = mtrMouseInit();

    MTR_SF_PUSH_BOOL(success);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_MouseRefresh)
{
    mtrMouseRefresh();

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_MousePress)
{
    int  button;
    bool result;

    MTR_SF_GET_INT(button, 1);
    result = mtrMousePress(button);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_MouseRelease)
{
    int  button;
    bool result;

    MTR_SF_GET_INT(button, 1);
    result = mtrMouseRelease(button);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_MousePressed)
{
    int  button;
    bool result;

    MTR_SF_GET_INT(button, 1);
    result = mtrMousePressed(button);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_MouseGetWheelRelative)
{
    int result;

    result = mtrMouseGetWheelRelative();

    MTR_SF_PUSH_INT(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_MouseGetX)
{
    int x;

    x = mtrMouseGetX();

    MTR_SF_PUSH_INT(x);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_MouseGetY)
{
    int y;

    y = mtrMouseGetY();

    MTR_SF_PUSH_INT(y);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_MouseGetXY)
{
    int x;
    int y;

    mtrMouseGetXY(&x, &y);

    MTR_SF_PUSH_INT(x);
    MTR_SF_PUSH_INT(y);

    return 2;
}

MTR_SCRIPT_FUNC(mtrSF_MouseGetDeltaX)
{
    int deltaX;

    deltaX = mtrMouseGetDeltaX();

    MTR_SF_PUSH_INT(deltaX);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_MouseGetDeltaY)
{
    int deltaY;

    deltaY = mtrMouseGetDeltaY();

    MTR_SF_PUSH_INT(deltaY);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_MouseGetDeltaXY)
{
    int deltaX;
    int deltaY;

    mtrMouseGetDeltaXY(&deltaX, &deltaY);

    MTR_SF_PUSH_INT(deltaX);
    MTR_SF_PUSH_INT(deltaY);

    return 2;
}
