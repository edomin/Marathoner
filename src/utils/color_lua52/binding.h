#ifndef MTR_PRIMITIVE_SDL_GPU_LUA52
#define MTR_PRIMITIVE_SDL_GPU_LUA52

#include "marathoner/plugin.h"
#include "marathoner/colors.h"

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

typedef uint32_t (__stdcall * mtrColorAssembleRGBFunc)(uint8_t, uint8_t, uint8_t);
mtrColorAssembleRGBFunc mtrColorAssembleRGB;

typedef uint32_t (__stdcall * mtrColorAssembleRGBAFunc)(uint8_t, uint8_t, uint8_t, uint8_t);
mtrColorAssembleRGBAFunc mtrColorAssembleRGBA;

typedef void (__stdcall * mtrColorSplitRGBFunc)(uint32_t, uint8_t *, uint8_t *, uint8_t *);
mtrColorSplitRGBFunc mtrColorSplitRGB;

typedef void (__stdcall * mtrColorSplitRGBAFunc)(uint32_t, uint8_t *, uint8_t *, uint8_t *, uint8_t *);
mtrColorSplitRGBAFunc mtrColorSplitRGBA;

typedef uint32_t (__stdcall * mtrColorRGBtoRGBAFunc)(uint32_t);
mtrColorRGBtoRGBAFunc mtrColorRGBtoRGBA;

typedef uint32_t (__stdcall * mtrColorRGBAtoRGBFunc)(uint32_t);
mtrColorRGBAtoRGBFunc mtrColorRGBAtoRGB;

int mtrSF_ColorAssembleRGB(lua_State* l);
int mtrSF_ColorAssembleRGBA(lua_State* l);
int mtrSF_ColorSplitRGB(lua_State* l);
int mtrSF_ColorSplitRGBA(lua_State* l);
int mtrSF_ColorRGBtoRGBA(lua_State* l);
int mtrSF_ColorRGBAtoRGB(lua_State* l);

#endif
