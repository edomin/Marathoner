local i;
local x;
local helicopter;

-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

ScreenInit(640, 480, false, "Sprite Test");
TimerInit();
PrimitiveInit();
MouseInit();
TextureInit(IKDM_SMALL, 32);
SpriteInit(IKDM_SMALL, 32);
helicopter = SpriteLoadSimple("test/media/helicopter.png", 48, 16);
helicopterAnim = SpriteLoad("test/media/helicopter_anim.png", 96, 32, 1, 8, 8,
 48, 16);

-- Prepare to watch
for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

-- Animated sprite
x = 32;
for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    SpriteDraw_f(helicopterAnim, Floor_f(i / 4) % 8, x, 128);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    SpriteDrawSized_f(helicopterAnim, Floor_f(i / 4) % 8, 64, 128,
     96 / 60 * i, 32 / 60 * i);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    SpriteDrawScaled_f(helicopterAnim, Floor_f(i / 4) % 8, 64, 128, i / 30,
     i / 30);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

x = 32;
for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    SpriteDrawAngled_f(helicopterAnim, Floor_f(i / 4) % 8, x, 128, -x);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

x = 32;
for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    SpriteDrawFlipped_f(helicopterAnim, Floor_f(i / 4) % 8, x, 128, FLIP_NONE);
    SpriteDrawFlipped_f(helicopterAnim, Floor_f(i / 4) % 8, x, 160,
     FLIP_HORIZONTAL);
    SpriteDrawFlipped_f(helicopterAnim, Floor_f(i / 4) % 8, x, 192,
     FLIP_VERTICAL);
    SpriteDrawFlipped_f(helicopterAnim, Floor_f(i / 4) % 8, x, 224, FLIP_BOTH);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    SpriteDrawGeneral_f(helicopterAnim, Floor_f(i / 4) % 8, 64, 128, i / 30,
     i / 30, -i * 2, FLIP_NONE);
    SpriteDrawGeneral_f(helicopterAnim, Floor_f(i / 4) % 8, 64, 160, i / 30,
     i / 30, -i * 2, FLIP_HORIZONTAL);
    SpriteDrawGeneral_f(helicopterAnim, Floor_f(i / 4) % 8, 64, 192, i / 30,
     i / 30, -i * 2, FLIP_VERTICAL);
    SpriteDrawGeneral_f(helicopterAnim, Floor_f(i / 4) % 8, 64, 244, i / 30,
     i / 30, -i * 2, FLIP_BOTH);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

-- Non-animated sprite with modulation
x = 32;
for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    SpriteSetModulation_c(helicopter, 0x000101 * (60 - i) * 4 + 0xFF0000);
    SpriteDraw_f(helicopter, 0, x, 128);
    ScreenFlip();
    TimerDelayForFPS(30);
end;
TextureSetModulation_c(helicopter, 0xFFFFFF);

x = 32;
for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    SpriteSetModulation_ca(helicopter,
     0x00010100 * (60 - i) * 4 + 0x00000001 * i * 4 + 0xFF000000);
    SpriteDraw_f(helicopter, 0, x, 128);
    ScreenFlip();
    TimerDelayForFPS(30);
end;
TextureSetModulation_ca(helicopter, 0xFFFFFFFF);

x = 32;
for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    SpriteSetModulation_rgb(helicopter, 0xFF, 0x01 * (60 - i) * 4,
     0x01 * (60 - i) * 4);
    SpriteDraw_f(helicopter, 0, x, 128);
    ScreenFlip();
    TimerDelayForFPS(30);
end;
TextureSetModulation_rgb(helicopter, 0xFF, 0xFF, 0xFF);

x = 32;
for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    SpriteSetModulation_rgba(helicopter, 0xFF, 0x01 * (60 - i) * 4,
     0x01 * (60 - i) * 4, 0x01 * i * 4);
    SpriteDraw_f(helicopter, 0, x, 128);
    ScreenFlip();
    TimerDelayForFPS(30);
end;
TextureSetModulation_rgba(helicopter, 0xFF, 0xFF, 0xFF, 0xFF);

x = 32;
for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    SpriteSetModulationAlpha(helicopter, 0x01 * i * 4);
    SpriteDraw_f(helicopter, 0, x, 128);
    ScreenFlip();
    TimerDelayForFPS(30);
end;
TextureSetModulationAlpha(helicopter, 0xFF);

x = 32;
for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    SpriteSetModulationAlpha_f(helicopter, 1 / 240 * i * 4);
    SpriteDraw_f(helicopter, 0, x, 128);
    ScreenFlip();
    TimerDelayForFPS(30);
end;
TextureSetModulationAlpha_f(helicopter, 1.0);

-- Texture Copy
SpriteFree(helicopter);
SpriteFree(helicopterAnim);
