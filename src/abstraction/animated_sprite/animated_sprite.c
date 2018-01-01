#include "animated_sprite.h"

#ifdef MTR_MOD_PLUGIN
#include "marathoner/plugin_common.c"

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Abstraction_animated_sprite";
    report->version = MTR_VERSION_ABSTRACTION_ANIMATED_SPRITE;
    report->subsystem = "abstraction";
    report->prereqsCount = 1;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    if (report->prereqs == NULL) {
        free(report);
        return NULL;
    }
    report->prereqs[0] = "Abstraction_sprite";
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}
#endif

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(AnimatedSprite, FA_FUNCTIONS_COUNT)

/*fa MTR_AnimatedSpriteInit yes */
MTR_DCLSPC bool MTR_CALL MTR_AnimatedSpriteInit(uint32_t dmSize,
 uint32_t reservedCount)
{
    #ifdef MTR_MOD_PLUGIN
    bool ok = true;
    #endif
    MTR_LogWrite("Initializing animated sprite abstraction manager", 0,
     MTR_LMT_INFO);

    #ifdef MTR_MOD_PLUGIN
    MTR_FIND_FUNCTION(MTR_SpriteFree, "Abstraction_sprite");
    MTR_FIND_FUNCTION(MTR_SpriteGetFramesCount, "Abstraction_sprite");
    MTR_FIND_FUNCTION(MTR_SpriteDrawScaled_f, "Abstraction_sprite");
    MTR_FIND_FUNCTION(MTR_SpriteDrawGeneral_f, "Abstraction_sprite");

    if (ok)
        MTR_LogWrite("Added dependent functions", 1, MTR_LMT_INFO);
    else {
        MTR_Notify("Functions not added", 1, MTR_LMT_FATAL);
        return false;
    }
    #endif

    mtrAnimatedSpriteKeeper = (mtrIndexkeeper_t *)MTR_IndexkeeperCreate(dmSize,
     reservedCount, sizeof(mtrAnimatedSprite_t));
    if (mtrAnimatedSpriteKeeper == NULL) {
        MTR_Notify(
         "Unable to create indexkeeper structure for animated sprites", 1,
         MTR_LMT_FATAL);
        return false;
    }
    else
        MTR_LogWrite("Indexkeeper structure for animated sprites created", 1,
         MTR_LMT_INFO);

    MTR_LogWrite("Animated sprite abstraction manager initialized", 0,
     MTR_LMT_INFO);
    mtrAnimatedSpriteInited = true;
    return true;
}

/*fa MTR_AnimatedSpriteCreateFromSprite yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_AnimatedSpriteCreateFromSprite(
 uint32_t spriteNum, float animSpeed, float hscale, float vscale,
 float currentFrame)
{
    uint32_t             freeIndex;
    mtrAnimatedSprite_t *animatedSprite;
    MTR_ANIMATED_SPRITE_CHECK_IF_NOT_INITED(0U);

    if (spriteNum == 0U)
        return 0U;

    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrAnimatedSpriteKeeper);
    animatedSprite = IK_GET_DATA(mtrAnimatedSprite_t *, mtrAnimatedSpriteKeeper,
     freeIndex);

    animatedSprite->spriteIndex = spriteNum;
    animatedSprite->animSpeed = animSpeed;
    animatedSprite->hscale = hscale;
    animatedSprite->vscale = vscale;
    animatedSprite->currentFrame = currentFrame;
    animatedSprite->framesCount = MTR_SpriteGetFramesCount(spriteNum);

    return freeIndex;
}

/*fa MTR_AnimatedSpriteCreate yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_AnimatedSpriteCreate(void)
{
    uint32_t             freeIndex;
    mtrAnimatedSprite_t *animatedSprite;
    MTR_ANIMATED_SPRITE_CHECK_IF_NOT_INITED(0U);

    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrAnimatedSpriteKeeper);
    animatedSprite = IK_GET_DATA(mtrAnimatedSprite_t *, mtrAnimatedSpriteKeeper,
     freeIndex);

    animatedSprite->spriteIndex = 0U;
    animatedSprite->animSpeed = 0.0f;
    animatedSprite->hscale = 1.0f;
    animatedSprite->vscale = 1.0f;
    animatedSprite->currentFrame = 0.0f;
    animatedSprite->framesCount = 0;

    return freeIndex;
}

/*fa MTR_AnimatedSpriteSetSprite yes */
MTR_DCLSPC bool MTR_CALL MTR_AnimatedSpriteSetSprite(uint32_t animatedSpriteNum,
 uint32_t spriteNum)
{
    mtrAnimatedSprite_t *animatedSprite;
    MTR_ANIMATED_SPRITE_CHECK_IF_NOT_INITED(false);

    if (spriteNum == 0U)
        return false;

    animatedSprite = IK_GET_DATA(mtrAnimatedSprite_t *, mtrAnimatedSpriteKeeper,
     animatedSpriteNum);

    animatedSprite->spriteIndex = spriteNum;
    animatedSprite->framesCount = MTR_SpriteGetFramesCount(spriteNum);

    return true;
}

