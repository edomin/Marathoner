#ifndef MTR_SCREEN_SDL2_GPU_H
#define MTR_SCREEN_SDL2_GPU_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_gpu.h"

#include "marathoner/plugin.h"

typedef struct mtrScreen_t {
    GPU_Target* screen;
    GPU_Target* target;
} mtrScreen_t;

mtrScreen_t *mtrScreen;

#endif
