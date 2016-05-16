#ifndef MTR_SCRIPT_LUA52
#define MTR_SCRIPT_LUA52

#define MTR_PLUGIN
#include "marathoner.h"

#include "lua52/lua.h"
#include "lua52/lualib.h"
#include "lua52/lauxlib.h"
#include "bool/bool.h"

typedef void (__stdcall * mtrPluginInitFunc)(void);
mtrPluginInitFunc mtrPluginInit;

lua_State *mtrVm;

#endif

