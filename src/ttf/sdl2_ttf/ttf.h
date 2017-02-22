#ifndef MTR_TTF_SDL2_TTF_H
#define MTR_TTF_SDL2_TTF_H

#include "SDL2/SDL_ttf.h"

#include "marathoner/plugin.h"
#include "../common.h"

typedef struct mtrTtf_t {
    TTF_Font *font;
    char     *name;
} mtrTtf_t;

mtrIndexkeeper_t *mtrTtfKeeper;

SDL_Surface      *tempSurface;
mtrPixels_t      *tempPixels;

#endif
