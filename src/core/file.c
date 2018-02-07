#include "file.h"

bool MTR_CALL MTR_FileInit(uint32_t dmSize, uint32_t reservedCount)
{
    unsigned int i;
    uint64_t     reservedDataCount;
    mtrFile_t   *file;

    MTR_LogWrite("Initializing file I/O subsystem", 0, MTR_LMT_INFO);

    mtrFileKeeper = (mtrIndexkeeper_t *)MTR_IndexkeeperCreate(dmSize,
     reservedCount, sizeof(mtrFile_t));
    if (mtrFileKeeper == NULL)
    {
        MTR_Notify("Unable to initialize file I/O subsystem", 1, MTR_LMT_ERROR);
        return false;
    }
    else
        MTR_LogWrite("file I/O subsystem initialized", 0, MTR_LMT_INFO);

    reservedDataCount = MTR_IndexkeeperGetReservedDataCount(mtrFileKeeper);
    for (i = 0; i < reservedDataCount; i++)
    {
        file = IK_GET_DATA(mtrFile_t *, mtrFileKeeper, i);
        file->buffer = NULL;
        file->bufLength = 0;
    }

    MTR_FileStdio.Fopen = MTR_FileGetStdFopen();
    MTR_FileStdio.Fclose = MTR_FileGetStdFclose();
    MTR_FileStdio.Feof = MTR_FileGetStdFeof();
    MTR_FileStdio.Ftell = MTR_FileGetStdFtell();
    MTR_FileStdio.Fseek = MTR_FileGetStdFseek();
    MTR_FileStdio.Rewind = MTR_FileGetStdRewind();
    MTR_FileStdio.Fread = MTR_FileGetStdFread();
    MTR_FileStdio.Fwrite = MTR_FileGetStdFwrite();
    MTR_FileStdio.Fprintf = MTR_FileGetStdFprintf();

    MTR_FileStdioExt.Freadable = MTR_FileGetStdFreadable();
    MTR_FileStdioExt.Fwritable = MTR_FileGetStdFwritable();

    return true;
}

const char *MTR_CALL MTR_FileConstToMode(int mode)
{
    if ((mode >= 0) && (mode < MTR_FM_MAX))
        return mtrFileMode[mode];
    return NULL;
}

/*fa MTR_FileOpen yes */
uint32_t MTR_CALL MTR_FileOpen(const char *filename, int mode)
{
    uint32_t    freeIndex;
    mtrFile_t  *file;
    const char *openMode;

    if (filename == NULL)
    {
        MTR_LogWrite("Unable to open file. Filename is empty", 0,
         MTR_LMT_ERROR);
        return 0;
    }
    openMode = MTR_FileConstToMode(mode);
    if (openMode == NULL)
    {
        MTR_LogWrite("Unable to open file. Incorrect file open mode", 0,
         MTR_LMT_ERROR);
        return 0;
    }

    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrFileKeeper);
    file = IK_GET_DATA(mtrFile_t *, mtrFileKeeper, freeIndex);
    file->file =  MTR_FileStdio.Fopen(filename, openMode);
    if (file->file == NULL)
    {
        MTR_LogWrite("Unable to open file.", 0, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrFileKeeper, freeIndex);
        return 0;
    }
    return freeIndex;
}

/*fa MTR_FileClose yes */
bool MTR_CALL MTR_FileClose(uint32_t fileNum)
{
    mtrFile_t *file;
    int        success;

    file = IK_GET_DATA(mtrFile_t *, mtrFileKeeper, fileNum);

    success = MTR_FileStdio.Fclose(file->file);
    if (success == EOF)
        return false;

    MTR_IndexkeeperFreeIndex(mtrFileKeeper, fileNum);
    return true;
}

/*fa MTR_FileRead yes */
size_t MTR_CALL MTR_FileRead(uint32_t fileNum, char **buffer)
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

//    #ifndef __MINGW32__
    if (MTR_FileStdioExt.Freadable(file->file) == 0)
    {
        *buffer = NULL;
        return 0;
    }
//    #endif

    if (MTR_FileStdio.Fseek(file->file, 0, SEEK_END) != 0)
    {
        *buffer = NULL;
        return 0;
    }

    fileSizeResult = MTR_FileStdio.Ftell(file->file);
    MTR_FileStdio.Rewind(file->file);
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

    readedSize = MTR_FileStdio.Fread(file->buffer, 1, fileSize, file->file);
    file->buffer[readedSize] = '\0';
    file->bufLength = readedSize;
    *buffer = file->buffer;
    return file->bufLength;
}

/*fa MTR_FileWrite yes */
bool MTR_CALL MTR_FileWrite(uint32_t fileNum, const char *string)
{
    mtrFile_t *file;

    file = IK_GET_DATA(mtrFile_t *, mtrFileKeeper, fileNum);

//    #ifndef __MINGW32__
    if (MTR_FileStdioExt.Fwritable(file->file) == 0)
        return false;
//    #endif

    MTR_FileStdio.Fprintf(file->file, "%s", string);

    return true;
}

/*fa MTR_FileWriteLine yes */
bool MTR_CALL MTR_FileWriteLine(uint32_t fileNum, const char *string)
{
    mtrFile_t *file;

    file = IK_GET_DATA(mtrFile_t *, mtrFileKeeper, fileNum);

//    #ifndef __MINGW32__
    if (MTR_FileStdioExt.Fwritable(file->file) == 0)
        return false;
//    #endif

    MTR_FileStdio.Fprintf(file->file, "%s\n", string);

    return true;
}

