-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(TtfInit, "mtrTtfInit", TtfFunctionSupported);
fa.FunctionSupported(TtfQuit, "mtrTtfQuit", TtfFunctionSupported);
fa.FunctionSupported(TtfLoad, "mtrTtfLoad", TtfFunctionSupported);
fa.FunctionSupported(TtfFree, "mtrTtfFree", TtfFunctionSupported);
fa.FunctionSupported(TtfGetFontHeight, "mtrTtfGetFontHeight",
 TtfFunctionSupported);
fa.FunctionSupported(TtfGetStringSizes, "mtrTtfGetStringSizes",
 TtfFunctionSupported);
fa.FunctionSupported(TtfGetStringWidth, "mtrTtfGetStringWidth",
 TtfFunctionSupported);
fa.FunctionSupported(TtfSetFontStyle, "mtrTtfSetFontStyle",
 TtfFunctionSupported);
fa.FunctionSupported(TtfSetFontOutline, "mtrTtfSetFontOutline",
 TtfFunctionSupported);
