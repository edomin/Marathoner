#ifndef MTR_SCREEN_SDL2_GPU_SQUIRREL
#define MTR_SCREEN_SDL2_GPU_SQUIRREL

#include "squirrel.h"

#include "marathoner/plugin.h"
#include "../binding_common.h"

HSQUIRRELVM mtrVm;

typedef HSQUIRRELVM (MTR_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(SQFUNCTION, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

#endif
