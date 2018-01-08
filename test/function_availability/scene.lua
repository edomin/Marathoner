-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(SceneInit, "MTR_SceneInit", SceneFunctionSupported);
fa.FunctionSupported(SceneCreate, "MTR_SceneCreate", SceneFunctionSupported);
fa.FunctionSupported(SceneCreateDefault, "MTR_SceneCreateDefault",
 SceneFunctionSupported);
fa.FunctionSupported(SceneAddTileLayer, "MTR_SceneAddTileLayer",
 SceneFunctionSupported);
fa.FunctionSupported(SceneTileLayerSetTile, "MTR_SceneTileLayerSetTile",
 SceneFunctionSupported);
fa.FunctionSupported(SceneTileLayerRemoveTile, "MTR_SceneTileLayerRemoveTile",
 SceneFunctionSupported);
fa.FunctionSupported(SceneAddCamera, "MTR_SceneAddCamera",
 SceneFunctionSupported);
fa.FunctionSupported(SceneCameraSetSizes, "MTR_SceneCameraSetSizes",
 SceneFunctionSupported);
fa.FunctionSupported(SceneCameraSetBoundOut, "MTR_SceneCameraSetBoundOut",
 SceneFunctionSupported);
fa.FunctionSupported(SceneCameraSetCursorScrolling,
 "MTR_SceneCameraSetCursorScrolling", SceneFunctionSupported);
fa.FunctionSupported(SceneCameraSetMouseWheelScaling,
 "MTR_SceneCameraSetMouseWheelScaling", SceneFunctionSupported);
fa.FunctionSupported(SceneCameraSetScaleLimits, "MTR_SceneCameraSetScaleLimits",
 SceneFunctionSupported);
fa.FunctionSupported(SceneCameraSetMouseDragging,
 "MTR_SceneCameraSetMouseDragging", SceneFunctionSupported);
fa.FunctionSupported(SceneCameraSetMouseDragButton,
 "MTR_SceneCameraSetMouseDragButton", SceneFunctionSupported);
fa.FunctionSupported(SceneCameraSetScrollingKeys,
 "MTR_SceneCameraSetScrollingKeys", SceneFunctionSupported);
fa.FunctionSupported(SceneCameraSetScrollingSpeed,
 "MTR_SceneCameraSetScrollingSpeed", SceneFunctionSupported);
fa.FunctionSupported(SceneDisableCamera, "MTR_SceneDisableCamera",
 SceneFunctionSupported);
fa.FunctionSupported(SceneUpdate, "MTR_SceneUpdate", SceneFunctionSupported);
fa.FunctionSupported(SceneDraw, "MTR_SceneDraw", SceneFunctionSupported);
