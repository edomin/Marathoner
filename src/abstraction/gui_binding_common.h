#ifndef MTR_ABSTRACTION_GUI_BINDING_COMMON_H
#define MTR_ABSTRACTION_GUI_BINDING_COMMON_H

typedef bool (MTR_CALL * mtrGuiInitFunc)(uint32_t);
mtrGuiInitFunc mtrGuiInit;

typedef void (MTR_CALL * mtrGuiQuitFunc)(void);
mtrGuiQuitFunc mtrGuiQuit;

typedef void (MTR_CALL * mtrGuiProcessEventsFunc)(void);
mtrGuiProcessEventsFunc mtrGuiProcessEvents;

typedef void (MTR_CALL * mtrGuiRenderFunc)(void);
mtrGuiRenderFunc mtrGuiRender;

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

typedef bool (MTR_CALL * mtrGuiCheckLabelFunc)(const char *, bool);
mtrGuiCheckLabelFunc mtrGuiCheckLabel;

typedef bool (MTR_CALL * mtrGuiCheckTextFunc)(const char *, int, bool);
mtrGuiCheckTextFunc mtrGuiCheckText;

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
