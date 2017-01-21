#ifndef MTR_ENGINE_LOG_H
#define MTR_ENGINE_LOG_H

#include <stdio.h>
#include <time.h>

#include "marathoner/engine.h"

FILE      *mtrLogFile;
time_t     mtrCurrentTime;
struct tm *mtrNow;

void MTR_CALL mtrLogInit(void);
void MTR_CALL mtrLogWrite(const char *message, uint8_t level, uint8_t messageType);
void MTR_CALL mtrLogWrite_s(const char *message, uint8_t level, uint8_t messageType,
  const char * argument);
void MTR_CALL mtrLogWrite_i(const char *message, uint8_t level, uint8_t messageType,
  int32_t argument);
void MTR_CALL mtrLogWrite_d(const char *message, uint8_t level, uint8_t messageType,
  double argument);

#endif
