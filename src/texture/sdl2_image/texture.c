#include "texture.h"

#include "marathoner/plugin_common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Texture_SDL2_image";
    report->version = MTR_VERSION_TEXTURE_SDL2_IMAGE;
    report->subsystem = "texture";
    report->prereqsCount = 1;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    report->prereqs[0] = "Screen_SDL2";
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}

MTR_EXPORT bool MTR_CALL mtrTextureInit(uint32_t dmSize, uint32_t reservedCount)
{
    SDL_version        compiled;
    SDL_version        sdlLinked;
    const SDL_version *sdlImageLinked;

    mtrLogWrite("Initializing texture manager", 0, MTR_LMT_INFO);

    mtrLogWrite("Reporting SDL compile-time version:", 1, MTR_LMT_INFO);
    SDL_VERSION(&compiled);
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, compiled.major);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, compiled.minor);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, compiled.patch);
    mtrLogWrite("Reporting SDL linked version:", 1, MTR_LMT_INFO);
    SDL_GetVersion(&sdlLinked);
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, sdlLinked.major);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, sdlLinked.minor);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, sdlLinked.patch);
    SDL_IMAGE_VERSION(&compiled);
    mtrLogWrite("Reporting SDL_image compile-time version", 1, MTR_LMT_INFO);
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, compiled.major);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, compiled.minor);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, compiled.patch);
    sdlImageLinked = IMG_Linked_Version();
    mtrLogWrite("Reporting SDL_image linked version", 1, MTR_LMT_INFO);
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, sdlImageLinked->major);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, sdlImageLinked->minor);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, sdlImageLinked->patch);

    mtrGetScreen = (mtrGetScreenFunc)mtrFindFunction("Screen_SDL2",
     "mtrGetScreen");
    if (mtrGetScreen == NULL)
    {
        mtrNotify("Unable to load 'mtrGetScreen' function from 'Screen_SDL2' module",
         1, MTR_LMT_FATAL);
        return false;
    }
    mtrScreen = mtrGetScreen();

    mtrTextureKeeper = (mtrIndexkeeper_t *)mtrIndexkeeperCreate(dmSize,
     reservedCount, sizeof(mtrTexture_t));
    if (mtrTextureKeeper == NULL)
    {
        mtrNotify("Unable to create indexkeeper structure for textures", 1,
         MTR_LMT_FATAL);
        return false;
    }
    else
        mtrLogWrite("Indexkeeper structure for textures created", 1,
         MTR_LMT_INFO);

    if (IMG_Init(IMG_INIT_PNG) == IMG_INIT_PNG)
        mtrLogWrite("SDL_image initialized", 1, MTR_LMT_INFO);
    else
    {
        mtrNotify("Unable to initialize SDL_image", 1, MTR_LMT_FATAL);
        mtrLogWrite(IMG_GetError(), 1, MTR_LMT_FATAL);
        return false;
    }

    mtrLogWrite("Texture manager initialized", 0, MTR_LMT_INFO);
    return true;
}

MTR_EXPORT uint32_t MTR_CALL mtrTextureLoad(const char *filename)
{
    uint32_t      freeIndex;
    mtrTexture_t *texture;
    SDL_Surface  *loadedImage;

    mtrLogWrite_s("Loading texture", 0, MTR_LMT_INFO, filename);
    freeIndex = mtrIndexkeeperGetFreeIndex(mtrTextureKeeper);
    mtrLogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    texture = (mtrTexture_t *)(&((mtrTexture_t *)mtrTextureKeeper->data)[freeIndex]);
    loadedImage = IMG_Load(filename);
    if (loadedImage != NULL)
        mtrLogWrite("Image loaded", 1, MTR_LMT_INFO);
    else
    {
        mtrNotify("Unable to load image", 1, MTR_LMT_ERROR);
        mtrLogWrite(IMG_GetError(), 1, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrTextureKeeper, freeIndex);
        return 0;
    }
    texture->texture = SDL_CreateTextureFromSurface(mtrScreen->renderer,
     loadedImage);
    SDL_FreeSurface(loadedImage);
    if (texture->texture != NULL)
    {
        texture->name = malloc(sizeof(char) * (strlen(filename) + 1));
        texture->name = strcpy(texture->name, filename);
        mtrLogWrite_s("Texture loaded", 0, MTR_LMT_INFO, filename);
        return freeIndex;
    }
    else
    {
        mtrNotify("Unable to create texture", 1, MTR_LMT_ERROR);
        mtrLogWrite(SDL_GetError(), 1, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrTextureKeeper, freeIndex);
        return 0;
    }
    return 0;
}

MTR_EXPORT uint32_t MTR_CALL mtrTextureCreateAlias(uint32_t texNum)
{
    return 0;
}

MTR_EXPORT void MTR_CALL mtrTextureFree(uint32_t texNum)
{
    mtrTexture_t *texture;
    if (texNum != 0)
    {
        texture = (mtrTexture_t *)(&((mtrTexture_t *)mtrTextureKeeper->data)[texNum]);
        mtrLogWrite_s("Unloading texture", 0, MTR_LMT_INFO, texture->name);
        free(texture->name);
        SDL_DestroyTexture(texture->texture);
        mtrIndexkeeperFreeIndex(mtrTextureKeeper, texNum);
        mtrLogWrite("Texture unloaded", 0, MTR_LMT_INFO);
    }
}