/*fa MTR_FileWriteFast yes */
void MTR_CALL MTR_FileWriteFast(const char* filename, const char *text,
 int mode)
{
    FILE *file;
    if (mode == MTR_FM_WRITE)
        file = MTR_FileStdio.Fopen(filename, "w");
    else
        file = MTR_FileStdio.Fopen(filename, "a");
    MTR_FileStdio.Fprintf(file, "%s\n", text);
    MTR_FileStdio.Fclose(file);
}

/*fa MTR_FileWriteLineFast yes */
void MTR_CALL MTR_FileWriteLineFast(const char* filename, const char *text,
 int mode)
{
    FILE *file;
    if (mode == MTR_FM_WRITE)
        file = MTR_FileStdio.Fopen(filename, "w");
    else
        file = MTR_FileStdio.Fopen(filename, "a");
    MTR_FileStdio.Fprintf(file, "%s\n", text);
    MTR_FileStdio.Fclose(file);
}

/*fa MTR_FileExists yes */
bool MTR_CALL MTR_FileExists(const char* filename)
{
    if (access(filename, F_OK) != -1)
        return true;
    else
        return false;
}

/*fa MTR_FileGetStdFopen yes */
MTR_FopenFunc MTR_CALL MTR_FileGetStdFopen(void)
{
    return fopen;
}

/*fa MTR_FileGetStdFclose yes */
MTR_FcloseFunc MTR_CALL MTR_FileGetStdFclose(void)
{
    return fclose;
}

/*fa MTR_FileGetStdFeof yes */
MTR_FeofFunc MTR_CALL MTR_FileGetStdFeof(void)
{
    return feof;
}

/*fa MTR_FileGetStdFtell yes */
MTR_FtellFunc MTR_CALL MTR_FileGetStdFtell(void)
{
    return ftell;
}

/*fa MTR_FileGetStdFseek yes */
MTR_FseekFunc MTR_CALL MTR_FileGetStdFseek(void)
{
    return fseek;
}

/*fa MTR_FileGetStdRewind yes */
MTR_RewindFunc MTR_CALL MTR_FileGetStdRewind(void)
{
    return rewind;
}

/*fa MTR_FileGetStdFread yes */
MTR_FreadFunc MTR_CALL MTR_FileGetStdFread(void)
{
    return fread;
}

/*fa MTR_FileGetStdFwrite yes */
MTR_FwriteFunc MTR_CALL MTR_FileGetStdFwrite(void)
{
    return fwrite;
}

/*fa MTR_FileGetStdFprintf yes */
MTR_FprintfFunc MTR_CALL MTR_FileGetStdFprintf(void)
{
    return fprintf;
}

/*fa MTR_FileGetStdFreadable yes */
MTR_FreadableFunc MTR_CALL MTR_FileGetStdFreadable(void)
{
    return __freadable;
}

/*fa MTR_FileGetStdFwritable yes */
MTR_FwritableFunc MTR_CALL MTR_FileGetStdFwritable(void)
{
    return __fwritable;
}

/*fa MTR_FileSetStdioFuncs yes */
bool MTR_CALL MTR_FileSetStdioFuncs(MTR_FopenFunc fopenFunc,
 MTR_FcloseFunc fcloseFunc, MTR_FeofFunc feofFunc, MTR_FtellFunc ftellFunc,
 MTR_FseekFunc fseekFunc, MTR_RewindFunc rewindFunc, MTR_FreadFunc freadFunc,
 MTR_FwriteFunc fwriteFunc, MTR_FprintfFunc fprintfFunc)
{
    if ((fopenFunc == NULL) || (fcloseFunc == NULL) || (feofFunc == NULL) ||
     (ftellFunc == NULL) || (fseekFunc == NULL) || (rewindFunc == NULL) ||
     (freadFunc == NULL) || (fwriteFunc == NULL) || (fprintfFunc == NULL)) {
        MTR_LogWrite(
         "Unable to set Stdio funcs. All function pointers must be non NULL", 0,
         MTR_LMT_ERROR);
         return false;
    }
    MTR_FileStdio.Fopen = fopenFunc;
    MTR_FileStdio.Fclose = fcloseFunc;
    MTR_FileStdio.Feof = feofFunc;
    MTR_FileStdio.Ftell = ftellFunc;
    MTR_FileStdio.Fseek = fseekFunc;
    MTR_FileStdio.Rewind = rewindFunc;
    MTR_FileStdio.Fread = freadFunc;
    MTR_FileStdio.Fwrite = fwriteFunc;
    MTR_FileStdio.Fprintf = fprintfFunc;

    return true;
}

/*fa MTR_FileSetStdioExtFuncs yes */
bool MTR_CALL MTR_FileSetStdioExtFuncs(MTR_FreadableFunc freadableFunc,
 MTR_FwritableFunc fwritableFunc)
{
    if ((freadableFunc == NULL) || (fwritableFunc == NULL)) {
        MTR_LogWrite(
         "Unable to set StdioExt funcs. All function pointers must be non NULL",
         0, MTR_LMT_ERROR);
         return false;
    }
    MTR_FileStdioExt.Freadable = freadableFunc;
    MTR_FileStdioExt.Fwritable = fwritableFunc;

    return true;
}

#ifdef __MINGW32__
MTR_STDCALL int __freadable(FILE *stream)
{
    if (stream != NULL)
        return -1;
    else
        return 0;
}

MTR_STDCALL int __fwritable(FILE *stream)
{
    if (stream != NULL)
        return -1;
    else
        return 0;
}
#endif
