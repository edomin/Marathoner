-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(TimerInit, "MTR_TimerInit", TimerFunctionSupported);
fa.FunctionSupported(TimerStart, "MTR_TimerStart", TimerFunctionSupported);
fa.FunctionSupported(TimerDelay, "MTR_TimerDelay", TimerFunctionSupported);
fa.FunctionSupported(TimerDelayForFPS, "MTR_TimerDelayForFPS",
 TimerFunctionSupported);
fa.FunctionSupported(TimerDelayForFPS_f, "MTR_TimerDelayForFPS_f",
 TimerFunctionSupported);
