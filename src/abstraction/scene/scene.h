#ifndef MTR_ABSTRACTION_SCENE_H
#define MTR_ABSTRACTION_SCENE_H

#include "marathoner/plugin.h"
#ifdef MTR_MOD_STATIC
    #define fa faScene
#endif
#include "fa/Abstraction_scene.h"

//#include <math.h>
//#include <string.h>

typedef struct mtrCamera_t {
    bool  enabled;
    float sceneX;
    float sceneY;
    float sceneScale;
    float outputX;
    float outputY;
    float outputWidth;
    float outputHeight;
    float horBoundOutFactor; /* Число процентов от размера камеры, на которое
                              * камера может выйти за границу сцены по
                              * горизонтали. 100% - 1.0f */
    float verBoundOutFactor;
    bool  centerOnBigView; /* set camera to center of scene if scene is so small
                            * for bound out factors */
    bool  mouseWheelScaling;
    float minScale;
    float maxScale;
    bool  mouseDragging;
    int   mouseDragButton;
    bool  cursorScrolling;
    bool  arrowsScrolling;
    int   keyScrollLeft;
    int   keyScrollRight;
    int   keyScrollUp;
    int   keyScrollDown;
    float scrollingSpeed;
} mtrCamera_t;

typedef struct mtrBackground_t {
    float    sceneX; /* for tiled backgrounds it is offset */
    float    sceneY; /* for tiled backgrounds it is offset */
    bool     hTiled;
    bool     vTiled;
    bool     animated;
    uint32_t sprite;
} mtrBackground_t;

typedef struct mtrTile_t {
    uint32_t sprite;
    int      clip;
} mtrTile_t;

typedef struct mtrTileLayer_t {
    int         rows;
    int         cols;
    float       tileWidth;
    float       tileHeight;
    uint32_t    missingTileColor;
    mtrTile_t **tile; /* 2D array - tile grid */
} mtrTileLayer_t;

typedef struct mtrObject_t {
    float    sceneX;
    float    sceneY;
    uint32_t animatedSpriteIndex;
} mtrObject_t;

typedef struct mtrScene_t {
    char             *name;
    int               width;
    int               height;
    int               camerasCount;
    mtrCamera_t      *camera;
    int               backgroundsCount;
    mtrBackground_t  *background;
    int               tileLayersCount;
    mtrTileLayer_t   *tileLayer;
    mtrIndexkeeper_t *objectKeeper;
    uint32_t          nextSceneNum;
} mtrScene_t;

//mtrScene_t       *mtrScene;
char              mtrDefaultSceneName[] = "Unnamed_Scene";
mtrIndexkeeper_t *mtrSceneKeeper;
static bool       mtrSceneInited = false;
int               mtrSceneMouseX;
int               mtrSceneMouseY;
int               mtrSceneMouseWheel;

#define DEFAULT_OBJECT_DM_SIZE        MTR_IKDM_MEDIUM
#define DEFAULT_OBJECT_RESERVED_COUNT 4096
#define DEFAULT_TILE_LAYERS_COUNT     4
#define DEFAULT_BACKGROUNDS_COUNT     1
#define DEFAULT_CAMERAS_COUNT         1

#define MTR_SCENE_CHECK_IF_NOT_INITED(returnValue) \
    if (!mtrSceneInited)                           \
        return returnValue;
#define MTR_SCENE_CHECK_IF_NOT_INITED_WITH_LOG(message, returnValue) \
    if (!mtrSceneInited)                                             \
    {                                                                \
        MTR_LogWrite(                                                \
         message ". Scene abstraction manager are not initialized",  \
         1, MTR_LMT_ERROR);                                          \
        return returnValue;                                          \
    }

MTR_FUNC(void, MTR_PrimitiveRectangleFilled_ca_f, float, float, float, float,
 uint32_t);
MTR_FUNC(int, MTR_SpriteGetFramesCount, uint32_t);
MTR_FUNC(void, MTR_SpriteDrawScaled_f, uint32_t, int, float, float, float,
 float);
MTR_FUNC(bool, MTR_KeyboardPressed, int);
MTR_FUNC(int, MTR_MouseGetWheelRelative, void);
MTR_FUNC(bool, MTR_MousePress, int);
MTR_FUNC(bool, MTR_MouseRelease, int);
MTR_FUNC(void, MTR_MouseGetXY, int *, int *);

#endif
