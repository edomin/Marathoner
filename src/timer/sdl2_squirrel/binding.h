#ifndef MTR_TIMER_SDL2_SQUIRREL_H
#define MTR_TIMER_SDL2_SQUIRREL_H

#include "squirrel.h"

#include "marathoner/plugin.h"
#include "../binding_common.h"

#define MTR_SOURCE_MODULE "Timer_SDL2"

HSQUIRRELVM mtrVm;

typedef HSQUIRRELVM (MTR_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(SQFUNCTION, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

#endif
