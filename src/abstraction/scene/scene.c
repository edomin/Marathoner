#include "scene.h"

#ifdef MTR_MOD_PLUGIN
#include "marathoner/plugin_common.c"

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Abstraction_scene";
    report->version = MTR_VERSION_ABSTRACTION_SCENE;
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

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Scene, FA_FUNCTIONS_COUNT)

/*fa MTR_GameInit yes */
MTR_DCLSPC bool MTR_CALL MTR_SceneInit(uint32_t sceneDmSize,
 uint32_t sceneReservedCount)
{
    #ifdef MTR_MOD_PLUGIN
    bool ok = true;
    #endif

    MTR_LogWrite("Initializing scene abstraction manager", 0, MTR_LMT_INFO);

    #ifdef MTR_MOD_PLUGIN
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_PrimitiveRectangleFilled_ca_f,
     "primitive");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_KeyboardPressed, "keyboard");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_MouseGetWheelRelative, "mouse");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_MousePress, "mouse");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_MouseRelease, "mouse");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_MouseGetXY, "mouse");
    MTR_FIND_FUNCTION(MTR_SpriteGetFramesCount, "Abstraction_sprite");
    MTR_FIND_FUNCTION(MTR_SpriteDrawScaled_f, "Abstraction_sprite");

    if (ok)
        MTR_LogWrite("Added dependent functions", 1, MTR_LMT_INFO);
    else {
        MTR_Notify("Functions not added", 1, MTR_LMT_FATAL);
        return false;
    }
    #endif

    mtrSceneKeeper = (mtrIndexkeeper_t *)MTR_IndexkeeperCreate(sceneDmSize,
     sceneReservedCount, sizeof(mtrScene_t));
    if (mtrSceneKeeper == NULL) {
        MTR_Notify("Unable to create indexkeeper structure for scenes", 1,
         MTR_LMT_FATAL);
        return false;
    } else
        MTR_LogWrite("Indexkeeper structure for scenes created", 1,
         MTR_LMT_INFO);

    MTR_LogWrite("Scene abstraction manager initialized", 0, MTR_LMT_INFO);
    mtrSceneInited = true;
    return true;
}

