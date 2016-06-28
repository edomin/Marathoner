#ifndef MTR_TIMER_SDL2
#define MTR_TIMER_SDL2

#define MTR_PLUGIN
#include "marathoner.h"

#include "SDL2/SDL.h"

typedef struct mtrTimer_t{
    uint32_t startTime;
} mtrTimer_t;

mtrTimer_t mtrTimer;

#endif