/*fa MTR_AnimatedSpriteSetAnimSpeed yes */
MTR_DCLSPC bool MTR_CALL MTR_AnimatedSpriteSetAnimSpeed(
 uint32_t animatedSpriteNum, float animSpeed)
{
    mtrAnimatedSprite_t *animatedSprite;
    MTR_ANIMATED_SPRITE_CHECK_IF_NOT_INITED(false);

    animatedSprite = IK_GET_DATA(mtrAnimatedSprite_t *, mtrAnimatedSpriteKeeper,
     animatedSpriteNum);

    animatedSprite->animSpeed = animSpeed;

    return true;
}

/*fa MTR_AnimatedSpriteSetScale yes */
MTR_DCLSPC bool MTR_CALL MTR_AnimatedSpriteSetScale(uint32_t animatedSpriteNum,
 float hscale, float vscale)
{
    mtrAnimatedSprite_t *animatedSprite;
    MTR_ANIMATED_SPRITE_CHECK_IF_NOT_INITED(false);

    animatedSprite = IK_GET_DATA(mtrAnimatedSprite_t *, mtrAnimatedSpriteKeeper,
     animatedSpriteNum);

    animatedSprite->hscale = hscale;
    animatedSprite->vscale = vscale;

    return true;
}

/*fa MTR_AnimatedSpriteSetCurrentFrame yes */
MTR_DCLSPC bool MTR_CALL MTR_AnimatedSpriteSetCurrentFrame(
 uint32_t animatedSpriteNum, float currentFrame)
{
    mtrAnimatedSprite_t *animatedSprite;
    MTR_ANIMATED_SPRITE_CHECK_IF_NOT_INITED(false);

    animatedSprite = IK_GET_DATA(mtrAnimatedSprite_t *, mtrAnimatedSpriteKeeper,
     animatedSpriteNum);

    animatedSprite->currentFrame = currentFrame;

    return true;
}

/*fa MTR_AnimatedSpriteFree yes */
MTR_DCLSPC void MTR_CALL MTR_AnimatedSpriteFree(uint32_t animatedSpriteNum)
{
    mtrAnimatedSprite_t *animatedSprite;
    MTR_ANIMATED_SPRITE_CHECK_IF_NOT_INITED();

    if (animatedSpriteNum == 0U)
        return;
    animatedSprite = IK_GET_DATA(mtrAnimatedSprite_t *, mtrAnimatedSpriteKeeper,
     animatedSpriteNum);
    if (animatedSprite->spriteIndex != 0U)
        MTR_SpriteFree(animatedSprite->spriteIndex);
    MTR_IndexkeeperFreeIndex(mtrAnimatedSpriteKeeper, animatedSpriteNum);
}

/*fa MTR_AnimatedSpriteDetachSprite yes */
MTR_DCLSPC void MTR_CALL MTR_AnimatedSpriteDetachSprite(
 uint32_t animatedSpriteNum)
{
    mtrAnimatedSprite_t *animatedSprite;
    MTR_ANIMATED_SPRITE_CHECK_IF_NOT_INITED();

    if (animatedSpriteNum == 0U)
        return;
    animatedSprite = IK_GET_DATA(mtrAnimatedSprite_t *, mtrAnimatedSpriteKeeper,
     animatedSpriteNum);
    animatedSprite->spriteIndex = 0U;
}

