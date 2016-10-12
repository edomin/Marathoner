#include "directory.h"

mtrDirectory_t *mtrDirectoryOpen(const char *directoryName)
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

bool mtrDirectoryNextFile(mtrDirectory_t *directory)
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

char *mtrDirectoryGetFilename(mtrDirectory_t *directory)
{
    if (directory->endOfDirectory)
        return NULL;
    #ifdef __MINGW32__
    return directory->FindFileData.cFileName;
    #else
    return directory.dir->d_name;
    #endif
}

bool mtrDirectoryFileIsDir(mtrDirectory_t *directory)
{
    char *tempFilename;

    tempFilename = mtrDirectoryGetFilename(directory);
    if (tempFilename == NULL)
        return false;
    if ((strcmp(tempFilename, "..") == 0) ||
      (strcmp(tempFilename, ".") == 0))
        return true;
    else
        return false;
}

void mtrDirectoryClose(mtrDirectory_t *directory)
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
