#ifndef MTR_ENGINE_MESSAGEBOX_H
#define MTR_ENGINE_MESSAGEBOX_H

#include "marathoner/marathoner.h"

#ifdef __EMSCRIPTEN__
    #include <emscripten.h>
#else
    #include <windows.h>
#endif

#include "marathoner/engine.h"

void MTR_CALL mtrShowSimpleMessageBox(uint8_t type, const char *title,
 const char *message);
bool MTR_CALL mtrShowYesNoMessageBox(const char *title, const char *message);

#endif
