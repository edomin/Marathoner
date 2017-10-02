-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(ColorAssembleRGB, "mtrColorAssembleRGB",
 ColorFunctionSupported);
fa.FunctionSupported(ColorAssembleRGBA, "mtrColorAssembleRGBA",
 ColorFunctionSupported);
fa.FunctionSupported(ColorSplitRGB, "mtrColorSplitRGB", ColorFunctionSupported);
fa.FunctionSupported(ColorRGBGetR, "mtrColorRGBGetR", ColorFunctionSupported);
fa.FunctionSupported(ColorRGBGetG, "mtrColorRGBGetG", ColorFunctionSupported);
fa.FunctionSupported(ColorRGBGetB, "mtrColorRGBGetB", ColorFunctionSupported);
fa.FunctionSupported(ColorRGBSetR, "mtrColorRGBSetR", ColorFunctionSupported);
fa.FunctionSupported(ColorRGBSetG, "mtrColorRGBSetG", ColorFunctionSupported);
fa.FunctionSupported(ColorRGBSetB, "mtrColorRGBSetB", ColorFunctionSupported);
fa.FunctionSupported(ColorSplitRGBA, "mtrColorSplitRGBA",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRGBAGetR, "mtrColorRGBAGetR", ColorFunctionSupported);
fa.FunctionSupported(ColorRGBAGetG, "mtrColorRGBAGetG", ColorFunctionSupported);
fa.FunctionSupported(ColorRGBAGetB, "mtrColorRGBAGetB", ColorFunctionSupported);
fa.FunctionSupported(ColorRGBAGetA, "mtrColorRGBAGetA", ColorFunctionSupported);
fa.FunctionSupported(ColorRGBASetR, "mtrColorRGBASetR", ColorFunctionSupported);
fa.FunctionSupported(ColorRGBASetG, "mtrColorRGBASetG", ColorFunctionSupported);
fa.FunctionSupported(ColorRGBASetB, "mtrColorRGBASetB", ColorFunctionSupported);
fa.FunctionSupported(ColorRGBASetA, "mtrColorRGBASetA", ColorFunctionSupported);
fa.FunctionSupported(ColorRGBtoRGBA, "mtrColorRGBtoRGBA",
 ColorFunctionSupported);
fa.FunctionSupported(ColorRGBAtoRGB, "mtrColorRGBAtoRGB",
 ColorFunctionSupported);
