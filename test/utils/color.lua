-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

local r = 0x44;
local g = 0x88;
local b = 0xCC;
local a = 0xFF;
local c = ColorRgbAssemble(r, g, b);
local ca = ColorRgbAssemble(r, g, b, a);
FileWriteLineFast("test/output.txt", "c: " .. c, FM_APPEND);
FileWriteLineFast("test/output.txt", "ca: " .. ca, FM_APPEND);
r, g, b = ColorRgbSplit(c);
FileWriteLineFast("test/output.txt", "r: " .. r, FM_APPEND);
FileWriteLineFast("test/output.txt", "g: " .. g, FM_APPEND);
FileWriteLineFast("test/output.txt", "b: " .. b, FM_APPEND);
r = ColorRgbGetRed(c);
g = ColorRgbGetGreen(c);
b = ColorRgbGetBlue(c);
FileWriteLineFast("test/output.txt", "r: " .. r, FM_APPEND);
FileWriteLineFast("test/output.txt", "g: " .. g, FM_APPEND);
FileWriteLineFast("test/output.txt", "b: " .. b, FM_APPEND);
r, g, b, a = ColorRgbaSplit(ca);
FileWriteLineFast("test/output.txt", "r: " .. r, FM_APPEND);
FileWriteLineFast("test/output.txt", "g: " .. g, FM_APPEND);
FileWriteLineFast("test/output.txt", "b: " .. b, FM_APPEND);
FileWriteLineFast("test/output.txt", "a: " .. a, FM_APPEND);
r = ColorRgbaGetRed(ca);
g = ColorRgbaGetGreen(ca);
b = ColorRgbaGetBlue(ca);
a = ColorRgbaGetAlpha(ca);
FileWriteLineFast("test/output.txt", "r: " .. r, FM_APPEND);
FileWriteLineFast("test/output.txt", "g: " .. g, FM_APPEND);
FileWriteLineFast("test/output.txt", "b: " .. b, FM_APPEND);
FileWriteLineFast("test/output.txt", "a: " .. a, FM_APPEND);
c = ColorRgbSetRed(c, 0xFF);
c = ColorRgbSetGreen(c, 0xCC);
c = ColorRgbSetBlue(c, 0x88);
FileWriteLineFast("test/output.txt", "c: " .. c, FM_APPEND);
ca = ColorRgbaSetRed(ca, 0xFF);
ca = ColorRgbaSetGreen(ca, 0xCC);
ca = ColorRgbaSetBlue(ca, 0x88);
ca = ColorRgbaSetAlpha(ca, 0x44);
FileWriteLineFast("test/output.txt", "ca: " .. ca, FM_APPEND);
FileWriteLineFast("test/output.txt",
 "ColorRgbToRgba(c): " .. ColorRgbToRgba(c), FM_APPEND);
FileWriteLineFast("test/output.txt",
 "ColorRgbaToRgb(ca): " .. ColorRgbaToRgb(ca), FM_APPEND);
