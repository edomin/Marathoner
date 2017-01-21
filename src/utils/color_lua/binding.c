#include "binding.h"

#include "marathoner/plugin_common.c"
#include "../color_binding_common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Utils_color_Lua";
    report->version = MTR_VERSION_UTILS_COLOR_LUA;
    report->subsystem = "binding";
    report->prereqsCount = 2;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    if (report->prereqs == NULL)
    {
        free(report);
        return NULL;
    }
    report->prereqs[0] = "Utils_color";
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

    MTR_FIND_FUNCTION(mtrScriptsRegisterFunction, "Script_Squirrel");
    MTR_FIND_FUNCTION(mtrScriptsRegisterNumericVariable, "Script_Squirrel");
    MTR_FIND_FUNCTION(mtrScriptsGetVm, "Script_Squirrel");

    if (ok)
    {
        mtrScriptsRegisterAll();
    }
}
