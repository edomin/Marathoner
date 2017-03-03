#include "gui.h"

#include "marathoner/plugin_common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Abstraction_gui";
    report->version = MTR_VERSION_ABSTRACTION_GUI;
    report->subsystem = "abstraction";

    report->prereqsCount = 1;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    if (report->prereqs == NULL)
    {
        free(report);
        return NULL;
    }
    report->prereqs[0] = "Abstraction_font";

    report->prereqSubsystemsCount = 5;
    report->prereqSubsystems = malloc(sizeof(char *) * report->prereqSubsystemsCount);
    if (report->prereqSubsystems == NULL)
    {
        free(report);
        free(report->prereqs);
        return NULL;
    }
    report->prereqSubsystems[0] = "screen";
    report->prereqSubsystems[1] = "texture";
    report->prereqSubsystems[2] = "primitive";
    report->prereqSubsystems[3] = "keyboard";
    report->prereqSubsystems[4] = "mouse";
    return report;
}

NK_API mtrNkFont *mtrNkAddFont(uint32_t fontnum)
{
    mtrNkFont *font;
    font = malloc(sizeof(mtrNkFont));
    if (font != NULL)
    {
        font->font = fontnum;
        font->height = mtrFontGetHeight(fontnum);
    }

    return font;
}

static float mtrNkGetTextWidth(nk_handle handle, float height,
 const char *text, int len)
{
    mtrNkFont *font;

    font = (mtrNkFont *)handle.ptr;

    if (!font || !text)
        return 0;

    char strcpy[len + 1];
    strncpy((char*)&strcpy, text, len);
    strcpy[len] = '\0';

    return mtrFontGetStringWidth(font->font, strcpy);
}

NK_INTERN void mtrNkClipboardPaste(nk_handle usr, struct nk_text_edit *edit)
{
    char *text;

    text = mtrClipboardGetText();

    if (text)
        nk_textedit_paste(edit, text, nk_strlen(text));
    (void)usr;
    free(text);
}

NK_INTERN void mtrNkClipboardCopy(nk_handle usr, const char *text, int len)
{
    char *str;

    str = 0;
    (void)usr;
    if (!len)
        return;
    str = (char*)malloc((size_t)len + 1);
    if (!str)
        return;
    memcpy(str, text, (size_t)len);
    str[len] = '\0';

    mtrClipboardPutText(str);

    free(str);
}

NK_API struct nk_context* mtrNkInit(mtrNkFont *nkFont, unsigned int width,
 unsigned int height)
{
    struct nk_user_font *font;

    if (nkFont == NULL)
        return NULL;
    font = &nkFont->nk;
    font->userdata = nk_handle_ptr(nkFont);
    font->height = nkFont->height;
    font->width = mtrNkGetTextWidth;

    mtrNkGui.width = width;
    mtrNkGui.height = height;
    mtrNkGui.is_touch_down = 0;
    mtrNkGui.touch_down_id = -1;

    nk_init_default(&mtrNkGui.ctx, font);
    mtrNkGui.ctx.clip.copy = mtrNkClipboardCopy;
    mtrNkGui.ctx.clip.paste = mtrNkClipboardPaste;
    mtrNkGui.ctx.clip.userdata = nk_handle_ptr(0);
    return &mtrNkGui.ctx;
}

void mtrNkUpdateKey(struct nk_context *ctx, int key, enum nk_keys nk_key)
{
    if (mtrKeyboardPress(key))
        nk_input_key(ctx, nk_key, 1);
    if (mtrKeyboardRelease(key))
        nk_input_key(ctx, nk_key, 0);
}

