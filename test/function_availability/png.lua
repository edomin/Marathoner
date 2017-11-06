-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(PngInit, "MTR_PngInit", PngFunctionSupported);
fa.FunctionSupported(PngLoadSimple, "MTR_PngLoadSimple", PngFunctionSupported);
fa.FunctionSupported(PngSaveSimple, "MTR_PngSaveSimple", PngFunctionSupported);
