local i;
local x;
local dog;

-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

ScreenInit(640, 480, false, "Sprite Test");
TimerInit();
PrimitiveInit();
MouseInit();
TextureInit(IKDM_SMALL, 32);
SpriteInit(IKDM_SMALL, 32);

dog = SpriteLoadAtlas("test/media/dog.png", 6);
SpriteSetAtlasFrame(dog, 0,  1, 12,  14, 21, 9, 9);
SpriteSetAtlasFrame(dog, 1, 18, 13,  32, 21, 9, 8);
SpriteSetAtlasFrame(dog, 2, 36, 12,  51, 21, 9, 9);
SpriteSetAtlasFrame(dog, 3, 54, 13,  68, 21, 9, 8);
SpriteSetAtlasFrame(dog, 4, 72, 12,  85, 21, 9, 9);
SpriteSetAtlasFrame(dog, 5, 90, 13, 104, 21, 9, 8);

-- Prepare to watch
for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

-- Animated sprite
for i = 0, 120, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    PrimitiveLine_c_f(0, 64, 639, 64, 0xFF0000);
    SpriteDrawFlipped_f(dog, Floor_f((i % 24) / 4), i / 2 + 64, 63,
     FLIP_HORIZONTAL);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

-- Animated sprite
for i = 0, 120, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    PrimitiveLine_c_f(0, 64, 639, 64, 0xFF0000);
    SpriteDrawGeneral_f(dog, Floor_f((i % 24) / 4), i + 64, 62, 2.0, 2.0, 0,
     FLIP_HORIZONTAL);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

-- Animated sprite
for i = 0, 120, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    PrimitiveLine_c_f(0, 64, 639, 64, 0xFF0000);
    SpriteDrawGeneral_f(dog, Floor_f((i % 24) / 4), i * 2 + 64, 60, 4.0, 4.0, 0,
     FLIP_HORIZONTAL);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

-- Texture Copy
SpriteFree(dog);
