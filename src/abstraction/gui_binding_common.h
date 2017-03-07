#ifndef MTR_ABSTRACTION_GUI_BINDING_COMMON_H
#define MTR_ABSTRACTION_GUI_BINDING_COMMON_H

typedef bool (MTR_CALL * mtrGuiInitFunc)(uint32_t, uint32_t, uint32_t, uint32_t,
 uint32_t, uint32_t, uint32_t);
mtrGuiInitFunc mtrGuiInit;

typedef void (MTR_CALL * mtrGuiQuitFunc)(void);
mtrGuiQuitFunc mtrGuiQuit;

typedef void (MTR_CALL * mtrGuiProcessEventsFunc)(void);
mtrGuiProcessEventsFunc mtrGuiProcessEvents;

typedef void (MTR_CALL * mtrGuiRenderFunc)(void);
mtrGuiRenderFunc mtrGuiRender;

typedef uint32_t (MTR_CALL * mtrGuiAddFontFunc)(uint32_t);
mtrGuiAddFontFunc mtrGuiAddFont;

typedef uint32_t (MTR_CALL * mtrGuiAddImageFunc)(uint32_t, int, int, int, int);
mtrGuiAddImageFunc mtrGuiAddImage;

typedef uint32_t (MTR_CALL * mtrGuiAddStringBufferFunc)(const char *, int);
mtrGuiAddStringBufferFunc mtrGuiAddStringBuffer;

typedef void (MTR_CALL * mtrGuiDeleteFontFunc)(uint32_t);
mtrGuiDeleteFontFunc mtrGuiDeleteFont;

typedef void (MTR_CALL * mtrGuiDeleteImageFunc)(uint32_t);
mtrGuiDeleteImageFunc mtrGuiDeleteImage;

typedef void (MTR_CALL * mtrGuiDeleteStringBufferFunc)(uint32_t);
mtrGuiDeleteStringBufferFunc mtrGuiDeleteStringBuffer;

typedef bool (MTR_CALL * mtrGuiBeginFunc)(const char *, float, float, float,
 float, int);
mtrGuiBeginFunc mtrGuiBegin;

typedef void (MTR_CALL * mtrGuiEndFunc)(void);
mtrGuiEndFunc mtrGuiEnd;

typedef bool (MTR_CALL * mtrGuiButtonTextFunc)(const char *, int);
mtrGuiButtonTextFunc mtrGuiButtonText;

typedef bool (MTR_CALL * mtrGuiButtonLabelFunc)(const char *);
mtrGuiButtonLabelFunc mtrGuiButtonLabel;

typedef bool (MTR_CALL * mtrGuiButtonColor_cFunc)(uint32_t);
mtrGuiButtonColor_cFunc mtrGuiButtonColor_c;

typedef bool (MTR_CALL * mtrGuiButtonColor_caFunc)(uint32_t);
mtrGuiButtonColor_caFunc mtrGuiButtonColor_ca;

typedef bool (MTR_CALL * mtrGuiButtonColor_rgbFunc)(uint8_t, uint8_t, uint8_t);
mtrGuiButtonColor_rgbFunc mtrGuiButtonColor_rgb;

typedef bool (MTR_CALL * mtrGuiButtonColor_rgbaFunc)(uint8_t, uint8_t, uint8_t,
 uint8_t);
mtrGuiButtonColor_rgbaFunc mtrGuiButtonColor_rgba;

typedef bool (MTR_CALL * mtrGuiButtonSymbolFunc)(int);
mtrGuiButtonSymbolFunc mtrGuiButtonSymbol;

typedef bool (MTR_CALL * mtrGuiButtonSymbolLabelFunc)(int, const char *, int);
mtrGuiButtonSymbolLabelFunc mtrGuiButtonSymbolLabel;

typedef bool (MTR_CALL * mtrGuiButtonSymbolTextFunc)(int, const char *, int,
 int);
mtrGuiButtonSymbolTextFunc mtrGuiButtonSymbolText;

typedef bool (MTR_CALL * mtrGuiButtonImageFunc)(uint32_t);
mtrGuiButtonImageFunc mtrGuiButtonImage;

typedef bool (MTR_CALL * mtrGuiButtonImageLabelFunc)(uint32_t, const char *,
 int);
mtrGuiButtonImageLabelFunc mtrGuiButtonImageLabel;

typedef bool (MTR_CALL * mtrGuiButtonImageTextFunc)(uint32_t, const char *, int,
 int);
mtrGuiButtonImageTextFunc mtrGuiButtonImageText;

typedef bool (MTR_CALL * mtrGuiCheckLabelFunc)(const char *, bool);
mtrGuiCheckLabelFunc mtrGuiCheckLabel;

