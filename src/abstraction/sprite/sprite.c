#include "sprite.h"

#include "marathoner/plugin_common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Sprite, FA_FUNCTIONS_COUNT)

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
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

/*fa MTR_SpriteInit yes */
MTR_DCLSPC bool MTR_CALL MTR_SpriteInit(uint32_t dmSize, uint32_t reservedCount)
{
    MTR_LogWrite("Initializing sprite abstraction manager", 0, MTR_LMT_INFO);

    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TextureLoad, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TextureFree, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TextureGetSizes, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TextureSetModulation_c, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TextureSetModulation_ca, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TextureSetModulation_rgb, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TextureSetModulation_rgba, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TextureSetModulationAlpha, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TextureSetModulationAlpha_f, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TextureBlitRegion_f, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TextureBlitRegionSized_f, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TextureBlitRegionScaled_f, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TextureBlitRegionAngled_f, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TextureBlitRegionFlipped_f, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TextureBlitRegionGeneral_f, "texture");

    mtrSpriteKeeper = (mtrIndexkeeper_t *)MTR_IndexkeeperCreate(dmSize,
     reservedCount, sizeof(mtrSprite_t));
    if (mtrSpriteKeeper == NULL)
    {
        MTR_Notify("Unable to create indexkeeper structure for sprites", 1,
         MTR_LMT_FATAL);
        return false;
    }
    else
        MTR_LogWrite("Indexkeeper structure for sprites created", 1,
         MTR_LMT_INFO);

    MTR_LogWrite("Sprite abstraction manager initialized", 0, MTR_LMT_INFO);
    mtrSpriteInited = true;
    return true;
}

