-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

local sb = StringBufferAdd("some text", 32);
if sb ~= 0 then
    local text;
    local maxlen;
    FileWriteLineFast("test/output.txt", "String buffer created", FM_APPEND);
    text = StringBufferGetString(sb);
    FileWriteLineFast("test/output.txt", text, FM_APPEND);
    StringBufferSetString(sb, "other some text");
    text = StringBufferGetString(sb);
    FileWriteLineFast("test/output.txt", text, FM_APPEND);
    maxlen = StringBufferGetMaxLen(sb);
    FileWriteLineFast("test/output.txt", "maxlen: " .. maxlen, FM_APPEND);
    StringBufferDelete(sb);
else
    FileWriteLineFast("test/output.txt", "String buffer not created",
     FM_APPEND);
end;
