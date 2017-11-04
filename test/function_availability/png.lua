-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(PngInit, "MTR_PngInit", PngFunctionSupported);
fa.FunctionSupported(PngLoadFast, "MTR_PngLoadFast", PngFunctionSupported);
fa.FunctionSupported(PngSaveFast, "MTR_PngSaveFast", PngFunctionSupported);
