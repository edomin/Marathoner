#ifndef MTR_ABSTRACTION_FONT_SQUIRREL_H
#define MTR_ABSTRACTION_FONT_SQUIRREL_H

#include "squirrel.h"

#include "marathoner/plugin.h"
#include "../font_binding_common.h"

HSQUIRRELVM mtrVm;

typedef HSQUIRRELVM (MTR_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(SQFUNCTION, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

#endif
