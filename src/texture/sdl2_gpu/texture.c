#include "texture.h"

#include "marathoner/plugin_common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Texture, FA_FUNCTIONS_COUNT)

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Texture_SDL2_gpu";
    report->version = MTR_VERSION_TEXTURE_SDL2_GPU;
    report->subsystem = "texture";
    report->prereqsCount = 1;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    if (report->prereqs == NULL)
    {
        free(report);
        return NULL;
    }
    report->prereqs[0] = "Screen_SDL2_gpu";
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}

int mtrFlipToActualFlip(int flip)
{
    switch (flip)
    {
        case MTR_FLIP_NONE:
            return GPU_FLIP_NONE;
            break;
        case MTR_FLIP_HORIZONTAL:
            return  GPU_FLIP_HORIZONTAL;
            break;
        case MTR_FLIP_VERTICAL:
            return GPU_FLIP_VERTICAL;
            break;
        case MTR_FLIP_BOTH:
            return (GPU_FLIP_HORIZONTAL | GPU_FLIP_VERTICAL);
            break;
        default:
            return GPU_FLIP_NONE;
            break;
    }
}

/*fa mtrTextureInit yes */
MTR_EXPORT bool MTR_CALL mtrTextureInit(uint32_t dmSize, uint32_t reservedCount)
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

    mtrGetScreen = (mtrGetScreenFunc)mtrFindFunction("Screen_SDL2_gpu",
     "mtrGetScreen");
    if (mtrGetScreen == NULL)
    {
        mtrNotify("Unable to load 'mtrGetScreen' function from 'Screen_SDL2_gpu' module",
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

/*fa mtrTextureBeginTarget yes */
MTR_EXPORT void MTR_CALL mtrTextureBeginTarget(uint32_t texNum)
{
    mtrTexture_t *texture;
    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        mtrScreen->target = texture->texture->target;
    }
}

/*fa mtrTextureEndTarget yes */
MTR_EXPORT void MTR_CALL mtrTextureEndTarget(void)
{
    mtrScreen->target = mtrScreen->screen;
}

/*fa mtrTextureGetWidth yes */
MTR_EXPORT int MTR_CALL mtrTextureGetWidth(uint32_t texNum)
{
    mtrTexture_t *texture;
    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        return texture->texture->w;
    }
    else
        return 0;
}

/*fa mtrTextureGetHeight yes */
MTR_EXPORT int MTR_CALL mtrTextureGetHeight(uint32_t texNum)
{
    mtrTexture_t *texture;
    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        return texture->texture->h;
    }
    else
        return 0;
}

/*fa mtrTextureGetSizes yes */
MTR_EXPORT void MTR_CALL mtrTextureGetSizes(uint32_t texNum, int *width,
 int *height)
{
    mtrTexture_t *texture;
    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        *width = texture->texture->w;
        *height = texture->texture->h;
    }
    else
    {
        *width = 0;
        *height = 0;
    }
}

/*fa mtrTextureCreate yes */
MTR_EXPORT uint32_t MTR_CALL mtrTextureCreate(const char *name, int width,
 int height)
{
    uint32_t      freeIndex;
    mtrTexture_t *texture;
    GPU_Target* target;

    mtrLogWrite_s("Creating texture", 0, MTR_LMT_INFO, name);
    freeIndex = mtrIndexkeeperGetFreeIndex(mtrTextureKeeper);
    mtrLogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, freeIndex);
    texture->texture = GPU_CreateImage(width, height, GPU_FORMAT_RGBA);
    if (texture->texture != NULL)
    {
//        GPU_SetImageFilter(texture->texture, GPU_FILTER_NEAREST);
//        GPU_SetSnapMode(texture->texture, GPU_SNAP_POSITION_AND_DIMENSIONS);

        texture->name = malloc(sizeof(char) * (strlen(name) + 1));
        if (texture->name == NULL)
            texture->name = mtrDefaultTextureName;
        else
            texture->name = strcpy(texture->name, name);
        GPU_SetAnchor(texture->texture, 0.0f, 0.0f);
        GPU_SetBlending(texture->texture, true);
        mtrLogWrite_s("Texture created", 0, MTR_LMT_INFO, name);
        target = GPU_LoadTarget(texture->texture);
        if (target == NULL)
        {
            mtrLogWrite_s("Texture can not be used as render targer", 0,
             MTR_LMT_INFO, name);
        }
        return freeIndex;
    }
    else
    {
        mtrNotify("Unable to create texture", 1, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrTextureKeeper, freeIndex);
        return 0;
    }
    return 0;
}

