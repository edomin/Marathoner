-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(SpriteInit, "mtrSpriteInit", SpriteFunctionSupported);
fa.FunctionSupported(SpriteLoad, "mtrSpriteLoad", SpriteFunctionSupported);
fa.FunctionSupported(SpriteLoadSimple, "mtrSpriteLoadSimple",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteFree, "mtrSpriteFree", SpriteFunctionSupported);
fa.FunctionSupported(SpriteSetModulation_c, "mtrSpriteSetModulation_c",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteSetModulation_ca, "mtrSpriteSetModulation_ca",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteSetModulation_rgb, "mtrSpriteSetModulation_rgb",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteSetModulation_rgba, "mtrSpriteSetModulation_rgba",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteSetModulationAlpha, "mtrSpriteSetModulationAlpha",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteSetModulationAlpha_f,
 "mtrSpriteSetModulationAlpha_f", SpriteFunctionSupported);
fa.FunctionSupported(SpriteDraw_f, "mtrSpriteDraw_f", SpriteFunctionSupported);
fa.FunctionSupported(SpriteDrawScaled_f, "mtrSpriteDrawScaled_f",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteDrawAngled_f, "mtrSpriteDrawAngled_f",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteDrawFlipped_f, "mtrSpriteDrawFlipped_f",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteDrawGeneral_f, "mtrSpriteDrawGeneral_f",
 SpriteFunctionSupported);
