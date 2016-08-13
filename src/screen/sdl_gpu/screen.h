#ifndef MTR_SCREEN_SDL_GPU
#define MTR_SCREEN_SDL_GPU

#include "marathoner/plugin.h"

#include "sdl_gpu/SDL_gpu.h"

typedef struct mtrScreen_t {
    GPU_Target* screen;
} mtrScreen_t;

mtrScreen_t *mtrScreen;

#endif