/*fa MTR_SceneCreate yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_SceneCreate(const char *name, int width,
 int height, uint32_t objectDmSize, uint32_t objectReservedCount,
 int tileLayersCount, int backgroundsCount, int camerasCount)
{
    int          i;
    uint32_t     freeIndex;
    mtrScene_t  *scene;
    bool         nullName = false;
    MTR_SCENE_CHECK_IF_NOT_INITED_WITH_LOG("Unable to create scene", 0U);

    if (name == NULL) {
        MTR_LogWrite("Scene name is not valid", 0, MTR_LMT_WARNING);
        nullName = true;
    }

    MTR_LogWrite_s("Creating scene", 0, MTR_LMT_INFO, name);

    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrSceneKeeper);
    MTR_LogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    scene = IK_GET_DATA(mtrScene_t *, mtrSceneKeeper, freeIndex);

    scene->objectKeeper = (mtrIndexkeeper_t *)MTR_IndexkeeperCreate(
     objectDmSize, objectReservedCount, sizeof(mtrObject_t));
    if (scene->objectKeeper == NULL) {
        MTR_Notify(
         "Unable to create indexkeeper structure for objects of scene", 1,
         MTR_LMT_FATAL);
        MTR_IndexkeeperFreeIndex(mtrSceneKeeper, freeIndex);
        return 0U;
    }
    MTR_LogWrite("Indexkeeper structure for objects of scene created", 1,
     MTR_LMT_INFO);

    scene->tileLayersCount = tileLayersCount;
    scene->tileLayer = malloc(sizeof(mtrTileLayer_t) * tileLayersCount);
    if (scene->tileLayer == NULL) {
        MTR_Notify("Unable to allocate memory for tile layers of scene", 1,
         MTR_LMT_FATAL);
        MTR_IndexkeeperDestroy(scene->objectKeeper);
        MTR_IndexkeeperFreeIndex(mtrSceneKeeper, freeIndex);
        return 0U;
    }
    for (i = 0; i < tileLayersCount; i++)
        scene->tileLayer[i].tile = NULL;

    scene->backgroundsCount = backgroundsCount;
    scene->background = malloc(sizeof(mtrBackground_t) * backgroundsCount);
    if (scene->background == NULL) {
        MTR_Notify("Unable to allocate memory for backgrounds of scene", 1,
         MTR_LMT_FATAL);
        MTR_IndexkeeperDestroy(scene->objectKeeper);
        free(scene->tileLayer);
        MTR_IndexkeeperFreeIndex(mtrSceneKeeper, freeIndex);
        return 0U;
    }
    for (i = 0; i < backgroundsCount; i++) {
        scene->background[i].animated = false;
        scene->background[i].sprite = 0U;
    }

    scene->camerasCount = camerasCount;
    scene->camera = malloc(sizeof(mtrCamera_t) * camerasCount);
    if (scene->camera == NULL) {
        MTR_Notify("Unable to allocate memory for backgrounds of scene", 1,
         MTR_LMT_FATAL);
        MTR_IndexkeeperDestroy(scene->objectKeeper);
        free(scene->tileLayer);
        free(scene->background);
        MTR_IndexkeeperFreeIndex(mtrSceneKeeper, freeIndex);
        return 0U;
    }
    for (i = 0; i < camerasCount; i++)
        scene->camera[i].enabled = false;

    if (!nullName) {
        scene->name = malloc(sizeof(char) * (strlen(name) + 1));
        if (scene->name == NULL)
            scene->name = mtrDefaultSceneName;
        else
            scene->name = strcpy(scene->name, name);
    } else {
        scene->name = mtrDefaultSceneName;
    }

    scene->width = width;
    scene->height = height;

    return freeIndex;
}

/*fa MTR_SceneCreateDefault yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_SceneCreateDefault(const char *name, int width,
 int height)
{
    int          i;
    uint32_t     freeIndex;
    mtrScene_t  *scene;
    bool         nullName = false;
    MTR_SCENE_CHECK_IF_NOT_INITED_WITH_LOG("Unable to create scene", 0U);

    if (name == NULL) {
        MTR_LogWrite("Scene name is not valid", 0, MTR_LMT_WARNING);
        nullName = true;
    }

    MTR_LogWrite_s("Creating scene", 0, MTR_LMT_INFO, name);

    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrSceneKeeper);
    MTR_LogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    scene = IK_GET_DATA(mtrScene_t *, mtrSceneKeeper, freeIndex);

    scene->objectKeeper = (mtrIndexkeeper_t *)MTR_IndexkeeperCreate(
     DEFAULT_OBJECT_DM_SIZE, DEFAULT_OBJECT_RESERVED_COUNT,
     sizeof(mtrObject_t));
    if (scene->objectKeeper == NULL) {
        MTR_Notify(
         "Unable to create indexkeeper structure for objects of scene", 1,
         MTR_LMT_FATAL);
        MTR_IndexkeeperFreeIndex(mtrSceneKeeper, freeIndex);
        return 0U;
    }
    MTR_LogWrite("Indexkeeper structure for objects of scene created", 1,
     MTR_LMT_INFO);

    scene->tileLayersCount = DEFAULT_TILE_LAYERS_COUNT;
    scene->tileLayer = malloc(
     sizeof(mtrTileLayer_t) * DEFAULT_TILE_LAYERS_COUNT);
    if (scene->tileLayer == NULL) {
        MTR_Notify("Unable to allocate memory for tile layers of scene", 1,
         MTR_LMT_FATAL);
        MTR_IndexkeeperDestroy(scene->objectKeeper);
        MTR_IndexkeeperFreeIndex(mtrSceneKeeper, freeIndex);
        return 0U;
    }
    for (i = 0; i < DEFAULT_TILE_LAYERS_COUNT; i++)
        scene->tileLayer[i].tile = NULL;

    scene->backgroundsCount = DEFAULT_BACKGROUNDS_COUNT;
    scene->background = malloc(
     sizeof(mtrBackground_t) * DEFAULT_BACKGROUNDS_COUNT);
    if (scene->background == NULL) {
        MTR_Notify("Unable to allocate memory for backgrounds of scene", 1,
         MTR_LMT_FATAL);
        MTR_IndexkeeperDestroy(scene->objectKeeper);
        free(scene->tileLayer);
        MTR_IndexkeeperFreeIndex(mtrSceneKeeper, freeIndex);
        return 0U;
    }
    for (i = 0; i < DEFAULT_BACKGROUNDS_COUNT; i++) {
        scene->background[i].animated = false;
        scene->background[i].sprite = 0U;
    }

    scene->camerasCount = DEFAULT_CAMERAS_COUNT;
    scene->camera = malloc(sizeof(mtrCamera_t) * DEFAULT_CAMERAS_COUNT);
    if (scene->camera == NULL) {
        MTR_Notify("Unable to allocate memory for backgrounds of scene", 1,
         MTR_LMT_FATAL);
        MTR_IndexkeeperDestroy(scene->objectKeeper);
        free(scene->tileLayer);
        free(scene->background);
        MTR_IndexkeeperFreeIndex(mtrSceneKeeper, freeIndex);
        return 0U;
    }
    for (i = 0; i < DEFAULT_CAMERAS_COUNT; i++)
        scene->camera[i].enabled = false;

    if (!nullName) {
        scene->name = malloc(sizeof(char) * (strlen(name) + 1));
        if (scene->name == NULL)
            scene->name = mtrDefaultSceneName;
        else
            scene->name = strcpy(scene->name, name);
    } else {
        scene->name = mtrDefaultSceneName;
    }

    scene->width = width;
    scene->height = height;

    return freeIndex;
}

/*fa MTR_SceneAddTileLayer yes */
MTR_DCLSPC bool MTR_CALL MTR_SceneAddTileLayer(uint32_t sceneNum,
 int tileLayerIndex, float tileWidth, float tileHeight, int rows, int cols,
 uint32_t missingTileColor)
{
    int i;
    int j;
    mtrScene_t *scene;
    MTR_SCENE_CHECK_IF_NOT_INITED(false);

    if (sceneNum == 0U)
        return false;

    scene = IK_GET_DATA(mtrScene_t *, mtrSceneKeeper, sceneNum);

    if (tileLayerIndex >= scene->tileLayersCount)
        return false;

    scene->tileLayer[tileLayerIndex].tileWidth = tileWidth;
    scene->tileLayer[tileLayerIndex].tileHeight = tileHeight;
    scene->tileLayer[tileLayerIndex].rows = rows;
    scene->tileLayer[tileLayerIndex].cols = cols;
    scene->tileLayer[tileLayerIndex].missingTileColor = missingTileColor;

    scene->tileLayer[tileLayerIndex].tile = malloc(sizeof(mtrTile_t *) * cols);
    if (scene->tileLayer[tileLayerIndex].tile == NULL)
        return false;

    for (i = 0; i < cols; i++) {
        scene->tileLayer[tileLayerIndex].tile[i] = malloc(
         sizeof(mtrTile_t) * rows);
        if (scene->tileLayer[tileLayerIndex].tile[i] == NULL) {
            for (j = 0; j < i; j++) {
                free(scene->tileLayer[tileLayerIndex].tile[j]);
            }
            free(scene->tileLayer[tileLayerIndex].tile);
            scene->tileLayer[tileLayerIndex].tile = NULL;
            return false;
        }
        for (j = 0; j < rows; j++) {
            scene->tileLayer[tileLayerIndex].tile[i][j].sprite = 0U;
        }
    }

    return true;
}

