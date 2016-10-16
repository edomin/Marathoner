#ifndef MTR_SCRIPT_LUA
#define MTR_SCRIPT_LUA

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "marathoner/plugin.h"

typedef void (MTR_CALL * mtrPluginInitFunc)(void);
mtrPluginInitFunc mtrPluginInit;

lua_State *mtrVm;

MTR_EXPORT void MTR_CALL mtrScriptsRegisterFunction(lua_CFunction func,
 char * funcname);
MTR_EXPORT void MTR_CALL mtrScriptsRegisterStringVariable(char *name,
 char *value);
MTR_EXPORT void MTR_CALL mtrScriptsRegisterNumericVariable(char *name,
 double value);

#endif

