#ifndef MTR_MOUSE_BINDING_COMMON_C
#define MTR_MOUSE_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(MTR_SF_MouseFunctionSupported, MTR_MouseFunctionSupported)
MTR_SCRIPT_FUNC_B_V(MTR_SF_MouseInit, MTR_MouseInit)
MTR_SCRIPT_FUNC_V_V(MTR_SF_MouseRefresh, MTR_MouseRefresh)
MTR_SCRIPT_FUNC_B_I1(MTR_SF_MousePress, MTR_MousePress)
MTR_SCRIPT_FUNC_B_I1(MTR_SF_MouseRelease, MTR_MouseRelease)
MTR_SCRIPT_FUNC_B_I1(MTR_SF_MousePressed, MTR_MousePressed)
MTR_SCRIPT_FUNC_I_V(MTR_SF_MouseGetWheelRelative, MTR_MouseGetWheelRelative)
MTR_SCRIPT_FUNC_B_V(MTR_SF_MouseMoving, MTR_MouseMoving)
MTR_SCRIPT_FUNC_I_V(MTR_SF_MouseGetX, MTR_MouseGetX)
MTR_SCRIPT_FUNC_I_V(MTR_SF_MouseGetY, MTR_MouseGetY)

#ifdef lua_h
MTR_SCRIPT_FUNC(MTR_SF_MouseGetXY)
{
    int x;
    int y;

    MTR_MouseGetXY(&x, &y);

    MTR_SF_PUSH_INT(x);
    MTR_SF_PUSH_INT(y);

    return 2;
}
#endif

MTR_SCRIPT_FUNC_I_V(MTR_SF_MouseGetDeltaX, MTR_MouseGetDeltaX)
MTR_SCRIPT_FUNC_I_V(MTR_SF_MouseGetDeltaY, MTR_MouseGetDeltaY)

#ifdef lua_h
MTR_SCRIPT_FUNC(MTR_SF_MouseGetDeltaXY)
{
    int deltaX;
    int deltaY;

    MTR_MouseGetDeltaXY(&deltaX, &deltaY);

    MTR_SF_PUSH_INT(deltaX);
    MTR_SF_PUSH_INT(deltaY);

    return 2;
}
#endif

void MTR_ScriptsRegisterAll(void)
{
    mtrVm = MTR_ScriptsGetVm();

    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, MouseFunctionSupported);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, MouseInit);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, MouseRefresh);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, MousePress);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, MouseRelease);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, MousePressed);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, MouseGetWheelRelative);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, MouseMoving);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, MouseGetX);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, MouseGetY);
    #ifdef lua_h
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, MouseGetXY);
    #endif
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, MouseGetDeltaX);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, MouseGetDeltaY);
    #ifdef lua_h
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, MouseGetDeltaXY);
    #endif

    MTR_ScriptsRegisterVariable_i("MOUSE_LEFT", MTR_MOUSE_LEFT);
    MTR_ScriptsRegisterVariable_i("MOUSE_RIGHT", MTR_MOUSE_RIGHT);
    MTR_ScriptsRegisterVariable_i("MOUSE_MIDDLE", MTR_MOUSE_MIDDLE);
    MTR_ScriptsRegisterVariable_i("MOUSE_X1", MTR_MOUSE_X1);
    MTR_ScriptsRegisterVariable_i("MOUSE_X2", MTR_MOUSE_X2);
}

#endif
