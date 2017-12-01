local i;
local renderedGlyph;
local glyphPixels;
local ttfWidth;
local ttfHeight;
local glyphWidth;
local glyphHeight;

-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

ScreenInit(640, 480, false, "Font test");
TextureInit(IKDM_SMALL, 32);
TtfInit(IKDM_SMALL, 32);
PrimitiveInit();
TimerInit();

local ttf = TtfLoad("test/media/Vera.ttf");
if TtfSetSizes(ttf, 24, 24) then
    FileWriteLineFast("test/output.txt", "TTF size set", FM_APPEND);
else
    FileWriteLineFast("test/output.txt", "Unable to set TTF size", FM_APPEND);
end;
ttfWidth, ttfHeight = TtfGetSizes(ttf);
FileWriteLineFast("test/output.txt", "ttfWidth: " .. ttfWidth, FM_APPEND);
FileWriteLineFast("test/output.txt", "ttfHeight: " .. ttfHeight, FM_APPEND);
FileWriteLineFast("test/output.txt", "TtfGetWidth(ttf): " .. TtfGetWidth(ttf),
 FM_APPEND);
FileWriteLineFast("test/output.txt", "TtfGetHeight(ttf): " .. TtfGetHeight(ttf),
 FM_APPEND);

glyphWidth, glyphHeight = TtfGetGlyphSizes(ttf, 0x00000041);
FileWriteLineFast("test/output.txt", "glyphWidth: " .. glyphWidth, FM_APPEND);
FileWriteLineFast("test/output.txt", "glyphHeight: " .. glyphHeight, FM_APPEND);
FileWriteLineFast("test/output.txt",
 "TtfGetGlyphWidth(ttf, 0x00000041): " .. TtfGetGlyphWidth(ttf, 0x00000041),
 FM_APPEND);
FileWriteLineFast("test/output.txt",
 "TtfGetGlyphHeight(ttf, 0x00000041): " .. TtfGetGlyphHeight(ttf, 0x00000041),
 FM_APPEND);

TtfSetSizes(ttf, 12, 12);
glyphPixels = TtfRenderGlyph(ttf, 0xFF, 0x00, 0x00, 0x00000041);
glyphWidth, glyphHeight = TtfGetGlyphSizes(ttf, 0x00000041);
renderedGlyph = TextureCreate("rendered glyph texture", glyphWidth,
 glyphHeight);
TextureReceivePixels(renderedGlyph, glyphPixels);
for i = 0, 30, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedGlyph, 32, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TtfSetSizes(ttf, 24, 24);
glyphPixels = TtfRenderGlyph(ttf, 0xFF, 0x00, 0x00, 0x00000041);
glyphWidth, glyphHeight = TtfGetGlyphSizes(ttf, 0x00000041);
renderedGlyph = TextureCreate("rendered glyph texture", glyphWidth,
 glyphHeight);
TextureReceivePixels(renderedGlyph, glyphPixels);
for i = 0, 30, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedGlyph, 32, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TtfSetSizes(ttf, 36, 36);
glyphPixels = TtfRenderGlyph(ttf, 0xFF, 0x00, 0x00, 0x00000041);
glyphWidth, glyphHeight = TtfGetGlyphSizes(ttf, 0x00000041);
renderedGlyph = TextureCreate("rendered glyph texture", glyphWidth,
 glyphHeight);
TextureReceivePixels(renderedGlyph, glyphPixels);
for i = 0, 30, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedGlyph, 32, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TtfSetSizes(ttf, 48, 48);
glyphPixels = TtfRenderGlyph(ttf, 0xFF, 0x00, 0x00, 0x00000041);
glyphWidth, glyphHeight = TtfGetGlyphSizes(ttf, 0x00000041);
renderedGlyph = TextureCreate("rendered glyph texture", glyphWidth,
 glyphHeight);
TextureReceivePixels(renderedGlyph, glyphPixels);
for i = 0, 30, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedGlyph, 32, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureFree(renderedGlyph);
TtfFree(ttf);
TtfQuit();
ScreenQuit();
