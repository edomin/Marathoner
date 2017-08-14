-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);
if (TtfInit(IKDM_SMALL, 32)) then
    FileWriteLineFast("test/output.txt", "Success", FM_APPEND);

    local ttf = TtfLoad("test/media/Vera.ttf", 12);
    local w, h = TtfGetStringSizes(ttf, "Hello World");
    FileWriteLineFast("test/output.txt", "w: " .. w, FM_APPEND);
    FileWriteLineFast("test/output.txt", "h: " .. h, FM_APPEND);
    w = TtfGetStringWidth(ttf, "Hello World");
    h = TtfGetFontHeight(ttf);
    FileWriteLineFast("test/output.txt", "w: " .. w, FM_APPEND);
    FileWriteLineFast("test/output.txt", "h: " .. h, FM_APPEND);

    -- functions TtfSetFontStyle() and TtfSetFontOutline() can be tested by Font
    -- Abstraction module

    TtfFree(ttf);
    TtfQuit();
else
    FileWriteLineFast("test/output.txt", "Fail", FM_APPEND);
end;
