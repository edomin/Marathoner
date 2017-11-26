-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(TtfInit, "MTR_TtfInit", TtfFunctionSupported);
fa.FunctionSupported(TtfQuit, "MTR_TtfQuit", TtfFunctionSupported);
fa.FunctionSupported(TtfLoad, "MTR_TtfLoad", TtfFunctionSupported);
fa.FunctionSupported(TtfFree, "MTR_TtfFree", TtfFunctionSupported);
fa.FunctionSupported(TtfSetSizes, "MTR_TtfSetSizes", TtfFunctionSupported);
fa.FunctionSupported(TtfGetHeight, "MTR_TtfGetHeight", TtfFunctionSupported);
fa.FunctionSupported(TtfGetStringSizes, "MTR_TtfGetStringSizes",
 TtfFunctionSupported);
fa.FunctionSupported(TtfGetStringWidth, "MTR_TtfGetStringWidth",
 TtfFunctionSupported);
fa.FunctionSupported(TtfGetGlyphWidth, "MTR_TtfGetGlyphWidth",
 TtfFunctionSupported);
fa.FunctionSupported(TtfSetStyle, "MTR_TtfSetStyle", TtfFunctionSupported);
fa.FunctionSupported(TtfSetOutline, "MTR_TtfSetOutline", TtfFunctionSupported);
fa.FunctionSupported(TtfRenderGlyph, "MTR_TtfRenderGlyph",
 TtfFunctionSupported);
fa.FunctionSupported(TtfRenderString, "MTR_TtfRenderString",
 TtfFunctionSupported);
