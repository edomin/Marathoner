#include "binding.h"

#include "marathoner/plugin_common.c"
#include "../binding_common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Texture_SDL2_gpu_Lua";
    report->version = MTR_VERSION_TEXTURE_SDL2_GPU_LUA;
    report->subsystem = "binding";
    report->prereqsCount = 2;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    report->prereqs[0] = "Texture_SDL2_gpu";
    report->prereqs[1] = "Script_Lua";
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}

MTR_EXPORT void MTR_CALL mtrPluginInit(void)
{
    bool ok;
    ok = true;

    mtrLogWrite_s("Reporting Lua compile-time version:", 3, MTR_LMT_INFO,
     LUA_RELEASE);

    mtrScriptsRegisterFunction = (mtrScriptsRegisterFunctionFunc)mtrFindFunction("Script_Lua",
     "mtrScriptsRegisterFunction");
    if (mtrScriptsRegisterFunction == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrScriptsRegisterFunction");
        ok = false;
    }
    mtrScriptsRegisterNumericVariable = (mtrScriptsRegisterNumericVariableFunc)mtrFindFunction("Script_Lua",
     "mtrScriptsRegisterNumericVariable");
    if (mtrScriptsRegisterNumericVariable == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrScriptsRegisterNumericVariable");
        ok = false;
    }
    mtrScriptsGetVm = (mtrScriptsGetVmFunc)mtrFindFunction("Script_Lua",
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
        mtrTextureInit = (mtrTextureInitFunc)mtrFindFunction("Texture_SDL2_gpu",
          "mtrTextureInit");
        if (mtrTextureInit == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTextureInit");
            ok = false;
        }
        mtrTextureBeginTarget = (mtrTextureBeginTargetFunc)mtrFindFunction("Texture_SDL2_gpu",
          "mtrTextureBeginTarget");
        if (mtrTextureBeginTarget == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTextureBeginTarget");
            ok = false;
        }
        mtrTextureEndTarget = (mtrTextureEndTargetFunc)mtrFindFunction("Texture_SDL2_gpu",
          "mtrTextureEndTarget");
        if (mtrTextureEndTarget == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTextureEndTarget");
            ok = false;
        }
        mtrTextureCreate = (mtrTextureCreateFunc)mtrFindFunction("Texture_SDL2_gpu",
          "mtrTextureCreate");
        if (mtrTextureCreate == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTextureCreate");
            ok = false;
        }
        mtrTextureLoad = (mtrTextureLoadFunc)mtrFindFunction("Texture_SDL2_gpu",
          "mtrTextureLoad");
        if (mtrTextureLoad == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTextureLoad");
            ok = false;
        }
        mtrTextureFree = (mtrTextureFreeFunc)mtrFindFunction("Texture_SDL2_gpu",
          "mtrTextureFree");
        if (mtrTextureFree == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTextureFree");
            ok = false;
        }
        mtrTextureSetBlendFunction = (mtrTextureSetBlendFunctionFunc)mtrFindFunction("Texture_SDL2_gpu",
          "mtrTextureSetBlendFunction");
        if (mtrTextureSetBlendFunction == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTextureSetBlendFunction");
            ok = false;
        }
        mtrTextureSetAlphaBlending = (mtrTextureSetAlphaBlendingFunc)mtrFindFunction("Texture_SDL2_gpu",
          "mtrTextureSetAlphaBlending");
        if (mtrTextureSetAlphaBlending == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTextureSetAlphaBlending");
            ok = false;
        }
        mtrTextureBlit_f = (mtrTextureBlit_fFunc)mtrFindFunction("Texture_SDL2_gpu",
          "mtrTextureBlit_f");
        if (mtrTextureBlit_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTextureBlit_f");
            ok = false;
        }
        mtrTextureBlitRegion_f = (mtrTextureBlitRegion_fFunc)mtrFindFunction("Texture_SDL2_gpu",
          "mtrTextureBlitRegion_f");
        if (mtrTextureBlitRegion_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTextureBlitRegion_f");
            ok = false;
        }
        mtrTextureBlitRegionScaled_f = (mtrTextureBlitRegionScaled_fFunc)mtrFindFunction("Texture_SDL2_gpu",
          "mtrTextureBlitRegionScaled_f");
        if (mtrTextureBlitRegionScaled_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTextureBlitRegionScaled_f");
            ok = false;
        }
        mtrTextureBlitRegionAngled_f = (mtrTextureBlitRegionAngled_fFunc)mtrFindFunction("Texture_SDL2_gpu",
          "mtrTextureBlitRegionAngled_f");
        if (mtrTextureBlitRegionAngled_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTextureBlitRegionAngled_f");
            ok = false;
        }
        mtrTextureBlitRegionFlipped_f = (mtrTextureBlitRegionFlipped_fFunc)mtrFindFunction("Texture_SDL2_gpu",
          "mtrTextureBlitRegionFlipped_f");
        if (mtrTextureBlitRegionFlipped_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrTextureBlitRegionFlipped_f");
            ok = false;
        }
        mtrTextureBlitRegionGeneral_f = (mtrTextureBlitRegionGeneral_fFunc)mtrFindFunction("Texture_SDL2_gpu",
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
            mtrScriptsRegisterNumericVariable("FLIP_HORIZONTAL",
             MTR_FLIP_HORIZONTAL);
            mtrScriptsRegisterNumericVariable("FLIP_VERTICAL",
             MTR_FLIP_VERTICAL);
            mtrScriptsRegisterNumericVariable("FLIP_BOTH", MTR_FLIP_BOTH);
            mtrScriptsRegisterNumericVariable("BLEND_ZERO", MTR_BLEND_ZERO);
            mtrScriptsRegisterNumericVariable("BLEND_ONE", MTR_BLEND_ONE);
            mtrScriptsRegisterNumericVariable("BLEND_SRC_COLOR",
             MTR_BLEND_SRC_COLOR);
            mtrScriptsRegisterNumericVariable("BLEND_DST_COLOR",
             MTR_BLEND_DST_COLOR);
            mtrScriptsRegisterNumericVariable("BLEND_ONE_MINUS_SRC",
             MTR_BLEND_ONE_MINUS_SRC);
            mtrScriptsRegisterNumericVariable("BLEND_ONE_MINUS_DST",
             MTR_BLEND_ONE_MINUS_DST);
            mtrScriptsRegisterNumericVariable("BLEND_SRC_ALPHA",
             MTR_BLEND_SRC_ALPHA);
            mtrScriptsRegisterNumericVariable("BLEND_DST_ALPHA",
             MTR_BLEND_DST_ALPHA);
            mtrScriptsRegisterNumericVariable("BLEND_ONE_MINUS_SRC_ALPHA",
             MTR_BLEND_ONE_MINUS_SRC_ALPHA);
            mtrScriptsRegisterNumericVariable("BLEND_ONE_MINUS_DST_ALPHA",
             MTR_BLEND_ONE_MINUS_DST_ALPHA);
            mtrScriptsRegisterFunction(mtrSF_TextureInit, "TextureInit");
            mtrScriptsRegisterFunction(mtrSF_TextureBeginTarget, "TextureBeginTarget");
            mtrScriptsRegisterFunction(mtrSF_TextureEndTarget, "TextureEndTarget");
            mtrScriptsRegisterFunction(mtrSF_TextureCreate, "TextureCreate");
            mtrScriptsRegisterFunction(mtrSF_TextureLoad, "TextureLoad");
            mtrScriptsRegisterFunction(mtrSF_TextureFree, "TextureFree");
            mtrScriptsRegisterFunction(mtrSF_TextureSetBlendFunction,
             "TextureSetBlendFunction");
            mtrScriptsRegisterFunction(mtrSF_TextureSetAlphaBlending,
             "TextureSetBlending");
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