/*fa MTR_SceneTileLayerSetTile yes */
MTR_DCLSPC bool MTR_CALL MTR_SceneTileLayerSetTile(uint32_t sceneNum,
 int tileLayerIndex, int col, int row, uint32_t sprite, int clip)
{
    mtrScene_t *scene;
    MTR_SCENE_CHECK_IF_NOT_INITED(false);

    if (sceneNum == 0U)
        return false;

    scene = IK_GET_DATA(mtrScene_t *, mtrSceneKeeper, sceneNum);

    if (tileLayerIndex >= scene->tileLayersCount)
        return false;

    if ((col >= scene->tileLayer[tileLayerIndex].cols) ||
      (row >= scene->tileLayer[tileLayerIndex].rows))
        return false;

    if (sprite == 0U)
        return false;

    if (clip >= MTR_SpriteGetFramesCount(sprite))
        return false;

    scene->tileLayer[tileLayerIndex].tile[col][row].sprite = sprite;
    scene->tileLayer[tileLayerIndex].tile[col][row].clip = clip;

    return true;
}

/*fa MTR_SceneTileLayerRemoveTile yes */
MTR_DCLSPC bool MTR_CALL MTR_SceneTileLayerRemoveTile(uint32_t sceneNum,
 int tileLayerIndex, int col, int row)
{
    mtrScene_t *scene;
    MTR_SCENE_CHECK_IF_NOT_INITED(false);

    if (sceneNum == 0U)
        return false;

    scene = IK_GET_DATA(mtrScene_t *, mtrSceneKeeper, sceneNum);

    if (tileLayerIndex >= scene->tileLayersCount)
        return false;

    if ((col >= scene->tileLayer[tileLayerIndex].cols) ||
      (row >= scene->tileLayer[tileLayerIndex].rows))
        return false;

    scene->tileLayer[tileLayerIndex].tile[col][row].sprite = 0U;
    scene->tileLayer[tileLayerIndex].tile[col][row].clip = 0;

    return true;
}

