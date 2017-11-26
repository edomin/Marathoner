-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(TtfInit, "MTR_TtfInit", TtfFunctionSupported);
fa.FunctionSupported(TtfQuit, "MTR_TtfQuit", TtfFunctionSupported);
fa.FunctionSupported(TtfLoad, "MTR_TtfLoad", TtfFunctionSupported);
fa.FunctionSupported(TtfFree, "MTR_TtfFree", TtfFunctionSupported);
fa.FunctionSupported(TtfGetFontHeight, "MTR_TtfGetFontHeight",
 TtfFunctionSupported);
fa.FunctionSupported(TtfSetSizes, "MTR_TtfSetSizes", TtfFunctionSupported);
fa.FunctionSupported(TtfGetStringSizes, "MTR_TtfGetStringSizes",
 TtfFunctionSupported);
fa.FunctionSupported(TtfGetStringWidth, "MTR_TtfGetStringWidth",
 TtfFunctionSupported);
fa.FunctionSupported(TtfSetFontStyle, "MTR_TtfSetFontStyle",
fa.FunctionSupported(TtfGetGlyphWidth, "MTR_TtfGetGlyphWidth",
 TtfFunctionSupported);
fa.FunctionSupported(TtfRenderGlyph, "MTR_TtfRenderGlyph",
 TtfFunctionSupported);
fa.FunctionSupported(TtfSetFontOutline, "MTR_TtfSetFontOutline",
 TtfFunctionSupported);
