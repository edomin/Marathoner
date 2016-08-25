#ifndef MTR_SCREEN_SDL_GPU
#define MTR_SCREEN_SDL_GPU

#include "SDL/SDL_gpu.h"

#include "marathoner/plugin.h"

typedef struct mtrScreen_t {
    GPU_Target* screen;
} mtrScreen_t;

mtrScreen_t *mtrScreen;

#endif
