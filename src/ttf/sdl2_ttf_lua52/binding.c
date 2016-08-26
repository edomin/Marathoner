#include "binding.h"

#include "marathoner/plugin_common.c"

__declspec(dllexport) mtrReport* __stdcall mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "TTF_SDL2_ttf_Lua52";
    report->version = 0x000000;
    report->prereqsCount = 2;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    report->prereqs[0] = "TTF_SDL2_ttf";
    report->prereqs[1] = "Script_Lua52";
    return report;
}

__declspec(dllexport) void __stdcall mtrPluginInit(void)
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
        mtrTtfInit = (mtrTtfInitFunc)mtrFindFunction("TTF_SDL2_ttf",
          "mtrTtfInit");
        if (mtrTtfInit == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTtfInit");
            ok = false;
        }
        mtrTtfQuit = (mtrTtfQuitFunc)mtrFindFunction("TTF_SDL2_ttf",
          "mtrTtfQuit");
        if (mtrTtfQuit == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTtfQuit");
            ok = false;
        }
        mtrTtfLoad = (mtrTtfLoadFunc)mtrFindFunction("TTF_SDL2_ttf",
          "mtrTtfLoad");
        if (mtrTtfLoad == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTtfLoad");
            ok = false;
        }
        mtrTtfFree = (mtrTtfFreeFunc)mtrFindFunction("TTF_SDL2_ttf",
          "mtrTtfFree");
        if (mtrTtfFree == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTtfFree");
            ok = false;
        }
        mtrTtfSetFontStyle = (mtrTtfSetFontStyleFunc)mtrFindFunction("TTF_SDL2_ttf",
          "mtrTtfSetFontStyle");
        if (mtrTtfSetFontStyle == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTtfSetFontStyle");
            ok = false;
        }
        mtrTtfSetFontOutline = (mtrTtfSetFontOutlineFunc)mtrFindFunction("TTF_SDL2_ttf",
          "mtrTtfSetFontOutline");
        if (mtrTtfSetFontOutline == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTtfSetFontOutline");
            ok = false;
        }
        if (ok)
        {
            mtrScriptsRegisterNumericVariable("FS_NORMAL", MTR_FS_NORMAL);
            mtrScriptsRegisterNumericVariable("FS_BOLD", MTR_FS_BOLD);
            mtrScriptsRegisterNumericVariable("FS_ITALIC", MTR_FS_ITALIC);
            mtrScriptsRegisterNumericVariable("FS_UNDERLINE", MTR_FS_UNDERLINE);
            mtrScriptsRegisterNumericVariable("FS_STRIKETHROUGH",
             MTR_FS_STRIKETHROUGH);

            mtrScriptsRegisterFunction(mtrSF_TtfInit, "TtfInit");
            mtrScriptsRegisterFunction(mtrSF_TtfQuit, "TtfQuit");
            mtrScriptsRegisterFunction(mtrSF_TtfLoad, "TtfLoad");
            mtrScriptsRegisterFunction(mtrSF_TtfFree, "TtfFree");
            mtrScriptsRegisterFunction(mtrSF_TtfSetFontStyle,
             "TtfSetFontStyle");
            mtrScriptsRegisterFunction(mtrSF_TtfSetFontOutline,
             "TtfSetFontOutline");
        }
        else
        {
            mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
        }
    }
}

int mtrSF_TtfInit(lua_State* l)
{
    uint32_t dmSize = lua_tonumber(mtrVm, 1);
    uint32_t reservedCount = lua_tonumber(mtrVm, 2);
    bool     success = mtrTtfInit(dmSize, reservedCount);
    lua_pushboolean(mtrVm, success);

    return 1;
}

int mtrSF_TtfQuit(lua_State* l)
{
    mtrTtfQuit();

    return 0;
}

int mtrSF_TtfLoad(lua_State* l)
{
    const char *filename = lua_tostring(mtrVm, 1);
    uint16_t    size = lua_tointeger(mtrVm, 2);
    uint32_t    fontNum = mtrTtfLoad(filename, size);
    lua_pushnumber(mtrVm, fontNum);

    return 1;
}

int mtrSF_TtfFree(lua_State* l)
{
    uint32_t fontNum = lua_tonumber(mtrVm, 1);
    mtrTtfFree(fontNum);

    return 0;
}

int mtrSF_TtfSetFontStyle(lua_State* l)
{
    uint32_t texNum = lua_tonumber(mtrVm, 1);
    uint8_t style = lua_tointeger(mtrVm, 2);
    mtrTtfSetFontStyle(texNum, style);

    return 0;
}

int mtrSF_TtfSetFontOutline(lua_State* l)
{
    uint32_t texNum = lua_tonumber(mtrVm, 1);
    uint16_t outline = lua_tointeger(mtrVm, 2);
    mtrTtfSetFontOutline(texNum, outline);

    return 0;
}
