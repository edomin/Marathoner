local DMT_INFO = 0;
local i;
local quit = false;
local windowFlags = GUI_WINDOW_BORDER + GUI_WINDOW_MOVABLE +
 GUI_WINDOW_SCALABLE + GUI_WINDOW_CLOSABLE + GUI_WINDOW_MINIMIZABLE +
 GUI_WINDOW_TITLE + GUI_WINDOW_SCROLL_AUTO_HIDE;
local groupFlags = GUI_WINDOW_SCROLL_AUTO_HIDE;
local buttonAlignFlags = GUI_TEXT_ALIGN_CENTERED + GUI_TEXT_ALIGN_MIDDLE;
local labelAlignFlags = GUI_TEXT_ALIGN_LEFT + GUI_TEXT_ALIGN_MIDDLE;
local check_1 = false;
local check_2 = false;
local selectable_1 = false;
local selectable_2 = false;
local selectable_3 = false;
local selectable_4 = false;

local sbText = StringBufferAdd("Text Input", 16);
local sbInt = StringBufferAdd("42", 16);
local sbFloat = StringBufferAdd("3.14", 16);

local treeTabMax1 = false;
local treeTabMax2 = false;

-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

ScreenInit(640, 480, false, "GUI test");
TextureInit(IKDM_SMALL, 32);
PrimitiveInit();
TimerInit();
TtfInit(IKDM_SMALL, 32);
SpriteInit(IKDM_SMALL, 32);
FontInit(IKDM_SMALL, 32);
KeyboardInit();
MouseInit();

local mbf_big_00 = SpriteLoad("test/media/mbf_big_00.png", 10, 12, 16, 16, 256,
 0, 0);
local mbf_big_04 = SpriteLoad("test/media/mbf_big_04.png", 10, 12, 16, 16, 256,
 0, 0);
local mbf = FontCreate("MBF font", 5);
FontAddAtlas(mbf, mbf_big_00, 0);
FontAddAtlas(mbf, mbf_big_04, 4);
GuiInit(IKDM_SMALL, 32, IKDM_SMALL, 32, mbf);

local helicopter = TextureLoad("test/media/helicopter.png");
local guiCopter = GuiAddImage(helicopter, 0, 0, 96, 32);

