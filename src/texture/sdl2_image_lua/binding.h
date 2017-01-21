#ifndef MTR_TEXTURE_SDL2_IMAGE_LUA_H
#define MTR_TEXTURE_SDL2_IMAGE_LUA_H

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "SDL2/SDL.h"

#include "marathoner/plugin.h"
#include "../binding_common.h"

#define MTR_SOURCE_MODULE "Texture_SDL2"

#define MTR_FLIP_NONE                   SDL_FLIP_NONE
#define MTR_FLIP_HORIZONTAL             SDL_FLIP_HORIZONTAL
#define MTR_FLIP_VERTICAL               SDL_FLIP_VERTICAL
#define MTR_FLIP_BOTH                   (SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL)
/*
#define MTR_BLEND_ZERO                  0
#define MTR_BLEND_ONE                   1
#define MTR_BLEND_SRC_COLOR             2
#define MTR_BLEND_DST_COLOR             3
#define MTR_BLEND_ONE_MINUS_SRC         4
#define MTR_BLEND_ONE_MINUS_DST         5
#define MTR_BLEND_SRC_ALPHA             6
#define MTR_BLEND_DST_ALPHA             7
#define MTR_BLEND_ONE_MINUS_SRC_ALPHA   8
#define MTR_BLEND_ONE_MINUS_DST_ALPHA   9
*/
lua_State *mtrVm;

typedef lua_State* (MTR_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(lua_CFunction, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (MTR_CALL * mtrScriptsRegisterNumericVariableFunc)(char *, double);
mtrScriptsRegisterNumericVariableFunc mtrScriptsRegisterNumericVariable;

#endif