MTR_EXPORT void MTR_CALL mtrTextureSetBlendFunction(uint32_t texNum,
 int srcColor, int destColor, int srcAlpha, int dstAlpha)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrTextureSetAlphaBlending(uint32_t texNum,
 bool blending)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrTextureBlit_f(uint32_t texNum, float x, float y)
{
    mtrTexture_t *texture;
    SDL_Rect offset;
    SDL_Rect clip;
    texture = (mtrTexture_t *)(&((mtrTexture_t *)mtrTextureKeeper->data)[texNum]);
    offset.x = x;
    offset.y = y;
    SDL_QueryTexture(texture->texture, NULL, NULL, &offset.w, &offset.h);
    clip.x = 0;
    clip.y = 0;
    SDL_QueryTexture(texture->texture, NULL, NULL, &clip.w, &clip.h);
    SDL_RenderCopy(mtrScreen->renderer, texture->texture, &clip, &offset);
}

MTR_EXPORT void MTR_CALL mtrTextureBlitRegion_f(uint32_t texNum, float x,
 float y, float rx, float ry, float rw, float rh)
{
    mtrTexture_t *texture;
    SDL_Rect offset;
    SDL_Rect clip;
    texture = (mtrTexture_t *)(&((mtrTexture_t *)mtrTextureKeeper->data)[texNum]);
    offset.x = x;
    offset.y = y;
    offset.w = rw;
    offset.h = rh;
    clip.x = rx;
    clip.y = ry;
    clip.w = rw;
    clip.h = rh;
    SDL_RenderCopy(mtrScreen->renderer, texture->texture, &clip, &offset);
}

MTR_EXPORT void MTR_CALL mtrTextureBlitRegionScaled_f(uint32_t texNum, float x,
 float y, float w, float h, float rx, float ry, float rw, float rh)
{
    mtrTexture_t *texture;
    SDL_Rect offset;
    SDL_Rect clip;
    texture = (mtrTexture_t *)(&((mtrTexture_t *)mtrTextureKeeper->data)[texNum]);
    offset.x = x;
    offset.y = y;
    offset.w = w;
    offset.h = h;
    clip.x = rx;
    clip.y = ry;
    clip.w = rw;
    clip.h = rh;
    SDL_RenderCopyEx(mtrScreen->renderer, texture->texture, &clip, &offset, 0,
     NULL, MTR_FLIP_NONE);
}

MTR_EXPORT void MTR_CALL mtrTextureBlitRegionAngled_f(uint32_t texNum, float x,
 float y, float rx, float ry, float rw, float rh, float angle, float pivotX,
 float pivotY)
{
    mtrTexture_t *texture;
    SDL_Rect offset;
    SDL_Rect clip;
    SDL_Point pivot;
    texture = (mtrTexture_t *)(&((mtrTexture_t *)mtrTextureKeeper->data)[texNum]);
    offset.x = x;
    offset.y = y;
    offset.w = rw;
    offset.h = rh;
    clip.x = rx;
    clip.y = ry;
    clip.w = rw;
    clip.h = rh;
    pivot.x = pivotX;
    pivot.y = pivotY;
    SDL_RenderCopyEx(mtrScreen->renderer, texture->texture, &clip, &offset,
     -angle, &pivot, MTR_FLIP_NONE);
}

MTR_EXPORT void MTR_CALL mtrTextureBlitRegionFlipped_f(uint32_t texNum, float x,
 float y, float rx, float ry, float rw, float rh, int flip)
{
    mtrTexture_t *texture;
    SDL_Rect offset;
    SDL_Rect clip;
    texture = (mtrTexture_t *)(&((mtrTexture_t *)mtrTextureKeeper->data)[texNum]);
    offset.x = x;
    offset.y = y;
    offset.w = rw;
    offset.h = rh;
    clip.x = rx;
    clip.y = ry;
    clip.w = rw;
    clip.h = rh;
    SDL_RenderCopyEx(mtrScreen->renderer, texture->texture, &clip, &offset, 0,
     NULL, flip);
}

MTR_EXPORT void MTR_CALL mtrTextureBlitRegionGeneral_f(uint32_t texNum, float x,
 float y, float w, float h, float rx, float ry, float rw, float rh, float angle,
 float pivotX, float pivotY, int flip)
{
    mtrTexture_t *texture;
    SDL_Rect offset;
    SDL_Rect clip;
    SDL_Point pivot;
    texture = (mtrTexture_t *)(&((mtrTexture_t *)mtrTextureKeeper->data)[texNum]);
    offset.x = x;
    offset.y = y;
    offset.w = w;
    offset.h = h;
    clip.x = rx;
    clip.y = ry;
    clip.w = rw;
    clip.h = rh;
    pivot.x = pivotX;
    pivot.y = pivotY;
    SDL_RenderCopyEx(mtrScreen->renderer, texture->texture, &clip, &offset,
     -angle, &pivot, flip);
}