void mtrNkHandleEvents(void)
{
    struct nk_context *ctx;
    int mouseRelX;
    int mouseRelY;
    int mouseRelWheel;
    int mouseX;
    int mouseY;
    bool controlPressed;
    char *utf8char;

    UNUSED(utf8char);

    ctx = &mtrNkGui.ctx;
//    case ALLEGRO_EVENT_DISPLAY_RESIZE: {
//        allegro5.width = (unsigned int)ev->display.width;
//        allegro5.height = (unsigned int)ev->display.height;
//        al_acknowledge_resize(ev->display.source);
//    } break;

    mtrMouseGetDeltaXY(&mouseRelX, &mouseRelY);
    mtrMouseGetXY(&mouseX, &mouseY);
    if (mouseRelX != 0 && mouseRelY != 0)
        nk_input_motion(ctx, mouseX, mouseY);

    mouseRelWheel = mtrMouseGetWheelRelative();
    if (mouseRelWheel != 0)
        nk_input_scroll(ctx, (float)mouseRelWheel);

    if (mtrMousePress(0))
        nk_input_button(ctx, NK_BUTTON_LEFT, mouseX, mouseY, 1);
    if (mtrMousePress(1))
        nk_input_button(ctx, NK_BUTTON_MIDDLE, mouseX, mouseY, 1);
    if (mtrMousePress(2))
        nk_input_button(ctx, NK_BUTTON_RIGHT, mouseX, mouseY, 1);

    if (mtrMouseRelease(0))
        nk_input_button(ctx, NK_BUTTON_LEFT, mouseX, mouseY, 0);
    if (mtrMouseRelease(1))
        nk_input_button(ctx, NK_BUTTON_MIDDLE, mouseX, mouseY, 0);
    if (mtrMouseRelease(2))
        nk_input_button(ctx, NK_BUTTON_RIGHT, mouseX, mouseY, 0);

    if (mtrKeyboardPress(MTR_KEY_LSHIFT) || mtrKeyboardPress(MTR_KEY_RSHIFT))
        nk_input_key(ctx, NK_KEY_SHIFT, 1);
    if (mtrKeyboardRelease(MTR_KEY_LSHIFT) || mtrKeyboardRelease(MTR_KEY_RSHIFT))
        nk_input_key(ctx, NK_KEY_SHIFT, 0);

    mtrNkUpdateKey(ctx, MTR_KEY_DELETE, NK_KEY_DEL);
    mtrNkUpdateKey(ctx, MTR_KEY_RETURN, NK_KEY_ENTER);
    mtrNkUpdateKey(ctx, MTR_KEY_TAB, NK_KEY_TAB);
    mtrNkUpdateKey(ctx, MTR_KEY_LEFT, NK_KEY_LEFT);
    mtrNkUpdateKey(ctx, MTR_KEY_RIGHT, NK_KEY_RIGHT);
    mtrNkUpdateKey(ctx, MTR_KEY_UP, NK_KEY_UP);
    mtrNkUpdateKey(ctx, MTR_KEY_DOWN, NK_KEY_DOWN);
    mtrNkUpdateKey(ctx, MTR_KEY_BACKSPACE, NK_KEY_BACKSPACE);
    mtrNkUpdateKey(ctx, MTR_KEY_ESCAPE, NK_KEY_TEXT_RESET_MODE);
    mtrNkUpdateKey(ctx, MTR_KEY_PAGEUP, NK_KEY_SCROLL_UP);
    mtrNkUpdateKey(ctx, MTR_KEY_PAGEDOWN, NK_KEY_SCROLL_DOWN);

    if (mtrKeyboardPress(MTR_KEY_HOME))
    {
        nk_input_key(ctx, NK_KEY_TEXT_START, 1);
        nk_input_key(ctx, NK_KEY_SCROLL_START, 1);
    }
    if (mtrKeyboardRelease(MTR_KEY_END))
    {
        nk_input_key(ctx, NK_KEY_TEXT_END, 0);
        nk_input_key(ctx, NK_KEY_SCROLL_END, 0);
    }

    controlPressed = mtrKeyboardPress(MTR_KEY_LCTRL)
      || mtrKeyboardPress(MTR_KEY_RCTRL) || mtrKeyboardPress(MTR_KEY_LGUI)
      || mtrKeyboardPress(MTR_KEY_RGUI);

    if (mtrKeyboardPress(MTR_KEY_C) && controlPressed)
        nk_input_key(ctx, NK_KEY_COPY, 1);
    else if (mtrKeyboardPress(MTR_KEY_V) && controlPressed)
        nk_input_key(ctx, NK_KEY_PASTE, 1);
    else if (mtrKeyboardPress(MTR_KEY_X) && controlPressed)
        nk_input_key(ctx, NK_KEY_CUT, 1);
    else if (mtrKeyboardPress(MTR_KEY_Z) && controlPressed)
        nk_input_key(ctx, NK_KEY_TEXT_UNDO, 1);
    else if (mtrKeyboardPress(MTR_KEY_R) && controlPressed)
        nk_input_key(ctx, NK_KEY_TEXT_REDO, 1);
    else if (mtrKeyboardPress(MTR_KEY_A) && controlPressed)
        nk_input_key(ctx, NK_KEY_TEXT_SELECT_ALL, 1);
    else
    {
        utf8char = mtrKeyboardInputChar();
        if (utf8char != NULL)
            nk_input_glyph(ctx, utf8char);
    }
}

