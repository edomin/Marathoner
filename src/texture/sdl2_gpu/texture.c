#include "texture.h"

#ifdef MTR_MOD_PLUGIN
#include "marathoner/plugin_common.c"

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
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
#endif

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Texture, FA_FUNCTIONS_COUNT)

int MTR_FlipToActualFlip(int flip)
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

/*fa MTR_TextureInit yes */
MTR_DCLSPC bool MTR_CALL MTR_TextureInit(uint32_t dmSize, uint32_t reservedCount)
{
    SDL_version linked;

    MTR_LogWrite("Initializing texture manager", 0, MTR_LMT_INFO);

    MTR_LogWrite("Reporting sdl_gpu compile-time version:", 1, MTR_LMT_INFO);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, SDL_GPU_VERSION_MAJOR);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, SDL_GPU_VERSION_MINOR);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, SDL_GPU_VERSION_PATCH);
    MTR_LogWrite("Reporting sdl_gpu linked version:", 1, MTR_LMT_INFO);
    linked = GPU_GetLinkedVersion();
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, linked.major);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, linked.minor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, linked.patch);

    #ifdef MTR_MOD_PLUGIN
    MTR_GetScreen = (MTR_GetScreenFunc)MTR_FindFunction("Screen_SDL2_gpu",
     "MTR_GetScreen");
    if (MTR_GetScreen == NULL)
    {
        MTR_Notify("Unable to load 'MTR_GetScreen' function from "
         "'Screen_SDL2_gpu' module", 1, MTR_LMT_FATAL);
        return false;
    }
    mtrScreen = MTR_GetScreen();
    #endif

    mtrTextureKeeper = (mtrIndexkeeper_t *)MTR_IndexkeeperCreate(dmSize,
     reservedCount, sizeof(mtrTexture_t));
    if (mtrTextureKeeper == NULL)
    {
        MTR_Notify("Unable to initialize texture manager", 1, MTR_LMT_ERROR);
        return false;
    }
    else
        MTR_LogWrite("Texture manager initialized", 0, MTR_LMT_INFO);

    mtrTextureInited = true;
    return true;
}

/*fa MTR_TextureBeginTarget yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBeginTarget(uint32_t texNum)
{
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        mtrScreen->target = texture->texture->target;
    }
}

/*fa MTR_TextureEndTarget yes */
MTR_DCLSPC void MTR_CALL MTR_TextureEndTarget(void)
{
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    mtrScreen->target = mtrScreen->screen;
}

/*fa MTR_TextureGetWidth yes */
MTR_DCLSPC int MTR_CALL MTR_TextureGetWidth(uint32_t texNum)
{
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED(0);

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        return texture->texture->w;
    }
    else
        return 0;
}

/*fa MTR_TextureGetHeight yes */
MTR_DCLSPC int MTR_CALL MTR_TextureGetHeight(uint32_t texNum)
{
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED(0);

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        return texture->texture->h;
    }
    else
        return 0;
}

