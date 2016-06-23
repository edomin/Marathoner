#include "binding.h"

#include "plugin_common.c"

__declspec(dllexport) mtrReport* __stdcall mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Texture_sdl_gpu_Lua52";
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
    mtrScriptsRegisterFunction = (mtrScriptsRegisterFunctionFunc)mtrFindFunction("Script_Lua52", "mtrScriptsRegisterFunction");
    if (mtrScriptsRegisterFunction == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrScriptsRegisterFunction");
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
        if (ok)
        {
            mtrScriptsRegisterFunction(mtrSF_TextureInit, "TextureInit");
            mtrScriptsRegisterFunction(mtrSF_TextureLoad, "TextureLoad");
            mtrScriptsRegisterFunction(mtrSF_TextureFree, "TextureFree");
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
