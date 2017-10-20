-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(FontInit, "MTR_FontInit", FontFunctionSupported);
fa.FunctionSupported(FontLoadTtf, "MTR_FontLoadTtf", FontFunctionSupported);
fa.FunctionSupported(FontFree, "MTR_FontFree", FontFunctionSupported);
fa.FunctionSupported(FontSetTtfStyle, "MTR_FontSetTtfStyle",
 FontFunctionSupported);
fa.FunctionSupported(FontSetTtfOutline, "MTR_FontSetTtfOutline",
 FontFunctionSupported);
fa.FunctionSupported(FontRenderTtfString, "MTR_FontRenderTtfString",
 FontFunctionSupported);
fa.FunctionSupported(FontCreateMbf, "MTR_FontCreateMbf", FontFunctionSupported);
fa.FunctionSupported(FontAddMbfTextureTable, "MTR_FontAddMbfTextureTable",
 FontFunctionSupported);
fa.FunctionSupported(FontDrawMbfString_f, "MTR_FontDrawMbfString_f",
 FontFunctionSupported);
fa.FunctionSupported(FontGetHeight, "MTR_FontGetHeight", FontFunctionSupported);
fa.FunctionSupported(FontGetStringWidth, "MTR_FontGetStringWidth",
 FontFunctionSupported);
fa.FunctionSupported(FontGetName, "MTR_FontGetName", FontFunctionSupported);
