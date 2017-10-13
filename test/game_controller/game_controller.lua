-- TODO testing of trackball functions. I have noone controller with trackball

local quit = false;
local i;

-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

ScreenInit(640, 480, false, "Game Controller Test");
PrimitiveInit();
KeyboardInit();
GameControllerInit();
TimerInit();

local buttonsCount = GameControllerGetButtonsCount(1);
local button = {};
for i = 0, buttonsCount - 1, 1 do
    button[i] = {};
    button[i].yr = 0; -- Y relative
    button[i].pressed = false;
end;

local axesCount = GameControllerGetAxesCount(1);
local axis = {};
for i = 0, axesCount - 1, 1 do
    axis[i] = {};
    axis[i].yr = 0;
    axis[i].yr2 = 0;
    axis[i].dyr = 0;
    axis[i].dyr2 = 0;
end;

local powHatsCount = GameControllerGetPowHatsCount(1);
local powHat = {};
for i = 0, powHatsCount - 1, 1 do
    powHat[i] = {};
end;

while not quit do
    TimerStart();
    KeyboardRefresh();
    GameControllerRefresh();
    if KeyboardPress(KEY_ESCAPE) then
        quit = true;
    end;

    for i = 0, buttonsCount - 1, 1 do
        if GameControllerButtonPress(1, i) then
            button[i].yr = -32;
        end;
        if GameControllerButtonRelease(1, i) then
            button[i].yr = 32;
        end;
        button[i].pressed = GameControllerButtonPressed(1, i);
        button[i].yr = button[i].yr - Sign(button[i].yr);
    end;

    for i = 0, axesCount - 1, 1 do
        axis[i].yr = GameControllerGetAxis_f(1, i) * 32;
        axis[i].yr2 = GameControllerGetAxis(1, i) / 32768 * 32;
        axis[i].dyr = GameControllerGetAxisDelta_f(1, i) * 32;
        axis[i].dyr2 = GameControllerGetAxisDelta(1, i) / 32768 * 32;
    end;

    for i = 0, powHatsCount - 1, 1 do
        powHat[i].dir = GameControllerGetPovHat(1, i);
        powHat[i].hor = GameControllerGetPovHatHorizontal(1, i);
        powHat[i].ver = GameControllerGetPovHatVertical(1, i);
    end;

    PrimitiveFill_c(0x000000);

    for i = 0, buttonsCount - 1, 1 do
        if button[i].pressed then
            PrimitiveCircleFilled_c_f(32 + i * 32, 64 + button[i].yr, 8,
             0xFFFFFF);
        else
            PrimitiveCircle_c_f(32 + i * 32, 64 + button[i].yr, 8, 0xFFFFFF);
        end;
    end;

    for i = 0, axesCount - 1, 1 do
        PrimitiveCircleFilled_c_f(32 + i * 32, 128 + axis[i].yr, 8, 0xFF0000);
        PrimitiveRectangle_c_f(32 + i * 32 - 8, 128 + axis[i].yr2 - 8, 32 + i * 32 + 8, 128 + axis[i].yr2 + 8, 0x0000FF);
        PrimitiveCircleFilled_c_f(32 + i * 32, 192 + axis[i].dyr, 8, 0xFF0000);
        PrimitiveRectangle_c_f(32 + i * 32 - 8, 192 + axis[i].dyr2 - 8, 32 + i * 32 + 8, 192 + axis[i].dyr2 + 8, 0x0000FF);
    end;

    for i = 0, powHatsCount - 1, 1 do
        if powHat[i].dir == POVHAT_UP then
            PrimitiveCircleFilled_c_f(32 + i * 32, 256 - 16, 8, 0x0000FF);
        elseif powHat[i].dir == POVHAT_DOWN then
            PrimitiveCircleFilled_c_f(32 + i * 32, 256 + 16, 8, 0x0000FF);
        elseif powHat[i].dir == POVHAT_LEFT then
            PrimitiveCircleFilled_c_f(32 + i * 32 - 16, 256, 8, 0x0000FF);
        elseif powHat[i].dir == POVHAT_RIGHT then
            PrimitiveCircleFilled_c_f(32 + i * 32 + 16, 256, 8, 0x0000FF);
        elseif powHat[i].dir == POVHAT_UP_LEFT then
            PrimitiveCircleFilled_c_f(32 + i * 32 - 16, 256 - 16, 8, 0x0000FF);
        elseif powHat[i].dir == POVHAT_UP_RIGHT then
            PrimitiveCircleFilled_c_f(32 + i * 32 + 16, 256 - 16, 8, 0x0000FF);
        elseif powHat[i].dir == POVHAT_DOWN_LEFT then
            PrimitiveCircleFilled_c_f(32 + i * 32 - 16, 256 + 16, 8, 0x0000FF);
        elseif powHat[i].dir == POVHAT_DOWN_RIGHT then
            PrimitiveCircleFilled_c_f(32 + i * 32 + 16, 256 + 16, 8, 0x0000FF);
        else
            PrimitiveCircleFilled_c_f(32 + i * 32, 256, 8, 0x0000FF);
        end;
        PrimitiveCircleFilled_c_f(32 + i * 32 + Sign(powHat[i].hor) * 16,
         320 + Sign(powHat[i].ver) * 16, 8, 0x0000FF);
    end;

    ScreenFlip();

    TimerDelayForFPS(30);
end;

GameControllerQuit();
