#ifndef MTR_SCRIPT_DUKTAPE_H
#define MTR_SCRIPT_DUKTAPE_H

#include "duktape.h"

#include "fa/Script_Duktape.h"
#include "marathoner/plugin.h"

typedef void (MTR_CALL * mtrPluginInitFunc)(void);
mtrPluginInitFunc mtrPluginInit;

duk_context *mtrVm;

typedef int (MTR_CALL * mtrScriptsFunctionSupportedFunc)(const char *);
mtrScriptsFunctionSupportedFunc mtrScriptsFunctionSupported;

MTR_EXPORT void MTR_CALL mtrScriptsRegisterFunction(duk_c_function func,
 const char *funcname);
MTR_EXPORT bool MTR_CALL mtrScriptsRegisterStringVariable(const char *name,
 const char *value);
MTR_EXPORT bool MTR_CALL mtrScriptsRegisterNumericVariable(const char *name,
 double value);

#endif
