#include "texture.h"

#ifdef MTR_MOD_PLUGIN
#include "marathoner/plugin_common.c"

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
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
    if (report->prereqs == NULL) {
        free(report);
        return NULL;
    }
    report->prereqs[0] = "Screen_SDL2";
    report->prereqSubsystemsCount = 1;
    report->prereqSubsystems = malloc(
     sizeof(char *) * report->prereqSubsystemsCount);
    if (report->prereqSubsystems == NULL) {
        free(report);
        return NULL;
    }
    report->prereqSubsystems[0] = "png";
    return report;
}
#endif

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Texture, FA_FUNCTIONS_COUNT)

int MTR_FlipToActualFlip(int flip)
{
    switch (flip) {
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

/*fa MTR_TextureInit yes */
MTR_DCLSPC bool MTR_CALL MTR_TextureInit(uint32_t dmSize, uint32_t reservedCount)
{
    SDL_version        compiled;
    SDL_version        sdlLinked;
    const SDL_version *sdlImageLinked;

    MTR_LogWrite("Initializing texture manager", 0, MTR_LMT_INFO);

    MTR_LogWrite("Reporting SDL compile-time version:", 1, MTR_LMT_INFO);
    SDL_VERSION(&compiled);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, compiled.major);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, compiled.minor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, compiled.patch);
    MTR_LogWrite("Reporting SDL linked version:", 1, MTR_LMT_INFO);
    SDL_GetVersion(&sdlLinked);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, sdlLinked.major);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, sdlLinked.minor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, sdlLinked.patch);
    SDL_IMAGE_VERSION(&compiled);
    MTR_LogWrite("Reporting SDL_image compile-time version", 1, MTR_LMT_INFO);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, compiled.major);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, compiled.minor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, compiled.patch);
    sdlImageLinked = IMG_Linked_Version();
    MTR_LogWrite("Reporting SDL_image linked version", 1, MTR_LMT_INFO);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, sdlImageLinked->major);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, sdlImageLinked->minor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, sdlImageLinked->patch);

    #ifdef MTR_MOD_PLUGIN
    MTR_GetScreen = (MTR_GetScreenFunc)MTR_FindFunction("Screen_SDL2",
     "MTR_GetScreen");
    if (MTR_GetScreen == NULL) {
        MTR_Notify(
         "Unable to load 'MTR_GetScreen' function from 'Screen_SDL2' module", 1,
         MTR_LMT_FATAL);
        return false;
    }
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_PngInit, "png");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_PngSaveSimple, "png");

    mtrScreen = MTR_GetScreen();
    #endif

    mtrTextureKeeper = (mtrIndexkeeper_t *)MTR_IndexkeeperCreate(dmSize,
     reservedCount, sizeof(mtrTexture_t));
    if (mtrTextureKeeper == NULL) {
        MTR_Notify("Unable to create indexkeeper structure for textures", 1,
         MTR_LMT_FATAL);
        return false;
    } else
        MTR_LogWrite("Indexkeeper structure for textures created", 1,
         MTR_LMT_INFO);

    if (IMG_Init(IMG_INIT_PNG) == IMG_INIT_PNG)
        MTR_LogWrite("SDL_image initialized", 1, MTR_LMT_INFO);
    else {
        MTR_Notify("Unable to initialize SDL_image", 1, MTR_LMT_FATAL);
        MTR_LogWrite(IMG_GetError(), 1, MTR_LMT_FATAL);
        return false;
    }

    MTR_PngInit();
    tempPixels = NULL;

    MTR_LogWrite("Texture manager initialized", 0, MTR_LMT_INFO);

    mtrTextureInited = true;
    return true;
}

/*fa MTR_TextureBeginTarget yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBeginTarget(uint32_t texNum)
{
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0) {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        SDL_SetRenderTarget(mtrScreen->renderer, texture->texture);
    }
}

/*fa MTR_TextureEndTarget yes */
MTR_DCLSPC void MTR_CALL MTR_TextureEndTarget()
{
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    SDL_SetRenderTarget(mtrScreen->renderer, NULL);
}

