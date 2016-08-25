#ifndef MTR_MOUSE_SDL2_LUA52
#define MTR_MOUSE_SDL2_LUA52

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "SDL2/SDL.h"

#include "marathoner/plugin.h"

lua_State *mtrVm;

typedef lua_State* (__stdcall * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (__stdcall * mtrScriptsRegisterFunctionFunc)(lua_CFunction, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (__stdcall * mtrScriptsRegisterNumericVariableFunc)(char *, double);
mtrScriptsRegisterNumericVariableFunc mtrScriptsRegisterNumericVariable;

typedef bool (__stdcall * mtrMouseInitFunc)(void);
mtrMouseInitFunc mtrMouseInit;

typedef void (__stdcall * mtrMouseRefreshFunc)(void);
mtrMouseRefreshFunc mtrMouseRefresh;

typedef bool (__stdcall * mtrMousePressFunc)(uint8_t);
mtrMousePressFunc mtrMousePress;

typedef bool (__stdcall * mtrMouseReleaseFunc)(uint8_t);
mtrMouseReleaseFunc mtrMouseRelease;

typedef bool (__stdcall * mtrMousePressedFunc)(uint8_t);
mtrMousePressedFunc mtrMousePressed;

typedef uint8_t (__stdcall * mtrMouseGetWheelRelativeFunc)(void);
mtrMouseGetWheelRelativeFunc mtrMouseGetWheelRelative;

typedef int16_t (__stdcall * mtrMouseGetXFunc)(void);
mtrMouseGetXFunc mtrMouseGetX;

typedef int16_t (__stdcall * mtrMouseGetYFunc)(void);
mtrMouseGetYFunc mtrMouseGetY;

typedef void (__stdcall * mtrMouseGetXYFunc)(int16_t *, int16_t *);
mtrMouseGetXYFunc mtrMouseGetXY;

typedef int16_t (__stdcall * mtrMouseGetDeltaXFunc)(void);
mtrMouseGetDeltaXFunc mtrMouseGetDeltaX;

typedef int16_t (__stdcall * mtrMouseGetDeltaYFunc)(void);
mtrMouseGetDeltaYFunc mtrMouseGetDeltaY;

typedef void (__stdcall * mtrMouseGetDeltaXYFunc)(int16_t *, int16_t *);
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


