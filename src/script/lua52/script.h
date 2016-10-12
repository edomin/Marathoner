#ifndef MTR_SCRIPT_LUA52
#define MTR_SCRIPT_LUA52

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

int mtrSF_ConfigfileGetKeyName(lua_State* l);
int mtrSF_ConfigfileGetSectionName(lua_State* l);
int mtrSF_ConfigfileDeleteKey(lua_State* l);
int mtrSF_ConfigfileDeleteSection(lua_State* l);
int mtrSF_ConfigfileReadBool(lua_State* l);
int mtrSF_ConfigfileReadInt(lua_State* l);
int mtrSF_ConfigfileReadSingle(lua_State* l);
int mtrSF_ConfigfileReadString(lua_State* l);
int mtrSF_ConfigfileWriteInt(lua_State* l);
int mtrSF_ConfigfileWriteSingle(lua_State* l);
int mtrSF_ConfigfileWriteString(lua_State* l);

int mtrSF_FileWriteLine(lua_State* l);

#endif

