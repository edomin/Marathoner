#ifndef MTR_SCREEN_SDL2
#define MTR_SCREEN_SDL2

#include "SDL2/SDL.h"

#include "marathoner/plugin.h"

typedef struct mtrScreen_t {
    SDL_Window   *screen;
    SDL_Renderer *renderer;
} mtrScreen_t;

mtrScreen_t *mtrScreen;

#endif

