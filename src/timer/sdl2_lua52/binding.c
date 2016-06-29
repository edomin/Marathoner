#include "binding.h"

#include "plugin_common.c"

__declspec(dllexport) mtrReport* __stdcall mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Timer_SDL2_Lua52";
    report->version = 0x000000;
    report->prereqsCount = 2;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    report->prereqs[0] = "Timer_SDL2";
    report->prereqs[1] = "Script_Lua52";
    return report;
}

__declspec(dllexport) void __stdcall mtrPluginInit(void)
{
    bool ok;
    ok = true;

    mtrLogWrite_s("Reporting Lua compile-time version:", 1, MTR_LMT_INFO,
     LUA_RELEASE);

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

int mtrSF_TimerStart(lua_State* l)
{
    mtrTimerStart();

    return 0;
}

int mtrSF_TimerDelay(lua_State* l)
{
    uint32_t ms = lua_tonumber(mtrVm, 1);
    uint32_t fps = mtrTimerDelay(ms);
    lua_pushnumber(mtrVm, fps);

    return 1;
}

int mtrSF_TimerDelayForFPS(lua_State* l)
{
    uint32_t fps = lua_tonumber(mtrVm, 1);
    uint32_t resultFps = mtrTimerDelayForFPS(fps);
    lua_pushnumber(mtrVm, resultFps);

    return 1;
}

int mtrSF_TimerDelayForFPS_f(lua_State* l)
{
    float fps = lua_tonumber(mtrVm, 1);
    float resultFps = mtrTimerDelayForFPS_f(fps);
    lua_pushnumber(mtrVm, resultFps);

    return 1;
}
