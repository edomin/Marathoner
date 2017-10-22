#ifndef MTR_CORE_LOG_H
#define MTR_CORE_LOG_H

#include <stdio.h>
#include <stdarg.h>
#include <time.h>

#include "console.h"

#include "marathoner/engine.h"

FILE       *mtrLogFile;
time_t      mtrCurrentTime;
struct tm  *mtrNow;
const char *logFilename;
char        mtrLogBuffer[256];

void MTR_CALL MTR_LogInit(const char *filename);
void MTR_CALL MTR_LogWrite(const char *message, uint8_t level,
 uint8_t messageType);
void MTR_CALL MTR_LogWrite_s(const char *message, uint8_t level,
 uint8_t messageType, const char *argument);
void MTR_CALL MTR_LogWrite_i(const char *message, uint8_t level,
 uint8_t messageType, int32_t argument);
void MTR_CALL MTR_LogWrite_d(const char *message, uint8_t level,
 uint8_t messageType, double argument);

#endif
