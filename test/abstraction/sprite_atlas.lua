local i;
local x;
local dog;
local frameX;
local frameY;
local frameWidth;
local frameHeight;
local frameAnchorX;
local frameAnchorY;

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

for i = 0, 5, 1 do
    FileWriteLineFast("test/output.txt", "Frame: " .. i, FM_APPEND);
    frameX, frameY = SpriteGetFrameCoords(dog, i);
    FileWriteLineFast("test/output.txt", "frameX: " .. frameX, FM_APPEND);
    FileWriteLineFast("test/output.txt", "frameY: " .. frameY, FM_APPEND);
    FileWriteLineFast("test/output.txt", "SpriteGetFrameX(dog, i): " .. SpriteGetFrameX(dog, i), FM_APPEND);
    FileWriteLineFast("test/output.txt", "SpriteGetFrameY(dog, i): " .. SpriteGetFrameY(dog, i), FM_APPEND);
    frameWidth, frameHeight = SpriteGetFrameSizes(dog, i);
    FileWriteLineFast("test/output.txt", "frameWidth: " .. frameWidth, FM_APPEND);
    FileWriteLineFast("test/output.txt", "frameHeight: " .. frameHeight, FM_APPEND);
    FileWriteLineFast("test/output.txt", "SpriteGetFrameWidth(dog, i): " .. SpriteGetFrameWidth(dog, i), FM_APPEND);
    FileWriteLineFast("test/output.txt", "SpriteGetFrameHeight(dog, i): " .. SpriteGetFrameHeight(dog, i), FM_APPEND);
    frameAnchorX, frameAnchorY = SpriteGetFrameAnchors(dog, i);
    FileWriteLineFast("test/output.txt", "frameAnchorX: " .. frameAnchorX, FM_APPEND);
    FileWriteLineFast("test/output.txt", "frameAnchorY: " .. frameAnchorY, FM_APPEND);
    FileWriteLineFast("test/output.txt", "SpriteGetFrameAnchorX(dog, i): " .. SpriteGetFrameAnchorX(dog, i), FM_APPEND);
    FileWriteLineFast("test/output.txt", "SpriteGetFrameAnchorY(dog, i): " .. SpriteGetFrameAnchorY(dog, i), FM_APPEND);
end;

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
