#ifndef MTR_TTF_SDL2_TTF_LUA52
#define MTR_TTF_SDL2_TTF_LUA52

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

typedef bool (MTR_CALL * mtrTtfInitFunc)(uint32_t, uint32_t);
mtrTtfInitFunc mtrTtfInit;

typedef void (MTR_CALL * mtrTtfQuitFunc)(void);
mtrTtfQuitFunc mtrTtfQuit;

typedef uint32_t (MTR_CALL * mtrTtfLoadFunc)(const char *, uint16_t);
mtrTtfLoadFunc mtrTtfLoad;

typedef void (MTR_CALL * mtrTtfFreeFunc)(uint32_t);
mtrTtfFreeFunc mtrTtfFree;

typedef void (MTR_CALL * mtrTtfSetFontStyleFunc)(uint32_t, uint8_t);
mtrTtfSetFontStyleFunc mtrTtfSetFontStyle;

typedef void (MTR_CALL * mtrTtfSetFontOutlineFunc)(uint32_t, uint16_t);
mtrTtfSetFontOutlineFunc mtrTtfSetFontOutline;

int mtrSF_TtfInit(lua_State* l);
int mtrSF_TtfQuit(lua_State* l);
int mtrSF_TtfLoad(lua_State* l);
int mtrSF_TtfFree(lua_State* l);
int mtrSF_TtfSetFontStyle(lua_State* l);
int mtrSF_TtfSetFontOutline(lua_State* l);

#endif
