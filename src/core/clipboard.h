#ifndef MTR_CORE_CLIPBOARD_H
#define MTR_CORE_CLIPBOARD_H

#include "lazy_winapi.h"

#include "marathoner/engine.h"

bool MTR_CALL MTR_ClipboardPutText(const char* text);
char *MTR_CALL MTR_ClipboardGetText(void);

#endif
