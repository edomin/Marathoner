#ifndef MTR_SCREEN_SDL_GPU_LUA52
#define MTR_SCREEN_SDL_GPU_LUA52

#define MTR_PLUGIN
#include "marathoner.h"

#include "lua52/lua.h"
#include "lua52/lualib.h"
#include "lua52/lauxlib.h"

//#include "sdl_gpu/SDL_gpu.h"

lua_State *mtrVm;

typedef lua_State* (__stdcall * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (__stdcall * mtrScriptsRegisterFunctionFunc)(lua_CFunction, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (__stdcall * mtrScreenInitFunc)(uint16_t, uint16_t);
mtrScreenInitFunc mtrScreenInit;

typedef void (__stdcall * mtrScreenQuitFunc)(void);
mtrScreenQuitFunc mtrScreenQuit;

int mtrSF_ScreenInit(lua_State* l);
int mtrSF_ScreenQuit(lua_State* l);

#endif
