#include "binding.h"

#include "marathoner/plugin_common.c"
#include "../binding_common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Game_Controller_SDL2_Lua";
    report->version = MTR_VERSION_GAME_CONTROLLER_SDL2_LUA;
    report->subsystem = "binding";
    report->prereqsCount = 2;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    report->prereqs[0] = "Game_Controller_SDL2";
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
    if (ok)
    {
        mtrScriptsRegisterAll();
    }
}
