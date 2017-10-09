#ifndef MTR_SCRIPT_LUA_H
#define MTR_SCRIPT_LUA_H

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "fa/Script_Lua.h"
#include "marathoner/plugin.h"

typedef void (MTR_CALL * mtrPluginInitFunc)(void);
mtrPluginInitFunc mtrPluginInit;

lua_State *mtrVm;
char *mtrAutorun;

MTR_EXPORT int MTR_CALL mtrScriptsFunctionSupported(const char *);

MTR_EXPORT char * MTR_CALL mtrScriptsGetAutorunPath(void);
MTR_EXPORT void MTR_CALL mtrScriptsRegisterFunction(lua_CFunction func,
 const char * funcname);
MTR_EXPORT bool MTR_CALL mtrScriptsRegisterStringVariable(const char *name,
 const char *value);
MTR_EXPORT bool MTR_CALL mtrScriptsRegisterNumericVariable(const char *name,
 double value);

#endif
