#ifndef MTR_MOUSE_SDL2_LUA52
#define MTR_MOUSE_SDL2_LUA52

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "SDL2/SDL.h"

#include "marathoner/plugin.h"

lua_State *mtrVm;

typedef lua_State* (MRT_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MRT_CALL * mtrScriptsRegisterFunctionFunc)(lua_CFunction, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (MRT_CALL * mtrScriptsRegisterNumericVariableFunc)(char *, double);
mtrScriptsRegisterNumericVariableFunc mtrScriptsRegisterNumericVariable;

typedef bool (MRT_CALL * mtrMouseInitFunc)(void);
mtrMouseInitFunc mtrMouseInit;

typedef void (MRT_CALL * mtrMouseRefreshFunc)(void);
mtrMouseRefreshFunc mtrMouseRefresh;

typedef bool (MRT_CALL * mtrMousePressFunc)(uint8_t);
mtrMousePressFunc mtrMousePress;

typedef bool (MRT_CALL * mtrMouseReleaseFunc)(uint8_t);
mtrMouseReleaseFunc mtrMouseRelease;

typedef bool (MRT_CALL * mtrMousePressedFunc)(uint8_t);
mtrMousePressedFunc mtrMousePressed;

typedef uint8_t (MRT_CALL * mtrMouseGetWheelRelativeFunc)(void);
mtrMouseGetWheelRelativeFunc mtrMouseGetWheelRelative;

typedef int16_t (MRT_CALL * mtrMouseGetXFunc)(void);
mtrMouseGetXFunc mtrMouseGetX;

typedef int16_t (MRT_CALL * mtrMouseGetYFunc)(void);
mtrMouseGetYFunc mtrMouseGetY;

typedef void (MRT_CALL * mtrMouseGetXYFunc)(int16_t *, int16_t *);
mtrMouseGetXYFunc mtrMouseGetXY;

typedef int16_t (MRT_CALL * mtrMouseGetDeltaXFunc)(void);
mtrMouseGetDeltaXFunc mtrMouseGetDeltaX;

typedef int16_t (MRT_CALL * mtrMouseGetDeltaYFunc)(void);
mtrMouseGetDeltaYFunc mtrMouseGetDeltaY;

typedef void (MRT_CALL * mtrMouseGetDeltaXYFunc)(int16_t *, int16_t *);
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


