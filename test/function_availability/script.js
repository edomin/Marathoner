// Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
const fa = require("test/common/function_availability");

fa.FunctionSupported(ScriptsGetAutorunPath,
 "MTR_ScriptsGetAutorunPath", ScriptsFunctionSupported);
fa.FunctionSupported(ScriptsRegisterVariable_b,
 "MTR_ScriptsRegisterVariable_b", ScriptsFunctionSupported);
fa.FunctionSupported(ScriptsRegisterVariable_i,
 "MTR_ScriptsRegisterVariable_i", ScriptsFunctionSupported);
fa.FunctionSupported(ScriptsRegisterVariable_u,
 "MTR_ScriptsRegisterVariable_u", ScriptsFunctionSupported);
fa.FunctionSupported(ScriptsRegisterVariable_f,
 "MTR_ScriptsRegisterVariable_f", ScriptsFunctionSupported);
fa.FunctionSupported(ScriptsRegisterVariable_d,
 "MTR_ScriptsRegisterVariable_d", ScriptsFunctionSupported);
fa.FunctionSupported(ScriptsRegisterVariable_s,
 "MTR_ScriptsRegisterVariable_s", ScriptsFunctionSupported);
