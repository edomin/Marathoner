#ifndef MTR_ENGINE_FILE
#define MTR_ENGINE_FILE

#include <stdio.h>

#include "marathoner/engine.h"

void __stdcall mtrFileWriteLine(const char* filename, const char *text,
 uint8_t mode);

#endif
