#ifndef MTR_MOUSE_BINDING_COMMON_C
#define MTR_MOUSE_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(mtrSF_MouseFunctionSupported, mtrMouseFunctionSupported)
MTR_SCRIPT_FUNC_B_V(mtrSF_MouseInit, mtrMouseInit)
MTR_SCRIPT_FUNC_V_V(mtrSF_MouseRefresh, mtrMouseRefresh)
MTR_SCRIPT_FUNC_B_I1(mtrSF_MousePress, mtrMousePress)
MTR_SCRIPT_FUNC_B_I1(mtrSF_MouseRelease, mtrMouseRelease)
MTR_SCRIPT_FUNC_B_I1(mtrSF_MousePressed, mtrMousePressed)
MTR_SCRIPT_FUNC_I_V(mtrSF_MouseGetWheelRelative, mtrMouseGetWheelRelative)
MTR_SCRIPT_FUNC_B_V(mtrSF_MouseMoving, mtrMouseMoving)
MTR_SCRIPT_FUNC_I_V(mtrSF_MouseGetX, mtrMouseGetX)
MTR_SCRIPT_FUNC_I_V(mtrSF_MouseGetY, mtrMouseGetY)

#ifdef lua_h
MTR_SCRIPT_FUNC(mtrSF_MouseGetXY)
{
    int x;
    int y;

    mtrMouseGetXY(&x, &y);

    MTR_SF_PUSH_INT(x);
    MTR_SF_PUSH_INT(y);

    return 2;
}
#endif

MTR_SCRIPT_FUNC_I_V(mtrSF_MouseGetDeltaX, mtrMouseGetDeltaX)
MTR_SCRIPT_FUNC_I_V(mtrSF_MouseGetDeltaY, mtrMouseGetDeltaY)

#ifdef lua_h
MTR_SCRIPT_FUNC(mtrSF_MouseGetDeltaXY)
{
    int deltaX;
    int deltaY;

    mtrMouseGetDeltaXY(&deltaX, &deltaY);

    MTR_SF_PUSH_INT(deltaX);
    MTR_SF_PUSH_INT(deltaY);

    return 2;
}
#endif

void mtrScriptsRegisterAll(void)
{
    mtrVm = mtrScriptsGetVm();

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

    mtrScriptsRegisterNumericVariable("MOUSE_LEFT", MTR_MOUSE_LEFT);
    mtrScriptsRegisterNumericVariable("MOUSE_RIGHT", MTR_MOUSE_RIGHT);
    mtrScriptsRegisterNumericVariable("MOUSE_MIDDLE", MTR_MOUSE_MIDDLE);
    mtrScriptsRegisterNumericVariable("MOUSE_X1", MTR_MOUSE_X1);
    mtrScriptsRegisterNumericVariable("MOUSE_X2", MTR_MOUSE_X2);
}

#endif
