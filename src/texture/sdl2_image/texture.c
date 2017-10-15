#include "texture.h"

#include "marathoner/plugin_common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Texture, FA_FUNCTIONS_COUNT)

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Texture_SDL2_image";
    report->version = MTR_VERSION_TEXTURE_SDL2_IMAGE;
    report->subsystem = "texture";
    report->prereqsCount = 1;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    if (report->prereqs == NULL)
    {
        free(report);
        return NULL;
    }
    report->prereqs[0] = "Screen_SDL2";
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}

int mtrFlipToActualFlip(int flip)
{
    switch (flip)
    {
        case MTR_FLIP_NONE:
            return SDL_FLIP_NONE;
            break;
        case MTR_FLIP_HORIZONTAL:
            return  SDL_FLIP_HORIZONTAL;
            break;
        case MTR_FLIP_VERTICAL:
            return SDL_FLIP_VERTICAL;
            break;
        case MTR_FLIP_BOTH:
            return (SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
            break;
        default:
            return SDL_FLIP_NONE;
            break;
    }
}

/*fa mtrTextureInit yes */
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
        mtrNotify(
         "Unable to load 'mtrGetScreen' function from 'Screen_SDL2' module", 1,
         MTR_LMT_FATAL);
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

    mtrTextureInited = true;
    return true;
}

/*fa mtrTextureBeginTarget yes */
MTR_EXPORT void MTR_CALL mtrTextureBeginTarget(uint32_t texNum)
{
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        SDL_SetRenderTarget(mtrScreen->renderer, texture->texture);
    }
}

/*fa mtrTextureEndTarget yes */
MTR_EXPORT void MTR_CALL mtrTextureEndTarget()
{
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    SDL_SetRenderTarget(mtrScreen->renderer, NULL);
}

/*fa mtrTextureGetWidth yes */
MTR_EXPORT int MTR_CALL mtrTextureGetWidth(uint32_t texNum)
{
    mtrTexture_t *texture;
    int           w;
    MTR_TEXTURE_CHECK_IF_NOT_INITED(0);

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        SDL_QueryTexture(texture->texture, NULL, NULL, &w, NULL);
        return w;
    }
    else
        return 0;
}

/*fa mtrTextureGetHeight yes */
MTR_EXPORT int MTR_CALL mtrTextureGetHeight(uint32_t texNum)
{
    mtrTexture_t *texture;
    int           h;
    MTR_TEXTURE_CHECK_IF_NOT_INITED(0);

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        SDL_QueryTexture(texture->texture, NULL, NULL, NULL, &h);
        return h;
    }
    else
        return 0;
}

/*fa mtrTextureGetSizes yes */
MTR_EXPORT void MTR_CALL mtrTextureGetSizes(uint32_t texNum, int *width,
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
        SDL_QueryTexture(texture->texture, NULL, NULL, width, height);
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
    MTR_TEXTURE_CHECK_IF_NOT_INITED(0U);

    mtrLogWrite_s("Creating texture", 0, MTR_LMT_INFO, name);
    freeIndex = mtrIndexkeeperGetFreeIndex(mtrTextureKeeper);
    mtrLogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, freeIndex);

    texture->texture = SDL_CreateTexture(mtrScreen->renderer,
     SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);

    if (texture->texture != NULL)
    {
        texture->name = malloc(sizeof(char) * (strlen(name) + 1));
        if (texture->name == NULL)
            texture->name = mtrDefaultTextureName;
        else
            texture->name = strcpy(texture->name, name);
//        SDL_SetTextureBlendMode(texture->texture,
//         SDL_BLENDMODE_BLEND | SDL_BLENDMODE_MOD);
        SDL_SetTextureColorMod(texture->texture, 0xFF, 0xFF, 0xFF);
        SDL_SetTextureAlphaMod(texture->texture, 0xFF);
        mtrLogWrite_s("Texture created", 0, MTR_LMT_INFO, name);
        texture->surface = NULL;
        return freeIndex;
    }
    else
    {
        mtrNotify("Unable to create texture", 1, MTR_LMT_ERROR);
        mtrLogWrite(SDL_GetError(), 1, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrTextureKeeper, freeIndex);
        return 0U;
    }
    return 0U;
}

