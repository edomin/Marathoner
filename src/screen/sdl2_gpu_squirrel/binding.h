#ifndef MTR_SCREEN_SDL2_GPU_SQUIRREL_H
#define MTR_SCREEN_SDL2_GPU_SQUIRREL_H

#include "squirrel.h"

#include "marathoner/plugin.h"

#define MTR_SOURCE_MODULE "Screen_SDL2_gpu"
#ifdef MTR_MOD_STATIC
    #define MTR_BINDING
    #define MTR_ScriptsRegisterAll MTR_Screen_SDL2_gpu_SquirrelRegisterAll
#endif
#include "marathoner/binding_common.h"
#include "../binding_common.h"

MTR_BINDING_COMMON_HEADER()

#endif
