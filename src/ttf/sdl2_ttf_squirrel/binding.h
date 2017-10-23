#ifndef MTR_TTF_SDL2_TTF_SQUIRREL_H
#define MTR_TTF_SDL2_TTF_SQUIRREL_H

#ifdef __MINGW64__
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wswitch-default"
#endif
#include "SDL2/SDL_ttf.h"
#ifdef __MINGW64__
    #pragma GCC diagnostic pop
#endif

#include "squirrel.h"

#include "marathoner/plugin.h"
#include "../binding_common.h"
#include "../common.h"

#define MTR_SOURCE_MODULE "TTF_SDL2_ttf"
#include "marathoner/binding_common.h"

MTR_BINDING_COMMON_HEADER()

#endif
