local i;

-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

ScreenInit(640, 480, false, "Font test");
TextureInit(IKDM_SMALL, 32);
TtfInit(IKDM_SMALL, 32);
PrimitiveInit();
TimerInit();

local ttf = TtfLoad("test/media/Vera.ttf", 24);
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
TtfFree(ttf);
TtfQuit();
ScreenQuit();
