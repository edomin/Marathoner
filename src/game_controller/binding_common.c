#ifndef MTR_GAME_CONTROLLER_BINDING_COMMON_C
#define MTR_GAME_CONTROLLER_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_B_V(mtrSF_GameControllerInit, mtrGameControllerInit)
MTR_SCRIPT_FUNC_V_V(mtrSF_GameControllerQuit, mtrGameControllerQuit)
MTR_SCRIPT_FUNC_V_V(mtrSF_GameControllerRefresh, mtrGameControllerRefresh)
MTR_SCRIPT_FUNC_B_I2(mtrSF_GameControllerButtonPress,
 mtrGameControllerButtonPress)
MTR_SCRIPT_FUNC_B_I2(mtrSF_GameControllerButtonRelease,
 mtrGameControllerButtonRelease)
MTR_SCRIPT_FUNC_B_I2(mtrSF_GameControllerButtonPressed,
 mtrGameControllerButtonPressed)
MTR_SCRIPT_FUNC_S16t_I2(mtrSF_GameControllerGetAxis, mtrGameControllerGetAxis)
MTR_SCRIPT_FUNC_F_I2(mtrSF_GameControllerGetAxis_f, mtrGameControllerGetAxis_f)
MTR_SCRIPT_FUNC_I_I2(mtrSF_GameControllerGetAxisDelta,
 mtrGameControllerGetAxisDelta)
MTR_SCRIPT_FUNC_F_I2(mtrSF_GameControllerGetAxisDelta_f,
 mtrGameControllerGetAxisDelta_f)
MTR_SCRIPT_FUNC_I_I2(mtrSF_GameControllerGetTrackballDeltaX,
 mtrGameControllerGetTrackballDeltaX)
MTR_SCRIPT_FUNC_I_I2(mtrSF_GameControllerGetTrackballDeltaY,
 mtrGameControllerGetTrackballDeltaY)

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

MTR_SCRIPT_FUNC_U8t_I2(mtrSF_GameControllerGetPovHat,
 mtrGameControllerGetPovHat)

void mtrScriptsRegisterAll(void)
{
    bool ok;
    ok = true;

    mtrVm = mtrScriptsGetVm();

    MTR_FIND_FUNCTION(mtrGameControllerInit, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrGameControllerQuit, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrGameControllerRefresh, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrGameControllerButtonPress, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrGameControllerButtonRelease, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrGameControllerButtonPressed, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrGameControllerGetAxis, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrGameControllerGetAxis_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrGameControllerGetAxisDelta, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrGameControllerGetAxisDelta_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrGameControllerGetTrackballDeltaX, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrGameControllerGetTrackballDeltaY, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrGameControllerGetTrackballDeltaXY, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrGameControllerGetPovHat, MTR_SOURCE_MODULE);

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

#endif
