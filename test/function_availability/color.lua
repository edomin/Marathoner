-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(ColorRgbAssemble, "MTR_ColorRgbAssemble",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRgbaAssemble, "MTR_ColorRgbaAssemble",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRgbSplit, "MTR_ColorRgbSplit",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRgbGetRed, "MTR_ColorRgbGetRed",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRgbGetGreen, "MTR_ColorRgbGetGreen",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRgbGetBlue, "MTR_ColorRgbGetBlue",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRgbSetRed, "MTR_ColorRgbSetRed",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRgbSetGreen, "MTR_ColorRgbSetGreen",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRgbSetBlue, "MTR_ColorRgbSetBlue",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRgbaSplit, "MTR_ColorRgbaSplit",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRgbaGetRed, "MTR_ColorRgbaGetRed",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRgbaGetGreen, "MTR_ColorRgbaGetGreen",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRgbaGetBlue, "MTR_ColorRgbaGetBlue",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRgbaGetAlpha, "MTR_ColorRgbaGetAlpha",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRgbaSetRed, "MTR_ColorRgbaSetRed",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRgbaSetGreen, "MTR_ColorRgbaSetGreen",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRgbaSetBlue, "MTR_ColorRgbaSetBlue",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRgbaSetAlpha, "MTR_ColorRgbaSetAlpha",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRgbToRgba, "MTR_ColorRgbToRgba",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRgbaToRgb, "MTR_ColorRgbaToRgb",
 ColorFunctionSupported);