/*fa MTR_SpriteLoad yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_SpriteLoad(const char *filename, int clipWidth,
 int clipHeight, int rowsCount, int colsCount, int clipsCount, int anchorX,
 int anchorY)
{
    uint32_t     freeIndex;
    mtrSprite_t *sprite;
    int          textureWidth;
    int          textureHeight;
    int          i;
    MTR_SPRITE_CHECK_IF_NOT_INITED_WITH_LOG("Unable to load sprite", 0U);

    if (filename == NULL) {
        MTR_Notify("Unable to load sprite. Filename is is not valid", 0,
         MTR_LMT_ERROR);
        return 0U;
    }

    MTR_LogWrite_s("Loading sprite", 0, MTR_LMT_INFO, filename);

    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrSpriteKeeper);
    MTR_LogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, freeIndex);

    sprite->textureIndex = MTR_TextureLoad(filename);
    if (sprite->textureIndex == 0)
    {
        MTR_Notify("Unable to load sprite", 1, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrSpriteKeeper, freeIndex);
        return 0;
    }
    sprite->name = malloc(sizeof(char) * (strlen(filename) + 1));
    if (sprite->name == NULL)
        sprite->name = mtrDefaultSpriteName;
    else
        sprite->name = strcpy(sprite->name, filename);

    MTR_TextureGetSizes(sprite->textureIndex, &textureWidth, &textureHeight);
    MTR_LogWrite_i("Texture width:", 1, MTR_LMT_INFO, textureWidth);
    MTR_LogWrite_i("Texture height:", 1, MTR_LMT_INFO, textureHeight);

    if ((clipWidth != 0) && (clipWidth <= textureWidth))
        sprite->clipWidth = clipWidth;
    else
        sprite->clipWidth = textureWidth;
    MTR_LogWrite_i("Clip width:", 1, MTR_LMT_INFO, sprite->clipWidth);

    if ((clipHeight != 0) && (clipHeight <= textureHeight))
        sprite->clipHeight = clipHeight;
    else
        sprite->clipHeight = textureHeight;
    MTR_LogWrite_i("Clip height:", 1, MTR_LMT_INFO, sprite->clipHeight);

    if ((rowsCount == 0) || (rowsCount * sprite->clipWidth > textureWidth))
        sprite->rowsCount = textureWidth / sprite->clipWidth;
    else
        sprite->rowsCount = rowsCount;
    MTR_LogWrite_i("Rows count:", 1, MTR_LMT_INFO, sprite->rowsCount);

    if ((colsCount == 0) ||
     (colsCount * sprite->clipWidth > textureWidth))
        sprite->colsCount = textureWidth / sprite->clipWidth;
    else
        sprite->colsCount = colsCount;
    MTR_LogWrite_i("Cols count:", 1, MTR_LMT_INFO, sprite->colsCount);

    if (clipsCount == 0)
        sprite->clipsCount = sprite->rowsCount * sprite->colsCount;
    else
        sprite->clipsCount = clipsCount;
    MTR_LogWrite_i("Clips count:", 1, MTR_LMT_INFO, sprite->clipsCount);

    sprite->clip = malloc(sizeof(mtrClip_t) * sprite->clipsCount);
    if (sprite->clip == NULL)
    {
        MTR_Notify("Unable to allocate memory for clips' coords array", 1,
         MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrSpriteKeeper, freeIndex);
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
        sprite->clip[i].anchorX = anchorX;
        sprite->clip[i].anchorY = anchorY;
    }
    sprite->atlas = false;

    return freeIndex;
}

/*fa MTR_SpriteLoadSimple yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_SpriteLoadSimple(const char *filename,
 int anchorX, int anchorY)
{
    uint32_t     freeIndex;
    mtrSprite_t *sprite;
    int          textureWidth;
    int          textureHeight;
    MTR_SPRITE_CHECK_IF_NOT_INITED_WITH_LOG("Unable to load sprite", 0U);

    if (filename == NULL) {
        MTR_Notify("Unable to load sprite. Filename is is not valid", 0,
         MTR_LMT_ERROR);
        return 0U;
    }

    MTR_LogWrite_s("Loading sprite", 0, MTR_LMT_INFO, filename);

    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrSpriteKeeper);
    MTR_LogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, freeIndex);

    sprite->textureIndex = MTR_TextureLoad(filename);
    if (sprite->textureIndex == 0)
    {
        MTR_Notify("Unable to load sprite", 1, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrSpriteKeeper, freeIndex);
        return 0;
    }
    sprite->name = malloc(sizeof(char) * (strlen(filename) + 1));
    if (sprite->name == NULL)
        sprite->name = mtrDefaultSpriteName;
    else
        sprite->name = strcpy(sprite->name, filename);

    MTR_TextureGetSizes(sprite->textureIndex, &textureWidth, &textureHeight);
    MTR_LogWrite_i("Texture width:", 1, MTR_LMT_INFO, textureWidth);
    MTR_LogWrite_i("Texture height:", 1, MTR_LMT_INFO, textureHeight);

    sprite->clipWidth = textureWidth;
    sprite->clipHeight = textureHeight;
    sprite->rowsCount = 1;
    sprite->colsCount = 1;
    sprite->clipsCount = 1;
    sprite->clip = malloc(sizeof(mtrClip_t) * sprite->clipsCount);
    if (sprite->clip == NULL)
    {
        MTR_Notify("Unable to allocate memory for clips' coords array", 1,
         MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrSpriteKeeper, freeIndex);
        if (sprite->name != mtrDefaultSpriteName)
            free(sprite->name);
        return 0;
    }

    sprite->clip[0].x = 0;
    sprite->clip[0].y = 0;
    sprite->clip[0].w = sprite->clipWidth;
    sprite->clip[0].h = sprite->clipHeight;
    sprite->clip[0].anchorX = anchorX;
    sprite->clip[0].anchorY = anchorY;
    sprite->atlas = false;

    return freeIndex;
}

/*fa MTR_SpriteLoadAtlas yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_SpriteLoadAtlas(const char *filename,
 int clipsCount)
{
    uint32_t     freeIndex;
    mtrSprite_t *sprite;
    int          textureWidth;
    int          textureHeight;
    int          i;
    MTR_SPRITE_CHECK_IF_NOT_INITED_WITH_LOG("Unable to load sprite", 0U);

    if (filename == NULL) {
        MTR_Notify("Unable to load texture atlas. Filename is is not valid", 0,
         MTR_LMT_ERROR);
        return 0U;
    }

    MTR_LogWrite_s("Loading texture atlas", 0, MTR_LMT_INFO, filename);

    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrSpriteKeeper);
    MTR_LogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, freeIndex);

    sprite->textureIndex = MTR_TextureLoad(filename);
    if (sprite->textureIndex == 0)
    {
        MTR_Notify("Unable to load sprite", 1, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrSpriteKeeper, freeIndex);
        return 0;
    }
    sprite->name = malloc(sizeof(char) * (strlen(filename) + 1));
    if (sprite->name == NULL)
        sprite->name = mtrDefaultSpriteName;
    else
        sprite->name = strcpy(sprite->name, filename);
    MTR_TextureGetSizes(sprite->textureIndex, &textureWidth, &textureHeight);
    MTR_LogWrite_i("Texture width:", 1, MTR_LMT_INFO, textureWidth);
    MTR_LogWrite_i("Texture height:", 1, MTR_LMT_INFO, textureHeight);

    sprite->clipWidth = 0;
    sprite->clipHeight = 0;
    sprite->rowsCount = 0;
    sprite->colsCount = 0;
    sprite->clipsCount = clipsCount;
    MTR_LogWrite_i("Clips count:", 1, MTR_LMT_INFO, sprite->clipsCount);

    sprite->clip = malloc(sizeof(mtrClip_t) * sprite->clipsCount);
    if (sprite->clip == NULL)
    {
        MTR_Notify("Unable to allocate memory for clips' coords array", 1,
         MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrSpriteKeeper, freeIndex);
        if (sprite->name != mtrDefaultSpriteName)
            free(sprite->name);
        return 0;
    }

    for (i = 0; i < sprite->clipsCount; i++)
    {
        sprite->clip[i].x = 0;
        sprite->clip[i].y = 0;
        sprite->clip[i].w = 0;
        sprite->clip[i].h = 0;
        sprite->clip[i].anchorX = 0;
        sprite->clip[i].anchorY = 0;
    }
    sprite->atlas = true;

    return freeIndex;
}

/*fa MTR_SpriteSetAtlasFrame yes */
MTR_DCLSPC bool MTR_CALL MTR_SpriteSetAtlasFrame(uint32_t sprNum, int clipNum,
 int x1, int y1, int x2, int y2, int anchorX, int anchorY)
{
    mtrSprite_t *sprite;
    MTR_SPRITE_CHECK_IF_NOT_INITED(false);

    if (sprNum == 0)
        return false;

    sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);

    if (clipNum > sprite->clipsCount)
        return false;

    if (((x2 - x1) < 0) || ((y2 - y1) < 0))
        return false;

    sprite->clip[clipNum].x = x1;
    sprite->clip[clipNum].y = y1;
    sprite->clip[clipNum].w = x2 - x1 + 1;
    sprite->clip[clipNum].h = y2 - y1 + 1;
    sprite->clip[clipNum].anchorX = anchorX;
    sprite->clip[clipNum].anchorY = anchorY;

    return true;
}

