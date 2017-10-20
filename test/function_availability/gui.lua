-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(GuiInit, "MTR_GuiInit", GuiFunctionSupported);
fa.FunctionSupported(GuiQuit, "MTR_GuiQuit", GuiFunctionSupported);
fa.FunctionSupported(GuiProcessEvents, "MTR_GuiProcessEvents",
 GuiFunctionSupported);
fa.FunctionSupported(GuiRender, "MTR_GuiRender", GuiFunctionSupported);
fa.FunctionSupported(GuiAddFont, "MTR_GuiAddFont", GuiFunctionSupported);
fa.FunctionSupported(GuiAddImage, "MTR_GuiAddImage", GuiFunctionSupported);
fa.FunctionSupported(GuiDeleteFont, "MTR_GuiDeleteFont", GuiFunctionSupported);
fa.FunctionSupported(GuiDeleteImage, "MTR_GuiDeleteImage",
 GuiFunctionSupported);
fa.FunctionSupported(GuiBegin, "MTR_GuiBegin", GuiFunctionSupported);
fa.FunctionSupported(GuiEnd, "MTR_GuiEnd", GuiFunctionSupported);
fa.FunctionSupported(GuiButtonText, "MTR_GuiButtonText", GuiFunctionSupported);
fa.FunctionSupported(GuiButtonLabel, "MTR_GuiButtonLabel",
 GuiFunctionSupported);
fa.FunctionSupported(GuiButtonColor_c, "MTR_GuiButtonColor_c",
 GuiFunctionSupported);
fa.FunctionSupported(GuiButtonColor_ca, "MTR_GuiButtonColor_ca",
 GuiFunctionSupported);
fa.FunctionSupported(GuiButtonColor_rgb, "MTR_GuiButtonColor_rgb",
 GuiFunctionSupported);
fa.FunctionSupported(GuiButtonColor_rgba, "MTR_GuiButtonColor_rgba",
 GuiFunctionSupported);
fa.FunctionSupported(GuiButtonSymbol, "MTR_GuiButtonSymbol",
 GuiFunctionSupported);
fa.FunctionSupported(GuiButtonSymbolLabel, "MTR_GuiButtonSymbolLabel",
 GuiFunctionSupported);
fa.FunctionSupported(GuiButtonSymbolText, "MTR_GuiButtonSymbolText",
 GuiFunctionSupported);
fa.FunctionSupported(GuiButtonImage, "MTR_GuiButtonImage",
 GuiFunctionSupported);
fa.FunctionSupported(GuiButtonImageLabel, "MTR_GuiButtonImageLabel",
 GuiFunctionSupported);
fa.FunctionSupported(GuiButtonImageText, "MTR_GuiButtonImageText",
 GuiFunctionSupported);
fa.FunctionSupported(GuiCheckLabel, "MTR_GuiCheckLabel", GuiFunctionSupported);
fa.FunctionSupported(GuiCheckText, "MTR_GuiCheckText", GuiFunctionSupported);
fa.FunctionSupported(GuiSelectableLabel, "MTR_GuiSelectableLabel",
 GuiFunctionSupported);
fa.FunctionSupported(GuiSelectableText, "MTR_GuiSelectableText",
 GuiFunctionSupported);
fa.FunctionSupported(GuiSelectableImageLabel, "MTR_GuiSelectableImageLabel",
 GuiFunctionSupported);
fa.FunctionSupported(GuiSelectableImageText, "MTR_GuiSelectableImageText",
 GuiFunctionSupported);
fa.FunctionSupported(GuiEditText, "MTR_GuiEditText", GuiFunctionSupported);
fa.FunctionSupported(GuiEditInteger, "MTR_GuiEditInteger",
 GuiFunctionSupported);
fa.FunctionSupported(GuiEditFloat, "MTR_GuiEditFloat", GuiFunctionSupported);
fa.FunctionSupported(GuiLabel, "MTR_GuiLabel", GuiFunctionSupported);
fa.FunctionSupported(GuiLabelColored_c, "MTR_GuiLabelColored_c",
 GuiFunctionSupported);
fa.FunctionSupported(GuiLabelColored_ca, "MTR_GuiLabelColored_ca",
 GuiFunctionSupported);
fa.FunctionSupported(GuiLabelColored_rgb, "MTR_GuiLabelColored_rgb",
 GuiFunctionSupported);
fa.FunctionSupported(GuiLabelColored_rgba, "MTR_GuiLabelColored_rgba",
 GuiFunctionSupported);
fa.FunctionSupported(GuiLabelWrap, "MTR_GuiLabelWrap", GuiFunctionSupported);
fa.FunctionSupported(GuiLabelColoredWrap_c, "MTR_GuiLabelColoredWrap_c",
 GuiFunctionSupported);
fa.FunctionSupported(GuiLabelColoredWrap_ca, "MTR_GuiLabelColoredWrap_ca",
 GuiFunctionSupported);
fa.FunctionSupported(GuiLabelColoredWrap_rgb, "MTR_GuiLabelColoredWrap_rgb",
 GuiFunctionSupported);
fa.FunctionSupported(GuiLabelColoredWrap_rgba, "MTR_GuiLabelColoredWrap_rgba",
 GuiFunctionSupported);
fa.FunctionSupported(GuiTreeTabBegin, "MTR_GuiTreeTabBegin",
 GuiFunctionSupported);
fa.FunctionSupported(GuiTreeTabEnd, "MTR_GuiTreeTabEnd", GuiFunctionSupported);
fa.FunctionSupported(GuiLayoutRowDynamic, "MTR_GuiLayoutRowDynamic",
 GuiFunctionSupported);
fa.FunctionSupported(GuiLayoutRowStatic, "MTR_GuiLayoutRowStatic",
 GuiFunctionSupported);
fa.FunctionSupported(GuiGroupBegin, "MTR_GuiGroupBegin", GuiFunctionSupported);
fa.FunctionSupported(GuiGroupEnd, "MTR_GuiGroupEnd", GuiFunctionSupported);
fa.FunctionSupported(GuiSpacing, "MTR_GuiSpacing", GuiFunctionSupported);