/*fa mtrTextureLoad yes */
MTR_EXPORT uint32_t MTR_CALL mtrTextureLoad(const char *filename)
{
    uint32_t      freeIndex;
    mtrTexture_t *texture;

    mtrLogWrite_s("Loading texture", 0, MTR_LMT_INFO, filename);
    freeIndex = mtrIndexkeeperGetFreeIndex(mtrTextureKeeper);
    mtrLogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, freeIndex);
    texture->texture = GPU_LoadImage(filename);
    if (texture->texture != NULL)
    {
//        GPU_SetImageFilter(texture->texture, GPU_FILTER_NEAREST);
//        GPU_SetSnapMode(texture->texture, GPU_SNAP_POSITION_AND_DIMENSIONS);

        texture->name = malloc(sizeof(char) * (strlen(filename) + 1));
        if (texture->name == NULL)
            texture->name = mtrDefaultTextureName;
        else
            texture->name = strcpy(texture->name, filename);
        GPU_SetAnchor(texture->texture, 0.0f, 0.0f);
        GPU_SetBlending(texture->texture, true);
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

/*fa mtrTextureCopy yes */
MTR_EXPORT uint32_t MTR_CALL mtrTextureCopy(uint32_t texNum)
{
    uint32_t      freeIndex;
    mtrTexture_t *texture;
    mtrTexture_t *newTexture;
    SDL_Surface* surface;

    if (texNum != 0)
    {
        freeIndex = mtrIndexkeeperGetFreeIndex(mtrTextureKeeper);
        mtrLogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
        newTexture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, freeIndex);
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        surface = GPU_CopySurfaceFromImage(texture->texture);
        if (surface == NULL)
        {
            mtrNotify("Unable to copy texture", 1, MTR_LMT_ERROR);
            mtrIndexkeeperFreeIndex(mtrTextureKeeper, freeIndex);
            return 0;
        }
        newTexture->texture = GPU_CopyImageFromSurface(surface);
        if (newTexture->texture != NULL)
        {
            mtrLogWrite_s("Copying texture", 0, MTR_LMT_INFO, texture->name);
            newTexture->name = malloc(sizeof(char) * (strlen(texture->name) + 1));
            if (newTexture->name == NULL)
                newTexture->name = mtrDefaultTextureName;
            else
                newTexture->name = strcpy(newTexture->name, texture->name);
            GPU_SetAnchor(newTexture->texture, 0.0f, 0.0f);
            GPU_SetBlending(newTexture->texture, true);
            SDL_FreeSurface(surface);
            mtrLogWrite_s("Texture copyed", 0, MTR_LMT_INFO, newTexture->name);
            return freeIndex;
        }
        else
        {
            mtrNotify("Unable to copy texture", 1, MTR_LMT_ERROR);
            mtrIndexkeeperFreeIndex(mtrTextureKeeper, freeIndex);
            return 0;
        }
    }
    else
    {
        mtrNotify("Unable to copy texture. Incorrect texture for copy", 1,
         MTR_LMT_ERROR);
        return 0;
    }
    return 0;
}

/*fa mtrTextureSave yes */
MTR_EXPORT bool MTR_CALL mtrTextureSave(uint32_t texNum, const char *filename)
{
    mtrTexture_t *texture;
    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        mtrLogWrite_s("Saving texture", 0, MTR_LMT_INFO, texture->name);

        if (GPU_SaveImage(texture->texture, filename, GPU_FILE_AUTO))
        {
            mtrLogWrite("Texture saved", 0, MTR_LMT_INFO);
            return true;
        }
        else
        {
            mtrLogWrite("Unable to save to format autodetected by extension. "
             "Saving to PNG", 0, MTR_LMT_WARNING);
            if (GPU_SaveImage(texture->texture, filename, GPU_FILE_PNG))
            {
                mtrLogWrite("Texture saved", 0, MTR_LMT_INFO);
                return true;
            }
            else
            {
                mtrLogWrite("Unable to save texture", 0, MTR_LMT_ERROR);
                return false;
            }
        }
    }
    else
        mtrLogWrite("Unable to save texture. Incorrect texture index", 0,
         MTR_LMT_ERROR);
    return false;
}

