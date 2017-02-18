#ifndef MTR_ENGINE_MESSAGEBOX_H
#define MTR_ENGINE_MESSAGEBOX_H

#include "marathoner/marathoner.h"

#ifdef __EMSCRIPTEN__
    #include <emscripten.h>
#else
    #include "tinyfiledialogs.h"
#endif

#include "marathoner/engine.h"

MTR_EXPORT void MTR_CALL mtrShowSimpleMessageBox(uint8_t type,
 const char *title, const char *message);
MTR_EXPORT bool MTR_CALL mtrShowYesNoMessageBox(const char *title,
 const char *message);

#endif
