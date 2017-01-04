#ifndef MTR_GAME_CONTROLLER_SDL2_SQUIRREL
#define MTR_GAME_CONTROLLER_SDL2_SQUIRREL

#include "SDL2/SDL.h"

#include "squirrel.h"

#include "marathoner/plugin.h"
#include "../binding_common.h"
#include "../common.h"

HSQUIRRELVM mtrVm;

typedef HSQUIRRELVM (MTR_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(SQFUNCTION, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (MTR_CALL * mtrScriptsRegisterNumericVariableFunc)(char *, double);
mtrScriptsRegisterNumericVariableFunc mtrScriptsRegisterNumericVariable;

#endif

