#include "binding.h"

#include "marathoner/plugin_common.c"
#include "../binding_common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Primitive_SDL2_Lua";
    report->version = MTR_VERSION_PRIMITIVE_SDL2_LUA;
    report->subsystem = "binding";
    report->prereqsCount = 2;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    if (report->prereqs == NULL)
    {
        free(report);
        return NULL;
    }
    report->prereqs[0] = "Primitive_SDL2";
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

    MTR_FIND_FUNCTION(mtrScriptsRegisterFunction, "Script_Lua");
    MTR_FIND_FUNCTION(mtrScriptsGetVm, "Script_Lua");

    if (ok)
    {
        mtrScriptsRegisterAll();
    }
}
