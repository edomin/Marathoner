// Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
const fa = require("test/common/function_availability");

fa.FunctionSupported(RegisterStringVariable,
 "MTR_ScriptsRegisterStringVariable", ScriptsFunctionSupported);
fa.FunctionSupported(RegisterNumericVariable,
 "MTR_ScriptsRegisterNumericVariable", ScriptsFunctionSupported);
