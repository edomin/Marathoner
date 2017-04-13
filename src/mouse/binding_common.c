#ifndef MTR_MOUSE_BINDING_COMMON_C
#define MTR_MOUSE_BINDING_COMMON_C

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

MTR_SCRIPT_FUNC(mtrSF_MouseMoving)
{
    bool moving;

    moving = mtrMouseMoving();

    MTR_SF_PUSH_BOOL(moving);

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

#ifndef _SQUIRREL_H_
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

#ifndef _SQUIRREL_H_
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
    #ifndef _SQUIRREL_H_
    MTR_FIND_FUNCTION(mtrMouseGetXY, MTR_SOURCE_MODULE);
    #endif
    MTR_FIND_FUNCTION(mtrMouseGetDeltaX, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrMouseGetDeltaY, MTR_SOURCE_MODULE);
    #ifndef _SQUIRREL_H_
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
        #ifndef _SQUIRREL_H_
        mtrScriptsRegisterFunction(mtrSF_MouseGetXY, "MouseGetXY");
        #endif
        mtrScriptsRegisterFunction(mtrSF_MouseGetDeltaX, "MouseGetDeltaX");
        mtrScriptsRegisterFunction(mtrSF_MouseGetDeltaY, "MouseGetDeltaY");
        #ifndef _SQUIRREL_H_
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
