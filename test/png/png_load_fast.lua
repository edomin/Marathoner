local i;
local x;
local helicopter;
local loadedHelicopter;
local success;

-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

ScreenInit(640, 480, false, "Png Test");
TimerInit();
PrimitiveInit();
PngInit();
TextureInit(IKDM_SMALL, 32);
MouseInit();
helicopter = TextureCreate("helicopter", 96, 32);
loadedHelicopter = PngLoadFast("test/media/helicopter.png");
success = TextureReceivePixels(helicopter, loadedHelicopter);
if success then
    FileWriteLineFast("test/output.txt", "Texture created from PNG", FM_APPEND);
else
    FileWriteLineFast("test/output.txt", "Texture not created from PNG",
     FM_APPEND);
end;

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

TextureFree(helicopter);
