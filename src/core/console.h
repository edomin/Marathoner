#ifndef MTR_CORE_CONSOLE_H
#define MTR_CORE_CONSOLE_H

#include <stdio.h>
#ifdef __MINGW32__
    #include <windows.h>
#endif

#include "marathoner/engine.h"

#ifdef __MINGW32__
HWND mtrConsole;
#endif
static bool mtrConsoleInited __attribute__((used)) = false;
bool mtrConsoleShowed;

void MTR_CALL MTR_ConsoleShow(void);
void MTR_CALL MTR_ConsoleHide(void);
void MTR_ConsolePrint(const char *string);

#endif