/*fa MTR_TextureGetWidth yes */
MTR_DCLSPC int MTR_CALL MTR_TextureGetWidth(uint32_t texNum)
{
    mtrTexture_t *texture;
    int           w;
    MTR_TEXTURE_CHECK_IF_NOT_INITED(0);

    if (texNum != 0) {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        SDL_QueryTexture(texture->texture, NULL, NULL, &w, NULL);
        return w;
    } else
        return 0;
}

/*fa MTR_TextureGetHeight yes */
MTR_DCLSPC int MTR_CALL MTR_TextureGetHeight(uint32_t texNum)
{
    mtrTexture_t *texture;
    int           h;
    MTR_TEXTURE_CHECK_IF_NOT_INITED(0);

    if (texNum != 0) {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        SDL_QueryTexture(texture->texture, NULL, NULL, NULL, &h);
        return h;
    } else
        return 0;
}

/*fa MTR_TextureGetSizes yes */
MTR_DCLSPC void MTR_CALL MTR_TextureGetSizes(uint32_t texNum, int *width,
 int *height)
{
    mtrTexture_t *texture;

    if (!mtrTextureInited) {
        *width = 0;
        *height = 0;
        return;
    }

    if (texNum != 0) {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        SDL_QueryTexture(texture->texture, NULL, NULL, width, height);
    } else {
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
    MTR_TEXTURE_CHECK_IF_NOT_INITED(0U);

    MTR_LogWrite_s("Creating texture", 0, MTR_LMT_INFO, name);
    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrTextureKeeper);
    MTR_LogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, freeIndex);

    texture->texture = SDL_CreateTexture(mtrScreen->renderer,
     SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);

    if (texture->texture != NULL) {
        texture->name = malloc(sizeof(char) * (strlen(name) + 1));
        if (texture->name == NULL)
            texture->name = mtrDefaultTextureName;
        else
            texture->name = strcpy(texture->name, name);
//        SDL_SetTextureBlendMode(texture->texture,
//         SDL_BLENDMODE_BLEND | SDL_BLENDMODE_MOD);
        SDL_SetTextureColorMod(texture->texture, 0xFF, 0xFF, 0xFF);
        SDL_SetTextureAlphaMod(texture->texture, 0xFF);
        MTR_LogWrite_s("Texture created", 0, MTR_LMT_INFO, name);
        texture->surface = NULL;
        return freeIndex;
    } else {
        MTR_Notify("Unable to create texture", 1, MTR_LMT_ERROR);
        MTR_LogWrite(SDL_GetError(), 1, MTR_LMT_ERROR);
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
    texture->surface = IMG_Load(filename);
    if (texture->surface != NULL)
        MTR_LogWrite("Image loaded", 1, MTR_LMT_INFO);
    else {
        MTR_Notify("Unable to load image", 1, MTR_LMT_ERROR);
        MTR_LogWrite(IMG_GetError(), 1, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrTextureKeeper, freeIndex);
        return 0;
    }
    texture->texture = SDL_CreateTextureFromSurface(mtrScreen->renderer,
     texture->surface);
    //SDL_FreeSurface(loadedImage);
    if (texture->texture != NULL) {
        texture->name = malloc(sizeof(char) * (strlen(filename) + 1));
        if (texture->name == NULL)
            texture->name = mtrDefaultTextureName;
        else
            texture->name = strcpy(texture->name, filename);
//        SDL_SetTextureBlendMode(texture->texture,
//         SDL_BLENDMODE_BLEND | SDL_BLENDMODE_MOD);
        SDL_SetTextureColorMod(texture->texture, 0xFF, 0xFF, 0xFF);
        SDL_SetTextureAlphaMod(texture->texture, 0xFF);
        MTR_LogWrite_s("Texture loaded", 0, MTR_LMT_INFO, filename);
        return freeIndex;
    } else {
        MTR_Notify("Unable to create texture", 1, MTR_LMT_ERROR);
        MTR_LogWrite(SDL_GetError(), 1, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrTextureKeeper, freeIndex);
        return 0U;
    }
    return 0U;
}

