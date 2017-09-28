#ifndef MTR_SCREEN_SDL2_H
#define MTR_SCREEN_SDL2_H

#include "SDL2/SDL.h"

#include "fa/Screen_SDL2.h"
#include "marathoner/plugin.h"

typedef struct mtrScreen_t {
    SDL_Window   *screen;
    SDL_Renderer *renderer;
} mtrScreen_t;

mtrScreen_t *mtrScreen;

#endif

