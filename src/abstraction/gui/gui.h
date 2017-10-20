#ifndef MTR_ABSTRACTION_GUI_H
#define MTR_ABSTRACTION_GUI_H

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_IMPLEMENTATION
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#pragma GCC diagnostic ignored "-Wfloat-equal"
#include "nuklear.h"
#pragma GCC diagnostic pop

#include "fa/Abstraction_gui.h"
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

static struct mtrNkGui {
    unsigned int      width;
    unsigned int      height;
    int               is_touch_down;
    int               touch_down_id;
    struct nk_context ctx;
    struct nk_buffer  cmds;
} mtrNkGui;

mtrIndexkeeper_t *mtrGuiFontKeeper;
mtrIndexkeeper_t *mtrGuiImageKeeper;
/* Buffer used by function mtrNkGetTextWidth */
char getTextWidthBuffer[0x10000];
static bool mtrGuiInited = false;
#define MTR_GUI_CHECK_IF_NOT_INITED(returnValue) \
    if (!mtrGuiInited)                           \
        return returnValue;
#define MTR_GUI_CHECK_IF_NOT_INITED_WITH_LOG(message, returnValue)             \
    if (!mtrGuiInited)                                                         \
    {                                                                          \
        MTR_LogWrite(message ". GUI abstraction subsystem are not initialized",\
         1, MTR_LMT_ERROR);                                                    \
        return returnValue;                                                    \
    }

typedef bool (MTR_CALL * MTR_FontDrawMbfString_fFunc)(uint32_t fontNum, float x,
 float y, const char *string);
MTR_FontDrawMbfString_fFunc MTR_FontDrawMbfString_f;

typedef int (MTR_CALL * MTR_FontGetHeightFunc)(uint32_t fontNum);
MTR_FontGetHeightFunc MTR_FontGetHeight;

typedef int (MTR_CALL * MTR_FontGetStringWidthFunc)(uint32_t fontNum,
 const char *string);
MTR_FontGetStringWidthFunc MTR_FontGetStringWidth;

typedef char *(MTR_CALL * MTR_FontGetNameFunc)(uint32_t fontNum);
MTR_FontGetNameFunc MTR_FontGetName;

typedef void (MTR_CALL * MTR_ScreenGetSizesFunc)(int *w, int *h);
MTR_ScreenGetSizesFunc MTR_ScreenGetSizes;

typedef void (MTR_CALL * MTR_TextureBlitRegionSized_fFunc)(uint32_t texNum,
 float x, float y, float w, float h, float rx, float ry, float rw, float rh);
MTR_TextureBlitRegionSized_fFunc MTR_TextureBlitRegionSized_f;

typedef void (MTR_CALL * MTR_TextureGetSizesFunc)(uint32_t texNum, int *width,
 int *height);
MTR_TextureGetSizesFunc MTR_TextureGetSizes;

typedef void (MTR_CALL * MTR_PrimitiveLine_rgba_fFunc)(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
MTR_PrimitiveLine_rgba_fFunc MTR_PrimitiveLine_rgba_f;

typedef void (MTR_CALL * MTR_PrimitiveArc_rgba_fFunc)(float x, float y,
 float radius, float startAngle, float endAngle, uint8_t r, uint8_t g,
 uint8_t b, uint8_t a);
MTR_PrimitiveArc_rgba_fFunc MTR_PrimitiveArc_rgba_f;

typedef void (MTR_CALL * MTR_PrimitiveSegmentFilled_rgba_fFunc)(float x, float y,
 float radius, float startAngle, float endAngle, uint8_t r, uint8_t g,
 uint8_t b, uint8_t a);
MTR_PrimitiveSegmentFilled_rgba_fFunc MTR_PrimitiveSegmentFilled_rgba_f;

typedef void (MTR_CALL * MTR_PrimitiveCircle_rgba_fFunc)(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
MTR_PrimitiveCircle_rgba_fFunc MTR_PrimitiveCircle_rgba_f;

typedef void (MTR_CALL * MTR_PrimitiveCircleFilled_rgba_fFunc)(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
MTR_PrimitiveCircleFilled_rgba_fFunc MTR_PrimitiveCircleFilled_rgba_f;

typedef void (MTR_CALL * MTR_PrimitiveTriangle_rgba_fFunc)(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a);
MTR_PrimitiveTriangle_rgba_fFunc MTR_PrimitiveTriangle_rgba_f;

typedef void (MTR_CALL * MTR_PrimitiveTriangleFilled_rgba_fFunc)(float x1,
 float y1, float x2, float y2, float x3, float y3, uint8_t r, uint8_t g,
 uint8_t b, uint8_t a);
MTR_PrimitiveTriangleFilled_rgba_fFunc MTR_PrimitiveTriangleFilled_rgba_f;

typedef void (MTR_CALL * MTR_PrimitiveRoundedRectangle_rgba_fFunc)(float x1,
 float y1, float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a);
MTR_PrimitiveRoundedRectangle_rgba_fFunc MTR_PrimitiveRoundedRectangle_rgba_f;

typedef void (MTR_CALL * MTR_PrimitiveRoundedRectangleFilled_rgba_fFunc)(
 float x1, float y1, float x2, float y2, float radius, uint8_t r, uint8_t g,
 uint8_t b, uint8_t a);
MTR_PrimitiveRoundedRectangleFilled_rgba_fFunc MTR_PrimitiveRoundedRectangleFilled_rgba_f;

typedef bool (MTR_CALL * MTR_KeyboardPressFunc)(int key);
MTR_KeyboardPressFunc MTR_KeyboardPress;

typedef bool (MTR_CALL * MTR_KeyboardReleaseFunc)(int key);
MTR_KeyboardReleaseFunc MTR_KeyboardRelease;

typedef bool (MTR_CALL * MTR_KeyboardPressedFunc)(int key);
MTR_KeyboardPressedFunc MTR_KeyboardPressed;

typedef char *(MTR_CALL * MTR_KeyboardInputCharFunc)(void);
MTR_KeyboardInputCharFunc MTR_KeyboardInputChar;

typedef bool (MTR_CALL * MTR_MouseMovingFunc)(void);
MTR_MouseMovingFunc MTR_MouseMoving;

typedef void (MTR_CALL * MTR_MouseGetXYFunc)(int *mouseX, int *mouseY);
MTR_MouseGetXYFunc MTR_MouseGetXY;

typedef bool (MTR_CALL * MTR_MousePressFunc)(int button);
MTR_MousePressFunc MTR_MousePress;

typedef bool (MTR_CALL * MTR_MouseReleaseFunc)(int button);
MTR_MouseReleaseFunc MTR_MouseRelease;

typedef int (MTR_CALL * MTR_MouseGetWheelRelativeFunc)(void);
MTR_MouseGetWheelRelativeFunc MTR_MouseGetWheelRelative;

#endif