/*fa mtrTextureLoad yes */
MTR_EXPORT uint32_t MTR_CALL mtrTextureLoad(const char *filename)
{
    uint32_t      freeIndex;
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED(0U);

    mtrLogWrite_s("Loading texture", 0, MTR_LMT_INFO, filename);
    freeIndex = mtrIndexkeeperGetFreeIndex(mtrTextureKeeper);
    mtrLogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, freeIndex);
    texture->surface = IMG_Load(filename);
    if (texture->surface != NULL)
        mtrLogWrite("Image loaded", 1, MTR_LMT_INFO);
    else
    {
        mtrNotify("Unable to load image", 1, MTR_LMT_ERROR);
        mtrLogWrite(IMG_GetError(), 1, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrTextureKeeper, freeIndex);
        return 0;
    }
    texture->texture = SDL_CreateTextureFromSurface(mtrScreen->renderer,
     texture->surface);
    //SDL_FreeSurface(loadedImage);
    if (texture->texture != NULL)
    {
        texture->name = malloc(sizeof(char) * (strlen(filename) + 1));
        if (texture->name == NULL)
            texture->name = mtrDefaultTextureName;
        else
            texture->name = strcpy(texture->name, filename);
//        SDL_SetTextureBlendMode(texture->texture,
//         SDL_BLENDMODE_BLEND | SDL_BLENDMODE_MOD);
        SDL_SetTextureColorMod(texture->texture, 0xFF, 0xFF, 0xFF);
        SDL_SetTextureAlphaMod(texture->texture, 0xFF);
        mtrLogWrite_s("Texture loaded", 0, MTR_LMT_INFO, filename);
        return freeIndex;
    }
    else
    {
        mtrNotify("Unable to create texture", 1, MTR_LMT_ERROR);
        mtrLogWrite(SDL_GetError(), 1, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrTextureKeeper, freeIndex);
        return 0U;
    }
    return 0U;
}

/*fa mtrTextureCopy yes */
MTR_EXPORT uint32_t MTR_CALL mtrTextureCopy(uint32_t texNum)
{
    uint32_t      newIndex;
    mtrTexture_t *texture;
    mtrTexture_t *newTexture;
    void         *pixels = NULL;
    int           w;
    int           h;
    uint32_t      pixFormat;
    MTR_TEXTURE_CHECK_IF_NOT_INITED(0U);

    mtrLogWrite("Copying texture", 0, MTR_LMT_INFO);
    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);

        if (texture->surface == NULL)
        {
            if (SDL_QueryTexture(texture->texture, &pixFormat, NULL, &w, &h) <
             0)
            {
                mtrNotify("Unable to query texture", 1, MTR_LMT_ERROR);
                mtrLogWrite(SDL_GetError(), 1, MTR_LMT_ERROR);
                return 0U;
            }

            if (SDL_SetRenderTarget(mtrScreen->renderer, texture->texture) < 0)
            {
                mtrNotify("Unable to set target texture for reading pixels", 1,
                 MTR_LMT_ERROR);
                mtrLogWrite(SDL_GetError(), 1, MTR_LMT_ERROR);
                return 0U;
            }
            if (SDL_RenderReadPixels(mtrScreen->renderer, NULL, pixFormat,
             pixels, w * 4) < 0)
            {
                mtrNotify("Unable to read pixels", 1, MTR_LMT_ERROR);
                mtrLogWrite(SDL_GetError(), 1, MTR_LMT_ERROR);
                return 0U;
            }
            SDL_SetRenderTarget(mtrScreen->renderer, NULL);
            newIndex = mtrTextureCreate(texture->name, w, h);
            if (newIndex == 0)
                return 0U;
            newTexture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper,
             newIndex);
            if (SDL_UpdateTexture(newTexture->texture, NULL, pixels, w * 4) < 0)
            {
                mtrNotify("Unable to fill pixels to new texture", 1,
                 MTR_LMT_ERROR);
                mtrLogWrite(SDL_GetError(), 1, MTR_LMT_ERROR);
                mtrTextureFree(newIndex);
                return 0U;
            }
        }
        else /* texture->surface == NULL */
        {
            newIndex = mtrIndexkeeperGetFreeIndex(mtrTextureKeeper);
            mtrLogWrite_i("Found free index: ", 1, MTR_LMT_INFO, newIndex);
            newTexture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper,
             newIndex);
            newTexture->texture = SDL_CreateTextureFromSurface(
             mtrScreen->renderer, texture->surface);

            if (SDL_MUSTLOCK(texture->surface))
                if (SDL_LockSurface(texture->surface) == -1)
                {
                    mtrNotify("Unable to lock surface for reading pixels", 1,
                     MTR_LMT_ERROR);
                    mtrTextureFree(newIndex);
                    return 0U;
                }

            newTexture->surface = SDL_CreateRGBSurfaceFrom(
             texture->surface->pixels, texture->surface->w, texture->surface->h,
             32, texture->surface->pitch, 0xFF000000, 0x00FF0000, 0x0000FF00,
             0x000000FF);
            if (newTexture->surface == NULL)
            {
                mtrNotify("Unable to create new surface", 1, MTR_LMT_ERROR);
                mtrTextureFree(newIndex);
                return 0U;
            }

            if (SDL_MUSTLOCK(texture->surface))
                SDL_UnlockSurface(texture->surface);

            if (newTexture->texture == NULL)
            {
                mtrNotify("Unable to create texture from old texture's surface",
                 1, MTR_LMT_ERROR);
                mtrTextureFree(newIndex);
                return 0;
            }
            newTexture->name = malloc(
             sizeof(char) * (strlen(texture->name) + 1));
            if (newTexture->name == NULL)
                newTexture->name = mtrDefaultTextureName;
            else
                newTexture->name = strcpy(newTexture->name, texture->name);
            SDL_SetTextureColorMod(newTexture->texture, 0xFF, 0xFF, 0xFF);
            SDL_SetTextureAlphaMod(newTexture->texture, 0xFF);
        }

        mtrLogWrite("Texture copy created", 0, MTR_LMT_INFO);
        return newIndex;
    }
    else
    {
        mtrNotify("Unable to copy texture. Incorrect texture for copy", 0,
         MTR_LMT_ERROR);
        return 0U;
    }
    return 0U;
}

