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

typedef bool (MTR_CALL * mtrGameControllerButtonPressFunc)(uint8_t, uint8_t);
mtrGameControllerButtonPressFunc mtrGameControllerButtonPress;

typedef bool (MTR_CALL * mtrGameControllerButtonReleaseFunc)(uint8_t, uint8_t);
mtrGameControllerButtonReleaseFunc mtrGameControllerButtonRelease;

typedef bool (MTR_CALL * mtrGameControllerButtonPressedFunc)(uint8_t, uint8_t);
mtrGameControllerButtonPressedFunc mtrGameControllerButtonPressed;

typedef int16_t (MTR_CALL * mtrGameControllerGetAxisFunc)(uint8_t, uint8_t);
mtrGameControllerGetAxisFunc mtrGameControllerGetAxis;

typedef float (MTR_CALL * mtrGameControllerGetAxis_fFunc)(uint8_t, uint8_t);
mtrGameControllerGetAxis_fFunc mtrGameControllerGetAxis_f;

typedef int32_t (MTR_CALL * mtrGameControllerGetAxisDeltaFunc)(uint8_t,
 uint8_t);
mtrGameControllerGetAxisDeltaFunc mtrGameControllerGetAxisDelta;

typedef float (MTR_CALL * mtrGameControllerGetAxisDelta_fFunc)(uint8_t,
 uint8_t);
mtrGameControllerGetAxisDelta_fFunc mtrGameControllerGetAxisDelta_f;

typedef int32_t (MTR_CALL * mtrGameControllerGetTrackballDeltaXFunc)(uint8_t,
 uint8_t);
mtrGameControllerGetTrackballDeltaXFunc mtrGameControllerGetTrackballDeltaX;

typedef int32_t (MTR_CALL * mtrGameControllerGetTrackballDeltaYFunc)(uint8_t,
 uint8_t);
mtrGameControllerGetTrackballDeltaYFunc mtrGameControllerGetTrackballDeltaY;

typedef void (MTR_CALL * mtrGameControllerGetTrackballDeltaXYFunc)(uint8_t,
 uint8_t, int32_t *, int32_t *);
mtrGameControllerGetTrackballDeltaXYFunc mtrGameControllerGetTrackballDeltaXY;

typedef uint8_t (MTR_CALL * mtrGameControllerGetPovHatFunc)(uint8_t, uint8_t);
mtrGameControllerGetPovHatFunc mtrGameControllerGetPovHat;

int mtrSF_GameControllerInit(lua_State* l);
int mtrSF_GameControllerQuit(lua_State* l);
int mtrSF_GameControllerRefresh(lua_State* l);
int mtrSF_GameControllerButtonPress(lua_State* l);
int mtrSF_GameControllerButtonRelease(lua_State* l);
int mtrSF_GameControllerButtonPressed(lua_State* l);
int mtrSF_GameControllerGetAxis(lua_State* l);
int mtrSF_GameControllerGetAxis_f(lua_State* l);
int mtrSF_GameControllerGetAxisDelta(lua_State* l);
int mtrSF_GameControllerGetAxisDelta_f(lua_State* l);
int mtrSF_GameControllerGetTrackballDeltaX(lua_State* l);
int mtrSF_GameControllerGetTrackballDeltaY(lua_State* l);
int mtrSF_GameControllerGetTrackballDeltaXY(lua_State* l);
int mtrSF_GameControllerGetPovHat(lua_State* l);

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