while not quit do
    TimerStart();
    KeyboardRefresh();
    MouseRefresh();
    if KeyboardPress(KEY_ESCAPE) then
        quit = true;
    end;

    if GuiBegin("Intest Window", 100, 100, 320, 240, windowFlags) then
        GuiLayoutRowDynamic(30, 2);
        if GuiButtonText("B_Text", 6) then
            ShowSimpleMessageBox(DMT_INFO, "info", "GuiButtonText pressed");
        end;
        if GuiButtonLabel("B_Label") then
            ShowSimpleMessageBox(DMT_INFO, "info", "GuiButtonLabel pressed");
        end;

        GuiLayoutRowDynamic(30, 4);
        if GuiButtonColor_c(0xFF0000) then
            ShowSimpleMessageBox(DMT_INFO, "info", "GuiButtonColor_c pressed");
        end;
        if GuiButtonColor_ca(0x00FF00FF) then
            ShowSimpleMessageBox(DMT_INFO, "info", "GuiButtonColor_ca pressed");
        end;
        if GuiButtonColor_rgb(0x00, 0x00, 0xFF) then
            ShowSimpleMessageBox(DMT_INFO, "info",
             "GuiButtonColor_rgb pressed");
        end;
        if GuiButtonColor_rgba(0xFF, 0xFF, 0x00, 0xFF) then
            ShowSimpleMessageBox(DMT_INFO, "info",
             "GuiButtonColor_rgba pressed");
        end;

        GuiLayoutRowDynamic(30, 3);
        if GuiButtonSymbol(GUI_SYMBOL_X) then
            ShowSimpleMessageBox(DMT_INFO, "info", "GuiButtonSymbol pressed");
        end;
        if GuiButtonSymbolLabel(GUI_SYMBOL_CIRCLE_OUTLINE, "Sym",
         buttonAlignFlags) then
            ShowSimpleMessageBox(DMT_INFO, "info",
             "GuiButtonSymbolLabel pressed");
        end;
        if GuiButtonSymbolText(GUI_SYMBOL_TRIANGLE_RIGHT, "Sym", 3,
         buttonAlignFlags) then
            ShowSimpleMessageBox(DMT_INFO, "info",
             "GuiButtonSymbolText pressed");
        end;

        if GuiButtonImage(guiCopter) then
            ShowSimpleMessageBox(DMT_INFO, "info", "GuiButtonImage pressed");
        end;
        if GuiButtonImageLabel(guiCopter, "Img", buttonAlignFlags) then
            ShowSimpleMessageBox(DMT_INFO, "info",
             "GuiButtonImageLabel pressed");
        end;
        if GuiButtonImageText(guiCopter, "Img", 3, buttonAlignFlags) then
            ShowSimpleMessageBox(DMT_INFO, "info",
             "GuiButtonImageText pressed");
        end;

        GuiLayoutRowDynamic(30, 4);
        check_1 = GuiCheckLabel("Chk_1", check_1);
        GuiSpacing(2);
        check_2 = GuiCheckText("Chk_2", 5, check_2);

        GuiLayoutRowDynamic(30, 4);
        selectable_1 = GuiSelectableLabel("S_1", buttonAlignFlags,
         selectable_1);
        selectable_2 = GuiSelectableText("S_2", 3, buttonAlignFlags,
         selectable_2);
        selectable_3 = GuiSelectableImageLabel(guiCopter, "S_3",
         buttonAlignFlags, selectable_3);
        selectable_4 = GuiSelectableImageText(guiCopter, "S_4", 3,
         buttonAlignFlags, selectable_4);

        GuiLayoutRowDynamic(30, 1);
        GuiEditText(sbText);
        GuiEditInteger(sbInt);
        GuiEditFloat(sbFloat);

        if GuiTreeTabBegin("Labels", false) then
            GuiLayoutRowDynamic(30, 1);
            GuiLabel("Label_1", labelAlignFlags);
            GuiLabelColored_c("Label_2", labelAlignFlags, 0xFF0000);
            GuiLabelColored_ca("Label_3", labelAlignFlags, 0x00FF00FF);
            GuiLabelColored_rgb("Label_4", labelAlignFlags, 0x00, 0x00, 0xFF);
            GuiLabelColored_rgba("Label_5", labelAlignFlags, 0xFF, 0xFF, 0x00,
             0xFF);
            GuiTreeTabEnd();
        end;
        treeTabMax2 = GuiTreeTabBegin("Labels Wrapped", treeTabMax2);
        if treeTabMax2 then
            GuiLayoutRowStatic(40, 1, 200);
            GuiLabelWrap("First very very very very very long label",
             labelAlignFlags);
            GuiLabelColoredWrap_c("Second very very very very very long label",
             labelAlignFlags, 0xFF0000);
            GuiLabelColoredWrap_ca("Third very very very very very long label",
             labelAlignFlags, 0x00FF00FF);
            GuiLabelColoredWrap_rgb(
             "Fourth very very very very very long label", labelAlignFlags,
             0x00, 0x00, 0xFF);
            GuiLabelColoredWrap_rgba(
             "Fifth very very very very very long label", labelAlignFlags,
             0xFF, 0xFF, 0x00, 0xFF);
            GuiTreeTabEnd();
        end;

        GuiLayoutRowDynamic(128, 2);
        if GuiGroupBegin("Group_1", groupFlags) then
            GuiEditText(sbText);
            GuiEditInteger(sbInt);
            GuiEditFloat(sbFloat);
            GuiGroupEnd();
        end;
        if GuiGroupBegin("Group_2", groupFlags) then
            GuiEditText(sbText);
            GuiEditInteger(sbInt);
            GuiEditFloat(sbFloat);
            GuiGroupEnd();
        end;
    end;
    GuiEnd();

    GuiProcessEvents();
    PrimitiveFill_c(0x000000);
    GuiRender();
    ScreenFlip();
end;

GuiDeleteFont(1);
GuiDeleteImage(guiCopter);
GuiQuit();
FontFree(mbf);
TextureFree(mbf_big_00);
TextureFree(mbf_big_04);
TextureFree(helicopter);
StringBufferDelete(sbText);
StringBufferDelete(sbInt);
StringBufferDelete(sbFloat);