/*fa MTR_SceneAddCamera yes */
MTR_DCLSPC bool MTR_CALL MTR_SceneAddCamera(uint32_t sceneNum, int cameraIndex,
 float sceneX, float sceneY, float sceneScale, float outputX, float outputY,
 float outputWidth, float outputHeight)
{
    mtrScene_t *scene;
    MTR_SCENE_CHECK_IF_NOT_INITED(false);

    if (sceneNum == 0U)
        return false;

    scene = IK_GET_DATA(mtrScene_t *, mtrSceneKeeper, sceneNum);

    if (cameraIndex >= scene->camerasCount)
        return false;

    scene->camera[cameraIndex].enabled = true;
    scene->camera[cameraIndex].sceneX = sceneX;
    scene->camera[cameraIndex].sceneY = sceneY;
    scene->camera[cameraIndex].sceneScale = sceneScale;
    scene->camera[cameraIndex].outputX = outputX;
    scene->camera[cameraIndex].outputY = outputY;
    scene->camera[cameraIndex].outputWidth = outputWidth;
    scene->camera[cameraIndex].outputHeight = outputHeight;
    scene->camera[cameraIndex].horBoundOutFactor = 0.0f;
    scene->camera[cameraIndex].verBoundOutFactor = 0.0f;
    scene->camera[cameraIndex].centerOnBigView = true;
    scene->camera[cameraIndex].cursorScrolling = false;
    scene->camera[cameraIndex].mouseWheelScaling = false;
    scene->camera[cameraIndex].minScale = 0.125f;
    scene->camera[cameraIndex].maxScale = 1.0f;
    scene->camera[cameraIndex].mouseDragging = false;
    scene->camera[cameraIndex].mouseDragButton = MTR_MOUSE_MIDDLE;
    scene->camera[cameraIndex].arrowsScrolling = false;
    scene->camera[cameraIndex].keyScrollLeft = MTR_KEY_LEFT;
    scene->camera[cameraIndex].keyScrollRight = MTR_KEY_RIGHT;
    scene->camera[cameraIndex].keyScrollUp = MTR_KEY_UP;
    scene->camera[cameraIndex].keyScrollDown = MTR_KEY_DOWN;
    scene->camera[cameraIndex].scrollingSpeed = 1.0f;

    return true;
}

/*fa MTR_SceneCameraSetSizes yes */
MTR_DCLSPC bool MTR_CALL MTR_SceneCameraSetSizes(uint32_t sceneNum,
 int cameraIndex, float sceneX, float sceneY, float sceneScale, float outputX,
 float outputY, float outputWidth, float outputHeight)
{
    mtrScene_t *scene;
    MTR_SCENE_CHECK_IF_NOT_INITED(false);

    if (sceneNum == 0U)
        return false;

    scene = IK_GET_DATA(mtrScene_t *, mtrSceneKeeper, sceneNum);

    if (cameraIndex >= scene->camerasCount)
        return false;

    scene->camera[cameraIndex].sceneX = sceneX;
    scene->camera[cameraIndex].sceneY = sceneY;
    scene->camera[cameraIndex].sceneScale = sceneScale;
    scene->camera[cameraIndex].outputX = outputX;
    scene->camera[cameraIndex].outputY = outputY;
    scene->camera[cameraIndex].outputWidth = outputWidth;
    scene->camera[cameraIndex].outputHeight = outputHeight;

    return true;
}

