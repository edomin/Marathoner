-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

local currentDirectory = GetCurrentDirectory();
FileWriteLineFast("test/output.txt", currentDirectory, FM_APPEND);
