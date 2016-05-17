#include "binding.h"

#include "plugin_common.c"

__declspec(dllexport) mtrReport* __stdcall mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Screen_sdl_gpu_Lua52";
    report->prereqsCount = 2;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    report->prereqs[0] = "Screen_sdl_gpu";
    report->prereqs[1] = "Script_Lua52";
    return report;
}

__declspec(dllexport) void __stdcall mtrPluginInit(void)
{
    bool ok;
    ok = true;
    mtrScriptsRegisterFunction = (mtrScriptsRegisterFunctionFunc)mtrFindFunction("Script_Lua52", "mtrScriptsRegisterFunction");
    if (mtrScriptsRegisterFunction == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrScriptsRegisterFunction");
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
        mtrScreenInit = (mtrScreenInitFunc)mtrFindFunction("Screen_sdl_gpu",
          "mtrScreenInit");
        if (mtrScreenInit == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrScreenInit");
            ok = false;
        }
        mtrScreenQuit = (mtrScreenQuitFunc)mtrFindFunction("Screen_sdl_gpu",
          "mtrScreenQuit");
        if (mtrScreenQuit == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrScreenQuit");
            ok = false;
        }
        if (ok)
        {
            mtrScriptsRegisterFunction(mtrSF_ScreenInit, "ScreenInit");
            mtrScriptsRegisterFunction(mtrSF_ScreenQuit, "ScreenQuit");
        }
        else
        {
            mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
        }
    }
}

int mtrSF_ScreenInit(lua_State* l)
{
    int w = lua_tonumber(mtrVm, 1); /* получаем 1-ый */
                                         /* переданный параметр */
    int h = lua_tonumber(mtrVm, 2);
//    const char *title = lua_tostring(mtrVm, 3);
//    bool fullscreen = lua_toboolean(mtrVm, 4);
    mtrScreenInit(w, h);
    return 0;
}

int mtrSF_ScreenQuit(lua_State* l)
{
    mtrScreenQuit();
    return 0;
}
