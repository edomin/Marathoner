#ifndef MTR_ABSTRACTION_SPRITE_SQUIRREL
#define MTR_ABSTRACTION_SPRITE_SQUIRREL

#include "squirrel.h"

#include "marathoner/plugin.h"
#include "../sprite_binding_common.h"

HSQUIRRELVM mtrVm;

typedef HSQUIRRELVM (MTR_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(SQFUNCTION, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

#endif
