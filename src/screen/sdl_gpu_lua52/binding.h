#ifndef MTR_SCREEN_SDL_GPU_LUA52
#define MTR_SCREEN_SDL_GPU_LUA52

#include "marathoner/plugin.h"

#include <stdbool.h>

#include "lua52/lua.h"
#include "lua52/lualib.h"
#include "lua52/lauxlib.h"

lua_State *mtrVm;

typedef lua_State* (__stdcall * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (__stdcall * mtrScriptsRegisterFunctionFunc)(lua_CFunction, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (__stdcall * mtrScreenInitFunc)(uint16_t, uint16_t);
mtrScreenInitFunc mtrScreenInit;

typedef void (__stdcall * mtrScreenQuitFunc)(void);
mtrScreenQuitFunc mtrScreenQuit;

typedef void (__stdcall * mtrScreenFlipFunc)(void);
mtrScreenFlipFunc mtrScreenFlip;

int mtrSF_ScreenInit(lua_State* l);
int mtrSF_ScreenQuit(lua_State* l);
int mtrSF_ScreenFlip(lua_State* l);

#endif
