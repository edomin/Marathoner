#ifndef MTR_GAME_CONTROLLER_SDL2_LUA52
#define MTR_GAME_CONTROLLER_SDL2_LUA52

#define MTR_PLUGIN
#include "marathoner.h"

#include <stdint.h>
#include <stdbool.h>

#include "SDL2/SDL.h"

#include "lua52/lua.h"
#include "lua52/lualib.h"
#include "lua52/lauxlib.h"

lua_State *mtrVm;

typedef lua_State* (__stdcall * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (__stdcall * mtrScriptsRegisterFunctionFunc)(lua_CFunction, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (__stdcall * mtrScriptsRegisterNumericVariableFunc)(char *, double);
mtrScriptsRegisterNumericVariableFunc mtrScriptsRegisterNumericVariable;

typedef bool (__stdcall * mtrGameControllerInitFunc)(void);
mtrGameControllerInitFunc mtrGameControllerInit;

typedef void (__stdcall * mtrGameControllerQuitFunc)(void);
mtrGameControllerQuitFunc mtrGameControllerQuit;

typedef void (__stdcall * mtrGameControllerRefreshFunc)(void);
mtrGameControllerRefreshFunc mtrGameControllerRefresh;

typedef bool (__stdcall * mtrGameControllerButtonPressFunc)(uint8_t, uint8_t);
mtrGameControllerButtonPressFunc mtrGameControllerButtonPress;

typedef bool (__stdcall * mtrGameControllerButtonReleaseFunc)(uint8_t, uint8_t);
mtrGameControllerButtonReleaseFunc mtrGameControllerButtonRelease;

typedef bool (__stdcall * mtrGameControllerButtonPressedFunc)(uint8_t, uint8_t);
mtrGameControllerButtonPressedFunc mtrGameControllerButtonPressed;

typedef int16_t (__stdcall * mtrGameControllerGetAxisFunc)(uint8_t, uint8_t);
mtrGameControllerGetAxisFunc mtrGameControllerGetAxis;

typedef float (__stdcall * mtrGameControllerGetAxis_fFunc)(uint8_t, uint8_t);
mtrGameControllerGetAxis_fFunc mtrGameControllerGetAxis_f;

typedef int32_t (__stdcall * mtrGameControllerGetAxisDeltaFunc)(uint8_t,
 uint8_t);
mtrGameControllerGetAxisDeltaFunc mtrGameControllerGetAxisDelta;

typedef float (__stdcall * mtrGameControllerGetAxisDelta_fFunc)(uint8_t,
 uint8_t);
mtrGameControllerGetAxisDelta_fFunc mtrGameControllerGetAxisDelta_f;

typedef int32_t (__stdcall * mtrGameControllerGetTrackballDeltaXFunc)(uint8_t,
 uint8_t);
mtrGameControllerGetTrackballDeltaXFunc mtrGameControllerGetTrackballDeltaX;

typedef int32_t (__stdcall * mtrGameControllerGetTrackballDeltaYFunc)(uint8_t,
 uint8_t);
mtrGameControllerGetTrackballDeltaYFunc mtrGameControllerGetTrackballDeltaY;

typedef void (__stdcall * mtrGameControllerGetTrackballDeltaXYFunc)(uint8_t,
 uint8_t, int32_t *, int32_t *);
mtrGameControllerGetTrackballDeltaXYFunc mtrGameControllerGetTrackballDeltaXY;

typedef uint8_t (__stdcall * mtrGameControllerGetPovHatFunc)(uint8_t,
 uint8_t);
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
