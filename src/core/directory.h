#ifndef MTR_CORE_DIRECTORY_H
#define MTR_CORE_DIRECTORY_H

#include <dirent.h>
#include <string.h>
#if defined(__GNUC__) && !defined(__MINGW32__)
    #include <unistd.h>
#endif

#include "marathoner/engine.h"

typedef struct mtrDirectory_t{
    DIR            *d;
    struct dirent  *dir;
    bool            endOfDirectory;
} mtrDirectory_t;

char *MTR_CALL MTR_GetCurrentDirectory(void);
/* directoryName format: "./<directoryName>/" */
mtrDirectory_t *MTR_DirectoryOpen(const char *directoryName);
bool MTR_DirectoryNextFile(mtrDirectory_t *directory);
char *MTR_DirectoryGetFilename(mtrDirectory_t *directory);
bool MTR_DirectoryFileIsDir(mtrDirectory_t *directory);
void MTR_DirectoryClose(mtrDirectory_t *directory);

#endif