/*fa MTR_TextureGetSizes yes */
MTR_DCLSPC void MTR_CALL MTR_TextureGetSizes(uint32_t texNum, int *width,
 int *height)
{
    mtrTexture_t *texture;

    if (!mtrTextureInited)
    {
        *width = 0;
        *height = 0;
        return;
    }

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

/*fa MTR_TextureCreate yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_TextureCreate(const char *name, int width,
 int height)
{
    uint32_t      freeIndex;
    mtrTexture_t *texture;
    GPU_Target   *target;
    MTR_TEXTURE_CHECK_IF_NOT_INITED(0U);

    MTR_LogWrite_s("Creating texture", 0, MTR_LMT_INFO, name);
    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrTextureKeeper);
    MTR_LogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, freeIndex);
    texture->texture = GPU_CreateImage(width, height, GPU_FORMAT_RGBA);
    if (texture->texture != NULL)
    {
        GPU_SetImageFilter(texture->texture, GPU_FILTER_NEAREST);
        GPU_SetSnapMode(texture->texture, GPU_SNAP_NONE);

        texture->name = malloc(sizeof(char) * (strlen(name) + 1));
        if (texture->name == NULL)
            texture->name = mtrDefaultTextureName;
        else
            texture->name = strcpy(texture->name, name);
        GPU_SetAnchor(texture->texture, 0.0f, 0.0f);
        GPU_SetBlending(texture->texture, true);
        MTR_LogWrite_s("Texture created", 0, MTR_LMT_INFO, name);
        target = GPU_LoadTarget(texture->texture);
        if (target == NULL)
        {
            MTR_LogWrite_s("Texture can not be used as render targer", 0,
             MTR_LMT_INFO, name);
        }
        return freeIndex;
    }
    else
    {
        MTR_Notify("Unable to create texture", 1, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrTextureKeeper, freeIndex);
        return 0U;
    }
    return 0U;
}

/*fa MTR_TextureLoad yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_TextureLoad(const char *filename)
{
    uint32_t      freeIndex;
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED(0U);

    if (filename == NULL) {
        MTR_Notify("Unable to load texture. Filename is is not valid", 0,
         MTR_LMT_ERROR);
        return 0U;
    }

    MTR_LogWrite_s("Loading texture", 0, MTR_LMT_INFO, filename);
    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrTextureKeeper);
    MTR_LogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, freeIndex);
    texture->texture = GPU_LoadImage(filename);
    if (texture->texture != NULL)
    {
        GPU_SetImageFilter(texture->texture, GPU_FILTER_NEAREST);
        GPU_SetSnapMode(texture->texture, GPU_SNAP_NONE);

        texture->name = malloc(sizeof(char) * (strlen(filename) + 1));
        if (texture->name == NULL)
            texture->name = mtrDefaultTextureName;
        else
            texture->name = strcpy(texture->name, filename);
        GPU_SetAnchor(texture->texture, 0.0f, 0.0f);
        GPU_SetBlending(texture->texture, true);
        MTR_LogWrite_s("Texture loaded", 0, MTR_LMT_INFO, filename);
        return freeIndex;
    }
    else
    {
        MTR_Notify("Unable to load texture", 1, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrTextureKeeper, freeIndex);
        return 0U;
    }
    return 0U;
}

/*fa MTR_TextureCopy yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_TextureCopy(uint32_t texNum)
{
    uint32_t      freeIndex;
    mtrTexture_t *texture;
    mtrTexture_t *newTexture;
    SDL_Surface  *surface;
    MTR_TEXTURE_CHECK_IF_NOT_INITED(0U);

    if (texNum != 0)
    {
        freeIndex = MTR_IndexkeeperGetFreeIndex(mtrTextureKeeper);
        MTR_LogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
        newTexture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, freeIndex);
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        surface = GPU_CopySurfaceFromImage(texture->texture);
        if (surface == NULL)
        {
            MTR_Notify("Unable to copy texture", 1, MTR_LMT_ERROR);
            MTR_IndexkeeperFreeIndex(mtrTextureKeeper, freeIndex);
            return 0;
        }
        newTexture->texture = GPU_CopyImageFromSurface(surface);
        if (newTexture->texture != NULL)
        {
            MTR_LogWrite_s("Copying texture", 0, MTR_LMT_INFO, texture->name);
            GPU_SetImageFilter(texture->texture, GPU_FILTER_NEAREST);
            GPU_SetSnapMode(texture->texture, GPU_SNAP_NONE);
            newTexture->name = malloc(
             sizeof(char) * (strlen(texture->name) + 1));
            if (newTexture->name == NULL)
                newTexture->name = mtrDefaultTextureName;
            else
                newTexture->name = strcpy(newTexture->name, texture->name);
            GPU_SetAnchor(newTexture->texture, 0.0f, 0.0f);
            GPU_SetBlending(newTexture->texture, true);
            SDL_FreeSurface(surface);
            MTR_LogWrite_s("Texture copyed", 0, MTR_LMT_INFO, newTexture->name);
            return freeIndex;
        }
        else
        {
            MTR_Notify("Unable to copy texture", 1, MTR_LMT_ERROR);
            MTR_IndexkeeperFreeIndex(mtrTextureKeeper, freeIndex);
            return 0U;
        }
    }
    else
    {
        MTR_Notify("Unable to copy texture. Incorrect texture for copy", 1,
         MTR_LMT_ERROR);
        return 0U;
    }
    return 0U;
}

/*fa MTR_TextureSave yes */
MTR_DCLSPC bool MTR_CALL MTR_TextureSave(uint32_t texNum, const char *filename)
{
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED(false);

    if (filename == NULL) {
        MTR_Notify("Unable to save texture to file. Filename is is not valid",
         0, MTR_LMT_ERROR);
        return false;
    }

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        MTR_LogWrite_s("Saving texture", 0, MTR_LMT_INFO, texture->name);

        if (GPU_SaveImage(texture->texture, filename, GPU_FILE_AUTO))
        {
            MTR_LogWrite("Texture saved", 0, MTR_LMT_INFO);
            return true;
        }
        else
        {
            MTR_LogWrite("Unable to save to format autodetected by extension. "
             "Saving to PNG", 0, MTR_LMT_WARNING);
            if (GPU_SaveImage(texture->texture, filename, GPU_FILE_PNG))
            {
                MTR_LogWrite("Texture saved", 0, MTR_LMT_INFO);
                return true;
            }
            else
            {
                MTR_LogWrite("Unable to save texture", 0, MTR_LMT_ERROR);
                return false;
            }
        }
    }
    else
        MTR_LogWrite("Unable to save texture. Incorrect texture index", 0,
         MTR_LMT_ERROR);
    return false;
}

