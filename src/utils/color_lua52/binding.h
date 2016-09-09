#ifndef MTR_PRIMITIVE_SDL_GPU_LUA52
#define MTR_PRIMITIVE_SDL_GPU_LUA52

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "marathoner/plugin.h"
#include "marathoner/colors.h"

lua_State *mtrVm;

typedef lua_State* (MTR_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(lua_CFunction, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (MTR_CALL * mtrScriptsRegisterNumericVariableFunc)(char *, double);
mtrScriptsRegisterNumericVariableFunc mtrScriptsRegisterNumericVariable;

typedef uint32_t (MTR_CALL * mtrColorAssembleRGBFunc)(uint8_t, uint8_t, uint8_t);
mtrColorAssembleRGBFunc mtrColorAssembleRGB;

typedef uint32_t (MTR_CALL * mtrColorAssembleRGBAFunc)(uint8_t, uint8_t, uint8_t, uint8_t);
mtrColorAssembleRGBAFunc mtrColorAssembleRGBA;

typedef void (MTR_CALL * mtrColorSplitRGBFunc)(uint32_t, uint8_t *, uint8_t *, uint8_t *);
mtrColorSplitRGBFunc mtrColorSplitRGB;

typedef void (MTR_CALL * mtrColorSplitRGBAFunc)(uint32_t, uint8_t *, uint8_t *, uint8_t *, uint8_t *);
mtrColorSplitRGBAFunc mtrColorSplitRGBA;

typedef uint32_t (MTR_CALL * mtrColorRGBtoRGBAFunc)(uint32_t);
mtrColorRGBtoRGBAFunc mtrColorRGBtoRGBA;

typedef uint32_t (MTR_CALL * mtrColorRGBAtoRGBFunc)(uint32_t);
mtrColorRGBAtoRGBFunc mtrColorRGBAtoRGB;

int mtrSF_ColorAssembleRGB(lua_State* l);
int mtrSF_ColorAssembleRGBA(lua_State* l);
int mtrSF_ColorSplitRGB(lua_State* l);
int mtrSF_ColorSplitRGBA(lua_State* l);
int mtrSF_ColorRGBtoRGBA(lua_State* l);
int mtrSF_ColorRGBAtoRGB(lua_State* l);

#endif
