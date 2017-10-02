-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(TimerInit, "mtrTimerInit", TimerFunctionSupported);
fa.FunctionSupported(TimerStart, "mtrTimerStart", TimerFunctionSupported);
fa.FunctionSupported(TimerDelay, "mtrTimerDelay", TimerFunctionSupported);
fa.FunctionSupported(TimerDelayForFPS, "mtrTimerDelayForFPS",
 TimerFunctionSupported);
fa.FunctionSupported(TimerDelayForFPS_f, "mtrTimerDelayForFPS_f",
 TimerFunctionSupported);