/*fa MTR_TextureCopy yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_TextureCopy(uint32_t texNum)
{
    uint32_t      newIndex;
    mtrTexture_t *texture;
    mtrTexture_t *newTexture;
    void         *pixels = NULL;
    int           w;
    int           h;
    uint32_t      pixFormat;
    MTR_TEXTURE_CHECK_IF_NOT_INITED(0U);

    MTR_LogWrite("Copying texture", 0, MTR_LMT_INFO);
    if (texNum != 0) {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);

        if (texture->surface == NULL) {
            if (SDL_QueryTexture(texture->texture, &pixFormat, NULL, &w, &h) <
             0)
            {
                MTR_Notify("Unable to query texture", 1, MTR_LMT_ERROR);
                MTR_LogWrite(SDL_GetError(), 1, MTR_LMT_ERROR);
                return 0U;
            }

            if (SDL_SetRenderTarget(mtrScreen->renderer, texture->texture) < 0)
            {
                MTR_Notify("Unable to set target texture for reading pixels", 1,
                 MTR_LMT_ERROR);
                MTR_LogWrite(SDL_GetError(), 1, MTR_LMT_ERROR);
                return 0U;
            }
            if (SDL_RenderReadPixels(mtrScreen->renderer, NULL, pixFormat,
             pixels, w * 4) < 0)
            {
                MTR_Notify("Unable to read pixels", 1, MTR_LMT_ERROR);
                MTR_LogWrite(SDL_GetError(), 1, MTR_LMT_ERROR);
                return 0U;
            }
            SDL_SetRenderTarget(mtrScreen->renderer, NULL);
            newIndex = MTR_TextureCreate(texture->name, w, h);
            if (newIndex == 0)
                return 0U;
            newTexture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper,
             newIndex);
            if (SDL_UpdateTexture(newTexture->texture, NULL, pixels, w * 4) < 0)
            {
                MTR_Notify("Unable to fill pixels to new texture", 1,
                 MTR_LMT_ERROR);
                MTR_LogWrite(SDL_GetError(), 1, MTR_LMT_ERROR);
                MTR_TextureFree(newIndex);
                return 0U;
            }
        } else { /* texture->surface == NULL */
            newIndex = MTR_IndexkeeperGetFreeIndex(mtrTextureKeeper);
            MTR_LogWrite_i("Found free index: ", 1, MTR_LMT_INFO, newIndex);
            newTexture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper,
             newIndex);
            newTexture->texture = SDL_CreateTextureFromSurface(
             mtrScreen->renderer, texture->surface);

            if (SDL_MUSTLOCK(texture->surface))
                if (SDL_LockSurface(texture->surface) == -1) {
                    MTR_Notify("Unable to lock surface for reading pixels", 1,
                     MTR_LMT_ERROR);
                    MTR_TextureFree(newIndex);
                    return 0U;
                }

            newTexture->surface = SDL_CreateRGBSurfaceFrom(
             texture->surface->pixels, texture->surface->w, texture->surface->h,
             32, texture->surface->pitch, 0xFF000000, 0x00FF0000, 0x0000FF00,
             0x000000FF);
            if (newTexture->surface == NULL) {
                MTR_Notify("Unable to create new surface", 1, MTR_LMT_ERROR);
                MTR_TextureFree(newIndex);
                return 0U;
            }

            if (SDL_MUSTLOCK(texture->surface))
                SDL_UnlockSurface(texture->surface);

            if (newTexture->texture == NULL) {
                MTR_Notify("Unable to create texture from old texture's surface",
                 1, MTR_LMT_ERROR);
                MTR_TextureFree(newIndex);
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

        MTR_LogWrite("Texture copy created", 0, MTR_LMT_INFO);
        return newIndex;
    } else {
        MTR_Notify("Unable to copy texture. Incorrect texture for copy", 0,
         MTR_LMT_ERROR);
        return 0U;
    }
    return 0U;
}

bool MTR_TextureCheckExtension(const char *filename, const char *ext)
{
    uint16_t fnLength;
    uint16_t extLength;
    uint16_t diff;
    uint16_t i;

    fnLength = strlen (filename);
    extLength = strlen (ext);

    if (extLength < fnLength)
        return false;

    diff = fnLength - extLength;
    for (i = 0; i < extLength; i++) {
        if (ext[i] != filename[i + diff])
            return false;
    }
    return true;
}

