#include "pak.h"

#ifdef MTR_MOD_PLUGIN
#include "marathoner/plugin_common.c"

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "PAK_PhysFS";
    report->version = MTR_VERSION_PAK_PHYSFS;
    report->subsystem = "pak";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}
#endif

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Pak, FA_FUNCTIONS_COUNT)

void MTR_PakWritePhysFsError(int logLevel)
{
    PHYSFS_ErrorCode errorcode;
    const char      *errorText;

    errorcode = PHYSFS_getLastErrorCode();
    errorText = PHYSFS_getErrorByCode(errorcode);
    if (errorText == NULL)
        MTR_LogWrite("Unknown PhysFS error", logLevel, MTR_LMT_ERROR);
    else
        MTR_LogWrite(errorText, logLevel, MTR_LMT_ERROR);
}

/*fa MTR_PakInit yes */
MTR_DCLSPC bool MTR_CALL MTR_PakInit(void)
{
    PHYSFS_Version             compiled;
    PHYSFS_Version             linked;
    char                      *fakeArgv0 = NULL;
    char                      *currentDirectory;
    size_t                     currentDirectoryLen;
    bool                       nullArgv0 = false;
    const PHYSFS_ArchiveInfo **supportedArchives;
    int                        i;

    MTR_LogWrite("Initializing PAK i/o", 0, MTR_LMT_INFO);

    PHYSFS_VERSION(&compiled);
    MTR_LogWrite("Reporting PhysFS compile-time version:", 1, MTR_LMT_INFO);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, compiled.major);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, compiled.minor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, compiled.patch);
    MTR_LogWrite("Reporting PhysFS linked version:", 1, MTR_LMT_INFO);
    PHYSFS_getLinkedVersion(&linked);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, linked.major);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, linked.minor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, linked.patch);

    currentDirectory = MTR_GetCurrentDirectory();
    if (currentDirectory == NULL) {
        MTR_LogWrite("Unable to get current directory", 1, MTR_LMT_ERROR);
        nullArgv0 = true;
    } else {
        currentDirectoryLen = strlen(currentDirectory);
        fakeArgv0 = malloc(sizeof(char) * (currentDirectoryLen + 10));
        if (fakeArgv0 == NULL) {
            MTR_LogWrite("Unable to allocate memory for fake argv[0]", 1,
             MTR_LMT_ERROR);
            nullArgv0 = true;
        } else {
            fakeArgv0 = strcpy(fakeArgv0, currentDirectory);
            if (fakeArgv0 == NULL) {
                MTR_LogWrite("Unable to copy current directory to fake argv[0]", 1,
                 MTR_LMT_ERROR);
                free(fakeArgv0);
                fakeArgv0 = NULL;
                nullArgv0 = true;
            } else
                strcat(fakeArgv0, "/fake.exe");
        }
    }
    if (nullArgv0)
        MTR_LogWrite("Trying to initialize PhysFS without argv[0]", 1,
         MTR_LMT_INFO);

    if (PHYSFS_init(fakeArgv0) == 0) {
        MTR_LogWrite("Unable to initialize PhysFS", 1, MTR_LMT_ERROR);
        MTR_PakWritePhysFsError(1);

        MTR_LogWrite("PAK i/o not initialized", 0, MTR_LMT_WARNING);
        mtrPakInited = false;
        return false;
    }

    MTR_LogWrite("Reporting supported archive types:", 1, MTR_LMT_INFO);
    supportedArchives = PHYSFS_supportedArchiveTypes();

    i = 0;
    while (supportedArchives[i] != NULL) {
        MTR_LogWrite_s(supportedArchives[i]->extension, 1, MTR_LMT_INFO,
         supportedArchives[i]->description);
        i++;
    }

    MTR_LogWrite("PAK i/o initialized", 0, MTR_LMT_INFO);
    mtrPakInited = true;
    return true;
}

