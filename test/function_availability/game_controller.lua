-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(GameControllerInit, "mtrGameControllerInit",
 GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerQuit, "mtrGameControllerQuit",
 GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerRefresh, "mtrGameControllerRefresh",
 GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerButtonPress, "mtrGameControllerButtonPress",
 GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerButtonRelease,
 "mtrGameControllerButtonRelease", GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerButtonPressed,
 "mtrGameControllerButtonPressed", GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerGetAxis, "mtrGameControllerGetAxis",
 GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerGetAxis_f, "mtrGameControllerGetAxis_f",
 GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerGetAxisDelta,
 "mtrGameControllerGetAxisDelta", GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerGetAxisDelta_f,
 "mtrGameControllerGetAxisDelta_f", GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerGetTrackballDeltaX,
 "mtrGameControllerGetTrackballDeltaX", GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerGetTrackballDeltaY,
 "mtrGameControllerGetTrackballDeltaY", GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerGetTrackballDeltaXY,
 "mtrGameControllerGetTrackballDeltaXY", GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerGetPovHat, "mtrGameControllerGetPovHat",
 GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerGetButtonsCount,
 "mtrGameControllerGetButtonsCount", GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerGetAxesCount,
 "mtrGameControllerGetAxesCount", GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerGetTrackballsCount,
 "mtrGameControllerGetTrackballsCount", GameControllerFunctionSupported);
fa.FunctionSupported(GameControllerGetPowHatsCount,
 "mtrGameControllerGetPowHatsCount", GameControllerFunctionSupported);
