#include "gui.h"

#include "marathoner/plugin_common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Gui, FA_FUNCTIONS_COUNT)

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
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
    report->prereqSubsystems = malloc(sizeof(char *)
     * report->prereqSubsystemsCount);
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

static float MTR_NkGetTextWidth(nk_handle handle, float height,
 const char *text, int len)
{
    mtrNkFont *font;

    font = (mtrNkFont *)handle.ptr;

    if (!font || !text)
        return 0;

    strncpy((char*)&getTextWidthBuffer, text, len);
    getTextWidthBuffer[len] = '\0';

    return MTR_FontGetStringWidth(font->font, getTextWidthBuffer);
}

/* Берёт номер шрифта менеджера шрифтов и возвращает внутренний индекс шрифта.
 * Подсистема GUI работает только с внутренними ресурсами (индекасми), т. е.
 * перед использованием их нужно непосредственно добавить
 */
/*fa MTR_GuiAddFont yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_GuiAddFont(uint32_t fontnum)
{
    mtrNkFont           *nkFont;
    uint32_t             freeIndex;
    struct nk_user_font *font;

    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrGuiFontKeeper);
    nkFont = IK_GET_DATA(mtrNkFont *, mtrGuiFontKeeper, freeIndex);

    nkFont->font = fontnum;
    nkFont->height = MTR_FontGetHeight(fontnum);

    font = &nkFont->nk;
    font->userdata = nk_handle_ptr(nkFont);
    font->height = nkFont->height;
    font->width = MTR_NkGetTextWidth;

    return freeIndex;
}

/*fa mtrGuiAddImage yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_GuiAddImage(uint32_t texnum, int x, int y,
 int w, int h)
{
    mtrNkImage      *nkImage;
    uint32_t         freeIndex;
    struct nk_image *image;
    MTR_GUI_CHECK_IF_NOT_INITED(0U);

    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrGuiImageKeeper);
    nkImage = IK_GET_DATA(mtrNkImage *, mtrGuiImageKeeper, freeIndex);

    nkImage->texture = texnum;
    MTR_TextureGetSizes(texnum, &nkImage->width, &nkImage->height);
    image = &nkImage->nk;
    image->handle = nk_handle_ptr(nkImage);
    image->w = nkImage->width;
    image->h = nkImage->height;
    image->region[0] = x;
    image->region[1] = y;
    image->region[2] = x + w;
    image->region[3] = y + h;

    return freeIndex;
}

/*fa mtrGuiDeleteFont yes */
MTR_DCLSPC void MTR_CALL MTR_GuiDeleteFont(uint32_t fontnum)
{
    MTR_GUI_CHECK_IF_NOT_INITED();

    if (fontnum != 0)
        MTR_IndexkeeperFreeIndex(mtrGuiFontKeeper, fontnum);
}

/*fa mtrGuiDeleteImage yes */
MTR_DCLSPC void MTR_CALL MTR_GuiDeleteImage(uint32_t imagenum)
{
    MTR_GUI_CHECK_IF_NOT_INITED();

    if (imagenum != 0)
        MTR_IndexkeeperFreeIndex(mtrGuiImageKeeper, imagenum);
}

NK_INTERN void MTR_NkClipboardPaste(nk_handle usr, struct nk_text_edit *edit)
{
    char *text;

    text = MTR_ClipboardGetText();

    if (text)
        nk_textedit_paste(edit, text, nk_strlen(text));
    (void)usr;
    free(text);
}

NK_INTERN void MTR_NkClipboardCopy(nk_handle usr, const char *text, int len)
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

    MTR_ClipboardPutText(str);

    free(str);
}

NK_API struct nk_context* MTR_NkInit(uint32_t fontnum, unsigned int width,
 unsigned int height)
{
    mtrNkFont           *nkFont;
    struct nk_user_font *font;

    nkFont = IK_GET_DATA(mtrNkFont *, mtrGuiFontKeeper, fontnum);

    font = &nkFont->nk;
    font->userdata = nk_handle_ptr(nkFont);
    font->height = nkFont->height;
    font->width = MTR_NkGetTextWidth;

    mtrNkGui.width = width;
    mtrNkGui.height = height;
    mtrNkGui.is_touch_down = 0;
    mtrNkGui.touch_down_id = -1;

    nk_init_default(&mtrNkGui.ctx, &nkFont->nk);
    mtrNkGui.ctx.clip.copy = MTR_NkClipboardCopy;
    mtrNkGui.ctx.clip.paste = MTR_NkClipboardPaste;
    mtrNkGui.ctx.clip.userdata = nk_handle_ptr(0);
    return &mtrNkGui.ctx;
}

