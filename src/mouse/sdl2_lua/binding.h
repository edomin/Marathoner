#ifndef MTR_MOUSE_SDL2_LUA
#define MTR_MOUSE_SDL2_LUA

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "SDL2/SDL.h"

#include "marathoner/plugin.h"
#include "../binding_common.h"

lua_State *mtrVm;

typedef lua_State* (MTR_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(lua_CFunction, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (MTR_CALL * mtrScriptsRegisterNumericVariableFunc)(char *, double);
mtrScriptsRegisterNumericVariableFunc mtrScriptsRegisterNumericVariable;

#define MTR_MOUSE_LEFT   SDL_BUTTON_LEFT
#define MTR_MOUSE_RIGHT  SDL_BUTTON_RIGHT
#define MTR_MOUSE_MIDDLE SDL_BUTTON_MIDDLE
#define MTR_MOUSE_X1     SDL_BUTTON_X1
#define MTR_MOUSE_X2     SDL_BUTTON_X2

#endif