/*fa MTR_SpriteFree yes */
MTR_DCLSPC void MTR_CALL MTR_SpriteFree(uint32_t sprNum)
{
    mtrSprite_t *sprite;
    MTR_SPRITE_CHECK_IF_NOT_INITED_WITH_LOG("Unable to unload sprite",);

    if (sprNum != 0)
    {
        sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);
        MTR_LogWrite_s("Unloading sprite", 0, MTR_LMT_INFO, sprite->name);
        if (sprite->name != mtrDefaultSpriteName)
            free(sprite->name);
        free(sprite->clip);
        MTR_TextureFree(sprite->textureIndex);
        MTR_IndexkeeperFreeIndex(mtrSpriteKeeper, sprNum);
        MTR_LogWrite("Sprite unloaded", 0, MTR_LMT_INFO);
    }
}

/*fa MTR_SpriteSetModulation_c yes */
MTR_DCLSPC void MTR_CALL MTR_SpriteSetModulation_c(uint32_t sprNum,
 uint32_t color)
{
    mtrSprite_t *sprite;
    MTR_SPRITE_CHECK_IF_NOT_INITED();

    if (sprNum != 0)
    {
        sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);
        MTR_TextureSetModulation_c(sprite->textureIndex, color);
    }
}

/*fa MTR_SpriteSetModulation_ca yes */
MTR_DCLSPC void MTR_CALL MTR_SpriteSetModulation_ca(uint32_t sprNum,
 uint32_t color)
{
    mtrSprite_t *sprite;
    MTR_SPRITE_CHECK_IF_NOT_INITED();

    if (sprNum != 0)
    {
        sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);
        MTR_TextureSetModulation_ca(sprite->textureIndex, color);
    }
}

