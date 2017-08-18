local i;

-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

ScreenInit(640, 480, false, "Font test");
TextureInit(IKDM_SMALL, 32);
TtfInit(IKDM_SMALL, 32);
PrimitiveInit();
TimerInit();
FontInit(IKDM_SMALL, 32);

local ttf = FontLoadTtf("test/media/Vera.ttf", 24);
local rtWidth = FontGetStringWidth(ttf, "Hello World");
local rtHeight = FontGetHeight(ttf);
local renderedText = TextureCreate("rendered text texture", rtWidth, rtHeight);
FontRenderTtfString(ttf, renderedText, 0xFF, 0x00, 0x00, "Hello World");
for i = 0, 60, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedText, 32, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureFree(renderedText);
FontSetTtfOutline(ttf, 4);
rtWidth = FontGetStringWidth(ttf, "Hello World");
rtHeight = FontGetHeight(ttf);
renderedText = TextureCreate("rendered text texture", rtWidth, rtHeight);
FontRenderTtfString(ttf, renderedText, 0xFF, 0x00, 0x00, "Hello World");
for i = 0, 60, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedText, 32, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureFree(renderedText);
FontSetTtfOutline(ttf, 0);
FontSetTtfStyle(ttf, FS_BOLD);
rtWidth = FontGetStringWidth(ttf, "Hello World");
rtHeight = FontGetHeight(ttf);
renderedText = TextureCreate("rendered text texture", rtWidth, rtHeight);
FontRenderTtfString(ttf, renderedText, 0xFF, 0x00, 0x00, "Hello World");
for i = 0, 60, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedText, 32, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureFree(renderedText);
FontSetTtfStyle(ttf, FS_ITALIC);
rtWidth = FontGetStringWidth(ttf, "Hello World");
rtHeight = FontGetHeight(ttf);
renderedText = TextureCreate("rendered text texture", rtWidth, rtHeight);
FontRenderTtfString(ttf, renderedText, 0xFF, 0x00, 0x00, "Hello World");
for i = 0, 60, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedText, 32, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureFree(renderedText);
FontSetTtfStyle(ttf, FS_UNDERLINE);
rtWidth = FontGetStringWidth(ttf, "Hello World");
rtHeight = FontGetHeight(ttf);
renderedText = TextureCreate("rendered text texture", rtWidth, rtHeight);
FontRenderTtfString(ttf, renderedText, 0xFF, 0x00, 0x00, "Hello World");
for i = 0, 60, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedText, 32, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureFree(renderedText);
FontSetTtfStyle(ttf, FS_STRIKETHROUGH);
rtWidth = FontGetStringWidth(ttf, "Hello World");
rtHeight = FontGetHeight(ttf);
renderedText = TextureCreate("rendered text texture", rtWidth, rtHeight);
FontRenderTtfString(ttf, renderedText, 0xFF, 0x00, 0x00, "Hello World");
for i = 0, 60, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    TextureBlit_f(renderedText, 32, 32);
    ScreenFlip();
    TimerDelayForFPS(30);
end;

TextureFree(renderedText);
FontFree(ttf);

local mbf_big_00 = TextureLoad("test/media/mbf_big_00.png");
local mbf_big_04 = TextureLoad("test/media/mbf_big_04.png");
local mbf = FontCreateMbf("MBF font", 5, 10, 12);
FontAddMbfTextureTable(mbf, mbf_big_00, 0);
FontAddMbfTextureTable(mbf, mbf_big_04, 4);
for i = 0, 60, 1 do
    TimerStart();
    PrimitiveFill_c(0x000000);
    FontDrawMbfString_f(mbf, 32, 32, "Hello World");
    FontDrawMbfString_f(mbf, 32, 64, "Привет мир");
    ScreenFlip();
    TimerDelayForFPS(30);
end;
FontFree(mbf);
TextureFree(mbf_big_00);
TextureFree(mbf_big_04);