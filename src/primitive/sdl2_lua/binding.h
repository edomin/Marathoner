#ifndef MTR_PRIMITIVE_SDL2_LUA
#define MTR_PRIMITIVE_SDL2_LUA

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "marathoner/plugin.h"
#include "../binding_common.h"

lua_State *mtrVm;

typedef lua_State* (MTR_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(lua_CFunction,
 char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

#endif