/*fa MTR_SceneCameraSetBoundOut yes */
MTR_DCLSPC bool MTR_CALL MTR_SceneCameraSetBoundOut(uint32_t sceneNum,
 int cameraIndex, float horBoundOutFactor, float verBoundOutFactor,
 bool centerOnBigView)
{
    mtrScene_t *scene;
    MTR_SCENE_CHECK_IF_NOT_INITED(false);

    if (sceneNum == 0U)
        return false;

    scene = IK_GET_DATA(mtrScene_t *, mtrSceneKeeper, sceneNum);

    if (cameraIndex >= scene->camerasCount)
        return false;

    scene->camera[cameraIndex].horBoundOutFactor = horBoundOutFactor;
    scene->camera[cameraIndex].verBoundOutFactor = verBoundOutFactor;
    scene->camera[cameraIndex].centerOnBigView = centerOnBigView;

    return true;
}

/*fa MTR_SceneCameraSetCursorScrolling yes */
MTR_DCLSPC bool MTR_CALL MTR_SceneCameraSetCursorScrolling(uint32_t sceneNum,
 int cameraIndex, bool cursorScrolling)
{
    mtrScene_t *scene;
    MTR_SCENE_CHECK_IF_NOT_INITED(false);

    if (sceneNum == 0U)
        return false;

    scene = IK_GET_DATA(mtrScene_t *, mtrSceneKeeper, sceneNum);

    if (cameraIndex >= scene->camerasCount)
        return false;

    scene->camera[cameraIndex].cursorScrolling = cursorScrolling;

    return true;
}

/*fa MTR_SceneCameraSetMouseWheelScaling yes */
MTR_DCLSPC bool MTR_CALL MTR_SceneCameraSetMouseWheelScaling(uint32_t sceneNum,
 int cameraIndex, bool mouseWheelScaling)
{
    mtrScene_t *scene;
    MTR_SCENE_CHECK_IF_NOT_INITED(false);

    if (sceneNum == 0U)
        return false;

    scene = IK_GET_DATA(mtrScene_t *, mtrSceneKeeper, sceneNum);

    if (cameraIndex >= scene->camerasCount)
        return false;

    scene->camera[cameraIndex].mouseWheelScaling = mouseWheelScaling;

    return true;
}

/*fa MTR_SceneCameraSetScaleLimits yes */
MTR_DCLSPC bool MTR_CALL MTR_SceneCameraSetScaleLimits(uint32_t sceneNum,
 int cameraIndex, float minScale, float maxScale)
{
    mtrScene_t *scene;
    MTR_SCENE_CHECK_IF_NOT_INITED(false);

    if (sceneNum == 0U)
        return false;

    scene = IK_GET_DATA(mtrScene_t *, mtrSceneKeeper, sceneNum);

    if (cameraIndex >= scene->camerasCount)
        return false;

    scene->camera[cameraIndex].minScale = minScale;
    scene->camera[cameraIndex].maxScale = maxScale;

    return true;
}

/*fa MTR_SceneCameraSetMouseDragging yes */
MTR_DCLSPC bool MTR_CALL MTR_SceneCameraSetMouseDragging(uint32_t sceneNum,
 int cameraIndex, bool mouseDragging)
{
    mtrScene_t *scene;
    MTR_SCENE_CHECK_IF_NOT_INITED(false);

    if (sceneNum == 0U)
        return false;

    scene = IK_GET_DATA(mtrScene_t *, mtrSceneKeeper, sceneNum);

    if (cameraIndex >= scene->camerasCount)
        return false;

    scene->camera[cameraIndex].mouseDragging = mouseDragging;

    return true;
}

/*fa MTR_SceneCameraSetMouseDragButton yes */
MTR_DCLSPC bool MTR_CALL MTR_SceneCameraSetMouseDragButton(uint32_t sceneNum,
 int cameraIndex, int mouseDragButton)
{
    mtrScene_t *scene;
    MTR_SCENE_CHECK_IF_NOT_INITED(false);

    if (sceneNum == 0U)
        return false;

    scene = IK_GET_DATA(mtrScene_t *, mtrSceneKeeper, sceneNum);

    if (cameraIndex >= scene->camerasCount)
        return false;

    scene->camera[cameraIndex].mouseDragButton = mouseDragButton;

    return true;
}

/*fa MTR_SceneCameraSetScrollingKeys yes */
MTR_DCLSPC bool MTR_CALL MTR_SceneCameraSetScrollingKeys(uint32_t sceneNum,
 int cameraIndex, int keyScrollLeft, int keyScrollRight, int keyScrollUp,
 int keyScrollDown)
{
    mtrScene_t *scene;
    MTR_SCENE_CHECK_IF_NOT_INITED(false);

    if (sceneNum == 0U)
        return false;

    scene = IK_GET_DATA(mtrScene_t *, mtrSceneKeeper, sceneNum);

    if (cameraIndex >= scene->camerasCount)
        return false;

    scene->camera[cameraIndex].keyScrollLeft = keyScrollLeft;
    scene->camera[cameraIndex].keyScrollRight = keyScrollRight;
    scene->camera[cameraIndex].keyScrollUp = keyScrollUp;
    scene->camera[cameraIndex].keyScrollDown = keyScrollDown;

    return true;
}

