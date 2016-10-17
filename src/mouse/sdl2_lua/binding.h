#ifndef MTR_MOUSE_SDL2_LUA
#define MTR_MOUSE_SDL2_LUA

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

typedef bool (MTR_CALL * mtrMousePressFunc)(int);
mtrMousePressFunc mtrMousePress;

typedef bool (MTR_CALL * mtrMouseReleaseFunc)(int);
mtrMouseReleaseFunc mtrMouseRelease;

typedef bool (MTR_CALL * mtrMousePressedFunc)(int);
mtrMousePressedFunc mtrMousePressed;

typedef int (MTR_CALL * mtrMouseGetWheelRelativeFunc)(void);
mtrMouseGetWheelRelativeFunc mtrMouseGetWheelRelative;

typedef int (MTR_CALL * mtrMouseGetXFunc)(void);
mtrMouseGetXFunc mtrMouseGetX;

typedef int (MTR_CALL * mtrMouseGetYFunc)(void);
mtrMouseGetYFunc mtrMouseGetY;

typedef void (MTR_CALL * mtrMouseGetXYFunc)(int *, int *);
mtrMouseGetXYFunc mtrMouseGetXY;

typedef int (MTR_CALL * mtrMouseGetDeltaXFunc)(void);
mtrMouseGetDeltaXFunc mtrMouseGetDeltaX;

typedef int (MTR_CALL * mtrMouseGetDeltaYFunc)(void);
mtrMouseGetDeltaYFunc mtrMouseGetDeltaY;

typedef void (MTR_CALL * mtrMouseGetDeltaXYFunc)(int *, int *);
mtrMouseGetDeltaXYFunc mtrMouseGetDeltaXY;

#define MTR_MOUSE_LEFT   SDL_BUTTON_LEFT
#define MTR_MOUSE_RIGHT  SDL_BUTTON_RIGHT
#define MTR_MOUSE_MIDDLE SDL_BUTTON_MIDDLE
#define MTR_MOUSE_X1     SDL_BUTTON_X1
#define MTR_MOUSE_X2     SDL_BUTTON_X2

#endif