void MTR_NkUpdateKey(struct nk_context *ctx, int key, enum nk_keys nk_key)
{
    if (MTR_KeyboardPress(key))
        nk_input_key(ctx, nk_key, 1);
    if (MTR_KeyboardRelease(key))
        nk_input_key(ctx, nk_key, 0);
}

void MTR_NkHandleEvents(void)
{
    struct nk_context *ctx;
    bool               mouseMotion;
    int                mouseRelWheel;
    int                mouseX;
    int                mouseY;
    bool               controlPressed;
    char              *utf8char;

    UNUSED(utf8char);

    ctx = &mtrNkGui.ctx;
//    case ALLEGRO_EVENT_DISPLAY_RESIZE: {
//        allegro5.width = (unsigned int)ev->display.width;
//        allegro5.height = (unsigned int)ev->display.height;
//        al_acknowledge_resize(ev->display.source);
//    } break;

    mouseMotion = MTR_MouseMoving();
    MTR_MouseGetXY(&mouseX, &mouseY);
    if (mouseMotion)
        nk_input_motion(ctx, mouseX, mouseY);

    mouseRelWheel = MTR_MouseGetWheelRelative();
    if (mouseRelWheel != 0)
        nk_input_scroll(ctx, (float)mouseRelWheel);

    if (MTR_MousePress(MTR_MOUSE_LEFT))
        nk_input_button(ctx, NK_BUTTON_LEFT, mouseX, mouseY, 1);
    if (MTR_MousePress(MTR_MOUSE_RIGHT))
        nk_input_button(ctx, NK_BUTTON_RIGHT, mouseX, mouseY, 1);
    if (MTR_MousePress(MTR_MOUSE_MIDDLE))
        nk_input_button(ctx, NK_BUTTON_MIDDLE, mouseX, mouseY, 1);

    if (MTR_MouseRelease(MTR_MOUSE_LEFT))
        nk_input_button(ctx, NK_BUTTON_LEFT, mouseX, mouseY, 0);
    if (MTR_MouseRelease(MTR_MOUSE_RIGHT))
        nk_input_button(ctx, NK_BUTTON_RIGHT, mouseX, mouseY, 0);
    if (MTR_MouseRelease(MTR_MOUSE_MIDDLE))
        nk_input_button(ctx, NK_BUTTON_MIDDLE, mouseX, mouseY, 0);

    if (MTR_KeyboardPress(MTR_KEY_LSHIFT) || MTR_KeyboardPress(MTR_KEY_RSHIFT))
        nk_input_key(ctx, NK_KEY_SHIFT, 1);
    if (MTR_KeyboardRelease(
     MTR_KEY_LSHIFT) || MTR_KeyboardRelease(MTR_KEY_RSHIFT))
        nk_input_key(ctx, NK_KEY_SHIFT, 0);

    MTR_NkUpdateKey(ctx, MTR_KEY_DELETE, NK_KEY_DEL);
    MTR_NkUpdateKey(ctx, MTR_KEY_RETURN, NK_KEY_ENTER);
    MTR_NkUpdateKey(ctx, MTR_KEY_TAB, NK_KEY_TAB);
    MTR_NkUpdateKey(ctx, MTR_KEY_LEFT, NK_KEY_LEFT);
    MTR_NkUpdateKey(ctx, MTR_KEY_RIGHT, NK_KEY_RIGHT);
    MTR_NkUpdateKey(ctx, MTR_KEY_UP, NK_KEY_UP);
    MTR_NkUpdateKey(ctx, MTR_KEY_DOWN, NK_KEY_DOWN);
    MTR_NkUpdateKey(ctx, MTR_KEY_BACKSPACE, NK_KEY_BACKSPACE);
    MTR_NkUpdateKey(ctx, MTR_KEY_ESCAPE, NK_KEY_TEXT_RESET_MODE);
    MTR_NkUpdateKey(ctx, MTR_KEY_PAGEUP, NK_KEY_SCROLL_UP);
    MTR_NkUpdateKey(ctx, MTR_KEY_PAGEDOWN, NK_KEY_SCROLL_DOWN);

    if (MTR_KeyboardPress(MTR_KEY_HOME))
    {
        nk_input_key(ctx, NK_KEY_TEXT_START, 1);
        nk_input_key(ctx, NK_KEY_SCROLL_START, 1);
    }
    if (MTR_KeyboardRelease(MTR_KEY_END))
    {
        nk_input_key(ctx, NK_KEY_TEXT_END, 0);
        nk_input_key(ctx, NK_KEY_SCROLL_END, 0);
    }

    controlPressed = MTR_KeyboardPress(MTR_KEY_LCTRL)
      || MTR_KeyboardPress(MTR_KEY_RCTRL) || MTR_KeyboardPress(MTR_KEY_LGUI)
      || MTR_KeyboardPress(MTR_KEY_RGUI);

    if (MTR_KeyboardPress(MTR_KEY_C) && controlPressed)
        nk_input_key(ctx, NK_KEY_COPY, 1);
    else if (MTR_KeyboardPress(MTR_KEY_V) && controlPressed)
        nk_input_key(ctx, NK_KEY_PASTE, 1);
    else if (MTR_KeyboardPress(MTR_KEY_X) && controlPressed)
        nk_input_key(ctx, NK_KEY_CUT, 1);
    else if (MTR_KeyboardPress(MTR_KEY_Z) && controlPressed)
        nk_input_key(ctx, NK_KEY_TEXT_UNDO, 1);
    else if (MTR_KeyboardPress(MTR_KEY_R) && controlPressed)
        nk_input_key(ctx, NK_KEY_TEXT_REDO, 1);
    else if (MTR_KeyboardPress(MTR_KEY_A) && controlPressed)
        nk_input_key(ctx, NK_KEY_TEXT_SELECT_ALL, 1);
    else
    {
        utf8char = MTR_KeyboardInputChar();
        if (utf8char != NULL)
            nk_input_glyph(ctx, utf8char);
    }
}