typedef bool (MTR_CALL * mtrGuiCheckTextFunc)(const char *, int, bool);
mtrGuiCheckTextFunc mtrGuiCheckText;

typedef bool (MTR_CALL * mtrGuiSelectableLabelFunc)(const char *, int, bool);
mtrGuiSelectableLabelFunc mtrGuiSelectableLabel;

typedef bool (MTR_CALL * mtrGuiSelectableTextFunc)(const char *, int, int,
 bool);
mtrGuiSelectableTextFunc mtrGuiSelectableText;

typedef bool (MTR_CALL * mtrGuiSelectableImageLabelFunc)(uint32_t, const char *,
 int, bool);
mtrGuiSelectableImageLabelFunc mtrGuiSelectableImageLabel;

typedef bool (MTR_CALL * mtrGuiSelectableImageTextFunc)(uint32_t, const char *,
 int, int, bool);
mtrGuiSelectableImageTextFunc mtrGuiSelectableImageText;

MTR_EXPORT void MTR_CALL mtrGuiEditTextFunc(uint32_t);
mtrGuiEditTextFunc mtrGuiEditText;

MTR_EXPORT void MTR_CALL mtrGuiEditIntegerFunc(uint32_t);
mtrGuiEditIntegerFunc mtrGuiEditInteger;

MTR_EXPORT void MTR_CALL mtrGuiEditFloatFunc(uint32_t);
mtrGuiEditFloatFunc mtrGuiEditFloat;

typedef void (MTR_CALL * mtrGuiLabelFunc)(const char *, int);
mtrGuiLabelFunc mtrGuiLabel;

typedef void (MTR_CALL * mtrGuiLabelColored_cFunc)(const char *, int, uint32_t);
mtrGuiLabelColored_cFunc mtrGuiLabelColored_c;

typedef void (MTR_CALL * mtrGuiLabelColored_caFunc)(const char *, int,
 uint32_t);
mtrGuiLabelColored_caFunc mtrGuiLabelColored_ca;

typedef void (MTR_CALL * mtrGuiLabelColored_rgbFunc)(const char *, int, uint8_t,
 uint8_t, uint8_t);
mtrGuiLabelColored_rgbFunc mtrGuiLabelColored_rgb;

typedef void (MTR_CALL * mtrGuiLabelColored_rgbaFunc)(const char *, int,
 uint8_t, uint8_t, uint8_t, uint8_t);
mtrGuiLabelColored_rgbaFunc mtrGuiLabelColored_rgba;

typedef void (MTR_CALL * mtrGuiLabelWrapFunc)(const char *);
mtrGuiLabelWrapFunc mtrGuiLabelWrap;

typedef void (MTR_CALL * mtrGuiLabelColoredWrap_cFunc)(const char *, uint32_t);
mtrGuiLabelColoredWrap_cFunc mtrGuiLabelColoredWrap_c;

typedef void (MTR_CALL * mtrGuiLabelColoredWrap_caFunc)(const char *, uint32_t);
mtrGuiLabelColoredWrap_caFunc mtrGuiLabelColoredWrap_ca;

typedef void (MTR_CALL * mtrGuiLabelColoredWrap_rgbFunc)(const char *, uint8_t,
 uint8_t, uint8_t);
mtrGuiLabelColoredWrap_rgbFunc mtrGuiLabelColoredWrap_rgb;

typedef void (MTR_CALL * mtrGuiLabelColoredWrap_rgbaFunc)(const char *, uint8_t,
 uint8_t, uint8_t, uint8_t);
mtrGuiLabelColoredWrap_rgbaFunc mtrGuiLabelColoredWrap_rgba;

typedef bool (MTR_CALL * mtrGuiTreeTabBeginFunc)(const char *, bool);
mtrGuiTreeTabBeginFunc mtrGuiTreeTabBegin;

typedef void (MTR_CALL * mtrGuiTreeTabEndFunc)(void);
mtrGuiTreeTabEndFunc mtrGuiTreeTabEnd;

typedef void (MTR_CALL * mtrGuiLayoutRowDynamicFunc)(float, int);
mtrGuiLayoutRowDynamicFunc mtrGuiLayoutRowDynamic;

typedef void (MTR_CALL * mtrGuiLayoutRowStaticFunc)(float, int, int);
mtrGuiLayoutRowStaticFunc mtrGuiLayoutRowStatic;

typedef bool (MTR_CALL * mtrGuiGroupBeginFunc)(const char *, int);
mtrGuiGroupBeginFunc mtrGuiGroupBegin;

typedef void (MTR_CALL * mtrGuiGroupEndFunc)(void);
mtrGuiGroupEndFunc mtrGuiGroupEnd;

typedef void (MTR_CALL * mtrGuiSpacingFunc)(int);
mtrGuiSpacingFunc mtrGuiSpacing;

#endif