/*fa mtrTextureSave buggy */
MTR_EXPORT bool MTR_CALL mtrTextureSave(uint32_t texNum, const char *filename)
{
    mtrTexture_t *texture;
    void         *pixels = NULL;
    SDL_Surface  *surface = NULL;
    int           w;
    int           h;
    uint32_t      pixFormat;
    MTR_TEXTURE_CHECK_IF_NOT_INITED(false);

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        mtrLogWrite_s("Saving texture", 0, MTR_LMT_INFO, texture->name);

        if (texture->surface != NULL)
            IMG_SavePNG(texture->surface, filename);
        else
        {
            if (SDL_QueryTexture(texture->texture, &pixFormat, NULL, &w, &h) <
             0)
            {
                mtrNotify("Unable to query texture", 1, MTR_LMT_ERROR);
                mtrLogWrite(SDL_GetError(), 1, MTR_LMT_ERROR);
                return false;
            }

            if (SDL_SetRenderTarget(mtrScreen->renderer, texture->texture) < 0)
            {
                mtrNotify("Unable to set target texture for reading pixels", 1,
                 MTR_LMT_ERROR);
                mtrLogWrite(SDL_GetError(), 1, MTR_LMT_ERROR);
                return false;
            }
            if (SDL_RenderReadPixels(mtrScreen->renderer, NULL, pixFormat,
             pixels, w * 4) == -1)
            {
                mtrNotify("Unable to read pixels", 1, MTR_LMT_ERROR);
                mtrLogWrite(SDL_GetError(), 1, MTR_LMT_ERROR);
                return false;
            }
            if (pixels == NULL)
            {
                mtrNotify("Pixels are not readed", 1, MTR_LMT_ERROR);
                return false;
            }
            if (SDL_SetRenderTarget(mtrScreen->renderer, NULL) == -1)
            {
                mtrNotify("Unable to unset render target", 1, MTR_LMT_ERROR);
                return false;
            }

            surface = SDL_CreateRGBSurfaceFrom(pixels, w, h, 32, w * 4,
             0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
            if (surface == NULL)
            {
                mtrNotify("Unable to create temp surface from readed pixels", 1,
                 MTR_LMT_ERROR);
                return false;
            }
            IMG_SavePNG(surface, filename);
            SDL_FreeSurface(surface);
        }
        mtrLogWrite("Texture saved", 0, MTR_LMT_INFO);
        return true;
    }
    else
        mtrLogWrite("Unable to save texture. Incorrect texture index", 0,
         MTR_LMT_ERROR);
    return false;
}

