#ifndef MTR_ABSTRACTION_GUI_H
#define MTR_ABSTRACTION_GUI_H

#include <string.h>
#include <stdarg.h>

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_IMPLEMENTATION
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#pragma GCC diagnostic ignored "-Wfloat-equal"
#ifdef __EMSCRIPTEN__
    #pragma GCC diagnostic ignored "-Wformat-nonliteral"
#endif
#ifdef __MINGW64__
    #pragma GCC diagnostic ignored "-Wnull-dereference"
#endif
#include "nuklear.h"
#pragma GCC diagnostic pop

#include "marathoner/plugin.h"
#ifdef MTR_MOD_STATIC
    #define fa faGui
#endif
#include "fa/Abstraction_gui.h"

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
char        getTextWidthBuffer[0x10000];
static bool mtrGuiInited = false;
int         mtrTreeTabId;
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

MTR_FUNC(bool, MTR_FontDrawString_f, uint32_t fontNum, float x, float y,
 const char *string);
MTR_FUNC(int, MTR_FontGetHeight, uint32_t fontNum);
MTR_FUNC(int, MTR_FontGetStringWidth, uint32_t fontNum, const char *string);
MTR_FUNC(char *, MTR_FontGetName, uint32_t);
MTR_FUNC(void, MTR_ScreenGetSizes, int *, int *);
MTR_FUNC(void, MTR_TextureBlitRegionSized_f, uint32_t, float, float, float,
 float, float, float, float, float);
MTR_FUNC(void, MTR_TextureGetSizes, uint32_t, int *, int *);
MTR_FUNC(void, MTR_PrimitiveLine_rgba_f, float, float, float, float, uint8_t,
 uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveArc_rgba_f, float, float, float, float, float,
 uint8_t, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveSegmentFilled_rgba_f, float, float, float, float,
 float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveCircle_rgba_f, float, float, float, uint8_t,
 uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveCircleFilled_rgba_f, float, float, float, uint8_t,
 uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveTriangle_rgba_f, float, float, float, float, float,
 float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveTriangleFilled_rgba_f, float, float, float, float,
 float, float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveRoundedRectangle_rgba_f, float, float, float, float,
 float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveRoundedRectangleFilled_rgba_f, float, float, float,
 float, float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_FUNC(bool, MTR_KeyboardPress, int);
MTR_FUNC(bool, MTR_KeyboardRelease, int);
MTR_FUNC(bool, MTR_KeyboardPressed, int);
MTR_FUNC(char *, MTR_KeyboardInputChar, void);
MTR_FUNC(bool, MTR_MouseMoving, void);
MTR_FUNC(void, MTR_MouseGetXY, int *, int *);
MTR_FUNC(bool, MTR_MousePress, int);
MTR_FUNC(bool, MTR_MouseRelease, int);
MTR_FUNC(int, MTR_MouseGetWheelRelative, void);

#endif
