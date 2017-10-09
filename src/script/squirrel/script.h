#ifndef MTR_SCRIPT_SQUIRREL_H
#define MTR_SCRIPT_SQUIRREL_H

#include <stdio.h>

#include "squirrel.h"
#include "sqstdblob.h"
#include "sqstdio.h"
#include "sqstdsystem.h"
#include "sqstdmath.h"
#include "sqstdstring.h"
#include "sqstdaux.h"

#include "fa/Script_Squirrel.h"
#include "marathoner/plugin.h"

typedef void (MTR_CALL * mtrPluginInitFunc)(void);
mtrPluginInitFunc mtrPluginInit;

HSQUIRRELVM mtrVm;
char *mtrAutorun;

MTR_EXPORT int MTR_CALL mtrScriptsFunctionSupported(const char *);

MTR_EXPORT char * MTR_CALL mtrScriptsGetAutorunPath(void);
MTR_EXPORT void MTR_CALL mtrScriptsRegisterFunction(SQFUNCTION func,
 const char * funcname);
MTR_EXPORT bool MTR_CALL mtrScriptsRegisterStringVariable(const char *name,
 const char *value);
MTR_EXPORT bool MTR_CALL mtrScriptsRegisterNumericVariable(const char *name,
 double value);

#endif


