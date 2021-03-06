#ifndef MTR_ABSTRACTION_SCENE_LUA_H
#define MTR_ABSTRACTION_SCENE_LUA_H

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "marathoner/plugin.h"
#ifdef MTR_MOD_STATIC
    #define MTR_BINDING
    #define MTR_ScriptsRegisterAll MTR_Abstraction_scene_LuaRegisterAll
#endif
#include "marathoner/binding_common.h"
#include "../scene_binding_common.h"

MTR_BINDING_COMMON_HEADER()

#endif
