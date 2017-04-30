#include "sprite.h"

#include "marathoner/plugin_common.c"

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

MTR_EXPORT bool MTR_CALL mtrSpriteInit(uint32_t dmSize, uint32_t reservedCount)
{
    mtrLogWrite("Initializing sprite abstraction manager", 0, MTR_LMT_INFO);

    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTextureLoad, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTextureFree, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTextureGetSizes, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTextureBlitRegion_f, "texture");
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
    return true;
}

MTR_EXPORT uint32_t MTR_CALL mtrSpriteLoad(const char *filename, int clipWidth,
 int clipHeight, int rowsCount, int colsCount, int clipsCount, int anchorX,
 int anchorY)
{
    uint32_t     freeIndex;
    mtrSprite_t *sprite;
    int          textureWidth;
    int          textureHeight;
    int          i;

    mtrLogWrite_s("Loading sprite", 0, MTR_LMT_INFO, filename);

    freeIndex = mtrIndexkeeperGetFreeIndex(mtrSpriteKeeper);
    mtrLogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    sprite = (mtrSprite_t *)(&((mtrSprite_t *)mtrSpriteKeeper->data)[freeIndex]);

    sprite->textureIndex = mtrTextureLoad(filename);
    if (sprite->textureIndex != 0)
    {
        sprite->name = malloc(sizeof(char) * (strlen(filename) + 1));
        if (sprite->name == NULL)
        {
            mtrNotify("Unable to allocate memory for sprite's name", 1,
             MTR_LMT_ERROR);
            mtrIndexkeeperFreeIndex(mtrSpriteKeeper, freeIndex);
            return 0;
        }
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
         (colsCount * sprite->clipHeight > textureHeight))
            sprite->colsCount = textureHeight / sprite->clipHeight;
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
            free(sprite->name);
            return 0;
        }

        for (i = 0; i < sprite->clipsCount; i++)
        {
            sprite->clip[i].x = sprite->clipWidth * (fmodl(i, sprite->colsCount));
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

MTR_EXPORT void MTR_CALL mtrSpriteFree(uint32_t sprNum)
{
    mtrSprite_t *sprite;
    if (sprNum != 0)
    {
        sprite = (mtrSprite_t *)(&((mtrSprite_t *)mtrSpriteKeeper->data)[sprNum]);
        mtrLogWrite_s("Unloading sprite", 0, MTR_LMT_INFO, sprite->name);
        free(sprite->name);
        mtrTextureFree(sprite->textureIndex);
        mtrIndexkeeperFreeIndex(mtrSpriteKeeper, sprNum);
        mtrLogWrite("Sprite unloaded", 0, MTR_LMT_INFO);
    }
}

MTR_EXPORT void MTR_CALL mtrSpriteDraw_f(uint32_t sprNum, int clipNum, float x,
 float y)
{
    mtrSprite_t *sprite;
    if (sprNum != 0)
    {
        sprite = (mtrSprite_t *)(&((mtrSprite_t *)mtrSpriteKeeper->data)[sprNum]);
        mtrTextureBlitRegion_f(sprite->textureIndex, x - sprite->anchorX,
         y - sprite->anchorY, sprite->clip[clipNum].x,
         sprite->clip[clipNum].y, sprite->clip[clipNum].w,
         sprite->clip[clipNum].h);
    }
}

MTR_EXPORT void MTR_CALL mtrSpriteDrawScaled_f(uint32_t sprNum, int clipNum,
 float x, float y, float w, float h)
{
    mtrSprite_t *sprite;
    if (sprNum != 0)
    {
        sprite = (mtrSprite_t *)(&((mtrSprite_t *)mtrSpriteKeeper->data)[sprNum]);
        mtrTextureBlitRegionScaled_f(sprite->textureIndex, x - sprite->anchorX,
         y - sprite->anchorY, w, h, sprite->clip[clipNum].x,
         sprite->clip[clipNum].y, sprite->clip[clipNum].w,
         sprite->clip[clipNum].h);
    }
}

MTR_EXPORT void MTR_CALL mtrSpriteDrawAngled_f(uint32_t sprNum, int clipNum,
 float x, float y, float angle)
{
    mtrSprite_t *sprite;
    if (sprNum != 0)
    {
        sprite = (mtrSprite_t *)(&((mtrSprite_t *)mtrSpriteKeeper->data)[sprNum]);
        mtrTextureBlitRegionAngled_f(sprite->textureIndex, x - sprite->anchorX,
         y - sprite->anchorY, sprite->clip[clipNum].x,
         sprite->clip[clipNum].y, sprite->clip[clipNum].w,
         sprite->clip[clipNum].h, angle, sprite->anchorX, sprite->anchorY);
    }
}

MTR_EXPORT void MTR_CALL mtrSpriteDrawFlipped_f(uint32_t sprNum, int clipNum,
 float x, float y, int flip)
{
    mtrSprite_t *sprite;
    if (sprNum != 0)
    {
        sprite = (mtrSprite_t *)(&((mtrSprite_t *)mtrSpriteKeeper->data)[sprNum]);
        mtrTextureBlitRegionFlipped_f(sprite->textureIndex, x - sprite->anchorX,
         y - sprite->anchorY, sprite->clip[clipNum].x,
         sprite->clip[clipNum].y, sprite->clip[clipNum].w,
         sprite->clip[clipNum].h, flip);
    }
}

MTR_EXPORT void MTR_CALL mtrSpriteDrawGeneral_f(uint32_t sprNum, int clipNum,
 float x, float y, float w, float h, float angle, int flip)
{
    mtrSprite_t *sprite;
    if (sprNum != 0)
    {
        sprite = (mtrSprite_t *)(&((mtrSprite_t *)mtrSpriteKeeper->data)[sprNum]);
        mtrTextureBlitRegionGeneral_f(sprite->textureIndex, x - sprite->anchorX,
         y - sprite->anchorY, w, h, sprite->clip[clipNum].x,
         sprite->clip[clipNum].y, sprite->clip[clipNum].w,
         sprite->clip[clipNum].h, angle, sprite->anchorX, sprite->anchorY,
         flip);
    }
}
