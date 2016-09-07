#ifndef MTR_GAME_CONTROLLER_SDL2_LUA52
#define MTR_GAME_CONTROLLER_SDL2_LUA52

#include "SDL2/SDL.h"

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "marathoner/plugin.h"

lua_State *mtrVm;

typedef lua_State* (MRT_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MRT_CALL * mtrScriptsRegisterFunctionFunc)(lua_CFunction, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (MRT_CALL * mtrScriptsRegisterNumericVariableFunc)(char *, double);
mtrScriptsRegisterNumericVariableFunc mtrScriptsRegisterNumericVariable;

typedef bool (MRT_CALL * mtrGameControllerInitFunc)(void);
mtrGameControllerInitFunc mtrGameControllerInit;

typedef void (MRT_CALL * mtrGameControllerQuitFunc)(void);
mtrGameControllerQuitFunc mtrGameControllerQuit;

typedef void (MRT_CALL * mtrGameControllerRefreshFunc)(void);
mtrGameControllerRefreshFunc mtrGameControllerRefresh;

typedef bool (MRT_CALL * mtrGameControllerButtonPressFunc)(uint8_t, uint8_t);
mtrGameControllerButtonPressFunc mtrGameControllerButtonPress;

typedef bool (MRT_CALL * mtrGameControllerButtonReleaseFunc)(uint8_t, uint8_t);
mtrGameControllerButtonReleaseFunc mtrGameControllerButtonRelease;

typedef bool (MRT_CALL * mtrGameControllerButtonPressedFunc)(uint8_t, uint8_t);
mtrGameControllerButtonPressedFunc mtrGameControllerButtonPressed;

typedef int16_t (MRT_CALL * mtrGameControllerGetAxisFunc)(uint8_t, uint8_t);
mtrGameControllerGetAxisFunc mtrGameControllerGetAxis;

typedef float (MRT_CALL * mtrGameControllerGetAxis_fFunc)(uint8_t, uint8_t);
mtrGameControllerGetAxis_fFunc mtrGameControllerGetAxis_f;

typedef int32_t (MRT_CALL * mtrGameControllerGetAxisDeltaFunc)(uint8_t,
 uint8_t);
mtrGameControllerGetAxisDeltaFunc mtrGameControllerGetAxisDelta;

typedef float (MRT_CALL * mtrGameControllerGetAxisDelta_fFunc)(uint8_t,
 uint8_t);
mtrGameControllerGetAxisDelta_fFunc mtrGameControllerGetAxisDelta_f;

typedef int32_t (MRT_CALL * mtrGameControllerGetTrackballDeltaXFunc)(uint8_t,
 uint8_t);
mtrGameControllerGetTrackballDeltaXFunc mtrGameControllerGetTrackballDeltaX;

typedef int32_t (MRT_CALL * mtrGameControllerGetTrackballDeltaYFunc)(uint8_t,
 uint8_t);
mtrGameControllerGetTrackballDeltaYFunc mtrGameControllerGetTrackballDeltaY;

typedef void (MRT_CALL * mtrGameControllerGetTrackballDeltaXYFunc)(uint8_t,
 uint8_t, int32_t *, int32_t *);
mtrGameControllerGetTrackballDeltaXYFunc mtrGameControllerGetTrackballDeltaXY;

typedef uint8_t (MRT_CALL * mtrGameControllerGetPovHatFunc)(uint8_t, uint8_t);
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
