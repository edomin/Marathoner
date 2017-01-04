#ifndef MTR_KEYBOARD_SDL2_LUA
#define MTR_KEYBOARD_SDL2_LUA

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "SDL2/SDL.h"

#include "marathoner/plugin.h"
#include "../binding_common.h"
#include "../common.h"

lua_State *mtrVm;

typedef lua_State* (MTR_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(lua_CFunction, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (MTR_CALL * mtrScriptsRegisterNumericVariableFunc)(char *, double);
mtrScriptsRegisterNumericVariableFunc mtrScriptsRegisterNumericVariable;

#endif
