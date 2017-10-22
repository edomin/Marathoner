#include "log.h"

int MTR_LogPrintfCommon(char *format, ...)
{
    va_list aptr;
    int     ret;

    va_start(aptr, format);
    ret = vsprintf(mtrLogBuffer, format, aptr);
    va_end(aptr);

    fprintf(mtrLogFile, "%s", mtrLogBuffer);
    MTR_ConsolePrint(mtrLogBuffer);

    return ret;
}

void MTR_LogWriteMeta(uint8_t messageType, uint8_t level)
{
    uint8_t i;

    time(&mtrCurrentTime);
    mtrNow = localtime(&mtrCurrentTime);
    #ifdef __MINGW32__
    mtrLogFile = fopen(logFilename, "a");
    #endif
    MTR_LogPrintfCommon("[%i-%i-%i %i:%i:%i] ",
     mtrNow->tm_year + 1900, mtrNow->tm_mon + 1, mtrNow->tm_mday,
     mtrNow->tm_hour, mtrNow->tm_min, mtrNow->tm_sec);
    switch (messageType)
    {
        case MTR_LMT_INFO:
            MTR_LogPrintfCommon("%s", "   Info: ");
            break;
        case MTR_LMT_NOTE:
            MTR_LogPrintfCommon("%s", "   Note: ");
            break;
        case MTR_LMT_WARNING:
            MTR_LogPrintfCommon("%s", "Warning: ");
            break;
        case MTR_LMT_ERROR:
            MTR_LogPrintfCommon("%s", "  Error: ");
            break;
        case MTR_LMT_FATAL:
            MTR_LogPrintfCommon("%s", "  Fatal: ");
            break;
        case MTR_LMT_DEBUG:
        default:
            MTR_LogPrintfCommon("%s", "  Debug: ");
            break;
    }
    for (i = 0; i < level; i++)
        MTR_LogPrintfCommon("%s", "-- ");
}

void MTR_CALL MTR_LogInit(const char *filename)
{
    logFilename = filename;
    time(&mtrCurrentTime);
    mtrNow = localtime(&mtrCurrentTime);
    #ifdef __MINGW32__
    mtrLogFile = fopen(logFilename, "w");
    #endif
    MTR_LogPrintfCommon("[%i-%i-%i %i:%i:%i]          Begin Logging.\n",
     mtrNow->tm_year + 1900, mtrNow->tm_mon + 1, mtrNow->tm_mday,
     mtrNow->tm_hour, mtrNow->tm_min, mtrNow->tm_sec);
    #ifdef __MINGW32__
    fclose(mtrLogFile);
    #endif
}

void MTR_CALL MTR_LogWrite(const char *message, uint8_t level,
 uint8_t messageType)
{
    MTR_LogWriteMeta(messageType, level);
    MTR_LogPrintfCommon("%s\n", message);
    #ifdef __MINGW32__
    fclose(mtrLogFile);
    #endif
}

void MTR_CALL MTR_LogWrite_s(const char *message, uint8_t level,
 uint8_t messageType, const char * argument)
{
    MTR_LogWriteMeta(messageType, level);
    MTR_LogPrintfCommon("%s %s\n", message, argument);
    #ifdef __MINGW32__
    fclose(mtrLogFile);
    #endif
}

void MTR_CALL MTR_LogWrite_i(const char *message, uint8_t level,
 uint8_t messageType, int32_t argument)
{
    MTR_LogWriteMeta(messageType, level);
    MTR_LogPrintfCommon("%s %i\n", message, argument);
    #ifdef __MINGW32__
    fclose(mtrLogFile);
    #endif
}

void MTR_CALL MTR_LogWrite_d(const char *message, uint8_t level,
 uint8_t messageType, double argument)
{
    MTR_LogWriteMeta(messageType, level);
    MTR_LogPrintfCommon("%s %f\n", message, argument);
    #ifdef __MINGW32__
    fclose(mtrLogFile);
    #endif
}
