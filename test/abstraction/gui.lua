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

local windowTitle = "Intest Window";
local guiButtonText = "B_Text";
local guiButtonLabel = "B_Label";
local guiButtonSymbolLabel = "Sym";
local guiButtonImageLabel = "Img";
local guiCheckLabel = "Chk_1";
local guiCheckText = "Chk_2";
local guiSelectableLabel = "S_1";
local guiSelectableText = "S_2";
local guiSelectableImageLabel = "S_3";
local guiSelectableImageText = "S_4";
local guiTreeTabLabels = "Labels";
local guiLabel1 = "Label_1";
local guiLabel2 = "Label_2";
local guiLabel3 = "Label_3";
local guiLabel4 = "Label_4";
local guiLabel5 = "Label_5";
local guiTreeTabLabelsWrapped = "Labels Wrapped";
local guiLabelWrapped1 = "First very very very very very long label";
local guiLabelWrapped2 = "Second very very very very very long label";
local guiLabelWrapped3 = "Third very very very very very long label";
local guiLabelWrapped4 = "Fourth very very very very very long label";
local guiLabelWrapped5 = "Fifth very very very very very long label";
local guiGroup1 = "Group_1";
local guiGroup2 = "Group_2";

while not quit do
    TimerStart();
    KeyboardRefresh();
    MouseRefresh();
    if KeyboardPress(KEY_ESCAPE) then
        quit = true;
    end;

    if GuiBegin(windowTitle, 100, 100, 320, 240, windowFlags) then
        GuiLayoutRowDynamic(30, 2);
        if GuiButtonText(guiButtonText, 6) then
            ShowSimpleMessageBox(DMT_INFO, "info", "GuiButtonText pressed");
        end;
        if GuiButtonLabel(guiButtonLabel) then
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
        if GuiButtonSymbolLabel(GUI_SYMBOL_CIRCLE_OUTLINE, guiButtonSymbolLabel,
         buttonAlignFlags) then
            ShowSimpleMessageBox(DMT_INFO, "info",
             "GuiButtonSymbolLabel pressed");
        end;
        if GuiButtonSymbolText(GUI_SYMBOL_TRIANGLE_RIGHT, guiButtonSymbolLabel, 3,
         buttonAlignFlags) then
            ShowSimpleMessageBox(DMT_INFO, "info",
             "GuiButtonSymbolText pressed");
        end;

        if GuiButtonImage(guiCopter) then
            ShowSimpleMessageBox(DMT_INFO, "info", "GuiButtonImage pressed");
        end;
        if GuiButtonImageLabel(guiCopter, guiButtonImageLabel, buttonAlignFlags) then
            ShowSimpleMessageBox(DMT_INFO, "info",
             "GuiButtonImageLabel pressed");
        end;
        if GuiButtonImageText(guiCopter, guiButtonImageLabel, 3, buttonAlignFlags) then
            ShowSimpleMessageBox(DMT_INFO, "info",
             "GuiButtonImageText pressed");
        end;

        GuiLayoutRowDynamic(30, 4);
        check_1 = GuiCheckLabel(guiCheckLabel, check_1);
        GuiSpacing(2);
        check_2 = GuiCheckText(guiCheckText, 5, check_2);

        GuiLayoutRowDynamic(30, 4);
        selectable_1 = GuiSelectableLabel(guiSelectableLabel, buttonAlignFlags,
         selectable_1);
        selectable_2 = GuiSelectableText(guiSelectableText, 3, buttonAlignFlags,
         selectable_2);
        selectable_3 = GuiSelectableImageLabel(guiCopter, guiSelectableImageLabel,
         buttonAlignFlags, selectable_3);
        selectable_4 = GuiSelectableImageText(guiCopter, guiSelectableImageText, 3,
         buttonAlignFlags, selectable_4);

        GuiLayoutRowDynamic(30, 1);
        GuiEditText(sbText);
        GuiEditInteger(sbInt);
        GuiEditFloat(sbFloat);

        if GuiTreeTabBegin(guiTreeTabLabels, false) then
            GuiLayoutRowDynamic(30, 1);
            GuiLabel(guiLabel1, labelAlignFlags);
            GuiLabelColored_c(guiLabel2, labelAlignFlags, 0xFF0000);
            GuiLabelColored_ca(guiLabel3, labelAlignFlags, 0x00FF00FF);
            GuiLabelColored_rgb(guiLabel4, labelAlignFlags, 0x00, 0x00, 0xFF);
            GuiLabelColored_rgba(guiLabel5, labelAlignFlags, 0xFF, 0xFF, 0x00,
             0xFF);
            GuiTreeTabEnd();
        end;
        treeTabMax2 = GuiTreeTabBegin(guiTreeTabLabelsWrapped, treeTabMax2);
        if treeTabMax2 then
            GuiLayoutRowStatic(40, 1, 200);
            GuiLabelWrap(guiLabelWrapped1,
             labelAlignFlags);
            GuiLabelColoredWrap_c(guiLabelWrapped2,
             labelAlignFlags, 0xFF0000);
            GuiLabelColoredWrap_ca(guiLabelWrapped3,
             labelAlignFlags, 0x00FF00FF);
            GuiLabelColoredWrap_rgb(
             guiLabelWrapped4, labelAlignFlags,
             0x00, 0x00, 0xFF);
            GuiLabelColoredWrap_rgba(
             guiLabelWrapped5, labelAlignFlags,
             0xFF, 0xFF, 0x00, 0xFF);
            GuiTreeTabEnd();
        end;

        GuiLayoutRowDynamic(128, 2);
        if GuiGroupBegin(guiGroup1, groupFlags) then
            GuiEditText(sbText);
            GuiEditInteger(sbInt);
            GuiEditFloat(sbFloat);
            GuiGroupEnd();
        end;
        if GuiGroupBegin(guiGroup2, groupFlags) then
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
