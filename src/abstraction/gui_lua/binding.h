#ifndef MTR_ABSTRACTION_GUI_LUA_H
#define MTR_ABSTRACTION_GUI_LUA_H

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "marathoner/plugin.h"
#include "../gui_binding_common.h"

lua_State *mtrVm;

typedef lua_State* (MTR_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(lua_CFunction, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (MTR_CALL * mtrScriptsRegisterNumericVariableFunc)(
 const char *name, double value);
mtrScriptsRegisterNumericVariableFunc mtrScriptsRegisterNumericVariable;

#endif