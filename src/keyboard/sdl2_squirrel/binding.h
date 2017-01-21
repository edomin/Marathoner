#ifndef MTR_KEYBOARD_SDL2_SQUIRREL_H
#define MTR_KEYBOARD_SDL2_SQUIRREL_H

#include "squirrel.h"

#include "SDL2/SDL.h"

#include "marathoner/plugin.h"
#include "../binding_common.h"
#include "../common.h"

#define MTR_SOURCE_MODULE "Keyboard_SDL2"

HSQUIRRELVM mtrVm;

typedef HSQUIRRELVM (MTR_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(SQFUNCTION, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (MTR_CALL * mtrScriptsRegisterNumericVariableFunc)(char *, double);
mtrScriptsRegisterNumericVariableFunc mtrScriptsRegisterNumericVariable;

#endif
