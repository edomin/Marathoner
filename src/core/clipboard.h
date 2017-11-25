#ifndef MTR_CORE_CLIPBOARD_H
#define MTR_CORE_CLIPBOARD_H

#ifdef __MINGW32__
    #include "lazy_winapi.h"
#endif

#include "marathoner/engine.h"

bool MTR_CALL MTR_ClipboardPutText(const char* text);
char *MTR_CALL MTR_ClipboardGetText(void);

#endif
