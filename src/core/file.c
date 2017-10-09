#include "file.h"

bool MTR_CALL mtrFileInit(uint32_t dmSize, uint32_t reservedCount)
{
    unsigned int i;
    uint64_t     reservedDataCount;
    mtrFile_t   *file;

    mtrLogWrite("Initializing file I/O subsystem", 0, MTR_LMT_INFO);

    mtrFileKeeper = (mtrIndexkeeper_t *)mtrIndexkeeperCreate(dmSize,
     reservedCount, sizeof(mtrFile_t));
    if (mtrFileKeeper == NULL)
    {
        mtrNotify("Unable to initialize file I/O subsystem", 1, MTR_LMT_ERROR);
        return false;
    }
    else
        mtrLogWrite("file I/O subsystem initialized", 0, MTR_LMT_INFO);

    reservedDataCount = mtrIndexkeeperGetReservedDataCount(mtrFileKeeper);
    for (i = 0; i < reservedDataCount; i++)
    {
        file = IK_GET_DATA(mtrFile_t *, mtrFileKeeper, i);
        file->buffer = NULL;
        file->bufLength = 0;
    }

    return true;
}

const char *MTR_CALL mtrFileConstToMode(int mode)
{
    if ((mode >= 0) && (mode < MTR_FM_MAX))
        return mtrFileMode[mode];
    return NULL;
}

/*fa mtrFileOpen yes */
uint32_t MTR_CALL mtrFileOpen(const char *filename, int mode)
{
    uint32_t    freeIndex;
    mtrFile_t  *file;
    const char *openMode;

    if (filename == NULL)
    {
        mtrLogWrite("Unable to open file. Filename is empty", 0, MTR_LMT_ERROR);
        return 0;
    }
    openMode = mtrFileConstToMode(mode);
    if (openMode == NULL)
    {
        mtrLogWrite("Unable to open file. Incorrect file open mode", 0,
         MTR_LMT_ERROR);
        return 0;
    }

    freeIndex = mtrIndexkeeperGetFreeIndex(mtrFileKeeper);
    file = IK_GET_DATA(mtrFile_t *, mtrFileKeeper, freeIndex);
    file->file =  fopen(filename, openMode);
    if (file->file == NULL)
    {
        mtrLogWrite("Unable to open file.", 0, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrFileKeeper, freeIndex);
        return 0;
    }
    return freeIndex;
}

/*fa mtrFileClose yes */
bool MTR_CALL mtrFileClose(uint32_t fileNum)
{
    mtrFile_t *file;
    int        success;

    file = IK_GET_DATA(mtrFile_t *, mtrFileKeeper, fileNum);

    success = fclose(file->file);
    if (success == EOF)
        return false;

    mtrIndexkeeperFreeIndex(mtrFileKeeper, fileNum);
    return true;
}

/*fa mtrFileRead yes */
size_t MTR_CALL mtrFileRead(uint32_t fileNum, char **buffer)
{
    mtrFile_t *file;
    long int   fileSizeResult;
    size_t     fileSize;
    size_t     readedSize;

    file = IK_GET_DATA(mtrFile_t *, mtrFileKeeper, fileNum);

    if (file->buffer != NULL)
    {
        free(file->buffer);
        file->buffer = NULL;
        file->bufLength = 0;
    }

    #ifndef __MINGW32__
    if (__freadable(file->file) == 0)
    {
        *buffer = NULL;
        return 0;
    }
    #endif

    if (fseek(file->file, 0, SEEK_END) != 0)
    {
        *buffer = NULL;
        return 0;
    }

    fileSizeResult = ftell(file->file);
    rewind(file->file);
    if (fileSizeResult == -1L)
    {
        *buffer = NULL;
        return 0;
    }

    fileSize = fileSizeResult;
    file->buffer = malloc(sizeof(char) * (fileSize + 1));
    if (file->buffer == NULL)
    {
        *buffer = NULL;
        return 0;
    }

    readedSize = fread(file->buffer, 1, fileSize, file->file);
    file->buffer[readedSize] = '\0';
    file->bufLength = readedSize;
    *buffer = file->buffer;
    return file->bufLength;
}

/*fa mtrFileWrite yes */
bool MTR_CALL mtrFileWrite(uint32_t fileNum, const char *string)
{
    mtrFile_t *file;

    file = IK_GET_DATA(mtrFile_t *, mtrFileKeeper, fileNum);

    #ifndef __MINGW32__
    if (__fwritable(file->file) == 0)
        return false;
    #endif

    fprintf(file->file, "%s", string);

    return true;
}

/*fa mtrFileWriteLine yes */
bool MTR_CALL mtrFileWriteLine(uint32_t fileNum, const char *string)
{
    mtrFile_t *file;

    file = IK_GET_DATA(mtrFile_t *, mtrFileKeeper, fileNum);

    #ifndef __MINGW32__
    if (__fwritable(file->file) == 0)
        return false;
    #endif

    fprintf(file->file, "%s\n", string);

    return true;
}

/*fa mtrFileWriteFast yes */
void MTR_CALL mtrFileWriteFast(const char* filename, const char *text,
 int mode)
{
    FILE *file;
    if (mode == MTR_FM_WRITE)
        file = fopen(filename, "w");
    else
        file = fopen(filename, "a");
    fprintf(file, "%s\n", text);
    fclose(file);
}

/*fa mtrFileWriteLineFast yes */
void MTR_CALL mtrFileWriteLineFast(const char* filename, const char *text,
 int mode)
{
    FILE *file;
    if (mode == MTR_FM_WRITE)
        file = fopen(filename, "w");
    else
        file = fopen(filename, "a");
    fprintf(file, "%s\n", text);
    fclose(file);
}