/*fa MTR_TextureCreateAlias buggy */
MTR_DCLSPC uint32_t MTR_CALL MTR_TextureCreateAlias(uint32_t texNum)
{
    uint32_t      freeIndex;
    mtrTexture_t *texture;
    mtrTexture_t *oldTexture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED(0U);

    MTR_LogWrite("Creating texture alias", 0, MTR_LMT_INFO);
    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrTextureKeeper);
    MTR_LogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, freeIndex);
    oldTexture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
    texture->texture = GPU_CreateAliasImage(oldTexture->texture);
    if (texture->texture != NULL)
    {
        texture->name = malloc(sizeof(char) * (strlen(oldTexture->name) + 1));
        texture->name = strcpy(texture->name, oldTexture->name);
        MTR_LogWrite_s("Created alias for texture", 0, MTR_LMT_INFO,
         oldTexture->name);
        return freeIndex;
    }
    else
    {
        MTR_Notify("Unable to create texture alias", 1, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrTextureKeeper, freeIndex);
        return 0U;
    }
    return 0U;
}

/*fa MTR_TextureFree yes */
MTR_DCLSPC void MTR_CALL MTR_TextureFree(uint32_t texNum)
{
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        MTR_LogWrite_s("Unloading texture", 0, MTR_LMT_INFO, texture->name);
        if (texture->name != mtrDefaultTextureName)
            free(texture->name);
        GPU_FreeImage (texture->texture);
        MTR_IndexkeeperFreeIndex(mtrTextureKeeper, texNum);
        MTR_LogWrite("Texture unloaded", 0, MTR_LMT_INFO);
    }
}

/*fa MTR_TextureSetModulation_c yes */
MTR_DCLSPC void MTR_CALL MTR_TextureSetModulation_c(uint32_t texNum,
 uint32_t color)
{
    mtrTexture_t *texture;
    uint8_t       r;
    uint8_t       g;
    uint8_t       b;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    r = color >> 16;
    g = (color & 0x00FF00) >> 8;
    b = color & 0x0000FF;
    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_SetRGB(texture->texture, r, g, b);
    }
}

/*fa MTR_TextureSetModulation_ca yes */
MTR_DCLSPC void MTR_CALL MTR_TextureSetModulation_ca(uint32_t texNum,
 uint32_t color)
{
    mtrTexture_t *texture;
    uint8_t       r;
    uint8_t       g;
    uint8_t       b;
    uint8_t       a;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    r = color >> 24;
    g = (color & 0x00FF0000) >> 16;
    b = (color & 0x0000FF00) >> 8;
    a = color & 0x000000FF;
    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_SetRGBA(texture->texture, r, g, b, a);
    }
}

/*fa MTR_TextureSetModulation_rgb yes */
MTR_DCLSPC void MTR_CALL MTR_TextureSetModulation_rgb(uint32_t texNum,
 uint8_t r, uint8_t g, uint8_t b)
{
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_SetRGB(texture->texture, r, g, b);
    }
}

/*fa MTR_TextureSetModulation_rgba yes */
MTR_DCLSPC void MTR_CALL MTR_TextureSetModulation_rgba(uint32_t texNum,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_SetRGBA(texture->texture, r, g, b, a);
    }
}

/*fa MTR_TextureSetModulationAlpha yes */
MTR_DCLSPC void MTR_CALL MTR_TextureSetModulationAlpha(uint32_t texNum,
 uint8_t alpha)
{
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_SetRGBA(texture->texture, 0xFF, 0xFF, 0xFF, alpha);
    }
}

