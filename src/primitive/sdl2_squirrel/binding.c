#include "binding.h"

#include "marathoner/plugin_common.c"
#include "../binding_common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Primitive_SDL2_Squirrel";
    report->version = MTR_VERSION_PRIMITIVE_SDL2_SQUIRREL;
    report->subsystem = "binding";
    report->prereqsCount = 2;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    report->prereqs[0] = "Primitive_SDL2";
    report->prereqs[1] = "Script_Squirrel";
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}

MTR_EXPORT void MTR_CALL mtrPluginInit(void)
{
    bool ok;
    ok = true;

    mtrLogWrite_s("Reporting Squirrel compile-time version:", 1, MTR_LMT_INFO,
     SQUIRREL_VERSION);
    mtrLogWrite_i("Reporting Squirrel linked version:", 1, MTR_LMT_INFO,
     sq_getversion());

    mtrScriptsRegisterFunction = (mtrScriptsRegisterFunctionFunc)mtrFindFunction("Script_Squirrel",
     "mtrScriptsRegisterFunction");
    if (mtrScriptsRegisterFunction == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrScriptsRegisterFunction");
        ok = false;
    }
    mtrScriptsGetVm = (mtrScriptsGetVmFunc)mtrFindFunction("Script_Squirrel",
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
