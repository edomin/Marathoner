#ifndef MTR_ENGINE_LOG
#define MTR_ENGINE_LOG

#include <stdio.h>
#include <time.h>

#include "marathoner/engine.h"

FILE      *mtrLogFile;
time_t     mtrCurrentTime;
struct tm *mtrNow;

void MRT_CALL mtrLogInit(void);
void MRT_CALL mtrLogWrite(const char *message, uint8_t level, uint8_t messageType);
void MRT_CALL mtrLogWrite_s(const char *message, uint8_t level, uint8_t messageType,
  const char * argument);
void MRT_CALL mtrLogWrite_i(const char *message, uint8_t level, uint8_t messageType,
  int32_t argument);
void MRT_CALL mtrLogWrite_d(const char *message, uint8_t level, uint8_t messageType,
  double argument);

#endif
