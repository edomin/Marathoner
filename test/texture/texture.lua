local i;
local x;
local helicopter;

-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

ScreenInit(640, 480, false, "Texture Test");
TimerInit();
PrimitiveInit();
TextureInit(IKDM_SMALL, 32);
MouseInit();
helicopter = TextureLoad("test/media/helicopter.png");
helicopterAnim = TextureLoad("test/media/helicopter_anim.png");
local w = TextureGetWidth(helicopter);
local h = TextureGetHeight(helicopter);
FileWriteLineFast("test/output.txt", "width: " .. w , FM_APPEND);
FileWriteLineFast("test/output.txt", "height: " .. h , FM_APPEND);
w, h = TextureGetSizes(helicopter);
FileWriteLineFast("test/output.txt", "width: " .. w , FM_APPEND);
FileWriteLineFast("test/output.txt", "height: " .. h , FM_APPEND);

-- Prepare to watch
for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    PrimitiveFill_c(0x000000);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

-- Texture
x = 32;
for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    TextureBlit_f(helicopter, x, 128);
    PrimitiveRectangle_c_f(x, 128, x + 96, 160, 0xFF0000);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

x = 32;
for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    TextureBlitSized_f(helicopter, x, 128, (162 - x) / 162 * 96,
     (162 - x) / 162 * 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

x = 32;
for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    TextureBlitScaled_f(helicopter, x, 128, i / 30, i / 30);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

x = 32;
for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    TextureBlitAngled_f(helicopter, x, 128, -x, 48, 16);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

x = 32;
for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    TextureBlitFlipped_f(helicopter, x, 128, FLIP_NONE);
    PrimitiveRectangle_c_f(x, 128, x + 96, 160, 0xFF0000);
    TextureBlitFlipped_f(helicopter, x, 160, FLIP_HORIZONTAL);
    PrimitiveRectangle_c_f(x, 160, x + 96, 192, 0xFF0000);
    TextureBlitFlipped_f(helicopter, x, 192, FLIP_VERTICAL);
    PrimitiveRectangle_c_f(x, 192, x + 96, 224, 0xFF0000);
    TextureBlitFlipped_f(helicopter, x, 224, FLIP_BOTH);
    PrimitiveRectangle_c_f(x, 224, x + 96, 256, 0xFF0000);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

x = 32;
for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    TextureBlitGeneral_f(helicopter, x, 128, i / 30, i / 30, -x, 48, 16,
     FLIP_NONE);
    TextureBlitGeneral_f(helicopter, x, 160, i / 30, i / 30, -x, 48, 16,
     FLIP_HORIZONTAL);
    TextureBlitGeneral_f(helicopter, x, 192, i / 30, i / 30, -x, 48, 16,
     FLIP_VERTICAL);
    TextureBlitGeneral_f(helicopter, x, 244, i / 30, i / 30, -x, 48, 16,
     FLIP_BOTH);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

-- Region
x = 32;
for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    TextureBlitRegion_f(helicopterAnim, x, 128, (Floor_f(i / 4) % 8) * 96, 0,
     96, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

x = 32;
for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    TextureBlitRegionSized_f(helicopterAnim, x, 128, (162 - x) / 162 * 96,
     (162 - x) / 162 * 32, (Floor_f(i / 4) % 8) * 96, 0, 96, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

x = 32;
for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    TextureBlitRegionScaled_f(helicopterAnim, x, 128, i / 30, i / 30,
     (Floor_f(i / 4) % 8) * 96, 0, 96, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

x = 32;
for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    TextureBlitRegionAngled_f(helicopterAnim, x, 128,
     (Floor_f(i / 4) % 8) * 96, 0, 96, 32, -x, 48, 16);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

x = 32;
for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    TextureBlitRegionFlipped_f(helicopterAnim, x, 128,
     (Floor_f(i / 4) % 8) * 96, 0, 96, 32, FLIP_NONE);
    TextureBlitRegionFlipped_f(helicopterAnim, x, 160,
     (Floor_f(i / 4) % 8) * 96, 0, 96, 32, FLIP_HORIZONTAL);
    TextureBlitRegionFlipped_f(helicopterAnim, x, 192,
     (Floor_f(i / 4) % 8) * 96, 0, 96, 32, FLIP_VERTICAL);
    TextureBlitRegionFlipped_f(helicopterAnim, x, 224,
     (Floor_f(i / 4) % 8) * 96, 0, 96, 32, FLIP_BOTH);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

x = 32;
for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    TextureBlitRegionGeneral_f(helicopterAnim, x, 128, i / 30, i / 30,
     (Floor_f(i / 4) % 8) * 96, 0, 96, 32, -x, 48, 16, FLIP_NONE);
    TextureBlitRegionGeneral_f(helicopterAnim, x, 160, i / 30, i / 30,
     (Floor_f(i / 4) % 8) * 96, 0, 96, 32, -x, 48, 16, FLIP_HORIZONTAL);
    TextureBlitRegionGeneral_f(helicopterAnim, x, 192, i / 30, i / 30,
     (Floor_f(i / 4) % 8) * 96, 0, 96, 32, -x, 48, 16, FLIP_VERTICAL);
    TextureBlitRegionGeneral_f(helicopterAnim, x, 244, i / 30, i / 30,
     (Floor_f(i / 4) % 8) * 96, 0, 96, 32, -x, 48, 16, FLIP_BOTH);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

-- Texture with modulation
x = 32;
for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    TextureSetModulation_c(helicopter, 0x010101 * i * 4);
    TextureBlit_f(helicopter, x, 128);
    ScreenFlip();
    TimerDelayForFPS(30);
end;
TextureSetModulation_c(helicopter, 0xFFFFFF);

x = 32;
for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    TextureSetModulation_ca(helicopter, 0x01010101 * i * 4);
    TextureBlit_f(helicopter, x, 128);
    ScreenFlip();
    TimerDelayForFPS(30);
end;
TextureSetModulation_ca(helicopter, 0xFFFFFFFF);

x = 32;
for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    TextureSetModulation_rgb(helicopter, 0x01 * i * 4, 0x01 * i * 4,
     0x01 * i * 4);
    TextureBlit_f(helicopter, x, 128);
    ScreenFlip();
    TimerDelayForFPS(30);
end;
TextureSetModulation_rgb(helicopter, 0xFF, 0xFF, 0xFF);

x = 32;
for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    TextureSetModulation_rgba(helicopter, 0x01 * i * 4, 0x01 * i * 4,
     0x01 * i * 4, 0x01 * i * 4);
    TextureBlit_f(helicopter, x, 128);
    ScreenFlip();
    TimerDelayForFPS(30);
end;
TextureSetModulation_rgba(helicopter, 0xFF, 0xFF, 0xFF, 0xFF);

x = 32;
for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    TextureSetModulationAlpha(helicopter, 0x01 * i * 4);
    TextureBlit_f(helicopter, x, 128);
    ScreenFlip();
    TimerDelayForFPS(30);
end;
TextureSetModulationAlpha(helicopter, 0xFF);

x = 32;
for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    TextureSetModulationAlpha_f(helicopter, 1 / 240 * i * 4);
    TextureBlit_f(helicopter, x, 128);
    ScreenFlip();
    TimerDelayForFPS(30);
end;
TextureSetModulationAlpha_f(helicopter, 1.0);

-- Texture Copy
helicopterCopy = TextureCopy(helicopter);
x = 32;
for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    TextureBlit_f(helicopterCopy, x, 128);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureSave(helicopter, "test/output_1.png");
TextureSave(helicopterCopy, "test/output_2.png");

output = TextureCreate("Output texture", 96, 32);
TextureBeginTarget(output);
    TextureBlit_f(helicopterCopy, 0, 0);
TextureEndTarget();

x = 32;
for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    TextureBlit_f(output, x, 128);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureSave(output, "test/output_3.png");
TextureFree(output);
TextureFree(helicopterCopy);
TextureFree(helicopterAnim);
TextureFree(helicopter);
