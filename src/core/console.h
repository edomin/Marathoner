#ifndef MTR_CORE_CONSOLE_H
#define MTR_CORE_CONSOLE_H

#include <stdio.h>

#include "marathoner/engine.h"

HWND mtrConsole;
static bool mtrConsoleInited __attribute__((used)) = false;
bool mtrConsoleShowed;

void MTR_CALL mtrConsoleShow(void);
void MTR_CALL mtrConsoleHide(void);
void mtrConsolePrint(const char *string);

#endif