/*fa MTR_TextureSetModulationAlpha_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureSetModulationAlpha_f(uint32_t texNum,
 float alpha)
{
    mtrTexture_t *texture;
    uint8_t       alpha8;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        alpha8 = (alpha * 255);
        alpha8 %= 256;
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_SetRGBA(texture->texture, 0xFF, 0xFF, 0xFF, alpha8);
    }
}

/*fa MTR_TextureSetBlendFunction buggy */
MTR_DCLSPC void MTR_CALL MTR_TextureSetBlendFunction(uint32_t texNum,
 int srcColor, int destColor, int srcAlpha, int dstAlpha)
{
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_SetBlendFunction(texture->texture, srcColor, destColor, srcAlpha,
         dstAlpha);
    }
}

/*fa MTR_TextureSetAlphaBlending yes */
MTR_DCLSPC void MTR_CALL MTR_TextureSetAlphaBlending(uint32_t texNum,
 bool blending)
{
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_SetBlending(texture->texture, blending);
    }
}

/*fa MTR_TextureBlit_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlit_f(uint32_t texNum, float x, float y)
{
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_Blit(texture->texture, NULL, mtrScreen->target, x, y);
    }
}

/*fa MTR_TextureBlitSized_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitSized_f(uint32_t texNum, float x,
 float y, float w, float h)
{
    GPU_Rect      outputRegion;
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

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

/*fa MTR_TextureBlitScaled_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitScaled_f(uint32_t texNum, float x,
 float y, float hscale, float vscale)
{
    GPU_Rect      outputRegion;
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        outputRegion.x = x;
        outputRegion.y = y;
        outputRegion.w = texture->texture->w * hscale;
        outputRegion.h = texture->texture->h * vscale;
        GPU_BlitRect(texture->texture, NULL, mtrScreen->target, &outputRegion);
    }
}

/*fa MTR_TextureBlitAngled_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitAngled_f(uint32_t texNum, float x,
 float y, float angle, float pivotX, float pivotY)
{
    GPU_Rect      outputRegion;
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

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

MTR_DCLSPC void MTR_CALL MTR_TextureFillShearedValue(float *shearedArray,
 int vertexNum, float x, float y, float s, float t)
{
    shearedArray[vertexNum * 4]     = x;
    shearedArray[vertexNum * 4 + 1] = y;
    shearedArray[vertexNum * 4 + 2] = s;
    shearedArray[vertexNum * 4 + 3] = t;
}

/*fa MTR_TextureBlitHorSheared_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitHorSheared_f(uint32_t texNum, float x,
 float y, float shearFactor, float originY)
{
    mtrTexture_t *texture;
    float         offsetX;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum == 0)
        return;

    texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
    offsetX = shearFactor * (texture->texture->h - originY);

    /* top left */
    MTR_TextureFillShearedValue(blitShearedValues, 0,
     x + texture->texture->h * shearFactor - offsetX, y, 0.0f, 0.0f);
    /* top right */
    MTR_TextureFillShearedValue(blitShearedValues, 1,
     x + texture->texture->h * shearFactor + texture->texture->w - offsetX, y,
     1.0f, 0.0f);
    /* bottom left */
    MTR_TextureFillShearedValue(blitShearedValues, 2, x - offsetX,
     y + texture->texture->h, 0.0f, 1.0f);

    /* bottom left */
    MTR_TextureFillShearedValue(blitShearedValues, 3, x - offsetX,
     y + texture->texture->h, 0.0f, 1.0f);
    /* top right */
    MTR_TextureFillShearedValue(blitShearedValues, 4,
     x + texture->texture->h * shearFactor + texture->texture->w - offsetX, y,
     1.0f, 0.0f);
    /* bottom right */
    MTR_TextureFillShearedValue(blitShearedValues, 5,
     x + texture->texture->w - offsetX, y + texture->texture->h, 1.0f, 1.0f);

    GPU_TriangleBatch(texture->texture, mtrScreen->target, 6,
     blitShearedValues, 0, NULL, GPU_BATCH_XY_ST);
}

