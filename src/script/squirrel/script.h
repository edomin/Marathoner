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
mtrPluginInitFunc MTR_PluginInit;

HSQUIRRELVM mtrVm;
char       *mtrAutorun;

MTR_DCLSPC int MTR_CALL MTR_ScriptsFunctionSupported(const char *);

MTR_DCLSPC char * MTR_CALL MTR_ScriptsGetAutorunPath(void);
MTR_DCLSPC void MTR_CALL MTR_ScriptsRegisterFunction(SQFUNCTION func,
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