/*fa mtrTextureCreateAlias dummy */
MTR_EXPORT uint32_t MTR_CALL mtrTextureCreateAlias(uint32_t texNum)
{
    mtrLogWrite("Creating texture alias not supported", 0, MTR_LMT_ERROR);
    return 0;
}

/*fa mtrTextureFree yes */
MTR_EXPORT void MTR_CALL mtrTextureFree(uint32_t texNum)
{
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        mtrLogWrite_s("Unloading texture", 0, MTR_LMT_INFO, texture->name);
        if (texture->name != mtrDefaultTextureName)
            free(texture->name);
        SDL_DestroyTexture(texture->texture);
        if (texture->surface != NULL)
            SDL_FreeSurface(texture->surface);
        mtrIndexkeeperFreeIndex(mtrTextureKeeper, texNum);
        mtrLogWrite("Texture unloaded", 0, MTR_LMT_INFO);
    }
}

/*fa mtrTextureSetModulation_c yes */
MTR_EXPORT void MTR_CALL mtrTextureSetModulation_c(uint32_t texNum,
 uint32_t color)
{
    mtrTexture_t *texture;
    uint8_t       r;
    uint8_t       g;
    uint8_t       b;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        SDL_SetTextureColorMod(texture->texture, r, g, b);
    }
}

/*fa mtrTextureSetModulation_ca yes */
MTR_EXPORT void MTR_CALL mtrTextureSetModulation_ca(uint32_t texNum,
 uint32_t color)
{
    mtrTexture_t *texture;
    uint8_t       r;
    uint8_t       g;
    uint8_t       b;
    uint8_t       a;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    r = (uint8_t)(color >> 24);
    g = (uint8_t)((color >> 16) - ((uint32_t)r << 8));
    b = (uint8_t)((color >> 8) - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    a = (uint8_t)(color  - ((uint32_t)r << 24) - ((uint32_t)g << 16) -
     ((uint32_t)b << 8));
    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        SDL_SetTextureColorMod(texture->texture, r, g, b);
        SDL_SetTextureAlphaMod(texture->texture, a);
    }
}

/*fa mtrTextureSetModulation_rgb yes */
MTR_EXPORT void MTR_CALL mtrTextureSetModulation_rgb(uint32_t texNum,
 uint8_t r, uint8_t g, uint8_t b)
{
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        SDL_SetTextureColorMod(texture->texture, r, g, b);
    }
}

/*fa mtrTextureSetModulation_rgba yes */
MTR_EXPORT void MTR_CALL mtrTextureSetModulation_rgba(uint32_t texNum,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        SDL_SetTextureColorMod(texture->texture, r, g, b);
        SDL_SetTextureAlphaMod(texture->texture, a);
    }
}

/*fa mtrTextureSetModulationAlpha yes */
MTR_EXPORT void MTR_CALL mtrTextureSetModulationAlpha(uint32_t texNum,
 uint8_t alpha)
{
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        SDL_SetTextureAlphaMod(texture->texture, alpha);
    }
}

/*fa mtrTextureSetModulationAlpha_f yes */
MTR_EXPORT void MTR_CALL mtrTextureSetModulationAlpha_f(uint32_t texNum,
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
        SDL_SetTextureAlphaMod(texture->texture, alpha8);
    }
}

/*fa mtrTextureSetModulationAlpha_f dummy */
MTR_EXPORT void MTR_CALL mtrTextureSetBlendFunction(uint32_t texNum,
 int srcColor, int destColor, int srcAlpha, int dstAlpha)
{
    return;
}

/*fa mtrTextureSetModulationAlpha_f dummy */
MTR_EXPORT void MTR_CALL mtrTextureSetAlphaBlending(uint32_t texNum,
 bool blending)
{
    return;
}

/*fa mtrTextureBlit_f yes */
MTR_EXPORT void MTR_CALL mtrTextureBlit_f(uint32_t texNum, float x, float y)
{
    mtrTexture_t *texture;
    SDL_Rect      offset;
    SDL_Rect      clip;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        offset.x = x;
        offset.y = y;
        SDL_QueryTexture(texture->texture, NULL, NULL, &offset.w, &offset.h);
        clip.x = 0;
        clip.y = 0;
        SDL_QueryTexture(texture->texture, NULL, NULL, &clip.w, &clip.h);
        SDL_RenderCopy(mtrScreen->renderer, texture->texture, &clip, &offset);
    }
}

