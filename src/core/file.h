#ifndef MTR_ENGINE_FILE_H
#define MTR_ENGINE_FILE_H

#include "marathoner/marathoner.h"

#include <stdio.h>

#include "marathoner/engine.h"

void MTR_CALL mtrFileWriteLine(const char* filename, const char *text,
 int mode);

#endif
