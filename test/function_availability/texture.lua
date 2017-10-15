-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(TextureInit, "mtrTextureInit", TextureFunctionSupported);
fa.FunctionSupported(TextureBeginTarget, "mtrTextureBeginTarget",
 TextureFunctionSupported);
fa.FunctionSupported(TextureEndTarget, "mtrTextureEndTarget",
 TextureFunctionSupported);
fa.FunctionSupported(TextureGetWidth, "mtrTextureGetWidth",
 TextureFunctionSupported);
fa.FunctionSupported(TextureGetHeight, "mtrTextureGetHeight",
 TextureFunctionSupported);
fa.FunctionSupported(TextureGetSizes, "mtrTextureGetSizes",
 TextureFunctionSupported);
fa.FunctionSupported(TextureCreate, "mtrTextureCreate",
 TextureFunctionSupported);
fa.FunctionSupported(TextureLoad, "mtrTextureLoad", TextureFunctionSupported);
fa.FunctionSupported(TextureCopy, "mtrTextureCopy", TextureFunctionSupported);
fa.FunctionSupported(TextureSave, "mtrTextureSave", TextureFunctionSupported);
fa.FunctionSupported(TextureFree, "mtrTextureFree", TextureFunctionSupported);
fa.FunctionSupported(TextureSetModulation_c, "mtrTextureSetModulation_c",
 TextureFunctionSupported);
fa.FunctionSupported(TextureSetModulation_ca, "mtrTextureSetModulation_ca",
 TextureFunctionSupported);
fa.FunctionSupported(TextureSetModulation_rgb, "mtrTextureSetModulation_rgb",
 TextureFunctionSupported);
fa.FunctionSupported(TextureSetModulation_rgba, "mtrTextureSetModulation_rgba",
 TextureFunctionSupported);
fa.FunctionSupported(TextureSetModulationAlpha, "mtrTextureSetModulationAlpha",
 TextureFunctionSupported);
fa.FunctionSupported(TextureSetModulationAlpha_f,
 "mtrTextureSetModulationAlpha_f", TextureFunctionSupported);
fa.FunctionSupported(TextureBlit_f, "mtrTextureBlit_f",
 TextureFunctionSupported);
fa.FunctionSupported(TextureBlitSized_f, "mtrTextureBlitSized_f",
 TextureFunctionSupported);
fa.FunctionSupported(TextureBlitScaled_f, "mtrTextureBlitScaled_f",
 TextureFunctionSupported);
fa.FunctionSupported(TextureBlitAngled_f, "mtrTextureBlitAngled_f",
 TextureFunctionSupported);
fa.FunctionSupported(TextureBlitFlipped_f, "mtrTextureBlitFlipped_f",
 TextureFunctionSupported);
fa.FunctionSupported(TextureBlitGeneral_f, "mtrTextureBlitGeneral_f",
 TextureFunctionSupported);
fa.FunctionSupported(TextureBlitRegion_f, "mtrTextureBlitRegion_f",
 TextureFunctionSupported);
fa.FunctionSupported(TextureBlitRegionSized_f, "mtrTextureBlitRegionSized_f",
 TextureFunctionSupported);
fa.FunctionSupported(TextureBlitRegionScaled_f, "mtrTextureBlitRegionScaled_f",
 TextureFunctionSupported);
fa.FunctionSupported(TextureBlitRegionAngled_f, "mtrTextureBlitRegionAngled_f",
 TextureFunctionSupported);
fa.FunctionSupported(TextureBlitRegionFlipped_f,
 "mtrTextureBlitRegionFlipped_f", TextureFunctionSupported);
fa.FunctionSupported(TextureBlitRegionGeneral_f,
 "mtrTextureBlitRegionGeneral_f", TextureFunctionSupported);
