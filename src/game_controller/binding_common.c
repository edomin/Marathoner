#ifndef MTR_GAME_CONTROLLER_BINDING_COMMON_C
#define MTR_GAME_CONTROLLER_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(MTR_SF_GameControllerFunctionSupported,
 MTR_GameControllerFunctionSupported)
MTR_SCRIPT_FUNC_B_V(MTR_SF_GameControllerInit, MTR_GameControllerInit)
MTR_SCRIPT_FUNC_V_V(MTR_SF_GameControllerQuit, MTR_GameControllerQuit)
MTR_SCRIPT_FUNC_V_V(MTR_SF_GameControllerRefresh, MTR_GameControllerRefresh)
MTR_SCRIPT_FUNC_B_I2(MTR_SF_GameControllerButtonPress,
 MTR_GameControllerButtonPress)
MTR_SCRIPT_FUNC_B_I2(MTR_SF_GameControllerButtonRelease,
 MTR_GameControllerButtonRelease)
MTR_SCRIPT_FUNC_B_I2(MTR_SF_GameControllerButtonPressed,
 MTR_GameControllerButtonPressed)
MTR_SCRIPT_FUNC_S16t_I2(MTR_SF_GameControllerGetAxis, MTR_GameControllerGetAxis)
MTR_SCRIPT_FUNC_F_I2(MTR_SF_GameControllerGetAxis_f,
 MTR_GameControllerGetAxis_f)
MTR_SCRIPT_FUNC_I_I2(MTR_SF_GameControllerGetAxisDelta,
 MTR_GameControllerGetAxisDelta)
MTR_SCRIPT_FUNC_F_I2(MTR_SF_GameControllerGetAxisDelta_f,
 MTR_GameControllerGetAxisDelta_f)
MTR_SCRIPT_FUNC_I_I2(MTR_SF_GameControllerGetTrackballDeltaX,
 MTR_GameControllerGetTrackballDeltaX)
MTR_SCRIPT_FUNC_I_I2(MTR_SF_GameControllerGetTrackballDeltaY,
 MTR_GameControllerGetTrackballDeltaY)

#ifdef lua_h
MTR_SCRIPT_FUNC(MTR_SF_GameControllerGetTrackballDeltaXY)
{
    int controllerNum;
    int trackball;
    int deltaX;
    int deltaY;

    MTR_SF_GET_INT(controllerNum, 1);
    MTR_SF_GET_INT(trackball, 2);
    MTR_GameControllerGetTrackballDeltaXY(controllerNum, trackball, &deltaX,
     &deltaY);

    MTR_SF_PUSH_INT(deltaX);
    MTR_SF_PUSH_INT(deltaY);

    return 2;
}
#endif

MTR_SCRIPT_FUNC_U8t_I2(MTR_SF_GameControllerGetPovHat,
 MTR_GameControllerGetPovHat)
MTR_SCRIPT_FUNC_I_I2(MTR_SF_GameControllerGetPovHatHorizontal,
 MTR_GameControllerGetPovHatHorizontal)
MTR_SCRIPT_FUNC_I_I2(MTR_SF_GameControllerGetPovHatVertical,
 MTR_GameControllerGetPovHatVertical)

#ifdef lua_h
MTR_SCRIPT_FUNC(MTR_SF_GameControllerGetPovHatAxes)
{
    int controllerNum;
    int povHatNum;
    int horizontal;
    int vertical;

    MTR_SF_GET_INT(controllerNum, 1);
    MTR_SF_GET_INT(povHatNum, 2);
    MTR_GameControllerGetPovHatAxes(controllerNum, povHatNum, &horizontal,
     &vertical);

    MTR_SF_PUSH_INT(horizontal);
    MTR_SF_PUSH_INT(vertical);

    return 2;
}
#endif

MTR_SCRIPT_FUNC_I_I1(MTR_SF_GameControllerGetButtonsCount,
 MTR_GameControllerGetButtonsCount)
MTR_SCRIPT_FUNC_I_I1(MTR_SF_GameControllerGetAxesCount,
 MTR_GameControllerGetAxesCount)
MTR_SCRIPT_FUNC_I_I1(MTR_SF_GameControllerGetTrackballsCount,
 MTR_GameControllerGetTrackballsCount)
MTR_SCRIPT_FUNC_I_I1(MTR_SF_GameControllerGetPowHatsCount,
 MTR_GameControllerGetPowHatsCount)

void MTR_ScriptsRegisterAll(void)
{
    #ifdef MTR_MOD_PLUGIN
    mtrVm = MTR_ScriptsGetVm();
    #endif

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

    MTR_ScriptsRegisterVariable_i("POVHAT_CENTER", MTR_POVHAT_CENTER);
    MTR_ScriptsRegisterVariable_i("POVHAT_UP", MTR_POVHAT_UP);
    MTR_ScriptsRegisterVariable_i("POVHAT_DOWN", MTR_POVHAT_DOWN);
    MTR_ScriptsRegisterVariable_i("POVHAT_LEFT", MTR_POVHAT_LEFT);
    MTR_ScriptsRegisterVariable_i("POVHAT_RIGHT", MTR_POVHAT_RIGHT);
    MTR_ScriptsRegisterVariable_i("POVHAT_UP_LEFT", MTR_POVHAT_UP_LEFT);
    MTR_ScriptsRegisterVariable_i("POVHAT_UP_RIGHT", MTR_POVHAT_UP_RIGHT);
    MTR_ScriptsRegisterVariable_i("POVHAT_DOWN_LEFT", MTR_POVHAT_DOWN_LEFT);
    MTR_ScriptsRegisterVariable_i("POVHAT_DOWN_RIGHT", MTR_POVHAT_DOWN_RIGHT);
}

#endif
