#ifndef MTR_TIMER_SDL_GPU
#define MTR_TIMER_SDL_GPU

#define MTR_PLUGIN
#include "marathoner.h"

#include "sdl_gpu/SDL_gpu.h"

typedef struct mtrTimer_t{
    uint32_t startTime;
} mtrTimer_t;

mtrTimer_t mtrTimer;

#endif