bool MTR_TextureSaveSurface(SDL_Surface *surface, const char *filename)
{
    bool success;

    if (tempPixels != NULL)
        free(tempPixels);

    if (filename == NULL)
        return false;

    if (!MTR_TextureCheckExtension(filename, "png") ||
     !MTR_TextureCheckExtension(filename, "PNG"))
        return false;

    tempPixels = malloc(sizeof(mtrPixels_t));
    if (tempPixels == NULL)
        return false;

    tempPixels->data = surface->pixels;
    tempPixels->w = surface->w;
    tempPixels->h = surface->h;
    tempPixels->pitch = surface->pitch;
    tempPixels->pixelformat = MTR_PF_RGBA;

    success = MTR_PngSaveSimple(filename, tempPixels);

    return success;
}

/*fa MTR_TextureSave partial */
MTR_DCLSPC bool MTR_CALL MTR_TextureSave(uint32_t texNum, const char *filename)
{
    mtrTexture_t *texture;
    void         *pixels = NULL;
    SDL_Surface  *surface = NULL;
    int           w;
    int           h;
    uint32_t      pixFormat;
    MTR_TEXTURE_CHECK_IF_NOT_INITED(false);

    if (filename == NULL) {
        MTR_Notify("Unable to save texture to file. Filename is is not valid",
         0, MTR_LMT_ERROR);
        return false;
    }

    if (texNum == 0) {
        MTR_LogWrite("Unable to save texture. Incorrect texture index", 0,
         MTR_LMT_ERROR);
        return false;
    }

    texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
    MTR_LogWrite_s("Saving texture", 0, MTR_LMT_INFO, texture->name);

    if (texture->surface != NULL)
        MTR_TextureSaveSurface(texture->surface, filename);
    else {
        if (SDL_QueryTexture(texture->texture, &pixFormat, NULL, &w, &h) < 0) {
            MTR_Notify("Unable to query texture", 1, MTR_LMT_ERROR);
            MTR_LogWrite(SDL_GetError(), 1, MTR_LMT_ERROR);
            return false;
        }

        if (SDL_SetRenderTarget(mtrScreen->renderer, texture->texture) < 0) {
            MTR_Notify("Unable to set target texture for reading pixels", 1,
             MTR_LMT_ERROR);
            MTR_LogWrite(SDL_GetError(), 1, MTR_LMT_ERROR);
            return false;
        }
        if (SDL_RenderReadPixels(mtrScreen->renderer, NULL, pixFormat,
         pixels, w * 4) == -1)
        {
            MTR_Notify("Unable to read pixels", 1, MTR_LMT_ERROR);
            MTR_LogWrite(SDL_GetError(), 1, MTR_LMT_ERROR);
            return false;
        }
        if (pixels == NULL) {
            MTR_Notify("Pixels are not readed", 1, MTR_LMT_ERROR);
            return false;
        }
        if (SDL_SetRenderTarget(mtrScreen->renderer, NULL) == -1) {
            MTR_Notify("Unable to unset render target", 1, MTR_LMT_ERROR);
            return false;
        }

        surface = SDL_CreateRGBSurfaceFrom(pixels, w, h, 32, w * 4,
         0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
        if (surface == NULL) {
            MTR_Notify("Unable to create temp surface from readed pixels", 1,
             MTR_LMT_ERROR);
            return false;
        }
        MTR_TextureSaveSurface(surface, filename);
        SDL_FreeSurface(surface);
    }
    MTR_LogWrite("Texture saved", 0, MTR_LMT_INFO);
    return true;
}

/*fa MTR_TextureCreateAlias dummy */
MTR_DCLSPC uint32_t MTR_CALL MTR_TextureCreateAlias(uint32_t texNum)
{
    MTR_LogWrite("Creating texture alias not supported", 0, MTR_LMT_ERROR);
    return 0;
}

/*fa MTR_TextureFree yes */
MTR_DCLSPC void MTR_CALL MTR_TextureFree(uint32_t texNum)
{
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0) {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        MTR_LogWrite_s("Unloading texture", 0, MTR_LMT_INFO, texture->name);
        if (texture->name != mtrDefaultTextureName)
            free(texture->name);
        SDL_DestroyTexture(texture->texture);
        if (texture->surface != NULL)
            SDL_FreeSurface(texture->surface);
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
    if (texNum != 0) {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        SDL_SetTextureColorMod(texture->texture, r, g, b);
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
    if (texNum != 0) {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        SDL_SetTextureColorMod(texture->texture, r, g, b);
        SDL_SetTextureAlphaMod(texture->texture, a);
    }
}

/*fa MTR_TextureSetModulation_rgb yes */
MTR_DCLSPC void MTR_CALL MTR_TextureSetModulation_rgb(uint32_t texNum,
 uint8_t r, uint8_t g, uint8_t b)
{
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0) {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        SDL_SetTextureColorMod(texture->texture, r, g, b);
    }
}

/*fa MTR_TextureSetModulation_rgba yes */
MTR_DCLSPC void MTR_CALL MTR_TextureSetModulation_rgba(uint32_t texNum,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0) {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        SDL_SetTextureColorMod(texture->texture, r, g, b);
        SDL_SetTextureAlphaMod(texture->texture, a);
    }
}

