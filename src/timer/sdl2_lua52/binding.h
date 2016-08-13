#ifndef MTR_TIMER_SDL2_LUA52
#define MTR_TIMER_SDL2_LUA52

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

typedef bool (__stdcall * mtrTimerInitFunc)(void);
mtrTimerInitFunc mtrTimerInit;

typedef void (__stdcall * mtrTimerStartFunc)(void);
mtrTimerStartFunc mtrTimerStart;

typedef uint32_t (__stdcall * mtrTimerDelayFunc)(uint32_t);
mtrTimerDelayFunc mtrTimerDelay;

typedef uint32_t (__stdcall * mtrTimerDelayForFPSFunc)(uint32_t);
mtrTimerDelayForFPSFunc mtrTimerDelayForFPS;

typedef float (__stdcall * mtrTimerDelayForFPS_fFunc)(float);
mtrTimerDelayForFPS_fFunc mtrTimerDelayForFPS_f;

int mtrSF_TimerInit(lua_State* l);
int mtrSF_TimerStart(lua_State* l);
int mtrSF_TimerDelay(lua_State* l);
int mtrSF_TimerDelayForFPS(lua_State* l);
int mtrSF_TimerDelayForFPS_f(lua_State* l);

#endif
