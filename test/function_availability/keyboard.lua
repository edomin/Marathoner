-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(KeyboardInit, "MTR_KeyboardInit",
 KeyboardFunctionSupported);
fa.FunctionSupported(KeyboardRefresh, "MTR_KeyboardRefresh",
 KeyboardFunctionSupported);
fa.FunctionSupported(KeyboardPress, "MTR_KeyboardPress",
 KeyboardFunctionSupported);
fa.FunctionSupported(KeyboardRelease, "MTR_KeyboardRelease",
 KeyboardFunctionSupported);
fa.FunctionSupported(KeyboardPressed, "MTR_KeyboardPressed",
 KeyboardFunctionSupported);
fa.FunctionSupported(KeyboardInputChar, "MTR_KeyboardInputChar",
 KeyboardFunctionSupported);
