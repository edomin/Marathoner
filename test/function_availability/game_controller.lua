-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(GameControllerInit, "MTR_GameControllerInit",
 GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerQuit, "MTR_GameControllerQuit",
 GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerRefresh, "MTR_GameControllerRefresh",
 GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerButtonPress, "MTR_GameControllerButtonPress",
 GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerButtonRelease,
 "MTR_GameControllerButtonRelease", GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerButtonPressed,
 "MTR_GameControllerButtonPressed", GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerGetAxis, "MTR_GameControllerGetAxis",
 GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerGetAxis_f, "MTR_GameControllerGetAxis_f",
 GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerGetAxisDelta,
 "MTR_GameControllerGetAxisDelta", GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerGetAxisDelta_f,
 "MTR_GameControllerGetAxisDelta_f", GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerGetTrackballDeltaX,
 "MTR_GameControllerGetTrackballDeltaX", GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerGetTrackballDeltaY,
 "MTR_GameControllerGetTrackballDeltaY", GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerGetTrackballDeltaXY,
 "MTR_GameControllerGetTrackballDeltaXY", GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerGetPovHat, "MTR_GameControllerGetPovHat",
 GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerGetButtonsCount,
 "MTR_GameControllerGetButtonsCount", GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerGetAxesCount,
 "MTR_GameControllerGetAxesCount", GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerGetTrackballsCount,
 "MTR_GameControllerGetTrackballsCount", GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerGetPowHatsCount,
 "MTR_GameControllerGetPowHatsCount", GameControllerFunctionSupported);
