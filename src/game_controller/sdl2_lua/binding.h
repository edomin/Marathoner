#ifndef MTR_GAME_CONTROLLER_SDL2_LUA_H
#define MTR_GAME_CONTROLLER_SDL2_LUA_H

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "marathoner/plugin.h"

#define MTR_SOURCE_MODULE "Game_Controller_SDL2"
#ifdef MTR_MOD_STATIC
    #define MTR_BINDING
    #define MTR_ScriptsRegisterAll MTR_Game_Controller_SDL2_LuaRegisterAll
#endif
#include "marathoner/binding_common.h"
#include "../binding_common.h"

MTR_BINDING_COMMON_HEADER()

#endif
