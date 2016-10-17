#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC(mtrSF_GameControllerInit)
{
    bool success;

    success = mtrGameControllerInit();

    MTR_SF_PUSH_BOOL(success);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GameControllerQuit)
{
    mtrGameControllerQuit();

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GameControllerRefresh)
{
    mtrGameControllerRefresh();

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GameControllerButtonPress)
{
    int  controllerNum;
    int  button;
    bool result;

    MTR_SF_GET_INT(controllerNum, 1);
    MTR_SF_GET_INT(button, 2);
    result = mtrGameControllerButtonPress(controllerNum, button);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GameControllerButtonRelease)
{
    int  controllerNum;
    int  button;
    bool result;

    MTR_SF_GET_INT(controllerNum, 1);
    MTR_SF_GET_INT(button, 2);
    result = mtrGameControllerButtonRelease(controllerNum, button);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GameControllerButtonPressed)
{
    int  controllerNum;
    int  button;
    bool result;

    MTR_SF_GET_INT(controllerNum, 1);
    MTR_SF_GET_INT(button, 2);
    result = mtrGameControllerButtonPressed(controllerNum, button);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GameControllerGetAxis)
{
    int     controllerNum;
    int     axis;
    int16_t result;

    MTR_SF_GET_INT(controllerNum, 1);
    MTR_SF_GET_INT(axis, 2);
    result = mtrGameControllerGetAxis(controllerNum, axis);

    MTR_SF_PUSH_INT(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GameControllerGetAxis_f)
{
    int     controllerNum;
    int     axis;
    float   result;

    MTR_SF_GET_INT(controllerNum, 1);
    MTR_SF_GET_INT(axis, 2);
    result = mtrGameControllerGetAxis_f(controllerNum, axis);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GameControllerGetAxisDelta)
{
    int controllerNum;
    int axis;
    int result;

    MTR_SF_GET_INT(controllerNum, 1);
    MTR_SF_GET_INT(axis, 2);
    result = mtrGameControllerGetAxisDelta(controllerNum, axis);

    MTR_SF_PUSH_INT(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GameControllerGetAxisDelta_f)
{
    int   controllerNum;
    int   axis;
    float result;

    MTR_SF_GET_INT(controllerNum, 1);
    MTR_SF_GET_INT(axis, 2);
    result = mtrGameControllerGetAxisDelta_f(controllerNum, axis);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GameControllerGetTrackballDeltaX)
{
    int controllerNum;
    int trackball;
    int result;

    MTR_SF_GET_INT(controllerNum, 1);
    MTR_SF_GET_INT(trackball, 2);
    result = mtrGameControllerGetTrackballDeltaX(controllerNum, trackball);

    MTR_SF_PUSH_INT(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GameControllerGetTrackballDeltaY)
{
    int controllerNum;
    int trackball;
    int result;

    MTR_SF_GET_INT(controllerNum, 1);
    MTR_SF_GET_INT(trackball, 2);
    result = mtrGameControllerGetTrackballDeltaY(controllerNum, trackball);

    MTR_SF_PUSH_INT(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GameControllerGetTrackballDeltaXY)
{
    int controllerNum;
    int trackball;
    int deltaX;
    int deltaY;

    MTR_SF_GET_INT(controllerNum, 1);
    MTR_SF_GET_INT(trackball, 2);
    mtrGameControllerGetTrackballDeltaXY(controllerNum,
     trackball, &deltaX, &deltaY);

    MTR_SF_PUSH_INT(deltaX);
    MTR_SF_PUSH_INT(deltaY);

    return 2;
}

MTR_SCRIPT_FUNC(mtrSF_GameControllerGetPovHat)
{
    int     controllerNum;
    int     povHat;
    uint8_t result;

    MTR_SF_GET_INT(controllerNum, 1);
    MTR_SF_GET_INT(povHat, 2);
    result = mtrGameControllerGetPovHat(controllerNum, povHat);

    MTR_SF_PUSH_INT(result);

    return 1;
}
