#include "binding.h"

#include "marathoner/plugin_common.c"

MRT_EXPORT mtrReport* MRT_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Mouse_SDL2_Lua52";
    report->version = 0x000000;
    report->prereqsCount = 2;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    report->prereqs[0] = "Mouse_SDL2";
    report->prereqs[1] = "Script_Lua52";
    return report;
}

MRT_EXPORT void MRT_CALL mtrPluginInit(void)
{
    bool ok;
    ok = true;

    mtrLogWrite_s("Reporting Lua compile-time version:", 3, MTR_LMT_INFO,
     LUA_RELEASE);

    mtrScriptsRegisterFunction = (mtrScriptsRegisterFunctionFunc)mtrFindFunction("Script_Lua52",
     "mtrScriptsRegisterFunction");
    if (mtrScriptsRegisterFunction == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrScriptsRegisterFunction");
        ok = false;
    }
    mtrScriptsRegisterNumericVariable = (mtrScriptsRegisterNumericVariableFunc)mtrFindFunction("Script_Lua52",
     "mtrScriptsRegisterNumericVariable");
    if (mtrScriptsRegisterNumericVariable == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrScriptsRegisterNumericVariable");
        ok = false;
    }
    mtrScriptsGetVm = (mtrScriptsGetVmFunc)mtrFindFunction("Script_Lua52",
      "mtrScriptsGetVm");
    if (mtrScriptsGetVm == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrScriptsGetVm");
        ok = false;
    }
    else
    {
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
        mtrMouseGetXY = (mtrMouseGetXYFunc)mtrFindFunction("Mouse_SDL2",
          "mtrMouseGetXY");
        if (mtrMouseGetXY == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrMouseGetXY");
            ok = false;
        }
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
        mtrMouseGetDeltaXY = (mtrMouseGetDeltaXYFunc)mtrFindFunction("Mouse_SDL2",
          "mtrMouseGetDeltaXY");
        if (mtrMouseGetDeltaXY == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrMouseGetDeltaXY");
            ok = false;
        }
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
            mtrScriptsRegisterFunction(mtrSF_MouseGetXY, "MouseGetXY");
            mtrScriptsRegisterFunction(mtrSF_MouseGetDeltaX, "MouseGetDeltaX");
            mtrScriptsRegisterFunction(mtrSF_MouseGetDeltaY, "MouseGetDeltaY");
            mtrScriptsRegisterFunction(mtrSF_MouseGetDeltaXY,
             "MouseGetDeltaXY");
        }
        else
        {
            mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
        }
    }
}

int mtrSF_MouseInit(lua_State* l)
{
    bool success = mtrMouseInit();
    lua_pushboolean(mtrVm, success);

    return 1;
}

int mtrSF_MouseRefresh(lua_State* l)
{
    mtrMouseRefresh();

    return 0;
}

int mtrSF_MousePress(lua_State* l)
{
    uint8_t button = (uint8_t)lua_tointeger(mtrVm, 1);
    bool result = mtrMousePress(button);
    lua_pushboolean(mtrVm, result);

    return 1;
}

int mtrSF_MouseRelease(lua_State* l)
{
    uint8_t button = (uint8_t)lua_tointeger(mtrVm, 1);
    bool result = mtrMouseRelease(button);
    lua_pushboolean(mtrVm, result);

    return 1;
}

int mtrSF_MousePressed(lua_State* l)
{
    uint8_t button = (uint8_t)lua_tointeger(mtrVm, 1);
    bool result = mtrMousePressed(button);
    lua_pushboolean(mtrVm, result);

    return 1;
}

int mtrSF_MouseGetWheelRelative(lua_State* l)
{
    uint8_t result = mtrMouseGetWheelRelative();
    lua_pushinteger(mtrVm, result);

    return 1;
}

int mtrSF_MouseGetX(lua_State* l)
{
    int16_t x = mtrMouseGetX();
    lua_pushnumber(mtrVm, x);

    return 1;
}

int mtrSF_MouseGetY(lua_State* l)
{
    int16_t y = mtrMouseGetY();
    lua_pushinteger(mtrVm, y);

    return 1;
}

int mtrSF_MouseGetXY(lua_State* l)
{
    int16_t x;
    int16_t y;
    mtrMouseGetXY(&x, &y);
    lua_pushinteger(mtrVm, x);
    lua_pushinteger(mtrVm, y);

    return 2;
}

int mtrSF_MouseGetDeltaX(lua_State* l)
{
    int16_t deltaX = mtrMouseGetDeltaX();
    lua_pushnumber(mtrVm, deltaX);

    return 1;
}

int mtrSF_MouseGetDeltaY(lua_State* l)
{
    int16_t deltaY = mtrMouseGetDeltaY();
    lua_pushinteger(mtrVm, deltaY);

    return 1;
}

int mtrSF_MouseGetDeltaXY(lua_State* l)
{
    int16_t deltaX;
    int16_t deltaY;
    mtrMouseGetDeltaXY(&deltaX, &deltaY);
    lua_pushinteger(mtrVm, deltaX);
    lua_pushinteger(mtrVm, deltaY);

    return 2;
}
