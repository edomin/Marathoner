-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(SpriteInit, "MTR_SpriteInit", SpriteFunctionSupported);
fa.FunctionSupported(SpriteLoad, "MTR_SpriteLoad", SpriteFunctionSupported);
fa.FunctionSupported(SpriteLoadSimple, "MTR_SpriteLoadSimple",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteLoadAtlas, "MTR_SpriteLoadAtlas",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteCreateFromTexture, "MTR_SpriteCreateFromTexture",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteSetAtlasFrame, "MTR_SpriteSetAtlasFrame",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteGetFrameSizes, "MTR_SpriteGetFrameSizes",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteGetFrameWidth, "MTR_SpriteGetFrameWidth",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteGetFrameHeight, "MTR_SpriteGetFrameHeight",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteGetFrameCoords, "MTR_SpriteGetFrameCoords",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteGetFrameX, "MTR_SpriteGetFrameX",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteGetFrameY, "MTR_SpriteGetFrameY",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteGetFrameAnchors, "MTR_SpriteGetFrameAnchors",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteGetFrameAnchorX, "MTR_SpriteGetFrameAnchorX",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteGetFrameAnchorY, "MTR_SpriteGetFrameAnchorY",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteGetTexture, "MTR_SpriteGetTexture",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteFree, "MTR_SpriteFree", SpriteFunctionSupported);
fa.FunctionSupported(SpriteDetachTexture, "MTR_SpriteDetachTexture",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteSetModulation_c, "MTR_SpriteSetModulation_c",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteSetModulation_ca, "MTR_SpriteSetModulation_ca",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteSetModulation_rgb, "MTR_SpriteSetModulation_rgb",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteSetModulation_rgba, "MTR_SpriteSetModulation_rgba",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteSetModulationAlpha, "MTR_SpriteSetModulationAlpha",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteSetModulationAlpha_f,
 "MTR_SpriteSetModulationAlpha_f", SpriteFunctionSupported);
fa.FunctionSupported(SpriteDraw_f, "MTR_SpriteDraw_f", SpriteFunctionSupported);
fa.FunctionSupported(SpriteDrawSized_f, "MTR_SpriteDrawSized_f",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteDrawScaled_f, "MTR_SpriteDrawScaled_f",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteDrawAngled_f, "MTR_SpriteDrawAngled_f",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteDrawFlipped_f, "MTR_SpriteDrawFlipped_f",
 SpriteFunctionSupported);
fa.FunctionSupported(SpriteDrawGeneral_f, "MTR_SpriteDrawGeneral_f",
 SpriteFunctionSupported);
