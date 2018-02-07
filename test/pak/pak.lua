local stdioAdded;
local stdioExtAdded;
local packedFile;
local fileText;

-- Positive
FileWriteFast("test/output.txt", "Outputing to log", FM_WRITE);
LogWrite("Positive test", 0, LMT_DEBUG);

PakInit();
PakMount("test/media/Hello.pak", "/txt");

stdioAdded = FileSetStdioFuncs(PakGetFopen(), PakGetFclose(), PakGetFeof(),
 PakGetFtell(), PakGetFseek(), PakGetRewind(), PakGetFread(), PakGetFwrite(),
 PakGetFprintf());
if stdioAdded then
    LogWrite("stdio funcs added", 0, LMT_DEBUG);
else
    LogWrite("stdio funcs are not added", 0, LMT_DEBUG);
end;

stdioExtAdded = FileSetStdioExtFuncs(PakGetFreadable(), PakGetFwritable());
if stdioExtAdded then
    LogWrite("stdio_ext funcs added", 0, LMT_DEBUG);
else
    LogWrite("stdio_ext funcs are not added", 0, LMT_DEBUG);
end;

packedFile = FileOpen("/txt/test.txt", FM_READ);
if packedFile == 0 then
    LogWrite("Unable to open file '/txt/test.txt'", 0, LMT_DEBUG);
    PakUnmount("test/media/Hello.pak");
    PakQuit();
    return;
end;

fileText = FileRead(packedFile);
FileClose(packedFile);

if fileText ~= nil then
    LogWrite("/txt/test.txt: " .. fileText, 0, LMT_DEBUG);
else
    LogWrite("Unable to read file /txt/test.txt", 0, LMT_DEBUG);
end;

PakUnmount("test/media/Hello.pak");
PakQuit();
