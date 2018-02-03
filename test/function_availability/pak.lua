-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(PakInit, "MTR_PakInit", PakFunctionSupported);
fa.FunctionSupported(PakMount, "MTR_PakMount", PakFunctionSupported);
fa.FunctionSupported(PakUnmount, "MTR_PakUnmount", PakFunctionSupported);
fa.FunctionSupported(PakQuit, "MTR_PakQuit", PakFunctionSupported);
fa.FunctionSupported(PakGetFopen, "MTR_PakGetFopen", PakFunctionSupported);
fa.FunctionSupported(PakGetFclose, "MTR_PakGetFclose", PakFunctionSupported);
fa.FunctionSupported(PakGetFeof, "MTR_PakGetFeof", PakFunctionSupported);
fa.FunctionSupported(PakGetFtell, "MTR_PakGetFtell", PakFunctionSupported);
fa.FunctionSupported(PakGetFseek, "MTR_PakGetFseek", PakFunctionSupported);
fa.FunctionSupported(PakGetFread, "MTR_PakGetFread", PakFunctionSupported);
fa.FunctionSupported(PakGetFwrite, "MTR_PakGetFwrite", PakFunctionSupported);
