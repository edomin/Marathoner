#include "binding.h"

#include "marathoner/plugin_common.c"
#include "../binding_common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Screen_SDL2_gpu_Lua";
    report->version = MTR_VERSION_SCREEN_SDL2_GPU_LUA;
    report->subsystem = "binding";
    report->prereqsCount = 2;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    report->prereqs[0] = "Screen_SDL2_gpu";
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
        mtrScreenInit = (mtrScreenInitFunc)mtrFindFunction("Screen_SDL2_gpu",
         "mtrScreenInit");
        if (mtrScreenInit == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
             "mtrScreenInit");
            ok = false;
        }
        mtrScreenQuit = (mtrScreenQuitFunc)mtrFindFunction("Screen_SDL2_gpu",
         "mtrScreenQuit");
        if (mtrScreenQuit == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
             "mtrScreenQuit");
            ok = false;
        }
        mtrScreenFlip = (mtrScreenFlipFunc)mtrFindFunction("Screen_SDL2_gpu",
         "mtrScreenFlip");
        if (mtrScreenFlip == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
             "mtrScreenFlip");
            ok = false;
        }
        if (ok)
        {
            mtrScriptsRegisterFunction(mtrSF_ScreenInit, "ScreenInit");
            mtrScriptsRegisterFunction(mtrSF_ScreenQuit, "ScreenQuit");
            mtrScriptsRegisterFunction(mtrSF_ScreenFlip, "ScreenFlip");
        }
        else
        {
            mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
        }
    }
}