MTR_EXPORT bool MTR_CALL mtrGuiInit(uint32_t fontnum)
{
    mtrNkFont *font;
    int screenWidth;
    int screenHeight;
    bool ok;

    ok = true;
    mtrLogWrite("Initializing GUI abstraction subsystem", 0, MTR_LMT_INFO);

    MTR_FIND_FUNCTION(mtrFontDrawMbfString_f, "Abstraction_font");
    MTR_FIND_FUNCTION(mtrFontGetHeight, "Abstraction_font");
    MTR_FIND_FUNCTION(mtrFontGetStringWidth, "Abstraction_font");
    MTR_FIND_FUNCTION(mtrFontGetName, "Abstraction_font");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrScreenGetSizes, "screen");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrPrimitiveLine_rgba_f, "primitive");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrPrimitiveArc_rgba_f, "primitive");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrPrimitiveCircle_rgba_f, "primitive");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrPrimitiveCircleFilled_rgba_f,
     "primitive");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrPrimitiveTriangle_rgba_f, "primitive");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrPrimitiveTriangleFilled_rgba_f,
     "primitive");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrPrimitiveRoundedRectangle_rgba_f,
     "primitive");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrPrimitiveRoundedRectangleFilled_rgba_f,
     "primitive");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrKeyboardPress, "keyboard");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrKeyboardRelease, "keyboard");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrKeyboardPressed, "keyboard");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrKeyboardInputChar, "keyboard");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrMouseGetDeltaXY, "mouse");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrMouseGetXY, "mouse");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrMousePress, "mouse");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrMouseRelease, "mouse");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrMouseGetWheelRelative, "mouse");

    if (ok)
        mtrLogWrite("Added dependently functions", 1, MTR_LMT_INFO);
    else
    {
        mtrNotify("Functions not added", 1, MTR_LMT_FATAL);
        return false;
    }

    font = mtrNkAddFont(fontnum);
    if (font != NULL)
    {
//        mtrLogWrite_s("Font for GUI added", 1, MTR_LMT_INFO,
//         mtrFontGetName(fontnum));
        mtrLogWrite("Font for GUI added", 1, MTR_LMT_INFO);
    }
    else
    {
        mtrNotify("Unable to add font to GUI", 1, MTR_LMT_FATAL);
        return false;
    }

    mtrScreenGetSizes(&screenWidth, &screenHeight);
    if (mtrNkInit(font, screenWidth, screenHeight) == NULL)
    {
        mtrNotify("Unable to create nuklear context", 1, MTR_LMT_FATAL);
        return false;
    }

    mtrLogWrite("GUI abstraction subsystem initialized", 0, MTR_LMT_INFO);
    return true;
}

MTR_EXPORT void MTR_CALL mtrGuiQuit(void)
{
    nk_free(&mtrNkGui.ctx);
    memset(&mtrNkGui.ctx, 0, sizeof(mtrNkGui));
}

MTR_EXPORT void MTR_CALL mtrGuiProcessEvents(void)
{
    struct nk_context *ctx;

    ctx = &mtrNkGui.ctx;
    nk_input_begin(ctx);
    mtrNkHandleEvents();
    nk_input_end(ctx);
}

