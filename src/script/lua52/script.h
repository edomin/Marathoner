#ifndef MTR_SCRIPT_LUA52
#define MTR_SCRIPT_LUA52

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "marathoner/plugin.h"

typedef void (__stdcall * mtrPluginInitFunc)(void);
mtrPluginInitFunc mtrPluginInit;

lua_State *mtrVm;

__declspec(dllexport) void __stdcall mtrScriptsRegisterFunction(lua_CFunction func, char * funcname);
__declspec(dllexport) void __stdcall mtrScriptsRegisterStringVariable(char *name, char *value);
__declspec(dllexport) void __stdcall mtrScriptsRegisterNumericVariable(char *name, double value);

#endif

