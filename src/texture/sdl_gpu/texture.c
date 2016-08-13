#include "texture.h"

#include "marathoner/plugin_common.c"

__declspec(dllexport) mtrReport* __stdcall mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Texture_sdl_gpu";
    report->version = 0x000000;
    report->prereqsCount = 1;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    report->prereqs[0] = "Screen_sdl_gpu";
    return report;
}

__declspec(dllexport) bool __stdcall mtrTextureInit(uint32_t dmSize,
 uint32_t reservedCount)
{
    SDL_version linked;

    mtrLogWrite("Initializing texture manager", 0, MTR_LMT_INFO);

    mtrLogWrite("Reporting sdl_gpu compile-time version:", 1, MTR_LMT_INFO);
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, SDL_GPU_VERSION_MAJOR);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, SDL_GPU_VERSION_MINOR);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, SDL_GPU_VERSION_PATCH);
    mtrLogWrite("Reporting sdl_gpu linked version:", 1, MTR_LMT_INFO);
    linked = GPU_GetLinkedVersion();
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, linked.major);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, linked.minor);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, linked.patch);

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

__declspec(dllexport) uint32_t __stdcall mtrTextureCreateAlias(uint32_t texNum)
{
    uint32_t      freeIndex;
    mtrTexture_t *texture;
    mtrTexture_t *oldTexture;

    mtrLogWrite("Creating texture alias", 0, MTR_LMT_INFO);
    freeIndex = mtrIndexkeeperGetFreeIndex(mtrTextureKeeper);
    mtrLogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    texture = (mtrTexture_t *)(&((mtrTexture_t *)mtrTextureKeeper->data)[freeIndex]);
    oldTexture = (mtrTexture_t *)(&((mtrTexture_t *)mtrTextureKeeper->data)[texNum]);
    texture->texture = GPU_CreateAliasImage(oldTexture->texture);
    if (texture->texture != NULL)
    {
        texture->name = malloc(sizeof(char) * (strlen(oldTexture->name) + 1));
        texture->name = strcpy(texture->name, oldTexture->name);
        mtrLogWrite_s("Created alias for texture", 0, MTR_LMT_INFO,
         oldTexture->name);
        return freeIndex;
    }
    else
    {
        mtrNotify("Unable to create texture alias", 1, MTR_LMT_ERROR);
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

__declspec(dllexport) void __stdcall mtrTextureSetBlendFunction(uint32_t texNum,
 uint8_t srcColor, uint8_t destColor, uint8_t srcAlpha, uint8_t dstAlpha)
{
    mtrTexture_t *texture;
    if (texNum != 0)
    {
        texture = (mtrTexture_t *)(&((mtrTexture_t *)mtrTextureKeeper->data)[texNum]);
        GPU_SetBlendFunction(texture->texture, (int)srcColor, (int)destColor,
         (int)srcAlpha, (int)dstAlpha);
    }
}

__declspec(dllexport) void __stdcall mtrTextureSetAlphaBlending(uint32_t texNum,
 bool blending)
{
    mtrTexture_t *texture;
    if (texNum != 0)
    {
        texture = (mtrTexture_t *)(&((mtrTexture_t *)mtrTextureKeeper->data)[texNum]);
        GPU_SetBlending(texture->texture, blending);
    }
}

__declspec(dllexport) void __stdcall mtrTextureBlit_f(uint32_t texNum, float x,
 float y)
{
    mtrTexture_t *texture;
    texture = (mtrTexture_t *)(&((mtrTexture_t *)mtrTextureKeeper->data)[texNum]);
    GPU_Blit(texture->texture, NULL, mtrScreen->screen, x, y);
}

__declspec(dllexport) void __stdcall mtrTextureBlitRegion_f(uint32_t texNum,
 float x, float y, float rx, float ry, float rw, float rh)
{
    GPU_Rect region;
    mtrTexture_t *texture;
    region.x = rx;
    region.y = ry;
    region.w = rw;
    region.h = rh;
    texture = (mtrTexture_t *)(&((mtrTexture_t *)mtrTextureKeeper->data)[texNum]);
    GPU_Blit(texture->texture, &region, mtrScreen->screen, x, y);
}

__declspec(dllexport) void __stdcall mtrTextureBlitRegionScaled_f(uint32_t texNum,
 float x, float y, float w, float h, float rx, float ry, float rw, float rh)
{
    GPU_Rect region;
    GPU_Rect outputRegion;
    mtrTexture_t *texture;
    region.x = rx;
    region.y = ry;
    region.w = rw;
    region.h = rh;
    outputRegion.x = x;
    outputRegion.y = y;
    outputRegion.w = w;
    outputRegion.h = h;
    texture = (mtrTexture_t *)(&((mtrTexture_t *)mtrTextureKeeper->data)[texNum]);
    GPU_BlitRect(texture->texture, &region, mtrScreen->screen, &outputRegion);
}

__declspec(dllexport) void __stdcall mtrTextureBlitRegionAngled_f(uint32_t texNum,
 float x, float y, float rx, float ry, float rw, float rh, float angle,
 float pivotX, float pivotY)
{
    GPU_Rect region;
    GPU_Rect outputRegion;
    mtrTexture_t *texture;
    region.x = rx;
    region.y = ry;
    region.w = rw;
    region.h = rh;
    outputRegion.x = x;
    outputRegion.y = y;
    outputRegion.w = rw;
    outputRegion.h = rh;
    texture = (mtrTexture_t *)(&((mtrTexture_t *)mtrTextureKeeper->data)[texNum]);
    GPU_BlitRectX(texture->texture, &region, mtrScreen->screen, &outputRegion,
     -angle, pivotX, pivotY, GPU_FLIP_NONE);
}

__declspec(dllexport) void __stdcall mtrTextureBlitRegionFlipped_f(uint32_t texNum,
 float x, float y, float rx, float ry, float rw, float rh, uint8_t flip)
{
    GPU_Rect region;
    GPU_Rect outputRegion;
    mtrTexture_t *texture;
    region.x = rx;
    region.y = ry;
    region.w = rw;
    region.h = rh;
    outputRegion.x = x;
    outputRegion.y = y;
    outputRegion.w = rw;
    outputRegion.h = rh;
    texture = (mtrTexture_t *)(&((mtrTexture_t *)mtrTextureKeeper->data)[texNum]);
    GPU_BlitRectX(texture->texture, &region, mtrScreen->screen, &outputRegion,
     0.0f, rx, ry, flip);
}

__declspec(dllexport) void __stdcall mtrTextureBlitRegionGeneral_f(uint32_t texNum,
 float x, float y, float w, float h, float rx, float ry, float rw, float rh,
 float angle, float pivotX, float pivotY, uint8_t flip)
{
    GPU_Rect region;
    GPU_Rect outputRegion;
    mtrTexture_t *texture;
    region.x = rx;
    region.y = ry;
    region.w = rw;
    region.h = rh;
    outputRegion.x = x;
    outputRegion.y = y;
    outputRegion.w = w;
    outputRegion.h = h;
    texture = (mtrTexture_t *)(&((mtrTexture_t *)mtrTextureKeeper->data)[texNum]);
    GPU_BlitRectX(texture->texture, &region, mtrScreen->screen, &outputRegion,
     -angle, pivotX, pivotY, flip);
}
