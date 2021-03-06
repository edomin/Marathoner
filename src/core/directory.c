#include "directory.h"

/*fa MTR_GetCurrentDirectory yes */
char *MTR_CALL MTR_GetCurrentDirectory(void)
{
    #ifdef __MINGW32__
    char *directoryName;
    int directoryNameLength;

    directoryNameLength = GetCurrentDirectory(0, NULL);
    if (directoryNameLength == 0)
        return NULL;
    directoryName = malloc(sizeof(char) * (directoryNameLength + 1));

    if (GetCurrentDirectory(directoryNameLength, directoryName) != 0)
        return directoryName;
    else
        return NULL;
    #endif
    #if defined(__GNUC__) && !defined(__MINGW32__)
    char buffer[4096];
    char *success = NULL;
    char *directoryName = NULL;
    int directoryNameLength;

    success = getcwd(buffer, 4096);
    if (!success)
        return NULL;

    directoryNameLength = strlen(buffer);
    directoryName = malloc(sizeof(char) * (directoryNameLength + 1));
    if (!directoryName)
        return NULL;

    if (!strcpy(directoryName, buffer)) {
        free(directoryName);
        return NULL;
    }

    return directoryName;
    #endif
}

mtrDirectory_t *MTR_DirectoryOpen(const char *directoryName)
{
    mtrDirectory_t *mtrDirectory;

    if (directoryName == NULL)
        return NULL;

    mtrDirectory = malloc(sizeof(mtrDirectory_t));
    if (mtrDirectory == NULL)
        return NULL;

    mtrDirectory->endOfDirectory = false;
    mtrDirectory->d = opendir(directoryName);
    if (mtrDirectory->d == NULL) {
        free(mtrDirectory);
        return NULL;
    }

    return mtrDirectory;
}

bool MTR_DirectoryNextFile(mtrDirectory_t *directory)
{
    directory->dir = readdir(directory->d);
    if (directory->dir == NULL) {
        directory->endOfDirectory = true;
        return false;
    }
    else
        return true;
}

char *MTR_DirectoryGetFilename(mtrDirectory_t *directory)
{
    if (directory->endOfDirectory)
        return NULL;
    return directory->dir->d_name;
}

bool MTR_DirectoryFileIsDir(mtrDirectory_t *directory)
{
    char *tempFilename;

    tempFilename = MTR_DirectoryGetFilename(directory);
    if (tempFilename == NULL)
        return false;
    if ((strcmp(tempFilename, "..") == 0) ||
      (strcmp(tempFilename, ".") == 0))
        return true;
    else
        return false;
}

void MTR_DirectoryClose(mtrDirectory_t *directory)
{
    if (directory != NULL) {
        closedir(directory->d);
        free(directory);
    }
}
