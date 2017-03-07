#ifndef MTR_ABSTRACTION_GUI_H
#define MTR_ABSTRACTION_GUI_H

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_IMPLEMENTATION
#include "nuklear.h"

#include "marathoner/plugin.h"

typedef struct mtrNkFont {
    struct nk_user_font nk;
    int                 height;
    uint32_t            font;
} mtrNkFont;

typedef struct mtrNkImage {
    struct nk_image nk;
    int             width;
    int             height;
    uint32_t        texture;
} mtrNkImage;

typedef struct mtrNkSb {
    char *string;
    int   maxlen;
} mtrNkSb;

static struct mtrNkGui {
//    Tigr             *dsp;
//    Tigr             *backdrop;
    unsigned int      width;
    unsigned int      height;
    int               is_touch_down;
    int               touch_down_id;
    struct nk_context ctx;
    struct nk_buffer  cmds;
} mtrNkGui;

mtrIndexkeeper_t *mtrGuiFontKeeper;
mtrIndexkeeper_t *mtrGuiImageKeeper;
mtrIndexkeeper_t *mtrGuiStringBufferKeeper;

typedef bool (MTR_CALL * mtrFontDrawMbfString_fFunc)(uint32_t fontNum, float x,
 float y, const char *string);
mtrFontDrawMbfString_fFunc mtrFontDrawMbfString_f;

typedef int (MTR_CALL * mtrFontGetHeightFunc)(uint32_t fontNum);
mtrFontGetHeightFunc mtrFontGetHeight;

typedef int (MTR_CALL * mtrFontGetStringWidthFunc)(uint32_t fontNum,
 const char *string);
mtrFontGetStringWidthFunc mtrFontGetStringWidth;

typedef char *(MTR_CALL * mtrFontGetNameFunc)(uint32_t fontNum);
mtrFontGetNameFunc mtrFontGetName;

typedef void (MTR_CALL * mtrScreenGetSizesFunc)(int *w, int *h);
mtrScreenGetSizesFunc mtrScreenGetSizes;

typedef void (MTR_CALL * mtrTextureBlitRegionScaled_fFunc)(uint32_t texNum,
 float x, float y, float w, float h, float rx, float ry, float rw, float rh);
mtrTextureBlitRegionScaled_fFunc mtrTextureBlitRegionScaled_f;

typedef void (MTR_CALL * mtrTextureGetSizesFunc)(uint32_t texNum, int *width,
 int *height);
mtrTextureGetSizesFunc mtrTextureGetSizes;

typedef void (MTR_CALL * mtrPrimitiveLine_rgba_fFunc)(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
mtrPrimitiveLine_rgba_fFunc mtrPrimitiveLine_rgba_f;

typedef void (MTR_CALL * mtrPrimitiveArc_rgba_fFunc)(float x, float y,
 float radius, float startAngle, float endAngle, uint8_t r, uint8_t g,
 uint8_t b, uint8_t a);
mtrPrimitiveArc_rgba_fFunc mtrPrimitiveArc_rgba_f;

typedef void (MTR_CALL * mtrPrimitiveSegmentFilled_rgba_fFunc)(float x, float y,
 float radius, float startAngle, float endAngle, uint8_t r, uint8_t g,
 uint8_t b, uint8_t a);
mtrPrimitiveSegmentFilled_rgba_fFunc mtrPrimitiveSegmentFilled_rgba_f;

typedef void (MTR_CALL * mtrPrimitiveCircle_rgba_fFunc)(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
mtrPrimitiveCircle_rgba_fFunc mtrPrimitiveCircle_rgba_f;

typedef void (MTR_CALL * mtrPrimitiveCircleFilled_rgba_fFunc)(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
mtrPrimitiveCircleFilled_rgba_fFunc mtrPrimitiveCircleFilled_rgba_f;

typedef void (MTR_CALL * mtrPrimitiveTriangle_rgba_fFunc)(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a);
mtrPrimitiveTriangle_rgba_fFunc mtrPrimitiveTriangle_rgba_f;

typedef void (MTR_CALL * mtrPrimitiveTriangleFilled_rgba_fFunc)(float x1,
 float y1, float x2, float y2, float x3, float y3, uint8_t r, uint8_t g,
 uint8_t b, uint8_t a);
mtrPrimitiveTriangleFilled_rgba_fFunc mtrPrimitiveTriangleFilled_rgba_f;

typedef void (MTR_CALL * mtrPrimitiveRoundedRectangle_rgba_fFunc)(float x1,
 float y1, float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a);
mtrPrimitiveRoundedRectangle_rgba_fFunc mtrPrimitiveRoundedRectangle_rgba_f;

typedef void (MTR_CALL * mtrPrimitiveRoundedRectangleFilled_rgba_fFunc)(
 float x1, float y1, float x2, float y2, float radius, uint8_t r, uint8_t g,
 uint8_t b, uint8_t a);
mtrPrimitiveRoundedRectangleFilled_rgba_fFunc mtrPrimitiveRoundedRectangleFilled_rgba_f;

typedef bool (MTR_CALL * mtrKeyboardPressFunc)(int key);
mtrKeyboardPressFunc mtrKeyboardPress;

typedef bool (MTR_CALL * mtrKeyboardReleaseFunc)(int key);
mtrKeyboardReleaseFunc mtrKeyboardRelease;

typedef bool (MTR_CALL * mtrKeyboardPressedFunc)(int key);
mtrKeyboardPressedFunc mtrKeyboardPressed;

typedef char *(MTR_CALL * mtrKeyboardInputCharFunc)(void);
mtrKeyboardInputCharFunc mtrKeyboardInputChar;

typedef void (MTR_CALL * mtrMouseGetDeltaXYFunc)(int *deltaX, int *deltaY);
mtrMouseGetDeltaXYFunc mtrMouseGetDeltaXY;

typedef void (MTR_CALL * mtrMouseGetXYFunc)(int *mouseX, int *mouseY);
mtrMouseGetXYFunc mtrMouseGetXY;

typedef bool (MTR_CALL * mtrMousePressFunc)(int button);
mtrMousePressFunc mtrMousePress;

typedef bool (MTR_CALL * mtrMouseReleaseFunc)(int button);
mtrMouseReleaseFunc mtrMouseRelease;

typedef int (MTR_CALL * mtrMouseGetWheelRelativeFunc)(void);
mtrMouseGetWheelRelativeFunc mtrMouseGetWheelRelative;

#endif
