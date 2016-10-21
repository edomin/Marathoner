#ifndef MTR_PRIMITIVE_SDL2_GPU
#define MTR_PRIMITIVE_SDL2_GPU

#include "SDL2/SDL_gpu.h"

#include "marathoner/plugin.h"

typedef struct mtrScreen_t {
    GPU_Target* screen;
} mtrScreen_t;

mtrScreen_t *mtrScreen; /* this will imported from screen plugin */
float mtrLinePointX_f;
float mtrLinePointY_f;
bool  mtrLineDrawing;

typedef mtrScreen_t *(MTR_CALL * mtrGetScreenFunc)(void);
mtrGetScreenFunc mtrGetScreen;

#endif
