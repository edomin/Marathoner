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
    mtrScriptsRegisterFunction = (mtrScriptsRegisterFunctionFunc)mtrFindFunction("Script_Lua52", "mtrScriptsRegisterFunction");
    mtrScriptsGetVm = (mtrScriptsGetVmFunc)mtrFindFunction("Script_Lua52", "mtrScriptsGetVm");

    mtrScreenInit = (mtrScreenInitFunc)mtrFindFunction("Screen_sdl_gpu", "mtrScreenInit");
    mtrScreenQuit = (mtrScreenQuitFunc)mtrFindFunction("Screen_sdl_gpu", "mtrScreenQuit");

    mtrScriptsRegisterFunction(mtrSF_ScreenInit, "ScreenInit");
    mtrScriptsRegisterFunction(mtrSF_ScreenQuit, "ScreenQuit");
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
