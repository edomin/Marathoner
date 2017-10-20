#ifndef MTR_SCRIPT_LUA_H
#define MTR_SCRIPT_LUA_H

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "fa/Script_Lua.h"
#include "marathoner/plugin.h"

typedef void (MTR_CALL * mtrPluginInitFunc)(void);
mtrPluginInitFunc MTR_PluginInit;

lua_State *mtrVm;
char      *mtrAutorun;

MTR_DCLSPC int MTR_CALL MTR_ScriptsFunctionSupported(const char *);

MTR_DCLSPC char * MTR_CALL MTR_ScriptsGetAutorunPath(void);
MTR_DCLSPC void MTR_CALL MTR_ScriptsRegisterFunction(lua_CFunction func,
 const char * funcname);
MTR_DCLSPC bool MTR_CALL MTR_ScriptsRegisterVariable_b(const char *name,
 bool value);
MTR_DCLSPC bool MTR_CALL MTR_ScriptsRegisterVariable_i(const char *name,
 int value);
MTR_DCLSPC bool MTR_CALL MTR_ScriptsRegisterVariable_u(const char *name,
 unsigned int value);
MTR_DCLSPC bool MTR_CALL MTR_ScriptsRegisterVariable_f(const char *name,
 float value);
MTR_DCLSPC bool MTR_CALL MTR_ScriptsRegisterVariable_d(const char *name,
 double value);
MTR_DCLSPC bool MTR_CALL MTR_ScriptsRegisterVariable_s(const char *name,
 const char *value);

#endif
