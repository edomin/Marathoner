#ifndef MTR_ENGINE_MESSAGEBOX
#define MTR_ENGINE_MESSAGEBOX

#include <stdint.h>
#include <windows.h>
#include <stdbool.h>

#include "marathoner.h"

void mtrShowSimpleMessageBox(uint8_t type, char *title, char *message);
bool mtrShowYesNoMessageBox(char *title, char *message);

#endif