/*fa MTR_TextureBlitHorShearedByAngle_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitHorShearedByAngle_f(uint32_t texNum,
 float x, float y, float angle, float originY)
{
    mtrTexture_t *texture;
    float         offsetX;
    float         shearFactor;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum == 0)
        return;

    if ((angle >= 90) || (angle <= -90))
        return;

    angle += 90;

    texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
    shearFactor = 1.0f / tanf(angle * MTR_DEGREE_F);
    offsetX = shearFactor * (texture->texture->h - originY);

    /* top left */
    MTR_TextureFillShearedValue(blitShearedValues, 0,
     x + texture->texture->h * shearFactor - offsetX, y, 0.0f, 0.0f);
    /* top right */
    MTR_TextureFillShearedValue(blitShearedValues, 1,
     x + texture->texture->h * shearFactor + texture->texture->w - offsetX, y,
     1.0f, 0.0f);
    /* bottom left */
    MTR_TextureFillShearedValue(blitShearedValues, 2, x - offsetX,
     y + texture->texture->h, 0.0f, 1.0f);

    /* bottom left */
    MTR_TextureFillShearedValue(blitShearedValues, 3, x - offsetX,
     y + texture->texture->h, 0.0f, 1.0f);
    /* top right */
    MTR_TextureFillShearedValue(blitShearedValues, 4,
     x + texture->texture->h * shearFactor + texture->texture->w - offsetX, y,
     1.0f, 0.0f);
    /* bottom right */
    MTR_TextureFillShearedValue(blitShearedValues, 5,
     x + texture->texture->w - offsetX, y + texture->texture->h, 1.0f, 1.0f);

    GPU_TriangleBatch(texture->texture, mtrScreen->target, 6,
     blitShearedValues, 0, NULL, GPU_BATCH_XY_ST);
}

/*fa MTR_TextureBlitVerSheared_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitVerSheared_f(uint32_t texNum, float x,
 float y, float shearFactor, float originX)
{
    mtrTexture_t *texture;
    float         offsetY;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum == 0)
        return;

    texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
    offsetY = shearFactor * (texture->texture->w - originX);

    /* bottom left */
    MTR_TextureFillShearedValue(blitShearedValues, 0, x,
     y + texture->texture->w * shearFactor - offsetY, 0.0f, 1.0f);
    /* top left */
    MTR_TextureFillShearedValue(blitShearedValues, 1, x,
     y + texture->texture->w * shearFactor + texture->texture->h - offsetY,
     0.0f, 0.0f);
    /* bottom right */
    MTR_TextureFillShearedValue(blitShearedValues, 2, x + texture->texture->w,
     y - offsetY, 1.0f, 1.0f);

    /* bottom right */
    MTR_TextureFillShearedValue(blitShearedValues, 3, x + texture->texture->w,
     y - offsetY, 1.0f, 1.0f);
    /* top left */
    MTR_TextureFillShearedValue(blitShearedValues, 4, x,
     y + texture->texture->w * shearFactor + texture->texture->h - offsetY,
     0.0f, 0.0f);
    /* top right */
    MTR_TextureFillShearedValue(blitShearedValues, 5, x + texture->texture->w,
     y + texture->texture->h - offsetY, 1.0f, 0.0f);

    GPU_TriangleBatch(texture->texture, mtrScreen->target, 6,
     blitShearedValues, 0, NULL, GPU_BATCH_XY_ST);
}

/*fa MTR_TextureBlitVerShearedByAngle_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitVerShearedByAngle_f(uint32_t texNum,
 float x, float y, float angle, float originX)
{
    mtrTexture_t *texture;
    float         offsetY;
    float         shearFactor;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum == 0)
        return;

    if ((angle >= 90) || (angle <= -90))
        return;

    angle += 90;

    texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
    shearFactor = 1.0f / tanf(angle * MTR_DEGREE_F);
    offsetY = shearFactor * (texture->texture->w - originX);

    /* bottom left */
    MTR_TextureFillShearedValue(blitShearedValues, 0, x,
     y + texture->texture->w * shearFactor - offsetY, 0.0f, 1.0f);
    /* top left */
    MTR_TextureFillShearedValue(blitShearedValues, 1, x,
     y + texture->texture->w * shearFactor + texture->texture->h - offsetY,
     0.0f, 0.0f);
    /* bottom right */
    MTR_TextureFillShearedValue(blitShearedValues, 2, x + texture->texture->w,
     y - offsetY, 1.0f, 1.0f);

    /* bottom right */
    MTR_TextureFillShearedValue(blitShearedValues, 3, x + texture->texture->w,
     y - offsetY, 1.0f, 1.0f);
    /* top left */
    MTR_TextureFillShearedValue(blitShearedValues, 4, x,
     y + texture->texture->w * shearFactor + texture->texture->h - offsetY,
     0.0f, 0.0f);
    /* top right */
    MTR_TextureFillShearedValue(blitShearedValues, 5, x + texture->texture->w,
     y + texture->texture->h - offsetY, 1.0f, 0.0f);

    GPU_TriangleBatch(texture->texture, mtrScreen->target, 6,
     blitShearedValues, 0, NULL, GPU_BATCH_XY_ST);
}

