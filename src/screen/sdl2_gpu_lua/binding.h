#ifndef MTR_SCREEN_SDL2_GPU_LUA_H
#define MTR_SCREEN_SDL2_GPU_LUA_H

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "marathoner/plugin.h"

#define MTR_SOURCE_MODULE "Screen_SDL2_gpu"
#ifdef MTR_MOD_STATIC
    #define MTR_BINDING
    #define MTR_ScriptsRegisterAll MTR_Screen_SDL2_gpu_LuaRegisterAll
#endif
#include "marathoner/binding_common.h"
#include "../binding_common.h"

MTR_BINDING_COMMON_HEADER()

#endif
