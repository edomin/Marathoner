#include "general.h"

mtrReport* __stdcall mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "General_SDL2";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    return report;
}