/*fa MTR_TextureBlitFlipped_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitFlipped_f(uint32_t texNum, float x,
 float y, int flip)
{
    GPU_Rect      outputRegion;
    mtrTexture_t *texture;
    int           actualFlip;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        actualFlip = MTR_FlipToActualFlip(flip);
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

/*fa MTR_TextureBlitGeneral_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitGeneral_f(uint32_t texNum, float x,
 float y, float hscale, float vscale, float angle, float pivotX, float pivotY,
 int flip)
{
    GPU_Rect      outputRegion;
    mtrTexture_t *texture;
    int           actualFlip;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        actualFlip = MTR_FlipToActualFlip(flip);
        outputRegion.x = x;
        outputRegion.y = y;
        outputRegion.w = texture->texture->w * hscale;
        outputRegion.h = texture->texture->h * vscale;
        if ((actualFlip & GPU_FLIP_VERTICAL) == GPU_FLIP_VERTICAL)
            outputRegion.y += outputRegion.h;
        if ((actualFlip & GPU_FLIP_HORIZONTAL) == GPU_FLIP_HORIZONTAL)
            outputRegion.x += outputRegion.w;
        GPU_BlitRectX(texture->texture, NULL, mtrScreen->target,
         &outputRegion, -angle, pivotX, pivotY, actualFlip);
    }
}

/*fa MTR_TextureBlitRegion_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitRegion_f(uint32_t texNum, float x,
 float y, float rx, float ry, float rw, float rh)
{
    GPU_Rect      region;
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

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

/*fa MTR_TextureBlitRegionSized_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitRegionSized_f(uint32_t texNum, float x,
 float y, float w, float h, float rx, float ry, float rw, float rh)
{
    GPU_Rect      region;
    GPU_Rect      outputRegion;
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

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
        GPU_BlitRect(texture->texture, &region, mtrScreen->target,
         &outputRegion);
    }
}

/*fa MTR_TextureBlitRegionScaled_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitRegionScaled_f(uint32_t texNum, float x,
 float y, float hscale, float vscale, float rx, float ry, float rw, float rh)
{
    GPU_Rect      region;
    GPU_Rect      outputRegion;
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        region.x = rx;
        region.y = ry;
        region.w = rw;
        region.h = rh;
        outputRegion.x = x;
        outputRegion.y = y;
        outputRegion.w = rw * hscale;
        outputRegion.h = rh * vscale;
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_BlitRect(texture->texture, &region, mtrScreen->target,
         &outputRegion);
    }
}

/*fa MTR_TextureBlitRegionAngled_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitRegionAngled_f(uint32_t texNum, float x,
 float y, float rx, float ry, float rw, float rh, float angle, float pivotX,
 float pivotY)
{
    GPU_Rect      region;
    GPU_Rect      outputRegion;
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

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

/*fa MTR_TextureBlitRegionHorSheared_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitRegionHorSheared_f(uint32_t texNum,
 float x, float y, float rx, float ry, float rw, float rh, float shearFactor,
 float originY)
{
    mtrTexture_t *texture;
    float         s1;
    float         t1;
    float         s2;
    float         t2;
    float         offsetX;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum == 0)
        return;

    texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);

    s1 = rx / texture->texture->w;
    s2 = (rx + (rw - 1)) / texture->texture->w;
    t1 = ry / texture->texture->h;
    t2 = (ry + (rh - 1)) / texture->texture->h;

    offsetX = shearFactor * (rh - originY);

    /* top left */
    MTR_TextureFillShearedValue(blitShearedValues, 0,
     x + rh * shearFactor - offsetX, y, s1, t1);
    /* top right */
    MTR_TextureFillShearedValue(blitShearedValues, 1,
     x + rh * shearFactor + rw - offsetX, y, s2, t1);
    /* bottom left */
    MTR_TextureFillShearedValue(blitShearedValues, 2, x - offsetX, y + rh, s1,
     t2);

    /* bottom left */
    MTR_TextureFillShearedValue(blitShearedValues, 3, x - offsetX, y + rh, s1,
     t2);
    /* top right */
    MTR_TextureFillShearedValue(blitShearedValues, 4,
     x + rh * shearFactor + rw - offsetX, y, s2, t1);
    /* bottom right */
    MTR_TextureFillShearedValue(blitShearedValues, 5, x + rw - offsetX, y + rh,
     s2, t2);

    GPU_TriangleBatch(texture->texture, mtrScreen->target, 6,
     blitShearedValues, 0, NULL, GPU_BATCH_XY_ST);
}

