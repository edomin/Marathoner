local quit = false;

-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

ScreenInit(640, 480, false, "Mouse Test");
PrimitiveInit();
KeyboardInit();
TimerInit();

while not quit do
    TimerStart();
    KeyboardRefresh();
    if KeyboardPress(KEY_ESCAPE) then
        quit = true;
    end;

    if KeyboardPress(KEY_1) then
        LogWrite("Hello", 0, LMT_INFO);
    end;

    if KeyboardPress(KEY_2) then
        ConsoleShow();
    end;

    if KeyboardPress(KEY_3) then
        ConsoleHide();
    end;

    PrimitiveFill_c(0x000000);

    ScreenFlip();

    TimerDelayForFPS(30);
end;

