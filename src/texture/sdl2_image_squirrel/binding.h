#ifndef MTR_TEXTURE_SDL2_IMAGE_SQUIRREL_H
#define MTR_TEXTURE_SDL2_IMAGE_SQUIRREL_H

#include "squirrel.h"
#include "SDL2/SDL.h"

#include "marathoner/plugin.h"
#include "../binding_common.h"

#define MTR_FLIP_NONE                   SDL_FLIP_NONE
#define MTR_FLIP_HORIZONTAL             SDL_FLIP_HORIZONTAL
#define MTR_FLIP_VERTICAL               SDL_FLIP_VERTICAL
#define MTR_FLIP_BOTH                   (SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL)
/*
#define MTR_BLEND_ZERO                  0
#define MTR_BLEND_ONE                   1
#define MTR_BLEND_SRC_COLOR             2
#define MTR_BLEND_DST_COLOR             3
#define MTR_BLEND_ONE_MINUS_SRC         4
#define MTR_BLEND_ONE_MINUS_DST         5
#define MTR_BLEND_SRC_ALPHA             6
#define MTR_BLEND_DST_ALPHA             7
#define MTR_BLEND_ONE_MINUS_SRC_ALPHA   8
#define MTR_BLEND_ONE_MINUS_DST_ALPHA   9
*/
HSQUIRRELVM mtrVm;

typedef HSQUIRRELVM (MTR_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(SQFUNCTION, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (MTR_CALL * mtrScriptsRegisterNumericVariableFunc)(char *, double);
mtrScriptsRegisterNumericVariableFunc mtrScriptsRegisterNumericVariable;

#endif
