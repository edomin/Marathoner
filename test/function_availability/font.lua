-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(FontInit, "MTR_FontInit", FontFunctionSupported);
fa.FunctionSupported(FontCreate, "MTR_FontCreate", FontFunctionSupported);
fa.FunctionSupported(FontAddAtlas, "MTR_FontAddAtlas", FontFunctionSupported);
fa.FunctionSupported(FontCacheTtf, "MTR_FontCacheTtf", FontFunctionSupported);
fa.FunctionSupported(FontFree, "MTR_FontFree", FontFunctionSupported);
fa.FunctionSupported(FontSetStyle, "MTR_FontSetStyle", FontFunctionSupported);
fa.FunctionSupported(FontSetOutline, "MTR_FontSetOutline",
 FontFunctionSupported);
fa.FunctionSupported(FontDrawString_f, "MTR_FontDrawString_f",
 FontFunctionSupported);
fa.FunctionSupported(FontGetHeight, "MTR_FontGetHeight", FontFunctionSupported);
fa.FunctionSupported(FontGetStringWidth, "MTR_FontGetStringWidth",
 FontFunctionSupported);
fa.FunctionSupported(FontGetName, "MTR_FontGetName", FontFunctionSupported);
