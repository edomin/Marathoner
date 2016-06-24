#include "texture.h"

#include "plugin_common.c"

__declspec(dllexport) mtrReport* __stdcall mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Texture_sdl_gpu";
    report->prereqsCount = 1;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    report->prereqs[0] = "Screen_sdl_gpu";
    return report;
}

__declspec(dllexport) bool __stdcall mtrTextureInit(uint32_t dmSize,
 uint32_t reservedCount)
{
    mtrLogWrite("Initializing texture manager", 0, MTR_LMT_INFO);

    mtrGetScreen = (mtrGetScreenFunc)mtrFindFunction("Screen_sdl_gpu", "mtrGetScreen");
    if (mtrGetScreen == NULL)
    {
        mtrNotify("Unable to load 'mtrGetScreen' function from 'Screen_sdl_gpu' module",
         1, MTR_LMT_FATAL);
        return false;
    }
    mtrScreen = mtrGetScreen();

    mtrTextureKeeper = (mtrIndexkeeper_t *)mtrIndexkeeperCreate(dmSize,
     reservedCount, sizeof(mtrTexture_t));
    if (mtrTextureKeeper == NULL)
    {
        mtrNotify("Unable to initialize texture manager", 1, MTR_LMT_ERROR);
        return false;
    }
    else
        mtrLogWrite("Texture manager initialized", 0, MTR_LMT_INFO);
    return true;
}

__declspec(dllexport) uint32_t __stdcall mtrTextureLoad(const char *filename)
{
    uint32_t      freeIndex;
    mtrTexture_t *texture;

    mtrLogWrite_s("Loading texture", 0, MTR_LMT_INFO, filename);
    freeIndex = mtrIndexkeeperGetFreeIndex(mtrTextureKeeper);
    mtrLogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    texture = (mtrTexture_t *)(&((mtrTexture_t *)mtrTextureKeeper->data)[freeIndex]);
    texture->texture = GPU_LoadImage(filename);
    if (texture->texture != NULL)
    {
        texture->name = malloc(sizeof(char) * (strlen(filename) + 1));
        texture->name = strcpy(texture->name, filename);
        mtrLogWrite_s("Texture loaded", 0, MTR_LMT_INFO, filename);
        return freeIndex;
    }
    else
    {
        mtrNotify("Unable to load texture", 1, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrTextureKeeper, freeIndex);
        return 0;
    }
    return 0;
}

__declspec(dllexport) void __stdcall mtrTextureFree(uint32_t texNum)
{
    mtrTexture_t *texture;
    if (texNum != 0)
    {
        texture = (mtrTexture_t *)(&((mtrTexture_t *)mtrTextureKeeper->data)[texNum]);
        mtrLogWrite_s("Unloading texture", 0, MTR_LMT_INFO, texture->name);
        free(texture->name);
        GPU_FreeImage (texture->texture);
        mtrIndexkeeperFreeIndex(mtrTextureKeeper, texNum);
        mtrLogWrite("Texture unloaded", 0, MTR_LMT_INFO);
    }
}

__declspec(dllexport) void __stdcall mtrTextureBlit_f(uint32_t texNum, float x, float y)
{
    mtrTexture_t *texture;
    texture = (mtrTexture_t *)(&((mtrTexture_t *)mtrTextureKeeper->data)[texNum]);
    GPU_Blit(texture->texture, NULL, mtrScreen->screen, x, y);
}
