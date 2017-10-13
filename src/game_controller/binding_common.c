#ifndef MTR_GAME_CONTROLLER_BINDING_COMMON_C
#define MTR_GAME_CONTROLLER_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(mtrSF_GameControllerFunctionSupported,
 mtrGameControllerFunctionSupported)
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

#ifdef lua_h
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
#endif

MTR_SCRIPT_FUNC_U8t_I2(mtrSF_GameControllerGetPovHat,
 mtrGameControllerGetPovHat)
MTR_SCRIPT_FUNC_I_I2(mtrSF_GameControllerGetPovHatHorizontal,
 mtrGameControllerGetPovHatHorizontal)
MTR_SCRIPT_FUNC_I_I2(mtrSF_GameControllerGetPovHatVertical,
 mtrGameControllerGetPovHatVertical)

#ifdef lua_h
MTR_SCRIPT_FUNC(mtrSF_GameControllerGetPovHatAxes)
{
    int controllerNum;
    int povHatNum;
    int horizontal;
    int vertical;

    MTR_SF_GET_INT(controllerNum, 1);
    MTR_SF_GET_INT(povHatNum, 2);
    mtrGameControllerGetPovHatAxes(controllerNum, povHatNum, &horizontal,
     &vertical);

    MTR_SF_PUSH_INT(horizontal);
    MTR_SF_PUSH_INT(vertical);

    return 2;
}
#endif

MTR_SCRIPT_FUNC_I_I1(mtrSF_GameControllerGetButtonsCount,
 mtrGameControllerGetButtonsCount)
MTR_SCRIPT_FUNC_I_I1(mtrSF_GameControllerGetAxesCount,
 mtrGameControllerGetAxesCount)
MTR_SCRIPT_FUNC_I_I1(mtrSF_GameControllerGetTrackballsCount,
 mtrGameControllerGetTrackballsCount)
MTR_SCRIPT_FUNC_I_I1(mtrSF_GameControllerGetPowHatsCount,
 mtrGameControllerGetPowHatsCount)

void mtrScriptsRegisterAll(void)
{
    mtrVm = mtrScriptsGetVm();

    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE,
     GameControllerFunctionSupported);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, GameControllerInit);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, GameControllerQuit);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, GameControllerRefresh);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, GameControllerButtonPress);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, GameControllerButtonRelease);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, GameControllerButtonPressed);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, GameControllerGetAxis);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, GameControllerGetAxis_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, GameControllerGetAxisDelta);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, GameControllerGetAxisDelta_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE,
     GameControllerGetTrackballDeltaX);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE,
     GameControllerGetTrackballDeltaY);
    #ifdef lua_h
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE,
     GameControllerGetTrackballDeltaXY);
    #endif
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, GameControllerGetPovHat);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE,
     GameControllerGetPovHatHorizontal);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE,
     GameControllerGetPovHatVertical);
    #ifdef lua_h
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, GameControllerGetPovHatAxes);
    #endif
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, GameControllerGetButtonsCount);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, GameControllerGetAxesCount);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE,
     GameControllerGetTrackballsCount);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, GameControllerGetPowHatsCount);

    mtrScriptsRegisterVariable_i("POVHAT_CENTER", MTR_POVHAT_CENTER);
    mtrScriptsRegisterVariable_i("POVHAT_UP", MTR_POVHAT_UP);
    mtrScriptsRegisterVariable_i("POVHAT_DOWN", MTR_POVHAT_DOWN);
    mtrScriptsRegisterVariable_i("POVHAT_LEFT", MTR_POVHAT_LEFT);
    mtrScriptsRegisterVariable_i("POVHAT_RIGHT", MTR_POVHAT_RIGHT);
    mtrScriptsRegisterVariable_i("POVHAT_UP_LEFT", MTR_POVHAT_UP_LEFT);
    mtrScriptsRegisterVariable_i("POVHAT_UP_RIGHT", MTR_POVHAT_UP_RIGHT);
    mtrScriptsRegisterVariable_i("POVHAT_DOWN_LEFT", MTR_POVHAT_DOWN_LEFT);
    mtrScriptsRegisterVariable_i("POVHAT_DOWN_RIGHT", MTR_POVHAT_DOWN_RIGHT);
}

#endif
