local i;
local renderedGlyph;
local glyphPixels;

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

TtfSetSizes(ttf, 12, 12);
renderedGlyph = TextureCreate("rendered glyph texture", rtWidth, rtHeight);
glyphPixels = TtfRenderGlyph(ttf, 0xFF, 0x00, 0x00, 0x00000041);
TextureReceivePixels(renderedGlyph, glyphPixels);
for i = 0, 15, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedGlyph, 32, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureFree(renderedGlyph);
TtfSetSizes(ttf, 24, 24);
renderedGlyph = TextureCreate("rendered glyph texture", rtWidth, rtHeight);
glyphPixels = TtfRenderGlyph(ttf, 0xFF, 0x00, 0x00, 0x00000042);
TextureReceivePixels(renderedGlyph, glyphPixels);
for i = 0, 15, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedGlyph, 32, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureFree(renderedGlyph);
TtfSetSizes(ttf, 36, 36);
renderedGlyph = TextureCreate("rendered glyph texture", rtWidth, rtHeight);
glyphPixels = TtfRenderGlyph(ttf, 0xFF, 0x00, 0x00, 0x00000043);
TextureReceivePixels(renderedGlyph, glyphPixels);
for i = 0, 15, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedGlyph, 32, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureFree(renderedGlyph);
TtfSetSizes(ttf, 48, 48);
renderedGlyph = TextureCreate("rendered glyph texture", rtWidth, rtHeight);
glyphPixels = TtfRenderGlyph(ttf, 0xFF, 0x00, 0x00, 0x00000044);
TextureReceivePixels(renderedGlyph, glyphPixels);
for i = 0, 15, 1 do
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
