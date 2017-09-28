#ifndef MTR_TIMER_SDL2_H
#define MTR_TIMER_SDL2_H

#include "SDL2/SDL.h"

#include "fa/Timer_SDL2.h"
#include "marathoner/plugin.h"

typedef struct mtrTimer_t{
    uint32_t startTime;
} mtrTimer_t;

mtrTimer_t mtrTimer;

#endif
