-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(GuiInit, "mtrGuiInit", GuiFunctionSupported);
fa.FunctionSupported(GuiQuit, "mtrGuiQuit", GuiFunctionSupported);
fa.FunctionSupported(GuiProcessEvents, "mtrGuiProcessEvents",
 GuiFunctionSupported);
fa.FunctionSupported(GuiRender, "mtrGuiRender", GuiFunctionSupported);
fa.FunctionSupported(GuiAddFont, "mtrGuiAddFont", GuiFunctionSupported);
fa.FunctionSupported(GuiAddImage, "mtrGuiAddImage", GuiFunctionSupported);
fa.FunctionSupported(GuiDeleteFont, "mtrGuiDeleteFont", GuiFunctionSupported);
fa.FunctionSupported(GuiDeleteImage, "mtrGuiDeleteImage", GuiFunctionSupported);
fa.FunctionSupported(GuiBegin, "mtrGuiBegin", GuiFunctionSupported);
fa.FunctionSupported(GuiEnd, "mtrGuiEnd", GuiFunctionSupported);
fa.FunctionSupported(GuiButtonText, "mtrGuiButtonText", GuiFunctionSupported);
fa.FunctionSupported(GuiButtonLabel, "mtrGuiButtonLabel", GuiFunctionSupported);
fa.FunctionSupported(GuiButtonColor_c, "mtrGuiButtonColor_c",
 GuiFunctionSupported);
fa.FunctionSupported(GuiButtonColor_ca, "mtrGuiButtonColor_ca",
 GuiFunctionSupported);
fa.FunctionSupported(GuiButtonColor_rgb, "mtrGuiButtonColor_rgb",
 GuiFunctionSupported);
fa.FunctionSupported(GuiButtonColor_rgba, "mtrGuiButtonColor_rgba",
 GuiFunctionSupported);
fa.FunctionSupported(GuiButtonSymbol, "mtrGuiButtonSymbol",
 GuiFunctionSupported);
fa.FunctionSupported(GuiButtonSymbolLabel, "mtrGuiButtonSymbolLabel",
 GuiFunctionSupported);
fa.FunctionSupported(GuiButtonSymbolText, "mtrGuiButtonSymbolText",
 GuiFunctionSupported);
fa.FunctionSupported(GuiButtonImage, "mtrGuiButtonImage", GuiFunctionSupported);
fa.FunctionSupported(GuiButtonImageLabel, "mtrGuiButtonImageLabel",
 GuiFunctionSupported);
fa.FunctionSupported(GuiButtonImageText, "mtrGuiButtonImageText",
 GuiFunctionSupported);
fa.FunctionSupported(GuiCheckLabel, "mtrGuiCheckLabel", GuiFunctionSupported);
fa.FunctionSupported(GuiCheckText, "mtrGuiCheckText", GuiFunctionSupported);
fa.FunctionSupported(GuiSelectableLabel, "mtrGuiSelectableLabel",
 GuiFunctionSupported);
fa.FunctionSupported(GuiSelectableText, "mtrGuiSelectableText",
 GuiFunctionSupported);
fa.FunctionSupported(GuiSelectableImageLabel, "mtrGuiSelectableImageLabel",
 GuiFunctionSupported);
fa.FunctionSupported(GuiSelectableImageText, "mtrGuiSelectableImageText",
 GuiFunctionSupported);
fa.FunctionSupported(GuiEditText, "mtrGuiEditText", GuiFunctionSupported);
fa.FunctionSupported(GuiEditInteger, "mtrGuiEditInteger", GuiFunctionSupported);
fa.FunctionSupported(GuiEditFloat, "mtrGuiEditFloat", GuiFunctionSupported);
fa.FunctionSupported(GuiLabel, "mtrGuiLabel", GuiFunctionSupported);
fa.FunctionSupported(GuiLabelColored_c, "mtrGuiLabelColored_c",
 GuiFunctionSupported);
fa.FunctionSupported(GuiLabelColored_ca, "mtrGuiLabelColored_ca",
 GuiFunctionSupported);
fa.FunctionSupported(GuiLabelColored_rgb, "mtrGuiLabelColored_rgb",
 GuiFunctionSupported);
fa.FunctionSupported(GuiLabelColored_rgba, "mtrGuiLabelColored_rgba",
 GuiFunctionSupported);
fa.FunctionSupported(GuiLabelWrap, "mtrGuiLabelWrap", GuiFunctionSupported);
fa.FunctionSupported(GuiLabelColoredWrap_c, "mtrGuiLabelColoredWrap_c",
 GuiFunctionSupported);
fa.FunctionSupported(GuiLabelColoredWrap_ca, "mtrGuiLabelColoredWrap_ca",
 GuiFunctionSupported);
fa.FunctionSupported(GuiLabelColoredWrap_rgb, "mtrGuiLabelColoredWrap_rgb",
 GuiFunctionSupported);
fa.FunctionSupported(GuiLabelColoredWrap_rgba, "mtrGuiLabelColoredWrap_rgba",
 GuiFunctionSupported);
fa.FunctionSupported(GuiTreeTabBegin, "mtrGuiTreeTabBegin",
 GuiFunctionSupported);
fa.FunctionSupported(GuiTreeTabEnd, "mtrGuiTreeTabEnd", GuiFunctionSupported);
fa.FunctionSupported(GuiLayoutRowDynamic, "mtrGuiLayoutRowDynamic",
 GuiFunctionSupported);
fa.FunctionSupported(GuiLayoutRowStatic, "mtrGuiLayoutRowStatic",
 GuiFunctionSupported);
fa.FunctionSupported(GuiGroupBegin, "mtrGuiGroupBegin", GuiFunctionSupported);
fa.FunctionSupported(GuiGroupEnd, "mtrGuiGroupEnd", GuiFunctionSupported);
fa.FunctionSupported(GuiSpacing, "mtrGuiSpacing", GuiFunctionSupported);