/*fa MTR_TextureSetModulationAlpha yes */
MTR_DCLSPC void MTR_CALL MTR_TextureSetModulationAlpha(uint32_t texNum,
 uint8_t alpha)
{
    mtrTexture_t *texture;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0) {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        SDL_SetTextureAlphaMod(texture->texture, alpha);
    }
}

/*fa MTR_TextureSetModulationAlpha_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureSetModulationAlpha_f(uint32_t texNum,
 float alpha)
{
    mtrTexture_t *texture;
    uint8_t       alpha8;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0) {
        alpha8 = (alpha * 255);
        alpha8 %= 256;
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        SDL_SetTextureAlphaMod(texture->texture, alpha8);
    }
}

/*fa MTR_TextureSetModulationAlpha_f dummy */
MTR_DCLSPC void MTR_CALL MTR_TextureSetBlendFunction(uint32_t texNum,
 int srcColor, int destColor, int srcAlpha, int dstAlpha)
{
    return;
}

/*fa MTR_TextureSetModulationAlpha_f dummy */
MTR_DCLSPC void MTR_CALL MTR_TextureSetAlphaBlending(uint32_t texNum,
 bool blending)
{
    return;
}

/*fa MTR_TextureBlit_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlit_f(uint32_t texNum, float x, float y)
{
    mtrTexture_t *texture;
    SDL_Rect      offset;
    SDL_Rect      clip;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0) {
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

/*fa MTR_TextureBlitSized_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitSized_f(uint32_t texNum, float x,
 float y, float w, float h)
{
    mtrTexture_t *texture;
    SDL_Rect      offset;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0) {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        offset.x = x;
        offset.y = y;
        offset.w = w;
        offset.h = h;
        SDL_RenderCopy(mtrScreen->renderer, texture->texture, NULL, &offset);
    }
}

/*fa MTR_TextureBlitScaled_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitScaled_f(uint32_t texNum, float x,
 float y, float hscale, float vscale)
{
    mtrTexture_t *texture;
    SDL_Rect      offset;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0) {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        offset.x = x;
        offset.y = y;
        SDL_QueryTexture(texture->texture, NULL, NULL, &offset.w, &offset.h);
        offset.w *= hscale;
        offset.h *= vscale;
        SDL_RenderCopy(mtrScreen->renderer, texture->texture, NULL, &offset);
    }
}

/*fa MTR_TextureBlitAngled_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitAngled_f(uint32_t texNum, float x,
 float y, float angle, float pivotX, float pivotY)
{
    mtrTexture_t *texture;
    SDL_Rect      offset;
    SDL_Point     pivot;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0) {
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

/*fa MTR_TextureBlitFlipped_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitFlipped_f(uint32_t texNum, float x,
 float y, int flip)
{
    mtrTexture_t *texture;
    SDL_Rect      offset;
    int           actualFlip;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0) {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        actualFlip = MTR_FlipToActualFlip(flip);
        offset.x = x;
        offset.y = y;
        SDL_QueryTexture(texture->texture, NULL, NULL, &offset.w, &offset.h);
        SDL_RenderCopyEx(mtrScreen->renderer, texture->texture, NULL, &offset,
         0, NULL, actualFlip);
    }
}

/*fa MTR_TextureBlitGeneral_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitGeneral_f(uint32_t texNum, float x,
 float y, float hscale, float vscale, float angle, float pivotX, float pivotY,
 int flip)
{
    mtrTexture_t *texture;
    SDL_Rect      offset;
    SDL_Point     pivot;
    int           actualFlip;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0) {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        actualFlip = MTR_FlipToActualFlip(flip);
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

/*fa MTR_TextureBlitRegion_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitRegion_f(uint32_t texNum, float x,
 float y, float rx, float ry, float rw, float rh)
{
    mtrTexture_t *texture;
    SDL_Rect      offset;
    SDL_Rect      clip;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0) {
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

/*fa MTR_TextureBlitRegionSized_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitRegionSized_f(uint32_t texNum, float x,
 float y, float w, float h, float rx, float ry, float rw, float rh)
{
    mtrTexture_t *texture;
    SDL_Rect      offset;
    SDL_Rect      clip;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0) {
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

/*fa MTR_TextureBlitRegionScaled_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitRegionScaled_f(uint32_t texNum, float x,
 float y, float hscale, float vscale, float rx, float ry, float rw, float rh)
{
    mtrTexture_t *texture;
    SDL_Rect      offset;
    SDL_Rect      clip;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0) {
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

/*fa MTR_TextureBlitRegionAngled_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitRegionAngled_f(uint32_t texNum, float x,
 float y, float rx, float ry, float rw, float rh, float angle, float pivotX,
 float pivotY)
{
    mtrTexture_t *texture;
    SDL_Rect      offset;
    SDL_Rect      clip;
    SDL_Point     pivot;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0) {
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

/*fa MTR_TextureBlitRegionFlipped_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitRegionFlipped_f(uint32_t texNum, float x,
 float y, float rx, float ry, float rw, float rh, int flip)
{
    mtrTexture_t *texture;
    SDL_Rect      offset;
    SDL_Rect      clip;
    int           actualFlip;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0) {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        actualFlip = MTR_FlipToActualFlip(flip);
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

/*fa MTR_TextureBlitRegionGeneral_f yes */
MTR_DCLSPC void MTR_CALL MTR_TextureBlitRegionGeneral_f(uint32_t texNum,
 float x, float y, float hscale, float vscale, float rx, float ry, float rw,
 float rh, float angle, float pivotX, float pivotY, int flip)
{
    mtrTexture_t *texture;
    SDL_Rect      offset;
    SDL_Rect      clip;
    SDL_Point     pivot;
    int           actualFlip;
    MTR_TEXTURE_CHECK_IF_NOT_INITED();

    if (texNum != 0) {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);
        actualFlip = MTR_FlipToActualFlip(flip);
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

/*fa MTR_TextureReceivePixels yes */
MTR_DCLSPC bool MTR_CALL MTR_TextureReceivePixels(uint32_t texNum,
 mtrPixels_t *pixels)
{
    mtrTexture_t *texture;
    SDL_Rect      rect;
    uint32_t      textureFormat;
    int           textureAccess; /* not using */
    int           textureW;
    int           textureH;
    MTR_TEXTURE_CHECK_IF_NOT_INITED(false);


    if (texNum != 0) {
        texture = IK_GET_DATA(mtrTexture_t *, mtrTextureKeeper, texNum);

        if (SDL_QueryTexture(texture->texture, &textureFormat, &textureAccess,
         &textureW, &textureH) == -1)
            return false;

        if (textureW != pixels->w || textureH != pixels->h) {
            SDL_DestroyTexture(texture->texture);
            texture->texture = SDL_CreateTexture(mtrScreen->renderer,
             SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, pixels->w,
             pixels->h);

            if (texture->texture == NULL) {
                MTR_IndexkeeperFreeIndex(mtrTextureKeeper, texNum);
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