/*fa mtrTextureSave buggy */
MTR_EXPORT uint32_t MTR_CALL mtrTextureCreateAlias(uint32_t texNum)
{
    uint32_t      freeIndex;
    mtrTexture_t *texture;
    mtrTexture_t *oldTexture;

    mtrLogWrite("Creating texture alias", 0, MTR_LMT_INFO);
    freeIndex = mtrIndexkeeperGetFreeIndex(mtrTextureKeeper);
    mtrLogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, freeIndex);
    oldTexture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
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

/*fa mtrTextureFree yes */
MTR_EXPORT void MTR_CALL mtrTextureFree(uint32_t texNum)
{
    mtrTexture_t *texture;
    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        mtrLogWrite_s("Unloading texture", 0, MTR_LMT_INFO, texture->name);
        if (texture->name != mtrDefaultTextureName)
            free(texture->name);
        GPU_FreeImage (texture->texture);
        mtrIndexkeeperFreeIndex(mtrTextureKeeper, texNum);
        mtrLogWrite("Texture unloaded", 0, MTR_LMT_INFO);
    }
}

/*fa mtrTextureSetModulation_c yes */
MTR_EXPORT void MTR_CALL mtrTextureSetModulation_c(uint32_t texNum,
 uint32_t color)
{
    mtrTexture_t *texture;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_SetRGB(texture->texture, r, g, b);
    }
}

/*fa mtrTextureSetModulation_ca yes */
MTR_EXPORT void MTR_CALL mtrTextureSetModulation_ca(uint32_t texNum,
 uint32_t color)
{
    mtrTexture_t *texture;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    r = (uint8_t)(color >> 24);
    g = (uint8_t)((color >> 16) - ((uint32_t)r << 8));
    b = (uint8_t)((color >> 8) - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    a = (uint8_t)(color  - ((uint32_t)r << 24) - ((uint32_t)g << 16) -
     ((uint32_t)b << 8));
    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_SetRGBA(texture->texture, r, g, b, a);
    }
}

/*fa mtrTextureSetModulation_rgb yes */
MTR_EXPORT void MTR_CALL mtrTextureSetModulation_rgb(uint32_t texNum,
 uint8_t r, uint8_t g, uint8_t b)
{
    mtrTexture_t *texture;
    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_SetRGB(texture->texture, r, g, b);
    }
}

/*fa mtrTextureSetModulation_rgba yes */
MTR_EXPORT void MTR_CALL mtrTextureSetModulation_rgba(uint32_t texNum,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    mtrTexture_t *texture;
    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_SetRGBA(texture->texture, r, g, b, a);
    }
}

/*fa mtrTextureSetModulationAlpha yes */
MTR_EXPORT void MTR_CALL mtrTextureSetModulationAlpha(uint32_t texNum,
 uint8_t alpha)
{
    mtrTexture_t *texture;
    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_SetRGBA(texture->texture, 0xFF, 0xFF, 0xFF, alpha);
    }
}

/*fa mtrTextureSetModulationAlpha_f yes */
MTR_EXPORT void MTR_CALL mtrTextureSetModulationAlpha_f(uint32_t texNum,
 float alpha)
{
    mtrTexture_t *texture;
    uint8_t alpha8;
    if (texNum != 0)
    {
        alpha8 = (alpha * 255);
        alpha8 %= 256;
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_SetRGBA(texture->texture, 0xFF, 0xFF, 0xFF, alpha8);
    }
}

/*fa mtrTextureSetBlendFunction buggy */
MTR_EXPORT void MTR_CALL mtrTextureSetBlendFunction(uint32_t texNum,
 int srcColor, int destColor, int srcAlpha, int dstAlpha)
{
    mtrTexture_t *texture;
    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_SetBlendFunction(texture->texture, srcColor, destColor, srcAlpha,
         dstAlpha);
    }
}

/*fa mtrTextureSetAlphaBlending yes */
MTR_EXPORT void MTR_CALL mtrTextureSetAlphaBlending(uint32_t texNum,
 bool blending)
{
    mtrTexture_t *texture;
    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_SetBlending(texture->texture, blending);
    }
}

/*fa mtrTextureBlit_f yes */
MTR_EXPORT void MTR_CALL mtrTextureBlit_f(uint32_t texNum, float x, float y)
{
    mtrTexture_t *texture;
    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_Blit(texture->texture, NULL, mtrScreen->target, x, y);
    }
}

