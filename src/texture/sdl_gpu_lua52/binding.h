#ifndef MTR_TEXTURE_SDL_GPU_LUA52
#define MTR_TEXTURE_SDL_GPU_LUA52

#define MTR_PLUGIN
#include "marathoner.h"

#include "bool/bool.h"

#include "lua52/lua.h"
#include "lua52/lualib.h"
#include "lua52/lauxlib.h"

lua_State *mtrVm;

typedef lua_State* (__stdcall * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (__stdcall * mtrScriptsRegisterFunctionFunc)(lua_CFunction, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef bool (__stdcall * mtrTextureInitFunc)(uint32_t, uint32_t);
mtrTextureInitFunc mtrTextureInit;

typedef uint32_t (__stdcall * mtrTextureLoadFunc)(const char *);
mtrTextureLoadFunc mtrTextureLoad;

typedef void (__stdcall * mtrTextureFreeFunc)(uint32_t);
mtrTextureFreeFunc mtrTextureFree;

typedef void (__stdcall * mtrTextureBlit_fFunc)(uint32_t, float, float);
mtrTextureBlit_fFunc mtrTextureBlit_f;

int mtrSF_TextureInit(lua_State* l);
int mtrSF_TextureLoad(lua_State* l);
int mtrSF_TextureFree(lua_State* l);
int mtrSF_TextureBlit_f(lua_State* l);

#endif
