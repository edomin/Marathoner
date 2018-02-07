local stdioAdded;
local stdioExtAdded;
local packedFile;
local fileText;

-- Positive
FileWriteFast("test/output.txt", "Outputing to log", FM_WRITE);
LogWrite("Positive test", 0, LMT_DEBUG);

PackageInit();
PackageMount("test/media/Hello.package", "/txt");

stdioAdded = FileSetStdioFuncs(PackageGetFopen(), PackageGetFclose(),
 PackageGetFeof(), PackageGetFtell(), PackageGetFseek(), PackageGetRewind(),
 PackageGetFread(), PackageGetFwrite(), PackageGetFprintf());
if stdioAdded then
    LogWrite("stdio funcs added", 0, LMT_DEBUG);
else
    LogWrite("stdio funcs are not added", 0, LMT_DEBUG);
end;

stdioExtAdded = FileSetStdioExtFuncs(PackageGetFreadable(),
 PackageGetFwritable());
if stdioExtAdded then
    LogWrite("stdio_ext funcs added", 0, LMT_DEBUG);
else
    LogWrite("stdio_ext funcs are not added", 0, LMT_DEBUG);
end;

packedFile = FileOpen("/txt/test.txt", FM_READ);
if packedFile == 0 then
    LogWrite("Unable to open file '/txt/test.txt'", 0, LMT_DEBUG);
    PackageUnmount("test/media/Hello.pak");
    PackageQuit();
    return;
end;

fileText = FileRead(packedFile);
FileClose(packedFile);

if fileText ~= nil then
    LogWrite("/txt/test.txt: " .. fileText, 0, LMT_DEBUG);
else
    LogWrite("Unable to read file /txt/test.txt", 0, LMT_DEBUG);
end;

PackageUnmount("test/media/Hello.pak");
PackageQuit();