/*fa mtrTextureBlitScaled_f yes */
MTR_EXPORT void MTR_CALL mtrTextureBlitScaled_f(uint32_t texNum, float x,
 float y, float w, float h)
{
    GPU_Rect outputRegion;
    mtrTexture_t *texture;
    if (texNum != 0)
    {
        outputRegion.x = x;
        outputRegion.y = y;
        outputRegion.w = w;
        outputRegion.h = h;
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_BlitRect(texture->texture, NULL, mtrScreen->target, &outputRegion);
    }
}

/*fa mtrTextureBlitAngled_f yes */
MTR_EXPORT void MTR_CALL mtrTextureBlitAngled_f(uint32_t texNum, float x,
 float y, float angle, float pivotX, float pivotY)
{
    GPU_Rect outputRegion;
    mtrTexture_t *texture;
    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        outputRegion.x = x;
        outputRegion.y = y;
        outputRegion.w = texture->texture->w;
        outputRegion.h = texture->texture->h;
        GPU_BlitRectX(texture->texture, NULL, mtrScreen->target,
         &outputRegion, -angle, pivotX, pivotY, GPU_FLIP_NONE);
    }
}

/*fa mtrTextureBlitFlipped_f yes */
MTR_EXPORT void MTR_CALL mtrTextureBlitFlipped_f(uint32_t texNum, float x,
 float y, int flip)
{
    GPU_Rect outputRegion;
    mtrTexture_t *texture;
    int actualFlip;
    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        actualFlip = mtrFlipToActualFlip(flip);
        outputRegion.x = x;
        outputRegion.y = y;
        outputRegion.w = texture->texture->w;
        outputRegion.h = texture->texture->h;
        if ((actualFlip & GPU_FLIP_VERTICAL) == GPU_FLIP_VERTICAL)
            outputRegion.y += outputRegion.h;
        if ((actualFlip & GPU_FLIP_HORIZONTAL) == GPU_FLIP_HORIZONTAL)
            outputRegion.x += outputRegion.w;
        GPU_BlitRectX(texture->texture, NULL, mtrScreen->target,
         &outputRegion, 0.0f, 0, 0, actualFlip);
    }
}

/*fa mtrTextureBlitGeneral_f yes */
MTR_EXPORT void MTR_CALL mtrTextureBlitGeneral_f(uint32_t texNum, float x,
 float y, float w, float h, float angle, float pivotX, float pivotY, int flip)
{
    GPU_Rect outputRegion;
    mtrTexture_t *texture;
    int actualFlip;
    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        actualFlip = mtrFlipToActualFlip(flip);
        outputRegion.x = x;
        outputRegion.y = y;
        outputRegion.w = texture->texture->w;
        outputRegion.h = texture->texture->h;
        if ((actualFlip & GPU_FLIP_VERTICAL) == GPU_FLIP_VERTICAL)
            outputRegion.y += outputRegion.h;
        if ((actualFlip & GPU_FLIP_HORIZONTAL) == GPU_FLIP_HORIZONTAL)
            outputRegion.x += outputRegion.w;
        GPU_BlitRectX(texture->texture, NULL, mtrScreen->target,
         &outputRegion, -angle, pivotX, pivotY, actualFlip);
    }
}

/*fa mtrTextureBlitRegion_f yes */
MTR_EXPORT void MTR_CALL mtrTextureBlitRegion_f(uint32_t texNum, float x,
 float y, float rx, float ry, float rw, float rh)
{
    GPU_Rect region;
    mtrTexture_t *texture;
    if (texNum != 0)
    {
        region.x = rx;
        region.y = ry;
        region.w = rw;
        region.h = rh;
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_Blit(texture->texture, &region, mtrScreen->target, x, y);
    }
}

/*fa mtrTextureBlitRegionScaled_f yes */
MTR_EXPORT void MTR_CALL mtrTextureBlitRegionScaled_f(uint32_t texNum, float x,
 float y, float w, float h, float rx, float ry, float rw, float rh)
{
    GPU_Rect region;
    GPU_Rect outputRegion;
    mtrTexture_t *texture;
    if (texNum != 0)
    {
        region.x = rx;
        region.y = ry;
        region.w = rw;
        region.h = rh;
        outputRegion.x = x;
        outputRegion.y = y;
        outputRegion.w = w;
        outputRegion.h = h;
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_BlitRect(texture->texture, &region, mtrScreen->target, &outputRegion);
    }
}

