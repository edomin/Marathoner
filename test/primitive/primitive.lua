local i;
local x;
local helicopter;

-- Positive
ScreenInit(640, 480, false, "Primitive Test");
TimerInit();
PrimitiveInit();
MouseInit();

for i = 0, 30, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 30, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_ca(0xFF0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 30, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_rgb(0x00, 0xFF, 0x00);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 30, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_rgb(0x00, 0x00, 0xFF, 0x00);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    PrimitivePixel_rgb_f(32 + i * 2, 32, 0xFF, 0x00, 0x00);
    PrimitivePixel_rgba_f(32 + i * 2, 34, 0xFF, 0x00, 0x00, 0xFF);
    PrimitivePixel_c_f(32 + i * 2, 36, 0xFF0000);
    PrimitivePixel_ca_f(32 + i * 2, 38, 0xFF0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    PrimitiveLine_rgb_f(32 + i * 2, 32, 32 + i * 2 + 4, 36, 0xFF, 0x00, 0x00);
    PrimitiveLine_rgba_f(32 + i * 2, 40, 32 + i * 2 + 4, 44, 0xFF, 0x00, 0x00,
     0xFF);
    PrimitiveLine_c_f(32 + i * 2, 48, 32 + i * 2 + 4, 52, 0xFF0000);
    PrimitiveLine_ca_f(32 + i * 2, 56, 32 + i * 2 + 4, 60, 0xFF0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    PrimitiveArc_rgb_f(32, 32, 24, i, i + 90, 0xFF, 0x00, 0x00);
    PrimitiveArc_rgba_f(32, 64, 24, i, i + 90, 0xFF, 0x00, 0x00, 0xFF);
    PrimitiveArc_c_f(32, 96, 24, i, i + 90, 0xFF0000);
    PrimitiveArc_ca_f(32, 128, 24, i, i + 90, 0xFF0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    PrimitiveSegmentFilled_rgb_f(32, 32, 24, i, i + 90, 0xFF, 0x00, 0x00);
    PrimitiveSegmentFilled_rgba_f(32, 64, 24, i, i + 90, 0xFF, 0x00, 0x00,
     0xFF);
    PrimitiveSegmentFilled_c_f(32, 96, 24, i, i + 90, 0xFF0000);
    PrimitiveSegmentFilled_ca_f(32, 128, 24, i, i + 90, 0xFF0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    PrimitiveCircle_rgb_f(32, 32, i, 0xFF, 0x00, 0x00);
    PrimitiveCircle_rgba_f(32, 64, i, 0xFF, 0x00, 0x00, 0xFF);
    PrimitiveCircle_c_f(32, 96, i, 0xFF0000);
    PrimitiveCircle_ca_f(32, 128, i, 0xFF0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    PrimitiveCircleFilled_rgb_f(32, 32, i, 0xFF, 0x00, 0x00);
    PrimitiveCircleFilled_rgba_f(32, 64, i, 0xFF, 0x00, 0x00, 0xFF);
    PrimitiveCircleFilled_c_f(32, 96, i, 0xFF0000);
    PrimitiveCircleFilled_ca_f(32, 128, i, 0xFF0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    PrimitiveEllipse_rgb_f(32, 32, i, i / 2, i, 0xFF, 0x00, 0x00);
    PrimitiveEllipse_rgba_f(32, 64, i, i / 2, i, 0xFF, 0x00, 0x00, 0xFF);
    PrimitiveEllipse_c_f(32, 32, i, i / 2, i, 0xFF0000);
    PrimitiveEllipse_ca_f(32, 32, i, i / 2, i, 0xFF0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    PrimitiveEllipseFilled_rgb_f(32, 32, i, i / 2, i, 0xFF, 0x00, 0x00);
    PrimitiveEllipseFilled_rgba_f(32, 64, i, i / 2, i, 0xFF, 0x00, 0x00, 0xFF);
    PrimitiveEllipseFilled_c_f(32, 32, i, i / 2, i, 0xFF0000);
    PrimitiveEllipseFilled_ca_f(32, 32, i, i / 2, i, 0xFF0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    PrimitiveRingSegment_rgb_f(32, 32, i / 60 * 24, 24, i, i + 90, 0xFF, 0x00,
     0x00);
    PrimitiveRingSegment_rgba_f(32, 64, i / 60 * 24, 24, i, i + 90, 0xFF, 0x00,
     0x00, 0xFF);
    PrimitiveRingSegment_c_f(32, 96, i / 60 * 24, 24, i, i + 90, 0xFF0000);
    PrimitiveRingSegment_ca_f(32, 128, i / 60 * 24, 24, i, i + 90, 0xFF0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    PrimitiveRingSegmentFilled_rgb_f(32, 32, i / 60 * 24, 24, i, i + 90, 0xFF,
     0x00, 0x00);
    PrimitiveRingSegmentFilled_rgba_f(32, 64, i / 60 * 24, 24, i, i + 90, 0xFF,
     0x00, 0x00, 0xFF);
    PrimitiveRingSegmentFilled_c_f(32, 96, i / 60 * 24, 24, i, i + 90,
     0xFF0000);
    PrimitiveRingSegmentFilled_ca_f(32, 128, i / 60 * 24, 24, i, i + 90,
     0xFF0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    PrimitiveTriangle_rgb_f(32 + i * 2, 32, 32 + i * 2 + 32, 32,
     32 + i * 2 + 16, 8, 0xFF, 0x00, 0x00);
    PrimitiveTriangle_rgba_f(32 + i * 2, 64, 32 + i * 2 + 32, 64,
     32 + i * 2 + 16, 40, 0xFF, 0x00, 0x00, 0xFF);
    PrimitiveTriangle_c_f(32 + i * 2, 96, 32 + i * 2 + 32, 96, 32 + i * 2 + 16,
     72, 0xFF0000);
    PrimitiveTriangle_ca_f(32 + i * 2, 128, 32 + i * 2 + 32, 128,
     32 + i * 2 + 16, 104, 0xFF0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    PrimitiveTriangleFilled_rgb_f(32 + i * 2, 32, 32 + i * 2 + 32, 32,
     32 + i * 2 + 16, 8, 0xFF, 0x00, 0x00);
    PrimitiveTriangleFilled_rgba_f(32 + i * 2, 64, 32 + i * 2 + 32, 64,
     32 + i * 2 + 16, 40, 0xFF, 0x00, 0x00, 0xFF);
    PrimitiveTriangleFilled_c_f(32 + i * 2, 96, 32 + i * 2 + 32, 96,
     32 + i * 2 + 16, 72, 0xFF0000);
    PrimitiveTriangleFilled_ca_f(32 + i * 2, 128, 32 + i * 2 + 32, 128,
     32 + i * 2 + 16, 104, 0xFF0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    PrimitiveRectangle_rgb_f(32 + i * 2, 32, 32 + i * 2 + 24, 56, 0xFF, 0x00,
     0x00);
    PrimitiveRectangle_rgba_f(32 + i * 2, 64, 32 + i * 2 + 24, 88, 0xFF, 0x00,
     0x00, 0xFF);
    PrimitiveRectangle_c_f(32 + i * 2, 96, 32 + i * 2 + 24, 120, 0xFF0000);
    PrimitiveRectangle_ca_f(32 + i * 2, 128, 32 + i * 2 + 24, 152, 0xFF0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    PrimitiveRectangleFilled_rgb_f(32 + i * 2, 32, 32 + i * 2 + 24, 56, 0xFF,
     0x00, 0x00);
    PrimitiveRectangleFilled_rgba_f(32 + i * 2, 64, 32 + i * 2 + 24, 88, 0xFF,
     0x00, 0x00, 0xFF);
    PrimitiveRectangleFilled_c_f(32 + i * 2, 96, 32 + i * 2 + 24, 120,
     0xFF0000);
    PrimitiveRectangleFilled_ca_f(32 + i * 2, 128, 32 + i * 2 + 24, 152,
     0xFF0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    PrimitiveRoundedRectangle_rgb_f(32 + i * 2, 32, 32 + i * 2 + 24, 56,
     i / 60 * 10, 0xFF, 0x00, 0x00);
    PrimitiveRoundedRectangle_rgba_f(32 + i * 2, 64, 32 + i * 2 + 24, 88,
     i / 60 * 10, 0xFF, 0x00, 0x00, 0xFF);
    PrimitiveRoundedRectangle_c_f(32 + i * 2, 96, 32 + i * 2 + 24, 120,
     i / 60 * 10, 0xFF0000);
    PrimitiveRoundedRectangle_ca_f(32 + i * 2, 128, 32 + i * 2 + 24, 152,
     i / 60 * 10, 0xFF0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    PrimitiveRoundedRectangleFilled_rgb_f(32 + i * 2, 32, 32 + i * 2 + 24, 56,
     i / 60 * 10, 0xFF, 0x00, 0x00);
    PrimitiveRoundedRectangleFilled_rgba_f(32 + i * 2, 64, 32 + i * 2 + 24, 88,
     i / 60 * 10, 0xFF, 0x00, 0x00, 0xFF);
    PrimitiveRoundedRectangleFilled_c_f(32 + i * 2, 96, 32 + i * 2 + 24, 120,
     i / 60 * 10, 0xFF0000);
    PrimitiveRoundedRectangleFilled_ca_f(32 + i * 2, 128, 32 + i * 2 + 24, 152,
     i / 60 * 10, 0xFF0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

for i = 0, 60, 1 do
    MouseRefresh();
    TimerStart();
    PrimitiveFill_c(0x000000);
    PrimitiveLineBegin_f(32 + i, 32);
    PrimitiveLineTo_rgb_f(64 + i, 32, 0xFF, 0x00, 0x00);
    PrimitiveLineTo_rgba_f(64 + i, 64, 0x00, 0xFF, 0x00, 0xFF);
    PrimitiveLineTo_c_f(32 + i, 64, 0x0000FF);
    PrimitiveLineTo_ca_f(32 + i, 32, 0xFFFF00FF);
    PrimitiveLineEnd();
    ScreenFlip();
    TimerDelayForFPS(30);
end;