/*fa MTR_PakMount yes */
MTR_DCLSPC bool MTR_CALL MTR_PakMount(const char *filename,
 const char *mountPoint)
{
    MTR_PAK_CHECK_IF_NOT_INITED_WITH_LOG("Unable to mount file", false);

    MTR_LogWrite_s("Mounting file", 0, MTR_LMT_INFO, filename);
    if (PHYSFS_mount(filename, mountPoint, true) == 0) {
        MTR_LogWrite("Unable to mount file", 1, MTR_LMT_ERROR);

        MTR_PakWritePhysFsError(1);

        return false;
    }
    MTR_LogWrite_s("Mounted to:", 0, MTR_LMT_INFO, mountPoint);

    return true;
}

/*fa MTR_PakUnmount yes */
MTR_DCLSPC bool MTR_CALL MTR_PakUnmount(const char *filename)
{
    MTR_PAK_CHECK_IF_NOT_INITED_WITH_LOG("Unable to mount file", false);

    MTR_LogWrite_s("Unmounting file", 0, MTR_LMT_INFO, filename);
    if (PHYSFS_unmount(filename) == 0) {
        MTR_LogWrite("Unable to unmount file", 1, MTR_LMT_ERROR);

        MTR_PakWritePhysFsError(1);

        return false;
    }
    MTR_LogWrite("File unmounted", 0, MTR_LMT_INFO);

    return true;
}

/*fa MTR_PakQuit yes */
MTR_DCLSPC bool MTR_CALL MTR_PakQuit(void)
{
    MTR_PAK_CHECK_IF_NOT_INITED_WITH_LOG("Unable to quit PAK i/o", false);

    MTR_LogWrite("Quiting PAK i/o", 0, MTR_LMT_INFO);

    if (PHYSFS_deinit()) {
        MTR_LogWrite("PAK i/o quited", 0, MTR_LMT_INFO);
        return true;
    }

    MTR_LogWrite("Unable to deinit PhysFS", 1, MTR_LMT_ERROR);
    MTR_PakWritePhysFsError(1);

    MTR_LogWrite("PAK i/o not quited", 0, MTR_LMT_WARNING);
    return false;
}

MTR_DCLSPC void *MTR_CALL MTR_PakOpenDir(const char *path)
{
    MTR_PAK_CHECK_IF_NOT_INITED(NULL);

    mtrPak.currentFile = 0;

    return PHYSFS_enumerateFiles(path);
}

MTR_DCLSPC void *MTR_CALL MTR_PakReadDir(void *directory)
{
    MTR_PAK_CHECK_IF_NOT_INITED(NULL);

    mtrPak.currentFilename = ((char **)directory)[mtrPak.currentFile];
    if (mtrPak.currentFilename != NULL)
        mtrPak.currentFile++;

    return mtrPak.currentFilename;
}

MTR_DCLSPC int MTR_CALL MTR_PakCloseDir(void *directory)
{
    MTR_PAK_CHECK_IF_NOT_INITED(-1);

    PHYSFS_freeList(directory);
    return 0;
}

MTR_DCLSPC char *MTR_CALL MTR_PakGetFilename(void *file)
{
    MTR_PAK_CHECK_IF_NOT_INITED(NULL);

    return (char *)file;
}

MTR_DCLSPC bool MTR_CALL MTR_PakFileExists(const char *filename)
{
    MTR_PAK_CHECK_IF_NOT_INITED(false);

    return PHYSFS_exists(filename);
}

FILE *MTR_STDCALL MTR_PakFopen(const char *filename, const char *mode)
{
    MTR_PAK_CHECK_IF_NOT_INITED(NULL);

    if (strcmp(mode, "r") == 0) {
        return (FILE *)PHYSFS_openRead(filename);
    } else if (strcmp(mode, "rb") == 0) {
        return (FILE *)PHYSFS_openRead(filename);
    } else if (strcmp(mode, "w") == 0) {
        return (FILE *)PHYSFS_openWrite(filename);
    } else if (strcmp(mode, "wb") == 0) {
        return (FILE *)PHYSFS_openWrite(filename);
    } else if (strcmp(mode, "a") == 0) {
        return (FILE *)PHYSFS_openAppend(filename);
    } else if (strcmp(mode, "ab") == 0) {
        return (FILE *)PHYSFS_openAppend(filename);
    }
    return NULL;
}

