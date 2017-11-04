local i;
local success;

-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

ScreenInit(640, 480, false, "Font test");
PngInit();
TextureInit(IKDM_SMALL, 32);
TtfInit(IKDM_SMALL, 32);
PrimitiveInit();
TimerInit();

local ttf = TtfLoad("test/media/Vera.ttf", 24);
local textPixels = TtfRenderString(ttf, 0xFF, 0x00, 0x00, "Hello World");
success = PngSaveFast("test/output.png", textPixels);
if not success then
    FileWriteLineFast("test/output.txt", "Pixels not saved to png-file",
     FM_APPEND);
end;

TtfFree(ttf);
TtfQuit();
ScreenQuit();
