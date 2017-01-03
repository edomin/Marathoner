#ifndef MTR_SCRIPT_SQUIRREL
#define MTR_SCRIPT_SQUIRREL

#include <stdio.h>

#include "squirrel.h"
#include "sqstdio.h"
#include "sqstdaux.h"

#include "marathoner/plugin.h"

typedef void (MTR_CALL * mtrPluginInitFunc)(void);
mtrPluginInitFunc mtrPluginInit;

HSQUIRRELVM mtrVm;

MTR_EXPORT void MTR_CALL mtrScriptsRegisterFunction(SQFUNCTION func,
 const char * funcname);
MTR_EXPORT void MTR_CALL mtrScriptsRegisterStringVariable(const char *name,
 const char *value);
MTR_EXPORT void MTR_CALL mtrScriptsRegisterNumericVariable(const char *name,
 double value);

#endif


