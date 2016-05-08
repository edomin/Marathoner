#include "log.h"

void mtrLogWriteMeta(uint8_t messageType, uint8_t level)
{
    uint8_t i;

    time(&mtrCurrentTime);
    mtrNow = localtime(&mtrCurrentTime);
    mtrLogFile = fopen("Log.log", "a");
    fprintf(mtrLogFile, "[%i-%i-%i %i:%i:%i] ",
      mtrNow->tm_year + 1900, mtrNow->tm_mon + 1, mtrNow->tm_mday,
      mtrNow->tm_hour, mtrNow->tm_min, mtrNow->tm_sec);
    switch (messageType)
    {
        case 0:
            fprintf(mtrLogFile, "   Info: ");
            break;
        case 1:
            fprintf(mtrLogFile, "   Note: ");
            break;
        case 2:
            fprintf(mtrLogFile, "Warning: ");
            break;
        case 3:
            fprintf(mtrLogFile, "  Error: ");
            break;
        case 4:
            fprintf(mtrLogFile, "  Fatal: ");
            break;
        case 5:
            fprintf(mtrLogFile, "  Debug: ");
            break;
    }
    for (i = 0; i < level; i++)
    {
        fprintf(mtrLogFile, "-- ");
    }
}

void mtrLogInit(void)
{
    time(&mtrCurrentTime);
    mtrNow = localtime(&mtrCurrentTime);
    mtrLogFile = fopen("Log.log", "w");
    fprintf(mtrLogFile, "[%i-%i-%i %i:%i:%i] Begin Logging.\n",
      mtrNow->tm_year + 1900, mtrNow->tm_mon + 1, mtrNow->tm_mday,
      mtrNow->tm_hour, mtrNow->tm_min, mtrNow->tm_sec);
    fclose(mtrLogFile);
}

void mtrLogWrite(char *message, uint8_t level, uint8_t messageType)
{
    mtrLogWriteMeta(messageType, level);
    fprintf(mtrLogFile, message);
    fprintf(mtrLogFile, "\n");
    fclose(mtrLogFile);
}

void mtrLogWrite_s(char *message, uint8_t level, uint8_t messageType, char * argument)
{
    mtrLogWriteMeta(messageType, level);
    fprintf(mtrLogFile, message);
    fprintf(mtrLogFile, " ");
    fprintf(mtrLogFile, argument);
    fprintf(mtrLogFile, "\n");
    fclose(mtrLogFile);
}

void mtrLogWrite_i(char *message, uint8_t level, uint8_t messageType, int32_t argument)
{
    mtrLogWriteMeta(messageType, level);
    fprintf(mtrLogFile, message);
    fprintf(mtrLogFile, " %i", argument);
    fprintf(mtrLogFile, "\n");
    fclose(mtrLogFile);
}

void mtrLogWrite_d(char *message, uint8_t level, uint8_t messageType, double argument)
{
    mtrLogWriteMeta(messageType, level);
    fprintf(mtrLogFile, message);
    fprintf(mtrLogFile, " %f", argument);
    fprintf(mtrLogFile, "\n");
    fclose(mtrLogFile);
}
