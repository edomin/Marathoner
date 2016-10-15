#ifndef MTR_PRIMITIVE_SDL2_GPU
#define MTR_PRIMITIVE_SDL2_GPU

#include "SDL/SDL_gpu.h"

#include "marathoner/plugin.h"

typedef struct mtrScreen_t {
    GPU_Target* screen;
} mtrScreen_t;

mtrScreen_t *mtrScreen; /* this will imported from screen plugin */

typedef mtrScreen_t *(MTR_CALL * mtrGetScreenFunc)(void);
mtrGetScreenFunc mtrGetScreen;

#endif
