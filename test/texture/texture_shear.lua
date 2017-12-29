local i;
local x;
local texture;

-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

ScreenInit(640, 480, false, "Texture shear Test");
TimerInit();
PrimitiveInit();
TextureInit(IKDM_SMALL, 32);
MouseInit();
texture = TextureLoad("test/media/castleFloor.png");
helicopterAnim = TextureLoad("test/media/helicopter_anim.png");

-- Prepare to watch
for i = 0, 30, 1 do
    TimerStart();
    MouseRefresh();
    PrimitiveFill_c(0x000000);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    if ScreenXed() then
        break;
    end;
    PrimitiveFill_c(0x000000);
    TextureBlitVerSheared_f(texture, 64, 128, i / 100, 0);
    TextureBlitVerSheared_f(texture, 128, 128, i / 100, 16);
    TextureBlitVerSheared_f(texture, 196, 128, i / 100, 32);
    PrimitiveRectangle_c_f(64, 128, 96, 160, 0xFF0000);
    PrimitiveLine_c_f(64, 128, 64, 160, 0x0000FF);
    PrimitiveRectangle_c_f(128, 128, 160, 160, 0xFF0000);
    PrimitiveLine_c_f(144, 128, 144, 160, 0x0000FF);
    PrimitiveRectangle_c_f(196, 128, 228, 160, 0xFF0000);
    PrimitiveLine_c_f(228, 128, 228, 160, 0x0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    if ScreenXed() then
        break;
    end;
    PrimitiveFill_c(0x000000);
    TextureBlitHorSheared_f(texture, 128, 64, i / 100, 0);
    TextureBlitHorSheared_f(texture, 128, 128, i / 100, 16);
    TextureBlitHorSheared_f(texture, 128, 196, i / 100, 32);
    PrimitiveRectangle_c_f(128, 64, 160, 96, 0xFF0000);
    PrimitiveLine_c_f(128, 64, 160, 64, 0x0000FF);
    PrimitiveRectangle_c_f(128, 128, 160, 160, 0xFF0000);
    PrimitiveLine_c_f(128, 144, 160, 144, 0x0000FF);
    PrimitiveRectangle_c_f(128, 196, 160, 228, 0xFF0000);
    PrimitiveLine_c_f(128, 228, 160, 228, 0x0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    if ScreenXed() then
        break;
    end;
    PrimitiveFill_c(0x000000);
    TextureBlitVerShearedByAngle_f(texture, 64, 128, -30 + i, 0);
    TextureBlitVerShearedByAngle_f(texture, 128, 128, -30 + i, 16);
    TextureBlitVerShearedByAngle_f(texture, 196, 128, -30 + i, 32);
    PrimitiveRectangle_c_f(64, 128, 96, 160, 0xFF0000);
    PrimitiveLine_c_f(64, 128, 64, 160, 0x0000FF);
    PrimitiveRectangle_c_f(128, 128, 160, 160, 0xFF0000);
    PrimitiveLine_c_f(144, 128, 144, 160, 0x0000FF);
    PrimitiveRectangle_c_f(196, 128, 228, 160, 0xFF0000);
    PrimitiveLine_c_f(228, 128, 228, 160, 0x0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    if ScreenXed() then
        break;
    end;
    PrimitiveFill_c(0x000000);
    TextureBlitHorShearedByAngle_f(texture, 128, 64, -30 + i, 0);
    TextureBlitHorShearedByAngle_f(texture, 128, 128, -30 + i, 16);
    TextureBlitHorShearedByAngle_f(texture, 128, 196, -30 + i, 32);
    PrimitiveRectangle_c_f(128, 64, 160, 96, 0xFF0000);
    PrimitiveLine_c_f(128, 64, 160, 64, 0x0000FF);
    PrimitiveRectangle_c_f(128, 128, 160, 160, 0xFF0000);
    PrimitiveLine_c_f(128, 144, 160, 144, 0x0000FF);
    PrimitiveRectangle_c_f(128, 196, 160, 228, 0xFF0000);
    PrimitiveLine_c_f(128, 228, 160, 228, 0x0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    if ScreenXed() then
        break;
    end;
    PrimitiveFill_c(0x000000);
    TextureBlitRegionVerSheared_f(helicopterAnim, 64, 128, (Floor_f(i / 4) % 8) * 96, 0, 96, 32, i / 100, 0);
    TextureBlitRegionVerSheared_f(helicopterAnim, 128, 128, (Floor_f(i / 4) % 8) * 96, 0, 96, 32, i / 100, 48);
    TextureBlitRegionVerSheared_f(helicopterAnim, 196, 128, (Floor_f(i / 4) % 8) * 96, 0, 96, 32, i / 100, 96);
    PrimitiveRectangle_c_f(64, 128, 160, 160, 0xFF0000);
    PrimitiveLine_c_f(64, 128, 64, 160, 0x0000FF);
    PrimitiveRectangle_c_f(128, 128, 224, 160, 0xFF0000);
    PrimitiveLine_c_f(176, 128, 176, 160, 0x0000FF);
    PrimitiveRectangle_c_f(196, 128, 292, 160, 0xFF0000);
    PrimitiveLine_c_f(292, 128, 292, 160, 0x0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

--for i = 0, 60, 1 do
--    TimerStart();
--    MouseRefresh();
--    if ScreenXed() then
--        break;
--    end;
--    PrimitiveFill_c(0x000000);
--    TextureBlitHorSheared_f(helicopterAnim, 128, 64, i / 100, 0);
--    TextureBlitHorSheared_f(helicopterAnim, 128, 128, i / 100, 16);
--    TextureBlitHorSheared_f(helicopterAnim, 128, 196, i / 100, 32);
--    PrimitiveRectangle_c_f(128, 64, 160, 96, 0xFF0000);
--    PrimitiveLine_c_f(128, 64, 160, 64, 0x0000FF);
--    PrimitiveRectangle_c_f(128, 128, 160, 160, 0xFF0000);
--    PrimitiveLine_c_f(128, 144, 160, 144, 0x0000FF);
--    PrimitiveRectangle_c_f(128, 196, 160, 228, 0xFF0000);
--    PrimitiveLine_c_f(128, 228, 160, 228, 0x0000FF);
--    ScreenFlip();
--    TimerDelayForFPS(30);
--end;

for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    if ScreenXed() then
        break;
    end;
    PrimitiveFill_c(0x000000);
    TextureBlitRegionVerShearedByAngle_f(helicopterAnim, 64, 128, (Floor_f(i / 4) % 8) * 96, 0, 96, 32, -30 + i, 0);
    TextureBlitRegionVerShearedByAngle_f(helicopterAnim, 128, 128, (Floor_f(i / 4) % 8) * 96, 0, 96, 32, -30 + i, 48);
    TextureBlitRegionVerShearedByAngle_f(helicopterAnim, 196, 128, (Floor_f(i / 4) % 8) * 96, 0, 96, 32, -30 + i, 96);
    PrimitiveRectangle_c_f(64, 128, 160, 160, 0xFF0000);
    PrimitiveLine_c_f(64, 128, 64, 160, 0x0000FF);
    PrimitiveRectangle_c_f(128, 128, 224, 160, 0xFF0000);
    PrimitiveLine_c_f(176, 128, 176, 160, 0x0000FF);
    PrimitiveRectangle_c_f(196, 128, 292, 160, 0xFF0000);
    PrimitiveLine_c_f(292, 128, 292, 160, 0x0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

--for i = 0, 60, 1 do
--    TimerStart();
--    MouseRefresh();
--    if ScreenXed() then
--        break;
--    end;
--    PrimitiveFill_c(0x000000);
--    TextureBlitHorShearedByAngle_f(helicopterAnim, 128, 64, -30 + i, 0);
--    TextureBlitHorShearedByAngle_f(helicopterAnim, 128, 128, -30 + i, 16);
--    TextureBlitHorShearedByAngle_f(helicopterAnim, 128, 196, -30 + i, 32);
--    PrimitiveRectangle_c_f(128, 64, 160, 96, 0xFF0000);
--    PrimitiveLine_c_f(128, 64, 160, 64, 0x0000FF);
--    PrimitiveRectangle_c_f(128, 128, 160, 160, 0xFF0000);
--    PrimitiveLine_c_f(128, 144, 160, 144, 0x0000FF);
--    PrimitiveRectangle_c_f(128, 196, 160, 228, 0xFF0000);
--    PrimitiveLine_c_f(128, 228, 160, 228, 0x0000FF);
--    ScreenFlip();
--    TimerDelayForFPS(30);
--end;

TextureFree(texture);
TextureFree(helicopterAnim);
