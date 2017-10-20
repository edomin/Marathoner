-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(ScreenInit, "MTR_ScreenInit", ScreenFunctionSupported);
fa.FunctionSupported(ScreenQuit, "MTR_ScreenQuit", ScreenFunctionSupported);
fa.FunctionSupported(ScreenFlip, "MTR_ScreenFlip", ScreenFunctionSupported);
fa.FunctionSupported(ScreenGetSizes, "MTR_ScreenGetSizes",
 ScreenFunctionSupported);
fa.FunctionSupported(ScreenGetWidth, "MTR_ScreenGetWidth",
 ScreenFunctionSupported);
fa.FunctionSupported(ScreenGetHeight, "MTR_ScreenGetHeight",
 ScreenFunctionSupported);
fa.FunctionSupported(ScreenXed, "MTR_ScreenXed", ScreenFunctionSupported);
