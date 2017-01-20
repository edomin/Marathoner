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
    mtrMouseInit = (mtrMouseInitFunc)mtrFindFunction("Mouse_SDL2",
      "mtrMouseInit");
    if (mtrMouseInit == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrMouseInit");
        ok = false;
    }
    mtrMouseRefresh = (mtrMouseRefreshFunc)mtrFindFunction("Mouse_SDL2",
      "mtrMouseRefresh");
    if (mtrMouseRefresh == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrMouseRefresh");
        ok = false;
    }
    mtrMousePress = (mtrMousePressFunc)mtrFindFunction("Mouse_SDL2",
      "mtrMousePress");
    if (mtrMousePress == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrMousePress");
        ok = false;
    }
    mtrMouseRelease = (mtrMouseReleaseFunc)mtrFindFunction("Mouse_SDL2",
      "mtrMouseRelease");
    if (mtrMouseRelease == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrMouseRelease");
        ok = false;
    }
    mtrMousePressed = (mtrMousePressedFunc)mtrFindFunction("Mouse_SDL2",
      "mtrMousePressed");
    if (mtrMousePressed == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrMousePressed");
        ok = false;
    }
    mtrMouseGetWheelRelative = (mtrMouseGetWheelRelativeFunc)mtrFindFunction("Mouse_SDL2",
      "mtrMouseGetWheelRelative");
    if (mtrMouseGetWheelRelative == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrMouseGetWheelRelative");
        ok = false;
    }
    mtrMouseGetX = (mtrMouseGetXFunc)mtrFindFunction("Mouse_SDL2",
      "mtrMouseGetX");
    if (mtrMouseGetX == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrMouseGetX");
        ok = false;
    }
    mtrMouseGetY = (mtrMouseGetYFunc)mtrFindFunction("Mouse_SDL2",
      "mtrMouseGetY");
    if (mtrMouseGetY == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrMouseGetY");
        ok = false;
    }
    #ifndef _SQUIRREL_H_
    mtrMouseGetXY = (mtrMouseGetXYFunc)mtrFindFunction("Mouse_SDL2",
      "mtrMouseGetXY");
    if (mtrMouseGetXY == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrMouseGetXY");
        ok = false;
    }
    #endif
    mtrMouseGetDeltaX = (mtrMouseGetDeltaXFunc)mtrFindFunction("Mouse_SDL2",
      "mtrMouseGetDeltaX");
    if (mtrMouseGetDeltaX == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrMouseGetDeltaX");
        ok = false;
    }
    mtrMouseGetDeltaY = (mtrMouseGetDeltaYFunc)mtrFindFunction("Mouse_SDL2",
      "mtrMouseGetDeltaY");
    if (mtrMouseGetDeltaY == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrMouseGetDeltaY");
        ok = false;
    }
    #ifndef _SQUIRREL_H_
    mtrMouseGetDeltaXY = (mtrMouseGetDeltaXYFunc)mtrFindFunction("Mouse_SDL2",
      "mtrMouseGetDeltaXY");
    if (mtrMouseGetDeltaXY == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrMouseGetDeltaXY");
        ok = false;
    }
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
