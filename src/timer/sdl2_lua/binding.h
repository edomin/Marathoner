#ifndef MTR_TIMER_SDL2_LUA_H
#define MTR_TIMER_SDL2_LUA_H

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "marathoner/plugin.h"

#define MTR_SOURCE_MODULE "Timer_SDL2"
#ifdef MTR_MOD_STATIC
    #define MTR_BINDING
    #define MTR_ScriptsRegisterAll MTR_Timer_SDL2_LuaRegisterAll
#endif
#include "marathoner/binding_common.h"
#include "../binding_common.h"

MTR_BINDING_COMMON_HEADER()

#endif
