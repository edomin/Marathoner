#ifndef MTR_ABSTRACTION_GUI_BINDING_COMMON_H
#define MTR_ABSTRACTION_GUI_BINDING_COMMON_H

MTR_FUNC(int, MTR_GuiFunctionSupported, const char *);
MTR_FUNC(bool, MTR_GuiInit, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
MTR_FUNC(void, MTR_GuiQuit, void);
MTR_FUNC(void, MTR_GuiProcessEvents, void);
MTR_FUNC(void, MTR_GuiRender, void);
MTR_FUNC(uint32_t, MTR_GuiAddFont, uint32_t);
MTR_FUNC(uint32_t, MTR_GuiAddImage, uint32_t, int, int, int, int);
MTR_FUNC(void, MTR_GuiDeleteFont, uint32_t);
MTR_FUNC(void, MTR_GuiDeleteImage, uint32_t);
MTR_FUNC(bool, MTR_GuiBegin, const char *, float, float, float, float, int);
MTR_FUNC(void, MTR_GuiEnd, void);
MTR_FUNC(bool, MTR_GuiButtonText, const char *, int);
MTR_FUNC(bool, MTR_GuiButtonLabel, const char *);
MTR_FUNC(bool, MTR_GuiButtonColor_c, uint32_t);
MTR_FUNC(bool, MTR_GuiButtonColor_ca, uint32_t);
MTR_FUNC(bool, MTR_GuiButtonColor_rgb, uint8_t, uint8_t, uint8_t);
MTR_FUNC(bool, MTR_GuiButtonColor_rgba, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_FUNC(bool, MTR_GuiButtonSymbol, int);
MTR_FUNC(bool, MTR_GuiButtonSymbolLabel, int, const char *, int);
MTR_FUNC(bool, MTR_GuiButtonSymbolText, int, const char *, int, int);
MTR_FUNC(bool, MTR_GuiButtonImage, uint32_t);
MTR_FUNC(bool, MTR_GuiButtonImageLabel, uint32_t, const char *, int);
MTR_FUNC(bool, MTR_GuiButtonImageText, uint32_t, const char *, int, int);
MTR_FUNC(bool, MTR_GuiCheckLabel, const char *, bool);
MTR_FUNC(bool, MTR_GuiCheckText, const char *, int, bool);
MTR_FUNC(bool, MTR_GuiSelectableLabel, const char *, int, bool);
MTR_FUNC(bool, MTR_GuiSelectableText, const char *, int, int, bool);
MTR_FUNC(bool, MTR_GuiSelectableImageLabel, uint32_t, const char *, int, bool);
MTR_FUNC(bool, MTR_GuiSelectableImageText, uint32_t, const char *, int, int,
 bool);
MTR_FUNC(void, MTR_GuiEditText, uint32_t);
MTR_FUNC(void, MTR_GuiEditInteger, uint32_t);
MTR_FUNC(void, MTR_GuiEditFloat, uint32_t);
MTR_FUNC(void, MTR_GuiLabel, const char *, int);
MTR_FUNC(void, MTR_GuiLabelColored_c, const char *, int, uint32_t);
MTR_FUNC(void, MTR_GuiLabelColored_ca, const char *, int, uint32_t);
MTR_FUNC(void, MTR_GuiLabelColored_rgb, const char *, int, uint8_t, uint8_t,
 uint8_t);
MTR_FUNC(void, MTR_GuiLabelColored_rgba, const char *, int, uint8_t, uint8_t,
 uint8_t, uint8_t);
MTR_FUNC(void, MTR_GuiLabelWrap, const char *);
MTR_FUNC(void, MTR_GuiLabelColoredWrap_c, const char *, uint32_t);
MTR_FUNC(void, MTR_GuiLabelColoredWrap_ca, const char *, uint32_t);
MTR_FUNC(void, MTR_GuiLabelColoredWrap_rgb, const char *, uint8_t, uint8_t,
 uint8_t);
MTR_FUNC(void, MTR_GuiLabelColoredWrap_rgba, const char *, uint8_t, uint8_t,
 uint8_t, uint8_t);
MTR_FUNC(bool, MTR_GuiTreeTabBegin, const char *, bool);
MTR_FUNC(void, MTR_GuiTreeTabEnd, void);
MTR_FUNC(void, MTR_GuiLayoutRowDynamic, float, int);
MTR_FUNC(void, MTR_GuiLayoutRowStatic, float, int, int);
MTR_FUNC(bool, MTR_GuiGroupBegin, const char *, int);
MTR_FUNC(void, MTR_GuiGroupEnd, void);
MTR_FUNC(void, MTR_GuiSpacing, int);

#endif
