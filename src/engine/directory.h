#ifndef MTR_ENGINE_DIRECTORY
#define MTR_ENGINE_DIRECTORY

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

/* directoryName format: "./<directoryName>/" */
mtrDirectory_t *mtrDirectoryOpen(const char *directoryName);
bool mtrDirectoryNextFile(mtrDirectory_t *directory);
char *mtrDirectoryGetFilename(mtrDirectory_t *directory);
bool mtrDirectoryFileIsDir(mtrDirectory_t *directory);
void mtrDirectoryClose(mtrDirectory_t *directory);

#endif
