#ifndef MTR_ABSTRACTION_SCENE_BINDING_COMMON_C
#define MTR_ABSTRACTION_SCENE_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(MTR_SF_SceneFunctionSupported, MTR_SceneFunctionSupported)
MTR_SCRIPT_FUNC_B_U32t2(MTR_SF_SceneInit, MTR_SceneInit)
MTR_SCRIPT_FUNC_U32t_S1I2U32t2I3(MTR_SF_SceneCreate, MTR_SceneCreate)
MTR_SCRIPT_FUNC_U32t_S1I2(MTR_SF_SceneCreateDefault, MTR_SceneCreateDefault)
MTR_SCRIPT_FUNC_B_U32t2(MTR_SF_SceneSetOutSceneColor, MTR_SceneSetOutSceneColor)
MTR_SCRIPT_FUNC_B_U32t1I1F2I2U32t1(MTR_SF_SceneAddTileLayer,
 MTR_SceneAddTileLayer)
MTR_SCRIPT_FUNC_B_U32t1I3U32t1I1(MTR_SF_SceneTileLayerSetTile,
 MTR_SceneTileLayerSetTile)
MTR_SCRIPT_FUNC_B_U32t1I3(MTR_SF_SceneTileLayerRemoveTile,
 MTR_SceneTileLayerRemoveTile)
MTR_SCRIPT_FUNC_F_U32t1I1(MTR_SF_SceneTileLayerGetTileWidth,
 MTR_SceneTileLayerGetTileWidth)
MTR_SCRIPT_FUNC_F_U32t1I1(MTR_SF_SceneTileLayerGetTileHeight,
 MTR_SceneTileLayerGetTileHeight)
MTR_SCRIPT_FUNC_B_U32t1I1F7(MTR_SF_SceneAddCamera, MTR_SceneAddCamera)
MTR_SCRIPT_FUNC_B_U32t1I1F7(MTR_SF_SceneCameraSetSizes, MTR_SceneCameraSetSizes)
MTR_SCRIPT_FUNC_B_U32t1I1F2B1(MTR_SF_SceneCameraSetBoundOut,
 MTR_SceneCameraSetBoundOut)
MTR_SCRIPT_FUNC_B_U32t1I1B1(MTR_SF_SceneCameraSetCursorScrolling,
 MTR_SceneCameraSetCursorScrolling)
MTR_SCRIPT_FUNC_B_U32t1I1B1(MTR_SF_SceneCameraSetMouseWheelScaling,
 MTR_SceneCameraSetMouseWheelScaling)
MTR_SCRIPT_FUNC_B_U32t1I1F2(MTR_SF_SceneCameraSetScaleLimits,
 MTR_SceneCameraSetScaleLimits)
MTR_SCRIPT_FUNC_B_U32t1I1B1(MTR_SF_SceneCameraSetMouseDragging,
 MTR_SceneCameraSetMouseDragging)
MTR_SCRIPT_FUNC_B_U32t1I2(MTR_SF_SceneCameraSetMouseDragButton,
 MTR_SceneCameraSetMouseDragButton)
MTR_SCRIPT_FUNC_B_U32t1I5(MTR_SF_SceneCameraSetScrollingKeys,
 MTR_SceneCameraSetScrollingKeys)
MTR_SCRIPT_FUNC_B_U32t1I1F1(MTR_SF_SceneCameraSetScrollingSpeed,
 MTR_SceneCameraSetScrollingSpeed)

#ifdef lua_h
MTR_SCRIPT_FUNC(MTR_SF_SceneCameraGetScenePos)
{
    uint32_t sceneNum;
    int      cameraNum;
    float    sceneX;
    float    sceneY;
    MTR_SF_GET_UINT32(sceneNum, 1);
    MTR_SF_GET_INT(cameraNum, 2);
    MTR_SF_GET_SINGLE(sceneX, 3);
    MTR_SF_GET_SINGLE(sceneY, 4);
    MTR_SceneCameraGetScenePos(sceneNum, cameraNum, &sceneX, &sceneY);
    MTR_SF_PUSH_INT(sceneX);
    MTR_SF_PUSH_INT(sceneY);
    return 2;
}
#endif

MTR_SCRIPT_FUNC_F_U32t1I1(MTR_SF_SceneCameraGetSceneX, MTR_SceneCameraGetSceneX)
MTR_SCRIPT_FUNC_F_U32t1I1(MTR_SF_SceneCameraGetSceneY, MTR_SceneCameraGetSceneY)
MTR_SCRIPT_FUNC_F_U32t1I1(MTR_SF_SceneCameraGetSceneScale,
 MTR_SceneCameraGetSceneScale)
MTR_SCRIPT_FUNC_F_U32t1I1F1(MTR_SF_SceneViewxToX, MTR_SceneViewxToX)
MTR_SCRIPT_FUNC_F_U32t1I1F1(MTR_SF_SceneViewyToY, MTR_SceneViewyToY)
MTR_SCRIPT_FUNC_I_U32t1I2F1(MTR_SF_SceneViewxToTileLayerCol,
 MTR_SceneViewxToTileLayerCol)
MTR_SCRIPT_FUNC_I_U32t1I2F1(MTR_SF_SceneViewyToTileLayerRow,
 MTR_SceneViewyToTileLayerRow)
MTR_SCRIPT_FUNC_F_U32t1I3(MTR_SF_SceneTileLayerColToViewx,
 MTR_SceneTileLayerColToViewx)
MTR_SCRIPT_FUNC_F_U32t1I3(MTR_SF_SceneTileLayerRowToViewy,
 MTR_SceneTileLayerRowToViewy)
MTR_SCRIPT_FUNC_B_U32t1I1(MTR_SF_SceneDisableCamera, MTR_SceneDisableCamera)
MTR_SCRIPT_FUNC_B_U32t1(MTR_SF_SceneUpdate, MTR_SceneUpdate)
MTR_SCRIPT_FUNC_B_U32t1(MTR_SF_SceneDraw, MTR_SceneDraw)

void MTR_ScriptsRegisterAll(void)
{
    #ifdef MTR_MOD_PLUGIN
    mtrVm = MTR_ScriptsGetVm();
    #endif

    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneFunctionSupported);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneInit);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneCreate);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneCreateDefault);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneSetOutSceneColor);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneAddTileLayer);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneTileLayerSetTile);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneTileLayerRemoveTile);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneTileLayerGetTileWidth);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneTileLayerGetTileHeight);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneAddCamera);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneCameraSetSizes);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneCameraSetBoundOut);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene",
     SceneCameraSetCursorScrolling);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene",
     SceneCameraSetMouseWheelScaling);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneCameraSetScaleLimits);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneCameraSetMouseDragging);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene",
     SceneCameraSetMouseDragButton);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneCameraSetScrollingKeys);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene",
     SceneCameraSetScrollingSpeed);
    #ifdef lua_h
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneCameraGetScenePos);
    #endif
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneCameraGetSceneX);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneCameraGetSceneY);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneCameraGetSceneScale);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneViewxToX);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneViewyToY);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneViewxToTileLayerCol);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneViewyToTileLayerRow);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneTileLayerColToViewx);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneTileLayerRowToViewy);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneDisableCamera);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneUpdate);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_scene", SceneDraw);
}

#endif
