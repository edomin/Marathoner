local quit = false;
local mouse_x;
local mouse_y;
local mouse_dx;
local mouse_dy;

-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

ScreenInit(640, 480, false, "Mouse Test");
PrimitiveInit();
KeyboardInit();
MouseInit();
TimerInit();

local cube1_y = 64;
local cube2_y = 64;
local cube3_y = 64;

local cube4_y = 64;

while not quit do
    TimerStart();
    KeyboardRefresh();
    MouseRefresh();
    if KeyboardPress(KEY_ESCAPE) then
        quit = true;
    end;

    if MousePressed(MOUSE_LEFT) then
        cube1_y = 32;
    end;
    if MousePress(MOUSE_LEFT) then
        cube2_y = 32;
    end;
    if MouseRelease(MOUSE_LEFT) then
        cube3_y = 32;
    end;

    cube4_y = cube4_y + MouseGetWheelRelative() * 2;

    if cube1_y < 64 then
        cube1_y = cube1_y + 1;
    end;
    if cube2_y < 64 then
        cube2_y = cube2_y + 1;
    end;
    if cube3_y < 64 then
        cube3_y = cube3_y + 1;
    end;
    if cube4_y < 64 then
        cube4_y = cube4_y + 1;
    end;
    if cube4_y > 64 then
        cube4_y = cube4_y - 1;
    end;

    PrimitiveFill_c(0x000000);
    PrimitiveRectangle_c_f(64 - 8, cube1_y - 8, 64 + 8, cube1_y + 8,
     0xFF0000);
    PrimitiveRectangle_c_f(128 - 8, cube2_y - 8, 128 + 8, cube2_y + 8,
     0x00FF00);
    PrimitiveRectangle_c_f(192 - 8, cube3_y - 8, 192 + 8, cube3_y + 8,
     0x0000FF);
    PrimitiveRectangle_c_f(256 - 8, cube4_y - 8, 256 + 8, cube4_y + 8,
     0xFFFF00);

    if not MouseMoving() then
        PrimitiveRectangle_c_f(320 - 8, 64 - 8, 320 + 8, 64 + 8,
         0xFF00FF);
    end;

    mouse_x = MouseGetX();
    mouse_y = MouseGetY();
    PrimitiveRectangle_c_f(mouse_x - 8, mouse_y - 8, mouse_x + 8, mouse_y + 8,
     0x00FFFF);
    mouse_x, mouse_y = MouseGetXY();
    PrimitiveCircle_c_f(mouse_x, mouse_y, 8, 0x00FFFF);

    mouse_dx = MouseGetDeltaX();
    mouse_dy = MouseGetDeltaY();
    PrimitiveRectangle_c_f(320 + mouse_dx - 8, 240 + mouse_dy - 8,
     320 + mouse_dx + 8, 240 + mouse_dy + 8, 0xFFFFFF);
    mouse_dx, mouse_dy = MouseGetDeltaXY();
    PrimitiveCircle_c_f(320 + mouse_dx, 240 + mouse_dy, 8, 0xFFFFFF);

    ScreenFlip();

    TimerDelayForFPS(30);
end;
