#ifndef MTR_JSON_CJSON_SQUIRREL_H
#define MTR_JSON_CJSON_SQUIRREL_H

#include "squirrel.h"

#include "marathoner/plugin.h"
#include "../binding_common.h"

#define MTR_SOURCE_MODULE "JSON_cJSON"

HSQUIRRELVM mtrVm;

typedef HSQUIRRELVM (MTR_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(SQFUNCTION, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

#endif
