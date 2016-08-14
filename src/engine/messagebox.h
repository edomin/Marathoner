#ifndef MTR_ENGINE_MESSAGEBOX
#define MTR_ENGINE_MESSAGEBOX

#include <windows.h>

#include "marathoner/engine.h"

void mtrShowSimpleMessageBox(uint8_t type, char *title, char *message);
bool mtrShowYesNoMessageBox(char *title, char *message);

#endif
