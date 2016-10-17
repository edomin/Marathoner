#include "binding.h"

#include "marathoner/plugin_common.c"
#include "../binding_common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "TTF_SDL2_ttf_Lua";
    report->version = MTR_VERSION_TTF_SDL2_TTF_LUA;
    report->subsystem = "binding";
    report->prereqsCount = 2;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    report->prereqs[0] = "TTF_SDL2_ttf";
    report->prereqs[1] = "Script_Lua";
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}

MTR_EXPORT void MTR_CALL mtrPluginInit(void)
{
    bool ok;
    ok = true;

    mtrLogWrite_s("Reporting Lua compile-time version:", 3, MTR_LMT_INFO,
     LUA_RELEASE);

    mtrScriptsRegisterFunction = (mtrScriptsRegisterFunctionFunc)mtrFindFunction("Script_Lua",
     "mtrScriptsRegisterFunction");
    if (mtrScriptsRegisterFunction == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrScriptsRegisterFunction");
        ok = false;
    }
    mtrScriptsRegisterNumericVariable = (mtrScriptsRegisterNumericVariableFunc)mtrFindFunction("Script_Lua",
     "mtrScriptsRegisterNumericVariable");
    if (mtrScriptsRegisterNumericVariable == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrScriptsRegisterNumericVariable");
        ok = false;
    }
    mtrScriptsGetVm = (mtrScriptsGetVmFunc)mtrFindFunction("Script_Lua",
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
