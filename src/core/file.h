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

bool MTR_CALL MTR_FileInit(uint32_t dmSize, uint32_t reservedCount);
uint32_t MTR_CALL MTR_FileOpen(const char *filename, int mode);
bool MTR_CALL MTR_FileClose(uint32_t fileNum);
size_t MTR_CALL MTR_FileRead(uint32_t fileNum, char **buffer);
bool MTR_CALL MTR_FileWrite(uint32_t fileNum, const char *string);
bool MTR_CALL MTR_FileWriteLine(uint32_t fileNum, const char *string);
void MTR_CALL MTR_FileWriteFast(const char* filename, const char *text,
 int mode);
void MTR_CALL MTR_FileWriteLineFast(const char* filename, const char *text,
 int mode);
bool MTR_CALL MTR_FileExists(const char* filename);
MTR_FopenFunc MTR_CALL MTR_FileGetStdFopen(void);
MTR_FcloseFunc MTR_CALL MTR_FileGetStdFclose(void);
MTR_FeofFunc MTR_CALL MTR_FileGetStdFeof(void);
MTR_FtellFunc MTR_CALL MTR_FileGetStdFtell(void);
MTR_FseekFunc MTR_CALL MTR_FileGetStdFseek(void);
MTR_RewindFunc MTR_CALL MTR_FileGetStdRewind(void);
MTR_FreadFunc MTR_CALL MTR_FileGetStdFread(void);
MTR_FwriteFunc MTR_CALL MTR_FileGetStdFwrite(void);
MTR_FprintfFunc MTR_CALL MTR_FileGetStdFprintf(void);
MTR_FreadableFunc MTR_CALL MTR_FileGetStdFreadable(void);
MTR_FwritableFunc MTR_CALL MTR_FileGetStdFwritable(void);

#endif
