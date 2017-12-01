-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(TextureInit, "MTR_TextureInit", TextureFunctionSupported);
fa.FunctionSupported(TextureBeginTarget, "MTR_TextureBeginTarget",
 TextureFunctionSupported);
fa.FunctionSupported(TextureEndTarget, "MTR_TextureEndTarget",
 TextureFunctionSupported);
fa.FunctionSupported(TextureGetWidth, "MTR_TextureGetWidth",
 TextureFunctionSupported);
fa.FunctionSupported(TextureGetHeight, "MTR_TextureGetHeight",
 TextureFunctionSupported);
fa.FunctionSupported(TextureGetSizes, "MTR_TextureGetSizes",
 TextureFunctionSupported);
fa.FunctionSupported(TextureCreate, "MTR_TextureCreate",
 TextureFunctionSupported);
fa.FunctionSupported(TextureLoad, "MTR_TextureLoad", TextureFunctionSupported);
fa.FunctionSupported(TextureCopy, "MTR_TextureCopy", TextureFunctionSupported);
fa.FunctionSupported(TextureSave, "MTR_TextureSave", TextureFunctionSupported);
fa.FunctionSupported(TextureFree, "MTR_TextureFree", TextureFunctionSupported);
fa.FunctionSupported(TextureSetModulation_c, "MTR_TextureSetModulation_c",
 TextureFunctionSupported);
fa.FunctionSupported(TextureSetModulation_ca, "MTR_TextureSetModulation_ca",
 TextureFunctionSupported);
fa.FunctionSupported(TextureSetModulation_rgb, "MTR_TextureSetModulation_rgb",
 TextureFunctionSupported);
fa.FunctionSupported(TextureSetModulation_rgba, "MTR_TextureSetModulation_rgba",
 TextureFunctionSupported);
fa.FunctionSupported(TextureSetModulationAlpha, "MTR_TextureSetModulationAlpha",
 TextureFunctionSupported);
fa.FunctionSupported(TextureSetModulationAlpha_f,
 "MTR_TextureSetModulationAlpha_f", TextureFunctionSupported);
fa.FunctionSupported(TextureBlit_f, "MTR_TextureBlit_f",
 TextureFunctionSupported);
fa.FunctionSupported(TextureBlitSized_f, "MTR_TextureBlitSized_f",
 TextureFunctionSupported);
fa.FunctionSupported(TextureBlitScaled_f, "MTR_TextureBlitScaled_f",
 TextureFunctionSupported);
fa.FunctionSupported(TextureBlitAngled_f, "MTR_TextureBlitAngled_f",
 TextureFunctionSupported);
fa.FunctionSupported(TextureBlitFlipped_f, "MTR_TextureBlitFlipped_f",
 TextureFunctionSupported);
fa.FunctionSupported(TextureBlitGeneral_f, "MTR_TextureBlitGeneral_f",
 TextureFunctionSupported);
fa.FunctionSupported(TextureBlitRegion_f, "MTR_TextureBlitRegion_f",
 TextureFunctionSupported);
fa.FunctionSupported(TextureBlitRegionSized_f, "MTR_TextureBlitRegionSized_f",
 TextureFunctionSupported);
fa.FunctionSupported(TextureBlitRegionScaled_f, "MTR_TextureBlitRegionScaled_f",
 TextureFunctionSupported);
fa.FunctionSupported(TextureBlitRegionAngled_f, "MTR_TextureBlitRegionAngled_f",
 TextureFunctionSupported);
fa.FunctionSupported(TextureBlitRegionFlipped_f,
 "MTR_TextureBlitRegionFlipped_f", TextureFunctionSupported);
fa.FunctionSupported(TextureBlitRegionGeneral_f,
 "MTR_TextureBlitRegionGeneral_f", TextureFunctionSupported);
fa.FunctionSupported(TextureReceivePixels, "MTR_TextureReceivePixels",
 TextureFunctionSupported);
fa.FunctionSupported(TextureReceivePixelsToPos, "MTR_TextureReceivePixelsToPos",
 TextureFunctionSupported);