/*fa MTR_AnimatedSpriteDraw_f yes */
MTR_DCLSPC void MTR_CALL MTR_AnimatedSpriteDraw_f(uint32_t animatedSpriteNum,
 float x, float y)
{
    mtrAnimatedSprite_t *animatedSprite;
    MTR_ANIMATED_SPRITE_CHECK_IF_NOT_INITED();

    if (animatedSpriteNum == 0U)
        return;
    animatedSprite = IK_GET_DATA(mtrAnimatedSprite_t *, mtrAnimatedSpriteKeeper,
     animatedSpriteNum);
    if (animatedSprite->spriteIndex == 0U)
        return;
    MTR_SpriteDrawScaled_f(animatedSprite->spriteIndex,
     animatedSprite->currentFrame, x, y, animatedSprite->hscale,
     animatedSprite->vscale);
}

/*fa MTR_AnimatedSpriteDrawAngled_f yes */
MTR_DCLSPC void MTR_CALL MTR_AnimatedSpriteDrawAngled_f(
 uint32_t animatedSpriteNum, float x, float y, float angle)
{
    mtrAnimatedSprite_t *animatedSprite;
    MTR_ANIMATED_SPRITE_CHECK_IF_NOT_INITED();

    if (animatedSpriteNum == 0U)
        return;
    animatedSprite = IK_GET_DATA(mtrAnimatedSprite_t *, mtrAnimatedSpriteKeeper,
     animatedSpriteNum);
    if (animatedSprite->spriteIndex == 0U)
        return;
    MTR_SpriteDrawGeneral_f(animatedSprite->spriteIndex,
     animatedSprite->currentFrame, x, y, animatedSprite->hscale,
     animatedSprite->vscale, angle, MTR_FLIP_NONE);
}

/*fa MTR_AnimatedSpriteDrawFlipped_f yes */
MTR_DCLSPC void MTR_CALL MTR_AnimatedSpriteDrawFlipped_f(
 uint32_t animatedSpriteNum, float x, float y, int flip)
{
    mtrAnimatedSprite_t *animatedSprite;
    MTR_ANIMATED_SPRITE_CHECK_IF_NOT_INITED();

    if (animatedSpriteNum == 0U)
        return;
    animatedSprite = IK_GET_DATA(mtrAnimatedSprite_t *, mtrAnimatedSpriteKeeper,
     animatedSpriteNum);
    if (animatedSprite->spriteIndex == 0U)
        return;
    MTR_SpriteDrawGeneral_f(animatedSprite->spriteIndex,
     animatedSprite->currentFrame, x, y, animatedSprite->hscale,
     animatedSprite->vscale, 0.0f, flip);
}

/*fa MTR_AnimatedSpriteDrawGeneral_f yes */
MTR_DCLSPC void MTR_CALL MTR_AnimatedSpriteDrawGeneral_f(
 uint32_t animatedSpriteNum, float x, float y, float angle, int flip)
{
    mtrAnimatedSprite_t *animatedSprite;
    MTR_ANIMATED_SPRITE_CHECK_IF_NOT_INITED();

    if (animatedSpriteNum == 0U)
        return;
    animatedSprite = IK_GET_DATA(mtrAnimatedSprite_t *, mtrAnimatedSpriteKeeper,
     animatedSpriteNum);
    if (animatedSprite->spriteIndex == 0U)
        return;
    MTR_SpriteDrawGeneral_f(animatedSprite->spriteIndex,
     animatedSprite->currentFrame, x, y, animatedSprite->hscale,
     animatedSprite->vscale, angle, flip);
}

/*fa MTR_AnimatedSpriteUpdate_f yes */
MTR_DCLSPC void MTR_CALL MTR_AnimatedSpriteUpdate_f(uint32_t animatedSpriteNum)
{
    mtrAnimatedSprite_t *animatedSprite;
    MTR_ANIMATED_SPRITE_CHECK_IF_NOT_INITED();

    if (animatedSpriteNum == 0U)
        return;
    animatedSprite = IK_GET_DATA(mtrAnimatedSprite_t *, mtrAnimatedSpriteKeeper,
     animatedSpriteNum);
    if (animatedSprite->spriteIndex == 0U)
        return;

    animatedSprite->currentFrame += animatedSprite->animSpeed +
     animatedSprite->framesCount;
    while (animatedSprite->currentFrame >= animatedSprite->framesCount) {
        animatedSprite->currentFrame -= animatedSprite->framesCount;
    }
}
