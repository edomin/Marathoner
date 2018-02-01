#ifndef MTR_CORE_DIRECTORY_H
#define MTR_CORE_DIRECTORY_H

#ifdef __MINGW32__
    #include <windows.h>
#else
    #include <dirent.h>
#endif
#include <string.h>

#include "marathoner/engine.h"

typedef struct mtrDirectory_t{
    #ifdef __MINGW32__
    WIN32_FIND_DATA FindFileData;
    HANDLE          hf;
    bool            firstFile;
    #else
    DIR            *d;
    struct dirent  *dir;
    #endif
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
