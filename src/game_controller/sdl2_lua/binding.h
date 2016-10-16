#ifndef MTR_GAME_CONTROLLER_SDL2_LUA
#define MTR_GAME_CONTROLLER_SDL2_LUA

#include "SDL2/SDL.h"

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "marathoner/plugin.h"

lua_State *mtrVm;

typedef lua_State* (MTR_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(lua_CFunction, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (MTR_CALL * mtrScriptsRegisterNumericVariableFunc)(char *, double);
mtrScriptsRegisterNumericVariableFunc mtrScriptsRegisterNumericVariable;

typedef bool (MTR_CALL * mtrGameControllerInitFunc)(void);
mtrGameControllerInitFunc mtrGameControllerInit;

typedef void (MTR_CALL * mtrGameControllerQuitFunc)(void);
mtrGameControllerQuitFunc mtrGameControllerQuit;

typedef void (MTR_CALL * mtrGameControllerRefreshFunc)(void);
mtrGameControllerRefreshFunc mtrGameControllerRefresh;

typedef bool (MTR_CALL * mtrGameControllerButtonPressFunc)(int, int);
mtrGameControllerButtonPressFunc mtrGameControllerButtonPress;

typedef bool (MTR_CALL * mtrGameControllerButtonReleaseFunc)(int, int);
mtrGameControllerButtonReleaseFunc mtrGameControllerButtonRelease;

typedef bool (MTR_CALL * mtrGameControllerButtonPressedFunc)(int, int);
mtrGameControllerButtonPressedFunc mtrGameControllerButtonPressed;

typedef int16_t (MTR_CALL * mtrGameControllerGetAxisFunc)(int, int);
mtrGameControllerGetAxisFunc mtrGameControllerGetAxis;

typedef float (MTR_CALL * mtrGameControllerGetAxis_fFunc)(int, int);
mtrGameControllerGetAxis_fFunc mtrGameControllerGetAxis_f;

typedef int (MTR_CALL * mtrGameControllerGetAxisDeltaFunc)(int, int);
mtrGameControllerGetAxisDeltaFunc mtrGameControllerGetAxisDelta;

typedef float (MTR_CALL * mtrGameControllerGetAxisDelta_fFunc)(int, int);
mtrGameControllerGetAxisDelta_fFunc mtrGameControllerGetAxisDelta_f;

typedef int (MTR_CALL * mtrGameControllerGetTrackballDeltaXFunc)(int, int);
mtrGameControllerGetTrackballDeltaXFunc mtrGameControllerGetTrackballDeltaX;

typedef int (MTR_CALL * mtrGameControllerGetTrackballDeltaYFunc)(int, int);
mtrGameControllerGetTrackballDeltaYFunc mtrGameControllerGetTrackballDeltaY;

typedef void (MTR_CALL * mtrGameControllerGetTrackballDeltaXYFunc)(int, int,
 int *, int *);
mtrGameControllerGetTrackballDeltaXYFunc mtrGameControllerGetTrackballDeltaXY;

typedef uint8_t (MTR_CALL * mtrGameControllerGetPovHatFunc)(int, int);
mtrGameControllerGetPovHatFunc mtrGameControllerGetPovHat;

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
