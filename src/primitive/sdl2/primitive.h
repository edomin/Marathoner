#ifndef MTR_PRIMITIVE_SDL2
#define MTR_PRIMITIVE_SDL2

#include "SDL2/SDL.h"

#include "marathoner/plugin.h"

typedef struct mtrScreen_t {
    SDL_Window   *screen;
    SDL_Renderer *renderer;
} mtrScreen_t;

mtrScreen_t *mtrScreen; /* this will imported from screen plugin */

typedef mtrScreen_t *(MRT_CALL * mtrGetScreenFunc)(void);
mtrGetScreenFunc mtrGetScreen;

#endif

