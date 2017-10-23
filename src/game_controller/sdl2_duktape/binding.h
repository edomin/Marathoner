#ifndef MTR_GAME_CONTROLLER_SDL2_DUKTAPE_H
#define MTR_GAME_CONTROLLER_SDL2_DUKTAPE_H

#ifdef __MINGW64__
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wswitch-default"
#endif
#include "SDL2/SDL.h"
#ifdef __MINGW64__
    #pragma GCC diagnostic pop
#endif

#include "duktape.h"

#include "marathoner/plugin.h"
#include "../binding_common.h"
#include "../common.h"

#define MTR_SOURCE_MODULE "Game_Controller_SDL2"
#include "marathoner/binding_common.h"

MTR_BINDING_COMMON_HEADER()

#endif


