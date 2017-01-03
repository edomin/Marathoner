#ifndef MTR_GAME_CONTROLLER_SDL2_SQUIRREL
#define MTR_GAME_CONTROLLER_SDL2_SQUIRREL

#include "SDL2/SDL.h"

#include "squirrel.h"

#include "marathoner/plugin.h"
#include "../binding_common.h"

HSQUIRRELVM mtrVm;

typedef HSQUIRRELVM (MTR_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(SQFUNCTION, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (MTR_CALL * mtrScriptsRegisterNumericVariableFunc)(char *, double);
mtrScriptsRegisterNumericVariableFunc mtrScriptsRegisterNumericVariable;

#define MTR_POVHAT_CENTER       SDL_HAT_CENTERED
#define MTR_POVHAT_UP           SDL_HAT_UP
#define MTR_POVHAT_DOWN         SDL_HAT_DOWN
#define MTR_POVHAT_LEFT         SDL_HAT_LEFT
#define MTR_POVHAT_RIGHT        SDL_HAT_RIGHT
#define MTR_POVHAT_UP_LEFT      SDL_HAT_LEFTUP
#define MTR_POVHAT_UP_RIGHT     SDL_HAT_RIGHTUP
#define MTR_POVHAT_DOWN_LEFT    SDL_HAT_LEFTDOWN
#define MTR_POVHAT_DOWN_RIGHT   SDL_HAT_RIGHTDOWN

#endif

