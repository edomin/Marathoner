#ifndef MTR_CORE_FILE_H
#define MTR_CORE_FILE_H

#include "marathoner/marathoner.h"

#include <stdio.h>
#ifndef __MINGW32__
    #include <stdio_ext.h>
#endif

#include "marathoner/engine.h"

#include "indexkeeper.h"

typedef struct mtrFile_t {
    FILE  *file;
    char  *buffer;
    size_t bufLength;
} mtrFile_t;

static const char *mtrFileMode[] __attribute__((used)) = {"r", "w", "a"};

mtrIndexkeeper_t *mtrFileKeeper;

bool MTR_CALL mtrFileInit(uint32_t dmSize, uint32_t reservedCount);
uint32_t MTR_CALL mtrFileOpen(const char *filename, int mode);
bool MTR_CALL mtrFileClose(uint32_t fileNum);
size_t MTR_CALL mtrFileRead(uint32_t fileNum, char **buffer);
bool MTR_CALL mtrFileWrite(uint32_t fileNum, const char *string);
bool MTR_CALL mtrFileWriteLine(uint32_t fileNum, const char *string);
void MTR_CALL mtrFileWriteFast(const char* filename, const char *text,
 int mode);
void MTR_CALL mtrFileWriteLineFast(const char* filename, const char *text,
 int mode);

#endif
