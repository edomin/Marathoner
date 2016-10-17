#include "binding.h"

#include "marathoner/plugin_common.c"
#include "../binding_common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Timer_SDL2_Lua";
    report->version = MTR_VERSION_TIMER_SDL2_LUA;
    report->subsystem = "binding";
    report->prereqsCount = 2;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    report->prereqs[0] = "Timer_SDL2";
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
        mtrTimerInit = (mtrTimerInitFunc)mtrFindFunction("Timer_SDL2",
          "mtrTimerInit");
        if (mtrTimerInit == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTimerInit");
            ok = false;
        }
        mtrTimerStart = (mtrTimerStartFunc)mtrFindFunction("Timer_SDL2",
          "mtrTimerStart");
        if (mtrTimerStart == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTimerStart");
            ok = false;
        }
        mtrTimerDelay = (mtrTimerDelayFunc)mtrFindFunction("Timer_SDL2",
          "mtrTimerDelay");
        if (mtrTimerDelay == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTimerDelay");
            ok = false;
        }
        mtrTimerDelayForFPS = (mtrTimerDelayForFPSFunc)mtrFindFunction("Timer_SDL2",
          "mtrTimerDelayForFPS");
        if (mtrTimerDelayForFPS == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTimerDelayForFPS");
            ok = false;
        }
        mtrTimerDelayForFPS_f = (mtrTimerDelayForFPS_fFunc)mtrFindFunction("Timer_SDL2",
          "mtrTimerDelayForFPS_f");
        if (mtrTimerDelayForFPS_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTimerDelayForFPS_f");
            ok = false;
        }
        if (ok)
        {
            mtrScriptsRegisterFunction(mtrSF_TimerInit, "TimerInit");
            mtrScriptsRegisterFunction(mtrSF_TimerStart, "TimerStart");
            mtrScriptsRegisterFunction(mtrSF_TimerDelay, "TimerDelay");
            mtrScriptsRegisterFunction(mtrSF_TimerDelayForFPS, "TimerDelayForFPS");
            mtrScriptsRegisterFunction(mtrSF_TimerDelayForFPS_f, "TimerDelayForFPS_f");
        }
        else
        {
            mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
        }
    }
}
