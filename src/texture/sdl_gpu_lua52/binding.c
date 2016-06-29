#include "binding.h"

#include "plugin_common.c"

__declspec(dllexport) mtrReport* __stdcall mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Texture_sdl_gpu_Lua52";
    report->version = 0x000000;
    report->prereqsCount = 2;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    report->prereqs[0] = "Texture_sdl_gpu";
    report->prereqs[1] = "Script_Lua52";
    return report;
}

__declspec(dllexport) void __stdcall mtrPluginInit(void)
{
    bool ok;
    ok = true;

    mtrLogWrite_s("Reporting Lua compile-time version:", 1, MTR_LMT_INFO,
     LUA_RELEASE);

    mtrScriptsRegisterFunction = (mtrScriptsRegisterFunctionFunc)mtrFindFunction("Script_Lua52",
     "mtrScriptsRegisterFunction");
    if (mtrScriptsRegisterFunction == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrScriptsRegisterFunction");
        ok = false;
    }
    mtrScriptsRegisterNumericVariable = (mtrScriptsRegisterNumericVariableFunc)mtrFindFunction("Script_Lua52",
     "mtrScriptsRegisterNumericVariable");
    if (mtrScriptsRegisterNumericVariable == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrScriptsRegisterNumericVariable");
        ok = false;
    }
    mtrScriptsGetVm = (mtrScriptsGetVmFunc)mtrFindFunction("Script_Lua52",
     "mtrScriptsGetVm");
    if (mtrScriptsGetVm == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrScriptsGetVm");
        ok = false;
    }
    else
    {
        mtrVm = mtrScriptsGetVm();
        mtrTextureInit = (mtrTextureInitFunc)mtrFindFunction("Texture_sdl_gpu",
          "mtrTextureInit");
        if (mtrTextureInit == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTextureInit");
            ok = false;
        }
        mtrTextureLoad = (mtrTextureLoadFunc)mtrFindFunction("Texture_sdl_gpu",
          "mtrTextureLoad");
        if (mtrTextureLoad == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTextureLoad");
            ok = false;
        }
        mtrTextureFree = (mtrTextureFreeFunc)mtrFindFunction("Texture_sdl_gpu",
          "mtrTextureFree");
        if (mtrTextureFree == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTextureFree");
            ok = false;
        }
        mtrTextureBlit_f = (mtrTextureBlit_fFunc)mtrFindFunction("Texture_sdl_gpu",
          "mtrTextureBlit_f");
        if (mtrTextureBlit_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTextureBlit_f");
            ok = false;
        }
        mtrTextureBlitRegion_f = (mtrTextureBlitRegion_fFunc)mtrFindFunction("Texture_sdl_gpu",
          "mtrTextureBlitRegion_f");
        if (mtrTextureBlitRegion_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTextureBlitRegion_f");
            ok = false;
        }
        mtrTextureBlitRegionScaled_f = (mtrTextureBlitRegionScaled_fFunc)mtrFindFunction("Texture_sdl_gpu",
          "mtrTextureBlitRegionScaled_f");
        if (mtrTextureBlitRegionScaled_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTextureBlitRegionScaled_f");
            ok = false;
        }
        mtrTextureBlitRegionAngled_f = (mtrTextureBlitRegionAngled_fFunc)mtrFindFunction("Texture_sdl_gpu",
          "mtrTextureBlitRegionAngled_f");
        if (mtrTextureBlitRegionAngled_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTextureBlitRegionAngled_f");
            ok = false;
        }
        mtrTextureBlitRegionFlipped_f = (mtrTextureBlitRegionFlipped_fFunc)mtrFindFunction("Texture_sdl_gpu",
          "mtrTextureBlitRegionFlipped_f");
        if (mtrTextureBlitRegionFlipped_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTextureBlitRegionFlipped_f");
            ok = false;
        }
        mtrTextureBlitRegionGeneral_f = (mtrTextureBlitRegionGeneral_fFunc)mtrFindFunction("Texture_sdl_gpu",
          "mtrTextureBlitRegionGeneral_f");
        if (mtrTextureBlitRegionGeneral_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTextureBlitRegionGeneral_f");
            ok = false;
        }
        if (ok)
        {
            mtrScriptsRegisterNumericVariable("FLIP_NONE", MTR_FLIP_NONE);
            mtrScriptsRegisterNumericVariable("FLIP_HORIZONTAL", MTR_FLIP_HORIZONTAL);
            mtrScriptsRegisterNumericVariable("FLIP_VERTICAL", MTR_FLIP_VERTICAL);
            mtrScriptsRegisterNumericVariable("FLIP_BOTH", MTR_FLIP_BOTH);
            mtrScriptsRegisterFunction(mtrSF_TextureInit, "TextureInit");
            mtrScriptsRegisterFunction(mtrSF_TextureLoad, "TextureLoad");
            mtrScriptsRegisterFunction(mtrSF_TextureFree, "TextureFree");
            mtrScriptsRegisterFunction(mtrSF_TextureBlit_f, "TextureBlit_f");
            mtrScriptsRegisterFunction(mtrSF_TextureBlitRegion_f,
             "TextureBlitRegion_f");
            mtrScriptsRegisterFunction(mtrSF_TextureBlitRegionScaled_f,
             "TextureBlitRegionScaled_f");
            mtrScriptsRegisterFunction(mtrSF_TextureBlitRegionAngled_f,
             "TextureBlitRegionAngled_f");
            mtrScriptsRegisterFunction(mtrSF_TextureBlitRegionFlipped_f,
             "TextureBlitRegionFlipped_f");
            mtrScriptsRegisterFunction(mtrSF_TextureBlitRegionGeneral_f,
             "TextureBlitRegionGeneral_f");
        }
        else
        {
            mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
        }
    }
}

