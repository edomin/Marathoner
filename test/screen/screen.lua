local i;
local x = 32;

-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

ScreenInit(640, 480, false, "Screen Test");
local w = ScreenGetWidth();
local h = ScreenGetHeight();
FileWriteLineFast("test/output.txt", "width: " .. w , FM_APPEND);
FileWriteLineFast("test/output.txt", "height: " .. h , FM_APPEND);
w, h = ScreenGetSizes();
FileWriteLineFast("test/output.txt", "width: " .. w , FM_APPEND);
FileWriteLineFast("test/output.txt", "height: " .. h , FM_APPEND);

TimerInit();
PrimitiveInit();
for i = 0, 150, 1 do
    TimerStart();
    x = x + 1;
    PrimitiveFill_c(0x000000);
    PrimitiveRectangleFilled_c_f(x, 128, x + 32, 160, 0xFF0000);
    ScreenFlip();
    TimerDelayForFPS(30);
end;