/*fa MTR_SceneCameraSetScrollingSpeed yes */
MTR_DCLSPC bool MTR_CALL MTR_SceneCameraSetScrollingSpeed(uint32_t sceneNum,
 int cameraIndex, float scrollingSpeed)
{
    mtrScene_t *scene;
    MTR_SCENE_CHECK_IF_NOT_INITED(false);

    if (sceneNum == 0U)
        return false;

    scene = IK_GET_DATA(mtrScene_t *, mtrSceneKeeper, sceneNum);

    if (cameraIndex >= scene->camerasCount)
        return false;

    scene->camera[cameraIndex].scrollingSpeed = scrollingSpeed;

    return true;
}

/*fa MTR_SceneDisableCamera yes */
MTR_DCLSPC bool MTR_CALL MTR_SceneDisableCamera(uint32_t sceneNum,
 int cameraIndex)
{
    mtrScene_t *scene;
    MTR_SCENE_CHECK_IF_NOT_INITED(false);

    if (sceneNum == 0U)
        return false;

    scene = IK_GET_DATA(mtrScene_t *, mtrSceneKeeper, sceneNum);

    if (cameraIndex >= scene->camerasCount)
        return false;

    scene->camera[cameraIndex].enabled = false;

    return true;
}

MTR_DCLSPC void MTR_CALL MTR_SceneUpdateCamera(uint32_t sceneNum, int cameraNum)
{
    mtrScene_t *scene;
    mtrCamera_t camera;

    scene = IK_GET_DATA(mtrScene_t *, mtrSceneKeeper, sceneNum);

    camera = scene->camera[cameraNum];
    if (camera.cursorScrolling) {
        if (mtrSceneMouseX <= camera.outputX)
            camera.sceneX -= camera.scrollingSpeed;
        else if (mtrSceneMouseX >= camera.outputX + camera.outputWidth - 1.0f)
            camera.sceneX += camera.scrollingSpeed;
        if (mtrSceneMouseY <= camera.outputY)
            camera.sceneY -= camera.scrollingSpeed;
        else if (mtrSceneMouseY >= camera.outputY + camera.outputHeight - 1.0f)
            camera.sceneY += camera.scrollingSpeed;

        if (camera.sceneX < 0.0f - camera.outputWidth * camera.sceneScale * (1.0f + camera.horBoundOutFactor)) {
            if (camera.sceneX > scene->width + camera.outputWidth * camera.sceneScale * (1.0f + camera.horBoundOutFactor))
                camera.sceneX = (scene->width - camera.outputWidth * camera.sceneScale) / 2.0f;
            else
                camera.sceneX = 0.0f - camera.outputWidth * camera.sceneScale * (1.0f + camera.horBoundOutFactor);
        } else {
            if (camera.sceneX > scene->width + camera.outputWidth * camera.sceneScale * (1.0f + camera.horBoundOutFactor))
                camera.sceneX = scene->width + camera.outputWidth * camera.sceneScale * (1.0f + camera.horBoundOutFactor);
        }

        if (camera.sceneY < 0.0f - camera.outputHeight * camera.sceneScale * (1.0f + camera.verBoundOutFactor)) {
            if (camera.sceneY > scene->height + camera.outputHeight * camera.sceneScale * (1.0f + camera.verBoundOutFactor))
                camera.sceneY = (scene->height - camera.outputHeight * camera.sceneScale) / 2.0f;
            else
                camera.sceneY = 0.0f - camera.outputHeight * camera.sceneScale * (1.0f + camera.verBoundOutFactor);
        } else {
            if (camera.sceneY > scene->height + camera.outputHeight * camera.sceneScale * (1.0f + camera.verBoundOutFactor))
                camera.sceneY = scene->height + camera.outputHeight * camera.sceneScale * (1.0f + camera.verBoundOutFactor);
        }
    }
}

