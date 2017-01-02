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

void mtrScriptsRegisterAll(void)
{
    bool ok;
    ok = true;

    mtrVm = mtrScriptsGetVm();
    mtrGameControllerInit = (mtrGameControllerInitFunc)mtrFindFunction("Game_Controller_SDL2",
      "mtrGameControllerInit");
    if (mtrGameControllerInit == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrGameControllerInit");
        ok = false;
    }
    mtrGameControllerQuit = (mtrGameControllerQuitFunc)mtrFindFunction("Game_Controller_SDL2",
      "mtrGameControllerQuit");
    if (mtrGameControllerQuit == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrGameControllerQuit");
        ok = false;
    }
    mtrGameControllerRefresh = (mtrGameControllerRefreshFunc)mtrFindFunction("Game_Controller_SDL2",
      "mtrGameControllerRefresh");
    if (mtrGameControllerRefresh == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrGameControllerRefresh");
        ok = false;
    }
    mtrGameControllerButtonPress = (mtrGameControllerButtonPressFunc)mtrFindFunction("Game_Controller_SDL2",
      "mtrGameControllerButtonPress");
    if (mtrGameControllerButtonPress == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrGameControllerButtonPress");
        ok = false;
    }
    mtrGameControllerButtonRelease = (mtrGameControllerButtonReleaseFunc)mtrFindFunction("Game_Controller_SDL2",
      "mtrGameControllerButtonRelease");
    if (mtrGameControllerButtonRelease == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrGameControllerButtonRelease");
        ok = false;
    }
    mtrGameControllerButtonPressed = (mtrGameControllerButtonPressedFunc)mtrFindFunction("Game_Controller_SDL2",
      "mtrGameControllerButtonPressed");
    if (mtrGameControllerButtonPressed == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrGameControllerButtonPressed");
        ok = false;
    }
    mtrGameControllerGetAxis = (mtrGameControllerGetAxisFunc)mtrFindFunction("Game_Controller_SDL2",
      "mtrGameControllerGetAxis");
    if (mtrGameControllerGetAxis == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrGameControllerGetAxis");
        ok = false;
    }
    mtrGameControllerGetAxis_f = (mtrGameControllerGetAxis_fFunc)mtrFindFunction("Game_Controller_SDL2",
      "mtrGameControllerGetAxis_f");
    if (mtrGameControllerGetAxis_f == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrGameControllerGetAxis_f");
        ok = false;
    }
    mtrGameControllerGetAxisDelta = (mtrGameControllerGetAxisDeltaFunc)mtrFindFunction("Game_Controller_SDL2",
      "mtrGameControllerGetAxisDelta");
    if (mtrGameControllerGetAxisDelta == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrGameControllerGetAxisDelta");
        ok = false;
    }
    mtrGameControllerGetAxisDelta_f = (mtrGameControllerGetAxisDelta_fFunc)mtrFindFunction("Game_Controller_SDL2",
      "mtrGameControllerGetAxisDelta_f");
    if (mtrGameControllerGetAxisDelta_f == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrGameControllerGetAxisDelta_f");
        ok = false;
    }
    mtrGameControllerGetTrackballDeltaX = (mtrGameControllerGetTrackballDeltaXFunc)mtrFindFunction("Game_Controller_SDL2",
      "mtrGameControllerGetTrackballDeltaX");
    if (mtrGameControllerGetTrackballDeltaX == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrGameControllerGetTrackballDeltaX");
        ok = false;
    }
    mtrGameControllerGetTrackballDeltaY = (mtrGameControllerGetTrackballDeltaYFunc)mtrFindFunction("Game_Controller_SDL2",
      "mtrGameControllerGetTrackballDeltaY");
    if (mtrGameControllerGetTrackballDeltaY == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrGameControllerGetTrackballDeltaY");
        ok = false;
    }
    mtrGameControllerGetTrackballDeltaXY = (mtrGameControllerGetTrackballDeltaXYFunc)mtrFindFunction("Game_Controller_SDL2",
      "mtrGameControllerGetTrackballDeltaXY");
    if (mtrGameControllerGetTrackballDeltaXY == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrGameControllerGetTrackballDeltaXY");
        ok = false;
    }
    mtrGameControllerGetPovHat = (mtrGameControllerGetPovHatFunc)mtrFindFunction("Game_Controller_SDL2",
      "mtrGameControllerGetPovHat");
    if (mtrGameControllerGetPovHat == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrGameControllerGetPovHat");
        ok = false;
    }
    if (ok)
    {
        mtrScriptsRegisterNumericVariable("POVHAT_CENTER",
         MTR_POVHAT_CENTER);
        mtrScriptsRegisterNumericVariable("POVHAT_UP", MTR_POVHAT_UP);
        mtrScriptsRegisterNumericVariable("POVHAT_DOWN", MTR_POVHAT_DOWN);
        mtrScriptsRegisterNumericVariable("POVHAT_LEFT", MTR_POVHAT_LEFT);
        mtrScriptsRegisterNumericVariable("POVHAT_RIGHT", MTR_POVHAT_RIGHT);
        mtrScriptsRegisterNumericVariable("POVHAT_UP_LEFT",
         MTR_POVHAT_UP_LEFT);
        mtrScriptsRegisterNumericVariable("POVHAT_UP_RIGHT",
         MTR_POVHAT_UP_RIGHT);
        mtrScriptsRegisterNumericVariable("POVHAT_DOWN_LEFT",
         MTR_POVHAT_DOWN_LEFT);
        mtrScriptsRegisterNumericVariable("POVHAT_DOWN_RIGHT",
         MTR_POVHAT_DOWN_RIGHT);
        mtrScriptsRegisterFunction(mtrSF_GameControllerInit,
         "GameControllerInit");
        mtrScriptsRegisterFunction(mtrSF_GameControllerQuit,
         "GameControllerQuit");
        mtrScriptsRegisterFunction(mtrSF_GameControllerRefresh,
         "GameControllerRefresh");
        mtrScriptsRegisterFunction(mtrSF_GameControllerButtonPress,
         "GameControllerButtonPress");
        mtrScriptsRegisterFunction(mtrSF_GameControllerButtonRelease,
         "GameControllerButtonRelease");
        mtrScriptsRegisterFunction(mtrSF_GameControllerButtonPressed,
         "GameControllerButtonPressed");
        mtrScriptsRegisterFunction(mtrSF_GameControllerGetAxis,
         "GameControllerGetAxis");
        mtrScriptsRegisterFunction(mtrSF_GameControllerGetAxis_f,
         "GameControllerGetAxis_f");
        mtrScriptsRegisterFunction(mtrSF_GameControllerGetAxisDelta,
         "GameControllerGetAxisDelta");
        mtrScriptsRegisterFunction(mtrSF_GameControllerGetAxisDelta_f,
         "GameControllerGetAxisDelta_f");
        mtrScriptsRegisterFunction(mtrSF_GameControllerGetTrackballDeltaX,
         "GameControllerGetTrackballDeltaX");
        mtrScriptsRegisterFunction(mtrSF_GameControllerGetTrackballDeltaY,
         "GameControllerGetTrackballDeltaY");
        mtrScriptsRegisterFunction(mtrSF_GameControllerGetTrackballDeltaXY,
         "GameControllerGetTrackballDeltaXY");
        mtrScriptsRegisterFunction(mtrSF_GameControllerGetPovHat,
         "GameControllerGetPovHat");
    }
    else
    {
        mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
    }
}
