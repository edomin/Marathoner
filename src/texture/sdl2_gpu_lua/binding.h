#ifndef MTR_TEXTURE_SDL2_GPU_LUA
#define MTR_TEXTURE_SDL2_GPU_LUA

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "marathoner/plugin.h"

#define MTR_FLIP_NONE       0
#define MTR_FLIP_HORIZONTAL 1
#define MTR_FLIP_VERTICAL   2
#define MTR_FLIP_BOTH       3

#define MTR_BLEND_ZERO                  0
#define MTR_BLEND_ONE                   1
#define MTR_BLEND_SRC_COLOR             2
#define MTR_BLEND_DST_COLOR             3
#define MTR_BLEND_ONE_MINUS_SRC         4
#define MTR_BLEND_ONE_MINUS_DST         5
#define MTR_BLEND_SRC_ALPHA             6
#define MTR_BLEND_DST_ALPHA             7
#define MTR_BLEND_ONE_MINUS_SRC_ALPHA   8
#define MTR_BLEND_ONE_MINUS_DST_ALPHA   9

lua_State *mtrVm;

typedef lua_State* (MTR_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(lua_CFunction, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (MTR_CALL * mtrScriptsRegisterNumericVariableFunc)(char *, double);
mtrScriptsRegisterNumericVariableFunc mtrScriptsRegisterNumericVariable;

typedef bool (MTR_CALL * mtrTextureInitFunc)(int, int);
mtrTextureInitFunc mtrTextureInit;

typedef int (MTR_CALL * mtrTextureLoadFunc)(const char *);
mtrTextureLoadFunc mtrTextureLoad;

typedef void (MTR_CALL * mtrTextureFreeFunc)(int);
mtrTextureFreeFunc mtrTextureFree;

typedef void (MTR_CALL * mtrTextureSetBlendFunctionFunc)(int, int, int, int,
 int);
mtrTextureSetBlendFunctionFunc mtrTextureSetBlendFunction;

typedef void (MTR_CALL * mtrTextureSetAlphaBlendingFunc)(int, bool);
mtrTextureSetAlphaBlendingFunc mtrTextureSetAlphaBlending;

typedef void (MTR_CALL * mtrTextureBlit_fFunc)(int, float, float);
mtrTextureBlit_fFunc mtrTextureBlit_f;

typedef void (MTR_CALL * mtrTextureBlitRegion_fFunc)(int, float, float, float,
 float, float, float);
mtrTextureBlitRegion_fFunc mtrTextureBlitRegion_f;

typedef void (MTR_CALL * mtrTextureBlitRegionScaled_fFunc)(int, float, float,
 float, float, float, float, float, float);
mtrTextureBlitRegionScaled_fFunc mtrTextureBlitRegionScaled_f;

typedef void (MTR_CALL * mtrTextureBlitRegionAngled_fFunc)(int, float, float,
 float, float, float, float, float, float, float);
mtrTextureBlitRegionAngled_fFunc mtrTextureBlitRegionAngled_f;

typedef void (MTR_CALL * mtrTextureBlitRegionFlipped_fFunc)(int, float, float,
 float, float, float, float, int);
mtrTextureBlitRegionFlipped_fFunc mtrTextureBlitRegionFlipped_f;

typedef void (MTR_CALL * mtrTextureBlitRegionGeneral_fFunc)(int, float, float,
 float, float, float, float, float, float, float, float, float, int);
mtrTextureBlitRegionGeneral_fFunc mtrTextureBlitRegionGeneral_f;

#endif
