-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(ScreenInit, "mtrScreenInit", ScreenFunctionSupported);
fa.FunctionSupported(ScreenQuit, "mtrScreenQuit", ScreenFunctionSupported);
fa.FunctionSupported(ScreenFlip, "mtrScreenFlip", ScreenFunctionSupported);
fa.FunctionSupported(ScreenGetSizes, "mtrScreenGetSizes",
 ScreenFunctionSupported);
fa.FunctionSupported(ScreenGetWidth, "mtrScreenGetWidth",
 ScreenFunctionSupported);
fa.FunctionSupported(ScreenGetHeight, "mtrScreenGetHeight",
 ScreenFunctionSupported);
fa.FunctionSupported(ScreenXed, "mtrScreenXed", ScreenFunctionSupported);
