local quit = false;
local char = nil;
local lastChar = " ";

-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

ScreenInit(640, 480, false, "Keyboard Test");
PrimitiveInit();
KeyboardInit();
TimerInit();
TextureInit(IKDM_SMALL, 32);
TtfInit(IKDM_SMALL, 32);
FontInit(IKDM_SMALL, 32);
local mbf_big_00 = TextureLoad("test/media/mbf_big_00.png");
local mbf_big_04 = TextureLoad("test/media/mbf_big_04.png");
local mbf = FontCreateMbf("MBF font", 5, 10, 12);
FontAddMbfTextureTable(mbf, mbf_big_00, 0);
FontAddMbfTextureTable(mbf, mbf_big_04, 4);

local cube1 = {};
cube1.x = 64;
cube1.y = 64;
local cube2 = {};
cube2.x = 128;
cube2.y = 64;
local cube3 = {};
cube3.x = 192;
cube3.y = 64;
local cube4 = {};
cube4.x = 256;
cube4.y = 64;
local cube5 = {};
cube5.x = 320;
cube5.y = 64;
local hsign;
local vsign;

while not quit do
    TimerStart();
    KeyboardRefresh();
    if KeyboardPress(KEY_ESCAPE) then
        quit = true;
    end;
    if KeyboardPressed(KEY_UP) then
        cube1.y = 32;
    end;
    if KeyboardPressed(KEY_DOWN) then
        cube1.y = 96;
    end;
    if KeyboardPressed(KEY_LEFT) then
        cube1.x = 32;
    end;
    if KeyboardPressed(KEY_RIGHT) then
        cube1.x = 96;
    end;
    if KeyboardPress(KEY_UP) then
        cube2.y = 32;
    end;
    if KeyboardPress(KEY_DOWN) then
        cube2.y = 96;
    end;
    if KeyboardPress(KEY_LEFT) then
        cube2.x = 96;
    end;
    if KeyboardPress(KEY_RIGHT) then
        cube2.x = 160;
    end;
    if KeyboardRelease(KEY_UP) then
        cube3.y = 32;
    end;
    if KeyboardRelease(KEY_DOWN) then
        cube3.y = 96;
    end;
    if KeyboardRelease(KEY_LEFT) then
        cube3.x = 160;
    end;
    if KeyboardRelease(KEY_RIGHT) then
        cube3.x = 224;
    end;
    cube4.x = 256 + KeyboardArrowsGetHorAxis(KEY_LEFT, KEY_RIGHT) * 32;
    cube4.y = 64 + KeyboardArrowsGetVerAxis(KEY_UP, KEY_DOWN) * 32;
    hsign, vsign = KeyboardArrowsGetAxes(KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT);
    cube5.x = 320 + hsign * 32;
    cube5.y = 64 + vsign * 32;

    if cube1.y > 64 then
        cube1.y = cube1.y - 1;
    end;
    if cube1.y < 64 then
        cube1.y = cube1.y + 1;
    end;
    if cube1.x > 64 then
        cube1.x = cube1.x - 1;
    end;
    if cube1.x < 64 then
        cube1.x = cube1.x + 1;
    end;

    if cube2.y > 64 then
        cube2.y = cube2.y - 1;
    end;
    if cube2.y < 64 then
        cube2.y = cube2.y + 1;
    end;
    if cube2.x > 128 then
        cube2.x = cube2.x - 1;
    end;
    if cube2.x < 128 then
        cube2.x = cube2.x + 1;
    end;

    if cube3.y > 64 then
        cube3.y = cube3.y - 1;
    end;
    if cube3.y < 64 then
        cube3.y = cube3.y + 1;
    end;
    if cube3.x > 192 then
        cube3.x = cube3.x - 1;
    end;
    if cube3.x < 192 then
        cube3.x = cube3.x + 1;
    end;

    if cube4.y > 64 then
        cube4.y = cube4.y - 1;
    end;
    if cube4.y < 64 then
        cube4.y = cube4.y + 1;
    end;
    if cube4.x > 256 then
        cube4.x = cube4.x - 1;
    end;
    if cube4.x < 256 then
        cube4.x = cube4.x + 1;
    end;

    if cube5.y > 64 then
        cube5.y = cube5.y - 1;
    end;
    if cube5.y < 64 then
        cube5.y = cube5.y + 1;
    end;
    if cube5.x > 320 then
        cube5.x = cube5.x - 1;
    end;
    if cube5.x < 320 then
        cube5.x = cube5.x + 1;
    end;

    PrimitiveFill_c(0x000000);
    PrimitiveRectangle_c_f(cube1.x - 8, cube1.y - 8, cube1.x + 8, cube1.y + 8,
     0xFF0000);
    PrimitiveRectangle_c_f(cube2.x - 8, cube2.y - 8, cube2.x + 8, cube2.y + 8,
     0x00FF00);
    PrimitiveRectangle_c_f(cube3.x - 8, cube3.y - 8, cube3.x + 8, cube3.y + 8,
     0x0000FF);
    PrimitiveRectangle_c_f(cube4.x - 8, cube4.y - 8, cube4.x + 8, cube4.y + 8,
     0xFFFF00);
    PrimitiveRectangle_c_f(cube5.x - 8, cube5.y - 8, cube5.x + 8, cube5.y + 8,
     0xFFFFFF);

    char = KeyboardInputChar();
    if char ~= nil then
        lastChar = char;
    end;
    FontDrawMbfString_f(mbf, 64, 128, lastChar);

    ScreenFlip();

    TimerDelayForFPS(30);
end;