int mtrSF_TextureInit(lua_State* l)
{
    uint32_t dmSize = lua_tonumber(mtrVm, 1);
    uint32_t reservedCount = lua_tonumber(mtrVm, 2);
    bool     success = mtrTextureInit(dmSize, reservedCount);
    lua_pushboolean(mtrVm, success);

    return 1;
}

int mtrSF_TextureLoad(lua_State* l)
{
    const char *filename = lua_tostring(mtrVm, 1);
    uint32_t    texNum = mtrTextureLoad(filename);
    lua_pushnumber(mtrVm, texNum);

    return 1;
}

int mtrSF_TextureFree(lua_State* l)
{
    uint32_t texNum = lua_tonumber(mtrVm, 1);
    mtrTextureFree(texNum);

    return 0;
}

int mtrSF_TextureBlit_f(lua_State* l)
{
    uint32_t texNum = lua_tonumber(mtrVm, 1);
    float x = (float)lua_tonumber(mtrVm, 2);
    float y = (float)lua_tonumber(mtrVm, 3);
    mtrTextureBlit_f(texNum, x, y);

    return 0;
}

int mtrSF_TextureBlitRegion_f(lua_State* l)
{
    uint32_t texNum = lua_tonumber(mtrVm, 1);
    float x = (float)lua_tonumber(mtrVm, 2);
    float y = (float)lua_tonumber(mtrVm, 3);
    float rx = (float)lua_tonumber(mtrVm, 4);
    float ry = (float)lua_tonumber(mtrVm, 5);
    float rw = (float)lua_tonumber(mtrVm, 6);
    float rh = (float)lua_tonumber(mtrVm, 7);
    mtrTextureBlitRegion_f(texNum, x, y, rx, ry, rw, rh);

    return 0;
}

int mtrSF_TextureBlitRegionScaled_f(lua_State* l)
{
    uint32_t texNum = lua_tonumber(mtrVm, 1);
    float x = (float)lua_tonumber(mtrVm, 2);
    float y = (float)lua_tonumber(mtrVm, 3);
    float w = (float)lua_tonumber(mtrVm, 4);
    float h = (float)lua_tonumber(mtrVm, 5);
    float rx = (float)lua_tonumber(mtrVm, 6);
    float ry = (float)lua_tonumber(mtrVm, 7);
    float rw = (float)lua_tonumber(mtrVm, 8);
    float rh = (float)lua_tonumber(mtrVm, 9);
    mtrTextureBlitRegionScaled_f(texNum, x, y, w, h, rx, ry, rw, rh);

    return 0;
}

int mtrSF_TextureBlitRegionAngled_f(lua_State* l)
{
    uint32_t texNum = lua_tonumber(mtrVm, 1);
    float x = (float)lua_tonumber(mtrVm, 2);
    float y = (float)lua_tonumber(mtrVm, 3);
    float rx = (float)lua_tonumber(mtrVm, 4);
    float ry = (float)lua_tonumber(mtrVm, 5);
    float rw = (float)lua_tonumber(mtrVm, 6);
    float rh = (float)lua_tonumber(mtrVm, 7);
    float angle = (float)lua_tonumber(mtrVm, 8);
    float pivotX = (float)lua_tonumber(mtrVm, 9);
    float pivotY = (float)lua_tonumber(mtrVm, 10);
    mtrTextureBlitRegionAngled_f(texNum, x, y, rx, ry, rw, rh, angle, pivotX,
     pivotY);

    return 0;
}

int mtrSF_TextureBlitRegionFlipped_f(lua_State* l)
{
    uint32_t texNum = lua_tonumber(mtrVm, 1);
    float x = (float)lua_tonumber(mtrVm, 2);
    float y = (float)lua_tonumber(mtrVm, 3);
    float rx = (float)lua_tonumber(mtrVm, 4);
    float ry = (float)lua_tonumber(mtrVm, 5);
    float rw = (float)lua_tonumber(mtrVm, 6);
    float rh = (float)lua_tonumber(mtrVm, 7);
    uint32_t flip = lua_tonumber(mtrVm, 8);
    mtrTextureBlitRegionFlipped_f(texNum, x, y, rx, ry, rw, rh, flip);

    return 0;
}

int mtrSF_TextureBlitRegionGeneral_f(lua_State* l)
{
    uint32_t texNum = lua_tonumber(mtrVm, 1);
    float x = (float)lua_tonumber(mtrVm, 2);
    float y = (float)lua_tonumber(mtrVm, 3);
    float w = (float)lua_tonumber(mtrVm, 4);
    float h = (float)lua_tonumber(mtrVm, 5);
    float rx = (float)lua_tonumber(mtrVm, 6);
    float ry = (float)lua_tonumber(mtrVm, 7);
    float rw = (float)lua_tonumber(mtrVm, 8);
    float rh = (float)lua_tonumber(mtrVm, 9);
    float angle = (float)lua_tonumber(mtrVm, 10);
    float pivotX = (float)lua_tonumber(mtrVm, 11);
    float pivotY = (float)lua_tonumber(mtrVm, 12);
    uint32_t flip = lua_tonumber(mtrVm, 13);
    mtrTextureBlitRegionGeneral_f(texNum, x, y, w, h, rx, ry, rw, rh, angle,
     pivotX, pivotY, flip);

    return 0;
}