int MTR_STDCALL MTR_PakFclose(FILE *file)
{
    MTR_PAK_CHECK_IF_NOT_INITED(EOF);

    if (PHYSFS_close((PHYSFS_File *)file) != 0)
        return 0;
    else
        return EOF;
}

int MTR_STDCALL MTR_PakFeof(FILE *file)
{
    MTR_PAK_CHECK_IF_NOT_INITED(1);

    if (PHYSFS_eof((PHYSFS_File *)file) != 0)
        return 1;
    else
        return 0;
}

long int MTR_STDCALL MTR_PakFtell(FILE *file)
{
    MTR_PAK_CHECK_IF_NOT_INITED(-1L);

    return PHYSFS_tell((PHYSFS_File *)file);
}

int MTR_STDCALL MTR_PakFseek(FILE *file, long int offset, int origin)
{
    bool success;
    MTR_PAK_CHECK_IF_NOT_INITED(-1);

    switch (origin) {
        case SEEK_SET:
            success = PHYSFS_seek((PHYSFS_File *)file, offset);
            break;
        case SEEK_CUR:
            success = PHYSFS_seek((PHYSFS_File *)file,
             PHYSFS_tell((PHYSFS_File *)file) + offset);
            break;
        case SEEK_END:
            success = PHYSFS_seek((PHYSFS_File *)file,
             PHYSFS_fileLength((PHYSFS_File *)file) - 1 + offset);
            break;
        default:
            success = false;
            break;
    }

    if (success)
        return 0;
    else
        return -1;
}

size_t MTR_STDCALL MTR_PakFread(void *ptr, size_t size, size_t count,
 FILE *file)
{
    MTR_PAK_CHECK_IF_NOT_INITED(0UL);

    return PHYSFS_readBytes((PHYSFS_File *)file, ptr, size * count) / size;
}

size_t MTR_STDCALL MTR_PakFwrite(const void *ptr, size_t size, size_t count,
 FILE *file)
{
    MTR_PAK_CHECK_IF_NOT_INITED(0UL);

    return PHYSFS_writeBytes((PHYSFS_File *)file, ptr, size * count) / size;
}

/*fa MTR_PakGetFopen yes */
MTR_DCLSPC MTR_FopenFunc MTR_CALL MTR_PakGetFopen(void)
{
    MTR_PAK_CHECK_IF_NOT_INITED(NULL);

    return MTR_PakFopen;
}

/*fa MTR_PakGetFclose yes */
MTR_DCLSPC MTR_FcloseFunc MTR_CALL MTR_PakGetFclose(void)
{
    MTR_PAK_CHECK_IF_NOT_INITED(NULL);

    return MTR_PakFclose;
}

/*fa MTR_PakGetFeof yes */
MTR_DCLSPC MTR_FeofFunc MTR_CALL MTR_PakGetFeof(void)
{
    MTR_PAK_CHECK_IF_NOT_INITED(NULL);

    return MTR_PakFeof;
}

/*fa MTR_PakGetFtell yes */
MTR_DCLSPC MTR_FtellFunc MTR_CALL MTR_PakGetFtell(void)
{
    MTR_PAK_CHECK_IF_NOT_INITED(NULL);

    return MTR_PakFtell;
}

/*fa MTR_PakGetFseek yes */
MTR_DCLSPC MTR_FseekFunc MTR_CALL MTR_PakGetFseek(void)
{
    MTR_PAK_CHECK_IF_NOT_INITED(NULL);

    return MTR_PakFseek;
}

/*fa MTR_PakGetFread yes */
MTR_DCLSPC MTR_FreadFunc MTR_CALL MTR_PakGetFread(void)
{
    MTR_PAK_CHECK_IF_NOT_INITED(NULL);

    return MTR_PakFread;
}

/*fa MTR_PakGetFwrite yes */
MTR_DCLSPC MTR_FwriteFunc MTR_CALL MTR_PakGetFwrite(void)
{
    MTR_PAK_CHECK_IF_NOT_INITED(NULL);

    return MTR_PakFwrite;
}
