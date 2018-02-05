local size;
local buffer;
-- Positive
FileWriteLineFast("test/output.txt", "Positive", FM_WRITE);
FileWriteFast("test/output.txt", "test", FM_APPEND);
FileWriteLineFast("test/output.txt", " ", FM_APPEND);

local file = FileOpen("test/output_2.txt", FM_WRITE);
FileWriteLine(file, "Hello");
FileWrite(file, "World");
FileClose(file);
file = FileOpen("test/output_2.txt", "FM_READ");
if file ~= 0 then
    FileWriteLineFast("test/output.txt", "File opened for read", FM_APPEND);
end;
buffer, size = FileRead(file);
FileWriteLineFast("test/output.txt", size, FM_APPEND);
FileWriteLineFast("test/output.txt", buffer, FM_APPEND);

if (FileExists("test/output.txt")) then
    FileWriteLineFast("test/output.txt", "File 'test/output.txt' exists",
     FM_APPEND);
else
    FileWriteLineFast("test/output.txt",
     "File 'test/output.txt' are not exists", FM_APPEND);
end;

if (FileExists("test/output_9000.txt")) then
    FileWriteLineFast("test/output.txt",
     "File 'test/output_9000.txt' exists", FM_APPEND);
else
    FileWriteLineFast("test/output.txt",
     "File 'test/output_9000.txt' are not exists", FM_APPEND);
end;

FileClose(file);
