#ifndef MTR_TTF_FREETYPE2_LUA_H
#define MTR_TTF_FREETYPE2_LUA_H

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "marathoner/plugin.h"

#define MTR_SOURCE_MODULE "TTF_FreeType2"
#ifdef MTR_MOD_STATIC
    #define MTR_BINDING
    #define MTR_ScriptsRegisterAll MTR_TTF_FreeType2_LuaRegisterAll
#endif
#include "marathoner/binding_common.h"
#include "../binding_common.h"

MTR_BINDING_COMMON_HEADER()

#endif
