#include "sprite.h"

#include "marathoner/plugin_common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Abstraction_sprite";
    report->version = MTR_VERSION_ABSTRACTION_SPRITE;
    report->subsystem = "abstraction";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    report->prereqSubsystemsCount = 1;
    report->prereqSubsystems = malloc(sizeof(char *) * report->prereqSubsystemsCount);
    report->prereqSubsystems[0] = "texture";
    return report;
}

MTR_EXPORT bool MTR_CALL mtrSpriteInit(uint32_t dmSize, uint32_t reservedCount)
{
    mtrLogWrite("Initializing sprite abstraction manager", 0, MTR_LMT_INFO);

    mtrTextureLoad = (mtrTextureLoadFunc)mtrFindFunctionInSubsystem("texture",
     "mtrTextureLoad");
    if (mtrTextureLoad == NULL)
    {
        mtrNotify("Unable to get 'mtrTextureLoad' function from texture manager",
         1, MTR_LMT_FATAL);
        return false;
    }

    mtrTextureFree = (mtrTextureFreeFunc)mtrFindFunctionInSubsystem("texture",
     "mtrTextureFree");
    if (mtrTextureFree == NULL)
    {
        mtrNotify("Unable to get 'mtrTextureFree' function from texture manager",
         1, MTR_LMT_FATAL);
        return false;
    }

    mtrTextureGetSizes = (mtrTextureGetSizesFunc)mtrFindFunctionInSubsystem("texture",
     "mtrTextureGetSizes");
    if (mtrTextureGetSizes == NULL)
    {
        mtrNotify("Unable to get 'mtrTextureGetSizes' function from texture manager",
         1, MTR_LMT_FATAL);
        return false;
    }

    mtrTextureBlitRegion_f = (mtrTextureBlitRegion_fFunc)mtrFindFunctionInSubsystem("texture",
     "mtrTextureBlitRegion_f");
    if (mtrTextureBlitRegion_f == NULL)
    {
        mtrNotify("Unable to get 'mtrTextureBlitRegion_f' function from texture manager",
         1, MTR_LMT_FATAL);
        return false;
    }

    mtrTextureBlitRegionScaled_f = (mtrTextureBlitRegionScaled_fFunc)mtrFindFunctionInSubsystem("texture",
     "mtrTextureBlitRegionScaled_f");
    if (mtrTextureBlitRegionScaled_f == NULL)
    {
        mtrNotify("Unable to get 'mtrTextureBlitRegionScaled_f' function from texture manager",
         1, MTR_LMT_FATAL);
        return false;
    }

    mtrTextureBlitRegionAngled_f = (mtrTextureBlitRegionAngled_fFunc)mtrFindFunctionInSubsystem("texture",
     "mtrTextureBlitRegionAngled_f");
    if (mtrTextureBlitRegionAngled_f == NULL)
    {
        mtrNotify("Unable to get 'mtrTextureBlitRegionAngled_f' function from texture manager",
         1, MTR_LMT_FATAL);
        return false;
    }

    mtrTextureBlitRegionFlipped_f = (mtrTextureBlitRegionFlipped_fFunc)mtrFindFunctionInSubsystem("texture",
     "mtrTextureBlitRegionFlipped_f");
    if (mtrTextureBlitRegionFlipped_f == NULL)
    {
        mtrNotify("Unable to get 'mtrTextureBlitRegionFlipped_f' function from texture manager",
         1, MTR_LMT_FATAL);
        return false;
    }

    mtrTextureBlitRegionGeneral_f = (mtrTextureBlitRegionGeneral_fFunc)mtrFindFunctionInSubsystem("texture",
     "mtrTextureBlitRegionGeneral_f");
    if (mtrTextureBlitRegionGeneral_f == NULL)
    {
        mtrNotify("Unable to get 'mtrTextureBlitRegionGeneral_f' function from texture manager",
         1, MTR_LMT_FATAL);
        return false;
    }

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
        sprite->name = strcpy(sprite->name, filename);
        /* TODO: Write actual values in log */
        mtrTextureGetSizes(sprite->textureIndex, &textureWidth, &textureHeight);

        if ((clipWidth != 0) && (clipWidth <= textureWidth))
            sprite->clipWidth = clipWidth;
        else
            sprite->clipWidth = textureWidth;

        if ((clipHeight != 0) && (clipHeight <= textureHeight))
            sprite->clipHeight = clipHeight;
        else
            sprite->clipHeight = textureHeight;

        if ((rowsCount == 0) || (rowsCount * sprite->clipWidth > textureWidth))
            sprite->rowsCount = textureWidth / sprite->clipWidth;
        else
            sprite->rowsCount = rowsCount;

        if ((colsCount == 0) ||
         (colsCount * sprite->clipHeight > textureHeight))
            sprite->colsCount = textureHeight / sprite->clipHeight;
        else
            sprite->colsCount = colsCount;

        if (clipsCount == 0)
        {
            sprite->clipsCount = sprite->rowsCount * sprite->colsCount;
        }

        sprite->clip = malloc(sizeof(mtrClip_t) * sprite->clipsCount);
        if (sprite->clip == NULL)
        {
            mtrNotify("Unable to allocate memory for clips' coords array", 1,
             MTR_LMT_ERROR);
            mtrIndexkeeperFreeIndex(mtrSpriteKeeper, freeIndex);
        }

        for (i = 0; i < sprite->clipsCount; i++)
        {
            sprite->clip[i].x = sprite->clipWidth * (fmodl(i, sprite->colsCount));
            sprite->clip[i].y = sprite->clipHeight *
             (int)ceilf((float)i / sprite->colsCount);
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
