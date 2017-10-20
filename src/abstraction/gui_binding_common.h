#ifndef MTR_ABSTRACTION_GUI_BINDING_COMMON_H
#define MTR_ABSTRACTION_GUI_BINDING_COMMON_H

typedef int (MTR_CALL * MTR_GuiFunctionSupportedFunc)(const char *);
MTR_GuiFunctionSupportedFunc MTR_GuiFunctionSupported;

typedef bool (MTR_CALL * MTR_GuiInitFunc)(uint32_t, uint32_t, uint32_t, uint32_t,
 uint32_t);
MTR_GuiInitFunc MTR_GuiInit;

typedef void (MTR_CALL * MTR_GuiQuitFunc)(void);
MTR_GuiQuitFunc MTR_GuiQuit;

typedef void (MTR_CALL * MTR_GuiProcessEventsFunc)(void);
MTR_GuiProcessEventsFunc MTR_GuiProcessEvents;

typedef void (MTR_CALL * MTR_GuiRenderFunc)(void);
MTR_GuiRenderFunc MTR_GuiRender;

typedef uint32_t (MTR_CALL * MTR_GuiAddFontFunc)(uint32_t);
MTR_GuiAddFontFunc MTR_GuiAddFont;

typedef uint32_t (MTR_CALL * MTR_GuiAddImageFunc)(uint32_t, int, int, int, int);
MTR_GuiAddImageFunc MTR_GuiAddImage;

typedef void (MTR_CALL * MTR_GuiDeleteFontFunc)(uint32_t);
MTR_GuiDeleteFontFunc MTR_GuiDeleteFont;

typedef void (MTR_CALL * MTR_GuiDeleteImageFunc)(uint32_t);
MTR_GuiDeleteImageFunc MTR_GuiDeleteImage;

typedef bool (MTR_CALL * MTR_GuiBeginFunc)(const char *, float, float, float,
 float, int);
MTR_GuiBeginFunc MTR_GuiBegin;

typedef void (MTR_CALL * MTR_GuiEndFunc)(void);
MTR_GuiEndFunc MTR_GuiEnd;

typedef bool (MTR_CALL * MTR_GuiButtonTextFunc)(const char *, int);
MTR_GuiButtonTextFunc MTR_GuiButtonText;

typedef bool (MTR_CALL * MTR_GuiButtonLabelFunc)(const char *);
MTR_GuiButtonLabelFunc MTR_GuiButtonLabel;

typedef bool (MTR_CALL * MTR_GuiButtonColor_cFunc)(uint32_t);
MTR_GuiButtonColor_cFunc MTR_GuiButtonColor_c;

typedef bool (MTR_CALL * MTR_GuiButtonColor_caFunc)(uint32_t);
MTR_GuiButtonColor_caFunc MTR_GuiButtonColor_ca;

typedef bool (MTR_CALL * MTR_GuiButtonColor_rgbFunc)(uint8_t, uint8_t, uint8_t);
MTR_GuiButtonColor_rgbFunc MTR_GuiButtonColor_rgb;

typedef bool (MTR_CALL * MTR_GuiButtonColor_rgbaFunc)(uint8_t, uint8_t, uint8_t,
 uint8_t);
MTR_GuiButtonColor_rgbaFunc MTR_GuiButtonColor_rgba;

typedef bool (MTR_CALL * MTR_GuiButtonSymbolFunc)(int);
MTR_GuiButtonSymbolFunc MTR_GuiButtonSymbol;

typedef bool (MTR_CALL * MTR_GuiButtonSymbolLabelFunc)(int, const char *, int);
MTR_GuiButtonSymbolLabelFunc MTR_GuiButtonSymbolLabel;

typedef bool (MTR_CALL * MTR_GuiButtonSymbolTextFunc)(int, const char *, int,
 int);
MTR_GuiButtonSymbolTextFunc MTR_GuiButtonSymbolText;

typedef bool (MTR_CALL * MTR_GuiButtonImageFunc)(uint32_t);
MTR_GuiButtonImageFunc MTR_GuiButtonImage;

typedef bool (MTR_CALL * MTR_GuiButtonImageLabelFunc)(uint32_t, const char *,
 int);
MTR_GuiButtonImageLabelFunc MTR_GuiButtonImageLabel;

typedef bool (MTR_CALL * MTR_GuiButtonImageTextFunc)(uint32_t, const char *, int,
 int);
MTR_GuiButtonImageTextFunc MTR_GuiButtonImageText;

typedef bool (MTR_CALL * MTR_GuiCheckLabelFunc)(const char *, bool);
MTR_GuiCheckLabelFunc MTR_GuiCheckLabel;

typedef bool (MTR_CALL * MTR_GuiCheckTextFunc)(const char *, int, bool);
MTR_GuiCheckTextFunc MTR_GuiCheckText;

