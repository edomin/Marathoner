#ifndef MTR_TIMER_SDL2_LUA
#define MTR_TIMER_SDL2_LUA

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "marathoner/plugin.h"

lua_State *mtrVm;

typedef lua_State* (MTR_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(lua_CFunction, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef bool (MTR_CALL * mtrTimerInitFunc)(void);
mtrTimerInitFunc mtrTimerInit;

typedef void (MTR_CALL * mtrTimerStartFunc)(void);
mtrTimerStartFunc mtrTimerStart;

typedef int (MTR_CALL * mtrTimerDelayFunc)(int);
mtrTimerDelayFunc mtrTimerDelay;

typedef int (MTR_CALL * mtrTimerDelayForFPSFunc)(int);
mtrTimerDelayForFPSFunc mtrTimerDelayForFPS;

typedef float (MTR_CALL * mtrTimerDelayForFPS_fFunc)(float);
mtrTimerDelayForFPS_fFunc mtrTimerDelayForFPS_f;

#endif
