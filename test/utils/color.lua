-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

local r = 0x44;
local g = 0x88;
local b = 0xCC;
local a = 0xFF;
local c = ColorAssembleRGB(r, g, b);
local ca = ColorAssembleRGBA(r, g, b, a);
FileWriteLineFast("test/output.txt", "c: " .. c, FM_APPEND);
FileWriteLineFast("test/output.txt", "ca: " .. ca, FM_APPEND);
r, g, b = ColorSplitRGB(c);
FileWriteLineFast("test/output.txt", "r: " .. r, FM_APPEND);
FileWriteLineFast("test/output.txt", "g: " .. g, FM_APPEND);
FileWriteLineFast("test/output.txt", "b: " .. b, FM_APPEND);
r = ColorRGBGetR(c);
g = ColorRGBGetG(c);
b = ColorRGBGetB(c);
FileWriteLineFast("test/output.txt", "r: " .. r, FM_APPEND);
FileWriteLineFast("test/output.txt", "g: " .. g, FM_APPEND);
FileWriteLineFast("test/output.txt", "b: " .. b, FM_APPEND);
r, g, b, a = ColorSplitRGBA(ca);
FileWriteLineFast("test/output.txt", "r: " .. r, FM_APPEND);
FileWriteLineFast("test/output.txt", "g: " .. g, FM_APPEND);
FileWriteLineFast("test/output.txt", "b: " .. b, FM_APPEND);
FileWriteLineFast("test/output.txt", "a: " .. a, FM_APPEND);
r = ColorRGBAGetR(ca);
g = ColorRGBAGetG(ca);
b = ColorRGBAGetB(ca);
a = ColorRGBAGetA(ca);
FileWriteLineFast("test/output.txt", "r: " .. r, FM_APPEND);
FileWriteLineFast("test/output.txt", "g: " .. g, FM_APPEND);
FileWriteLineFast("test/output.txt", "b: " .. b, FM_APPEND);
FileWriteLineFast("test/output.txt", "a: " .. a, FM_APPEND);
c = ColorRGBSetR(c, 0xFF);
c = ColorRGBSetG(c, 0xCC);
c = ColorRGBSetB(c, 0x88);
FileWriteLineFast("test/output.txt", "c: " .. c, FM_APPEND);
ca = ColorRGBASetR(ca, 0xFF);
ca = ColorRGBASetG(ca, 0xCC);
ca = ColorRGBASetB(ca, 0x88);
ca = ColorRGBASetA(ca, 0x44);
FileWriteLineFast("test/output.txt", "ca: " .. ca, FM_APPEND);
FileWriteLineFast("test/output.txt",
 "ColorRGBtoRGBA(c): " .. ColorRGBtoRGBA(c), FM_APPEND);
FileWriteLineFast("test/output.txt",
 "ColorRGBAtoRGB(ca): " .. ColorRGBAtoRGB(ca), FM_APPEND);
