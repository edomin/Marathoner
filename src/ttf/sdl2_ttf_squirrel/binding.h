#ifndef MTR_TTF_SDL2_TTF_SQUIRREL_H
#define MTR_TTF_SDL2_TTF_SQUIRREL_H

#include "SDL2/SDL_ttf.h"

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
