-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(KeyboardInit, "mtrKeyboardInit",
 KeyboardFunctionSupported);
fa.FunctionSupported(KeyboardRefresh, "mtrKeyboardRefresh",
 KeyboardFunctionSupported);
fa.FunctionSupported(KeyboardPress, "mtrKeyboardPress",
 KeyboardFunctionSupported);
fa.FunctionSupported(KeyboardRelease, "mtrKeyboardRelease",
 KeyboardFunctionSupported);
fa.FunctionSupported(KeyboardPressed, "mtrKeyboardPressed",
 KeyboardFunctionSupported);
fa.FunctionSupported(KeyboardInputChar, "mtrKeyboardInputChar",
 KeyboardFunctionSupported);
