#include "sprite.h"

#include "marathoner/plugin_common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Sprite, FA_FUNCTIONS_COUNT)

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Abstraction_sprite";
    report->version = MTR_VERSION_ABSTRACTION_SPRITE;
    report->subsystem = "abstraction";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    report->prereqSubsystemsCount = 1;
    report->prereqSubsystems = malloc(sizeof(char *) * report->prereqSubsystemsCount);
    if (report->prereqSubsystems == NULL)
    {
        free(report);
        return NULL;
    }
    report->prereqSubsystems[0] = "texture";
    return report;
}

/*fa mtrSpriteInit yes */
MTR_EXPORT bool MTR_CALL mtrSpriteInit(uint32_t dmSize, uint32_t reservedCount)
{
    mtrLogWrite("Initializing sprite abstraction manager", 0, MTR_LMT_INFO);

    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTextureLoad, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTextureFree, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTextureGetSizes, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTextureSetModulation_c, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTextureSetModulation_ca, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTextureSetModulation_rgb, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTextureSetModulation_rgba, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTextureSetModulationAlpha, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTextureSetModulationAlpha_f, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTextureBlitRegion_f, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTextureBlitRegionSized_f, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTextureBlitRegionScaled_f, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTextureBlitRegionAngled_f, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTextureBlitRegionFlipped_f, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTextureBlitRegionGeneral_f, "texture");

    mtrSpriteKeeper = (mtrIndexkeeper_t *)mtrIndexkeeperCreate(dmSize,
     reservedCount, sizeof(mtrSprite_t));
    if (mtrSpriteKeeper == NULL)
    {
        mtrNotify("Unable to create indexkeeper structure for sprites", 1,
         MTR_LMT_FATAL);
        return false;
    }
    else
        mtrLogWrite("Indexkeeper structure for sprites created", 1,
         MTR_LMT_INFO);

    mtrLogWrite("Sprite abstraction manager initialized", 0, MTR_LMT_INFO);
    mtrSpriteInited = true;
    return true;
}

