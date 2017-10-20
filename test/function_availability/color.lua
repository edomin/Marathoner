-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(ColorAssembleRGB, "MTR_ColorAssembleRGB",
 ColorFunctionSupported);
fa.FunctionSupported(ColorAssembleRGBA, "MTR_ColorAssembleRGBA",
 ColorFunctionSupported);
fa.FunctionSupported(ColorSplitRGB, "MTR_ColorSplitRGB",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRGBGetR, "MTR_ColorRGBGetR", ColorFunctionSupported);
fa.FunctionSupported(ColorRGBGetG, "MTR_ColorRGBGetG", ColorFunctionSupported);
fa.FunctionSupported(ColorRGBGetB, "MTR_ColorRGBGetB", ColorFunctionSupported);
fa.FunctionSupported(ColorRGBSetR, "MTR_ColorRGBSetR", ColorFunctionSupported);
fa.FunctionSupported(ColorRGBSetG, "MTR_ColorRGBSetG", ColorFunctionSupported);
fa.FunctionSupported(ColorRGBSetB, "MTR_ColorRGBSetB", ColorFunctionSupported);
fa.FunctionSupported(ColorSplitRGBA, "MTR_ColorSplitRGBA",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRGBAGetR, "MTR_ColorRGBAGetR",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRGBAGetG, "MTR_ColorRGBAGetG",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRGBAGetB, "MTR_ColorRGBAGetB",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRGBAGetA, "MTR_ColorRGBAGetA",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRGBASetR, "MTR_ColorRGBASetR",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRGBASetG, "MTR_ColorRGBASetG",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRGBASetB, "MTR_ColorRGBASetB",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRGBASetA, "MTR_ColorRGBASetA",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRGBtoRGBA, "MTR_ColorRGBtoRGBA",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRGBAtoRGB, "MTR_ColorRGBAtoRGB",
 ColorFunctionSupported);
