#ifndef MTR_PRIMITIVE_SDL_GPU
#define MTR_PRIMITIVE_SDL_GPU

#include "SDL/SDL_gpu.h"

#include "marathoner/plugin.h"

typedef struct mtrScreen_t {
    GPU_Target* screen;
} mtrScreen_t;

mtrScreen_t *mtrScreen; /* this will imported from screen plugin */

typedef mtrScreen_t *(__stdcall * mtrGetScreenFunc)(void);
mtrGetScreenFunc mtrGetScreen;

#endif