MTR_EXPORT void MTR_CALL mtrGuiRender(void)
{
    const struct nk_command *cmd;
    int                      i;
    float                    points[8];

    UNUSED(points);

    nk_foreach(cmd, &mtrNkGui.ctx)
    {
        switch (cmd->type)
        {
            case NK_COMMAND_NOP:
                break;
            case NK_COMMAND_SCISSOR:
                //const struct nk_command_scissor *s =(const struct nk_command_scissor*)cmd;
                //al_set_clipping_rectangle((int)s->x, (int)s->y, (int)s->w, (int)s->h);
                break;
            case NK_COMMAND_LINE:
                {
                    const struct nk_command_line *l = (const struct nk_command_line *)cmd;
                    mtrPrimitiveLine_rgba_f(l->begin.x, l->begin.y, l->end.x,
                     l->end.y, l->color.r, l->color.g, l->color.b, l->color.a);
                }
                break;
            case NK_COMMAND_RECT:
                {
                    const struct nk_command_rect *r = (const struct nk_command_rect *)cmd;
                    mtrPrimitiveRoundedRectangle_rgba_f(r->x, r->y, r->x + r->w,
                     r->y + r->h, r->rounding, r->color.r, r->color.g,
                     r->color.b, r->color.a);
                }
                break;
            case NK_COMMAND_RECT_FILLED:
                {
                    const struct nk_command_rect_filled *r = (const struct nk_command_rect_filled *)cmd;
                    mtrPrimitiveRoundedRectangleFilled_rgba_f(r->x, r->y,
                     r->x + r->w, r->y + r->h, r->rounding, r->color.r,
                     r->color.g, r->color.b, r->color.a);
                }
                break;
            case NK_COMMAND_CIRCLE:
                {
                    const struct nk_command_circle *c = (const struct nk_command_circle *)cmd;
                    mtrPrimitiveCircle_rgba_f(c->x + (c->w >> 1),
                     c->y + (c->h >> 1), (c->w > c->h) ? c->w : c->h,
                     c->color.r, c->color.g, c->color.b, c->color.a);
                }
                break;
            case NK_COMMAND_CIRCLE_FILLED:
                {
                    const struct nk_command_circle_filled *c = (const struct nk_command_circle_filled *)cmd;
                    mtrPrimitiveCircleFilled_rgba_f(c->x + (c->w >> 1),
                     c->y + (c->h >> 1), (c->w > c->h) ? c->w : c->h,
                     c->color.r, c->color.g, c->color.b, c->color.a);
                }
                break;
            case NK_COMMAND_TRIANGLE:
                {
                    const struct nk_command_triangle*t = (const struct nk_command_triangle*)cmd;
                    mtrPrimitiveTriangle_rgba_f(t->a.x, t->a.y, t->b.x, t->b.y,
                     t->c.x, t->c.y, t->color.r, t->color.g, t->color.b,
                     t->color.a);
                }
                break;
            case NK_COMMAND_TRIANGLE_FILLED:
                {
                    const struct nk_command_triangle_filled *t = (const struct nk_command_triangle_filled *)cmd;
                    mtrPrimitiveTriangleFilled_rgba_f(t->a.x, t->a.y, t->b.x,
                     t->b.y, t->c.x, t->c.y, t->color.r, t->color.g, t->color.b,
                     t->color.a);
                }
                break;
            case NK_COMMAND_POLYGON:
                {
                    const struct nk_command_polygon *p = (const struct nk_command_polygon*)cmd;
                    for (i = 0; i < p->point_count; i++)
                    {
                        if (i == p->point_count - 1)
                            mtrPrimitiveLine_rgba_f(p->points[i].x,
                             p->points[i].y, p->points[0].x, p->points[0].y,
                             p->color.r, p->color.g, p->color.b, p->color.a);
                        else
                            mtrPrimitiveLine_rgba_f(p->points[i].x,
                             p->points[i].y, p->points[i + 1].x,
                             p->points[i + 1].y, p->color.r, p->color.g,
                             p->color.b, p->color.a);
                    }
                }
                break;
            case NK_COMMAND_POLYGON_FILLED:
                {
                    const struct nk_command_polygon_filled *p = (const struct nk_command_polygon_filled *)cmd;
                    for (i = 0; i < p->point_count; i++)
                    {
                        if (i == p->point_count - 1)
                            mtrPrimitiveLine_rgba_f(p->points[i].x,
                             p->points[i].y, p->points[0].x, p->points[0].y,
                             p->color.r, p->color.g, p->color.b, p->color.a);
                        else
                            mtrPrimitiveLine_rgba_f(p->points[i].x,
                             p->points[i].y, p->points[i + 1].x,
                             p->points[i + 1].y, p->color.r, p->color.g,
                             p->color.b, p->color.a);
                    }
                }
                break;
            case NK_COMMAND_POLYLINE:
                {
                    const struct nk_command_polyline *p = (const struct nk_command_polyline *)cmd;
                    for (i = 0; i < p->point_count - 1; i++)
                        mtrPrimitiveLine_rgba_f(p->points[i].x,
                         p->points[i].y, p->points[i + 1].x,
                         p->points[i + 1].y, p->color.r, p->color.g,
                         p->color.b, p->color.a);
                }
                break;
            case NK_COMMAND_TEXT:
                {
                    const struct nk_command_text *t = (const struct nk_command_text*)cmd;
                    mtrNkFont *font = (mtrNkFont*)t->font->userdata.ptr;
                    mtrFontDrawMbfString_f(font->font, t->x, t->y, t->string);
                }
                break;
            case NK_COMMAND_CURVE:
                break;
            case NK_COMMAND_ARC:
                {
                    const struct nk_command_arc *a = (const struct nk_command_arc *)cmd;
                    mtrPrimitiveArc_rgba_f(a->cx, a->cy, a->r, a->a[0], a->a[1],
                     a->color.r, a->color.g, a->color.b, a->color.a);
                }
                break;
            case NK_COMMAND_RECT_MULTI_COLOR:
            case NK_COMMAND_IMAGE:
                break;
            case NK_COMMAND_ARC_FILLED:
                {
                    const struct nk_command_arc_filled *a = (const struct nk_command_arc_filled *)cmd;
                    mtrPrimitiveSegmentFilled_rgba_f(a->cx, a->cy, a->r,
                     a->a[0], a->a[1], a->color.r, a->color.g, a->color.b,
                     a->color.a);
                }
                break;
            default:
                break;
        }
    }
    nk_clear(&mtrNkGui.ctx);
}

