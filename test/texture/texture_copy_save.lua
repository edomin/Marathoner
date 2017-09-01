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

outputCopy = TextureCopy(output);
x = 32;
for i = 0, 60, 1 do
    TimerStart();
    MouseRefresh();
    x = x + 2;
    PrimitiveFill_c(0x000000);
    TextureBlit_f(outputCopy, x, 128);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureSave(output, "test/output_3.png");
TextureFree(output);
TextureFree(helicopterCopy);
TextureFree(helicopterAnim);
TextureFree(helicopter);
