local i;

-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

ScreenInit(640, 480, false, "Font test");
TextureInit(IKDM_SMALL, 32);
TtfInit(IKDM_SMALL, 32);
PrimitiveInit();
TimerInit();

local ttf = TtfLoad("test/media/Vera.ttf", 24);
if TtfSetSizes(ttf, 24, 24) then
    FileWriteLineFast("test/output.txt", "TTF size set", FM_APPEND);
else
    FileWriteLineFast("test/output.txt", "Unable to set TTF size", FM_APPEND);
end;
local rtWidth = TtfGetStringWidth(ttf, "Hello World");
local rtHeight = TtfGetFontHeight(ttf);
FileWriteLineFast("test/output.txt", "rtWidth: " .. rtWidth, FM_APPEND);
FileWriteLineFast("test/output.txt", "rtHeight: " .. rtHeight, FM_APPEND);
rtWidth, trHeight = TtfGetStringSizes(ttf, "Hello World");
FileWriteLineFast("test/output.txt", "rtWidth: " .. rtWidth, FM_APPEND);
FileWriteLineFast("test/output.txt", "rtHeight: " .. rtHeight, FM_APPEND);

local renderedText = TextureCreate("rendered text texture", rtWidth, rtHeight);
local textPixels = TtfRenderString(ttf, 0xFF, 0x00, 0x00, "Hello World");
TextureReceivePixels(renderedText, textPixels);
for i = 0, 60, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedText, 32, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureFree(renderedText);
TtfSetFontOutline(ttf, 4);
rtWidth = TtfGetStringWidth(ttf, "Hello World");
rtHeight = TtfGetFontHeight(ttf);
renderedText = TextureCreate("rendered text texture", rtWidth, rtHeight);
textPixels = TtfRenderString(ttf, 0xFF, 0x00, 0x00, "Hello World");
TextureReceivePixels(renderedText, textPixels);
for i = 0, 60, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedText, 32, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureFree(renderedText);
TtfSetFontOutline(ttf, 0);
TtfSetFontStyle(ttf, FS_BOLD);
rtWidth = TtfGetStringWidth(ttf, "Hello World");
rtHeight = TtfGetFontHeight(ttf);
renderedText = TextureCreate("rendered text texture", rtWidth, rtHeight);
textPixels = TtfRenderString(ttf, 0xFF, 0x00, 0x00, "Hello World");
TextureReceivePixels(renderedText, textPixels);
for i = 0, 60, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedText, 32, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureFree(renderedText);
TtfSetFontStyle(ttf, FS_ITALIC);
rtWidth = TtfGetStringWidth(ttf, "Hello World");
rtHeight = TtfGetFontHeight(ttf);
renderedText = TextureCreate("rendered text texture", rtWidth, rtHeight);
textPixels = TtfRenderString(ttf, 0xFF, 0x00, 0x00, "Hello World");
TextureReceivePixels(renderedText, textPixels);
for i = 0, 60, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedText, 32, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureFree(renderedText);
TtfSetFontStyle(ttf, FS_UNDERLINE);
rtWidth = TtfGetStringWidth(ttf, "Hello World");
rtHeight = TtfGetFontHeight(ttf);
renderedText = TextureCreate("rendered text texture", rtWidth, rtHeight);
textPixels = TtfRenderString(ttf, 0xFF, 0x00, 0x00, "Hello World");
TextureReceivePixels(renderedText, textPixels);
for i = 0, 60, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedText, 32, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureFree(renderedText);
TtfSetFontStyle(ttf, FS_STRIKETHROUGH);
rtWidth = TtfGetStringWidth(ttf, "Hello World");
rtHeight = TtfGetFontHeight(ttf);
renderedText = TextureCreate("rendered text texture", rtWidth, rtHeight);
textPixels = TtfRenderString(ttf, 0xFF, 0x00, 0x00, "Hello World");
TextureReceivePixels(renderedText, textPixels);
for i = 0, 60, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedText, 32, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureFree(renderedText);
TtfSetStyle(ttf, FS_NORMAL);
TtfSetSizes(ttf, 12, 12);
rtWidth = TtfGetStringWidth(ttf, "Hello World");
rtHeight = TtfGetHeight(ttf);
renderedText = TextureCreate("rendered text texture", rtWidth, rtHeight);
textPixels = TtfRenderString(ttf, 0xFF, 0x00, 0x00, "Hello World");
TextureReceivePixels(renderedText, textPixels);
for i = 0, 15, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedText, 32, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureFree(renderedText);
TtfSetSizes(ttf, 24, 24);
rtWidth = TtfGetStringWidth(ttf, "Hello World");
rtHeight = TtfGetHeight(ttf);
renderedText = TextureCreate("rendered text texture", rtWidth, rtHeight);
textPixels = TtfRenderString(ttf, 0xFF, 0x00, 0x00, "Hello World");
TextureReceivePixels(renderedText, textPixels);
for i = 0, 15, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedText, 32, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureFree(renderedText);
TtfSetSizes(ttf, 36, 36);
rtWidth = TtfGetStringWidth(ttf, "Hello World");
rtHeight = TtfGetHeight(ttf);
renderedText = TextureCreate("rendered text texture", rtWidth, rtHeight);
textPixels = TtfRenderString(ttf, 0xFF, 0x00, 0x00, "Hello World");
TextureReceivePixels(renderedText, textPixels);
for i = 0, 15, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedText, 32, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureFree(renderedText);
TtfSetSizes(ttf, 48, 48);
rtWidth = TtfGetStringWidth(ttf, "Hello World");
rtHeight = TtfGetHeight(ttf);
renderedText = TextureCreate("rendered text texture", rtWidth, rtHeight);
textPixels = TtfRenderString(ttf, 0xFF, 0x00, 0x00, "Hello World");
TextureReceivePixels(renderedText, textPixels);
for i = 0, 15, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedText, 32, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureFree(renderedText);
TtfSetSizes(ttf, 48, 48);
rtWidth = TtfGetGlyphWidth(ttf, 0x00000041);
rtHeight = TtfGetHeight(ttf);
renderedText = TextureCreate("rendered glyph texture", rtWidth, rtHeight);
textPixels = TtfRenderGlyph(ttf, 0xFF, 0x00, 0x00, 0x00000041);
TextureReceivePixels(renderedText, textPixels);
FileWriteLineFast("test/output.txt", "rtWidth: " .. rtWidth, FM_APPEND);
FileWriteLineFast("test/output.txt",
 "TextureGetWidth(renderedText): " .. TextureGetWidth(renderedText), FM_APPEND);