/*fa mtrTextureBlitRegionAngled_f yes */
MTR_EXPORT void MTR_CALL mtrTextureBlitRegionAngled_f(uint32_t texNum, float x,
 float y, float rx, float ry, float rw, float rh, float angle, float pivotX,
 float pivotY)
{
    GPU_Rect region;
    GPU_Rect outputRegion;
    mtrTexture_t *texture;
    if (texNum != 0)
    {
        region.x = rx;
        region.y = ry;
        region.w = rw;
        region.h = rh;
        outputRegion.x = x;
        outputRegion.y = y;
        outputRegion.w = rw;
        outputRegion.h = rh;
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_BlitRectX(texture->texture, &region, mtrScreen->target,
         &outputRegion, -angle, pivotX, pivotY, GPU_FLIP_NONE);
    }
}

/*fa mtrTextureBlitRegionFlipped_f yes */
MTR_EXPORT void MTR_CALL mtrTextureBlitRegionFlipped_f(uint32_t texNum, float x,
 float y, float rx, float ry, float rw, float rh, int flip)
{
    GPU_Rect region;
    GPU_Rect outputRegion;
    mtrTexture_t *texture;
    int actualFlip;
    if (texNum != 0)
    {
        actualFlip = mtrFlipToActualFlip(flip);
        region.x = rx;
        region.y = ry;
        region.w = rw;
        region.h = rh;
        outputRegion.x = x;
        outputRegion.y = y;
        outputRegion.w = rw;
        outputRegion.h = rh;
        if ((actualFlip & GPU_FLIP_VERTICAL) == GPU_FLIP_VERTICAL)
            outputRegion.y += outputRegion.h;
        if ((actualFlip & GPU_FLIP_HORIZONTAL) == GPU_FLIP_HORIZONTAL)
            outputRegion.x += outputRegion.w;
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_BlitRectX(texture->texture, &region, mtrScreen->target,
         &outputRegion, 0.0f, rx, ry, actualFlip);
    }
}

/*fa mtrTextureBlitRegionGeneral_f yes */
MTR_EXPORT void MTR_CALL mtrTextureBlitRegionGeneral_f(uint32_t texNum, float x,
 float y, float w, float h, float rx, float ry, float rw, float rh, float angle,
 float pivotX, float pivotY, int flip)
{
    GPU_Rect region;
    GPU_Rect outputRegion;
    mtrTexture_t *texture;
    int actualFlip;
    if (texNum != 0)
    {
        actualFlip = mtrFlipToActualFlip(flip);
        region.x = rx;
        region.y = ry;
        region.w = rw;
        region.h = rh;
        outputRegion.x = x;
        outputRegion.y = y;
        outputRegion.w = w;
        outputRegion.h = h;
        if ((actualFlip & GPU_FLIP_VERTICAL) == GPU_FLIP_VERTICAL)
            outputRegion.y += outputRegion.h;
        if ((actualFlip & GPU_FLIP_HORIZONTAL) == GPU_FLIP_HORIZONTAL)
            outputRegion.x += outputRegion.w;
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_BlitRectX(texture->texture, &region, mtrScreen->target,
         &outputRegion, -angle, pivotX, pivotY, actualFlip);
    }
}

/*fa mtrTextureReceivePixels yes */
MTR_EXPORT bool MTR_CALL mtrTextureReceivePixels(uint32_t texNum,
 mtrPixels_t *pixels)
{
    mtrTexture_t *texture;
    GPU_Rect      rect;
    int           textureW;
    int           textureH;

    if (texNum == 0)
        return false;

    texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);

    textureW = texture->texture->texture_w;
    textureH = texture->texture->texture_h;

    if (textureW != pixels->w || textureH != pixels->h)
    {
        GPU_FreeImage (texture->texture);
        texture->texture = GPU_CreateImage(pixels->w, pixels->h,
         GPU_FORMAT_RGBA);
        if (texture->texture == NULL)
        {
            mtrIndexkeeperFreeIndex(mtrTextureKeeper, texNum);
            return false;
        }
        GPU_SetAnchor(texture->texture, 0.0f, 0.0f);
        GPU_LoadTarget(texture->texture);
    }

    rect.x = 0.0f;
    rect.y = 0.0f;
    rect.w = pixels->w;
    rect.h = pixels->h;

    GPU_UpdateImageBytes(texture->texture, &rect, pixels->data, pixels->pitch);

    return true;
}