/*fa MTR_SpriteSetModulation_rgb yes */
MTR_DCLSPC void MTR_CALL MTR_SpriteSetModulation_rgb(uint32_t sprNum,
 uint8_t r, uint8_t g, uint8_t b)
{
    mtrSprite_t *sprite;
    MTR_SPRITE_CHECK_IF_NOT_INITED();

    if (sprNum != 0)
    {
        sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);
        MTR_TextureSetModulation_rgb(sprite->textureIndex, r, g, b);
    }
}

/*fa MTR_SpriteSetModulation_rgba yes */
MTR_DCLSPC void MTR_CALL MTR_SpriteSetModulation_rgba(uint32_t sprNum,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    mtrSprite_t *sprite;
    MTR_SPRITE_CHECK_IF_NOT_INITED();

    if (sprNum != 0)
    {
        sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);
        MTR_TextureSetModulation_rgba(sprite->textureIndex, r, g, b, a);
    }
}

/*fa MTR_SpriteSetModulationAlpha yes */
MTR_DCLSPC void MTR_CALL MTR_SpriteSetModulationAlpha(uint32_t sprNum,
 uint8_t alpha)
{
    mtrSprite_t *sprite;
    MTR_SPRITE_CHECK_IF_NOT_INITED();

    if (sprNum != 0)
    {
        sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);
        MTR_TextureSetModulationAlpha(sprite->textureIndex, alpha);
    }
}

/*fa MTR_SpriteSetModulationAlpha_f yes */
MTR_DCLSPC void MTR_CALL MTR_SpriteSetModulationAlpha_f(uint32_t sprNum,
 float alpha)
{
    mtrSprite_t *sprite;
    MTR_SPRITE_CHECK_IF_NOT_INITED();

    if (sprNum != 0)
    {
        sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);
        MTR_TextureSetModulationAlpha_f(sprite->textureIndex, alpha);
    }
}

/*fa MTR_SpriteDraw_f yes */
MTR_DCLSPC void MTR_CALL MTR_SpriteDraw_f(uint32_t sprNum, int clipNum, float x,
 float y)
{
    mtrSprite_t *sprite;
    MTR_SPRITE_CHECK_IF_NOT_INITED();

    if (sprNum != 0)
    {
        sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);
        MTR_TextureBlitRegion_f(sprite->textureIndex,
         x - sprite->clip[clipNum].anchorX, y - sprite->clip[clipNum].anchorY,
         sprite->clip[clipNum].x, sprite->clip[clipNum].y,
         sprite->clip[clipNum].w, sprite->clip[clipNum].h);
    }
}

/*fa MTR_SpriteDrawSized_f yes */
MTR_DCLSPC void MTR_CALL MTR_SpriteDrawSized_f(uint32_t sprNum, int clipNum,
 float x, float y, float w, float h)
{
    mtrSprite_t *sprite;
    float        offsetX;
    float        offsetY;
    MTR_SPRITE_CHECK_IF_NOT_INITED();

    if (sprNum != 0)
    {
        sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);

        offsetX = x - (float)sprite->clip[clipNum].anchorX /
         (float)sprite->clip[clipNum].w * w;
        offsetY = y - (float)sprite->clip[clipNum].anchorY /
         (float)sprite->clip[clipNum].h * h;

        MTR_TextureBlitRegionSized_f(sprite->textureIndex,
         offsetX, offsetY, w, h, sprite->clip[clipNum].x,
         sprite->clip[clipNum].y, sprite->clip[clipNum].w,
         sprite->clip[clipNum].h);
    }
}

