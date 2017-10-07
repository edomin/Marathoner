// Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
const fa = require("test/common/function_availability");

fa.FunctionSupported(RegisterStringVariable, "mtrScriptsRegisterStringVariable",
 ScriptsFunctionSupported);
fa.FunctionSupported(RegisterNumericVariable,
 "mtrScriptsRegisterNumericVariable", ScriptsFunctionSupported);
