#include "binding.h"

#include "marathoner/plugin_common.c"
#include "../math_binding_common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Utils_math_Squirrel";
    report->version = MTR_VERSION_UTILS_MATH_SQUIRREL;
    report->subsystem = "binding";
    report->prereqsCount = 2;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    if (report->prereqs == NULL)
    {
        free(report);
        return NULL;
    }
    report->prereqs[0] = "Utils_math";
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

    MTR_FIND_FUNCTION(mtrScriptsRegisterFunction, "Script_Squirrel");
    MTR_FIND_FUNCTION(mtrScriptsGetVm, "Script_Squirrel");

    if (ok)
    {
        mtrScriptsRegisterAll();
    }
}
