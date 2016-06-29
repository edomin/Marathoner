ScreenInit(800, 600);
PrimitiveInit();
TextureInit(IKDM_MEDIUM, 64);
helicopter = {};
for i = 0, 7, 1 do
    helicopter[i] = TextureLoad("autorun/helicopter_" .. (i + 1) .. ".png");
end;

road = TextureLoad("autorun/road.png");
testSphere = TextureLoad("autorun/test_sphere.png");
testSphere2 = TextureLoad("autorun/test_sphere2.png");
--TextureSetBlendFunction(testSphere, BLEND_SRC_ALPHA, BLEND_MINUS_SRC_ALPHA, BLEND_SRC_ALPHA, BLEND_MINUS_SRC_ALPHA);
--TextureSetBlendFunction(testSphere2, BLEND_SRC_ALPHA, BLEND_MINUS_SRC_ALPHA, BLEND_SRC_ALPHA, BLEND_MINUS_SRC_ALPHA);

for i = 0, 100, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    for j = 0, 10, 1 do
        for k = 0, 10, 1 do
            TextureBlit_f(road, j * 32, k * 32);
        end;
    end;
    TextureBlit_f(testSphere, 64, 64);
    TextureBlit_f(testSphere2, 128, 64);
    TextureBlit_f(helicopter[i % 8], i * 5, 64);
    PrimitiveEllipseFilled_ca_f(400, 300, 300, 150, i * 5, 0xFF000088);
    ScreenFlip();
    TimerDelay(30);
end;

for i = 0, 7, 1 do
    TextureFree(helicopter[i]);
end;
ScreenQuit();
