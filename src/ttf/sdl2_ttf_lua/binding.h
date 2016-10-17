#ifndef MTR_TTF_SDL2_TTF_LUA
#define MTR_TTF_SDL2_TTF_LUA

#include "SDL2/SDL_ttf.h"

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "marathoner/plugin.h"

#define MTR_FS_NORMAL           TTF_STYLE_NORMAL
#define MTR_FS_BOLD             TTF_STYLE_BOLD
#define MTR_FS_ITALIC           TTF_STYLE_ITALIC
#define MTR_FS_UNDERLINE        TTF_STYLE_UNDERLINE
#define MTR_FS_STRIKETHROUGH    TTF_STYLE_STRIKETHROUGH

lua_State *mtrVm;

typedef lua_State* (MTR_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(lua_CFunction, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (MTR_CALL * mtrScriptsRegisterNumericVariableFunc)(char *, double);
mtrScriptsRegisterNumericVariableFunc mtrScriptsRegisterNumericVariable;

typedef bool (MTR_CALL * mtrTtfInitFunc)(int, int);
mtrTtfInitFunc mtrTtfInit;

typedef void (MTR_CALL * mtrTtfQuitFunc)(void);
mtrTtfQuitFunc mtrTtfQuit;

typedef int (MTR_CALL * mtrTtfLoadFunc)(const char *, int);
mtrTtfLoadFunc mtrTtfLoad;

typedef void (MTR_CALL * mtrTtfFreeFunc)(int);
mtrTtfFreeFunc mtrTtfFree;

typedef void (MTR_CALL * mtrTtfSetFontStyleFunc)(int, int);
mtrTtfSetFontStyleFunc mtrTtfSetFontStyle;

typedef void (MTR_CALL * mtrTtfSetFontOutlineFunc)(int, int);
mtrTtfSetFontOutlineFunc mtrTtfSetFontOutline;

#endif