/*fa MTR_SpriteDrawScaled_f yes */
MTR_DCLSPC void MTR_CALL MTR_SpriteDrawScaled_f(uint32_t sprNum, int clipNum,
 float x, float y, float hscale, float vscale)
{
    mtrSprite_t *sprite;
    float        offsetX;
    float        offsetY;
    MTR_SPRITE_CHECK_IF_NOT_INITED();

    if (sprNum != 0)
    {
        sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);

        offsetX = x - (float)sprite->clip[clipNum].anchorX * hscale;
        offsetY = y - (float)sprite->clip[clipNum].anchorY * vscale;

        MTR_TextureBlitRegionScaled_f(sprite->textureIndex,
         offsetX, offsetY,
         hscale, vscale, sprite->clip[clipNum].x, sprite->clip[clipNum].y,
         sprite->clip[clipNum].w, sprite->clip[clipNum].h);
    }
}

/*fa MTR_SpriteDrawAngled_f yes */
MTR_DCLSPC void MTR_CALL MTR_SpriteDrawAngled_f(uint32_t sprNum, int clipNum,
 float x, float y, float angle)
{
    mtrSprite_t *sprite;
    MTR_SPRITE_CHECK_IF_NOT_INITED();

    if (sprNum != 0)
    {
        sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);
        MTR_TextureBlitRegionAngled_f(sprite->textureIndex,
         x - sprite->clip[clipNum].anchorX, y - sprite->clip[clipNum].anchorY,
         sprite->clip[clipNum].x, sprite->clip[clipNum].y,
         sprite->clip[clipNum].w, sprite->clip[clipNum].h, angle,
         sprite->clip[clipNum].anchorX, sprite->clip[clipNum].anchorY);
    }
}

/*fa MTR_SpriteDrawFlipped_f yes */
MTR_DCLSPC void MTR_CALL MTR_SpriteDrawFlipped_f(uint32_t sprNum, int clipNum,
 float x, float y, int flip)
{
    mtrSprite_t *sprite;
    MTR_SPRITE_CHECK_IF_NOT_INITED();

    if (sprNum != 0)
    {
        sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);
        MTR_TextureBlitRegionFlipped_f(sprite->textureIndex,
         x - sprite->clip[clipNum].anchorX, y - sprite->clip[clipNum].anchorY,
         sprite->clip[clipNum].x, sprite->clip[clipNum].y,
         sprite->clip[clipNum].w, sprite->clip[clipNum].h, flip);
    }
}

/*fa MTR_SpriteDrawGeneral_f yes */
MTR_DCLSPC void MTR_CALL MTR_SpriteDrawGeneral_f(uint32_t sprNum, int clipNum,
 float x, float y, float hscale, float vscale, float angle, int flip)
{
    mtrSprite_t *sprite;
    float        offsetX;
    float        offsetY;
    MTR_SPRITE_CHECK_IF_NOT_INITED();

    if (sprNum != 0)
    {
        sprite = IK_GET_DATA(mtrSprite_t *, mtrSpriteKeeper, sprNum);

        offsetX = x - (float)sprite->clip[clipNum].anchorX * hscale;
        offsetY = y - (float)sprite->clip[clipNum].anchorY * vscale;

        MTR_TextureBlitRegionGeneral_f(sprite->textureIndex,
         offsetX, offsetY, hscale, vscale, sprite->clip[clipNum].x,
         sprite->clip[clipNum].y, sprite->clip[clipNum].w,
         sprite->clip[clipNum].h, angle, sprite->clip[clipNum].anchorX,
         sprite->clip[clipNum].anchorY, flip);
    }
}