MTR_EXPORT bool MTR_CALL mtrGuiBegin(const char *title, float boundsX,
 float boundsY, float boundsW, float bountsH, int flags)
{
    return nk_begin(&mtrNkGui.ctx, title, nk_rect(boundsX, boundsY, boundsW, bountsH),
     flags);
}

MTR_EXPORT void MTR_CALL mtrGuiEnd(void)
{
    nk_end(&mtrNkGui.ctx);
}

MTR_EXPORT bool MTR_CALL mtrGuiButtonText(const char *title, int len)
{
    return nk_button_text(&mtrNkGui.ctx, title, len);
}

MTR_EXPORT bool MTR_CALL mtrGuiButtonLabel(const char *title)
{
    return nk_button_label(&mtrNkGui.ctx, title);
}

MTR_EXPORT bool MTR_CALL mtrGuiButtonColor_c(uint32_t color)
{
    struct nk_color nkColor;

    nkColor = (nk_rgba_u32((color << 8) | 0xFF));
    return nk_button_color(&mtrNkGui.ctx, nkColor);
}

MTR_EXPORT bool MTR_CALL mtrGuiButtonColor_ca(uint32_t color)
{
    return nk_button_color(&mtrNkGui.ctx, nk_rgba_u32(color));
}

MTR_EXPORT bool MTR_CALL mtrGuiButtonColor_rgb(uint8_t r, uint8_t g, uint8_t b)
{
    return nk_button_color(&mtrNkGui.ctx, nk_rgb(r, g, b));
}

MTR_EXPORT bool MTR_CALL mtrGuiButtonColor_rgba(uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    return nk_button_color(&mtrNkGui.ctx, nk_rgba(r, g, b, a));
}

