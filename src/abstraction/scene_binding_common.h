#ifndef MTR_ABSTRACTION_SCENE_BINDING_COMMON_H
#define MTR_ABSTRACTION_SCENE_BINDING_COMMON_H

MTR_FUNC(int, MTR_SceneFunctionSupported, const char *);
MTR_FUNC(bool, MTR_SceneInit, uint32_t, uint32_t);
MTR_FUNC(uint32_t, MTR_SceneCreate, const char *, int, int, uint32_t, uint32_t,
 int, int, int);
MTR_FUNC(uint32_t, MTR_SceneCreateDefault, const char *, int, int);
MTR_FUNC(bool, MTR_SceneSetOutSceneColor, uint32_t, uint32_t);
MTR_FUNC(bool, MTR_SceneAddTileLayer, uint32_t, int, float, float, int, int,
 uint32_t);
MTR_FUNC(bool, MTR_SceneTileLayerSetTile, uint32_t, int, int, int, uint32_t,
 int);
MTR_FUNC(bool, MTR_SceneTileLayerRemoveTile, uint32_t, int, int, int);
MTR_FUNC(float, MTR_SceneTileLayerGetTileWidth, uint32_t, int);
MTR_FUNC(float, MTR_SceneTileLayerGetTileHeight, uint32_t, int);
MTR_FUNC(bool, MTR_SceneAddCamera, uint32_t, int, float, float, float, float,
 float, float, float);
MTR_FUNC(bool, MTR_SceneCameraSetSizes, uint32_t, int, float, float, float,
 float, float, float, float);
MTR_FUNC(bool, MTR_SceneCameraSetBoundOut, uint32_t, int, float, float, bool);
MTR_FUNC(bool, MTR_SceneCameraSetCursorScrolling, uint32_t, int, bool);
MTR_FUNC(bool, MTR_SceneCameraSetMouseWheelScaling, uint32_t, int, bool);
MTR_FUNC(bool, MTR_SceneCameraSetScaleLimits, uint32_t, int, float, float);
MTR_FUNC(bool, MTR_SceneCameraSetMouseDragging, uint32_t, int, bool);
MTR_FUNC(bool, MTR_SceneCameraSetMouseDragButton, uint32_t, int, int);
MTR_FUNC(bool, MTR_SceneCameraSetScrollingKeys, uint32_t, int, int, int, int,
 int);
MTR_FUNC(bool, MTR_SceneCameraSetScrollingSpeed, uint32_t, int, float);
MTR_FUNC(void, MTR_SceneCameraGetScenePos, uint32_t, int, float *, float *);
MTR_FUNC(float, MTR_SceneCameraGetSceneX, uint32_t, int);
MTR_FUNC(float, MTR_SceneCameraGetSceneY, uint32_t, int);
MTR_FUNC(float, MTR_SceneCameraGetSceneScale, uint32_t, int);
MTR_FUNC(float, MTR_SceneViewxToX, uint32_t, int, float);
MTR_FUNC(float, MTR_SceneViewyToY, uint32_t, int, float);
MTR_FUNC(int, MTR_SceneViewxToTileLayerCol, uint32_t, int, int, float);
MTR_FUNC(int, MTR_SceneViewyToTileLayerRow, uint32_t, int, int, float);
MTR_FUNC(float, MTR_SceneTileLayerColToViewx, uint32_t, int, int, int);
MTR_FUNC(float, MTR_SceneTileLayerRowToViewy, uint32_t, int, int, int);
MTR_FUNC(bool, MTR_SceneDisableCamera, uint32_t, int);
MTR_FUNC(bool, MTR_SceneUpdate, uint32_t);
MTR_FUNC(bool, MTR_SceneDraw, uint32_t);

#endif
