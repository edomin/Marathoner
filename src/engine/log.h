#ifndef MTR_ENGINE_LOG
#define MTR_ENGINE_LOG

#include <stdint.h>
#include <stdio.h>
#include <time.h>

#include "marathoner.h"

FILE      *mtrLogFile;
time_t     mtrCurrentTime;
struct tm *mtrNow;

void __stdcall mtrLogInit(void);
void __stdcall mtrLogWrite(char *message, uint8_t level, uint8_t messageType);
void __stdcall mtrLogWrite_s(char *message, uint8_t level, uint8_t messageType,
  const char * argument);
void __stdcall mtrLogWrite_i(char *message, uint8_t level, uint8_t messageType,
  int32_t argument);
void __stdcall mtrLogWrite_d(char *message, uint8_t level, uint8_t messageType,
  double argument);

#endif
