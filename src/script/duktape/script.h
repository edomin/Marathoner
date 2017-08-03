#ifndef MTR_SCRIPT_DUKTAPE_H
#define MTR_SCRIPT_DUKTAPE_H

#include "duktape.h"

#include "marathoner/plugin.h"

typedef void (MTR_CALL * mtrPluginInitFunc)(void);
mtrPluginInitFunc mtrPluginInit;

duk_context *mtrVm;

MTR_EXPORT void MTR_CALL mtrScriptsRegisterFunction(duk_c_function func,
 const char *funcname);
MTR_EXPORT void MTR_CALL mtrScriptsRegisterStringVariable(const char *name,
 const char *value);
MTR_EXPORT void MTR_CALL mtrScriptsRegisterNumericVariable(const char *name,
 double value);

#endif