/*fa MTR_SceneUpdate yes */
MTR_DCLSPC bool MTR_CALL MTR_SceneUpdate(uint32_t sceneNum)
{
    int i;
    mtrScene_t *scene;
    MTR_SCENE_CHECK_IF_NOT_INITED(false);

    if (sceneNum == 0U)
        return false;

    scene = IK_GET_DATA(mtrScene_t *, mtrSceneKeeper, sceneNum);

    MTR_MouseGetXY(&mtrSceneMouseX, &mtrSceneMouseY);

    for (i = 0; i < scene->camerasCount; i++) {
        if (scene->camera[i].enabled)
            MTR_SceneUpdateCamera(sceneNum, i);
    }

    return true;
}

MTR_DCLSPC void MTR_CALL MTR_SceneDrawTileLayer(uint32_t sceneNum,
 int cameraNum, int tileLayerNum)
{
    mtrScene_t    *scene;
    mtrCamera_t    camera;
    mtrTileLayer_t tileLayer;
    int            i;
    int            j;
    int            tileFirstCol;
    int            tileLastCol;
    int            tileFirstRow;
    int            tileLastRow;
    float          tileWidth;
    float          tileHeight;

    scene = IK_GET_DATA(mtrScene_t *, mtrSceneKeeper, sceneNum);

    camera = scene->camera[cameraNum];
    tileLayer = scene->tileLayer[tileLayerNum];

    tileWidth = tileLayer.tileWidth;
    tileHeight = tileLayer.tileHeight;
    tileFirstCol = camera.sceneX / tileWidth;
    tileLastCol = (camera.sceneX + (camera.outputWidth - 1.0f) * camera.sceneScale) / tileWidth;
    tileFirstRow = camera.sceneY / tileHeight;
    tileLastRow = (camera.sceneY + (camera.outputHeight - 1.0f) * camera.sceneScale) / tileHeight;

    for (i = tileFirstCol; i <= tileLastCol; i++) {
        for (j = tileFirstRow; j <= tileLastRow; j++) {
            float tileOutputX = (i * tileWidth - camera.sceneX) * camera.sceneScale;
            float tileOutputY = (j * tileHeight - camera.sceneY) * camera.sceneScale;
            if ((i >= 0) && (i <= tileLayer.cols - 1) && (j >= 0) &&
             (j <= tileLayer.rows - 1)) {
                if (tileLayer.tile[i][j].sprite != 0U) {
                    MTR_SpriteDrawScaled_f(tileLayer.tile[i][j].sprite,
                     tileLayer.tile[i][j].clip, tileOutputX, tileOutputY,
                     camera.sceneScale, camera.sceneScale);
                } else {
                    MTR_PrimitiveRectangleFilled_ca_f(tileOutputX, tileOutputY,
                     tileOutputX + (tileWidth - 1.0f) * camera.sceneScale,
                     tileOutputY + (tileHeight - 1.0f) * camera.sceneScale,
                     tileLayer.missingTileColor);
                }
            } else {
                MTR_PrimitiveRectangleFilled_ca_f(tileOutputX, tileOutputY,
                 tileOutputX + (tileWidth - 1.0f) * camera.sceneScale,
                 tileOutputY + (tileHeight - 1.0f) * camera.sceneScale,
                 tileLayer.missingTileColor);
            }
        }
    }

    tileFirstCol = camera.sceneX;
}

MTR_DCLSPC void MTR_CALL MTR_SceneDrawCamera(uint32_t sceneNum, int cameraNum)
{
    mtrScene_t *scene;
    int         i;

    scene = IK_GET_DATA(mtrScene_t *, mtrSceneKeeper, sceneNum);

    for (i = 0; i < scene->tileLayersCount; i++) {
        if (scene->tileLayer[i].tile != NULL)
            MTR_SceneDrawTileLayer(sceneNum, cameraNum, i);
    }
}

/*fa MTR_SceneDraw yes */
MTR_DCLSPC bool MTR_CALL MTR_SceneDraw(uint32_t sceneNum)
{
    int i;
    mtrScene_t *scene;
    MTR_SCENE_CHECK_IF_NOT_INITED(false);

    if (sceneNum == 0U)
        return false;

    scene = IK_GET_DATA(mtrScene_t *, mtrSceneKeeper, sceneNum);

    for (i = 0; i < scene->camerasCount; i++) {
        if (scene->camera[i].enabled)
            MTR_SceneDrawCamera(sceneNum, i);
    }

    return true;
}
