-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(FontInit, "mtrFontInit", FontFunctionSupported);
fa.FunctionSupported(FontLoadTtf, "mtrFontLoadTtf", FontFunctionSupported);
fa.FunctionSupported(FontFree, "mtrFontFree", FontFunctionSupported);
fa.FunctionSupported(FontSetTtfStyle, "mtrFontSetTtfStyle",
 FontFunctionSupported);
fa.FunctionSupported(FontSetTtfOutline, "mtrFontSetTtfOutline",
 FontFunctionSupported);
fa.FunctionSupported(FontRenderTtfString, "mtrFontRenderTtfString",
 FontFunctionSupported);
fa.FunctionSupported(FontCreateMbf, "mtrFontCreateMbf", FontFunctionSupported);
fa.FunctionSupported(FontAddMbfTextureTable, "mtrFontAddMbfTextureTable",
 FontFunctionSupported);
fa.FunctionSupported(FontDrawMbfString_f, "mtrFontDrawMbfString_f",
 FontFunctionSupported);
fa.FunctionSupported(FontGetHeight, "mtrFontGetHeight", FontFunctionSupported);
fa.FunctionSupported(FontGetStringWidth, "mtrFontGetStringWidth",
 FontFunctionSupported);
fa.FunctionSupported(FontGetName, "mtrFontGetName", FontFunctionSupported);