/*fa MTR_TextureBlitRegionHorShearedByAngle_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitRegionHorShearedByAngle_f(
 uint32_t texNum, float x, float y, float rx, float ry, float rw, float rh,
 float angle, float originY)
{
    mtrTexture_t *texture;
    float         shearFactor;
    float         s1;
    float         t1;
    float         s2;
    float         t2;
    float         offsetX;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum == 0)
        return;

    if ((angle >= 90) || (angle <= -90))
        return;

    angle += 90;

    texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);

    s1 = rx / texture->texture->w;
    s2 = (rx + (rw - 1)) / texture->texture->w;
    t1 = ry / texture->texture->h;
    t2 = (ry + (rh - 1)) / texture->texture->h;

    shearFactor = 1.0f / tanf(angle * MTR_DEGREE_F);
    offsetX = shearFactor * (rh - originY);

    /* top left */
    MTR_TextureFillShearedValue(blitShearedValues, 0,
     x + rh * shearFactor - offsetX, y, s1, t1);
    /* top right */
    MTR_TextureFillShearedValue(blitShearedValues, 1,
     x + rh * shearFactor + rw - offsetX, y, s2, t1);
    /* bottom left */
    MTR_TextureFillShearedValue(blitShearedValues, 2, x - offsetX, y + rh, s1,
     t2);

    /* bottom left */
    MTR_TextureFillShearedValue(blitShearedValues, 3, x - offsetX, y + rh, s1,
     t2);
    /* top right */
    MTR_TextureFillShearedValue(blitShearedValues, 4,
     x + rh * shearFactor + rw - offsetX, y, s2, t1);
    /* bottom right */
    MTR_TextureFillShearedValue(blitShearedValues, 5, x + rw - offsetX, y + rh,
     s2, t2);

    GPU_TriangleBatch(texture->texture, mtrScreen->target, 6,
     blitShearedValues, 0, NULL, GPU_BATCH_XY_ST);
}

/*fa MTR_TextureBlitRegionVerSheared_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitRegionVerSheared_f(uint32_t texNum,
 float x, float y, float rx, float ry, float rw, float rh, float shearFactor,
 float originX)
{
    mtrTexture_t *texture;
    float         s1;
    float         t1;
    float         s2;
    float         t2;
    float         offsetY;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum == 0)
        return;

    texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);

    s1 = rx / texture->texture->w;
    s2 = (rx + (rw - 1)) / texture->texture->w;
    t1 = ry / texture->texture->h;
    t2 = (ry + (rh - 1)) / texture->texture->h;

    offsetY = shearFactor * (rw - originX);

    /* bottom left */
    MTR_TextureFillShearedValue(blitShearedValues, 0, x,
     y + rw * shearFactor - offsetY, s1, t2);
    /* top left */
    MTR_TextureFillShearedValue(blitShearedValues, 1, x,
     y + rw * shearFactor + rh - offsetY,
     s1, t1);
    /* bottom right */
    MTR_TextureFillShearedValue(blitShearedValues, 2, x + rw, y - offsetY, s2,
     t2);

    /* bottom right */
    MTR_TextureFillShearedValue(blitShearedValues, 3, x + rw, y - offsetY, s2,
     t2);
    /* top left */
    MTR_TextureFillShearedValue(blitShearedValues, 4, x,
     y + rw * shearFactor + rh - offsetY, s1, t1);
    /* top right */
    MTR_TextureFillShearedValue(blitShearedValues, 5, x + rw, y + rh - offsetY,
     s2, t1);

    GPU_TriangleBatch(texture->texture, mtrScreen->target, 6,
     blitShearedValues, 0, NULL, GPU_BATCH_XY_ST);
}

