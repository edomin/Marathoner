#include "directory.h"

/* Win32 only */
/*fa MTR_GetCurrentDirectory yes */
char *MTR_CALL MTR_GetCurrentDirectory(void)
{
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
}

mtrDirectory_t *MTR_DirectoryOpen(const char *directoryName)
{
    mtrDirectory_t *mtrDirectory;
    #ifdef __MINGW32__
    char *dirTempName;
    #else

    #endif

    if (directoryName == NULL)
        return NULL;

    mtrDirectory = malloc(sizeof(mtrDirectory_t));
    if (mtrDirectory == NULL)
        return NULL;

    mtrDirectory->endOfDirectory = false;
    #ifdef __MINGW32__
    dirTempName = malloc(strlen(directoryName) + 1);
    if (dirTempName == NULL)
    {
        free(mtrDirectory);
        return NULL;
    }
    strcpy(dirTempName, directoryName);
    strcat(dirTempName, "*");

    mtrDirectory->hf = FindFirstFile(dirTempName, &mtrDirectory->FindFileData);
    free(dirTempName);
    if(mtrDirectory->hf == INVALID_HANDLE_VALUE)
    {
        free(mtrDirectory);
        return NULL;
    }
    mtrDirectory->firstFile = true;
    #else
    mtrDirectory.d = opendir(directoryName);
    if (mtrDirectory.d == NULL)
    {
        free(mtrDirectory);
        return NULL;
    }
    #endif

    return mtrDirectory;
}

bool MTR_DirectoryNextFile(mtrDirectory_t *directory)
{
    #ifdef __MINGW32__
    if (directory->firstFile)
    {
        directory->firstFile = false;
        return true;
    }
    else
        if (FindNextFile(directory->hf, &directory->FindFileData) == 0)
        {
            directory->endOfDirectory = true;
            return false;
        }
        else
            return true;
    #else
    directory.dir = readdir(directory.d);
    if (directory.dir == NULL)
    {
        directory->endOfDirectory = true;
        return false;
    }
    else
        return true;
    #endif
}

char *MTR_DirectoryGetFilename(mtrDirectory_t *directory)
{
    if (directory->endOfDirectory)
        return NULL;
    #ifdef __MINGW32__
    return directory->FindFileData.cFileName;
    #else
    return directory.dir->d_name;
    #endif
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
    if (directory != NULL)
    {
        #ifdef __MINGW32__
        FindClose(directory->hf);
        #else
        closedir(directory.d);
        #endif
        free(directory);
    }
}