/*fa MTR_GuiInit yes */
MTR_DCLSPC bool MTR_CALL MTR_GuiInit(uint32_t fontDmSize,
 uint32_t fontReservedCount, uint32_t imageDmSize, uint32_t imageReservedCount,
 uint32_t fontnum)
{
    uint32_t nkFontNum;
    int screenWidth;
    int screenHeight;
    bool ok;

    ok = true;
    MTR_LogWrite("Initializing GUI abstraction subsystem", 0, MTR_LMT_INFO);

    MTR_FIND_FUNCTION(MTR_FontDrawMbfString_f, "Abstraction_font");
    MTR_FIND_FUNCTION(MTR_FontGetHeight, "Abstraction_font");
    MTR_FIND_FUNCTION(MTR_FontGetStringWidth, "Abstraction_font");
    MTR_FIND_FUNCTION(MTR_FontGetName, "Abstraction_font");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_ScreenGetSizes, "screen");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TextureBlitRegionSized_f, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TextureGetSizes, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_PrimitiveLine_rgba_f, "primitive");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_PrimitiveArc_rgba_f, "primitive");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_PrimitiveCircle_rgba_f, "primitive");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_PrimitiveCircleFilled_rgba_f,
     "primitive");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_PrimitiveTriangle_rgba_f, "primitive");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_PrimitiveTriangleFilled_rgba_f,
     "primitive");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_PrimitiveRoundedRectangle_rgba_f,
     "primitive");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_PrimitiveRoundedRectangleFilled_rgba_f,
     "primitive");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_KeyboardPress, "keyboard");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_KeyboardRelease, "keyboard");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_KeyboardPressed, "keyboard");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_KeyboardInputChar, "keyboard");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_MouseMoving, "mouse");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_MouseGetXY, "mouse");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_MousePress, "mouse");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_MouseRelease, "mouse");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_MouseGetWheelRelative, "mouse");

    if (ok)
        MTR_LogWrite("Added dependently functions", 1, MTR_LMT_INFO);
    else
    {
        MTR_Notify("Functions not added", 1, MTR_LMT_FATAL);
        return false;
    }

    mtrGuiFontKeeper = (mtrIndexkeeper_t *)MTR_IndexkeeperCreate(fontDmSize,
     fontReservedCount, sizeof(mtrNkFont));
    if (mtrGuiFontKeeper == NULL)
    {
        MTR_Notify("Unable to create indexkeeper structure for gui fonts", 1,
         MTR_LMT_FATAL);
        return false;
    }
    else
        MTR_LogWrite("Indexkeeper structure for gui fonts created", 1,
         MTR_LMT_INFO);

    mtrGuiImageKeeper = (mtrIndexkeeper_t *)MTR_IndexkeeperCreate(imageDmSize,
     imageReservedCount, sizeof(mtrNkImage));
    if (mtrGuiImageKeeper == NULL)
    {
        MTR_Notify("Unable to create indexkeeper structure for gui images", 1,
         MTR_LMT_FATAL);
        return false;
    }
    else
        MTR_LogWrite("Indexkeeper structure for gui images created", 1,
         MTR_LMT_INFO);

    nkFontNum = MTR_GuiAddFont(fontnum);

    MTR_ScreenGetSizes(&screenWidth, &screenHeight);
    if (MTR_NkInit(nkFontNum, screenWidth, screenHeight) == NULL)
    {
        MTR_Notify("Unable to create nuklear context", 1, MTR_LMT_FATAL);
        return false;
    }

    MTR_LogWrite("GUI abstraction subsystem initialized", 0, MTR_LMT_INFO);
    mtrGuiInited = true;
    return true;
}