/*fa MTR_TextureBlitRegionVerShearedByAngle_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitRegionVerShearedByAngle_f(
 uint32_t texNum, float x, float y, float rx, float ry, float rw, float rh,
 float angle, float originX)
{
    mtrTexture_t *texture;
    float         shearFactor;
    float         s1;
    float         t1;
    float         s2;
    float         t2;
    float         offsetY;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum == 0)
        return;

    if ((angle >= 90) || (angle <= -90))
        return;

    angle += 90;

    texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);

    s1 = rx / texture->texture->w;
    s2 = (rx + (rw - 1)) / texture->texture->w;
    t1 = ry / texture->texture->h;
    t2 = (ry + (rh - 1)) / texture->texture->h;

    shearFactor = 1.0f / tanf(angle * MTR_DEGREE_F);
    offsetY = shearFactor * (rw - originX);

    /* bottom left */
    MTR_TextureFillShearedValue(blitShearedValues, 0, x,
     y + rw * shearFactor - offsetY, s1, t2);
    /* top left */
    MTR_TextureFillShearedValue(blitShearedValues, 1, x,
     y + rw * shearFactor + rh - offsetY,
     s1, t1);
    /* bottom right */
    MTR_TextureFillShearedValue(blitShearedValues, 2, x + rw, y - offsetY, s2,
     t2);

    /* bottom right */
    MTR_TextureFillShearedValue(blitShearedValues, 3, x + rw, y - offsetY, s2,
     t2);
    /* top left */
    MTR_TextureFillShearedValue(blitShearedValues, 4, x,
     y + rw * shearFactor + rh - offsetY, s1, t1);
    /* top right */
    MTR_TextureFillShearedValue(blitShearedValues, 5, x + rw, y + rh - offsetY,
     s2, t1);

    GPU_TriangleBatch(texture->texture, mtrScreen->target, 6,
     blitShearedValues, 0, NULL, GPU_BATCH_XY_ST);
}

/*fa MTR_TextureBlitRegionFlipped_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitRegionFlipped_f(uint32_t texNum, float x,
 float y, float rx, float ry, float rw, float rh, int flip)
{
    GPU_Rect      region;
    GPU_Rect      outputRegion;
    mtrTexture_t *texture;
    int           actualFlip;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        actualFlip = MTR_FlipToActualFlip(flip);
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

/*fa MTR_TextureBlitRegionGeneral_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitRegionGeneral_f(uint32_t texNum, float x,
 float y, float hscale, float vscale, float rx, float ry, float rw, float rh,
 float angle, float pivotX, float pivotY, int flip)
{
    GPU_Rect      region;
    GPU_Rect      outputRegion;
    mtrTexture_t *texture;
    int           actualFlip;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        actualFlip = MTR_FlipToActualFlip(flip);
        region.x = rx;
        region.y = ry;
        region.w = rw;
        region.h = rh;
        outputRegion.x = x;
        outputRegion.y = y;
        outputRegion.w = rw * hscale;
        outputRegion.h = rh * vscale;
        if ((actualFlip & GPU_FLIP_VERTICAL) == GPU_FLIP_VERTICAL)
            outputRegion.y += outputRegion.h;
        if ((actualFlip & GPU_FLIP_HORIZONTAL) == GPU_FLIP_HORIZONTAL)
            outputRegion.x += outputRegion.w;
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        GPU_BlitRectX(texture->texture, &region, mtrScreen->target,
         &outputRegion, -angle, pivotX, pivotY, actualFlip);
    }
}

/*fa MTR_TextureReceivePixels yes */
MTR_DCLSPC bool MTR_CALL MTR_TextureReceivePixels(uint32_t texNum,
 mtrPixels_t *pixels)
{
    mtrTexture_t *texture;
    GPU_Rect      rect;
    int           textureW;
    int           textureH;
    MTR_TEXTURE_CHECK_IF_NOT_INITED(false);

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
            MTR_IndexkeeperFreeIndex(mtrTextureKeeper, texNum);
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

/*fa MTR_TextureReceivePixelsToPos yes */
MTR_DCLSPC bool MTR_CALL MTR_TextureReceivePixelsToPos(uint32_t texNum,
 mtrPixels_t *pixels, int x, int y)
{
    mtrTexture_t *texture;
    GPU_Rect      rect;
    MTR_TEXTURE_CHECK_IF_NOT_INITED(false);

    if (texNum == 0)
        return false;

    texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);

    rect.x = x;
    rect.y = y;
    rect.w = pixels->w;
    rect.h = pixels->h;

    GPU_UpdateImageBytes(texture->texture, &rect, pixels->data, pixels->pitch);

    return true;
}
