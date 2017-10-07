// Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.nut");

fa.FunctionSupported(RegisterStringVariable, "mtrScriptsRegisterStringVariable",
 ScriptsFunctionSupported);
fa.FunctionSupported(RegisterNumericVariable,
 "mtrScriptsRegisterNumericVariable", ScriptsFunctionSupported);