#ifndef MTR_SCREEN_SDL2_LUA52
#define MTR_SCREEN_SDL2_LUA52

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "marathoner/plugin.h"

lua_State *mtrVm;

typedef lua_State* (MRT_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MRT_CALL * mtrScriptsRegisterFunctionFunc)(lua_CFunction, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (MRT_CALL * mtrScreenInitFunc)(uint16_t, uint16_t);
mtrScreenInitFunc mtrScreenInit;

typedef void (MRT_CALL * mtrScreenQuitFunc)(void);
mtrScreenQuitFunc mtrScreenQuit;

typedef void (MRT_CALL * mtrScreenFlipFunc)(void);
mtrScreenFlipFunc mtrScreenFlip;

int mtrSF_ScreenInit(lua_State* l);
int mtrSF_ScreenQuit(lua_State* l);
int mtrSF_ScreenFlip(lua_State* l);

#endif

