#include "screen.h"

MTR_DECLSPEC mtrReport* __stdcall mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Screen_SDL2";
    report->prereqsCount = 1;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    report->prereqs[0] = "General_SDL2";
    return report;
}

