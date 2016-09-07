#ifndef MTR_ENGINE_FILE
#define MTR_ENGINE_FILE

#include "marathoner/marathoner.h"

#include <stdio.h>

#include "marathoner/engine.h"

void MRT_CALL mtrFileWriteLine(const char* filename, const char *text,
 uint8_t mode);

#endif
