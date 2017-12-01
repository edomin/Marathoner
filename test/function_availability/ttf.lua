-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(TtfInit, "MTR_TtfInit", TtfFunctionSupported);
fa.FunctionSupported(TtfQuit, "MTR_TtfQuit", TtfFunctionSupported);
fa.FunctionSupported(TtfLoad, "MTR_TtfLoad", TtfFunctionSupported);
fa.FunctionSupported(TtfFree, "MTR_TtfFree", TtfFunctionSupported);
fa.FunctionSupported(TtfGetWidth, "MTR_TtfGetWidth", TtfFunctionSupported);
fa.FunctionSupported(TtfGetHeight, "MTR_TtfGetHeight", TtfFunctionSupported);
fa.FunctionSupported(TtfGetSizes, "MTR_TtfGetSizes", TtfFunctionSupported);
fa.FunctionSupported(TtfSetSizes, "MTR_TtfSetSizes", TtfFunctionSupported);
fa.FunctionSupported(TtfGetStyle, "MTR_TtfGetStyle", TtfFunctionSupported);
fa.FunctionSupported(TtfGetOutline, "MTR_TtfGetOutline", TtfFunctionSupported);
fa.FunctionSupported(TtfSetStyle, "MTR_TtfSetStyle", TtfFunctionSupported);
fa.FunctionSupported(TtfSetOutline, "MTR_TtfSetOutline", TtfFunctionSupported);
fa.FunctionSupported(TtfGetGlyphSizes, "MTR_TtfGetGlyphSizes",
 TtfFunctionSupported);
fa.FunctionSupported(TtfGetGlyphWidth, "MTR_TtfGetGlyphWidth",
 TtfFunctionSupported);
fa.FunctionSupported(TtfGetGlyphHeight, "MTR_TtfGetGlyphHeight",
 TtfFunctionSupported);
fa.FunctionSupported(TtfRenderGlyph, "MTR_TtfRenderGlyph",
 TtfFunctionSupported);
