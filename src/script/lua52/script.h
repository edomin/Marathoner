#ifndef MTR_SCRIPT_LUA52
#define MTR_SCRIPT_LUA52

#define MTR_PLUGIN
#include "marathoner.h"

#include <stdbool.h>

#include "lua52/lua.h"
#include "lua52/lualib.h"
#include "lua52/lauxlib.h"

typedef void (__stdcall * mtrPluginInitFunc)(void);
mtrPluginInitFunc mtrPluginInit;

lua_State *mtrVm;

__declspec(dllexport) void __stdcall mtrScriptsRegisterFunction(lua_CFunction func, char * funcname);
__declspec(dllexport) void __stdcall mtrScriptsRegisterStringVariable(char *name, char *value);
__declspec(dllexport) void __stdcall mtrScriptsRegisterNumericVariable(char *name, double value);

#endif