for i = 0, 15, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedText, 32, 32);
    PrimitiveRectangle_c_f(32, 32, 32 + rtWidth, 32 + rtHeight, 0x0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureFree(renderedText);
TtfSetSizes(ttf, 48, 48);
rtWidth = TtfGetGlyphWidth(ttf, 0x00000042);
rtHeight = TtfGetHeight(ttf);
renderedText = TextureCreate("rendered glyph texture", rtWidth, rtHeight);
textPixels = TtfRenderGlyph(ttf, 0xFF, 0x00, 0x00, 0x00000042);
TextureReceivePixels(renderedText, textPixels);
FileWriteLineFast("test/output.txt", "rtWidth: " .. rtWidth, FM_APPEND);
FileWriteLineFast("test/output.txt",
 "TextureGetWidth(renderedText): " .. TextureGetWidth(renderedText), FM_APPEND);
for i = 0, 15, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedText, 32, 32);
    PrimitiveRectangle_c_f(32, 32, 32 + rtWidth, 32 + rtHeight, 0x0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureFree(renderedText);
TtfSetSizes(ttf, 48, 48);
rtWidth = TtfGetGlyphWidth(ttf, 0x00000043);
rtHeight = TtfGetHeight(ttf);
renderedText = TextureCreate("rendered glyph texture", rtWidth, rtHeight);
textPixels = TtfRenderGlyph(ttf, 0xFF, 0x00, 0x00, 0x00000043);
TextureReceivePixels(renderedText, textPixels);
FileWriteLineFast("test/output.txt", "rtWidth: " .. rtWidth, FM_APPEND);
FileWriteLineFast("test/output.txt",
 "TextureGetWidth(renderedText): " .. TextureGetWidth(renderedText), FM_APPEND);
for i = 0, 15, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedText, 32, 32);
    PrimitiveRectangle_c_f(32, 32, 32 + rtWidth, 32 + rtHeight, 0x0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureFree(renderedText);
TtfSetSizes(ttf, 48, 48);
rtWidth = TtfGetGlyphWidth(ttf, 0x00000044);
rtHeight = TtfGetHeight(ttf);
renderedText = TextureCreate("rendered glyph texture", rtWidth, rtHeight);
textPixels = TtfRenderGlyph(ttf, 0xFF, 0x00, 0x00, 0x00000044);
TextureReceivePixels(renderedText, textPixels);
FileWriteLineFast("test/output.txt", "rtWidth: " .. rtWidth, FM_APPEND);
FileWriteLineFast("test/output.txt",
 "TextureGetWidth(renderedText): " .. TextureGetWidth(renderedText), FM_APPEND);
for i = 0, 15, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedText, 32, 32);
    PrimitiveRectangle_c_f(32, 32, 32 + rtWidth, 32 + rtHeight, 0x0000FF);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureFree(renderedText);
TtfFree(ttf);
TtfQuit();
ScreenQuit();
