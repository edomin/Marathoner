#ifndef MTR_CORE_CLIPBOARD_H
#define MTR_CORE_CLIPBOARD_H

#include "libclipboard.h"

#include "marathoner/engine.h"

static bool clipboardInitialized __attribute__((used)) = false;
clipboard_c *clipboard;

bool MTR_CALL MTR_ClipboardPutText(const char* text);
char *MTR_CALL MTR_ClipboardGetText(void);

#endif
