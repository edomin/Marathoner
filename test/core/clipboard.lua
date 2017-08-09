-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

local success ClipboardPutText("some text");
if success then
    FileWriteLineFast("test/output.txt", "success", FM_APPEND);
else
    FileWriteLineFast("test/output.txt", "fail", FM_APPEND);
end;

local clipboardText = ClipboardGetText();
FileWriteLineFast("test/output.txt", clipboardText, FM_APPEND);