/*fa mtrSpriteLoad yes */
MTR_EXPORT uint32_t MTR_CALL mtrSpriteLoad(const char *filename, int clipWidth,
 int clipHeight, int rowsCount, int colsCount, int clipsCount, int anchorX,
 int anchorY)
{
    uint32_t     freeIndex;
    mtrSprite_t *sprite;
    int          textureWidth;
    int          textureHeight;
    int          i;
    MTR_SPRITE_CHECK_IF_NOT_INITED_WITH_LOG("Unable to load sprite", 0U);

    mtrLogWrite_s("Loading sprite", 0, MTR_LMT_INFO, filename);

    freeIndex = mtrIndexkeeperGetFreeIndex(mtrSpriteKeeper);
    mtrLogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, freeIndex);

    sprite->textureIndex = mtrTextureLoad(filename);
    if (sprite->textureIndex != 0)
    {
        sprite->name = malloc(sizeof(char) * (strlen(filename) + 1));
        if (sprite->name == NULL)
            sprite->name = mtrDefaultSpriteName;
        else
            sprite->name = strcpy(sprite->name, filename);
        /* TODO: Write actual values in log */
        mtrTextureGetSizes(sprite->textureIndex, &textureWidth, &textureHeight);
        mtrLogWrite_i("Texture width:", 1, MTR_LMT_INFO, textureWidth);
        mtrLogWrite_i("Texture height:", 1, MTR_LMT_INFO, textureHeight);

        if ((clipWidth != 0) && (clipWidth <= textureWidth))
            sprite->clipWidth = clipWidth;
        else
            sprite->clipWidth = textureWidth;
        mtrLogWrite_i("Clip width:", 1, MTR_LMT_INFO, sprite->clipWidth);

        if ((clipHeight != 0) && (clipHeight <= textureHeight))
            sprite->clipHeight = clipHeight;
        else
            sprite->clipHeight = textureHeight;
        mtrLogWrite_i("Clip height:", 1, MTR_LMT_INFO, sprite->clipHeight);

        if ((rowsCount == 0) || (rowsCount * sprite->clipWidth > textureWidth))
            sprite->rowsCount = textureWidth / sprite->clipWidth;
        else
            sprite->rowsCount = rowsCount;
        mtrLogWrite_i("Rows count:", 1, MTR_LMT_INFO, sprite->rowsCount);

        if ((colsCount == 0) ||
         (colsCount * sprite->clipWidth > textureWidth))
            sprite->colsCount = textureWidth / sprite->clipWidth;
        else
            sprite->colsCount = colsCount;
        mtrLogWrite_i("Cols count:", 1, MTR_LMT_INFO, sprite->colsCount);

        if (clipsCount == 0)
            sprite->clipsCount = sprite->rowsCount * sprite->colsCount;
        else
            sprite->clipsCount = clipsCount;
        mtrLogWrite_i("Clips count:", 1, MTR_LMT_INFO, sprite->clipsCount);

        sprite->clip = malloc(sizeof(mtrClip_t) * sprite->clipsCount);
        if (sprite->clip == NULL)
        {
            mtrNotify("Unable to allocate memory for clips' coords array", 1,
             MTR_LMT_ERROR);
            mtrIndexkeeperFreeIndex(mtrSpriteKeeper, freeIndex);
            if (sprite->name != mtrDefaultSpriteName)
                free(sprite->name);
            return 0;
        }

        for (i = 0; i < sprite->clipsCount; i++)
        {
            sprite->clip[i].x = sprite->clipWidth *
             (fmodl(i, sprite->colsCount));
            sprite->clip[i].y = sprite->clipHeight * (i / sprite->colsCount);
            sprite->clip[i].w = sprite->clipWidth;
            sprite->clip[i].h = sprite->clipHeight;
        }

        sprite->anchorX = anchorX;
        sprite->anchorY = anchorY;

        return freeIndex;
    }
    else
    {
        mtrNotify("Unable to load sprite", 1, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrSpriteKeeper, freeIndex);
        return 0;
    }
    return 0;
}

/*fa mtrSpriteLoadSimple yes */
MTR_EXPORT uint32_t MTR_CALL mtrSpriteLoadSimple(const char *filename,
 int anchorX, int anchorY)
{
    uint32_t     freeIndex;
    mtrSprite_t *sprite;
    int          textureWidth;
    int          textureHeight;
    MTR_SPRITE_CHECK_IF_NOT_INITED_WITH_LOG("Unable to load sprite", 0U);

    mtrLogWrite_s("Loading sprite", 0, MTR_LMT_INFO, filename);

    freeIndex = mtrIndexkeeperGetFreeIndex(mtrSpriteKeeper);
    mtrLogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, freeIndex);

    sprite->textureIndex = mtrTextureLoad(filename);
    if (sprite->textureIndex != 0)
    {
        sprite->name = malloc(sizeof(char) * (strlen(filename) + 1));
        if (sprite->name == NULL)
            sprite->name = mtrDefaultSpriteName;
        else
            sprite->name = strcpy(sprite->name, filename);

        mtrTextureGetSizes(sprite->textureIndex, &textureWidth, &textureHeight);
        mtrLogWrite_i("Texture width:", 1, MTR_LMT_INFO, textureWidth);
        mtrLogWrite_i("Texture height:", 1, MTR_LMT_INFO, textureHeight);

        sprite->clipWidth = textureWidth;
        sprite->clipHeight = textureHeight;
        sprite->rowsCount = 1;
        sprite->colsCount = 1;
        sprite->clipsCount = 1;
        sprite->clip = malloc(sizeof(mtrClip_t) * sprite->clipsCount);
        if (sprite->clip == NULL)
        {
            mtrNotify("Unable to allocate memory for clips' coords array", 1,
             MTR_LMT_ERROR);
            mtrIndexkeeperFreeIndex(mtrSpriteKeeper, freeIndex);
            if (sprite->name != mtrDefaultSpriteName)
                free(sprite->name);
            return 0;
        }

        sprite->clip[0].x = 0;
        sprite->clip[0].y = 0;
        sprite->clip[0].w = sprite->clipWidth;
        sprite->clip[0].h = sprite->clipHeight;

        sprite->anchorX = anchorX;
        sprite->anchorY = anchorY;

        return freeIndex;
    }
    else
    {
        mtrNotify("Unable to load sprite", 1, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrSpriteKeeper, freeIndex);
        return 0;
    }
    return 0;
}

