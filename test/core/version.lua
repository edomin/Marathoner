-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);
local ver = MarathonerGetVersion();
local majorMasked = bit32.band(ver, 0xFF0000);
local minorMasked = bit32.band(ver, 0x00FF00);
local patchMasked = bit32.band(ver, 0x0000FF);
local major = bit32.rshift(majorMasked, 16);
local minor = bit32.rshift(minorMasked, 8);
local patch = patchMasked;
FileWriteLineFast("test/output.txt", "Marathoner version major: " .. major,
 FM_APPEND);
FileWriteLineFast("test/output.txt", "Marathoner version minor: " .. minor,
 FM_APPEND);
FileWriteLineFast("test/output.txt", "Marathoner version patch: " .. patch,
 FM_APPEND);

local ver = MarathonerGetModuleVersion("Script_Lua");
local majorMasked = bit32.band(ver, 0xFF0000);
local minorMasked = bit32.band(ver, 0x00FF00);
local patchMasked = bit32.band(ver, 0x0000FF);
local major = bit32.rshift(majorMasked, 16);
local minor = bit32.rshift(minorMasked, 8);
local patch = patchMasked;
FileWriteLineFast("test/output.txt", "Script_Lua module version major: " ..
 major, FM_APPEND);
FileWriteLineFast("test/output.txt", "Script_Lua module version minor: " ..
 minor, FM_APPEND);
FileWriteLineFast("test/output.txt", "Script_Lua module version patch: " ..
 patch, FM_APPEND);