/*fa MTR_GuiQuit yes */
MTR_DCLSPC void MTR_CALL MTR_GuiQuit(void)
{
    MTR_GUI_CHECK_IF_NOT_INITED();
    nk_free(&mtrNkGui.ctx);
    memset(&mtrNkGui.ctx, 0, sizeof(mtrNkGui));
}

/*fa MTR_GuiProcessEvents yes */
MTR_DCLSPC void MTR_CALL MTR_GuiProcessEvents(void)
{
    struct nk_context *ctx;
    MTR_GUI_CHECK_IF_NOT_INITED();

    ctx = &mtrNkGui.ctx;
    nk_input_begin(ctx);
    MTR_NkHandleEvents();
    nk_input_end(ctx);
}

/*fa MTR_GuiRender yes */
MTR_DCLSPC void MTR_CALL MTR_GuiRender(void)
{
    const struct nk_command *cmd;
    int                      i;
    float                    points[8];
    MTR_GUI_CHECK_IF_NOT_INITED();
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
                    const struct nk_command_line *l = (
                     const struct nk_command_line *)cmd;
                    MTR_PrimitiveLine_rgba_f(l->begin.x, l->begin.y, l->end.x,
                     l->end.y, l->color.r, l->color.g, l->color.b, l->color.a);
                }
                break;
            case NK_COMMAND_RECT:
                {
                    const struct nk_command_rect *r = (
                     const struct nk_command_rect *)cmd;
                    MTR_PrimitiveRoundedRectangle_rgba_f(r->x, r->y,
                     r->x + r->w, r->y + r->h, r->rounding, r->color.r,
                     r->color.g, r->color.b, r->color.a);
                }
                break;
            case NK_COMMAND_RECT_FILLED:
                {
                    const struct nk_command_rect_filled *r = (
                     const struct nk_command_rect_filled *)cmd;
                    MTR_PrimitiveRoundedRectangleFilled_rgba_f(r->x, r->y,
                     r->x + r->w, r->y + r->h, r->rounding, r->color.r,
                     r->color.g, r->color.b, r->color.a);
                }
                break;
            case NK_COMMAND_CIRCLE:
                {
                    const struct nk_command_circle *c = (
                     const struct nk_command_circle *)cmd;
                    MTR_PrimitiveCircle_rgba_f(c->x + (c->w >> 1),
                     c->y + (c->h >> 1), (c->w > c->h) ? c->w : c->h,
                     c->color.r, c->color.g, c->color.b, c->color.a);
                }
                break;
            case NK_COMMAND_CIRCLE_FILLED:
                {
                    const struct nk_command_circle_filled *c = (
                     const struct nk_command_circle_filled *)cmd;
                    MTR_PrimitiveCircleFilled_rgba_f(c->x + (c->w >> 1),
                     c->y + (c->h >> 1), (c->w > c->h) ? c->w : c->h,
                     c->color.r, c->color.g, c->color.b, c->color.a);
                }
                break;
            case NK_COMMAND_TRIANGLE:
                {
                    const struct nk_command_triangle*t = (
                     const struct nk_command_triangle*)cmd;
                    MTR_PrimitiveTriangle_rgba_f(t->a.x, t->a.y, t->b.x, t->b.y,
                     t->c.x, t->c.y, t->color.r, t->color.g, t->color.b,
                     t->color.a);
                }
                break;
            case NK_COMMAND_TRIANGLE_FILLED:
                {
                    const struct nk_command_triangle_filled *t = (
                     const struct nk_command_triangle_filled *)cmd;
                    MTR_PrimitiveTriangleFilled_rgba_f(t->a.x, t->a.y, t->b.x,
                     t->b.y, t->c.x, t->c.y, t->color.r, t->color.g, t->color.b,
                     t->color.a);
                }
                break;
            case NK_COMMAND_POLYGON:
                {
                    const struct nk_command_polygon *p = (
                     const struct nk_command_polygon*)cmd;
                    for (i = 0; i < p->point_count; i++)
                    {
                        if (i == p->point_count - 1)
                            MTR_PrimitiveLine_rgba_f(p->points[i].x,
                             p->points[i].y, p->points[0].x, p->points[0].y,
                             p->color.r, p->color.g, p->color.b, p->color.a);
                        else
                            MTR_PrimitiveLine_rgba_f(p->points[i].x,
                             p->points[i].y, p->points[i + 1].x,
                             p->points[i + 1].y, p->color.r, p->color.g,
                             p->color.b, p->color.a);
                    }
                }
                break;
            case NK_COMMAND_POLYGON_FILLED:
                {
                    const struct nk_command_polygon_filled *p = (
                     const struct nk_command_polygon_filled *)cmd;
                    for (i = 0; i < p->point_count; i++)
                    {
                        if (i == p->point_count - 1)
                            MTR_PrimitiveLine_rgba_f(p->points[i].x,
                             p->points[i].y, p->points[0].x, p->points[0].y,
                             p->color.r, p->color.g, p->color.b, p->color.a);
                        else
                            MTR_PrimitiveLine_rgba_f(p->points[i].x,
                             p->points[i].y, p->points[i + 1].x,
                             p->points[i + 1].y, p->color.r, p->color.g,
                             p->color.b, p->color.a);
                    }
                }
                break;
            case NK_COMMAND_POLYLINE:
                {
                    const struct nk_command_polyline *p = (
                     const struct nk_command_polyline *)cmd;
                    for (i = 0; i < p->point_count - 1; i++)
                        MTR_PrimitiveLine_rgba_f(p->points[i].x,
                         p->points[i].y, p->points[i + 1].x,
                         p->points[i + 1].y, p->color.r, p->color.g,
                         p->color.b, p->color.a);
                }
                break;
            case NK_COMMAND_TEXT:
                {
                    const struct nk_command_text *t = (
                     const struct nk_command_text*)cmd;
                    mtrNkFont *font = (mtrNkFont*)t->font->userdata.ptr;
                    MTR_FontDrawMbfString_f(font->font, t->x, t->y, t->string);
                }
                break;
            case NK_COMMAND_CURVE:
                break;
            case NK_COMMAND_ARC:
                {
                    const struct nk_command_arc *a = (
                     const struct nk_command_arc *)cmd;
                    MTR_PrimitiveArc_rgba_f(a->cx, a->cy, a->r, a->a[0],
                     a->a[1], a->color.r, a->color.g, a->color.b, a->color.a);
                }
                break;
            case NK_COMMAND_RECT_MULTI_COLOR:
            case NK_COMMAND_IMAGE:
                {
                    const struct nk_command_image *img = (
                     const struct nk_command_image *)cmd;
                    mtrNkImage *image = (mtrNkImage *)img->img.handle.ptr;
                    MTR_TextureBlitRegionSized_f(image->texture, img->x, img->y,
                     img->w, img->h, image->nk.region[0], image->nk.region[1],
                     image->nk.region[2] - image->nk.region[0],
                     image->nk.region[3] - image->nk.region[1]);
                }
                break;
            case NK_COMMAND_ARC_FILLED:
                {
                    const struct nk_command_arc_filled *a = (
                     const struct nk_command_arc_filled *)cmd;
                    MTR_PrimitiveSegmentFilled_rgba_f(a->cx, a->cy, a->r,
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

/*fa MTR_GuiBegin yes */
MTR_DCLSPC bool MTR_CALL MTR_GuiBegin(const char *title, float boundsX,
 float boundsY, float boundsW, float boundsH, int flags)
{
    struct nk_rect bounds = nk_rect(boundsX, boundsY, boundsW, boundsH);
    MTR_GUI_CHECK_IF_NOT_INITED(false);

    return nk_begin(&mtrNkGui.ctx, title, bounds, flags);
}

/*fa MTR_GuiEnd yes */
MTR_DCLSPC void MTR_CALL MTR_GuiEnd(void)
{
    MTR_GUI_CHECK_IF_NOT_INITED();
    nk_end(&mtrNkGui.ctx);
}

/*fa MTR_GuiButtonText yes */
MTR_DCLSPC bool MTR_CALL MTR_GuiButtonText(const char *title, int len)
{
    MTR_GUI_CHECK_IF_NOT_INITED(false);
    return nk_button_text(&mtrNkGui.ctx, title, len);
}

/*fa MTR_GuiButtonLabel yes */
MTR_DCLSPC bool MTR_CALL MTR_GuiButtonLabel(const char *title)
{
    MTR_GUI_CHECK_IF_NOT_INITED(false);
    return nk_button_label(&mtrNkGui.ctx, title);
}

/*fa MTR_GuiButtonColor_c yes */
MTR_DCLSPC bool MTR_CALL MTR_GuiButtonColor_c(uint32_t color)
{
    struct nk_color nkColor;
    MTR_GUI_CHECK_IF_NOT_INITED(false);

    nkColor = (nk_rgba_u32((color << 8) | 0xFF));
    return nk_button_color(&mtrNkGui.ctx, nkColor);
}

/*fa MTR_GuiButtonColor_ca yes */
MTR_DCLSPC bool MTR_CALL MTR_GuiButtonColor_ca(uint32_t color)
{
    MTR_GUI_CHECK_IF_NOT_INITED(false);
    return nk_button_color(&mtrNkGui.ctx, nk_rgba_u32(color));
}

/*fa MTR_GuiButtonColor_rgb yes */
MTR_DCLSPC bool MTR_CALL MTR_GuiButtonColor_rgb(uint8_t r, uint8_t g, uint8_t b)
{
    MTR_GUI_CHECK_IF_NOT_INITED(false);
    return nk_button_color(&mtrNkGui.ctx, nk_rgb(r, g, b));
}

/*fa MTR_GuiButtonColor_rgba yes */
MTR_DCLSPC bool MTR_CALL MTR_GuiButtonColor_rgba(uint8_t r, uint8_t g,
 uint8_t b, uint8_t a)
{
    MTR_GUI_CHECK_IF_NOT_INITED(false);
    return nk_button_color(&mtrNkGui.ctx, nk_rgba(r, g, b, a));
}

/*fa MTR_GuiButtonSymbol yes */
MTR_DCLSPC bool MTR_CALL MTR_GuiButtonSymbol(int symbol)
{
    MTR_GUI_CHECK_IF_NOT_INITED(false);
    return nk_button_symbol(&mtrNkGui.ctx, symbol);
}

/*fa MTR_GuiButtonSymbolLabel yes */
MTR_DCLSPC bool MTR_CALL MTR_GuiButtonSymbolLabel(int symbol,
 const char *string, int alignment)
{
    MTR_GUI_CHECK_IF_NOT_INITED(false);
    return nk_button_symbol_label(&mtrNkGui.ctx, symbol, string, alignment);
}

/*fa MTR_GuiButtonSymbolText yes */
MTR_DCLSPC bool MTR_CALL MTR_GuiButtonSymbolText(int symbol, const char *string,
 int len, int alignment)
{
    MTR_GUI_CHECK_IF_NOT_INITED(false);
    return nk_button_symbol_text(&mtrNkGui.ctx, symbol, string, len, alignment);
}

/*fa MTR_GuiButtonImage yes */
MTR_DCLSPC bool MTR_CALL MTR_GuiButtonImage(uint32_t imagenum)
{
    mtrNkImage *nkImage;
    MTR_GUI_CHECK_IF_NOT_INITED(false);

    nkImage = IK_GET_DATA(mtrNkImage *, mtrGuiImageKeeper, imagenum);

    return nk_button_image(&mtrNkGui.ctx, nkImage->nk);
}

/*fa MTR_GuiButtonImageLabel yes */
MTR_DCLSPC bool MTR_CALL MTR_GuiButtonImageLabel(uint32_t imagenum,
 const char *string, int alignment)
{
    mtrNkImage *nkImage;
    MTR_GUI_CHECK_IF_NOT_INITED(false);

    nkImage = IK_GET_DATA(mtrNkImage *, mtrGuiImageKeeper, imagenum);

    return nk_button_image_label(&mtrNkGui.ctx, nkImage->nk, string, alignment);
}

/*fa MTR_GuiButtonImageText yes */
MTR_DCLSPC bool MTR_CALL MTR_GuiButtonImageText(uint32_t imagenum,
 const char *string, int len, int alignment)
{
    mtrNkImage *nkImage;
    MTR_GUI_CHECK_IF_NOT_INITED(false);

    nkImage = IK_GET_DATA(mtrNkImage *, mtrGuiImageKeeper, imagenum);

    return nk_button_image_text(&mtrNkGui.ctx, nkImage->nk, string, len,
     alignment);
}

/*fa MTR_GuiCheckLabel yes */
MTR_DCLSPC bool MTR_CALL MTR_GuiCheckLabel(const char *label, bool active)
{
    MTR_GUI_CHECK_IF_NOT_INITED(false);
    return nk_check_label(&mtrNkGui.ctx, label, active);
}

/*fa MTR_GuiCheckText yes */
MTR_DCLSPC bool MTR_CALL MTR_GuiCheckText(const char *text, int len,
 bool active)
{
    MTR_GUI_CHECK_IF_NOT_INITED(false);
    return nk_check_text(&mtrNkGui.ctx, text, len, active);
}

/*fa MTR_GuiSelectableLabel yes */
MTR_DCLSPC bool MTR_CALL MTR_GuiSelectableLabel(const char *text, int alignment,
 bool selected)
{
    MTR_GUI_CHECK_IF_NOT_INITED(false);
    return nk_select_label(&mtrNkGui.ctx, text, alignment, selected);
}

/*fa MTR_GuiSelectableText yes */
MTR_DCLSPC bool MTR_CALL MTR_GuiSelectableText(const char *text, int len,
 int alignment, bool selected)
{
    MTR_GUI_CHECK_IF_NOT_INITED(false);
    return nk_select_text(&mtrNkGui.ctx, text, len, alignment, selected);
}

/*fa MTR_GuiSelectableImageLabel yes */
MTR_DCLSPC bool MTR_CALL MTR_GuiSelectableImageLabel(uint32_t imagenum,
 const char *text, int alignment, bool selected)
{
    mtrNkImage *nkImage;
    MTR_GUI_CHECK_IF_NOT_INITED(false);

    nkImage = IK_GET_DATA(mtrNkImage *, mtrGuiImageKeeper, imagenum);

    if (text == NULL)
        return nk_select_image_label(&mtrNkGui.ctx, nkImage->nk, " ",
         alignment, selected);

    return nk_select_image_label(&mtrNkGui.ctx, nkImage->nk, text, alignment,
     selected);
}

/*fa MTR_GuiSelectableImageText yes */
MTR_DCLSPC bool MTR_CALL MTR_GuiSelectableImageText(uint32_t imagenum,
 const char *text, int len, int alignment, bool selected)
{
    mtrNkImage *nkImage;
    MTR_GUI_CHECK_IF_NOT_INITED(false);

    nkImage = IK_GET_DATA(mtrNkImage *, mtrGuiImageKeeper, imagenum);

    return nk_select_image_text(&mtrNkGui.ctx, nkImage->nk, text, len,
     alignment, selected);
}

/*fa MTR_GuiEditText yes */
MTR_DCLSPC void MTR_CALL MTR_GuiEditText(uint32_t sbnum)
{
    MTR_GUI_CHECK_IF_NOT_INITED();
    nk_edit_string_zero_terminated(&mtrNkGui.ctx, NK_EDIT_FIELD,
     MTR_StringBufferGetString(sbnum), MTR_StringBufferGetMaxLen(sbnum),
     nk_filter_default);
}

/*fa MTR_GuiEditInteger yes */
MTR_DCLSPC void MTR_CALL MTR_GuiEditInteger(uint32_t sbnum)
{
    MTR_GUI_CHECK_IF_NOT_INITED();
    nk_edit_string_zero_terminated(&mtrNkGui.ctx, NK_EDIT_FIELD,
     MTR_StringBufferGetString(sbnum), MTR_StringBufferGetMaxLen(sbnum),
     nk_filter_decimal);
}

/*fa MTR_GuiEditFloat yes */
MTR_DCLSPC void MTR_CALL MTR_GuiEditFloat(uint32_t sbnum)
{
    MTR_GUI_CHECK_IF_NOT_INITED();
    nk_edit_string_zero_terminated(&mtrNkGui.ctx, NK_EDIT_FIELD,
     MTR_StringBufferGetString(sbnum), MTR_StringBufferGetMaxLen(sbnum),
     nk_filter_float);
}

/*fa MTR_GuiLabel yes */
MTR_DCLSPC void MTR_CALL MTR_GuiLabel(const char *string, int alignment)
{
    MTR_GUI_CHECK_IF_NOT_INITED();
    nk_label(&mtrNkGui.ctx, string, alignment);
}

/*fa MTR_GuiLabelColored_c yes */
MTR_DCLSPC void MTR_CALL MTR_GuiLabelColored_c(const char *string,
 int alignment, uint32_t color)
{
    struct nk_color nkColor;
    MTR_GUI_CHECK_IF_NOT_INITED();

    nkColor = (nk_rgba_u32((color << 8) | 0xFF));
    nk_label_colored(&mtrNkGui.ctx, string, alignment, nkColor);
}

/*fa MTR_GuiLabelColored_ca yes */
MTR_DCLSPC void MTR_CALL MTR_GuiLabelColored_ca(const char *string,
 int alignment, uint32_t color)
{
    MTR_GUI_CHECK_IF_NOT_INITED();
    nk_label_colored(&mtrNkGui.ctx, string, alignment, nk_rgba_u32(color));
}

/*fa MTR_GuiLabelColored_rgb yes */
MTR_DCLSPC void MTR_CALL MTR_GuiLabelColored_rgb(const char *string,
 int alignment, uint8_t r, uint8_t g, uint8_t b)
{
    MTR_GUI_CHECK_IF_NOT_INITED();
    nk_label_colored(&mtrNkGui.ctx, string, alignment, nk_rgb(r, g, b));
}

/*fa MTR_GuiLabelColored_rgba yes */
MTR_DCLSPC void MTR_CALL MTR_GuiLabelColored_rgba(const char *string,
 int alignment, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    MTR_GUI_CHECK_IF_NOT_INITED();
    nk_label_colored(&mtrNkGui.ctx, string, alignment, nk_rgba(r, g, b, a));
}

/*fa MTR_GuiLabelWrap yes */
MTR_DCLSPC void MTR_CALL MTR_GuiLabelWrap(const char *string)
{
    MTR_GUI_CHECK_IF_NOT_INITED();
    nk_label_wrap(&mtrNkGui.ctx, string);
}

/*fa MTR_GuiLabelColoredWrap_c yes */
MTR_DCLSPC void MTR_CALL MTR_GuiLabelColoredWrap_c(const char *string,
 uint32_t color)
{
    struct nk_color nkColor;
    MTR_GUI_CHECK_IF_NOT_INITED();

    nkColor = (nk_rgba_u32((color << 8) | 0xFF));
    nk_label_colored_wrap(&mtrNkGui.ctx, string, nkColor);
}

/*fa MTR_GuiLabelColoredWrap_ca yes */
MTR_DCLSPC void MTR_CALL MTR_GuiLabelColoredWrap_ca(const char *string,
 uint32_t color)
{
    MTR_GUI_CHECK_IF_NOT_INITED();
    nk_label_colored_wrap(&mtrNkGui.ctx, string, nk_rgba_u32(color));
}

/*fa MTR_GuiLabelColoredWrap_rgb yes */
MTR_DCLSPC void MTR_CALL MTR_GuiLabelColoredWrap_rgb(const char *string,
 uint8_t r, uint8_t g, uint8_t b)
{
    MTR_GUI_CHECK_IF_NOT_INITED();
    nk_label_colored_wrap(&mtrNkGui.ctx, string, nk_rgb(r, g, b));
}

/*fa MTR_GuiLabelColoredWrap_rgba yes */
MTR_DCLSPC void MTR_CALL MTR_GuiLabelColoredWrap_rgba(const char *string,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    MTR_GUI_CHECK_IF_NOT_INITED();
    nk_label_colored_wrap(&mtrNkGui.ctx, string, nk_rgba(r, g, b, a));
}

/*fa MTR_GuiTreeTabBegin yes */
MTR_DCLSPC bool MTR_CALL MTR_GuiTreeTabBegin(const char *title, bool maximized)
{
    MTR_GUI_CHECK_IF_NOT_INITED(false);
    return nk_tree_push(&mtrNkGui.ctx, NK_TREE_TAB, title, maximized);
}

/*fa MTR_GuiTreeTabEnd yes */
MTR_DCLSPC void MTR_CALL MTR_GuiTreeTabEnd(void)
{
    MTR_GUI_CHECK_IF_NOT_INITED();
    nk_tree_pop(&mtrNkGui.ctx);
}

/*fa MTR_GuiLayoutRowDynamic yes */
MTR_DCLSPC void MTR_CALL MTR_GuiLayoutRowDynamic(float height, int cols)
{
    MTR_GUI_CHECK_IF_NOT_INITED();
    nk_layout_row_dynamic(&mtrNkGui.ctx, height, cols);
}

/*fa MTR_GuiLayoutRowStatic yes */
MTR_DCLSPC void MTR_CALL MTR_GuiLayoutRowStatic(float height, int cols,
 int itemWidth)
{
    MTR_GUI_CHECK_IF_NOT_INITED();
    nk_layout_row_static(&mtrNkGui.ctx, height, itemWidth, cols);
}

/*fa MTR_GuiGroupBegin yes */
MTR_DCLSPC bool MTR_CALL MTR_GuiGroupBegin(const char *title, int flags)
{
    MTR_GUI_CHECK_IF_NOT_INITED(false);
    return nk_group_begin(&mtrNkGui.ctx, title, flags);
}

/*fa MTR_GuiGroupEnd yes */
MTR_DCLSPC void MTR_CALL MTR_GuiGroupEnd(void)
{
    MTR_GUI_CHECK_IF_NOT_INITED();
    return nk_group_end(&mtrNkGui.ctx);
}

/*fa MTR_GuiSpacing yes */
MTR_DCLSPC void MTR_CALL MTR_GuiSpacing(int cols)
{
    MTR_GUI_CHECK_IF_NOT_INITED();
    nk_spacing(&mtrNkGui.ctx, cols);
}