/*fa mtrSpriteFree yes */
MTR_EXPORT void MTR_CALL mtrSpriteFree(uint32_t sprNum)
{
    mtrSprite_t *sprite;
    MTR_SPRITE_CHECK_IF_NOT_INITED_WITH_LOG("Unable to unload sprite",);

    if (sprNum != 0)
    {
        sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);
        mtrLogWrite_s("Unloading sprite", 0, MTR_LMT_INFO, sprite->name);
        if (sprite->name != mtrDefaultSpriteName)
            free(sprite->name);
        mtrTextureFree(sprite->textureIndex);
        mtrIndexkeeperFreeIndex(mtrSpriteKeeper, sprNum);
        mtrLogWrite("Sprite unloaded", 0, MTR_LMT_INFO);
    }
}

/*fa mtrSpriteSetModulation_c yes */
MTR_EXPORT void MTR_CALL mtrSpriteSetModulation_c(uint32_t sprNum,
 uint32_t color)
{
    mtrSprite_t *sprite;
    MTR_SPRITE_CHECK_IF_NOT_INITED();

    if (sprNum != 0)
    {
        sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);
        mtrTextureSetModulation_c(sprite->textureIndex, color);
    }
}

/*fa mtrSpriteSetModulation_ca yes */
MTR_EXPORT void MTR_CALL mtrSpriteSetModulation_ca(uint32_t sprNum,
 uint32_t color)
{
    mtrSprite_t *sprite;
    MTR_SPRITE_CHECK_IF_NOT_INITED();

    if (sprNum != 0)
    {
        sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);
        mtrTextureSetModulation_ca(sprite->textureIndex, color);
    }
}

/*fa mtrSpriteSetModulation_rgb yes */
MTR_EXPORT void MTR_CALL mtrSpriteSetModulation_rgb(uint32_t sprNum,
 uint8_t r, uint8_t g, uint8_t b)
{
    mtrSprite_t *sprite;
    MTR_SPRITE_CHECK_IF_NOT_INITED();

    if (sprNum != 0)
    {
        sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);
        mtrTextureSetModulation_rgb(sprite->textureIndex, r, g, b);
    }
}

/*fa mtrSpriteSetModulation_rgba yes */
MTR_EXPORT void MTR_CALL mtrSpriteSetModulation_rgba(uint32_t sprNum,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    mtrSprite_t *sprite;
    MTR_SPRITE_CHECK_IF_NOT_INITED();

    if (sprNum != 0)
    {
        sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);
        mtrTextureSetModulation_rgba(sprite->textureIndex, r, g, b, a);
    }
}

/*fa mtrSpriteSetModulationAlpha yes */
MTR_EXPORT void MTR_CALL mtrSpriteSetModulationAlpha(uint32_t sprNum,
 uint8_t alpha)
{
    mtrSprite_t *sprite;
    MTR_SPRITE_CHECK_IF_NOT_INITED();

    if (sprNum != 0)
    {
        sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);
        mtrTextureSetModulationAlpha(sprite->textureIndex, alpha);
    }
}

