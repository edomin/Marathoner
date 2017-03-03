#ifndef MTR_CORE_CLIPBOARD_H
#define MTR_CORE_CLIPBOARD_H

#include "lazy_winapi.h"

#include "marathoner/engine.h"

bool MTR_CALL mtrClipboardPutText(const char* text);
char *MTR_CALL mtrClipboardGetText(void);

#endif
