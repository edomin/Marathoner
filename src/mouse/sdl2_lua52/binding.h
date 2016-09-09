#ifndef MTR_MOUSE_SDL2_LUA52
#define MTR_MOUSE_SDL2_LUA52

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "SDL2/SDL.h"

#include "marathoner/plugin.h"

lua_State *mtrVm;

typedef lua_State* (MTR_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(lua_CFunction, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (MTR_CALL * mtrScriptsRegisterNumericVariableFunc)(char *, double);
mtrScriptsRegisterNumericVariableFunc mtrScriptsRegisterNumericVariable;

typedef bool (MTR_CALL * mtrMouseInitFunc)(void);
mtrMouseInitFunc mtrMouseInit;

typedef void (MTR_CALL * mtrMouseRefreshFunc)(void);
mtrMouseRefreshFunc mtrMouseRefresh;

typedef bool (MTR_CALL * mtrMousePressFunc)(uint8_t);
mtrMousePressFunc mtrMousePress;

typedef bool (MTR_CALL * mtrMouseReleaseFunc)(uint8_t);
mtrMouseReleaseFunc mtrMouseRelease;

typedef bool (MTR_CALL * mtrMousePressedFunc)(uint8_t);
mtrMousePressedFunc mtrMousePressed;

typedef uint8_t (MTR_CALL * mtrMouseGetWheelRelativeFunc)(void);
mtrMouseGetWheelRelativeFunc mtrMouseGetWheelRelative;

typedef int16_t (MTR_CALL * mtrMouseGetXFunc)(void);
mtrMouseGetXFunc mtrMouseGetX;

typedef int16_t (MTR_CALL * mtrMouseGetYFunc)(void);
mtrMouseGetYFunc mtrMouseGetY;

typedef void (MTR_CALL * mtrMouseGetXYFunc)(int16_t *, int16_t *);
mtrMouseGetXYFunc mtrMouseGetXY;

typedef int16_t (MTR_CALL * mtrMouseGetDeltaXFunc)(void);
mtrMouseGetDeltaXFunc mtrMouseGetDeltaX;

typedef int16_t (MTR_CALL * mtrMouseGetDeltaYFunc)(void);
mtrMouseGetDeltaYFunc mtrMouseGetDeltaY;

typedef void (MTR_CALL * mtrMouseGetDeltaXYFunc)(int16_t *, int16_t *);
mtrMouseGetDeltaXYFunc mtrMouseGetDeltaXY;

int mtrSF_MouseInit(lua_State* l);
int mtrSF_MouseRefresh(lua_State* l);
int mtrSF_MousePress(lua_State* l);
int mtrSF_MouseRelease(lua_State* l);
int mtrSF_MousePressed(lua_State* l);
int mtrSF_MouseGetWheelRelative(lua_State* l);
int mtrSF_MouseGetX(lua_State* l);
int mtrSF_MouseGetY(lua_State* l);
int mtrSF_MouseGetXY(lua_State* l);
int mtrSF_MouseGetDeltaX(lua_State* l);
int mtrSF_MouseGetDeltaY(lua_State* l);
int mtrSF_MouseGetDeltaXY(lua_State* l);

#define MTR_MOUSE_LEFT   SDL_BUTTON_LEFT
#define MTR_MOUSE_RIGHT  SDL_BUTTON_RIGHT
#define MTR_MOUSE_MIDDLE SDL_BUTTON_MIDDLE
#define MTR_MOUSE_X1     SDL_BUTTON_X1
#define MTR_MOUSE_X2     SDL_BUTTON_X2

#endif


