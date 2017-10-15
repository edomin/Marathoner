#include "log.h"

int mtrLogPrintf(char *format, ...)
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

void MTR_CALL mtrLogWriteMeta(uint8_t messageType, uint8_t level)
{
    uint8_t i;

    time(&mtrCurrentTime);
    mtrNow = localtime(&mtrCurrentTime);
    #ifdef __MINGW32__
        mtrLogFile = fopen(logFilename, "a");
        mtrLogPrintf("[%i-%i-%i %i:%i:%i] ",
         mtrNow->tm_year + 1900, mtrNow->tm_mon + 1, mtrNow->tm_mday,
         mtrNow->tm_hour, mtrNow->tm_min, mtrNow->tm_sec);
        switch (messageType)
        {
            case MTR_LMT_INFO:
                mtrLogPrintf("%s", "   Info: ");
                break;
            case MTR_LMT_NOTE:
                mtrLogPrintf("%s", "   Note: ");
                break;
            case MTR_LMT_WARNING:
                mtrLogPrintf("%s", "Warning: ");
                break;
            case MTR_LMT_ERROR:
                mtrLogPrintf("%s", "  Error: ");
                break;
            case MTR_LMT_FATAL:
                mtrLogPrintf("%s", "  Fatal: ");
                break;
            case MTR_LMT_DEBUG:
            default:
                mtrLogPrintf("%s", "  Debug: ");
                break;
        }
        for (i = 0; i < level; i++)
        {
            mtrLogPrintf("%s", "-- ");
        }
    #else
        printf("[%i-%i-%i %i:%i:%i] ",
         mtrNow->tm_year + 1900, mtrNow->tm_mon + 1, mtrNow->tm_mday,
         mtrNow->tm_hour, mtrNow->tm_min, mtrNow->tm_sec);
        switch (messageType)
        {
            case MTR_LMT_INFO:
                printf("%s", "   Info: ");
                break;
            case MTR_LMT_NOTE:
                printf("%s", "   Note: ");
                break;
            case MTR_LMT_WARNING:
                printf("%s", "Warning: ");
                break;
            case MTR_LMT_ERROR:
                printf("%s", "  Error: ");
                break;
            case MTR_LMT_FATAL:
                printf("%s", "  Fatal: ");
                break;
            case MTR_LMT_DEBUG:
                printf("%s", "  Debug: ");
                break;
        }
        for (i = 0; i < level; i++)
        {
            printf("%s", "-- ");
        }
    #endif
}

void MTR_CALL mtrLogInit(const char *filename)
{
    logFilename = filename;
    time(&mtrCurrentTime);
    mtrNow = localtime(&mtrCurrentTime);
    #ifdef __MINGW32__
        mtrLogFile = fopen(logFilename, "w");
        mtrLogPrintf("[%i-%i-%i %i:%i:%i]          Begin Logging.\n",
         mtrNow->tm_year + 1900, mtrNow->tm_mon + 1, mtrNow->tm_mday,
         mtrNow->tm_hour, mtrNow->tm_min, mtrNow->tm_sec);
        fclose(mtrLogFile);
    #else
        printf("[%i-%i-%i %i:%i:%i]          Begin Logging.\n",
         mtrNow->tm_year + 1900, mtrNow->tm_mon + 1, mtrNow->tm_mday,
         mtrNow->tm_hour, mtrNow->tm_min, mtrNow->tm_sec);
    #endif
}

/*fa mtrLogWrite yes */
void MTR_CALL mtrLogWrite(const char *message, uint8_t level,
 uint8_t messageType)
{
    mtrLogWriteMeta(messageType, level);
    #ifdef __MINGW32__
        mtrLogPrintf("%s\n", message);
        fclose(mtrLogFile);
    #else
        printf("%s\n", message);
    #endif
}

/*fa mtrLogWrite_s yes */
void MTR_CALL mtrLogWrite_s(const char *message, uint8_t level,
 uint8_t messageType, const char * argument)
{
    mtrLogWriteMeta(messageType, level);
    #ifdef __MINGW32__
        mtrLogPrintf("%s %s\n", message, argument);
        fclose(mtrLogFile);
    #else
        printf("%s %s\n", message, argument);
    #endif
}

/*fa mtrLogWrite_i yes */
void MTR_CALL mtrLogWrite_i(const char *message, uint8_t level,
 uint8_t messageType, int32_t argument)
{
    mtrLogWriteMeta(messageType, level);
    #ifdef __MINGW32__
        mtrLogPrintf("%s %i\n", message, argument);
        fclose(mtrLogFile);
    #else
        printf("%s %i\n", message, argument);
    #endif
}

/*fa mtrLogWrite_d yes */
void MTR_CALL mtrLogWrite_d(const char *message, uint8_t level,
 uint8_t messageType, double argument)
{
    mtrLogWriteMeta(messageType, level);
    #ifdef __MINGW32__
        mtrLogPrintf("%s %f\n", message, argument);
        fclose(mtrLogFile);
    #else
        printf("%s %f\n", message, argument);
    #endif
}
