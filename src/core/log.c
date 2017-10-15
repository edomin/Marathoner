#include "log.h"

int mtrLogPrintfCommon(char *format, ...)
{
    va_list aptr;
    int     ret;

    va_start(aptr, format);
    ret = vsprintf(mtrLogBuffer, format, aptr);
    va_end(aptr);

    fprintf(mtrLogFile, "%s", mtrLogBuffer);
    mtrConsolePrint(mtrLogBuffer);

    return ret;
}

void mtrLogWriteMeta(uint8_t messageType, uint8_t level)
{
    uint8_t i;

    time(&mtrCurrentTime);
    mtrNow = localtime(&mtrCurrentTime);
    #ifdef __MINGW32__
    mtrLogFile = fopen(logFilename, "a");
    #endif
    mtrLogPrintfCommon("[%i-%i-%i %i:%i:%i] ",
     mtrNow->tm_year + 1900, mtrNow->tm_mon + 1, mtrNow->tm_mday,
     mtrNow->tm_hour, mtrNow->tm_min, mtrNow->tm_sec);
    switch (messageType)
    {
        case MTR_LMT_INFO:
            mtrLogPrintfCommon("%s", "   Info: ");
            break;
        case MTR_LMT_NOTE:
            mtrLogPrintfCommon("%s", "   Note: ");
            break;
        case MTR_LMT_WARNING:
            mtrLogPrintfCommon("%s", "Warning: ");
            break;
        case MTR_LMT_ERROR:
            mtrLogPrintfCommon("%s", "  Error: ");
            break;
        case MTR_LMT_FATAL:
            mtrLogPrintfCommon("%s", "  Fatal: ");
            break;
        case MTR_LMT_DEBUG:
        default:
            mtrLogPrintfCommon("%s", "  Debug: ");
            break;
    }
    for (i = 0; i < level; i++)
        mtrLogPrintfCommon("%s", "-- ");
}

void MTR_CALL mtrLogInit(const char *filename)
{
    logFilename = filename;
    time(&mtrCurrentTime);
    mtrNow = localtime(&mtrCurrentTime);
    #ifdef __MINGW32__
    mtrLogFile = fopen(logFilename, "w");
    #endif
    mtrLogPrintfCommon("[%i-%i-%i %i:%i:%i]          Begin Logging.\n",
     mtrNow->tm_year + 1900, mtrNow->tm_mon + 1, mtrNow->tm_mday,
     mtrNow->tm_hour, mtrNow->tm_min, mtrNow->tm_sec);
    #ifdef __MINGW32__
    fclose(mtrLogFile);
    #endif
}

/*fa mtrLogWrite yes */
void MTR_CALL mtrLogWrite(const char *message, uint8_t level,
 uint8_t messageType)
{
    mtrLogWriteMeta(messageType, level);
    mtrLogPrintfCommon("%s\n", message);
    #ifdef __MINGW32__
    fclose(mtrLogFile);
    #endif
}

/*fa mtrLogWrite_s yes */
void MTR_CALL mtrLogWrite_s(const char *message, uint8_t level,
 uint8_t messageType, const char * argument)
{
    mtrLogWriteMeta(messageType, level);
    mtrLogPrintfCommon("%s %s\n", message, argument);
    #ifdef __MINGW32__
    fclose(mtrLogFile);
    #endif
}

/*fa mtrLogWrite_i yes */
void MTR_CALL mtrLogWrite_i(const char *message, uint8_t level,
 uint8_t messageType, int32_t argument)
{
    mtrLogWriteMeta(messageType, level);
    mtrLogPrintfCommon("%s %i\n", message, argument);
    #ifdef __MINGW32__
    fclose(mtrLogFile);
    #endif
}

/*fa mtrLogWrite_d yes */
void MTR_CALL mtrLogWrite_d(const char *message, uint8_t level,
 uint8_t messageType, double argument)
{
    mtrLogWriteMeta(messageType, level);
    mtrLogPrintfCommon("%s %f\n", message, argument);
    #ifdef __MINGW32__
    fclose(mtrLogFile);
    #endif
}