/*fa mtrTextureBlitSized_f yes */
MTR_EXPORT void MTR_CALL mtrTextureBlitSized_f(uint32_t texNum, float x,
 float y, float w, float h)
{
    mtrTexture_t *texture;
    SDL_Rect      offset;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        offset.x = x;
        offset.y = y;
        offset.w = w;
        offset.h = h;
        SDL_RenderCopy(mtrScreen->renderer, texture->texture, NULL, &offset);
    }
}

/*fa mtrTextureBlitScaled_f yes */
MTR_EXPORT void MTR_CALL mtrTextureBlitScaled_f(uint32_t texNum, float x,
 float y, float hscale, float vscale)
{
    mtrTexture_t *texture;
    SDL_Rect      offset;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        offset.x = x;
        offset.y = y;
        SDL_QueryTexture(texture->texture, NULL, NULL, &offset.w, &offset.h);
        offset.w *= hscale;
        offset.h *= vscale;
        SDL_RenderCopy(mtrScreen->renderer, texture->texture, NULL, &offset);
    }
}

/*fa mtrTextureBlitAngled_f yes */
MTR_EXPORT void MTR_CALL mtrTextureBlitAngled_f(uint32_t texNum, float x,
 float y, float angle, float pivotX, float pivotY)
{
    mtrTexture_t *texture;
    SDL_Rect      offset;
    SDL_Point     pivot;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        offset.x = x;
        offset.y = y;
        SDL_QueryTexture(texture->texture, NULL, NULL, &offset.w, &offset.h);
        pivot.x = pivotX;
        pivot.y = pivotY;
        SDL_RenderCopyEx(mtrScreen->renderer, texture->texture, NULL, &offset,
         -angle, &pivot, MTR_FLIP_NONE);
    }
}

/*fa mtrTextureBlitFlipped_f yes */
MTR_EXPORT void MTR_CALL mtrTextureBlitFlipped_f(uint32_t texNum, float x,
 float y, int flip)
{
    mtrTexture_t *texture;
    SDL_Rect      offset;
    int           actualFlip;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        actualFlip = mtrFlipToActualFlip(flip);
        offset.x = x;
        offset.y = y;
        SDL_QueryTexture(texture->texture, NULL, NULL, &offset.w, &offset.h);
        SDL_RenderCopyEx(mtrScreen->renderer, texture->texture, NULL, &offset,
         0, NULL, actualFlip);
    }
}

/*fa mtrTextureBlitGeneral_f yes */
MTR_EXPORT void MTR_CALL mtrTextureBlitGeneral_f(uint32_t texNum, float x,
 float y, float hscale, float vscale, float angle, float pivotX, float pivotY,
 int flip)
{
    mtrTexture_t *texture;
    SDL_Rect      offset;
    SDL_Point     pivot;
    int           actualFlip;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        actualFlip = mtrFlipToActualFlip(flip);
        offset.x = x;
        offset.y = y;
        SDL_QueryTexture(texture->texture, NULL, NULL, &offset.w, &offset.h);
        offset.w *= hscale;
        offset.h *= vscale;
        pivot.x = pivotX;
        pivot.y = pivotY;
        SDL_RenderCopyEx(mtrScreen->renderer, texture->texture, NULL, &offset,
         -angle, &pivot, actualFlip);
    }
}

/*fa mtrTextureBlitRegion_f yes */
MTR_EXPORT void MTR_CALL mtrTextureBlitRegion_f(uint32_t texNum, float x,
 float y, float rx, float ry, float rw, float rh)
{
    mtrTexture_t *texture;
    SDL_Rect      offset;
    SDL_Rect      clip;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
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
}

/*fa mtrTextureBlitRegionSized_f yes */
MTR_EXPORT void MTR_CALL mtrTextureBlitRegionSized_f(uint32_t texNum, float x,
 float y, float w, float h, float rx, float ry, float rw, float rh)
{
    mtrTexture_t *texture;
    SDL_Rect      offset;
    SDL_Rect      clip;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        offset.x = x;
        offset.y = y;
        offset.w = w;
        offset.h = h;
        clip.x = rx;
        clip.y = ry;
        clip.w = rw;
        clip.h = rh;
        SDL_RenderCopy(mtrScreen->renderer, texture->texture, &clip, &offset);
    }
}

