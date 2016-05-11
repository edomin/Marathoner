#ifndef MTR_SCREEN_SDL_GPU
#define MTR_SCREEN_SDL_GPU

#define MTR_PLUGIN
#include "marathoner.h"

#include "sdl_gpu/SDL_gpu.h"

typedef struct mtrScreen_t {
    GPU_Target* screen;
    uint16_t width;
    uint16_t height;
} mtrScreen_t;

mtrScreen_t *mtrScreen;

#endif