/*fa mtrSpriteSetModulationAlpha_f yes */
MTR_EXPORT void MTR_CALL mtrSpriteSetModulationAlpha_f(uint32_t sprNum,
 float alpha)
{
    mtrSprite_t *sprite;
    MTR_SPRITE_CHECK_IF_NOT_INITED();

    if (sprNum != 0)
    {
        sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);
        mtrTextureSetModulationAlpha_f(sprite->textureIndex, alpha);
    }
}

/*fa mtrSpriteDraw_f yes */
MTR_EXPORT void MTR_CALL mtrSpriteDraw_f(uint32_t sprNum, int clipNum, float x,
 float y)
{
    mtrSprite_t *sprite;
    MTR_SPRITE_CHECK_IF_NOT_INITED();

    if (sprNum != 0)
    {
        sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);
        mtrTextureBlitRegion_f(sprite->textureIndex, x - sprite->anchorX,
         y - sprite->anchorY, sprite->clip[clipNum].x,
         sprite->clip[clipNum].y, sprite->clip[clipNum].w,
         sprite->clip[clipNum].h);
    }
}

/*fa mtrSpriteDrawScaled_f yes */
MTR_EXPORT void MTR_CALL mtrSpriteDrawScaled_f(uint32_t sprNum, int clipNum,
 float x, float y, float w, float h)
{
    mtrSprite_t *sprite;
    MTR_SPRITE_CHECK_IF_NOT_INITED();

    if (sprNum != 0)
    {
        sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);
        mtrTextureBlitRegionScaled_f(sprite->textureIndex, x - sprite->anchorX,
         y - sprite->anchorY, w, h, sprite->clip[clipNum].x,
         sprite->clip[clipNum].y, sprite->clip[clipNum].w,
         sprite->clip[clipNum].h);
    }
}

/*fa mtrSpriteDrawAngled_f yes */
MTR_EXPORT void MTR_CALL mtrSpriteDrawAngled_f(uint32_t sprNum, int clipNum,
 float x, float y, float angle)
{
    mtrSprite_t *sprite;
    MTR_SPRITE_CHECK_IF_NOT_INITED();

    if (sprNum != 0)
    {
        sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);
        mtrTextureBlitRegionAngled_f(sprite->textureIndex, x - sprite->anchorX,
         y - sprite->anchorY, sprite->clip[clipNum].x,
         sprite->clip[clipNum].y, sprite->clip[clipNum].w,
         sprite->clip[clipNum].h, angle, sprite->anchorX, sprite->anchorY);
    }
}

/*fa mtrSpriteDrawFlipped_f yes */
MTR_EXPORT void MTR_CALL mtrSpriteDrawFlipped_f(uint32_t sprNum, int clipNum,
 float x, float y, int flip)
{
    mtrSprite_t *sprite;
    MTR_SPRITE_CHECK_IF_NOT_INITED();

    if (sprNum != 0)
    {
        sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);
        mtrTextureBlitRegionFlipped_f(sprite->textureIndex, x - sprite->anchorX,
         y - sprite->anchorY, sprite->clip[clipNum].x,
         sprite->clip[clipNum].y, sprite->clip[clipNum].w,
         sprite->clip[clipNum].h, flip);
    }
}

/*fa mtrSpriteDrawGeneral_f yes */
MTR_EXPORT void MTR_CALL mtrSpriteDrawGeneral_f(uint32_t sprNum, int clipNum,
 float x, float y, float w, float h, float angle, int flip)
{
    mtrSprite_t *sprite;
    MTR_SPRITE_CHECK_IF_NOT_INITED();

    if (sprNum != 0)
    {
        sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);
        mtrTextureBlitRegionGeneral_f(sprite->textureIndex, x - sprite->anchorX,
         y - sprite->anchorY, w, h, sprite->clip[clipNum].x,
         sprite->clip[clipNum].y, sprite->clip[clipNum].w,
         sprite->clip[clipNum].h, angle, sprite->anchorX, sprite->anchorY,
         flip);
    }
}
