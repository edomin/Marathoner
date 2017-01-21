#ifndef MTR_SCREEN_SDL2_GPU_SQUIRREL_H
#define MTR_SCREEN_SDL2_GPU_SQUIRREL_H

#include "squirrel.h"

#include "marathoner/plugin.h"
#include "../binding_common.h"

#define MTR_SOURCE_MODULE "Screen_SDL2_gpu"

HSQUIRRELVM mtrVm;

typedef HSQUIRRELVM (MTR_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(SQFUNCTION, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

#endif
