#ifndef MTR_SCRIPT_LUA52
#define MTR_SCRIPT_LUA52

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "marathoner/plugin.h"

typedef void (MRT_CALL * mtrPluginInitFunc)(void);
mtrPluginInitFunc mtrPluginInit;

lua_State *mtrVm;

MRT_EXPORT void MRT_CALL mtrScriptsRegisterFunction(lua_CFunction func,
 char * funcname);
MRT_EXPORT void MRT_CALL mtrScriptsRegisterStringVariable(char *name,
 char *value);
MRT_EXPORT void MRT_CALL mtrScriptsRegisterNumericVariable(char *name,
 double value);

int mtrSF_FileWriteLine(lua_State* l);

#endif