MTR_EXPORT bool MTR_CALL mtrGuiCheckLabel(const char *label, bool active)
{
    return nk_check_label(&mtrNkGui.ctx, label, active);
}

MTR_EXPORT bool MTR_CALL mtrGuiCheckText(const char *text, int len, bool active)
{
    return nk_check_text(&mtrNkGui.ctx, text, len, active);
}

/* TODO
nk_button_image(struct nk_context*, struct nk_image img);
nk_button_image_label(struct nk_context*, struct nk_image img, const char*, nk_flags text_alignment);
nk_button_image_text(struct nk_context*, struct nk_image img, const char*, int, nk_flags alignment);
*/

MTR_EXPORT void MTR_CALL mtrGuiLabel(const char *string, int alignment)
{
    nk_label(&mtrNkGui.ctx, string, alignment);
}

MTR_EXPORT void MTR_CALL mtrGuiLabelColored_c(const char *string, int alignment,
 uint32_t color)
{
    struct nk_color nkColor;

    nkColor = (nk_rgba_u32((color << 8) | 0xFF));
    nk_label_colored(&mtrNkGui.ctx, string, alignment, nkColor);
}

MTR_EXPORT void MTR_CALL mtrGuiLabelColored_ca(const char *string,
 int alignment, uint32_t color)
{
    nk_label_colored(&mtrNkGui.ctx, string, alignment, nk_rgba_u32(color));
}

MTR_EXPORT void MTR_CALL mtrGuiLabelColored_rgb(const char *string,
 int alignment, uint8_t r, uint8_t g, uint8_t b)
{
    nk_label_colored(&mtrNkGui.ctx, string, alignment, nk_rgb(r, g, b));
}

MTR_EXPORT void MTR_CALL mtrGuiLabelColored_rgba(const char *string,
 int alignment, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    nk_label_colored(&mtrNkGui.ctx, string, alignment, nk_rgba(r, g, b, a));
}

MTR_EXPORT void MTR_CALL mtrGuiLabelWrap(const char *string)
{
    nk_label_wrap(&mtrNkGui.ctx, string);
}

MTR_EXPORT void MTR_CALL mtrGuiLabelColoredWrap_c(const char *string,
 uint32_t color)
{
    struct nk_color nkColor;

    nkColor = (nk_rgba_u32((color << 8) | 0xFF));
    nk_label_colored_wrap(&mtrNkGui.ctx, string, nkColor);
}

MTR_EXPORT void MTR_CALL mtrGuiLabelColoredWrap_ca(const char *string,
 uint32_t color)
{
    nk_label_colored_wrap(&mtrNkGui.ctx, string, nk_rgba_u32(color));
}

MTR_EXPORT void MTR_CALL mtrGuiLabelColoredWrap_rgb(const char *string,
 uint8_t r, uint8_t g, uint8_t b)
{
    nk_label_colored_wrap(&mtrNkGui.ctx, string, nk_rgb(r, g, b));
}

MTR_EXPORT void MTR_CALL mtrGuiLabelColoredWrap_rgba(const char *string,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    nk_label_colored_wrap(&mtrNkGui.ctx, string, nk_rgba(r, g, b, a));
}

MTR_EXPORT void MTR_CALL mtrGuiLayoutRowDynamic(float height, int cols)
{
    nk_layout_row_dynamic(&mtrNkGui.ctx, height, cols);
}

MTR_EXPORT void MTR_CALL mtrGuiLayoutRowStatic(float height, int cols,
 int itemWidth)
{
    nk_layout_row_static(&mtrNkGui.ctx, height, itemWidth, cols);
}

MTR_EXPORT bool MTR_CALL mtrGuiGroupBegin(const char *title, int flags)
{
    return nk_group_begin(&mtrNkGui.ctx, title, flags);
}

MTR_EXPORT void MTR_CALL mtrGuiGroupEnd(void)
{
    return nk_group_end(&mtrNkGui.ctx);
}

MTR_EXPORT void MTR_CALL mtrGuiSpacing(int cols)
{
    nk_spacing(&mtrNkGui.ctx, cols);
}
