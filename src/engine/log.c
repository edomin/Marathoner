#include "log.h"

void MRT_CALL mtrLogWriteMeta(uint8_t messageType, uint8_t level)
{
    uint8_t i;

    time(&mtrCurrentTime);
    mtrNow = localtime(&mtrCurrentTime);
    mtrLogFile = fopen("Marathoner.log", "a");
    fprintf(mtrLogFile, "[%i-%i-%i %i:%i:%i] ",
      mtrNow->tm_year + 1900, mtrNow->tm_mon + 1, mtrNow->tm_mday,
      mtrNow->tm_hour, mtrNow->tm_min, mtrNow->tm_sec);
    switch (messageType)
    {
        case MTR_LMT_INFO:
            fprintf(mtrLogFile, "   Info: ");
            break;
        case MTR_LMT_NOTE:
            fprintf(mtrLogFile, "   Note: ");
            break;
        case MTR_LMT_WARNING:
            fprintf(mtrLogFile, "Warning: ");
            break;
        case MTR_LMT_ERROR:
            fprintf(mtrLogFile, "  Error: ");
            break;
        case MTR_LMT_FATAL:
            fprintf(mtrLogFile, "  Fatal: ");
            break;
        case MTR_LMT_DEBUG:
            fprintf(mtrLogFile, "  Debug: ");
            break;
    }
    for (i = 0; i < level; i++)
    {
        fprintf(mtrLogFile, "-- ");
    }
}

void MRT_CALL mtrLogInit(void)
{
    time(&mtrCurrentTime);
    mtrNow = localtime(&mtrCurrentTime);
    mtrLogFile = fopen("Marathoner.log", "w");
    fprintf(mtrLogFile, "[%i-%i-%i %i:%i:%i] Begin Logging.\n",
      mtrNow->tm_year + 1900, mtrNow->tm_mon + 1, mtrNow->tm_mday,
      mtrNow->tm_hour, mtrNow->tm_min, mtrNow->tm_sec);
    fclose(mtrLogFile);
}

void MRT_CALL mtrLogWrite(const char *message, uint8_t level,
 uint8_t messageType)
{
    mtrLogWriteMeta(messageType, level);
    fprintf(mtrLogFile, message);
    fprintf(mtrLogFile, "\n");
    fclose(mtrLogFile);
}

void MRT_CALL mtrLogWrite_s(const char *message, uint8_t level,
 uint8_t messageType, const char * argument)
{
    mtrLogWriteMeta(messageType, level);
    fprintf(mtrLogFile, message);
    fprintf(mtrLogFile, " ");
    fprintf(mtrLogFile, argument);
    fprintf(mtrLogFile, "\n");
    fclose(mtrLogFile);
}

void MRT_CALL mtrLogWrite_i(const char *message, uint8_t level,
 uint8_t messageType, int32_t argument)
{
    mtrLogWriteMeta(messageType, level);
    fprintf(mtrLogFile, message);
    fprintf(mtrLogFile, " %i", argument);
    fprintf(mtrLogFile, "\n");
    fclose(mtrLogFile);
}

void MRT_CALL mtrLogWrite_d(const char *message, uint8_t level,
 uint8_t messageType, double argument)
{
    mtrLogWriteMeta(messageType, level);
    fprintf(mtrLogFile, message);
    fprintf(mtrLogFile, " %f", argument);
    fprintf(mtrLogFile, "\n");
    fclose(mtrLogFile);
}
