#include "marathoner/script_func.h"

int mtrSF_GameControllerInit(lua_State* l)
{
    bool success;

    success = mtrGameControllerInit();

    MTR_SF_PUSH_BOOL(success);

    return 1;
}

int mtrSF_GameControllerQuit(lua_State* l)
{
    mtrGameControllerQuit();

    return 0;
}

int mtrSF_GameControllerRefresh(lua_State* l)
{
    mtrGameControllerRefresh();

    return 0;
}

int mtrSF_GameControllerButtonPress(lua_State* l)
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

int mtrSF_GameControllerButtonRelease(lua_State* l)
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

int mtrSF_GameControllerButtonPressed(lua_State* l)
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

int mtrSF_GameControllerGetAxis(lua_State* l)
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

int mtrSF_GameControllerGetAxis_f(lua_State* l)
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

int mtrSF_GameControllerGetAxisDelta(lua_State* l)
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

int mtrSF_GameControllerGetAxisDelta_f(lua_State* l)
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

int mtrSF_GameControllerGetTrackballDeltaX(lua_State* l)
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

int mtrSF_GameControllerGetTrackballDeltaY(lua_State* l)
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

int mtrSF_GameControllerGetTrackballDeltaXY(lua_State* l)
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

int mtrSF_GameControllerGetPovHat(lua_State* l)
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
