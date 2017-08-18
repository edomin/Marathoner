#ifndef MTR_MOUSE_BINDING_COMMON_C
#define MTR_MOUSE_BINDING_COMMON_C

#include "marathoner/script_func.h"

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
    bool ok;
    ok = true;

    mtrVm = mtrScriptsGetVm();

    MTR_FIND_FUNCTION(mtrMouseInit, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrMouseRefresh, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrMousePress, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrMouseRelease, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrMousePressed, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrMouseGetWheelRelative, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrMouseMoving, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrMouseGetX, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrMouseGetY, MTR_SOURCE_MODULE);
    #ifdef lua_h
    MTR_FIND_FUNCTION(mtrMouseGetXY, MTR_SOURCE_MODULE);
    #endif
    MTR_FIND_FUNCTION(mtrMouseGetDeltaX, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrMouseGetDeltaY, MTR_SOURCE_MODULE);
    #ifdef lua_h
    MTR_FIND_FUNCTION(mtrMouseGetDeltaXY, MTR_SOURCE_MODULE);
    #endif

    if (ok)
    {
        mtrScriptsRegisterNumericVariable("MOUSE_LEFT", MTR_MOUSE_LEFT);
        mtrScriptsRegisterNumericVariable("MOUSE_RIGHT", MTR_MOUSE_RIGHT);
        mtrScriptsRegisterNumericVariable("MOUSE_MIDDLE", MTR_MOUSE_MIDDLE);
        mtrScriptsRegisterNumericVariable("MOUSE_X1", MTR_MOUSE_X1);
        mtrScriptsRegisterNumericVariable("MOUSE_X2", MTR_MOUSE_X2);

        mtrScriptsRegisterFunction(mtrSF_MouseInit, "MouseInit");
        mtrScriptsRegisterFunction(mtrSF_MouseRefresh, "MouseRefresh");
        mtrScriptsRegisterFunction(mtrSF_MousePress, "MousePress");
        mtrScriptsRegisterFunction(mtrSF_MouseRelease, "MouseRelease");
        mtrScriptsRegisterFunction(mtrSF_MousePressed, "MousePressed");
        mtrScriptsRegisterFunction(mtrSF_MouseGetWheelRelative,
         "MouseGetWheelRelative");
        mtrScriptsRegisterFunction(mtrSF_MouseMoving, "MouseMoving");
        mtrScriptsRegisterFunction(mtrSF_MouseGetX, "MouseGetX");
        mtrScriptsRegisterFunction(mtrSF_MouseGetY, "MouseGetY");
        #ifdef lua_h
        mtrScriptsRegisterFunction(mtrSF_MouseGetXY, "MouseGetXY");
        #endif
        mtrScriptsRegisterFunction(mtrSF_MouseGetDeltaX, "MouseGetDeltaX");
        mtrScriptsRegisterFunction(mtrSF_MouseGetDeltaY, "MouseGetDeltaY");
        #ifdef lua_h
        mtrScriptsRegisterFunction(mtrSF_MouseGetDeltaXY,
         "MouseGetDeltaXY");
        #endif
    }
    else
    {
        mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
    }
}

#endif