typedef bool (MTR_CALL * MTR_GuiSelectableLabelFunc)(const char *, int, bool);
MTR_GuiSelectableLabelFunc MTR_GuiSelectableLabel;

typedef bool (MTR_CALL * MTR_GuiSelectableTextFunc)(const char *, int, int,
 bool);
MTR_GuiSelectableTextFunc MTR_GuiSelectableText;

typedef bool (MTR_CALL * MTR_GuiSelectableImageLabelFunc)(uint32_t, const char *,
 int, bool);
MTR_GuiSelectableImageLabelFunc MTR_GuiSelectableImageLabel;

typedef bool (MTR_CALL * MTR_GuiSelectableImageTextFunc)(uint32_t, const char *,
 int, int, bool);
MTR_GuiSelectableImageTextFunc MTR_GuiSelectableImageText;

typedef void (MTR_CALL * MTR_GuiEditTextFunc)(uint32_t);
MTR_GuiEditTextFunc MTR_GuiEditText;

typedef void (MTR_CALL * MTR_GuiEditIntegerFunc)(uint32_t);
MTR_GuiEditIntegerFunc MTR_GuiEditInteger;

typedef void (MTR_CALL * MTR_GuiEditFloatFunc)(uint32_t);
MTR_GuiEditFloatFunc MTR_GuiEditFloat;

typedef void (MTR_CALL * MTR_GuiLabelFunc)(const char *, int);
MTR_GuiLabelFunc MTR_GuiLabel;

typedef void (MTR_CALL * MTR_GuiLabelColored_cFunc)(const char *, int, uint32_t);
MTR_GuiLabelColored_cFunc MTR_GuiLabelColored_c;

typedef void (MTR_CALL * MTR_GuiLabelColored_caFunc)(const char *, int,
 uint32_t);
MTR_GuiLabelColored_caFunc MTR_GuiLabelColored_ca;

typedef void (MTR_CALL * MTR_GuiLabelColored_rgbFunc)(const char *, int, uint8_t,
 uint8_t, uint8_t);
MTR_GuiLabelColored_rgbFunc MTR_GuiLabelColored_rgb;

typedef void (MTR_CALL * MTR_GuiLabelColored_rgbaFunc)(const char *, int,
 uint8_t, uint8_t, uint8_t, uint8_t);
MTR_GuiLabelColored_rgbaFunc MTR_GuiLabelColored_rgba;

typedef void (MTR_CALL * MTR_GuiLabelWrapFunc)(const char *);
MTR_GuiLabelWrapFunc MTR_GuiLabelWrap;

typedef void (MTR_CALL * MTR_GuiLabelColoredWrap_cFunc)(const char *, uint32_t);
MTR_GuiLabelColoredWrap_cFunc MTR_GuiLabelColoredWrap_c;

typedef void (MTR_CALL * MTR_GuiLabelColoredWrap_caFunc)(const char *, uint32_t);
MTR_GuiLabelColoredWrap_caFunc MTR_GuiLabelColoredWrap_ca;

typedef void (MTR_CALL * MTR_GuiLabelColoredWrap_rgbFunc)(const char *, uint8_t,
 uint8_t, uint8_t);
MTR_GuiLabelColoredWrap_rgbFunc MTR_GuiLabelColoredWrap_rgb;

typedef void (MTR_CALL * MTR_GuiLabelColoredWrap_rgbaFunc)(const char *, uint8_t,
 uint8_t, uint8_t, uint8_t);
MTR_GuiLabelColoredWrap_rgbaFunc MTR_GuiLabelColoredWrap_rgba;

typedef bool (MTR_CALL * MTR_GuiTreeTabBeginFunc)(const char *, bool);
MTR_GuiTreeTabBeginFunc MTR_GuiTreeTabBegin;

typedef void (MTR_CALL * MTR_GuiTreeTabEndFunc)(void);
MTR_GuiTreeTabEndFunc MTR_GuiTreeTabEnd;

typedef void (MTR_CALL * MTR_GuiLayoutRowDynamicFunc)(float, int);
MTR_GuiLayoutRowDynamicFunc MTR_GuiLayoutRowDynamic;

typedef void (MTR_CALL * MTR_GuiLayoutRowStaticFunc)(float, int, int);
MTR_GuiLayoutRowStaticFunc MTR_GuiLayoutRowStatic;

typedef bool (MTR_CALL * MTR_GuiGroupBeginFunc)(const char *, int);
MTR_GuiGroupBeginFunc MTR_GuiGroupBegin;

typedef void (MTR_CALL * MTR_GuiGroupEndFunc)(void);
MTR_GuiGroupEndFunc MTR_GuiGroupEnd;

typedef void (MTR_CALL * MTR_GuiSpacingFunc)(int);
MTR_GuiSpacingFunc MTR_GuiSpacing;

#endif