/*fa mtrTextureBlitRegionScaled_f yes */
MTR_EXPORT void MTR_CALL mtrTextureBlitRegionScaled_f(uint32_t texNum, float x,
 float y, float hscale, float vscale, float rx, float ry, float rw, float rh)
{
    mtrTexture_t *texture;
    SDL_Rect      offset;
    SDL_Rect      clip;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        offset.x = x;
        offset.y = y;
        offset.w = rw * hscale;
        offset.h = rh * vscale;
        clip.x = rx;
        clip.y = ry;
        clip.w = rw;
        clip.h = rh;
        SDL_RenderCopy(mtrScreen->renderer, texture->texture, &clip, &offset);
    }
}

/*fa mtrTextureBlitRegionAngled_f yes */
MTR_EXPORT void MTR_CALL mtrTextureBlitRegionAngled_f(uint32_t texNum, float x,
 float y, float rx, float ry, float rw, float rh, float angle, float pivotX,
 float pivotY)
{
    mtrTexture_t *texture;
    SDL_Rect      offset;
    SDL_Rect      clip;
    SDL_Point     pivot;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
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
}

/*fa mtrTextureBlitRegionFlipped_f yes */
MTR_EXPORT void MTR_CALL mtrTextureBlitRegionFlipped_f(uint32_t texNum, float x,
 float y, float rx, float ry, float rw, float rh, int flip)
{
    mtrTexture_t *texture;
    SDL_Rect      offset;
    SDL_Rect      clip;
    int           actualFlip;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        actualFlip = mtrFlipToActualFlip(flip);
        offset.x = x;
        offset.y = y;
        offset.w = rw;
        offset.h = rh;
        clip.x = rx;
        clip.y = ry;
        clip.w = rw;
        clip.h = rh;
        SDL_RenderCopyEx(mtrScreen->renderer, texture->texture, &clip, &offset,
         0, NULL, actualFlip);
    }
}

/*fa mtrTextureBlitRegionGeneral_f yes */
MTR_EXPORT void MTR_CALL mtrTextureBlitRegionGeneral_f(uint32_t texNum, float x,
 float y, float hscale, float vscale, float rx, float ry, float rw, float rh,
 float angle, float pivotX, float pivotY, int flip)
{
    mtrTexture_t *texture;
    SDL_Rect      offset;
    SDL_Rect      clip;
    SDL_Point     pivot;
    int           actualFlip;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        actualFlip = mtrFlipToActualFlip(flip);
        offset.x = x;
        offset.y = y;
        offset.w = rw * hscale;
        offset.h = rh * vscale;
        clip.x = rx;
        clip.y = ry;
        clip.w = rw;
        clip.h = rh;
        pivot.x = pivotX;
        pivot.y = pivotY;
        SDL_RenderCopyEx(mtrScreen->renderer, texture->texture, &clip, &offset,
         -angle, &pivot, actualFlip);
    }
}

MTR_EXPORT bool MTR_CALL mtrTextureReceivePixels(uint32_t texNum,
 mtrPixels_t *pixels)
{
    mtrTexture_t *texture;
    SDL_Rect      rect;
    uint32_t      textureFormat;
    int           textureAccess; /* not using */
    int           textureW;
    int           textureH;
    MTR_TEXTURE_CHECK_IF_NOT_INITED(false);


    if (texNum != 0)
    {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);

        if (SDL_QueryTexture(texture->texture, &textureFormat, &textureAccess,
         &textureW, &textureH) == -1)
            return false;

        if (textureW != pixels->w || textureH != pixels->h)
        {
            SDL_DestroyTexture(texture->texture);
            texture->texture = SDL_CreateTexture(mtrScreen->renderer,
             SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, pixels->w,
             pixels->h);

            if (texture->texture == NULL)
            {
                mtrIndexkeeperFreeIndex(mtrTextureKeeper, texNum);
                return false;
            }
        }

        rect.x = 0;
        rect.y = 0;
        rect.w = pixels->w;
        rect.h = pixels->h;
        if (SDL_UpdateTexture(texture->texture, &rect, pixels->data,
         pixels->pitch) == 0)
            return true;
    }
    return false;
}
