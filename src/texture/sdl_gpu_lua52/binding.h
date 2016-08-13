#ifndef MTR_TEXTURE_SDL_GPU_LUA52
#define MTR_TEXTURE_SDL_GPU_LUA52

#include "marathoner/plugin.h"

#include <stdbool.h>

#include "lua52/lua.h"
#include "lua52/lualib.h"
#include "lua52/lauxlib.h"

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

typedef lua_State* (__stdcall * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (__stdcall * mtrScriptsRegisterFunctionFunc)(lua_CFunction, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (__stdcall * mtrScriptsRegisterNumericVariableFunc)(char *, double);
mtrScriptsRegisterNumericVariableFunc mtrScriptsRegisterNumericVariable;

typedef bool (__stdcall * mtrTextureInitFunc)(uint32_t, uint32_t);
mtrTextureInitFunc mtrTextureInit;

typedef uint32_t (__stdcall * mtrTextureLoadFunc)(const char *);
mtrTextureLoadFunc mtrTextureLoad;

typedef void (__stdcall * mtrTextureFreeFunc)(uint32_t);
mtrTextureFreeFunc mtrTextureFree;

typedef void (__stdcall * mtrTextureSetBlendFunctionFunc)(uint32_t, uint8_t,
 uint8_t, uint8_t, uint8_t);
mtrTextureSetBlendFunctionFunc mtrTextureSetBlendFunction;

typedef void (__stdcall * mtrTextureSetAlphaBlendingFunc)(uint32_t, bool);
mtrTextureSetAlphaBlendingFunc mtrTextureSetAlphaBlending;

typedef void (__stdcall * mtrTextureBlit_fFunc)(uint32_t, float, float);
mtrTextureBlit_fFunc mtrTextureBlit_f;

typedef void (__stdcall * mtrTextureBlitRegion_fFunc)(uint32_t, float, float,
 float, float, float, float);
mtrTextureBlitRegion_fFunc mtrTextureBlitRegion_f;

typedef void (__stdcall * mtrTextureBlitRegionScaled_fFunc)(uint32_t, float,
 float, float, float, float, float, float, float);
mtrTextureBlitRegionScaled_fFunc mtrTextureBlitRegionScaled_f;

typedef void (__stdcall * mtrTextureBlitRegionAngled_fFunc)(uint32_t, float,
 float, float, float, float, float, float, float, float);
mtrTextureBlitRegionAngled_fFunc mtrTextureBlitRegionAngled_f;

typedef void (__stdcall * mtrTextureBlitRegionFlipped_fFunc)(uint32_t, float,
 float, float, float, float, float, uint8_t);
mtrTextureBlitRegionFlipped_fFunc mtrTextureBlitRegionFlipped_f;

typedef void (__stdcall * mtrTextureBlitRegionGeneral_fFunc)(uint32_t, float,
 float, float, float, float, float, float, float, float, float, float, uint8_t);
mtrTextureBlitRegionGeneral_fFunc mtrTextureBlitRegionGeneral_f;

int mtrSF_TextureInit(lua_State* l);
int mtrSF_TextureLoad(lua_State* l);
int mtrSF_TextureFree(lua_State* l);
int mtrSF_TextureSetBlendFunction(lua_State* l);
int mtrSF_TextureSetAlphaBlending(lua_State* l);
int mtrSF_TextureBlit_f(lua_State* l);
int mtrSF_TextureBlitRegion_f(lua_State* l);
int mtrSF_TextureBlitRegionScaled_f(lua_State* l);
int mtrSF_TextureBlitRegionAngled_f(lua_State* l);
int mtrSF_TextureBlitRegionFlipped_f(lua_State* l);
int mtrSF_TextureBlitRegionGeneral_f(lua_State* l);

#endif
